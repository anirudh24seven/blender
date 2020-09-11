/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** VECTOR BLUR ******************** */
static bNodeSocketTemplate cmp_node_vecblur_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Z"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_VECTOR, N_("Speed"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_VELOCITY},
    {-1, ""}};
static bNodeSocketTemplate cmp_node_vecblur_out[] = {{SOCK_RGBA, N_("Image")}, {-1, ""}};

static void node_composit_init_vecblur(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeBlurData *nbd = MEM_callocN(sizeof(NodeBlurData), "node blur data");
  node->storage = nbd;
  nbd->samples = 32;
  nbd->fac = 1.0f;
}

/* custom1: iterations, custom2: maxspeed (0 = nolimit) */
void register_node_type_cmp_vecblur(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_VECBLUR, "Vector Blur", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_vecblur_in, cmp_node_vecblur_out);
  node_type_init(&ntype, node_composit_init_vecblur);
  node_type_storage(
      &ntype, "NodeBlurData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
