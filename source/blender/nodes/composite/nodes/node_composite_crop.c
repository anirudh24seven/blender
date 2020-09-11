/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Crop  ******************** */

static bNodeSocketTemplate cmp_node_crop_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_crop_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_crop(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTwoXYs *nxy = MEM_callocN(sizeof(NodeTwoXYs), "node xy data");
  node->storage = nxy;
  nxy->x1 = 0;
  nxy->x2 = 0;
  nxy->y1 = 0;
  nxy->y2 = 0;
}

void register_node_type_cmp_crop(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_CROP, "Crop", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_crop_in, cmp_node_crop_out);
  node_type_init(&ntype, node_composit_init_crop);
  node_type_storage(&ntype, "NodeTwoXYs", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
