/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

#include "BKE_context.h"
#include "BKE_lib_id.h"

/* **************** Translate  ******************** */

static bNodeSocketTemplate cmp_node_stabilize2d_in[] = {
    {SOCK_RGBA, N_("Image"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate cmp_node_stabilize2d_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void init(const bContext *C, PointerRNA *ptr)
{
  bNode *node = ptr->data;
  Scene *scene = CTX_data_scene(C);

  node->id = (ID *)scene->clip;
  id_us_plus(node->id);

  /* default to bilinear, see node_sampler_type_items in rna_nodetree.c */
  node->custom1 = 1;
}

void register_node_type_cmp_stabilize2d(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_STABILIZE2D, "Stabilize 2D", NODE_CLASS_DISTORT, 0);
  node_type_socket_templates(&ntype, cmp_node_stabilize2d_in, cmp_node_stabilize2d_out);
  ntype.initfunc_api = init;

  nodeRegisterType(&ntype);
}
