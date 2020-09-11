/** Copyright 2011, Blender Foundation.
 */

#include "COM_SingleThreadedOperation.h"

SingleThreadedOperation::SingleThreadedOperation() : NodeOperation()
{
  this->m_cachedInstance = NULL;
  setComplex(true);
}

void SingleThreadedOperation::initExecution()
{
  initMutex();
}

void SingleThreadedOperation::executePixel(float output[4], int x, int y, void * /*data*/)
{
  this->m_cachedInstance->readNoCheck(output, x, y);
}

void SingleThreadedOperation::deinitExecution()
{
  deinitMutex();
  if (this->m_cachedInstance) {
    delete this->m_cachedInstance;
    this->m_cachedInstance = NULL;
  }
}
void *SingleThreadedOperation::initializeTileData(rcti *rect)
{
  if (this->m_cachedInstance) {
    return this->m_cachedInstance;
  }

  lockMutex();
  if (this->m_cachedInstance == NULL) {
    //
    this->m_cachedInstance = createMemoryBuffer(rect);
  }
  unlockMutex();
  return this->m_cachedInstance;
}
