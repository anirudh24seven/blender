/** Copyright 2013, Blender Foundation.
 */

#pragma once

#include <string.h>

#include "COM_NodeOperation.h"

#include "DNA_movieclip_types.h"
#include "DNA_tracking_types.h"

#include "BLI_listbase.h"
#include "BLI_string.h"

#define PLANE_DISTORT_MAX_SAMPLES 64

class PlaneDistortWarpImageOperation : public NodeOperation {
 protected:
  struct MotionSample {
    float frameSpaceCorners[4][2]; /* Corners coordinates in pixel space. */
    float perspectiveMatrix[3][3];
  };
  SocketReader *m_pixelReader;
  MotionSample m_samples[PLANE_DISTORT_MAX_SAMPLES];
  int m_motion_blur_samples;
  float m_motion_blur_shutter;

 public:
  PlaneDistortWarpImageOperation();

  void calculateCorners(const float corners[4][2], bool normalized, int sample);

  void initExecution();
  void deinitExecution();

  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void setMotionBlurSamples(int samples)
  {
    BLI_assert(samples <= PLANE_DISTORT_MAX_SAMPLES);
    this->m_motion_blur_samples = samples;
  }
  void setMotionBlurShutter(float shutter)
  {
    this->m_motion_blur_shutter = shutter;
  }
};

class PlaneDistortMaskOperation : public NodeOperation {
 protected:
  struct MotionSample {
    float frameSpaceCorners[4][2]; /* Corners coordinates in pixel space. */
  };
  int m_osa;
  MotionSample m_samples[PLANE_DISTORT_MAX_SAMPLES];
  float m_jitter[32][2];
  int m_motion_blur_samples;
  float m_motion_blur_shutter;

 public:
  PlaneDistortMaskOperation();

  void calculateCorners(const float corners[4][2], bool normalized, int sample);

  void initExecution();

  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void setMotionBlurSamples(int samples)
  {
    BLI_assert(samples <= PLANE_DISTORT_MAX_SAMPLES);
    this->m_motion_blur_samples = samples;
  }
  void setMotionBlurShutter(float shutter)
  {
    this->m_motion_blur_shutter = shutter;
  }
};
