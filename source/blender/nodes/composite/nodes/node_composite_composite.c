/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** COMPOSITE ******************** */
static bNodeSocketTemplate cmp_node_composite_in[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Alpha"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Z"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};

void register_node_type_cmp_composite(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COMPOSITE, "Composite", NODE_CLASS_OUTPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_composite_in, NULL);

  /* Do not allow muting for this node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
