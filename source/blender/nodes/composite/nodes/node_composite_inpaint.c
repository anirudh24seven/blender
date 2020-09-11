/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Inpaint/ ******************** */

static bNodeSocketTemplate cmp_node_inpaint_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f}, {-1, ""}};
static bNodeSocketTemplate cmp_node_inpaint_out[] = {{SOCK_RGBA, N_("Image")}, {-1, ""}};

void register_node_type_cmp_inpaint(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_INPAINT, "Inpaint", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_inpaint_in, cmp_node_inpaint_out);

  nodeRegisterType(&ntype);
}
