/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** ALPHAOVER ******************** */
static bNodeSocketTemplate cmp_node_alphaover_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_alphaover_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_alphaover_init(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->storage = MEM_callocN(sizeof(NodeTwoFloats), "NodeTwoFloats");
}

void register_node_type_cmp_alphaover(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_ALPHAOVER, "Alpha Over", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_alphaover_in, cmp_node_alphaover_out);
  node_type_init(&ntype, node_alphaover_init);
  node_type_storage(
      &ntype, "NodeTwoFloats", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
