/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_huecorrect_in[] = {
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_huecorrect_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_huecorrect(bNodeTree *UNUSED(ntree), bNode *node)
{
  CurveMapping *cumapping = node->storage = BKE_curvemapping_add(1, 0.0f, 0.0f, 1.0f, 1.0f);
  int c;

  cumapping->preset = CURVE_PRESET_MID9;

  for (c = 0; c < 3; c++) {
    CurveMap *cuma = &cumapping->cm[c];
    BKE_curvemap_reset(cuma, &cumapping->clipr, cumapping->preset, CURVEMAP_SLOPE_POSITIVE);
  }

  /* default to showing Saturation */
  cumapping->cur = 1;
}

void register_node_type_cmp_huecorrect(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_HUECORRECT, "Hue Correct", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_huecorrect_in, cmp_node_huecorrect_out);
  node_type_size(&ntype, 320, 140, 500);
  node_type_init(&ntype, node_composit_init_huecorrect);
  node_type_storage(&ntype, "CurveMapping", node_free_curves, node_copy_curves);

  nodeRegisterType(&ntype);
}
