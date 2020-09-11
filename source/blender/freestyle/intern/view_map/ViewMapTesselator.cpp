/** \file
 * \ingroup freestyle
 * \brief Class to build a Node Tree designed to be displayed from a Silhouette View Map structure.
 */

#include "ViewMapTesselator.h"

namespace Freestyle {

NodeGroup *ViewMapTesselator::Tesselate(ViewMap *iViewMap)
{
  if (iViewMap->ViewEdges().empty()) {
    return NULL;
  }

  const vector<ViewEdge *> &viewedges = iViewMap->ViewEdges();
  return Tesselate(viewedges.begin(), viewedges.end());
}

NodeGroup *ViewMapTesselator::Tesselate(WShape *UNUSED(iWShape))
{
  return NULL;
}

} /* namespace Freestyle */
