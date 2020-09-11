/** \file
 * \ingroup cmpnodes
 */

#include "DNA_movieclip_types.h"

#include "BLI_math_base.h"
#include "BLI_math_color.h"

#include "node_composite_util.h"

/* **************** Translate  ******************** */

static bNodeSocketTemplate cmp_node_keyingscreen_out[] = {
    {SOCK_RGBA, "Screen"},
    {-1, ""},
};

static void node_composit_init_keyingscreen(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeKeyingScreenData *data;

  data = MEM_callocN(sizeof(NodeKeyingScreenData), "node keyingscreen data");

  node->storage = data;
}

void register_node_type_cmp_keyingscreen(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_KEYINGSCREEN, "Keying Screen", NODE_CLASS_MATTE, 0);
  node_type_socket_templates(&ntype, NULL, cmp_node_keyingscreen_out);
  node_type_init(&ntype, node_composit_init_keyingscreen);
  node_type_storage(
      &ntype, "NodeKeyingScreenData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
