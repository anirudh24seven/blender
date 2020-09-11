/** \file
 * \ingroup shdnodes
 */

#include "node_shader_util.h"

/* **************** RGB ******************** */
static bNodeSocketTemplate sh_node_rgb_out[] = {
    {SOCK_RGBA, N_("Color"), 0.5f, 0.5f, 0.5f, 1.0f},
    {-1, ""},
};

static int gpu_shader_rgb(GPUMaterial *mat,
                          bNode *node,
                          bNodeExecData *UNUSED(execdata),
                          GPUNodeStack *in,
                          GPUNodeStack *out)
{
  GPUNodeLink *link = GPU_uniformbuf_link_out(mat, node, out, 0);
  return GPU_stack_link(mat, node, "set_rgba", in, out, link);
}

void register_node_type_sh_rgb(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_RGB, "RGB", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_rgb_out);
  node_type_gpu(&ntype, gpu_shader_rgb);

  nodeRegisterType(&ntype);
}
