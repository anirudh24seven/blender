/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

#include "BKE_global.h"
#include "BKE_image.h"

/* **************** SPLIT VIEWER ******************** */
static bNodeSocketTemplate cmp_node_splitviewer_in[] = {
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_RGBA, N_("Image"), 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static void node_composit_init_splitviewer(bNodeTree *UNUSED(ntree), bNode *node)
{
  ImageUser *iuser = MEM_callocN(sizeof(ImageUser), "node image user");
  node->storage = iuser;
  iuser->sfra = 1;
  iuser->ok = 1;
  node->custom1 = 50; /* default 50% split */

  node->id = (ID *)BKE_image_ensure_viewer(G.main, IMA_TYPE_COMPOSITE, "Viewer Node");
}

void register_node_type_cmp_splitviewer(void)
{
  static bNodeType ntype;

  cmp_node_type_base(
      &ntype, CMP_NODE_SPLITVIEWER, "Split Viewer", NODE_CLASS_OUTPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_splitviewer_in, NULL);
  node_type_init(&ntype, node_composit_init_splitviewer);
  node_type_storage(&ntype, "ImageUser", node_free_standard_storage, node_copy_standard_storage);

  /* Do not allow muting for this node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
