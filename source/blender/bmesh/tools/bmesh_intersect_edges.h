/** \file
 * \ingroup bmesh
 */

#pragma once

bool BM_mesh_intersect_edges(
    BMesh *bm, const char hflag, const float dist, const bool split_faces, GHash *r_targetmap);
