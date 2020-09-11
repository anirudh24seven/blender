/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** BILATERALBLUR ******************** */
static bNodeSocketTemplate cmp_node_bilateralblur_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_RGBA, N_("Determinator"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""}};

static bNodeSocketTemplate cmp_node_bilateralblur_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_bilateralblur(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeBilateralBlurData *nbbd = MEM_callocN(sizeof(NodeBilateralBlurData),
                                            "node bilateral blur data");
  node->storage = nbbd;
  nbbd->iter = 1;
  nbbd->sigma_color = 0.3;
  nbbd->sigma_space = 5.0;
}

void register_node_type_cmp_bilateralblur(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_BILATERALBLUR, "Bilateral Blur", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_bilateralblur_in, cmp_node_bilateralblur_out);
  node_type_init(&ntype, node_composit_init_bilateralblur);
  node_type_storage(
      &ntype, "NodeBilateralBlurData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
