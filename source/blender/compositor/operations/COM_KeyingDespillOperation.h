/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * Class with implementation of keying despill node
 */
class KeyingDespillOperation : public NodeOperation {
 protected:
  SocketReader *m_pixelReader;
  SocketReader *m_screenReader;
  float m_despillFactor;
  float m_colorBalance;

 public:
  KeyingDespillOperation();

  void initExecution();
  void deinitExecution();

  void setDespillFactor(float value)
  {
    this->m_despillFactor = value;
  }
  void setColorBalance(float value)
  {
    this->m_colorBalance = value;
  }

  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
