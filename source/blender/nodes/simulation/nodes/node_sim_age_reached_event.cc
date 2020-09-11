#include "node_simulation_util.h"

static bNodeSocketTemplate sim_node_age_reached_event_in[] = {
    {SOCK_FLOAT, N_("Age"), 3, 0, 0, 0, 0, 10000000},
    {SOCK_CONTROL_FLOW, N_("Execute")},
    {-1, ""},
};

static bNodeSocketTemplate sim_node_age_reached_event_out[] = {
    {SOCK_EVENTS, N_("Event")},
    {-1, ""},
};

void register_node_type_sim_age_reached_event()
{
  static bNodeType ntype;

  sim_node_type_base(&ntype, SIM_NODE_AGE_REACHED_EVENT, "Age Reached Event", 0, 0);
  node_type_socket_templates(
      &ntype, sim_node_age_reached_event_in, sim_node_age_reached_event_out);
  nodeRegisterType(&ntype);
}
