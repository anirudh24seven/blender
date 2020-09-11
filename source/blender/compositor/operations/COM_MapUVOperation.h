/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class MapUVOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputUVProgram;
  SocketReader *m_inputColorProgram;

  float m_alpha;

 public:
  MapUVOperation();

  /**
   * we need a 3x3 differential filter for UV Input and full buffer for the image
   */
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void pixelTransform(const float xy[2], float r_uv[2], float r_deriv[2][2], float &r_alpha);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setAlpha(float alpha)
  {
    this->m_alpha = alpha;
  }

 private:
  bool read_uv(float x, float y, float &r_u, float &r_v, float &r_alpha);
};
