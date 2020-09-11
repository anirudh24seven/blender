/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_SingleThreadedOperation.h"
#include "DNA_node_types.h"

/* utility functions used by glare, tonemap and lens distortion */
/* soms macros for color handling */
typedef float fRGB[4];

/* TODO - replace with BLI_math_vector */
/* multiply c2 by color rgb, rgb as separate arguments */
#define fRGB_rgbmult(c, r, g, b) \
  { \
    c[0] *= (r); \
    c[1] *= (g); \
    c[2] *= (b); \
  } \
  (void)0

class GlareBaseOperation : public SingleThreadedOperation {
 private:
  /**
   * \brief Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;

  /**
   * \brief settings of the glare node.
   */
  NodeGlare *m_settings;

 public:
  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setGlareSettings(NodeGlare *settings)
  {
    this->m_settings = settings;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

 protected:
  GlareBaseOperation();

  virtual void generateGlare(float *data, MemoryBuffer *inputTile, NodeGlare *settings) = 0;

  MemoryBuffer *createMemoryBuffer(rcti *rect);
};
