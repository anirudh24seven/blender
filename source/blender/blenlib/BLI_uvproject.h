#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct ProjCameraInfo;

/* create uv info from the camera, needs to be freed */
struct ProjCameraInfo *BLI_uvproject_camera_info(struct Object *ob,
                                                 float rotmat[4][4],
                                                 float winx,
                                                 float winy);

/* apply uv from uvinfo (camera) */
void BLI_uvproject_from_camera(float target[2], float source[3], struct ProjCameraInfo *uci);

/* apply uv from perspective matrix */
void BLI_uvproject_from_view(float target[2],
                             float source[3],
                             float persmat[4][4],
                             float rotmat[4][4],
                             float winx,
                             float winy);

/* apply ortho uv's */
void BLI_uvproject_from_view_ortho(float target[2], float source[3], const float rotmat[4][4]);

/* so we can adjust scale with keeping the struct private */
void BLI_uvproject_camera_info_scale(struct ProjCameraInfo *uci, float scale_x, float scale_y);

#ifdef __cplusplus
}
#endif
