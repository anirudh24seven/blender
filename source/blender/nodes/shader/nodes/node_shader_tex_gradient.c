/** The Original Code is Copyright (C) 2005 Gradienter Foundation.
 * All rights reserved.
 */

#include "../node_shader_util.h"

/* **************** BLEND ******************** */

static bNodeSocketTemplate sh_node_tex_gradient_in[] = {
    {SOCK_VECTOR, N_("Vector"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_tex_gradient_out[] = {
    {SOCK_RGBA, N_("Color"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE, SOCK_NO_INTERNAL_LINK},
    {SOCK_FLOAT,
     N_("Fac"),
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     1.0f,
     PROP_FACTOR,
     SOCK_NO_INTERNAL_LINK},
    {-1, ""},
};

static void node_shader_init_tex_gradient(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTexGradient *tex = MEM_callocN(sizeof(NodeTexGradient), "NodeTexGradient");
  BKE_texture_mapping_default(&tex->base.tex_mapping, TEXMAP_TYPE_POINT);
  BKE_texture_colormapping_default(&tex->base.color_mapping);
  tex->gradient_type = SHD_BLEND_LINEAR;

  node->storage = tex;
}

static int node_shader_gpu_tex_gradient(GPUMaterial *mat,
                                        bNode *node,
                                        bNodeExecData *UNUSED(execdata),
                                        GPUNodeStack *in,
                                        GPUNodeStack *out)
{
  node_shader_gpu_default_tex_coord(mat, node, &in[0].link);
  node_shader_gpu_tex_mapping(mat, node, in, out);

  NodeTexGradient *tex = (NodeTexGradient *)node->storage;
  float gradient_type = tex->gradient_type;
  return GPU_stack_link(mat, node, "node_tex_gradient", in, out, GPU_constant(&gradient_type));
}

/* node type definition */
void register_node_type_sh_tex_gradient(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_TEX_GRADIENT, "Gradient Texture", NODE_CLASS_TEXTURE, 0);
  node_type_socket_templates(&ntype, sh_node_tex_gradient_in, sh_node_tex_gradient_out);
  node_type_init(&ntype, node_shader_init_tex_gradient);
  node_type_storage(
      &ntype, "NodeTexGradient", node_free_standard_storage, node_copy_standard_storage);
  node_type_gpu(&ntype, node_shader_gpu_tex_gradient);

  nodeRegisterType(&ntype);
}
