/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Pixelate ******************** */

static bNodeSocketTemplate cmp_node_pixelate_in[] = {
    {SOCK_RGBA, N_("Color"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE}, {-1, ""}};
static bNodeSocketTemplate cmp_node_pixelate_out[] = {{SOCK_RGBA, N_("Color")}, {-1, ""}};

void register_node_type_cmp_pixelate(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_PIXELATE, "Pixelate", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_pixelate_in, cmp_node_pixelate_out);

  nodeRegisterType(&ntype);
}
