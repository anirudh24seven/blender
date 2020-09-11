/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** MAP VALUE ******************** */
static bNodeSocketTemplate cmp_node_map_value_in[] = {
    {SOCK_FLOAT, N_("Value"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_map_value_out[] = {
    {SOCK_FLOAT, N_("Value")},
    {-1, ""},
};

static void node_composit_init_map_value(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->storage = BKE_texture_mapping_add(TEXMAP_TYPE_POINT);
}

void register_node_type_cmp_map_value(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MAP_VALUE, "Map Value", NODE_CLASS_OP_VECTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_map_value_in, cmp_node_map_value_out);
  node_type_init(&ntype, node_composit_init_map_value);
  node_type_storage(&ntype, "TexMapping", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
