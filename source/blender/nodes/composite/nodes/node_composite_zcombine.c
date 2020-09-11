/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Z COMBINE ******************** */
/* lazy coder note: node->custom2 is abused to send signal */
static bNodeSocketTemplate cmp_node_zcombine_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Z"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 10000.0f, PROP_NONE},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Z"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 10000.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_zcombine_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Z")},
    {-1, ""},
};

void register_node_type_cmp_zcombine(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_ZCOMBINE, "Z Combine", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_zcombine_in, cmp_node_zcombine_out);

  nodeRegisterType(&ntype);
}
