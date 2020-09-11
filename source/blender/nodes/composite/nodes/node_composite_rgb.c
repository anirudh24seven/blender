/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** RGB ******************** */
static bNodeSocketTemplate cmp_node_rgb_out[] = {
    {SOCK_RGBA, N_("RGBA"), 0.5f, 0.5f, 0.5f, 1.0f},
    {-1, ""},
};

void register_node_type_cmp_rgb(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_RGB, "RGB", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, cmp_node_rgb_out);
  node_type_size_preset(&ntype, NODE_SIZE_SMALL);

  nodeRegisterType(&ntype);
}
