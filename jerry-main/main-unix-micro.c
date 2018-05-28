/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <string.h>

#include "jerryscript.h"
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "micro-source.h"

void
jerry_port_log (jerry_log_level_t level, /**< message log level */
                const char *format, /**< format string */
                ...)  /**< parameters */
{
  (void) (level);
  (void) (format);
} /* jerry_port_log */

static jerry_value_t
jerry_handler_register_global (const jerry_char_t *name_p, /**< name of the function */
                               jerry_external_handler_t handler_p) /**< function callback */
{
  jerry_value_t global_obj_val = jerry_get_global_object ();
  jerry_value_t function_name_val = jerry_create_string_sz (name_p, (jerry_size_t) strlen ((const char *) name_p));
  jerry_value_t function_val = jerry_create_external_function (handler_p);

  jerry_value_t result_val = jerry_set_property (global_obj_val, function_name_val, function_val);

  jerry_release_value (function_val);
  jerry_release_value (function_name_val);
  jerry_release_value (global_obj_val);

  return result_val;
}

/**
 * Register a JavaScript function in the global object.
 */
static void
register_js_function (const char *name_p, /**< name of the function */
                      jerry_external_handler_t handler_p) /**< function callback */
{
  jerry_value_t result_val = jerry_handler_register_global ((const jerry_char_t *) name_p, handler_p);

  if (jerry_value_is_error (result_val))
  {
    printf("Warning: failed to register '%s' method.", name_p);
    result_val = jerry_get_value_from_error (result_val, true);
  }

  jerry_release_value (result_val);
} /* register_js_function */

/**
 * Provide a 'print' implementation for scripts.
 *
 * The routine converts all of its arguments to strings and outputs them
 * char-by-char using printf.
 *
 * The NUL character is output as "\u0000", other characters are output
 * bytewise.
 *
 * @return undefined - if all arguments could be converted to strings,
 *         error - otherwise.
 */
static jerry_value_t
jerry_handler_print (const jerry_value_t func_obj_val, /**< function object */
                     const jerry_value_t this_p, /**< this arg */
                     const jerry_value_t args_p[], /**< function arguments */
                     const jerry_length_t args_cnt) /**< number of function arguments */
{
  (void) func_obj_val; /* unused */
  (void) this_p; /* unused */

  jerry_value_t ret_val = jerry_create_undefined ();

  for (jerry_length_t arg_index = 0; arg_index < args_cnt; arg_index++)
  {
    jerry_value_t str_val = jerry_value_to_string (args_p[arg_index]);

    if (jerry_value_is_error (str_val))
    {
      /* There is no need to free the undefined value. */
      ret_val = str_val;
      break;
    }

    jerry_length_t length = jerry_get_string_length (str_val);
    jerry_length_t substr_pos = 0;
    jerry_char_t substr_buf[256];

    do
    {
      jerry_size_t substr_size = jerry_substring_to_char_buffer (str_val,
                                                                 substr_pos,
                                                                 length,
                                                                 substr_buf,
                                                                 256 - 1);

      jerry_char_t *buf_end_p = substr_buf + substr_size;
      substr_pos += (jerry_length_t) (buf_end_p - substr_buf);

      if (substr_pos == length)
      {
        *buf_end_p++ = (arg_index < args_cnt - 1) ? ' ' : '\n';
      }

      for (jerry_char_t *buf_p = substr_buf; buf_p < buf_end_p; buf_p++)
      {
        char chr = (char) *buf_p;

        if (chr != '\0')
        {
          printf ("%c", chr);
          continue;
        }
      }
    }
    while (substr_pos < length);

    jerry_release_value (str_val);
  }

  if (args_cnt == 0 || jerry_value_is_error (ret_val))
  {
    printf ("\n");
  }

  return ret_val;
} /* jerryx_handler_print */

#ifdef MICRO_PROFILE_ASSERT
static jerry_value_t
jerry_handler_assert (const jerry_value_t func_obj_val, /**< function object */
                      const jerry_value_t this_p, /**< this arg */
                      const jerry_value_t args_p[], /**< function arguments */
                      const jerry_length_t args_cnt) /**< number of function arguments */
{
  (void) func_obj_val; /* unused */
  (void) this_p; /* unused */

  if (args_cnt == 1
      && jerry_value_is_boolean (args_p[0])
      && jerry_get_boolean_value (args_p[0]))
  {
    return jerry_create_boolean (true);
  }
  else
  {
    jerry_port_log (JERRY_LOG_LEVEL_ERROR, "Script Error: assertion failed\n");
    jerry_port_fatal (ERR_FAILED_INTERNAL_ASSERTION);
  }
} /* jerryx_handler_assert */

#endif /* MICRO_PROFILE_ASSERT */

int
main (int argc,
      char **argv)
{
  (void) argc;
  (void) argv;

  jerry_init (JERRY_INIT_EMPTY);

  register_js_function ("print", jerry_handler_print);

#ifdef MICRO_PROFILE_ASSERT
  register_js_function ("assert", jerry_handler_assert);
#endif /* MICRO_PROFILE_ASSERT */

  jerry_value_t ret_value = jerry_exec_snapshot ((const uint32_t *) micro_snapshot,
                                                 micro_snapshot_len,
                                                 0,
                                                 0);
  jerry_release_value (ret_value);

  int ret_code = 0;

  if (jerry_value_is_error (ret_value))
  {
    printf ("Unhandled exception: Script Error!\n");
    ret_code = 1;
  }

  jerry_release_value (ret_value);
  jerry_cleanup ();

  return ret_code;
}
