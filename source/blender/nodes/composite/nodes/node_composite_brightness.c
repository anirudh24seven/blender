/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Brigh and contrsast  ******************** */

static bNodeSocketTemplate cmp_node_brightcontrast_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Bright"), 0.0f, 0.0f, 0.0f, 0.0f, -100.0f, 100.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Contrast"), 0.0f, 0.0f, 0.0f, 0.0f, -100.0f, 100.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_brightcontrast_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_brightcontrast(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 1;
}

void register_node_type_cmp_brightcontrast(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_BRIGHTCONTRAST, "Bright/Contrast", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_brightcontrast_in, cmp_node_brightcontrast_out);
  node_type_init(&ntype, node_composit_init_brightcontrast);

  nodeRegisterType(&ntype);
}
