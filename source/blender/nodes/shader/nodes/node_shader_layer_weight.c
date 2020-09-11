#include "../node_shader_util.h"

/* **************** Layer Weight ******************** */

static bNodeSocketTemplate sh_node_layer_weight_in[] = {
    {SOCK_FLOAT, N_("Blend"), 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_layer_weight_out[] = {
    {SOCK_FLOAT, N_("Fresnel"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Facing"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static int node_shader_gpu_layer_weight(GPUMaterial *mat,
                                        bNode *node,
                                        bNodeExecData *UNUSED(execdata),
                                        GPUNodeStack *in,
                                        GPUNodeStack *out)
{
  if (!in[1].link) {
    in[1].link = GPU_builtin(GPU_VIEW_NORMAL);
  }
  else {
    GPU_link(
        mat, "direction_transform_m4v3", in[1].link, GPU_builtin(GPU_VIEW_MATRIX), &in[1].link);
  }

  return GPU_stack_link(mat, node, "node_layer_weight", in, out, GPU_builtin(GPU_VIEW_POSITION));
}

static void node_shader_exec_layer_weight(void *UNUSED(data),
                                          int UNUSED(thread),
                                          bNode *UNUSED(node),
                                          bNodeExecData *UNUSED(execdata),
                                          bNodeStack **UNUSED(in),
                                          bNodeStack **UNUSED(out))
{
}

/* node type definition */
void register_node_type_sh_layer_weight(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_LAYER_WEIGHT, "Layer Weight", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, sh_node_layer_weight_in, sh_node_layer_weight_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_layer_weight);
  node_type_exec(&ntype, NULL, NULL, node_shader_exec_layer_weight);

  nodeRegisterType(&ntype);
}
