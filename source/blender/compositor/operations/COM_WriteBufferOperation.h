/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_MemoryProxy.h"
#include "COM_NodeOperation.h"
#include "COM_SocketReader.h"
/**
 * \brief NodeOperation to write to a tile
 * \ingroup Operation
 */
class WriteBufferOperation : public NodeOperation {
  MemoryProxy *m_memoryProxy;
  bool m_single_value; /* single value stored in buffer */
  NodeOperation *m_input;

 public:
  WriteBufferOperation(DataType datatype);
  ~WriteBufferOperation();
  MemoryProxy *getMemoryProxy()
  {
    return this->m_memoryProxy;
  }
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);
  bool isWriteBufferOperation() const
  {
    return true;
  }
  bool isSingleValue() const
  {
    return m_single_value;
  }

  void executeRegion(rcti *rect, unsigned int tileNumber);
  void initExecution();
  void deinitExecution();
  void executeOpenCLRegion(OpenCLDevice *device,
                           rcti *rect,
                           unsigned int chunkNumber,
                           MemoryBuffer **memoryBuffers,
                           MemoryBuffer *outputBuffer);
  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
  void readResolutionFromInputSocket();
  inline NodeOperation *getInput()
  {
    return m_input;
  }
};
