/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetSamplerOperation.h"

SetSamplerOperation::SetSamplerOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);
}

void SetSamplerOperation::initExecution()
{
  this->m_reader = this->getInputSocketReader(0);
}
void SetSamplerOperation::deinitExecution()
{
  this->m_reader = NULL;
}

void SetSamplerOperation::executePixelSampled(float output[4],
                                              float x,
                                              float y,
                                              PixelSampler /*sampler*/)
{
  this->m_reader->readSampled(output, x, y, this->m_sampler);
}
