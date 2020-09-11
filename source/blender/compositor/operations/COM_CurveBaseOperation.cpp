/** Copyright 2011, Blender Foundation.
 */

#include "COM_CurveBaseOperation.h"

#include "BKE_colortools.h"

CurveBaseOperation::CurveBaseOperation() : NodeOperation()
{
  this->m_curveMapping = NULL;
}

CurveBaseOperation::~CurveBaseOperation()
{
  if (this->m_curveMapping) {
    BKE_curvemapping_free(this->m_curveMapping);
    this->m_curveMapping = NULL;
  }
}

void CurveBaseOperation::initExecution()
{
  BKE_curvemapping_init(this->m_curveMapping);
}
void CurveBaseOperation::deinitExecution()
{
  if (this->m_curveMapping) {
    BKE_curvemapping_free(this->m_curveMapping);
    this->m_curveMapping = NULL;
  }
}

void CurveBaseOperation::setCurveMapping(CurveMapping *mapping)
{
  /* duplicate the curve to avoid glitches while drawing, see bug [#32374] */
  if (this->m_curveMapping) {
    BKE_curvemapping_free(this->m_curveMapping);
  }
  this->m_curveMapping = BKE_curvemapping_copy(mapping);
}
