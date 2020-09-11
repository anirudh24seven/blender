#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void register_node_type_fn_boolean_math(void);
void register_node_type_fn_float_compare(void);
void register_node_type_fn_switch(void);
void register_node_type_fn_group_instance_id(void);
void register_node_type_fn_combine_strings(void);
void register_node_type_fn_object_transforms(void);
void register_node_type_fn_random_float(void);

#ifdef __cplusplus
}
#endif
