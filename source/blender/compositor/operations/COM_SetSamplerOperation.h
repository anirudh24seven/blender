/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output Sampler.
 * it assumes we are in sRGB color space.
 */
class SetSamplerOperation : public NodeOperation {
 private:
  PixelSampler m_sampler;
  SocketReader *m_reader;

 public:
  /**
   * Default constructor
   */
  SetSamplerOperation();

  void setSampler(PixelSampler sampler)
  {
    this->m_sampler = sampler;
  }

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void initExecution();
  void deinitExecution();
};
