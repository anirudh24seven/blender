/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_ConvolutionFilterOperation.h"

class ConvolutionEdgeFilterOperation : public ConvolutionFilterOperation {
 public:
  ConvolutionEdgeFilterOperation();
  void executePixel(float output[4], int x, int y, void *data);
};
