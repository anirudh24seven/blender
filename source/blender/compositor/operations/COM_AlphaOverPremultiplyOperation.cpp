/** Copyright 2011, Blender Foundation.
 */

#include "COM_AlphaOverPremultiplyOperation.h"

AlphaOverPremultiplyOperation::AlphaOverPremultiplyOperation() : MixBaseOperation()
{
  /* pass */
}

void AlphaOverPremultiplyOperation::executePixelSampled(float output[4],
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

  /* Zero alpha values should still permit an add of RGB data */
  if (inputOverColor[3] < 0.0f) {
    copy_v4_v4(output, inputColor1);
  }
  else if (value[0] == 1.0f && inputOverColor[3] >= 1.0f) {
    copy_v4_v4(output, inputOverColor);
  }
  else {
    float mul = 1.0f - value[0] * inputOverColor[3];

    output[0] = (mul * inputColor1[0]) + value[0] * inputOverColor[0];
    output[1] = (mul * inputColor1[1]) + value[0] * inputOverColor[1];
    output[2] = (mul * inputColor1[2]) + value[0] * inputOverColor[2];
    output[3] = (mul * inputColor1[3]) + value[0] * inputOverColor[3];
  }
}
