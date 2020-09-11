/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class SetVectorOperation : public NodeOperation {
 private:
  float m_x;
  float m_y;
  float m_z;
  float m_w;

 public:
  /**
   * Default constructor
   */
  SetVectorOperation();

  float getX()
  {
    return this->m_x;
  }
  void setX(float value)
  {
    this->m_x = value;
  }
  float getY()
  {
    return this->m_y;
  }
  void setY(float value)
  {
    this->m_y = value;
  }
  float getZ()
  {
    return this->m_z;
  }
  void setZ(float value)
  {
    this->m_z = value;
  }
  float getW()
  {
    return this->m_w;
  }
  void setW(float value)
  {
    this->m_w = value;
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

  void setVector(const float vector[3])
  {
    setX(vector[0]);
    setY(vector[1]);
    setZ(vector[2]);
  }
};
