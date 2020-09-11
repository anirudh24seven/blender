/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Dilate/Erode ******************** */

static bNodeSocketTemplate cmp_node_dilateerode_in[] = {
    {SOCK_FLOAT, N_("Mask"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE}, {-1, ""}};
static bNodeSocketTemplate cmp_node_dilateerode_out[] = {{SOCK_FLOAT, N_("Mask")}, {-1, ""}};

static void node_composit_init_dilateerode(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeDilateErode *data = MEM_callocN(sizeof(NodeDilateErode), "NodeDilateErode");
  data->falloff = PROP_SMOOTH;
  node->storage = data;
}

void register_node_type_cmp_dilateerode(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_DILATEERODE, "Dilate/Erode", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_dilateerode_in, cmp_node_dilateerode_out);
  node_type_init(&ntype, node_composit_init_dilateerode);
  node_type_storage(
      &ntype, "NodeDilateErode", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
