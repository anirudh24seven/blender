/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class SingleThreadedOperation : public NodeOperation {
 private:
  MemoryBuffer *m_cachedInstance;

 protected:
  inline bool isCached()
  {
    return this->m_cachedInstance != NULL;
  }

 public:
  SingleThreadedOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void *initializeTileData(rcti *rect);

  virtual MemoryBuffer *createMemoryBuffer(rcti *rect) = 0;

  int isSingleThreaded()
  {
    return true;
  }
};
