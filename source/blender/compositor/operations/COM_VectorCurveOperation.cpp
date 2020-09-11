/** Copyright 2011, Blender Foundation.
 */

#include "COM_VectorCurveOperation.h"

#include "BKE_colortools.h"

VectorCurveOperation::VectorCurveOperation() : CurveBaseOperation()
{
  this->addInputSocket(COM_DT_VECTOR);
  this->addOutputSocket(COM_DT_VECTOR);

  this->m_inputProgram = NULL;
}
void VectorCurveOperation::initExecution()
{
  CurveBaseOperation::initExecution();
  this->m_inputProgram = this->getInputSocketReader(0);
}

void VectorCurveOperation::executePixelSampled(float output[4],
                                               float x,
                                               float y,
                                               PixelSampler sampler)
{
  float input[4];

  this->m_inputProgram->readSampled(input, x, y, sampler);

  BKE_curvemapping_evaluate_premulRGBF(this->m_curveMapping, output, input);
}

void VectorCurveOperation::deinitExecution()
{
  CurveBaseOperation::deinitExecution();
  this->m_inputProgram = NULL;
}
