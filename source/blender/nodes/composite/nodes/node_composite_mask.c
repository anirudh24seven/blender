/** \file
 * \ingroup cmpnodes
 */

#include "DNA_mask_types.h"

#include "node_composite_util.h"

/* **************** Translate  ******************** */

static bNodeSocketTemplate cmp_node_mask_out[] = {{SOCK_FLOAT, "Mask"}, {-1, ""}};

static void node_composit_init_mask(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeMask *data = MEM_callocN(sizeof(NodeMask), "NodeMask");
  data->size_x = data->size_y = 256;
  node->storage = data;

  node->custom2 = 16;   /* samples */
  node->custom3 = 0.5f; /* shutter */
}

static void node_mask_label(bNodeTree *UNUSED(ntree), bNode *node, char *label, int maxlen)
{
  if (node->id != NULL) {
    BLI_strncpy(label, node->id->name + 2, maxlen);
  }
  else {
    BLI_strncpy(label, IFACE_("Mask"), maxlen);
  }
}

void register_node_type_cmp_mask(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MASK, "Mask", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, cmp_node_mask_out);
  node_type_init(&ntype, node_composit_init_mask);
  node_type_label(&ntype, node_mask_label);

  node_type_storage(&ntype, "NodeMask", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
