#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_emission_in[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Strength"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000000.0f},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_emission_out[] = {
    {SOCK_SHADER, N_("Emission")},
    {-1, ""},
};

static int node_shader_gpu_emission(GPUMaterial *mat,
                                    bNode *node,
                                    bNodeExecData *UNUSED(execdata),
                                    GPUNodeStack *in,
                                    GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_emission", in, out, GPU_builtin(GPU_VIEW_NORMAL));
}

/* node type definition */
void register_node_type_sh_emission(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_EMISSION, "Emission", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_emission_in, sh_node_emission_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_emission);

  nodeRegisterType(&ntype);
}
