#include "../node_shader_util.h"

/* **************** IES Light ******************** */

static bNodeSocketTemplate sh_node_tex_ies_in[] = {
    {SOCK_VECTOR, N_("Vector"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_NONE, SOCK_HIDE_VALUE},
    {SOCK_FLOAT, N_("Strength"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000000.0f, PROP_NONE},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_tex_ies_out[] = {
    {SOCK_FLOAT, N_("Fac")},
    {-1, ""},
};

static void node_shader_init_tex_ies(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeShaderTexIES *tex = MEM_callocN(sizeof(NodeShaderTexIES), "NodeShaderIESLight");
  node->storage = tex;
}

/* node type definition */
void register_node_type_sh_tex_ies(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_TEX_IES, "IES Texture", NODE_CLASS_TEXTURE, 0);
  node_type_socket_templates(&ntype, sh_node_tex_ies_in, sh_node_tex_ies_out);
  node_type_init(&ntype, node_shader_init_tex_ies);
  node_type_storage(
      &ntype, "NodeShaderTexIES", node_free_standard_storage, node_copy_standard_storage);

  nodeRegisterType(&ntype);
}
