/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Gamma Tools  ******************** */

static bNodeSocketTemplate cmp_node_gamma_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Gamma"), 1.0f, 0.0f, 0.0f, 0.0f, 0.001f, 10.0f, PROP_UNSIGNED},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_gamma_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_gamma(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_GAMMA, "Gamma", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_gamma_in, cmp_node_gamma_out);

  nodeRegisterType(&ntype);
}
