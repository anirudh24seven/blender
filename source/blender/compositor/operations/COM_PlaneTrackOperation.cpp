/** Copyright 2013, Blender Foundation.
 */

#include "COM_PlaneTrackOperation.h"
#include "COM_ReadBufferOperation.h"

#include "MEM_guardedalloc.h"

#include "BLI_listbase.h"
#include "BLI_math.h"
#include "BLI_math_color.h"

#include "BKE_movieclip.h"
#include "BKE_node.h"
#include "BKE_tracking.h"

/* ******** PlaneTrackCommon ******** */

PlaneTrackCommon::PlaneTrackCommon()
{
  this->m_movieClip = NULL;
  this->m_framenumber = 0;
  this->m_trackingObjectName[0] = '\0';
  this->m_planeTrackName[0] = '\0';
}

void PlaneTrackCommon::readCornersFromTrack(float corners[4][2], float frame)
{
  MovieTracking *tracking;
  MovieTrackingObject *object;

  if (!this->m_movieClip) {
    return;
  }

  tracking = &this->m_movieClip->tracking;

  object = BKE_tracking_object_get_named(tracking, this->m_trackingObjectName);
  if (object) {
    MovieTrackingPlaneTrack *plane_track;
    plane_track = BKE_tracking_plane_track_get_named(tracking, object, this->m_planeTrackName);
    if (plane_track) {
      float clip_framenr = BKE_movieclip_remap_scene_to_clip_frame(this->m_movieClip, frame);
      BKE_tracking_plane_marker_get_subframe_corners(plane_track, clip_framenr, corners);
    }
  }
}

void PlaneTrackCommon::determineResolution(unsigned int resolution[2],
                                           unsigned int /*preferredResolution*/[2])
{
  resolution[0] = 0;
  resolution[1] = 0;

  if (this->m_movieClip) {
    int width, height;
    MovieClipUser user = {0};
    BKE_movieclip_user_set_frame(&user, this->m_framenumber);
    BKE_movieclip_get_size(this->m_movieClip, &user, &width, &height);
    resolution[0] = width;
    resolution[1] = height;
  }
}

/* ******** PlaneTrackMaskOperation ******** */

void PlaneTrackMaskOperation::initExecution()
{
  PlaneDistortMaskOperation::initExecution();
  float corners[4][2];
  if (this->m_motion_blur_samples == 1) {
    readCornersFromTrack(corners, this->m_framenumber);
    calculateCorners(corners, true, 0);
  }
  else {
    const float frame = (float)this->m_framenumber - this->m_motion_blur_shutter;
    const float frame_step = (this->m_motion_blur_shutter * 2.0f) / this->m_motion_blur_samples;
    float frame_iter = frame;
    for (int sample = 0; sample < this->m_motion_blur_samples; sample++) {
      readCornersFromTrack(corners, frame_iter);
      calculateCorners(corners, true, sample);
      frame_iter += frame_step;
    }
  }
}

/* ******** PlaneTrackWarpImageOperation ******** */

void PlaneTrackWarpImageOperation::initExecution()
{
  PlaneDistortWarpImageOperation::initExecution();
  /* TODO(sergey): De-duplicate with mask operation. */
  float corners[4][2];
  if (this->m_motion_blur_samples == 1) {
    readCornersFromTrack(corners, this->m_framenumber);
    calculateCorners(corners, true, 0);
  }
  else {
    const float frame = (float)this->m_framenumber - this->m_motion_blur_shutter;
    const float frame_step = (this->m_motion_blur_shutter * 2.0f) / this->m_motion_blur_samples;
    float frame_iter = frame;
    for (int sample = 0; sample < this->m_motion_blur_samples; sample++) {
      readCornersFromTrack(corners, frame_iter);
      calculateCorners(corners, true, sample);
      frame_iter += frame_step;
    }
  }
}
