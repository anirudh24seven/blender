/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_BlurBaseOperation.h"
#include "DNA_node_types.h"

class FastGaussianBlurOperation : public BlurBaseOperation {
 private:
  float m_sx;
  float m_sy;
  MemoryBuffer *m_iirgaus;

 public:
  FastGaussianBlurOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixel(float output[4], int x, int y, void *data);

  static void IIR_gauss(MemoryBuffer *src, float sigma, unsigned int channel, unsigned int xy);
  void *initializeTileData(rcti *rect);
  void deinitExecution();
  void initExecution();
};

enum {
  FAST_GAUSS_OVERLAY_MIN = -1,
  FAST_GAUSS_OVERLAY_NONE = 0,
  FAST_GAUSS_OVERLAY_MAX = 1,
};

class FastGaussianBlurValueOperation : public NodeOperation {
 private:
  float m_sigma;
  MemoryBuffer *m_iirgaus;
  SocketReader *m_inputprogram;

  /**
   * -1: re-mix with darker
   *  0: do nothing
   *  1 re-mix with lighter */
  int m_overlay;

 public:
  FastGaussianBlurValueOperation();
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  void executePixel(float output[4], int x, int y, void *data);

  void *initializeTileData(rcti *rect);
  void deinitExecution();
  void initExecution();
  void setSigma(float sigma)
  {
    this->m_sigma = sigma;
  }

  /* used for DOF blurring ZBuffer */
  void setOverlay(int overlay)
  {
    this->m_overlay = overlay;
  }
};
