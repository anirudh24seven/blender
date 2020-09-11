#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_tex_brick_in[] = {
    {SOCK_VECTOR,
     N_("Vector"),
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     1.0f,
     PROP_NONE,
     SOCK_HIDE_VALUE | SOCK_NO_INTERNAL_LINK},
    {SOCK_RGBA, N_("Color1"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f},
    {SOCK_RGBA, N_("Color2"), 0.2f, 0.2f, 0.2f, 1.0f, 0.0f, 1.0f},
    {SOCK_RGBA,
     N_("Mortar"),
     0.0f,
     0.0f,
     0.0f,
     1.0f,
     0.0f,
     1.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
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
    {SOCK_FLOAT,
     N_("Mortar Size"),
     0.02f,
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     0.125f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {SOCK_FLOAT,
     N_("Mortar Smooth"),
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     1.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {SOCK_FLOAT,
     N_("Bias"),
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     -1.0f,
     1.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {SOCK_FLOAT,
     N_("Brick Width"),
     0.5f,
     0.0f,
     0.0f,
     0.0f,
     0.01f,
     100.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {SOCK_FLOAT,
     N_("Row Height"),
     0.25f,
     0.0f,
     0.0f,
     0.0f,
     0.01f,
     100.0f,
     PROP_NONE,
     SOCK_NO_INTERNAL_LINK},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_tex_brick_out[] = {
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

static void node_shader_init_tex_brick(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeTexBrick *tex = MEM_callocN(sizeof(NodeTexBrick), "NodeTexBrick");
  BKE_texture_mapping_default(&tex->base.tex_mapping, TEXMAP_TYPE_POINT);
  BKE_texture_colormapping_default(&tex->base.color_mapping);

  tex->offset = 0.5f;
  tex->squash = 1.0f;
  tex->offset_freq = 2;
  tex->squash_freq = 2;

  node->storage = tex;

  LISTBASE_FOREACH (bNodeSocket *, sock, &node->inputs) {
    if (STREQ(sock->name, "Mortar Smooth")) {
      ((bNodeSocketValueFloat *)sock->default_value)->value = 0.1f;
    }
  }
}

static int node_shader_gpu_tex_brick(GPUMaterial *mat,
                                     bNode *node,
                                     bNodeExecData *UNUSED(execdata),
                                     GPUNodeStack *in,
                                     GPUNodeStack *out)
{
  node_shader_gpu_default_tex_coord(mat, node, &in[0].link);
  node_shader_gpu_tex_mapping(mat, node, in, out);
  NodeTexBrick *tex = (NodeTexBrick *)node->storage;
  float offset_freq = tex->offset_freq;
  float squash_freq = tex->squash_freq;
  return GPU_stack_link(mat,
                        node,
                        "node_tex_brick",
                        in,
                        out,
                        GPU_uniform(&tex->offset),
                        GPU_constant(&offset_freq),
                        GPU_uniform(&tex->squash),
                        GPU_constant(&squash_freq));
}

/* node type definition */
void register_node_type_sh_tex_brick(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_TEX_BRICK, "Brick Texture", NODE_CLASS_TEXTURE, 0);
  node_type_socket_templates(&ntype, sh_node_tex_brick_in, sh_node_tex_brick_out);
  node_type_size_preset(&ntype, NODE_SIZE_MIDDLE);
  node_type_init(&ntype, node_shader_init_tex_brick);
  node_type_storage(
      &ntype, "NodeTexBrick", node_free_standard_storage, node_copy_standard_storage);
  node_type_gpu(&ntype, node_shader_gpu_tex_brick);

  nodeRegisterType(&ntype);
}
