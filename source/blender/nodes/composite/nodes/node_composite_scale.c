/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Scale  ******************** */

static bNodeSocketTemplate cmp_node_scale_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("X"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0001f, CMP_SCALE_MAX, PROP_NONE},
    {SOCK_FLOAT, N_("Y"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0001f, CMP_SCALE_MAX, PROP_NONE},
    {-1, ""}};
static bNodeSocketTemplate cmp_node_scale_out[] = {{SOCK_RGBA, N_("Image")}, {-1, ""}};

static void node_composite_update_scale(bNodeTree *UNUSED(ntree), bNode *node)
{
  bNodeSocket *sock;
  bool use_xy_scale = ELEM(node->custom1, CMP_SCALE_RELATIVE, CMP_SCALE_ABSOLUTE);

  /* Only show X/Y scale factor inputs for modes using them! */
  for (sock = node->inputs.first; sock; sock = sock->next) {
    if (STR_ELEM(sock->name, "X", "Y")) {
      if (use_xy_scale) {
        sock->flag &= ~SOCK_UNAVAIL;
      }
      else {
        sock->flag |= SOCK_UNAVAIL;
      }
    }
  }
}

void register_node_type_cmp_scale(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SCALE, "Scale", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_scale_in, cmp_node_scale_out);
  node_type_update(&ntype, node_composite_update_scale);

  nodeRegisterType(&ntype);
}
