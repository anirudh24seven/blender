/** Copyright 2011, Blender Foundation.
 */

#include "COM_HueSaturationValueCorrectOperation.h"

#include "BLI_math.h"

#include "BKE_colortools.h"

HueSaturationValueCorrectOperation::HueSaturationValueCorrectOperation() : CurveBaseOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);

  this->m_inputProgram = NULL;
}
void HueSaturationValueCorrectOperation::initExecution()
{
  CurveBaseOperation::initExecution();
  this->m_inputProgram = this->getInputSocketReader(0);
}

void HueSaturationValueCorrectOperation::executePixelSampled(float output[4],
                                                             float x,
                                                             float y,
                                                             PixelSampler sampler)
{
  float hsv[4], f;

  this->m_inputProgram->readSampled(hsv, x, y, sampler);

  /* adjust hue, scaling returned default 0.5 up to 1 */
  f = BKE_curvemapping_evaluateF(this->m_curveMapping, 0, hsv[0]);
  hsv[0] += f - 0.5f;

  /* adjust saturation, scaling returned default 0.5 up to 1 */
  f = BKE_curvemapping_evaluateF(this->m_curveMapping, 1, hsv[0]);
  hsv[1] *= (f * 2.0f);

  /* adjust value, scaling returned default 0.5 up to 1 */
  f = BKE_curvemapping_evaluateF(this->m_curveMapping, 2, hsv[0]);
  hsv[2] *= (f * 2.0f);

  hsv[0] = hsv[0] - floorf(hsv[0]); /* mod 1.0 */
  CLAMP(hsv[1], 0.0f, 1.0f);

  output[0] = hsv[0];
  output[1] = hsv[1];
  output[2] = hsv[2];
  output[3] = hsv[3];
}

void HueSaturationValueCorrectOperation::deinitExecution()
{
  CurveBaseOperation::deinitExecution();
  this->m_inputProgram = NULL;
}
