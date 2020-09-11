#pragma once

/** \file
 * \ingroup bli
 */

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLI_Stack BLI_Stack;

BLI_Stack *BLI_stack_new_ex(const size_t elem_size,
                            const char *description,
                            const size_t chunk_size) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();
BLI_Stack *BLI_stack_new(const size_t elem_size, const char *description) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

void BLI_stack_free(BLI_Stack *stack) ATTR_NONNULL();

void *BLI_stack_push_r(BLI_Stack *stack) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();
void BLI_stack_push(BLI_Stack *stack, const void *src) ATTR_NONNULL();

void BLI_stack_pop_n(BLI_Stack *stack, void *dst, unsigned int n) ATTR_NONNULL();
void BLI_stack_pop_n_reverse(BLI_Stack *stack, void *dst, unsigned int n) ATTR_NONNULL();
void BLI_stack_pop(BLI_Stack *stack, void *dst) ATTR_NONNULL();

void *BLI_stack_peek(BLI_Stack *stack) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();
void BLI_stack_discard(BLI_Stack *stack) ATTR_NONNULL();
void BLI_stack_clear(BLI_Stack *stack) ATTR_NONNULL();

size_t BLI_stack_count(const BLI_Stack *stack) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

bool BLI_stack_is_empty(const BLI_Stack *stack) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

#ifdef __cplusplus
}
#endif
