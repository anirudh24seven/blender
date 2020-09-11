#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_output_linestyle_in[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 0.0f, 1.0f, 1.0f},
    {SOCK_FLOAT, N_("Color Fac"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("Alpha"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {SOCK_FLOAT, N_("Alpha Fac"), 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, PROP_FACTOR},
    {-1, ""},
};

/* node type definition */
void register_node_type_sh_output_linestyle(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_OUTPUT_LINESTYLE, "Line Style Output", NODE_CLASS_OUTPUT, 0);
  node_type_socket_templates(&ntype, sh_node_output_linestyle_in, NULL);
  node_type_init(&ntype, NULL);

  /* Do not allow muting output node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
