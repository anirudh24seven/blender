/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SEPARATE RGBA ******************** */
static bNodeSocketTemplate cmp_node_seprgba_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_seprgba_out[] = {
    {SOCK_FLOAT, N_("R")},
    {SOCK_FLOAT, N_("G")},
    {SOCK_FLOAT, N_("B")},
    {SOCK_FLOAT, N_("A")},
    {-1, ""},
};

void register_node_type_cmp_seprgba(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SEPRGBA, "Separate RGBA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_seprgba_in, cmp_node_seprgba_out);

  nodeRegisterType(&ntype);
}

/* **************** COMBINE RGBA ******************** */
static bNodeSocketTemplate cmp_node_combrgba_in[] = {
    {SOCK_FLOAT, N_("R"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("G"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("B"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("A"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_combrgba_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_combrgba(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COMBRGBA, "Combine RGBA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_combrgba_in, cmp_node_combrgba_out);

  nodeRegisterType(&ntype);
}
