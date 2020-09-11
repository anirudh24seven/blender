#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_output_aov_in[] = {
    {SOCK_RGBA, N_("Color"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Value"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static void node_shader_init_output_aov(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeShaderOutputAOV *aov = MEM_callocN(sizeof(NodeShaderOutputAOV), "NodeShaderOutputAOV");
  node->storage = aov;
}

/* node type definition */
void register_node_type_sh_output_aov(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_OUTPUT_AOV, "AOV Output", NODE_CLASS_OUTPUT, 0);
  node_type_socket_templates(&ntype, sh_node_output_aov_in, NULL);
  node_type_init(&ntype, node_shader_init_output_aov);
  node_type_storage(
      &ntype, "NodeShaderOutputAOV", node_free_standard_storage, node_copy_standard_storage);

  /* Do not allow muting output node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
