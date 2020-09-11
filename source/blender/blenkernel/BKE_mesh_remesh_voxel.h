#pragma once

/** \file
 * \ingroup bke
 */

#ifdef WITH_OPENVDB
#  include "openvdb_capi.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct Mesh;

/* OpenVDB Voxel Remesher */
#ifdef WITH_OPENVDB
struct OpenVDBLevelSet *BKE_mesh_remesh_voxel_ovdb_mesh_to_level_set_create(
    struct Mesh *mesh, struct OpenVDBTransform *transform);
struct Mesh *BKE_mesh_remesh_voxel_ovdb_volume_to_mesh_nomain(struct OpenVDBLevelSet *level_set,
                                                              double isovalue,
                                                              double adaptivity,
                                                              bool relax_disoriented_triangles);
#endif

struct Mesh *BKE_mesh_remesh_voxel_fix_poles(struct Mesh *mesh);
struct Mesh *BKE_mesh_remesh_voxel_to_mesh_nomain(struct Mesh *mesh,
                                                  float voxel_size,
                                                  float adaptivity,
                                                  float isovalue);
struct Mesh *BKE_mesh_remesh_quadriflow_to_mesh_nomain(struct Mesh *mesh,
                                                       int target_faces,
                                                       int seed,
                                                       bool preserve_sharp,
                                                       bool preserve_boundary,
                                                       bool adaptive_scale,
                                                       void *update_cb,
                                                       void *update_cb_data);

/* Data reprojection functions */
void BKE_mesh_remesh_reproject_paint_mask(struct Mesh *target, struct Mesh *source);
void BKE_remesh_reproject_vertex_paint(struct Mesh *target, struct Mesh *source);
void BKE_remesh_reproject_sculpt_face_sets(struct Mesh *target, struct Mesh *source);

#ifdef __cplusplus
}
#endif
