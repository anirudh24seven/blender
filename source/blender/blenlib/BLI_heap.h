#pragma once

/** \file
 * \ingroup bli
 * \brief A min-heap / priority queue ADT
 */

#include "BLI_math.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Heap;
struct HeapNode;
typedef struct Heap Heap;
typedef struct HeapNode HeapNode;

typedef void (*HeapFreeFP)(void *ptr);

Heap *BLI_heap_new_ex(unsigned int tot_reserve) ATTR_WARN_UNUSED_RESULT;
Heap *BLI_heap_new(void) ATTR_WARN_UNUSED_RESULT;
void BLI_heap_clear(Heap *heap, HeapFreeFP ptrfreefp) ATTR_NONNULL(1);
void BLI_heap_free(Heap *heap, HeapFreeFP ptrfreefp) ATTR_NONNULL(1);
HeapNode *BLI_heap_insert(Heap *heap, float value, void *ptr) ATTR_NONNULL(1);
void BLI_heap_insert_or_update(Heap *heap, HeapNode **node_p, float value, void *ptr)
    ATTR_NONNULL(1, 2);
void BLI_heap_remove(Heap *heap, HeapNode *node) ATTR_NONNULL(1, 2);
bool BLI_heap_is_empty(const Heap *heap) ATTR_NONNULL(1);
unsigned int BLI_heap_len(const Heap *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
HeapNode *BLI_heap_top(const Heap *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
float BLI_heap_top_value(const Heap *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
void *BLI_heap_pop_min(Heap *heap) ATTR_NONNULL(1);
void BLI_heap_node_value_update(Heap *heap, HeapNode *node, float value) ATTR_NONNULL(1, 2);
void BLI_heap_node_value_update_ptr(Heap *heap, HeapNode *node, float value, void *ptr)
    ATTR_NONNULL(1, 2);

/* Return the value or pointer of a heap node. */
float BLI_heap_node_value(const HeapNode *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
void *BLI_heap_node_ptr(const HeapNode *heap) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
/* only for gtest */
bool BLI_heap_is_valid(const Heap *heap);

#ifdef __cplusplus
}
#endif
