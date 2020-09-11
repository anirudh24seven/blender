#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_bevel_in[] = {
    {SOCK_FLOAT, N_("Radius"), 0.05f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_bevel_out[] = {
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static void node_shader_init_bevel(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = 4; /* samples */
}

static int gpu_shader_bevel(GPUMaterial *mat,
                            bNode *node,
                            bNodeExecData *UNUSED(execdata),
                            GPUNodeStack *in,
                            GPUNodeStack *out)
{
  if (!in[1].link) {
    GPU_link(mat,
             "direction_transform_m4v3",
             GPU_builtin(GPU_VIEW_NORMAL),
             GPU_builtin(GPU_INVERSE_VIEW_MATRIX),
             &in[1].link);
  }

  return GPU_stack_link(mat, node, "node_bevel", in, out);
}

/* node type definition */
void register_node_type_sh_bevel(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_BEVEL, "Bevel", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, sh_node_bevel_in, sh_node_bevel_out);
  node_type_init(&ntype, node_shader_init_bevel);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, gpu_shader_bevel);

  nodeRegisterType(&ntype);
}
