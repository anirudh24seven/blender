#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_holdout_in[] = {
    {-1, ""},
};

static bNodeSocketTemplate sh_node_holdout_out[] = {
    {SOCK_SHADER, N_("Holdout")},
    {-1, ""},
};

static int gpu_shader_rgb(GPUMaterial *mat,
                          bNode *node,
                          bNodeExecData *UNUSED(execdata),
                          GPUNodeStack *in,
                          GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_holdout", in, out);
}

/* node type definition */
void register_node_type_sh_holdout(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_HOLDOUT, "Holdout", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_holdout_in, sh_node_holdout_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, gpu_shader_rgb);

  nodeRegisterType(&ntype);
}
