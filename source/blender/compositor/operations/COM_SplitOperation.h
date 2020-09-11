/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class SplitOperation : public NodeOperation {
 private:
  SocketReader *m_image1Input;
  SocketReader *m_image2Input;

  float m_splitPercentage;
  bool m_xSplit;

 public:
  SplitOperation();
  void initExecution();
  void deinitExecution();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
  void setSplitPercentage(float splitPercentage)
  {
    this->m_splitPercentage = splitPercentage;
  }
  void setXSplit(bool xsplit)
  {
    this->m_xSplit = xsplit;
  }
};
