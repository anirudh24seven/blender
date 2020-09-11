/** \file
 * \ingroup gpu
 */

#pragma once

#include "BLI_sys_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct rcti;

/* flags for mode of operation */
enum {
  GPU_SELECT_ALL = 1,
  /* gpu_select_query */
  GPU_SELECT_NEAREST_FIRST_PASS = 2,
  GPU_SELECT_NEAREST_SECOND_PASS = 3,
  /* gpu_select_pick */
  GPU_SELECT_PICK_ALL = 4,
  GPU_SELECT_PICK_NEAREST = 5,
};

void GPU_select_begin(
    unsigned int *buffer, unsigned int bufsize, const struct rcti *input, char mode, int oldhits);
bool GPU_select_load_id(unsigned int id);
void GPU_select_finalize(void);
unsigned int GPU_select_end(void);

/* cache selection region */
bool GPU_select_is_cached(void);
void GPU_select_cache_begin(void);
void GPU_select_cache_load_id(void);
void GPU_select_cache_end(void);

/* utilities */
const uint *GPU_select_buffer_near(const uint *buffer, int hits);
uint GPU_select_buffer_remove_by_id(uint *buffer, int hits, uint select_id);
void GPU_select_buffer_stride_realign(const struct rcti *src, const struct rcti *dst, uint *r_buf);

#ifdef __cplusplus
}
#endif
