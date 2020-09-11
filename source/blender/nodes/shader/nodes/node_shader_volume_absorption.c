#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_volume_absorption_in[] = {
    {SOCK_RGBA, N_("Color"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Density"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_volume_absorption_out[] = {
    {SOCK_SHADER, N_("Volume")},
    {-1, ""},
};

static int node_shader_gpu_volume_absorption(GPUMaterial *mat,
                                             bNode *node,
                                             bNodeExecData *UNUSED(execdata),
                                             GPUNodeStack *in,
                                             GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_volume_absorption", in, out);
}

/* node type definition */
void register_node_type_sh_volume_absorption(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_VOLUME_ABSORPTION, "Volume Absorption", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_volume_absorption_in, sh_node_volume_absorption_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_volume_absorption);

  nodeRegisterType(&ntype);
}
