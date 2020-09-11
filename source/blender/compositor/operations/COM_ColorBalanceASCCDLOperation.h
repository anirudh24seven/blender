/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ColorBalanceASCCDLOperation : public NodeOperation {
 protected:
  /**
   * Prefetched reference to the inputProgram
   */
  SocketReader *m_inputValueOperation;
  SocketReader *m_inputColorOperation;

  float m_offset[3];
  float m_power[3];
  float m_slope[3];

 public:
  /**
   * Default constructor
   */
  ColorBalanceASCCDLOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setOffset(float offset[3])
  {
    copy_v3_v3(this->m_offset, offset);
  }
  void setPower(float power[3])
  {
    copy_v3_v3(this->m_power, power);
  }
  void setSlope(float slope[3])
  {
    copy_v3_v3(this->m_slope, slope);
  }
};
