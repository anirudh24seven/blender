/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** VALTORGB ******************** */
static bNodeSocketTemplate cmp_node_valtorgb_in[] = {
    {SOCK_FLOAT, N_("Fac"), 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_valtorgb_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Alpha")},
    {-1, ""},
};

static void node_composit_init_valtorgb(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->storage = BKE_colorband_add(true);
}

void register_node_type_cmp_valtorgb(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_VALTORGB, "ColorRamp", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_valtorgb_in, cmp_node_valtorgb_out);
  node_type_size(&ntype, 240, 200, 320);
  node_type_init(&ntype, node_composit_init_valtorgb);
  node_type_storage(&ntype, "ColorBand", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}

/* **************** RGBTOBW ******************** */
static bNodeSocketTemplate cmp_node_rgbtobw_in[] = {
    {SOCK_RGBA, N_("Image"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_rgbtobw_out[] = {
    {SOCK_FLOAT, N_("Val"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

void register_node_type_cmp_rgbtobw(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_RGBTOBW, "RGB to BW", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_rgbtobw_in, cmp_node_rgbtobw_out);
  node_type_size_preset(&ntype, NODE_SIZE_SMALL);

  nodeRegisterType(&ntype);
}
