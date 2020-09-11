/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_node_types.h"

/**
 * \brief temporarily storage during execution of Tonemap
 * \ingroup operation
 */
typedef struct AvgLogLum {
  float al;
  float auto_key;
  float lav;
  float cav[4];
  float igm;
} AvgLogLum;

/**
 * \brief base class of tonemap, implementing the simple tonemap
 * \ingroup operation
 */
class TonemapOperation : public NodeOperation {
 protected:
  /**
   * \brief Cached reference to the reader
   */
  SocketReader *m_imageReader;

  /**
   * \brief settings of the Tonemap
   */
  NodeTonemap *m_data;

  /**
   * \brief temporarily cache of the execution storage
   */
  AvgLogLum *m_cachedInstance;

 public:
  TonemapOperation();

  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);

  /**
   * Initialize the execution
   */
  void initExecution();

  void *initializeTileData(rcti *rect);
  void deinitializeTileData(rcti *rect, void *data);

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setData(NodeTonemap *data)
  {
    this->m_data = data;
  }

  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output);
};

/**
 * \brief class of tonemap, implementing the photoreceptor tonemap
 * most parts have already been done in TonemapOperation
 * \ingroup operation
 */

class PhotoreceptorTonemapOperation : public TonemapOperation {
 public:
  /**
   * the inner loop of this program
   */
  void executePixel(float output[4], int x, int y, void *data);
};
