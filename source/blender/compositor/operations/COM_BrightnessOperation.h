/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class BrightnessOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;
  SocketReader *m_inputBrightnessProgram;
  SocketReader *m_inputContrastProgram;

  bool m_use_premultiply;

 public:
  BrightnessOperation();

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

  void setUsePremultiply(bool use_premultiply);
};
