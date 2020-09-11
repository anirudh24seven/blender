/** Copyright 2011, Blender Foundation.
 */

#include "COM_MapValueOperation.h"

MapValueOperation::MapValueOperation() : NodeOperation()
{
  this->addInputSocket(COM_DT_VALUE);
  this->addOutputSocket(COM_DT_VALUE);
  this->m_inputOperation = NULL;
}

void MapValueOperation::initExecution()
{
  this->m_inputOperation = this->getInputSocketReader(0);
}

void MapValueOperation::executePixelSampled(float output[4],
                                            float x,
                                            float y,
                                            PixelSampler sampler)
{
  float src[4];
  this->m_inputOperation->readSampled(src, x, y, sampler);
  TexMapping *texmap = this->m_settings;
  float value = (src[0] + texmap->loc[0]) * texmap->size[0];
  if (texmap->flag & TEXMAP_CLIP_MIN) {
    if (value < texmap->min[0]) {
      value = texmap->min[0];
    }
  }
  if (texmap->flag & TEXMAP_CLIP_MAX) {
    if (value > texmap->max[0]) {
      value = texmap->max[0];
    }
  }

  output[0] = value;
}

void MapValueOperation::deinitExecution()
{
  this->m_inputOperation = NULL;
}
