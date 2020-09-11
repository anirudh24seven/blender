/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SET ALPHA ******************** */
static bNodeSocketTemplate cmp_node_setalpha_in[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Alpha"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_setalpha_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_setalpha(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_SETALPHA, "Set Alpha", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_setalpha_in, cmp_node_setalpha_out);

  nodeRegisterType(&ntype);
}
