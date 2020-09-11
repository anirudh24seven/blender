/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"

class BilateralBlurOperation : public NodeOperation, public QualityStepHelper {
 private:
  SocketReader *m_inputColorProgram;
  SocketReader *m_inputDeterminatorProgram;
  NodeBilateralBlurData *m_data;
  float m_space;

 public:
  BilateralBlurOperation();

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

  void setData(NodeBilateralBlurData *data)
  {
    this->m_data = data;
  }
};
