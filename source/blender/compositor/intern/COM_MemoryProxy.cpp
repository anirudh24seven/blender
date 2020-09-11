/** Copyright 2011, Blender Foundation.
 */

#include "COM_MemoryProxy.h"

MemoryProxy::MemoryProxy(DataType datatype)
{
  this->m_writeBufferOperation = NULL;
  this->m_executor = NULL;
  this->m_datatype = datatype;
}

void MemoryProxy::allocate(unsigned int width, unsigned int height)
{
  rcti result;
  result.xmin = 0;
  result.xmax = width;
  result.ymin = 0;
  result.ymax = height;

  this->m_buffer = new MemoryBuffer(this, 1, &result);
}

void MemoryProxy::free()
{
  if (this->m_buffer) {
    delete this->m_buffer;
    this->m_buffer = NULL;
  }
}
