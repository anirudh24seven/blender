/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_ReadBufferOperation.h"

class WrapOperation : public ReadBufferOperation {
 private:
  int m_wrappingType;

 public:
  WrapOperation(DataType datatype);
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void setWrapping(int wrapping_type);
  float getWrappedOriginalXPos(float x);
  float getWrappedOriginalYPos(float y);

  void setFactorXY(float factorX, float factorY);
};
