/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class FlipOperation : public NodeOperation {
 private:
  SocketReader *m_inputOperation;
  bool m_flipX;
  bool m_flipY;

 public:
  FlipOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();
  void setFlipX(bool flipX)
  {
    this->m_flipX = flipX;
  }
  void setFlipY(bool flipY)
  {
    this->m_flipY = flipY;
  }
};
