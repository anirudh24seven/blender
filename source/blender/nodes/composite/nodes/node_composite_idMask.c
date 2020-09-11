/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** ID Mask  ******************** */

static bNodeSocketTemplate cmp_node_idmask_in[] = {
    {SOCK_FLOAT, N_("ID value"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_idmask_out[] = {
    {SOCK_FLOAT, N_("Alpha")},
    {-1, ""},
};

void register_node_type_cmp_idmask(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_ID_MASK, "ID Mask", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_idmask_in, cmp_node_idmask_out);

  nodeRegisterType(&ntype);
}
