/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Rotate  ******************** */

static bNodeSocketTemplate cmp_node_rotate_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Degr"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f, PROP_ANGLE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_rotate_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_rotate(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 1; /* Bilinear Filter*/
}

void register_node_type_cmp_rotate(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_ROTATE, "Rotate", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_rotate_in, cmp_node_rotate_out);
  node_type_init(&ntype, node_composit_init_rotate);

  nodeRegisterType(&ntype);
}
