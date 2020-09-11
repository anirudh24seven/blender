/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_DistanceRGBMatteOperation.h"
#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class DistanceYCCMatteOperation : public DistanceRGBMatteOperation {
 protected:
  virtual float calculateDistance(float key[4], float image[4]);

 public:
  /**
   * Default constructor
   */
  DistanceYCCMatteOperation();
};
