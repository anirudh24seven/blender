/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Premul and Key Alpha Convert ******************** */

static bNodeSocketTemplate cmp_node_premulkey_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_premulkey_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

void register_node_type_cmp_premulkey(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_PREMULKEY, "Alpha Convert", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_premulkey_in, cmp_node_premulkey_out);

  nodeRegisterType(&ntype);
}
