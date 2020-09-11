/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** NORMAL  ******************** */
static bNodeSocketTemplate cmp_node_normal_in[] = {
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 1.0f, PROP_DIRECTION},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_normal_out[] = {
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 1.0f, PROP_DIRECTION},
    {SOCK_FLOAT, N_("Dot")},
    {-1, ""},
};

void register_node_type_cmp_normal(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_NORMAL, "Normal", NODE_CLASS_OP_VECTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_normal_in, cmp_node_normal_out);

  nodeRegisterType(&ntype);
}
