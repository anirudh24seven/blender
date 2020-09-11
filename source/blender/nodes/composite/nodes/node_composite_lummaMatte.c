/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* ******************* Luma Matte Node ********************************* */
static bNodeSocketTemplate cmp_node_luma_matte_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_luma_matte_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Matte")},
    {-1, ""},
};

static void node_composit_init_luma_matte(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeChroma *c = MEM_callocN(sizeof(NodeChroma), "node chroma");
  node->storage = c;
  c->t1 = 1.0f;
  c->t2 = 0.0f;
}

void register_node_type_cmp_luma_matte(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_LUMA_MATTE, "Luminance Key", NODE_CLASS_MATTE, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_luma_matte_in, cmp_node_luma_matte_out);
  node_type_init(&ntype, node_composit_init_luma_matte);
  node_type_storage(&ntype, "NodeChroma", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
