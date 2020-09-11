/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetValueOperation.h"

SetValueOperation::SetValueOperation() : NodeOperation()
{
  this->addOutputSocket(COM_DT_VALUE);
}

void SetValueOperation::executePixelSampled(float output[4],
                                            float /*x*/,
                                            float /*y*/,
                                            PixelSampler /*sampler*/)
{
  output[0] = this->m_value;
}

void SetValueOperation::determineResolution(unsigned int resolution[2],
                                            unsigned int preferredResolution[2])
{
  resolution[0] = preferredResolution[0];
  resolution[1] = preferredResolution[1];
}
