#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_vector_displacement_in[] = {
    {SOCK_RGBA, N_("Vector"), 0.00f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {SOCK_FLOAT, N_("Midlevel"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {SOCK_FLOAT, N_("Scale"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_vector_displacement_out[] = {
    {SOCK_VECTOR, N_("Displacement"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static void node_shader_init_vector_displacement(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = SHD_SPACE_TANGENT; /* space */
}

static int gpu_shader_vector_displacement(GPUMaterial *mat,
                                          bNode *node,
                                          bNodeExecData *UNUSED(execdata),
                                          GPUNodeStack *in,
                                          GPUNodeStack *out)
{
  if (node->custom1 == SHD_SPACE_TANGENT) {
    return GPU_stack_link(mat,
                          node,
                          "node_vector_displacement_tangent",
                          in,
                          out,
                          GPU_attribute(mat, CD_TANGENT, ""),
                          GPU_builtin(GPU_WORLD_NORMAL),
                          GPU_builtin(GPU_OBJECT_MATRIX),
                          GPU_builtin(GPU_VIEW_MATRIX));
  }
  if (node->custom1 == SHD_SPACE_OBJECT) {
    return GPU_stack_link(
        mat, node, "node_vector_displacement_object", in, out, GPU_builtin(GPU_OBJECT_MATRIX));
  }

  return GPU_stack_link(mat, node, "node_vector_displacement_world", in, out);
}

/* node type definition */
void register_node_type_sh_vector_displacement(void)
{
  static bNodeType ntype;

  sh_node_type_base(
      &ntype, SH_NODE_VECTOR_DISPLACEMENT, "Vector Displacement", NODE_CLASS_OP_VECTOR, 0);
  node_type_socket_templates(
      &ntype, sh_node_vector_displacement_in, sh_node_vector_displacement_out);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_init(&ntype, node_shader_init_vector_displacement);
  node_type_gpu(&ntype, gpu_shader_vector_displacement);

  nodeRegisterType(&ntype);
}
