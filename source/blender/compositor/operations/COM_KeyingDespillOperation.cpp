/** Copyright 2012, Blender Foundation.
 */

#include "COM_KeyingDespillOperation.h"

#include "MEM_guardedalloc.h"

#include "BLI_listbase.h"
#include "BLI_math.h"

KeyingDespillOperation::KeyingDespillOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);

  this->m_despillFactor = 0.5f;
  this->m_colorBalance = 0.5f;

  this->m_pixelReader = NULL;
  this->m_screenReader = NULL;
}

void KeyingDespillOperation::initExecution()
{
  this->m_pixelReader = this->getInputSocketReader(0);
  this->m_screenReader = this->getInputSocketReader(1);
}

void KeyingDespillOperation::deinitExecution()
{
  this->m_pixelReader = NULL;
  this->m_screenReader = NULL;
}

void KeyingDespillOperation::executePixelSampled(float output[4],
                                                 float x,
                                                 float y,
                                                 PixelSampler sampler)
{
  float pixelColor[4];
  float screenColor[4];

  this->m_pixelReader->readSampled(pixelColor, x, y, sampler);
  this->m_screenReader->readSampled(screenColor, x, y, sampler);

  const int screen_primary_channel = max_axis_v3(screenColor);
  const int other_1 = (screen_primary_channel + 1) % 3;
  const int other_2 = (screen_primary_channel + 2) % 3;

  const int min_channel = min(other_1, other_2);
  const int max_channel = max(other_1, other_2);

  float average_value, amount;

  average_value = this->m_colorBalance * pixelColor[min_channel] +
                  (1.0f - this->m_colorBalance) * pixelColor[max_channel];
  amount = (pixelColor[screen_primary_channel] - average_value);

  copy_v4_v4(output, pixelColor);

  const float amount_despill = this->m_despillFactor * amount;
  if (amount_despill > 0.0f) {
    output[screen_primary_channel] = pixelColor[screen_primary_channel] - amount_despill;
  }
}
