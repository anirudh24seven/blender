/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"

class DirectionalBlurOperation : public NodeOperation, public QualityStepHelper {
 private:
  SocketReader *m_inputProgram;
  NodeDBlurData *m_data;

  float m_center_x_pix, m_center_y_pix;
  float m_tx, m_ty;
  float m_sc, m_rot;

 public:
  DirectionalBlurOperation();

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

  void setData(NodeDBlurData *data)
  {
    this->m_data = data;
  }

  void executeOpenCL(OpenCLDevice *device,
                     MemoryBuffer *outputMemoryBuffer,
                     cl_mem clOutputBuffer,
                     MemoryBuffer **inputMemoryBuffers,
                     list<cl_mem> *clMemToCleanUp,
                     list<cl_kernel> *clKernelsToCleanUp);
};
