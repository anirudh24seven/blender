/** \file
 * \ingroup shdnodes
 */

#include "node_shader_util.h"

/* **************** CAMERA INFO  ******************** */
static bNodeSocketTemplate sh_node_camera_out[] = {
    {SOCK_VECTOR, N_("View Vector")},
    {SOCK_FLOAT, N_("View Z Depth")},
    {SOCK_FLOAT, N_("View Distance")},
    {-1, ""},
};

static int gpu_shader_camera(GPUMaterial *mat,
                             bNode *node,
                             bNodeExecData *UNUSED(execdata),
                             GPUNodeStack *in,
                             GPUNodeStack *out)
{
  GPUNodeLink *viewvec;

  viewvec = GPU_builtin(GPU_VIEW_POSITION);
  GPU_link(mat, "invert_z", viewvec, &viewvec);
  return GPU_stack_link(mat, node, "camera", in, out, viewvec);
}

void register_node_type_sh_camera(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_CAMERA, "Camera Data", NODE_CLASS_INPUT, 0);
  node_type_socket_templates(&ntype, NULL, sh_node_camera_out);
  node_type_storage(&ntype, "", NULL, NULL);
  node_type_gpu(&ntype, gpu_shader_camera);

  nodeRegisterType(&ntype);
}
