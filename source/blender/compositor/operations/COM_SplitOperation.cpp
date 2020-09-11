/** Copyright 2011, Blender Foundation.
 */

#include "COM_SplitOperation.h"
#include "BKE_image.h"
#include "BLI_listbase.h"
#include "BLI_math_color.h"
#include "BLI_math_vector.h"
#include "BLI_utildefines.h"
#include "MEM_guardedalloc.h"

#include "IMB_imbuf.h"
#include "IMB_imbuf_types.h"

SplitOperation::SplitOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_COLOR);
  this->addInputSocket(COM_DT_COLOR);
  this->addOutputSocket(COM_DT_COLOR);
  this->m_image1Input = NULL;
  this->m_image2Input = NULL;
}

void SplitOperation::initExecution()
{
  // When initializing the tree during initial load the width and height can be zero.
  this->m_image1Input = getInputSocketReader(0);
  this->m_image2Input = getInputSocketReader(1);
}

void SplitOperation::deinitExecution()
{
  this->m_image1Input = NULL;
  this->m_image2Input = NULL;
}

void SplitOperation::executePixelSampled(float output[4],
                                         float x,
                                         float y,
                                         PixelSampler /*sampler*/)
{
  int perc = this->m_xSplit ? this->m_splitPercentage * this->getWidth() / 100.0f :
                              this->m_splitPercentage * this->getHeight() / 100.0f;
  bool image1 = this->m_xSplit ? x > perc : y > perc;
  if (image1) {
    this->m_image1Input->readSampled(output, x, y, COM_PS_NEAREST);
  }
  else {
    this->m_image2Input->readSampled(output, x, y, COM_PS_NEAREST);
  }
}

void SplitOperation::determineResolution(unsigned int resolution[2],
                                         unsigned int preferredResolution[2])
{
  unsigned int tempPreferredResolution[2] = {0, 0};
  unsigned int tempResolution[2];

  this->getInputSocket(0)->determineResolution(tempResolution, tempPreferredResolution);
  this->setResolutionInputSocketIndex((tempResolution[0] && tempResolution[1]) ? 0 : 1);

  NodeOperation::determineResolution(resolution, preferredResolution);
}
