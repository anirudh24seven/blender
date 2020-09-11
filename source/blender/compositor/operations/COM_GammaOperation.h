/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class GammaOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;
  SocketReader *m_inputGammaProgram;

 public:
  GammaOperation();

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
};
