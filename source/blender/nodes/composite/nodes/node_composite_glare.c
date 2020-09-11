/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

static bNodeSocketTemplate cmp_node_glare_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_glare_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_glare(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeGlare *ndg = MEM_callocN(sizeof(NodeGlare), "node glare data");
  ndg->quality = 1;
  ndg->type = 2;
  ndg->iter = 3;
  ndg->colmod = 0.25;
  ndg->mix = 0;
  ndg->threshold = 1;
  ndg->star_45 = true;
  ndg->streaks = 4;
  ndg->angle_ofs = 0.0f;
  ndg->fade = 0.9;
  ndg->size = 8;
  node->storage = ndg;
}

void register_node_type_cmp_glare(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_GLARE, "Glare", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_glare_in, cmp_node_glare_out);
  node_type_init(&ntype, node_composit_init_glare);
  node_type_storage(&ntype, "NodeGlare", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
