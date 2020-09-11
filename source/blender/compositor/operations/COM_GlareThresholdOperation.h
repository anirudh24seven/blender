/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_light_types.h"

class GlareThresholdOperation : public NodeOperation {
 private:
  /**
   * \brief Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;

  /**
   * \brief settings of the glare node.
   */
  NodeGlare *m_settings;

 public:
  GlareThresholdOperation();

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

  void setGlareSettings(NodeGlare *settings)
  {
    this->m_settings = settings;
  }

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
};
