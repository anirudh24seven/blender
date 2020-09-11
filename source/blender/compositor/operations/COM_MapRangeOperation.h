/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_texture_types.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class MapRangeOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputOperation;
  SocketReader *m_sourceMinOperation;
  SocketReader *m_sourceMaxOperation;
  SocketReader *m_destMinOperation;
  SocketReader *m_destMaxOperation;

  bool m_useClamp;

 public:
  /**
   * Default constructor
   */
  MapRangeOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  /**
   * Clamp the output
   */
  void setUseClamp(bool value)
  {
    this->m_useClamp = value;
  }
};
