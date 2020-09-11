/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* ******************* Channel Matte Node ********************************* */
static bNodeSocketTemplate cmp_node_channel_matte_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_channel_matte_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Matte")},
    {-1, ""},
};

static void node_composit_init_channel_matte(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeChroma *c = MEM_callocN(sizeof(NodeChroma), "node chroma");
  node->storage = c;
  c->t1 = 1.0f;
  c->t2 = 0.0f;
  c->t3 = 0.0f;
  c->fsize = 0.0f;
  c->fstrength = 0.0f;
  c->algorithm = 1;  /*max channel limiting */
  c->channel = 1;    /* limit by red */
  node->custom1 = 1; /* RGB channel */
  node->custom2 = 2; /* Green Channel */
}

void register_node_type_cmp_channel_matte(void)
{
  static bNodeType ntype;

  cmp_node_type_base(
      &ntype, CMP_NODE_CHANNEL_MATTE, "Channel Key", NODE_CLASS_MATTE, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_channel_matte_in, cmp_node_channel_matte_out);
  node_type_init(&ntype, node_composit_init_channel_matte);
  node_type_storage(&ntype, "NodeChroma", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
