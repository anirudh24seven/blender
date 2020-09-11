/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class AlphaOverMixedOperation : public MixBaseOperation {
 private:
  float m_x;

 public:
  /**
   * Default constructor
   */
  AlphaOverMixedOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void setX(float x)
  {
    this->m_x = x;
  }
};
