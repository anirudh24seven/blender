/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetVectorOperation.h"
#include "COM_defines.h"

SetVectorOperation::SetVectorOperation() : NodeOperation()
{
  this->addOutputSocket(COM_DT_VECTOR);
}

void SetVectorOperation::executePixelSampled(float output[4],
                                             float /*x*/,
                                             float /*y*/,
                                             PixelSampler /*sampler*/)
{
  output[0] = this->m_x;
  output[1] = this->m_y;
  output[2] = this->m_z;
}

void SetVectorOperation::determineResolution(unsigned int resolution[2],
                                             unsigned int preferredResolution[2])
{
  resolution[0] = preferredResolution[0];
  resolution[1] = preferredResolution[1];
}
