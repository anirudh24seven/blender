/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_defines.h"

typedef enum QualityHelper {
  COM_QH_INCREASE,
  COM_QH_MULTIPLY,
} QualityHelper;

class QualityStepHelper {
 private:
  CompositorQuality m_quality;
  int m_step;
  int m_offsetadd;

 protected:
  /**
   * Initialize the execution
   */
  void initExecution(QualityHelper helper);

  inline int getStep() const
  {
    return this->m_step;
  }
  inline int getOffsetAdd() const
  {
    return this->m_offsetadd;
  }

 public:
  QualityStepHelper();

  void setQuality(CompositorQuality quality)
  {
    this->m_quality = quality;
  }
};
