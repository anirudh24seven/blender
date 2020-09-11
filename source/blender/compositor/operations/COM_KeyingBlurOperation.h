/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * Class with implementation of blurring for keying node
 */
class KeyingBlurOperation : public NodeOperation {
 protected:
  int m_size;
  int m_axis;

 public:
  enum BlurAxis {
    BLUR_AXIS_X = 0,
    BLUR_AXIS_Y = 1,
  };

  KeyingBlurOperation();

  void setSize(int value)
  {
    this->m_size = value;
  }
  void setAxis(int value)
  {
    this->m_axis = value;
  }

  void *initializeTileData(rcti *rect);

  void executePixel(float output[4], int x, int y, void *data);

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
