#pragma once

/** \file
 * \ingroup bmesh
 */

#ifdef __cplusplus
extern "C" {
#endif

void BM_mesh_edgesplit(BMesh *bm,
                       const bool use_verts,
                       const bool tag_only,
                       const bool copy_select);

#ifdef __cplusplus
}
#endif
