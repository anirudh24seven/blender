/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

class InpaintSimpleOperation : public NodeOperation {
 protected:
  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputImageProgram;

  int m_iterations;

  float *m_cached_buffer;
  bool m_cached_buffer_ready;

  int *m_pixelorder;
  int m_area_size;
  short *m_manhattan_distance;

 public:
  InpaintSimpleOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  void *initializeTileData(rcti *rect);
  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setIterations(int iterations)
  {
    this->m_iterations = iterations;
  }

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);

 private:
  void calc_manhattan_distance();
  void clamp_xy(int &x, int &y);
  float *get_pixel(int x, int y);
  int mdist(int x, int y);
  bool next_pixel(int &x, int &y, int &curr, int iters);
  void pix_step(int x, int y);
};
