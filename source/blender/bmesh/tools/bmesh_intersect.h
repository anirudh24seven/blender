#pragma once

/** \file
 * \ingroup bmesh
 */

bool BM_mesh_intersect(BMesh *bm,
                       struct BMLoop *(*looptris)[3],
                       const int looptris_tot,
                       int (*test_fn)(BMFace *f, void *user_data),
                       void *user_data,
                       const bool use_self,
                       const bool use_separate,
                       const bool use_dissolve,
                       const bool use_island_connect,
                       const bool use_partial_connect,
                       const bool use_edge_tag,
                       const int boolean_mode,
                       const float eps);

enum {
  BMESH_ISECT_BOOLEAN_NONE = -1,
  /* aligned with BooleanModifierOp */
  BMESH_ISECT_BOOLEAN_ISECT = 0,
  BMESH_ISECT_BOOLEAN_UNION = 1,
  BMESH_ISECT_BOOLEAN_DIFFERENCE = 2,
};
