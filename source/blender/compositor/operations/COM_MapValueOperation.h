/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_texture_types.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class MapValueOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputOperation;
  TexMapping *m_settings;

 public:
  /**
   * Default constructor
   */
  MapValueOperation();

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
   * \brief set the TexMapping settings
   */
  void setSettings(TexMapping *settings)
  {
    this->m_settings = settings;
  }
};
