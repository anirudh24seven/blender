/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_GlareBaseOperation.h"
#include "COM_NodeOperation.h"
#include "DNA_node_types.h"

class GlareStreaksOperation : public GlareBaseOperation {
 public:
  GlareStreaksOperation() : GlareBaseOperation()
  {
  }

 protected:
  void generateGlare(float *data, MemoryBuffer *inputTile, NodeGlare *settings);
};
