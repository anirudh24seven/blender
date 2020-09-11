/** \file
 * \ingroup shdnodes
 */

#include "node_shader_util.h"

/* **************** SEPARATE RGBA ******************** */
static bNodeSocketTemplate sh_node_seprgb_in[] = {
    {SOCK_RGBA, N_("Image"), 0.8f, 0.8f, 0.8f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate sh_node_seprgb_out[] = {
    {SOCK_FLOAT, N_("R")},
    {SOCK_FLOAT, N_("G")},
    {SOCK_FLOAT, N_("B")},
    {-1, ""},
};

static void node_shader_exec_seprgb(void *UNUSED(data),
                                    int UNUSED(thread),
                                    bNode *UNUSED(node),
                                    bNodeExecData *UNUSED(execdata),
                                    bNodeStack **in,
                                    bNodeStack **out)
{
  float col[3];
  nodestack_get_vec(col, SOCK_VECTOR, in[0]);

  out[0]->vec[0] = col[0];
  out[1]->vec[0] = col[1];
  out[2]->vec[0] = col[2];
}

static int gpu_shader_seprgb(GPUMaterial *mat,
                             bNode *node,
                             bNodeExecData *UNUSED(execdata),
                             GPUNodeStack *in,
                             GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "separate_rgb", in, out);
}

class SeparateRGBFunction : public blender::fn::MultiFunction {
 public:
  SeparateRGBFunction()
  {
    blender::fn::MFSignatureBuilder signature = this->get_builder("Separate RGB");
    signature.single_input<blender::Color4f>("Color");
    signature.single_output<float>("R");
    signature.single_output<float>("G");
    signature.single_output<float>("B");
  }

  void call(blender::IndexMask mask,
            blender::fn::MFParams params,
            blender::fn::MFContext UNUSED(context)) const override
  {
    blender::fn::VSpan<blender::Color4f> colors = params.readonly_single_input<blender::Color4f>(
        0, "Color");
    blender::MutableSpan<float> rs = params.uninitialized_single_output<float>(1, "R");
    blender::MutableSpan<float> gs = params.uninitialized_single_output<float>(2, "G");
    blender::MutableSpan<float> bs = params.uninitialized_single_output<float>(3, "B");

    for (int64_t i : mask) {
      blender::Color4f color = colors[i];
      rs[i] = color.r;
      gs[i] = color.g;
      bs[i] = color.b;
    }
  }
};

static void sh_node_seprgb_expand_in_mf_network(blender::nodes::NodeMFNetworkBuilder &builder)
{
  static SeparateRGBFunction fn;
  builder.set_matching_fn(fn);
}

void register_node_type_sh_seprgb(void)
{
  static bNodeType ntype;

  sh_fn_node_type_base(&ntype, SH_NODE_SEPRGB, "Separate RGB", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, sh_node_seprgb_in, sh_node_seprgb_out);
  node_type_exec(&ntype, NULL, NULL, node_shader_exec_seprgb);
  node_type_gpu(&ntype, gpu_shader_seprgb);
  ntype.expand_in_mf_network = sh_node_seprgb_expand_in_mf_network;

  nodeRegisterType(&ntype);
}

/* **************** COMBINE RGB ******************** */
static bNodeSocketTemplate sh_node_combrgb_in[] = {
    {SOCK_FLOAT, N_("R"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_UNSIGNED},
    {SOCK_FLOAT, N_("G"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_UNSIGNED},
    {SOCK_FLOAT, N_("B"), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, PROP_UNSIGNED},
    {-1, ""},
};
static bNodeSocketTemplate sh_node_combrgb_out[] = {
    {SOCK_RGBA, N_("Image")},
    {-1, ""},
};

static void node_shader_exec_combrgb(void *UNUSED(data),
                                     int UNUSED(thread),
                                     bNode *UNUSED(node),
                                     bNodeExecData *UNUSED(execdata),
                                     bNodeStack **in,
                                     bNodeStack **out)
{
  float r, g, b;
  nodestack_get_vec(&r, SOCK_FLOAT, in[0]);
  nodestack_get_vec(&g, SOCK_FLOAT, in[1]);
  nodestack_get_vec(&b, SOCK_FLOAT, in[2]);

  out[0]->vec[0] = r;
  out[0]->vec[1] = g;
  out[0]->vec[2] = b;
}

static int gpu_shader_combrgb(GPUMaterial *mat,
                              bNode *node,
                              bNodeExecData *UNUSED(execdata),
                              GPUNodeStack *in,
                              GPUNodeStack *out)
{
  return GPU_stack_link(mat, node, "combine_rgb", in, out);
}

static void sh_node_combrgb_expand_in_mf_network(blender::nodes::NodeMFNetworkBuilder &builder)
{
  static blender::fn::CustomMF_SI_SI_SI_SO<float, float, float, blender::Color4f> fn{
      "Combine RGB", [](float r, float g, float b) { return blender::Color4f(r, g, b, 1.0f); }};
  builder.set_matching_fn(fn);
}

void register_node_type_sh_combrgb(void)
{
  static bNodeType ntype;

  sh_fn_node_type_base(&ntype, SH_NODE_COMBRGB, "Combine RGB", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(&ntype, sh_node_combrgb_in, sh_node_combrgb_out);
  node_type_exec(&ntype, NULL, NULL, node_shader_exec_combrgb);
  node_type_gpu(&ntype, gpu_shader_combrgb);
  ntype.expand_in_mf_network = sh_node_combrgb_expand_in_mf_network;

  nodeRegisterType(&ntype);
}
