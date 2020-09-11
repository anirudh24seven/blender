/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** INVERT ******************** */
static bNodeSocketTemplate cmp_node_invert_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Color"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""}};

static bNodeSocketTemplate cmp_node_invert_out[] = {{SOCK_RGBA, N_("Color")}, {-1, ""}};

static void node_composit_init_invert(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 |= CMP_CHAN_RGB;
}

/* custom1 = mix type */
void register_node_type_cmp_invert(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_INVERT, "Invert", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_invert_in, cmp_node_invert_out);
  node_type_init(&ntype, node_composit_init_invert);

  nodeRegisterType(&ntype);
}
