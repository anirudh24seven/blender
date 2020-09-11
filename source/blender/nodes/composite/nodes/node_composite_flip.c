/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Flip  ******************** */
static bNodeSocketTemplate cmp_node_flip_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_flip_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_flip(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_FLIP, "Flip", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_flip_in, cmp_node_flip_out);

  nodeRegisterType(&ntype);
}
