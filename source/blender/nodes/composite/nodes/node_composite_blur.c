/** The Original Code is Copyright (C) 2006 Blender Foundation.
 * All rights reserved.
 * Juho Vepsäläinen
 */

/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** BLUR ******************** */
static bNodeSocketTemplate cmp_node_blur_in[] = {
    {SOCK_RGBA, N_("Image"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Size"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE},
    {-1, ""}};
static bNodeSocketTemplate cmp_node_blur_out[] = {{SOCK_RGBA, N_("Image")}, {-1, ""}};

static void node_composit_init_blur(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeBlurData *data = MEM_callocN(sizeof(NodeBlurData), "node blur data");
  data->filtertype = R_FILTER_GAUSS;
  node->storage = data;
}

void register_node_type_cmp_blur(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_BLUR, "Blur", NODE_CLASS_OP_FILTER, NODE_PREVIEW);
  node_type_socket_templates(&ntype, cmp_node_blur_in, cmp_node_blur_out);
  node_type_init(&ntype, node_composit_init_blur);
  node_type_storage(
      &ntype, "NodeBlurData", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
