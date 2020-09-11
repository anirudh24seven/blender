/** Copyright 2011, Blender Foundation.
 */

#include "COM_ColorRampOperation.h"

#include "BKE_colorband.h"

ColorRampOperation::ColorRampOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_VALUE);
  this->addOutputSocket(COM_DT_COLOR);

  this->m_inputProgram = NULL;
  this->m_colorBand = NULL;
}
void ColorRampOperation::initExecution()
{
  this->m_inputProgram = this->getInputSocketReader(0);
}

void ColorRampOperation::executePixelSampled(float output[4],
                                             float x,
                                             float y,
                                             PixelSampler sampler)
{
  float values[4];

  this->m_inputProgram->readSampled(values, x, y, sampler);
  BKE_colorband_evaluate(this->m_colorBand, values[0], output);
}

void ColorRampOperation::deinitExecution()
{
  this->m_inputProgram = NULL;
}
