/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"
#include "DNA_node_types.h"

class VectorBlurOperation : public NodeOperation, public QualityStepHelper {
 private:
  /**
   * \brief Cached reference to the inputProgram
   */
  SocketReader *m_inputImageProgram;
  SocketReader *m_inputSpeedProgram;
  SocketReader *m_inputZProgram;

  /**
   * \brief settings of the glare node.
   */
  NodeBlurData *m_settings;

  float *m_cachedInstance;

 public:
  VectorBlurOperation();

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

  void setVectorBlurSettings(NodeBlurData *settings)
  {
    this->m_settings = settings;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

 protected:
  void generateVectorBlur(float *data,
                          MemoryBuffer *inputImage,
                          MemoryBuffer *inputSpeed,
                          MemoryBuffer *inputZ);
};
