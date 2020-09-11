#pragma once

#include "FN_multi_function_network.hh"

#include "BLI_resource_collector.hh"

namespace blender::fn::mf_network_optimization {

void dead_node_removal(MFNetwork &network);
void constant_folding(MFNetwork &network, ResourceCollector &resources);
void common_subnetwork_elimination(MFNetwork &network);

}  // namespace blender::fn::mf_network_optimization
