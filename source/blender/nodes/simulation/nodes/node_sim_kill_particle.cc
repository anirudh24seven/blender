#include "node_simulation_util.h"

static bNodeSocketTemplate sim_node_kill_particle_in[] = {
    {SOCK_CONTROL_FLOW, N_("Execute")},
    {-1, ""},
};

static bNodeSocketTemplate sim_node_kill_particle_out[] = {
    {SOCK_CONTROL_FLOW, N_("Execute")},
    {-1, ""},
};

void register_node_type_sim_kill_particle()
{
  static bNodeType ntype;

  sim_node_type_base(&ntype, SIM_NODE_KILL_PARTICLE, "Kill Particle", 0, 0);
  node_type_socket_templates(&ntype, sim_node_kill_particle_in, sim_node_kill_particle_out);
  nodeRegisterType(&ntype);
}
