/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_CalculateMeanOperation.h"
#include "COM_NodeOperation.h"
#include "DNA_node_types.h"
/**
 * \brief base class of CalculateStandardDeviation,
 * implementing the simple CalculateStandardDeviation.
 * \ingroup operation
 */
class CalculateStandardDeviationOperation : public CalculateMeanOperation {
 protected:
  float m_standardDeviation;

 public:
  CalculateStandardDeviationOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  void *initializeTileData(rcti *rect);
};
