#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_object_info_out[] = {
    {SOCK_VECTOR, N_("Location"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_RGBA, N_("Color"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Object Index"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Material Index"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Random"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

static int node_shader_gpu_object_info(GPUMaterial *mat,
                                       bNode *node,
                                       bNodeExecData *UNUSED(execdata),
                                       GPUNodeStack *in,
                                       GPUNodeStack *out)
{
  Material *ma = GPU_material_get_material(mat);
  float index = ma ? ma->index : 0.0f;
  return GPU_stack_link(mat,
                        node,
                        "node_object_info",
                        in,
                        out,
                        GPU_builtin(GPU_OBJECT_MATRIX),
                        GPU_builtin(GPU_OBJECT_COLOR),
                        GPU_builtin(GPU_OBJECT_INFO),
                        GPU_constant(&index));
}

void register_node_type_sh_object_info(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_OBJECT_INFO, "Object Info", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_object_info_out);
  node_type_gpu(&ntype, node_shader_gpu_object_info);

  nodeRegisterType(&ntype);
}
