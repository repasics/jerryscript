# Detailed function sizes

## Text section

| Function name                                              | Size (B) |
|------------------------------------------------------------|----------|
| vm_loop                                                    | 7304     |
| vm_execute                                                 | 1022     |
| ecma_op_function_call                                      | 806      |
| ecma_string_to_number                                      | 748      |
| ecma_append_chars_to_string                                | 640      |
| main                                                       | 616      |
| __udivsi3                                                  | 604      |
| ecma_op_general_object_define_own_property                 | 548      |
| ecma_op_array_object_set_length                            | 530      |
| ecma_op_object_put                                         | 522      |
| ecma_gc_run                                                | 520      |
| ecma_op_object_get_own_property                            | 464      |
| ecma_builtin_try_to_instantiate_property                   | 432      |
| opfunc_relation                                            | 430      |
| ecma_op_object_find_own                                    | 410      |
| ecma_op_same_value                                         | 382      |
| ecma_snapshot_get_literal                                  | 380      |
| ecma_op_object_define_own_property                         | 370      |
| ecma_op_abstract_equality_compare                          | 358      |
| jerry_handler_print                                        | 346      |
| ecma_builtin_function_dispatch_construct                   | 338      |
| snapshot_load_compiled_code                                | 338      |
| ecma_new_ecma_string_from_utf8                             | 304      |
| ecma_string_get_chars                                      | 294      |
| ecma_op_function_construct                                 | 276      |
| do_number_arithmetic                                       | 240      |
| vm_stack_find_finally                                      | 238      |
| ecma_find_named_property                                   | 206      |
| ecma_op_strict_equality_compare                            | 202      |
| ecma_create_property                                       | 190      |
| do_number_bitwise_logic                                    | 184      |
| ecma_instantiate_builtin_helper                            | 182      |
| ecma_gc_mark                                               | 180      |
| ecma_op_to_object                                          | 178      |
| ecma_concat_ecma_strings                                   | 168      |
| ecma_number_to_uint32                                      | 168      |
| ecma_op_general_object_default_value                       | 158      |
| ecma_op_bound_function_try_to_lazy_instantiate_property    | 156      |
| ecma_op_to_string                                          | 156      |
| ecma_op_function_try_to_lazy_instantiate_property          | 152      |
| ecma_string_get_length                                     | 152      |
| vm_stack_context_abort                                     | 148      |
| ecma_get_number                                            | 144      |
| ecma_op_to_number                                          | 132      |
| vm_run                                                     | 124      |
| ecma_builtin_make_function_object_for_routine              | 120      |
| ecma_string_to_array_index                                 | 120      |
| ecma_delete_property                                       | 118      |
| ecma_instantiate_builtin                                   | 102      |
| ecma_append_to_values_collection                           | 100      |
| ecma_op_to_boolean                                         | 98       |
| ecma_make_number_value                                     | 94       |
| ecma_new_ecma_string_from_number                           | 94       |
| ecma_number_trunc                                          | 90       |
| ecma_bytecode_deref                                        | 82       |
| ecma_op_create_function_object                             | 78       |
| ecma_gc_mark_property                                      | 76       |
| jmem_heap_gc_and_alloc_block                               | 72       |
| ecma_create_named_accessor_property                        | 70       |
| ecma_op_resolve_reference_value                            | 70       |
| ecma_value_assign_value                                    | 70       |
| ecma_uint32_to_utf8_string                                 | 66       |
| ecma_deref_ecma_string                                     | 64       |
| ecma_op_create_mutable_binding                             | 64       |
| ecma_op_set_mutable_binding                                | 64       |
| ecma_free_property                                         | 62       |
| ecma_copy_value                                            | 60       |
| ecma_create_object                                         | 60       |
| ecma_free_value                                            | 60       |
| ecma_string_get_char_at_pos                                | 60       |
| __libc_csu_init                                            | 60       |
| ecma_op_put_value_lex_env_base                             | 58       |
| ecma_new_ecma_string_from_magic_string_ex_id               | 56       |
| ecma_op_get_binding_value                                  | 56       |
| ecma_create_error_reference_from_context                   | 52       |
| ecma_new_ecma_string_from_uint32                           | 52       |
| jerry_release_value                                        | 52       |
| ecma_free_values_collection                                | 50       |
| ecma_op_object_get_property                                | 50       |
| ecma_create_decl_lex_env                                   | 48       |
| ecma_create_object_lex_env                                 | 48       |
| ecma_free_string_list                                      | 48       |
| jmem_pools_collect_empty                                   | 48       |
| ecma_builtin_helper_def_prop                               | 42       |
| ecma_op_object_get                                         | 40       |
| ecma_op_object_find                                        | 38       |
| ecma_init_gc_info                                          | 36       |
| ecma_make_uint32_value                                     | 36       |
| ecma_string_get_property_index                             | 36       |
| vm_var_decl                                                | 36       |
| ecma_builtin_get                                           | 34       |
| ecma_new_values_collection                                 | 34       |
| ecma_op_external_function_try_to_lazy_instantiate_property | 34       |
| ecma_op_has_binding                                        | 34       |
| ecma_compare_ecma_strings_longpath                         | 30       |
| ecma_new_standard_error                                    | 30       |
| ecma_raise_standard_error                                  | 30       |
| ecma_ref_ecma_string                                       | 30       |
| ecma_alloc_number                                          | 28       |
| ecma_free_unused_memory                                    | 28       |
| ecma_op_is_callable                                        | 28       |
| vm_decode_branch_offset                                    | 28       |
| __aeabi_uidivmod                                           | 26       |
| ecma_get_number_from_value                                 | 26       |
| ecma_number_is_infinity                                    | 26       |
| ecma_op_resolve_reference_base                             | 26       |
| ecma_op_to_primitive                                       | 26       |
| __aeabi_llsl                                               | 24       |
| __ashldi3                                                  | 24       |
| ecma_ref_object                                            | 24       |
| vm_construct_literal_object                                | 24       |
| ecma_collection_iterator_next                              | 20       |
| ecma_create_named_data_property                            | 20       |
| ecma_string_get_chars_fast                                 | 20       |
| jmem_run_free_unused_memory_callbacks                      | 20       |
| ecma_copy_value_if_not_object                              | 18       |
| ecma_free_value_if_not_object                              | 16       |
| lit_get_magic_string_ex_size                               | 16       |
| lit_get_magic_string_ex_utf8                               | 16       |
| ecma_builtin_error_dispatch_construct                      | 14       |
| ecma_collection_iterator_init                              | 14       |
| ecma_gc_set_object_visited                                 | 14       |
| ecma_reject                                                | 14       |
| __aeabi_idiv0                                              | 12       |
| __aeabi_ldiv0                                              | 12       |
| ecma_builtin_function_prototype_dispatch_construct         | 10       |
| ecma_builtin_type_error_thrower_dispatch_construct         | 10       |
| ecma_op_check_object_coercible                             | 10       |
| ecma_op_function_construct                                 | 10       |
| ecma_op_object_has_instance                                | 10       |
| ecma_op_set_mutable_binding                                | 10       |
| ecma_op_to_object                                          | 10       |
| ecma_reject                                                | 10       |
| jerry_snapshot_result                                      | 10       |
| opfunc_in                                                  | 10       |
| ecma_get_named_accessor_property_setter                    | 6        |
| ecma_builtin_object_dispatch_construct                     | 4        |

