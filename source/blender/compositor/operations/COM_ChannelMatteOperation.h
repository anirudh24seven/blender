/** Copyright 2012, Blender Foundation.
 */

#pragma once

#include "COM_MixOperation.h"

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ChannelMatteOperation : public NodeOperation {
 private:
  SocketReader *m_inputImageProgram;

  /* int m_color_space; */ /* node->custom1 */ /* UNUSED */ /* TODO ? */
  int m_matte_channel;                                      /* node->custom2 */
  int m_limit_method;                                       /* node->algorithm */
  int m_limit_channel;                                      /* node->channel */
  float m_limit_max;                                        /* node->storage->t1 */
  float m_limit_min;                                        /* node->storage->t2 */

  float m_limit_range;

  /** ids to use for the operations (max and simple)
   * alpha = in[ids[0]] - max(in[ids[1]], in[ids[2]])
   * the simple operation is using:
   * alpha = in[ids[0]] - in[ids[1]]
   * but to use the same formula and operation for both we do:
   * ids[2] = ids[1]
   * alpha = in[ids[0]] - max(in[ids[1]], in[ids[2]])
   */
  int m_ids[3];

 public:
  /**
   * Default constructor
   */
  ChannelMatteOperation();

  /**
   * the inner loop of this program
   */
  void executePixelSampled(float output[4], float x, float y, PixelSampler sampler);

  void initExecution();
  void deinitExecution();

  void setSettings(NodeChroma *nodeChroma, const int custom2)
  {
    this->m_limit_max = nodeChroma->t1;
    this->m_limit_min = nodeChroma->t2;
    this->m_limit_method = nodeChroma->algorithm;
    this->m_limit_channel = nodeChroma->channel;
    this->m_matte_channel = custom2;
  }
};
