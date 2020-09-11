/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetAlphaOperation.h"

SetAlphaOperation::SetAlphaOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addInputSocket(COM_DT_VALUE);
  this->addOutputSocket(COM_DT_COLOR);

  this->m_inputColor = NULL;
  this->m_inputAlpha = NULL;
}

void SetAlphaOperation::initExecution()
{
  this->m_inputColor = getInputSocketReader(0);
  this->m_inputAlpha = getInputSocketReader(1);
}

void SetAlphaOperation::executePixelSampled(float output[4],
                                            float x,
                                            float y,
                                            PixelSampler sampler)
{
  float alphaInput[4];

  this->m_inputColor->readSampled(output, x, y, sampler);
  this->m_inputAlpha->readSampled(alphaInput, x, y, sampler);

  output[3] = alphaInput[0];
}

void SetAlphaOperation::deinitExecution()
{
  this->m_inputColor = NULL;
  this->m_inputAlpha = NULL;
}
