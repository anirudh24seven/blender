/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"

class BokehBlurOperation : public NodeOperation, public QualityStepHelper {
 private:
  SocketReader *m_inputProgram;
  SocketReader *m_inputBokehProgram;
  SocketReader *m_inputBoundingBoxReader;
  void updateSize();
  float m_size;
  bool m_sizeavailable;
  float m_bokehMidX;
  float m_bokehMidY;
  float m_bokehDimension;
  bool m_extend_bounds;

 public:
  BokehBlurOperation();

  void *initializeTileData(rcti *rect);
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

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void setSize(float size)
  {
    this->m_size = size;
    this->m_sizeavailable = true;
  }

  void executeOpenCL(OpenCLDevice *device,
                     MemoryBuffer *outputMemoryBuffer,
                     cl_mem clOutputBuffer,
                     MemoryBuffer **inputMemoryBuffers,
                     list<cl_mem> *clMemToCleanUp,
                     list<cl_kernel> *clKernelsToCleanUp);

  void setExtendBounds(bool extend_bounds)
  {
    this->m_extend_bounds = extend_bounds;
  }

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
};
