/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "COM_QualityStepHelper.h"

#define MAX_GAUSSTAB_RADIUS 30000

#ifdef __SSE2__
#  include <emmintrin.h>
#endif

class BlurBaseOperation : public NodeOperation, public QualityStepHelper {
 private:
 protected:
  BlurBaseOperation(DataType data_type);
  float *make_gausstab(float rad, int size);
#ifdef __SSE2__
  __m128 *convert_gausstab_sse(const float *gausstab, int size);
#endif
  float *make_dist_fac_inverse(float rad, int size, int falloff);

  void updateSize();

  /**
   * Cached reference to the inputProgram
   */
  SocketReader *m_inputProgram;
  SocketReader *m_inputSize;
  NodeBlurData m_data;

  float m_size;
  bool m_sizeavailable;

  bool m_extend_bounds;

 public:
  /**
   * Initialize the execution
   */
  void initExecution();

  /**
   * Deinitialize the execution
   */
  void deinitExecution();

  void setData(const NodeBlurData *data);

  void setSize(float size)
  {
    this->m_size = size;
    this->m_sizeavailable = true;
  }

  void setExtendBounds(bool extend_bounds)
  {
    this->m_extend_bounds = extend_bounds;
  }

  void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);
};
