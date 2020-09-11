/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SEPARATE HSVA ******************** */
static bNodeSocketTemplate cmp_node_sephsva_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_sephsva_out[] = {
    {SOCK_FLOAT, N_("H")},
    {SOCK_FLOAT, N_("S")},
    {SOCK_FLOAT, N_("V")},
    {SOCK_FLOAT, N_("A")},
    {-1, ""},
};

void register_node_type_cmp_sephsva(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SEPHSVA, "Separate HSVA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_sephsva_in, cmp_node_sephsva_out);

  nodeRegisterType(&ntype);
}

/* **************** COMBINE HSVA ******************** */
static bNodeSocketTemplate cmp_node_combhsva_in[] = {
    {SOCK_FLOAT, N_("H"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("S"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("V"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("A"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_combhsva_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_combhsva(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COMBHSVA, "Combine HSVA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_combhsva_in, cmp_node_combhsva_out);

  nodeRegisterType(&ntype);
}
