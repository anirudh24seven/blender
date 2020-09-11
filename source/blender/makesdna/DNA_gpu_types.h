/** \file
 * \ingroup DNA
 */

#pragma once

/* Keep for 'Camera' versioning. */
/** Properties for dof effect. */
typedef struct GPUDOFSettings {
  /** Focal distance for depth of field. */
  float focus_distance;
  float fstop;
  float focal_length;
  float sensor;
  float rotation;
  float ratio;
  int num_blades;
  int high_quality;
} GPUDOFSettings;
