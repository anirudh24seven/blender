/** \file
 * \ingroup cmpnodes
 */

#include "node_composite_util.h"

/* **************** SCALAR MATH ******************** */
static bNodeSocketTemplate cmp_node_math_in[] = {
    {SOCK_FLOAT, N_("Value"), 0.5f, 0.5f, 0.5f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Value"), 0.5f, 0.5f, 0.5f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_FLOAT, N_("Value"), 0.0f, 0.5f, 0.5f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {-1, ""}};

static bNodeSocketTemplate cmp_node_math_out[] = {{SOCK_FLOAT, N_("Value")}, {-1, ""}};

void register_node_type_cmp_math(void)
{
  static bNodeType ntype;

  cmp_node_type_base(&ntype, CMP_NODE_MATH, "Math", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, cmp_node_math_in, cmp_node_math_out);
  node_type_label(&ntype, node_math_label);
  node_type_update(&ntype, node_math_update);

  nodeRegisterType(&ntype);
}
