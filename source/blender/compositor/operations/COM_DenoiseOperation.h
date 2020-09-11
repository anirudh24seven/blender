#pragma once

#include "COM_SingleThreadedOperation.h"
#include "DNA_node_types.h"

class DenoiseOperation : public SingleThreadedOperation {
 private:
  /**
   * \brief Cached reference to the input programs
   */
  SocketReader *m_inputProgramColor;
  SocketReader *m_inputProgramAlbedo;
  SocketReader *m_inputProgramNormal;

  /**
   * \brief settings of the denoise node.
   */
  NodeDenoise *m_settings;

 public:
  DenoiseOperation();
  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setDenoiseSettings(NodeDenoise *settings)
  {
    this->m_settings = settings;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

 protected:
  void generateDenoise(float *data,
                       MemoryBuffer *inputTileColor,
                       MemoryBuffer *inputTileNormal,
                       MemoryBuffer *inputTileAlbedo,
                       NodeDenoise *settings);

  MemoryBuffer *createMemoryBuffer(rcti *rect);
};
