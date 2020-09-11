/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class SetValueOperation : public NodeOperation {
 private:
  float m_value;

 public:
  /**
   * Default constructor
   */
  SetValueOperation();

  float getValue()
  {
    return this->m_value;
  }
  void setValue(float value)
  {
    this->m_value = value;
  }

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

  bool isSetOperation() const
  {
    return true;
  }
};
