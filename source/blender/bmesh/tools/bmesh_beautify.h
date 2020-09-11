#pragma once

/** \file
 * \ingroup bmesh
 */

enum {
  /** Vertices tags must match (special case). */
  VERT_RESTRICT_TAG = (1 << 0),
  /** Don't rotate out of degenerate state (needed for iterative rotation). */
  EDGE_RESTRICT_DEGENERATE = (1 << 1),
};

void BM_mesh_beautify_fill(BMesh *bm,
                           BMEdge **edge_array,
                           const int edge_array_len,
                           const short flag,
                           const short method,
                           const short oflag_edge,
                           const short oflag_face);

float BM_verts_calc_rotate_beauty(const BMVert *v1,
                                  const BMVert *v2,
                                  const BMVert *v3,
                                  const BMVert *v4,
                                  const short flag,
                                  const short method);
