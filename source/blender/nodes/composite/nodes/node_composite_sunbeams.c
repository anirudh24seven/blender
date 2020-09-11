/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate inputs[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate outputs[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void init(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeSunBeams *data = MEM_callocN(sizeof(NodeSunBeams), "sun beams node");

  data->source[0] = 0.5f;
  data->source[1] = 0.5f;

  node->storage = data;
}

void register_node_type_cmp_sunbeams(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SUNBEAMS, "Sun Beams", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, inputs, outputs);
  node_type_init(&ntype, init);
  node_type_storage(
      &ntype, "NodeSunBeams", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
