#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_uvalongstroke_out[] = {
    {SOCK_VECTOR, N_("UV"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

/* node type definition */
void register_node_type_sh_uvalongstroke(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_UVALONGSTROKE, "UV Along Stroke", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_uvalongstroke_out);
  node_type_init(&ntype, NULL);

  nodeRegisterType(&ntype);
}
