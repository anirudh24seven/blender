#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_shadertorgb_in[] = {
    {SOCK_SHADER, N_("Shader")},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_shadertorgb_out[] = {
    {SOCK_RGBA, N_("Color")},
    {SOCK_FLOAT, N_("Alpha")},
    {-1, ""},
};

static int node_shader_gpu_shadertorgb(GPUMaterial *mat,
                                       bNode *node,
                                       bNodeExecData *UNUSED(execdata),
                                       GPUNodeStack *in,
                                       GPUNodeStack *out)
{
  /* Because node_shader_to_rgba is using fallback_cubemap()
   * we need to tag material as glossy. */
  GPU_material_flag_set(mat, GPU_MATFLAG_GLOSSY);

  return GPU_stack_link(mat, node, "node_shader_to_rgba", in, out);
}

/* node type definition */
void register_node_type_sh_shadertorgb(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_SHADERTORGB, "Shader to RGB", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, sh_node_shadertorgb_in, sh_node_shadertorgb_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_shadertorgb);

  nodeRegisterType(&ntype);
}
