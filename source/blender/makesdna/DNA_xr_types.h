/** \file
 * \ingroup DNA
 */

#pragma once

#include "DNA_view3d_types.h"

typedef struct XrSessionSettings {
  /** Shading settings, struct shared with 3D-View so settings are the same. */
  struct View3DShading shading;

  char _pad[7];

  char base_pose_type; /* eXRSessionBasePoseType */
  /** Object to take the location and rotation as base position from. */
  Object *base_pose_object;
  float base_pose_location[3];
  float base_pose_angle;

  /** View3D draw flags (V3D_OFSDRAW_NONE, V3D_OFSDRAW_SHOW_ANNOTATION, ...). */
  char draw_flags;
  char _pad2[3];

  /** Clipping distance. */
  float clip_start, clip_end;

  int flag;
} XrSessionSettings;

typedef enum eXrSessionFlag {
  XR_SESSION_USE_POSITION_TRACKING = (1 << 0),
} eXrSessionFlag;

typedef enum eXRSessionBasePoseType {
  XR_BASE_POSE_SCENE_CAMERA = 0,
  XR_BASE_POSE_OBJECT = 1,
  XR_BASE_POSE_CUSTOM = 2,
} eXRSessionBasePoseType;
