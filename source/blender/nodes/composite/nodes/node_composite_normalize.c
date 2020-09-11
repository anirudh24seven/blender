/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** NORMALIZE single channel, useful for Z buffer ******************** */
static bNodeSocketTemplate cmp_node_normalize_in[] = {
    {SOCK_FLOAT, N_("Value"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_NONE}, {-1, ""}};
static bNodeSocketTemplate cmp_node_normalize_out[] = {{SOCK_FLOAT, N_("Value")}, {-1, ""}};

void register_node_type_cmp_normalize(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_NORMALIZE, "Normalize", NODE_CLASS_OP_VECTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_normalize_in, cmp_node_normalize_out);

  nodeRegisterType(&ntype);
}
