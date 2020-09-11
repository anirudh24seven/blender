/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class DisplaceOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputColorProgram;
  SocketReader *m_inputVectorProgram;
  SocketReader *m_inputScaleXProgram;
  SocketReader *m_inputScaleYProgram;

  float m_width_x4;
  float m_height_x4;

 public:
  DisplaceOperation();

  /**
   * we need a 2x2 differential filter for Vector Input and full buffer for the image
   */
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void pixelTransform(const float xy[2], float r_uv[2], float r_deriv[2][2]);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

 private:
  bool read_displacement(
      float x, float y, float xscale, float yscale, const float origin[2], float &r_u, float &r_v);
};
