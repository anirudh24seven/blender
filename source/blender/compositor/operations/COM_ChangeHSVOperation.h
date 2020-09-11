/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ChangeHSVOperation : public NodeOperation {
 private:
  SocketReader *m_inputOperation;
  SocketReader *m_hueOperation;
  SocketReader *m_saturationOperation;
  SocketReader *m_valueOperation;

 public:
  /**
   * Default constructor
   */
  ChangeHSVOperation();

  void initExecution();
  void deinitExecution();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
