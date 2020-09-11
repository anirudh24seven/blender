/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

#include "BKE_context.h"
#include "BKE_lib_id.h"

/* **************** Translate  ******************** */

static bNodeSocketTemplate cmp_node_moviedistortion_in[] = {
    {SOCK_RGBA, N_("Image"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_moviedistortion_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void label(bNodeTree *UNUSED(ntree), bNode *node, char *label, int maxlen)
{
  if (node->custom1 == 0) {
    BLI_strncpy(label, IFACE_("Undistortion"), maxlen);
  }
  else {
    BLI_strncpy(label, IFACE_("Distortion"), maxlen);
  }
}

static void init(const bContext *C, PointerRNA *ptr)
{
  bNode *node = ptr->data;
  Scene *scene = CTX_data_scene(C);

  node->id = (ID *)scene->clip;
  id_us_plus(node->id);
}

static void storage_free(bNode *node)
{
  if (node->storage) {
    BKE_tracking_distortion_free(node->storage);
  }

  node->storage = NULL;
}

static void storage_copy(bNodeTree *UNUSED(dest_ntree), bNode *dest_node, const bNode *src_node)
{
  if (src_node->storage) {
    dest_node->storage = BKE_tracking_distortion_copy(src_node->storage);
  }
}

void register_node_type_cmp_moviedistortion(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MOVIEDISTORTION, "Movie Distortion", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_moviedistortion_in, cmp_node_moviedistortion_out);
  node_type_label(&ntype, label);

  ntype.initfunc_api = init;
  node_type_storage(&ntype, NULL, storage_free, storage_copy);

  nodeRegisterType(&ntype);
}
