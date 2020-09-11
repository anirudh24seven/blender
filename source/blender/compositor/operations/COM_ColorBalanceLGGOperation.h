/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ColorBalanceLGGOperation : public NodeOperation {
 protected:
  /**
   * Prefetched reference to the inputProgram
   */
  SocketReader *m_inputValueOperation;
  SocketReader *m_inputColorOperation;

  float m_gain[3];
  float m_lift[3];
  float m_gamma_inv[3];

 public:
  /**
   * Default constructor
   */
  ColorBalanceLGGOperation();

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

  void setGain(const float gain[3])
  {
    copy_v3_v3(this->m_gain, gain);
  }
  void setLift(const float lift[3])
  {
    copy_v3_v3(this->m_lift, lift);
  }
  void setGammaInv(const float gamma_inv[3])
  {
    copy_v3_v3(this->m_gamma_inv, gamma_inv);
  }
};
