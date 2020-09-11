/** Copyright 2011, Blender Foundation.
 */

#include "COM_IDMaskOperation.h"

IDMaskOperation::IDMaskOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_VALUE);
  this->addOutputSocket(COM_DT_VALUE);
  this->setComplex(true);
}

void *IDMaskOperation::initializeTileData(rcti *rect)
{
  void *buffer = getInputOperation(0)->initializeTileData(rect);
  return buffer;
}

void IDMaskOperation::executePixel(float output[4], int x, int y, void *data)
{
  MemoryBuffer *input_buffer = (MemoryBuffer *)data;
  const int buffer_width = input_buffer->getWidth();
  float *buffer = input_buffer->getBuffer();
  int buffer_index = (y * buffer_width + x);
  output[0] = (roundf(buffer[buffer_index]) == this->m_objectIndex) ? 1.0f : 0.0f;
}
