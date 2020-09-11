#include "node_shader_util.h"

/* **************** Brigh and contrsast  ******************** */

static bNodeSocketTemplate sh_node_brightcontrast_in[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 1.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Bright"), 0.0f, 0.0f, 0.0f, 0.0f, -100.0f, 100.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Contrast"), 0.0f, 0.0f, 0.0f, 0.0f, -100.0f, 100.0f, PROP_NONE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_brightcontrast_out[] = {
    {SOCK_RGBA, N_("Color")},
    {-1, ""},
};

static int gpu_shader_brightcontrast(GPUMaterial *mat,
                                     bNode *node,
                                     bNodeExecData *UNUSED(execdata),
                                     GPUNodeStack *in,
                                     GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "brightness_contrast", in, out);
}

void register_node_type_sh_brightcontrast(void)
{
  static bNodeType ntype;

  sh_fn_node_type_base(&ntype, SH_NODE_BRIGHTCONTRAST, "Bright/Contrast", NODE_CLASS_OP_COLOR, 0);
  node_type_socket_templates(&ntype, sh_node_brightcontrast_in, sh_node_brightcontrast_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, gpu_shader_brightcontrast);

  nodeRegisterType(&ntype);
}
