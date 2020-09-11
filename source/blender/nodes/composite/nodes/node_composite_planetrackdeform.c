/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_planetrackdeform_in[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE}, {-1, ""}};

static bNodeSocketTemplate cmp_node_planetrackdeform_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Plane")},
    {-1, ""},
};

static void init(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodePlaneTrackDeformData *data = MEM_callocN(sizeof(NodePlaneTrackDeformData),
                                               "node plane track deform data");
  data->motion_blur_samples = 16;
  data->motion_blur_shutter = 0.5f;
  node->storage = data;
}

void register_node_type_cmp_planetrackdeform(void)
{
  static bNodeType ntype;

  cmp_node_type_base(
      &ntype, CMP_NODE_PLANETRACKDEFORM, "Plane Track Deform", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_planetrackdeform_in, cmp_node_planetrackdeform_out);
  node_type_init(&ntype, init);
  node_type_storage(
      &ntype, "NodePlaneTrackDeformData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
