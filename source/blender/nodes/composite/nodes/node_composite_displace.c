/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Displace  ******************** */

static bNodeSocketTemplate cmp_node_displace_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_VECTOR, N_("Vector"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_TRANSLATION},
    {SOCK_FLOAT, N_("X Scale"), 0.0f, 0.0f, 0.0f, 0.0f, -1000.0f, 1000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Y Scale"), 0.0f, 0.0f, 0.0f, 0.0f, -1000.0f, 1000.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_displace_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_displace(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_DISPLACE, "Displace", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_displace_in, cmp_node_displace_out);

  nodeRegisterType(&ntype);
}
