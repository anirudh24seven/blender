/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SEPARATE YCCA ******************** */
static bNodeSocketTemplate cmp_node_sepycca_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f}, {-1, ""}};
static bNodeSocketTemplate cmp_node_sepycca_out[] = {
    {SOCK_FLOAT, N_("Y")},
    {SOCK_FLOAT, N_("Cb")},
    {SOCK_FLOAT, N_("Cr")},
    {SOCK_FLOAT, N_("A")},
    {-1, ""},
};

static void node_composit_init_mode_sepycca(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 1; /* BLI_YCC_ITU_BT709 */
}

void register_node_type_cmp_sepycca(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SEPYCCA, "Separate YCbCrA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_sepycca_in, cmp_node_sepycca_out);
  node_type_init(&ntype, node_composit_init_mode_sepycca);

  nodeRegisterType(&ntype);
}

/* **************** COMBINE YCCA ******************** */
static bNodeSocketTemplate cmp_node_combycca_in[] = {
    {SOCK_FLOAT, N_("Y"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Cb"), 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Cr"), 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("A"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_combycca_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_mode_combycca(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 1; /* BLI_YCC_ITU_BT709 */
}

void register_node_type_cmp_combycca(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COMBYCCA, "Combine YCbCrA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_combycca_in, cmp_node_combycca_out);
  node_type_init(&ntype, node_composit_init_mode_combycca);

  nodeRegisterType(&ntype);
}
