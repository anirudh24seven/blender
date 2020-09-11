/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_node_types.h"

/**
 * \brief base class of normalize, implementing the simple normalize
 * \ingroup operation
 */
class NormalizeOperation : public NodeOperation {
 protected:
  /**
   * \brief Cached reference to the reader
   */
  SocketReader *m_imageReader;

  /**
   * \brief temporarily cache of the execution storage
   * it stores x->min and y->mult
   */
  NodeTwoFloats *m_cachedInstance;

 public:
  NormalizeOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  void *initializeTileData(rcti *rect);
  void deinitializeTileData(rcti *rect, void *data);

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};
