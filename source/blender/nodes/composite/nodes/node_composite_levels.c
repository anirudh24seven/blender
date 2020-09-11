/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** LEVELS ******************** */
static bNodeSocketTemplate cmp_node_view_levels_in[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_view_levels_out[] = {
    {SOCK_FLOAT, N_("Mean")},
    {SOCK_FLOAT, N_("Std Dev")},
    {-1, ""},
};

static void node_composit_init_view_levels(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 1; /*All channels*/
}

void register_node_type_cmp_view_levels(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_VIEW_LEVELS, "Levels", NODE_CLASS_OUTPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_view_levels_in, cmp_node_view_levels_out);
  node_type_init(&ntype, node_composit_init_view_levels);

  nodeRegisterType(&ntype);
}
