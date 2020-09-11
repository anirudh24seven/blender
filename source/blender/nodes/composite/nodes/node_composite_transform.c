/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Transform  ******************** */

static bNodeSocketTemplate cmp_node_transform_in[] = {
    {SOCK_RGBA, N_("Image"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("X"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f},
    {SOCK_FLOAT, N_("Y"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f},
    {SOCK_FLOAT, N_("Angle"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f, PROP_ANGLE},
    {SOCK_FLOAT, N_("Scale"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0001f, CMP_SCALE_MAX},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_transform_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_transform(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_TRANSFORM, "Transform", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_transform_in, cmp_node_transform_out);

  nodeRegisterType(&ntype);
}
