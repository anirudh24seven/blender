/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_BlurBaseOperation.h"
#include "COM_NodeOperation.h"

class GaussianYBlurOperation : public BlurBaseOperation {
 private:
  float *m_gausstab;
#ifdef __SSE2__
  __m128 *m_gausstab_sse;
#endif
  int m_filtersize;
  void updateGauss();

 public:
  GaussianYBlurOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  void executeOpenCL(OpenCLDevice *device,
                     MemoryBuffer *outputMemoryBuffer,
                     cl_mem clOutputBuffer,
                     MemoryBuffer **inputMemoryBuffers,
                     list<cl_mem> *clMemToCleanUp,
                     list<cl_kernel> *clKernelsToCleanUp);

  /**
   * \brief initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void *initializeTileData(rcti *rect);
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

  void checkOpenCL()
  {
    this->setOpenCL(m_data.sizex >= 128);
  }
};
