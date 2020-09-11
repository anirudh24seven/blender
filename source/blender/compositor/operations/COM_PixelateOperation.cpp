/** Copyright 2011, Blender Foundation.
 */

#include "COM_PixelateOperation.h"

PixelateOperation::PixelateOperation(DataType datatype) : NodeOperation()
{
  this->addInputSocket(datatype);
  this->addOutputSocket(datatype);
  this->setResolutionInputSocketIndex(0);
  this->m_inputOperation = NULL;
}

void PixelateOperation::initExecution()
{
  this->m_inputOperation = this->getInputSocketReader(0);
}

void PixelateOperation::deinitExecution()
{
  this->m_inputOperation = NULL;
}

void PixelateOperation::executePixelSampled(float output[4],
                                            float x,
                                            float y,
                                            PixelSampler sampler)
{
  float nx = round(x);
  float ny = round(y);
  this->m_inputOperation->readSampled(output, nx, ny, sampler);
}
