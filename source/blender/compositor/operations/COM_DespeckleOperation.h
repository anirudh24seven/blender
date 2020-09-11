/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class DespeckleOperation : public NodeOperation {
 private:
  float m_threshold;
  float m_threshold_neighbor;

  // int m_filterWidth;
  // int m_filterHeight;

 protected:
  SocketReader *m_inputOperation;
  SocketReader *m_inputValueOperation;

 public:
  DespeckleOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixel(float output[4], int x, int y, void *data);

  void setThreshold(float threshold)
  {
    this->m_threshold = threshold;
  }
  void setThresholdNeighbor(float threshold)
  {
    this->m_threshold_neighbor = threshold;
  }

  void initExecution();
  void deinitExecution();
};
