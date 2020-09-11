/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class AlphaOverPremultiplyOperation : public MixBaseOperation {
 public:
  /**
   * Default constructor
   */
  AlphaOverPremultiplyOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
