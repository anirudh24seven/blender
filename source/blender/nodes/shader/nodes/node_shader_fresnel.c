#include "../node_shader_util.h"

/* **************** Fresnel ******************** */
static bNodeSocketTemplate sh_node_fresnel_in[] = {
    {SOCK_FLOAT, N_("IOR"), 1.45f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_fresnel_out[] = {
    {SOCK_FLOAT, N_("Fac"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {-1, ""},
};

static int node_shader_gpu_fresnel(GPUMaterial *mat,
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

  return GPU_stack_link(mat, node, "node_fresnel", in, out, GPU_builtin(GPU_VIEW_POSITION));
}

static void node_shader_exec_fresnel(void *UNUSED(data),
                                     int UNUSED(thread),
                                     bNode *UNUSED(node),
                                     bNodeExecData *UNUSED(execdata),
                                     bNodeStack **UNUSED(in),
                                     bNodeStack **UNUSED(out))
{
}

/* node type definition */
void register_node_type_sh_fresnel(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_FRESNEL, "Fresnel", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, sh_node_fresnel_in, sh_node_fresnel_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_fresnel);
  node_type_exec(&ntype, NULL, NULL, node_shader_exec_fresnel);

  nodeRegisterType(&ntype);
}
