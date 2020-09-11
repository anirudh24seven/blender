/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include <string.h>

#include "COM_NodeOperation.h"

#include "BLI_listbase.h"

/**
 * Class with implementation of keying node
 */
class KeyingOperation : public NodeOperation {
 protected:
  SocketReader *m_pixelReader;
  SocketReader *m_screenReader;

  float m_screenBalance;

 public:
  KeyingOperation();

  void initExecution();
  void deinitExecution();

  void setScreenBalance(float value)
  {
    this->m_screenBalance = value;
  }

  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
