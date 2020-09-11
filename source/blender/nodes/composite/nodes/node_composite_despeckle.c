/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** FILTER  ******************** */
static bNodeSocketTemplate cmp_node_despeckle_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_despeckle_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_despeckle(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom3 = 0.5f;
  node->custom4 = 0.5f;
}

void register_node_type_cmp_despeckle(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_DESPECKLE, "Despeckle", NODE_CLASS_OP_FILTER, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_despeckle_in, cmp_node_despeckle_out);
  node_type_init(&ntype, node_composit_init_despeckle);

  nodeRegisterType(&ntype);
}
