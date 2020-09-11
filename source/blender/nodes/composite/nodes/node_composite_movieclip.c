/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

#include "BKE_context.h"
#include "BKE_lib_id.h"

static bNodeSocketTemplate cmp_node_movieclip_out[] = {
    {SOCK_RGBA, N_("Image")},
    {SOCK_FLOAT, N_("Alpha")},
    {SOCK_FLOAT, N_("Offset X")},
    {SOCK_FLOAT, N_("Offset Y")},
    {SOCK_FLOAT, N_("Scale")},
    {SOCK_FLOAT, N_("Angle")},
    {-1, ""},
};

static void init(const bContext *C, PointerRNA *ptr)
{
  bNode *node = ptr->data;
  Scene *scene = CTX_data_scene(C);
  MovieClipUser *user = MEM_callocN(sizeof(MovieClipUser), "node movie clip user");

  node->id = (ID *)scene->clip;
  id_us_plus(node->id);
  node->storage = user;
  user->framenr = 1;
}

void register_node_type_cmp_movieclip(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MOVIECLIP, "Movie Clip", NODE_CLASS_INPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, NULL, cmp_node_movieclip_out);
  ntype.initfunc_api = init;
  node_type_storage(
      &ntype, "MovieClipUser", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
