/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

#include <limits.h>

/* ************ qdn: Defocus node ****************** */
static bNodeSocketTemplate cmp_node_defocus_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Z"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate cmp_node_defocus_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_composit_init_defocus(bNodeTree *UNUSED(ntree), bNode *node)
{
  /* qdn: defocus node */
  NodeDefocus *nbd = MEM_callocN(sizeof(NodeDefocus), "node defocus data");
  nbd->bktype = 0;
  nbd->rotation = 0.0f;
  nbd->preview = 1;
  nbd->gamco = 0;
  nbd->samples = 16;
  nbd->fstop = 128.f;
  nbd->maxblur = 16;
  nbd->bthresh = 1.f;
  nbd->scale = 1.f;
  nbd->no_zbuf = 1;
  node->storage = nbd;
}

void register_node_type_cmp_defocus(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_DEFOCUS, "Defocus", NODE_CLASS_OP_FILTER, 0);
  node_type_socket_templates(&ntype, cmp_node_defocus_in, cmp_node_defocus_out);
  node_type_init(&ntype, node_composit_init_defocus);
  node_type_storage(&ntype, "NodeDefocus", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
