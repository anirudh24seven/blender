/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* ******************* Color Spill Suppression ********************************* */
static bNodeSocketTemplate cmp_node_color_spill_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_FACTOR},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_color_spill_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_color_spill(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeColorspill *ncs = MEM_callocN(sizeof(NodeColorspill), "node colorspill");
  node->storage = ncs;
  node->custom1 = 2;    /* green channel */
  node->custom2 = 0;    /* simple limit algo*/
  ncs->limchan = 0;     /* limit by red */
  ncs->limscale = 1.0f; /* limit scaling factor */
  ncs->unspill = 0;     /* do not use unspill */
}

void register_node_type_cmp_color_spill(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COLOR_SPILL, "Color Spill", NODE_CLASS_MATTE, 0);
  node_type_socket_templates(&ntype, cmp_node_color_spill_in, cmp_node_color_spill_out);
  node_type_init(&ntype, node_composit_init_color_spill);
  node_type_storage(
      &ntype, "NodeColorspill", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
