#pragma once

/** \file
 * \ingroup bli
 */

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLI_MEM_BLOCK_CHUNK_SIZE (1 << 15) /* 32KiB */

struct BLI_memblock;

typedef struct BLI_memblock BLI_memblock;
typedef void (*MemblockValFreeFP)(void *val);

BLI_memblock *BLI_memblock_create_ex(uint elem_size, uint chunk_size) ATTR_WARN_UNUSED_RESULT;
void *BLI_memblock_alloc(BLI_memblock *mblk) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
void BLI_memblock_clear(BLI_memblock *mblk, MemblockValFreeFP free_callback) ATTR_NONNULL(1);
void BLI_memblock_destroy(BLI_memblock *mblk, MemblockValFreeFP free_callback) ATTR_NONNULL(1);

#define BLI_memblock_create(elem_size) BLI_memblock_create_ex(elem_size, BLI_MEM_BLOCK_CHUNK_SIZE)

typedef struct BLI_memblock_iter {
  void **chunk_list;
  int cur_index;
  int end_index;
  int chunk_max_ofs;
  int chunk_idx;
  int elem_size;
  int elem_ofs;
} BLI_memblock_iter;

void BLI_memblock_iternew(BLI_memblock *mblk, BLI_memblock_iter *iter) ATTR_NONNULL();
void *BLI_memblock_iterstep(BLI_memblock_iter *iter) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

void *BLI_memblock_elem_get(BLI_memblock *mblk, int chunk, int elem) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

#ifdef __cplusplus
}
#endif
