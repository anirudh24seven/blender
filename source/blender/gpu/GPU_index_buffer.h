/** \file
 * \ingroup gpu
 *
 * GPU index buffer
 */

#pragma once

#include "GPU_primitive.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Opaque type hiding blender::gpu::IndexBuf. */
typedef struct GPUIndexBuf GPUIndexBuf;

GPUIndexBuf *GPU_indexbuf_calloc(void);

typedef struct GPUIndexBufBuilder {
  uint max_allowed_index;
  uint max_index_len;
  uint index_len;
  GPUPrimType prim_type;
  uint32_t *data;
} GPUIndexBufBuilder;

/* supports all primitive types. */
void GPU_indexbuf_init_ex(GPUIndexBufBuilder *, GPUPrimType, uint index_len, uint vertex_len);

/* supports only GPU_PRIM_POINTS, GPU_PRIM_LINES and GPU_PRIM_TRIS. */
void GPU_indexbuf_init(GPUIndexBufBuilder *, GPUPrimType, uint prim_len, uint vertex_len);

void GPU_indexbuf_add_generic_vert(GPUIndexBufBuilder *, uint v);
void GPU_indexbuf_add_primitive_restart(GPUIndexBufBuilder *);

void GPU_indexbuf_add_point_vert(GPUIndexBufBuilder *, uint v);
void GPU_indexbuf_add_line_verts(GPUIndexBufBuilder *, uint v1, uint v2);
void GPU_indexbuf_add_tri_verts(GPUIndexBufBuilder *, uint v1, uint v2, uint v3);
void GPU_indexbuf_add_line_adj_verts(GPUIndexBufBuilder *, uint v1, uint v2, uint v3, uint v4);

void GPU_indexbuf_set_point_vert(GPUIndexBufBuilder *builder, uint elem, uint v1);
void GPU_indexbuf_set_line_verts(GPUIndexBufBuilder *builder, uint elem, uint v1, uint v2);
void GPU_indexbuf_set_tri_verts(GPUIndexBufBuilder *builder, uint elem, uint v1, uint v2, uint v3);

/* Skip primitive rendering at the given index. */
void GPU_indexbuf_set_point_restart(GPUIndexBufBuilder *builder, uint elem);
void GPU_indexbuf_set_line_restart(GPUIndexBufBuilder *builder, uint elem);
void GPU_indexbuf_set_tri_restart(GPUIndexBufBuilder *builder, uint elem);

GPUIndexBuf *GPU_indexbuf_build(GPUIndexBufBuilder *);
void GPU_indexbuf_build_in_place(GPUIndexBufBuilder *, GPUIndexBuf *);

/* Create a subrange of an existing indexbuffer. */
GPUIndexBuf *GPU_indexbuf_create_subrange(GPUIndexBuf *elem_src, uint start, uint length);
void GPU_indexbuf_create_subrange_in_place(GPUIndexBuf *elem,
                                           GPUIndexBuf *elem_src,
                                           uint start,
                                           uint length);

void GPU_indexbuf_discard(GPUIndexBuf *elem);

bool GPU_indexbuf_is_init(GPUIndexBuf *elem);

int GPU_indexbuf_primitive_len(GPUPrimType prim_type);

/* Macros */

#define GPU_INDEXBUF_DISCARD_SAFE(elem) \
  do { \
    if (elem != NULL) { \
      GPU_indexbuf_discard(elem); \
      elem = NULL; \
    } \
  } while (0)

#ifdef __cplusplus
}
#endif
