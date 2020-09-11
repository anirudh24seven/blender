/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** FILTER  ******************** */
static bNodeSocketTemplate cmp_node_filter_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_filter_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_filter(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_FILTER, "Filter", NODE_CLASS_OP_FILTER, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_filter_in, cmp_node_filter_out);
  node_type_label(&ntype, node_filter_label);

  nodeRegisterType(&ntype);
}
