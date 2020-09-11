#pragma once

/** \file
 * \ingroup bli
 * \brief A min-heap / priority queue ADT
 */

#ifdef __cplusplus
extern "C" {
#endif

struct HeapSimple;
typedef struct HeapSimple HeapSimple;

typedef void (*HeapSimpleFreeFP)(void *ptr);

HeapSimple *BLI_heapsimple_new_ex(unsigned int tot_reserve) ATTR_WARN_UNUSED_RESULT;
HeapSimple *BLI_heapsimple_new(void) ATTR_WARN_UNUSED_RESULT;
void BLI_heapsimple_clear(HeapSimple *heap, HeapSimpleFreeFP ptrfreefp) ATTR_NONNULL(1);
void BLI_heapsimple_free(HeapSimple *heap, HeapSimpleFreeFP ptrfreefp) ATTR_NONNULL(1);
void BLI_heapsimple_insert(HeapSimple *heap, float value, void *ptr) ATTR_NONNULL(1);
bool BLI_heapsimple_is_empty(const HeapSimple *heap) ATTR_NONNULL(1);
uint BLI_heapsimple_len(const HeapSimple *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
float BLI_heapsimple_top_value(const HeapSimple *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
void *BLI_heapsimple_pop_min(HeapSimple *heap) ATTR_NONNULL(1);

#ifdef __cplusplus
}
#endif
