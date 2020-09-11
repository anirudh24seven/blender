/** Copyright 2011, Blender Foundation.
 */

#include "COM_InvertOperation.h"

InvertOperation::InvertOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_VALUE);
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);
  this->m_inputValueProgram = NULL;
  this->m_inputColorProgram = NULL;
  this->m_color = true;
  this->m_alpha = false;
  setResolutionInputSocketIndex(1);
}
void InvertOperation::initExecution()
{
  this->m_inputValueProgram = this->getInputSocketReader(0);
  this->m_inputColorProgram = this->getInputSocketReader(1);
}

void InvertOperation::executePixelSampled(float output[4], float x, float y, PixelSampler sampler)
{
  float inputValue[4];
  float inputColor[4];
  this->m_inputValueProgram->readSampled(inputValue, x, y, sampler);
  this->m_inputColorProgram->readSampled(inputColor, x, y, sampler);

  const float value = inputValue[0];
  const float invertedValue = 1.0f - value;

  if (this->m_color) {
    output[0] = (1.0f - inputColor[0]) * value + inputColor[0] * invertedValue;
    output[1] = (1.0f - inputColor[1]) * value + inputColor[1] * invertedValue;
    output[2] = (1.0f - inputColor[2]) * value + inputColor[2] * invertedValue;
  }
  else {
    copy_v3_v3(output, inputColor);
  }

  if (this->m_alpha) {
    output[3] = (1.0f - inputColor[3]) * value + inputColor[3] * invertedValue;
  }
  else {
    output[3] = inputColor[3];
  }
}

void InvertOperation::deinitExecution()
{
  this->m_inputValueProgram = NULL;
  this->m_inputColorProgram = NULL;
}
