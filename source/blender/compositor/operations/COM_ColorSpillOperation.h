/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ColorSpillOperation : public NodeOperation {
 protected:
  NodeColorspill *m_settings;
  SocketReader *m_inputImageReader;
  SocketReader *m_inputFacReader;
  int m_spillChannel;
  int m_spillMethod;
  int m_channel2;
  int m_channel3;
  float m_rmut, m_gmut, m_bmut;

 public:
  /**
   * Default constructor
   */
  ColorSpillOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();

  void setSettings(NodeColorspill *nodeColorSpill)
  {
    this->m_settings = nodeColorSpill;
  }
  void setSpillChannel(int channel)
  {
    this->m_spillChannel = channel;
  }
  void setSpillMethod(int method)
  {
    this->m_spillMethod = method;
  }

  float calculateMapValue(float fac, float *input);
};
