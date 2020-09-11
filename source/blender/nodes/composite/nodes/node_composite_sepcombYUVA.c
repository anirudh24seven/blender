/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SEPARATE YUVA ******************** */
static bNodeSocketTemplate cmp_node_sepyuva_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f}, {-1, ""}};
static bNodeSocketTemplate cmp_node_sepyuva_out[] = {
    {SOCK_FLOAT, N_("Y")},
    {SOCK_FLOAT, N_("U")},
    {SOCK_FLOAT, N_("V")},
    {SOCK_FLOAT, N_("A")},
    {-1, ""},
};

void register_node_type_cmp_sepyuva(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SEPYUVA, "Separate YUVA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_sepyuva_in, cmp_node_sepyuva_out);

  nodeRegisterType(&ntype);
}

/* **************** COMBINE YUVA ******************** */
static bNodeSocketTemplate cmp_node_combyuva_in[] = {
    {SOCK_FLOAT, N_("Y"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("U"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("V"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_FLOAT, N_("A"), 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_combyuva_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_combyuva(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_COMBYUVA, "Combine YUVA", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_combyuva_in, cmp_node_combyuva_out);

  nodeRegisterType(&ntype);
}
