/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** VALUE ******************** */
static bNodeSocketTemplate cmp_node_value_out[] = {
    {SOCK_FLOAT, N_("Value"), 0.5f, 0, 0, 0, -FLT_MAX, FLT_MAX, PROP_NONE},
    {-1, ""},
};

void register_node_type_cmp_value(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_VALUE, "Value", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, cmp_node_value_out);
  node_type_size_preset(&ntype, NODE_SIZE_SMALL);

  nodeRegisterType(&ntype);
}
