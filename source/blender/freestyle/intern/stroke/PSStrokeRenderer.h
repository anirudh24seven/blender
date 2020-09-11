#pragma once

/** \file
 * \ingroup freestyle
 * \brief Class to define the Postscript rendering of a stroke
 */

#include <fstream>

#include "StrokeRenderer.h"

#include "../system/FreestyleConfig.h"

namespace Freestyle {

/**********************************/
/*                                */
/*                                */
/*         PSStrokeRenderer       */
/*                                */
/*                                */
/**********************************/

class PSStrokeRenderer : public StrokeRenderer {
 public:
  PSStrokeRenderer(const char *iFileName = NULL);
  virtual ~PSStrokeRenderer();

  /*! Renders a stroke rep */
  virtual void RenderStrokeRep(StrokeRep *iStrokeRep) const;
  virtual void RenderStrokeRepBasic(StrokeRep *iStrokeRep) const;

  /*! Closes the output PS file */
  void Close();

 protected:
  mutable ofstream _ofstream;
};

} /* namespace Freestyle */
