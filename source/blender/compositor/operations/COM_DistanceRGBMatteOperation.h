/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class DistanceRGBMatteOperation : public NodeOperation {
 protected:
  NodeChroma *m_settings;
  SocketReader *m_inputImageProgram;
  SocketReader *m_inputKeyProgram;

  virtual float calculateDistance(float key[4], float image[4]);

 public:
  /**
   * Default constructor
   */
  DistanceRGBMatteOperation();

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
