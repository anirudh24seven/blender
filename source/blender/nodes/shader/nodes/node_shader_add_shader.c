#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_add_shader_in[] = {
    {SOCK_SHADER, N_("Shader")},
    {SOCK_SHADER, N_("Shader")},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_add_shader_out[] = {
    {SOCK_SHADER, N_("Shader")},
    {-1, ""},
};

static int node_shader_gpu_add_shader(GPUMaterial *mat,
                                      bNode *node,
                                      bNodeExecData *UNUSED(execdata),
                                      GPUNodeStack *in,
                                      GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_add_shader", in, out);
}

/* node type definition */
void register_node_type_sh_add_shader(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_ADD_SHADER, "Add Shader", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_add_shader_in, sh_node_add_shader_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_add_shader);

  nodeRegisterType(&ntype);
}
