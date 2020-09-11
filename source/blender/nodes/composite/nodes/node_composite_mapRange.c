/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** MAP VALUE ******************** */
static bNodeSocketTemplate cmp_node_map_range_in[] = {
    {SOCK_FLOAT, N_("Value"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("From Min"), 0.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("From Max"), 1.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("To Min"), 0.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("To Max"), 1.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_map_range_out[] = {
    {SOCK_FLOAT, N_("Value")},
    {-1, ""},
};

void register_node_type_cmp_map_range(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MAP_RANGE, "Map Range", NODE_CLASS_OP_VECTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_map_range_in, cmp_node_map_range_out);

  nodeRegisterType(&ntype);
}
