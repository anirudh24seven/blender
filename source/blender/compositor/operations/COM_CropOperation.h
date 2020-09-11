/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class CropBaseOperation : public NodeOperation {
 protected:
  SocketReader *m_inputOperation;
  NodeTwoXYs *m_settings;
  bool m_relative;
  int m_xmax;
  int m_xmin;
  int m_ymax;
  int m_ymin;

  void updateArea();

 public:
  CropBaseOperation();
  void initExecution();
  void deinitExecution();
  void setCropSettings(NodeTwoXYs *settings)
  {
    this->m_settings = settings;
  }
  void setRelative(bool rel)
  {
    this->m_relative = rel;
  }
};

class CropOperation : public CropBaseOperation {
 private:
 public:
  CropOperation();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class CropImageOperation : public CropBaseOperation {
 private:
 public:
  CropImageOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
