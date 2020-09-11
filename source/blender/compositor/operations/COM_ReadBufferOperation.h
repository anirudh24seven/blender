/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MemoryBuffer.h"
#include "COM_MemoryProxy.h"
#include "COM_NodeOperation.h"

class ReadBufferOperation : public NodeOperation {
 private:
  MemoryProxy *m_memoryProxy;
  bool m_single_value; /* single value stored in buffer, copied from associated write operation */
  unsigned int m_offset;
  MemoryBuffer *m_buffer;

 public:
  ReadBufferOperation(DataType datatype);
  void setMemoryProxy(MemoryProxy *memoryProxy)
  {
    this->m_memoryProxy = memoryProxy;
  }
  MemoryProxy *getMemoryProxy()
  {
    return this->m_memoryProxy;
  }
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

  void *initializeTileData(rcti *rect);
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  void executePixelExtend(float output[4],
                          float x,
                          float y,
                          PixelSampler sampler,
                          MemoryBufferExtend extend_x,
                          MemoryBufferExtend extend_y);
  void executePixelFiltered(float output[4], float x, float y, float dx[2], float dy[2]);
  bool isReadBufferOperation() const
  {
    return true;
  }
  void setOffset(unsigned int offset)
  {
    this->m_offset = offset;
  }
  unsigned int getOffset() const
  {
    return this->m_offset;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
  MemoryBuffer *getInputMemoryBuffer(MemoryBuffer **memoryBuffers)
  {
    return memoryBuffers[this->m_offset];
  }
  void readResolutionFromWriteBuffer();
  void updateMemoryBuffer();
};
