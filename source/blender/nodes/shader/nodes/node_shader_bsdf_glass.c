#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_bsdf_glass_in[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Roughness"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("IOR"), 1.45f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f},
    {SOCK_VECTOR, N_("Normal"), 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_bsdf_glass_out[] = {
    {SOCK_SHADER, N_("BSDF")},
    {-1, ""},
};

static void node_shader_init_glass(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = SHD_GLOSSY_BECKMANN;
}

static int node_shader_gpu_bsdf_glass(GPUMaterial *mat,
                                      bNode *node,
                                      bNodeExecData *UNUSED(execdata),
                                      GPUNodeStack *in,
                                      GPUNodeStack *out)
{
  if (!in[3].link) {
    GPU_link(mat, "world_normals_get", &in[3].link);
  }

  GPU_material_flag_set(mat, GPU_MATFLAG_GLOSSY | GPU_MATFLAG_REFRACT);

  return GPU_stack_link(mat, node, "node_bsdf_glass", in, out, GPU_constant(&node->ssr_id));
}

/* node type definition */
void register_node_type_sh_bsdf_glass(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_BSDF_GLASS, "Glass BSDF", NODE_CLASS_SHADER, 0);
  node_type_socket_templates(&ntype, sh_node_bsdf_glass_in, sh_node_bsdf_glass_out);
  node_type_size_preset(&ntype, NODE_SIZE_MIDDLE);
  node_type_init(&ntype, node_shader_init_glass);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, node_shader_gpu_bsdf_glass);

  nodeRegisterType(&ntype);
}
