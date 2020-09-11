#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_output_light_in[] = {
    {SOCK_SHADER, N_("Surface"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};

/* node type definition */
void register_node_type_sh_output_light(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_OUTPUT_LIGHT, "Light Output", NODE_CLASS_OUTPUT, 0);
  node_type_socket_templates(&ntype, sh_node_output_light_in, NULL);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);

  /* Do not allow muting output node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
