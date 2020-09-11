#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_attribute_out[] = {
    {SOCK_RGBA, N_("Color")},
    {SOCK_VECTOR, N_("Vector"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {SOCK_FLOAT, N_("Fac"), 0.0f, 0.0f, 0.0f, 0.0f, -FLT_MAX, FLT_MAX, PROP_FACTOR},
    {-1, ""},
};

static void node_shader_init_attribute(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeShaderAttribute *attr = MEM_callocN(sizeof(NodeShaderAttribute), "NodeShaderAttribute");
  node->storage = attr;
}

static int node_shader_gpu_attribute(GPUMaterial *mat,
                                     bNode *node,
                                     bNodeExecData *UNUSED(execdata),
                                     GPUNodeStack *in,
                                     GPUNodeStack *out)
{
  NodeShaderAttribute *attr = node->storage;

  if (GPU_material_is_volume_shader(mat)) {
    if (out[0].hasoutput) {
      out[0].link = GPU_volume_grid(mat, attr->name, GPU_VOLUME_DEFAULT_0);
    }
    if (out[1].hasoutput) {
      out[1].link = GPU_volume_grid(mat, attr->name, GPU_VOLUME_DEFAULT_0);
    }
    if (out[2].hasoutput) {
      out[2].link = GPU_volume_grid(mat, attr->name, GPU_VOLUME_DEFAULT_0);
    }

    return 1;
  }

  GPUNodeLink *cd_attr = GPU_attribute(mat, CD_AUTO_FROM_NAME, attr->name);
  GPU_stack_link(mat, node, "node_attribute", in, out, cd_attr);

  /* for each output. */
  for (int i = 0; sh_node_attribute_out[i].type != -1; i++) {
    node_shader_gpu_bump_tex_coord(mat, node, &out[i].link);
  }

  return 1;
}

/* node type definition */
void register_node_type_sh_attribute(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_ATTRIBUTE, "Attribute", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_attribute_out);
  node_type_init(&ntype, node_shader_init_attribute);
  node_type_storage(
      &ntype, "NodeShaderAttribute", node_free_standard_storage, node_copy_standard_storage);
  node_type_gpu(&ntype, node_shader_gpu_attribute);

  nodeRegisterType(&ntype);
}
