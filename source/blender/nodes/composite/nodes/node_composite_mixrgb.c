/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** MIX RGB ******************** */
static bNodeSocketTemplate cmp_node_mix_rgb_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_mix_rgb_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

/* custom1 = mix type */
void register_node_type_cmp_mix_rgb(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MIX_RGB, "Mix", NODE_CLASS_OP_COLOR, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_mix_rgb_in, cmp_node_mix_rgb_out);
  node_type_label(&ntype, node_blend_label);

  nodeRegisterType(&ntype);
}
