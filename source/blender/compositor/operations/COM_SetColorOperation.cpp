/** Copyright 2011, Blender Foundation.
 */

#include "COM_SetColorOperation.h"

SetColorOperation::SetColorOperation() : NodeOperation()
{
  this->addOutputSocket(COM_DT_COLOR);
}

void SetColorOperation::executePixelSampled(float output[4],
                                            float /*x*/,
                                            float /*y*/,
                                            PixelSampler /*sampler*/)
{
  copy_v4_v4(output, this->m_color);
}

void SetColorOperation::determineResolution(unsigned int resolution[2],
                                            unsigned int preferredResolution[2])
{
  resolution[0] = preferredResolution[0];
  resolution[1] = preferredResolution[1];
}
