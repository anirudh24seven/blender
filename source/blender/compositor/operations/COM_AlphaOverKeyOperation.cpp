/** Copyright 2011, Blender Foundation.
 */

#include "COM_AlphaOverKeyOperation.h"

AlphaOverKeyOperation::AlphaOverKeyOperation() : MixBaseOperation()
{
  /* pass */
}

void AlphaOverKeyOperation::executePixelSampled(float output[4],
                                                float x,
                                                float y,
                                                PixelSampler sampler)
{
  float inputColor1[4];
  float inputOverColor[4];
  float value[4];

  this->m_inputValueOperation->readSampled(value, x, y, sampler);
  this->m_inputColor1Operation->readSampled(inputColor1, x, y, sampler);
  this->m_inputColor2Operation->readSampled(inputOverColor, x, y, sampler);

  if (inputOverColor[3] <= 0.0f) {
    copy_v4_v4(output, inputColor1);
  }
  else if (value[0] == 1.0f && inputOverColor[3] >= 1.0f) {
    copy_v4_v4(output, inputOverColor);
  }
  else {
    float premul = value[0] * inputOverColor[3];
    float mul = 1.0f - premul;

    output[0] = (mul * inputColor1[0]) + premul * inputOverColor[0];
    output[1] = (mul * inputColor1[1]) + premul * inputOverColor[1];
    output[2] = (mul * inputColor1[2]) + premul * inputOverColor[2];
    output[3] = (mul * inputColor1[3]) + value[0] * inputOverColor[3];
  }
}
