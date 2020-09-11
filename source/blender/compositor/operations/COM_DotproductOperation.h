/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class DotproductOperation : public NodeOperation {
 private:
  SocketReader *m_input1Operation;
  SocketReader *m_input2Operation;

 public:
  DotproductOperation();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();
};
