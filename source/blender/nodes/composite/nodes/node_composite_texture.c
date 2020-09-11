/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** TEXTURE ******************** */
static bNodeSocketTemplate cmp_node_texture_in[] = {
    {SOCK_VECTOR, N_("Offset"), 0.0f, 0.0f, 0.0f, 0.0f, -2.0f, 2.0f, PROP_TRANSLATION},
    {SOCK_VECTOR, N_("Scale"), 1.0f, 1.0f, 1.0f, 1.0f, -10.0f, 10.0f, PROP_XYZ},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_texture_out[] = {
    {SOCK_FLOAT, N_("Value")},
    {SOCK_RGBA, N_("Color")},
    {-1, ""},
};

void register_node_type_cmp_texture(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_TEXTURE, "Texture", NODE_CLASS_INPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_texture_in, cmp_node_texture_out);

  nodeRegisterType(&ntype);
}
