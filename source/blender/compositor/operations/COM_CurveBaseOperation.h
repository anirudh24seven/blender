/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"
#include "DNA_color_types.h"

class CurveBaseOperation : public NodeOperation {
 protected:
  /**
   * Cached reference to the inputProgram
   */
  CurveMapping *m_curveMapping;

 public:
  CurveBaseOperation();
  ~CurveBaseOperation();

  /**
   * Initialize the execution
   */
  void initExecution();
  void deinitExecution();

  void setCurveMapping(CurveMapping *mapping);
};
