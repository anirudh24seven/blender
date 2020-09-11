#pragma once

/** \file
 * \ingroup bmesh
 */

int BM_mesh_region_match(BMesh *bm,
                         BMFace **faces_region,
                         uint faces_region_len,
                         ListBase *r_face_regions);
