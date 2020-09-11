/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

/**
 * \brief Pixelate operation
 *
 * The Tile compositor is by default sub-pixel accurate.
 * For some setups you don want this.
 * This operation will remove the sub-pixel accuracy
 */
class PixelateOperation : public NodeOperation {
 private:
  /**
   * \brief cached reference to the input operation
   */
  SocketReader *m_inputOperation;

 public:
  /**
   * \brief PixelateOperation
   * \param dataType: the datatype to create this operator for (saves datatype conversions)
   */
  PixelateOperation(DataType dataType);

  /**
   * \brief initialization of the execution
   */
  void initExecution();

  /**
   * \brief de-initialization of the execution
   */
  void deinitExecution();

  /**
   * \brief executePixel
   * \param output: result
   * \param x: x-coordinate
   * \param y: y-coordinate
   * \param sampler: sampler
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
};
