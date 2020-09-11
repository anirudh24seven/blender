/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class SetAlphaOperation : public NodeOperation {
 private:
  SocketReader *m_inputColor;
  SocketReader *m_inputAlpha;

 public:
  /**
   * Default constructor
   */
  SetAlphaOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();
};
