/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class EllipseMaskOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputMask;
  SocketReader *m_inputValue;

  float m_sine;
  float m_cosine;
  float m_aspectRatio;
  int m_maskType;

  NodeEllipseMask *m_data;

 public:
  EllipseMaskOperation();

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

  void setData(NodeEllipseMask *data)
  {
    this->m_data = data;
  }

  void setMaskType(int maskType)
  {
    this->m_maskType = maskType;
  }
};
