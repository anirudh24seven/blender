/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate inputs[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_VECTOR, N_("Upper Left"), 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_VECTOR, N_("Upper Right"), 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_VECTOR, N_("Lower Left"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_VECTOR, N_("Lower Right"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};

static bNodeSocketTemplate outputs[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Plane")},
    {-1, ""},
};

void register_node_type_cmp_cornerpin(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_CORNERPIN, "Corner Pin", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, inputs, outputs);

  nodeRegisterType(&ntype);
}
