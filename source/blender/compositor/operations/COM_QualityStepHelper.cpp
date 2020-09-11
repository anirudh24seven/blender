/** Copyright 2011, Blender Foundation.
 */

#include "COM_QualityStepHelper.h"

QualityStepHelper::QualityStepHelper()
{
  this->m_quality = COM_QUALITY_HIGH;
  this->m_step = 1;
  this->m_offsetadd = 4;
}

void QualityStepHelper::initExecution(QualityHelper helper)
{
  switch (helper) {
    case COM_QH_INCREASE:
      switch (this->m_quality) {
        case COM_QUALITY_HIGH:
        default:
          this->m_step = 1;
          this->m_offsetadd = 1;
          break;
        case COM_QUALITY_MEDIUM:
          this->m_step = 2;
          this->m_offsetadd = 2;
          break;
        case COM_QUALITY_LOW:
          this->m_step = 3;
          this->m_offsetadd = 3;
          break;
      }
      break;
    case COM_QH_MULTIPLY:
      switch (this->m_quality) {
        case COM_QUALITY_HIGH:
        default:
          this->m_step = 1;
          this->m_offsetadd = 4;
          break;
        case COM_QUALITY_MEDIUM:
          this->m_step = 2;
          this->m_offsetadd = 8;
          break;
        case COM_QUALITY_LOW:
          this->m_step = 4;
          this->m_offsetadd = 16;
          break;
      }
      break;
  }
}
