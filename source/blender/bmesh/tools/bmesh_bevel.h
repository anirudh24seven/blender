#pragma once

/** \file
 * \ingroup bmesh
 */

struct CurveProfile;
struct MDeformVert;

void BM_mesh_bevel(BMesh *bm,
                   const float offset,
                   const int offset_type,
                   const int profile_type,
                   const int segments,
                   const float profile,
                   const bool affect_type,
                   const bool use_weights,
                   const bool limit_offset,
                   const struct MDeformVert *dvert,
                   const int vertex_group,
                   const int mat,
                   const bool loop_slide,
                   const bool mark_seam,
                   const bool mark_sharp,
                   const bool harden_normals,
                   const int face_strength_mode,
                   const int miter_outer,
                   const int miter_inner,
                   const float spread,
                   const float smoothresh,
                   const struct CurveProfile *custom_profile,
                   const int vmesh_method);
