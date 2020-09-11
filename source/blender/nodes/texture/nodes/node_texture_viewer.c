/** \file
 * \ingroup texnodes
 */

#include "NOD_texture.h"
#include "node_texture_util.h"
#include <math.h>

static bNodeSocketTemplate inputs[] = {
    {SOCK_RGBA, N_("Color"), 1.0f, 0.0f, 0.0f, 1.0f},
    {-1, ""},
};
static bNodeSocketTemplate outputs[] = {
    {-1, ""},
};

static void exec(void *data,
                 int UNUSED(thread),
                 bNode *UNUSED(node),
                 bNodeExecData *execdata,
                 bNodeStack **in,
                 bNodeStack **UNUSED(out))
{
  TexCallData *cdata = (TexCallData *)data;

  if (cdata->do_preview) {
    TexParams params;
    float col[4];
    params_from_cdata(&params, cdata);

    tex_input_rgba(col, in[0], &params, cdata->thread);
    tex_do_preview(execdata->preview, params.previewco, col, cdata->do_manage);
  }
}

void register_node_type_tex_viewer(void)
{
  static bNodeType ntype;

  tex_node_type_base(&ntype, TEX_NODE_VIEWER, "Viewer", NODE_CLASS_OUTPUT, NODE_PREVIEW);
  node_type_socket_templates(&ntype, inputs, outputs);
  node_type_exec(&ntype, NULL, NULL, exec);

  /* Do not allow muting viewer node. */
  node_type_internal_links(&ntype, NULL);

  nodeRegisterType(&ntype);
}
