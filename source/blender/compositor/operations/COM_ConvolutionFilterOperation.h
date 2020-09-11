/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class ConvolutionFilterOperation : public NodeOperation {
 private:
  int m_filterWidth;
  int m_filterHeight;

 protected:
  SocketReader *m_inputOperation;
  SocketReader *m_inputValueOperation;
  float m_filter[9];

 public:
  ConvolutionFilterOperation();
  void set3x3Filter(
      float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9);
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixel(float output[4], int x, int y, void *data);

  void initExecution();
  void deinitExecution();
};
