#include "../node_shader_util.h"

/* **************** Wavelength ******************** */
static bNodeSocketTemplate sh_node_wavelength_in[] = {
    {SOCK_FLOAT, N_("Wavelength"), 500.0f, 0.0f, 0.0f, 0.0f, 380.0f, 780.0f},
    {-1, ""},
};

static bNodeSocketTemplate sh_node_wavelength_out[] = {
    {SOCK_RGBA, N_("Color")},
    {-1, ""},
};

/* node type definition */
void register_node_type_sh_wavelength(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_WAVELENGTH, "Wavelength", NODE_CLASS_CONVERTOR, 0);
  node_type_size_preset(&ntype, NODE_SIZE_MIDDLE);
  node_type_socket_templates(&ntype, sh_node_wavelength_in, sh_node_wavelength_out);
  node_type_init(&ntype, NULL);
  node_type_storage(&ntype, "", NULL, NULL);

  nodeRegisterType(&ntype);
}
