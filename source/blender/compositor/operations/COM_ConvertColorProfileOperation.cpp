/** Copyright 2011, Blender Foundation.
 */

#include "COM_ConvertColorProfileOperation.h"

#include "IMB_imbuf.h"

ConvertColorProfileOperation::ConvertColorProfileOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);
  this->m_inputOperation = NULL;
  this->m_predivided = false;
}

void ConvertColorProfileOperation::initExecution()
{
  this->m_inputOperation = this->getInputSocketReader(0);
}

void ConvertColorProfileOperation::executePixelSampled(float output[4],
                                                       float x,
                                                       float y,
                                                       PixelSampler sampler)
{
  float color[4];
  this->m_inputOperation->readSampled(color, x, y, sampler);
  IMB_buffer_float_from_float(
      output, color, 4, this->m_toProfile, this->m_fromProfile, this->m_predivided, 1, 1, 0, 0);
}

void ConvertColorProfileOperation::deinitExecution()
{
  this->m_inputOperation = NULL;
}
