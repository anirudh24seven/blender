/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ZCombineOperation : public NodeOperation {
 protected:
  SocketReader *m_image1Reader;
  SocketReader *m_depth1Reader;
  SocketReader *m_image2Reader;
  SocketReader *m_depth2Reader;

 public:
  /**
   * Default constructor
   */
  ZCombineOperation();

  void initExecution();
  void deinitExecution();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class ZCombineAlphaOperation : public ZCombineOperation {
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};

class ZCombineMaskOperation : public NodeOperation {
 protected:
  SocketReader *m_maskReader;
  SocketReader *m_image1Reader;
  SocketReader *m_image2Reader;

 public:
  ZCombineMaskOperation();

  void initExecution();
  void deinitExecution();
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
class ZCombineMaskAlphaOperation : public ZCombineMaskOperation {
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
