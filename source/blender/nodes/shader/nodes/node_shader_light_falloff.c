#include "../node_shader_util.h"

/* **************** INPUT ********************* */

static bNodeSocketTemplate sh_node_light_falloff_in[] = {
    {SOCK_FLOAT, N_("Strength"), 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000000.0f},
    {SOCK_FLOAT, N_("Smooth"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {-1, ""},
};

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_light_falloff_out[] = {
    {SOCK_FLOAT, N_("Quadratic"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Linear"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Constant"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static int node_shader_gpu_light_falloff(GPUMaterial *mat,
                                         bNode *node,
                                         bNodeExecData *UNUSED(execdata),
                                         GPUNodeStack *in,
                                         GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "node_light_falloff", in, out);
}

/* node type definition */
void register_node_type_sh_light_falloff(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_LIGHT_FALLOFF, "Light Falloff", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, sh_node_light_falloff_in, sh_node_light_falloff_out);
  node_type_size_preset(&ntype, NODE_SIZE_MIDDLE);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_light_falloff);

  nodeRegisterType(&ntype);
}
