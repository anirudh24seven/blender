/** Copyright 2011, Blender Foundation.
 */

#include "COM_GlareBaseOperation.h"
#include "BLI_math.h"

GlareBaseOperation::GlareBaseOperation() : SingleThreadedOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);
  this->m_settings = NULL;
}
void GlareBaseOperation::initExecution()
{
  SingleThreadedOperation::initExecution();
  this->m_inputProgram = getInputSocketReader(0);
}

void GlareBaseOperation::deinitExecution()
{
  this->m_inputProgram = NULL;
  SingleThreadedOperation::deinitExecution();
}

MemoryBuffer *GlareBaseOperation::createMemoryBuffer(rcti *rect2)
{
  MemoryBuffer *tile = (MemoryBuffer *)this->m_inputProgram->initializeTileData(rect2);
  rcti rect;
  rect.xmin = 0;
  rect.ymin = 0;
  rect.xmax = getWidth();
  rect.ymax = getHeight();
  MemoryBuffer *result = new MemoryBuffer(COM_DT_COLOR, &rect);
  float *data = result->getBuffer();
  this->generateGlare(data, tile, this->m_settings);
  return result;
}

bool GlareBaseOperation::determineDependingAreaOfInterest(rcti * /*input*/,
                                                          ReadBufferOperation *readOperation,
                                                          rcti *output)
{
  if (isCached()) {
    return false;
  }

  rcti newInput;
  newInput.xmax = this->getWidth();
  newInput.xmin = 0;
  newInput.ymax = this->getHeight();
  newInput.ymin = 0;
  return NodeOperation::determineDependingAreaOfInterest(&newInput, readOperation, output);
}
