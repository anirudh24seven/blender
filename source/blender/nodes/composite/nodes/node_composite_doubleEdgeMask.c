/** \file
 * \ingroup cmpnodes
 */
#include "node_composite_util.h"
/* **************** Double Edge Mask ******************** */

static bNodeSocketTemplate cmp_node_doubleedgemask_in[] = {
    /* Inner mask socket definition. */
    {SOCK_FLOAT, "Inner Mask", 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    /* Outer mask socket definition. */
    {SOCK_FLOAT, "Outer Mask", 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    /* Input socket array terminator. */
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_doubleedgemask_out[] = {
    /* Output socket definition. */
    {SOCK_FLOAT, "Mask"},
    /* Output socket array terminator. */
    {-1, ""},
};

void register_node_type_cmp_doubleedgemask(void)
{
  static bNodeType ntype;  // allocate a node type data structure

  cmp_node_type_base(&ntype, CMP_NODE_DOUBLEEDGEMASK, "Double Edge Mask", NODE_CLASS_MATTE, 0);
  node_type_socket_templates(&ntype, cmp_node_doubleedgemask_in, cmp_node_doubleedgemask_out);
  node_type_socket_templates(&ntype, cmp_node_doubleedgemask_in, cmp_node_doubleedgemask_out);

  nodeRegisterType(&ntype);
}
