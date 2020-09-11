/** \file
 * \ingroup cmpnodes
 */

#include "../node_composite_util.h"

/* **************** Bokeh image Tools  ******************** */

static bNodeSocketTemplate cmp_node_bokehimage_out[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

static void node_composit_init_bokehimage(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeBokehImage *data = MEM_callocN(sizeof(NodeBokehImage), "NodeBokehImage");
  data->angle = 0.0f;
  data->flaps = 5;
  data->rounding = 0.0f;
  data->catadioptric = 0.0f;
  data->lensshift = 0.0f;
  node->storage = data;
}

void register_node_type_cmp_bokehimage(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_BOKEHIMAGE, "Bokeh Image", NODE_CLASS_INPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, NULL, cmp_node_bokehimage_out);
  node_type_init(&ntype, node_composit_init_bokehimage);
  node_type_storage(
      &ntype, "NodeBokehImage", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
