#include "../node_shader_util.h"

static bNodeSocketTemplate outputs[] = {
    {SOCK_FLOAT, N_("Is Strand"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Intercept"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Thickness"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_VECTOR, N_("Tangent Normal"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    /*{ SOCK_FLOAT,  0, N_("Fade"),             0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},*/
    {SOCK_FLOAT, N_("Random")},
    {-1, ""},
};

static int node_shader_gpu_hair_info(GPUMaterial *mat,
                                     bNode *node,
                                     bNodeExecData *UNUSED(execdata),
                                     GPUNodeStack *in,
                                     GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_hair_info", in, out);
}

/* node type definition */
void register_node_type_sh_hair_info(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_HAIR_INFO, "Hair Info", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, outputs);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_hair_info);

  nodeRegisterType(&ntype);
}
