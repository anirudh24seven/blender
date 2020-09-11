#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_bsdf_transparent_in[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_bsdf_transparent_out[] = {
    {SOCK_SHADER, N_("BSDF")},
    {-1, ""},
};

static int node_shader_gpu_bsdf_transparent(GPUMaterial *mat,
                                            bNode *node,
                                            bNodeExecData *UNUSED(execdata),
                                            GPUNodeStack *in,
                                            GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_bsdf_transparent", in, out);
}

/* node type definition */
void register_node_type_sh_bsdf_transparent(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_BSDF_TRANSPARENT, "Transparent BSDF", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_bsdf_transparent_in, sh_node_bsdf_transparent_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_bsdf_transparent);

  nodeRegisterType(&ntype);
}
