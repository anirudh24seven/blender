#pragma once

/** \file
 * \ingroup bmesh
 */

void BM_mesh_separate_faces(BMesh *bm, BMFaceFilterFunc filter_fn, void *user_data);
