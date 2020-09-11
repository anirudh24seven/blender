/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_node_types.h"

/**
 * \brief AntiAlias operations
 * it only supports anti aliasing on BW buffers.
 * \ingroup operation
 */
class AntiAliasOperation : public NodeOperation {
 protected:
  /**
   * \brief Cached reference to the reader
   */
  SocketReader *m_valueReader;

 public:
  AntiAliasOperation();

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
};
