/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Hue Saturation ******************** */
static bNodeSocketTemplate cmp_node_hue_sat_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Hue"), 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("Saturation"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("Value"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("Fac"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_hue_sat_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_hue_sat(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_HUE_SAT, "Hue Saturation Value", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, cmp_node_hue_sat_in, cmp_node_hue_sat_out);

  nodeRegisterType(&ntype);
}
