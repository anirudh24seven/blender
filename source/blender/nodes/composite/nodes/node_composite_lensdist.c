/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_lensdist_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Distort"), 0.f, 0.f, 0.f, 0.f, -0.999f, 1.f, PROP_NONE},
    {SOCK_FLOAT, N_("Dispersion"), 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_lensdist_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_lensdist(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeLensDist *nld = MEM_callocN(sizeof(NodeLensDist), "node lensdist data");
  nld->jit = nld->proj = nld->fit = 0;
  node->storage = nld;
}

void register_node_type_cmp_lensdist(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_LENSDIST, "Lens Distortion", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_lensdist_in, cmp_node_lensdist_out);
  node_type_init(&ntype, node_composit_init_lensdist);
  node_type_storage(
      &ntype, "NodeLensDist", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
