/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_node_types.h"

class ProjectorLensDistortionOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;

  float m_dispersion;
  bool m_dispersionAvailable;

  float m_kr, m_kr2;

 public:
  ProjectorLensDistortionOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  void *initializeTileData(rcti *rect);
  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void updateDispersion();
};
