/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_movieclip_types.h"
#include "MEM_guardedalloc.h"

#include "BKE_tracking.h"

class MovieDistortionOperation : public NodeOperation {
 private:
  SocketReader *m_inputOperation;
  MovieClip *m_movieClip;
  int m_margin[2];

 protected:
  bool m_apply;
  int m_framenumber;

  struct MovieDistortion *m_distortion;
  int m_calibration_width, m_calibration_height;
  float m_pixel_aspect;

 public:
  MovieDistortionOperation(bool distortion);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();

  void setMovieClip(MovieClip *clip)
  {
    this->m_movieClip = clip;
  }
  void setFramenumber(int framenumber)
  {
    this->m_framenumber = framenumber;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
