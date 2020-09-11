/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class LuminanceMatteOperation : public NodeOperation {
 private:
  NodeChroma *m_settings;
  SocketReader *m_inputImageProgram;

 public:
  /**
   * Default constructor
   */
  LuminanceMatteOperation();

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
