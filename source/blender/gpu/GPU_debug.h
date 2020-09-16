/** \file
 * \ingroup gpu
 *
 * Helpers for GPU / drawing debugging.
 */

#pragma once

#include "BLI_sys_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void GPU_debug_group_begin(const char *name);
void GPU_debug_group_end(void);
void GPU_debug_get_groups_names(int name_buf_len, char *r_name_buf);
bool GPU_debug_group_match(const char *ref);

#ifdef __cplusplus
}
#endif