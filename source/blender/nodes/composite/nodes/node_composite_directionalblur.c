/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_dblur_in[] = {{SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.f},
                                                  {-1, ""}};

static bNodeSocketTemplate cmp_node_dblur_out[] = {{SOCK_RGBA, N_("Image")}, {-1, ""}};

static void node_composit_init_dblur(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeDBlurData *ndbd = MEM_callocN(sizeof(NodeDBlurData), "node dblur data");
  node->storage = ndbd;
  ndbd->iter = 1;
  ndbd->center_x = 0.5;
  ndbd->center_y = 0.5;
}

void register_node_type_cmp_dblur(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_DBLUR, "Directional Blur", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_dblur_in, cmp_node_dblur_out);
  node_type_init(&ntype, node_composit_init_dblur);
  node_type_storage(
      &ntype, "NodeDBlurData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
