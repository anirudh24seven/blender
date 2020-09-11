/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* ******************* Color Balance ********************************* */
static bNodeSocketTemplate cmp_node_colorcorrection_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Mask"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_colorcorrection_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_colorcorrection(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeColorCorrection *n = node->storage = MEM_callocN(sizeof(NodeColorCorrection),
                                                       "node colorcorrection");
  n->startmidtones = 0.2f;
  n->endmidtones = 0.7f;
  n->master.contrast = 1.0f;
  n->master.gain = 1.0f;
  n->master.gamma = 1.0f;
  n->master.lift = 0.0f;
  n->master.saturation = 1.0f;
  n->midtones.contrast = 1.0f;
  n->midtones.gain = 1.0f;
  n->midtones.gamma = 1.0f;
  n->midtones.lift = 0.0f;
  n->midtones.saturation = 1.0f;
  n->shadows.contrast = 1.0f;
  n->shadows.gain = 1.0f;
  n->shadows.gamma = 1.0f;
  n->shadows.lift = 0.0f;
  n->shadows.saturation = 1.0f;
  n->highlights.contrast = 1.0f;
  n->highlights.gain = 1.0f;
  n->highlights.gamma = 1.0f;
  n->highlights.lift = 0.0f;
  n->highlights.saturation = 1.0f;
  node->custom1 = 7;  // red + green + blue enabled
}

void register_node_type_cmp_colorcorrection(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COLORCORRECTION, "Color Correction", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_colorcorrection_in, cmp_node_colorcorrection_out);
  node_type_size(&ntype, 400, 200, 600);
  node_type_init(&ntype, node_composit_init_colorcorrection);
  node_type_storage(
      &ntype, "NodeColorCorrection", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
