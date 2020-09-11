/** Copyright 2011, Blender Foundation.
 */

#include "COM_DistanceRGBMatteOperation.h"
#include "BLI_math.h"

DistanceRGBMatteOperation::DistanceRGBMatteOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_VALUE);

  this->m_inputImageProgram = NULL;
  this->m_inputKeyProgram = NULL;
}

void DistanceRGBMatteOperation::initExecution()
{
  this->m_inputImageProgram = this->getInputSocketReader(0);
  this->m_inputKeyProgram = this->getInputSocketReader(1);
}

void DistanceRGBMatteOperation::deinitExecution()
{
  this->m_inputImageProgram = NULL;
  this->m_inputKeyProgram = NULL;
}

float DistanceRGBMatteOperation::calculateDistance(float key[4], float image[4])
{
  return len_v3v3(key, image);
}

void DistanceRGBMatteOperation::executePixelSampled(float output[4],
                                                    float x,
                                                    float y,
                                                    PixelSampler sampler)
{
  float inKey[4];
  float inImage[4];

  const float tolerance = this->m_settings->t1;
  const float falloff = this->m_settings->t2;

  float distance;
  float alpha;

  this->m_inputKeyProgram->readSampled(inKey, x, y, sampler);
  this->m_inputImageProgram->readSampled(inImage, x, y, sampler);

  distance = this->calculateDistance(inKey, inImage);

  /* store matte(alpha) value in [0] to go with
   * COM_SetAlphaOperation and the Value output
   */

  /*make 100% transparent */
  if (distance < tolerance) {
    output[0] = 0.0f;
  }
  /*in the falloff region, make partially transparent */
  else if (distance < falloff + tolerance) {
    distance = distance - tolerance;
    alpha = distance / falloff;
    /*only change if more transparent than before */
    if (alpha < inImage[3]) {
      output[0] = alpha;
    }
    else { /* leave as before */
      output[0] = inImage[3];
    }
  }
  else {
    /* leave as before */
    output[0] = inImage[3];
  }
}
