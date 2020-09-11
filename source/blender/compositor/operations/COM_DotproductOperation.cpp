/** Copyright 2011, Blender Foundation.
 */

#include "COM_DotproductOperation.h"

DotproductOperation::DotproductOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_VECTOR);
  this->addInputSocket(COM_DT_VECTOR);
  this->addOutputSocket(COM_DT_VALUE);
  this->setResolutionInputSocketIndex(0);
  this->m_input1Operation = NULL;
  this->m_input2Operation = NULL;
}
void DotproductOperation::initExecution()
{
  this->m_input1Operation = this->getInputSocketReader(0);
  this->m_input2Operation = this->getInputSocketReader(1);
}

void DotproductOperation::deinitExecution()
{
  this->m_input1Operation = NULL;
  this->m_input2Operation = NULL;
}

/** \todo: current implementation is the inverse of a dotproduct. not 'logically' correct
 */
void DotproductOperation::executePixelSampled(float output[4],
                                              float x,
                                              float y,
                                              PixelSampler sampler)
{
  float input1[4];
  float input2[4];
  this->m_input1Operation->readSampled(input1, x, y, sampler);
  this->m_input2Operation->readSampled(input2, x, y, sampler);
  output[0] = -(input1[0] * input2[0] + input1[1] * input2[1] + input1[2] * input2[2]);
}