## Data section

| Data name                                                | Size (B) |
|----------------------------------------------------------|----------|
| ecma_builtin_object_prototype_property_descriptor_list   | 12       |
| ecma_builtin_type_error_thrower_property_descriptor_list | 12       |
| ecma_builtin_error_property_descriptor_list              | 18       |
| ecma_builtin_function_property_descriptor_list           | 18       |
| ecma_builtin_function_prototype_property_descriptor_list | 18       |
| ecma_builtin_object_property_descriptor_list             | 18       |
| ecma_builtin_construct_functions                         | 20       |
| ecma_builtin_error_prototype_property_descriptor_list    | 30       |
| ecma_builtin_property_list_references                    | 32       |
| builtin_number_list                                      | 40       |
| ecma_builtin_global_property_descriptor_list             | 42       |
| lit_magic_string_sizes                                   | 47       |
| lit_magic_string_size_block_starts                       | 64       |
| lit_magic_strings                                        | 188      |
| vm_decode_table                                          | 644      |


## Section sizes
| section              | size  |  addr  |
|---------------------------------------|
| .interp              |   25  |  65876 |
| .note.ABI-tag        |   32  |  65904 |
| .note.gnu.build-id   |   36  |  65936 |
| .gnu.hash            |   96  |  65972 |
| .dynsym              |  240  |  66068 |
| .dynstr              |  145  |  66308 |
| .gnu.version         |   30  |  66454 |
| .gnu.version_r       |   32  |  66484 |
| .rel.dyn             |    8  |  66516 |
| .rel.plt             |  112  |  66524 |
| .init                |   12  |  66636 |
| .plt                 |  188  |  66648 |
| .text                | 26460 |  66840 |
| .fini                |    8  |  93300 |
| .rodata              | 1612  |  93308 |
| .ARM.exidx           |    8  |  94920 |
| .eh_frame            |    4  |  94928 |
| .init_array          |    4  | 163596 |
| .fini_array          |    4  | 163600 |
| .jcr                 |    4  | 163604 |
| .dynamic             |  232  | 163608 |
| .got                 |   72  | 163840 |
| .data                |  190  | 163912 |
| .bss                 |  116  | 164104 |
| .comment             |   59  |      0 |
| .ARM.attributes      |   51  |      0 |
| Total                | 29780 |    -   |
