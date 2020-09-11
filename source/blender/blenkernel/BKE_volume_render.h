#pragma once

/** \file
 * \ingroup bke
 * \brief Volume data-block rendering and viewport drawing utilities.
 */

#include "BLI_sys_types.h"

#include "DNA_volume_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Volume;
struct VolumeGrid;

/* Dense Voxels */

bool BKE_volume_grid_dense_bounds(const struct Volume *volume,
                                  struct VolumeGrid *volume_grid,
                                  int64_t min[3],
                                  int64_t max[3]);
void BKE_volume_grid_dense_transform_matrix(const struct VolumeGrid *volume_grid,
                                            const int64_t min[3],
                                            const int64_t max[3],
                                            float matrix[4][4]);
void BKE_volume_grid_dense_voxels(const struct Volume *volume,
                                  struct VolumeGrid *volume_grid,
                                  const int64_t min[3],
                                  const int64_t max[3],
                                  float *voxels);

/* Wireframe */

typedef void (*BKE_volume_wireframe_cb)(
    void *userdata, float (*verts)[3], int (*edges)[2], int totvert, int totedge);

void BKE_volume_grid_wireframe(const struct Volume *volume,
                               struct VolumeGrid *volume_grid,
                               BKE_volume_wireframe_cb cb,
                               void *cb_userdata);

/* Render */

float BKE_volume_density_scale(const struct Volume *volume, const float matrix[4][4]);

#ifdef __cplusplus
}
#endif
