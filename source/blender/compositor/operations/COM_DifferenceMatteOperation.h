/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class DifferenceMatteOperation : public NodeOperation {
 private:
  NodeChroma *m_settings;
  SocketReader *m_inputImage1Program;
  SocketReader *m_inputImage2Program;

 public:
  /**
   * Default constructor
   */
  DifferenceMatteOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();

  void setSettings(NodeChroma *nodeChroma)
  {
    this->m_settings = nodeChroma;
  }
};
