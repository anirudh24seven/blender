#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_tex_checker_in[] = {
    {SOCK_VECTOR, N_("Vector"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {SOCK_RGBA, N_("Color1"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {SOCK_RGBA, N_("Color2"), 0.2f, 0.2f, 0.2f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT,
     N_("Scale"),
     5.0f,
     0.0f,
     0.0f,
     0.0f,
     -1000.0f,
     1000.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_tex_checker_out[] = {
    {SOCK_RGBA, N_("Color"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
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

static void node_shader_init_tex_checker(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTexChecker *tex = MEM_callocN(sizeof(NodeTexChecker), "NodeTexChecker");
  BKE_texture_mapping_default(&tex->base.tex_mapping, TEXMAP_TYPE_POINT);
  BKE_texture_colormapping_default(&tex->base.color_mapping);

  node->storage = tex;
}

static int node_shader_gpu_tex_checker(GPUMaterial *mat,
                                       bNode *node,
                                       bNodeExecData *UNUSED(execdata),
                                       GPUNodeStack *in,
                                       GPUNodeStack *out)
{
  node_shader_gpu_default_tex_coord(mat, node, &in[0].link);
  node_shader_gpu_tex_mapping(mat, node, in, out);

  return GPU_stack_link(mat, node, "node_tex_checker", in, out);
}

/* node type definition */
void register_node_type_sh_tex_checker(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_TEX_CHECKER, "Checker Texture", NODE_CLASS_TEXTURE, 0);
  node_type_socket_templates(&ntype, sh_node_tex_checker_in, sh_node_tex_checker_out);
  node_type_init(&ntype, node_shader_init_tex_checker);
  node_type_storage(
      &ntype, "NodeTexChecker", node_free_standard_storage, node_copy_standard_storage);
  node_type_gpu(&ntype, node_shader_gpu_tex_checker);

  nodeRegisterType(&ntype);
}
