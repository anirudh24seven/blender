/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* ******************* Color Key ********************************************************** */
static bNodeSocketTemplate cmp_node_color_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_RGBA, N_("Key Color"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_color_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Matte")},
    {-1, ""},
};

static void node_composit_init_color_matte(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeChroma *c = MEM_callocN(sizeof(NodeChroma), "node color");
  node->storage = c;
  c->t1 = 0.01f;
  c->t2 = 0.1f;
  c->t3 = 0.1f;
  c->fsize = 0.0f;
  c->fstrength = 1.0f;
}

void register_node_type_cmp_color_matte(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COLOR_MATTE, "Color Key", NODE_CLASS_MATTE, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_color_in, cmp_node_color_out);
  node_type_init(&ntype, node_composit_init_color_matte);
  node_type_storage(&ntype, "NodeChroma", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
