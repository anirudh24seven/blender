/** \file
 * \ingroup bli
 */

#pragma once

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* A reasonable standard buffer size, big
 * enough to not cause much internal fragmentation,
 * small enough not to waste resources
 */
#define BLI_MEMARENA_STD_BUFSIZE MEM_SIZE_OPTIMAL(1 << 14)

struct MemArena;
typedef struct MemArena MemArena;

struct MemArena *BLI_memarena_new(const size_t bufsize, const char *name) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(2) ATTR_MALLOC;
void BLI_memarena_free(struct MemArena *ma) ATTR_NONNULL(1);
void BLI_memarena_use_malloc(struct MemArena *ma) ATTR_NONNULL(1);
void BLI_memarena_use_calloc(struct MemArena *ma) ATTR_NONNULL(1);
void BLI_memarena_use_align(struct MemArena *ma, const size_t align) ATTR_NONNULL(1);
void *BLI_memarena_alloc(struct MemArena *ma, size_t size) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1) ATTR_MALLOC ATTR_ALLOC_SIZE(2);
void *BLI_memarena_calloc(struct MemArena *ma, size_t size) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1) ATTR_MALLOC ATTR_ALLOC_SIZE(2);

void BLI_memarena_clear(MemArena *ma) ATTR_NONNULL(1);

#ifdef __cplusplus
}
#endif
