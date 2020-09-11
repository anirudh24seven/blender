/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_trackpos_out[] = {
    {SOCK_FLOAT, N_("X")},
    {SOCK_FLOAT, N_("Y")},
    {SOCK_VECTOR, N_("Speed"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_VELOCITY},
    {-1, ""},
};

static void init(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTrackPosData *data = MEM_callocN(sizeof(NodeTrackPosData), "node track position data");

  node->storage = data;
}

void register_node_type_cmp_trackpos(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_TRACKPOS, "Track Position", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, cmp_node_trackpos_out);
  node_type_init(&ntype, init);
  node_type_storage(
      &ntype, "NodeTrackPosData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
