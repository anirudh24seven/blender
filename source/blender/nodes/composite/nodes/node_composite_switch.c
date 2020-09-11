/** \file
 * \ingroup cmpnodes
 */

#include "../node_composite_util.h"

/* **************** MIX RGB ******************** */
static bNodeSocketTemplate cmp_node_switch_in[] = {
    {SOCK_RGBA, N_("Off"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {SOCK_RGBA, N_("On"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_switch_out[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

/* custom1 = mix type */
void register_node_type_cmp_switch(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SWITCH, "Switch", NODE_CLASS_LAYOUT, 0);
  node_type_socket_templates(&ntype, cmp_node_switch_in, cmp_node_switch_out);
  node_type_size_preset(&ntype, NODE_SIZE_SMALL);
  nodeRegisterType(&ntype);
}
