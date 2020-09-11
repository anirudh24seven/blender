/** \file
 * \ingroup cmpnodes
 */

#include "../node_composite_util.h"

/* **************** SCALAR MATH ******************** */
static bNodeSocketTemplate cmp_node_ellipsemask_in[] = {
    {SOCK_FLOAT, N_("Mask"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Value"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""}};

static bNodeSocketTemplate cmp_node_ellipsemask_out[] = {
    {SOCK_FLOAT, N_("Mask"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f}, {-1, ""}};

static void node_composit_init_ellipsemask(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeEllipseMask *data = MEM_callocN(sizeof(NodeEllipseMask), "NodeEllipseMask");
  data->x = 0.5;
  data->y = 0.5;
  data->width = 0.2;
  data->height = 0.1;
  data->rotation = 0.0;
  node->storage = data;
}

void register_node_type_cmp_ellipsemask(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MASK_ELLIPSE, "Ellipse Mask", NODE_CLASS_MATTE, 0);
  node_type_socket_templates(&ntype, cmp_node_ellipsemask_in, cmp_node_ellipsemask_out);
  node_type_size(&ntype, 260, 110, 320);
  node_type_init(&ntype, node_composit_init_ellipsemask);
  node_type_storage(
      &ntype, "NodeEllipseMask", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
