/** \file
 * \ingroup bke
 */

#include "BKE_subdiv_topology.h"

#include "BKE_subdiv.h"

#include "opensubdiv_topology_refiner_capi.h"

int BKE_subdiv_topology_num_fvar_layers_get(const struct Subdiv *subdiv)
{
  OpenSubdiv_TopologyRefiner *topology_refiner = subdiv->topology_refiner;
  return topology_refiner->getNumFVarChannels(topology_refiner);
}
