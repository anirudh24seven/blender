/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class InvertOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputValueProgram;
  SocketReader *m_inputColorProgram;

  bool m_alpha;
  bool m_color;

 public:
  InvertOperation();

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

  void setColor(bool color)
  {
    this->m_color = color;
  }
  void setAlpha(bool alpha)
  {
    this->m_alpha = alpha;
  }
};
