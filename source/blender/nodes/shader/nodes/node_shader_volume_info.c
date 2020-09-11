#include "../node_shader_util.h"

static bNodeSocketTemplate sh_node_volume_info_out[] = {
    {SOCK_RGBA, N_("Color")},
    {SOCK_FLOAT, N_("Density")},
    {SOCK_FLOAT, N_("Flame")},
    {SOCK_FLOAT, N_("Temperature")},
    {-1, ""},
};

static int node_shader_gpu_volume_info(GPUMaterial *mat,
                                       bNode *UNUSED(node),
                                       bNodeExecData *UNUSED(execdata),
                                       GPUNodeStack *UNUSED(in),
                                       GPUNodeStack *out)
{
  if (out[0].hasoutput) {
    out[0].link = GPU_volume_grid(mat, "color", GPU_VOLUME_DEFAULT_0);
  }
  if (out[1].hasoutput) {
    out[1].link = GPU_volume_grid(mat, "density", GPU_VOLUME_DEFAULT_0);
  }
  if (out[2].hasoutput) {
    out[2].link = GPU_volume_grid(mat, "flame", GPU_VOLUME_DEFAULT_0);
  }
  if (out[3].hasoutput) {
    out[3].link = GPU_volume_grid(mat, "temperature", GPU_VOLUME_DEFAULT_0);
  }

  return true;
}

void register_node_type_sh_volume_info(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_VOLUME_INFO, "Volume Info", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_volume_info_out);
  node_type_gpu(&ntype, node_shader_gpu_volume_info);

  nodeRegisterType(&ntype);
}
