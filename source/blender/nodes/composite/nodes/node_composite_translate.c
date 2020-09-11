/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** Translate  ******************** */

static bNodeSocketTemplate cmp_node_translate_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("X"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Y"), 0.0f, 0.0f, 0.0f, 0.0f, -10000.0f, 10000.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_translate_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_translate(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTranslateData *data = MEM_callocN(sizeof(NodeTranslateData), "node translate data");
  node->storage = data;
}

void register_node_type_cmp_translate(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_TRANSLATE, "Translate", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_translate_in, cmp_node_translate_out);
  node_type_init(&ntype, node_composit_init_translate);
  node_type_storage(
      &ntype, "NodeTranslateData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
