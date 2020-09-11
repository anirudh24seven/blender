#pragma once

/** \file
 * \ingroup bmesh
 */

void BM_mesh_decimate_collapse(BMesh *bm,
                               const float factor,
                               float *vweights,
                               float vweight_factor,
                               const bool do_triangulate,
                               const int symmetry_axis,
                               const float symmetry_eps);

void BM_mesh_decimate_unsubdivide_ex(BMesh *bm, const int iterations, const bool tag_only);
void BM_mesh_decimate_unsubdivide(BMesh *bm, const int iterations);

void BM_mesh_decimate_dissolve_ex(BMesh *bm,
                                  const float angle_limit,
                                  const bool do_dissolve_boundaries,
                                  BMO_Delimit delimit,
                                  BMVert **vinput_arr,
                                  const int vinput_len,
                                  BMEdge **einput_arr,
                                  const int einput_len,
                                  const short oflag_out);
void BM_mesh_decimate_dissolve(BMesh *bm,
                               const float angle_limit,
                               const bool do_dissolve_boundaries,
                               const BMO_Delimit delimit);
