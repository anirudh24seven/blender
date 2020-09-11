/** \file
 * \ingroup cmpnodes
 */

#include "../node_composite_util.h"

/* **************** SCALAR MATH ******************** */
static bNodeSocketTemplate cmp_node_boxmask_in[] = {
    {SOCK_FLOAT, N_("Mask"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Value"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""}};

static bNodeSocketTemplate cmp_node_boxmask_out[] = {
    {SOCK_FLOAT, N_("Mask"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f}, {-1, ""}};

static void node_composit_init_boxmask(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeBoxMask *data = MEM_callocN(sizeof(NodeBoxMask), "NodeBoxMask");
  data->x = 0.5;
  data->y = 0.5;
  data->width = 0.2;
  data->height = 0.1;
  data->rotation = 0.0;
  node->storage = data;
}

void register_node_type_cmp_boxmask(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MASK_BOX, "Box Mask", NODE_CLASS_MATTE, 0);
  node_type_socket_templates(&ntype, cmp_node_boxmask_in, cmp_node_boxmask_out);
  node_type_init(&ntype, node_composit_init_boxmask);
  node_type_storage(&ntype, "NodeBoxMask", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
