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

#ifndef ECMA_MODULE_H
#define ECMA_MODULE_H

#include "js-parser-internal.h"

#ifndef CONFIG_DISABLE_ES2015_MODULE_SYSTEM

void ecma_module_load_modules (parser_context_t *context_p);

#endif /* !CONFIG_DISABLE_ES2015_MODULE_SYSTEM */

#endif /* !ECMA_MODULE_H */
