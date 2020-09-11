/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Map UV  ******************** */

static bNodeSocketTemplate cmp_node_mapuv_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_VECTOR, N_("UV"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_mapuv_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_mapuv(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MAP_UV, "Map UV", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_mapuv_in, cmp_node_mapuv_out);

  nodeRegisterType(&ntype);
}
