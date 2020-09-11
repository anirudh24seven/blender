/** \file
 * \ingroup shdnodes
 */

#include "node_shader_util.h"

/* **************** Script ******************** */

static void init(bNodeTree *UNUSED(ntree), bNode *node)
{
  NodeShaderScript *nss = MEM_callocN(sizeof(NodeShaderScript), "shader script node");
  node->storage = nss;
}

static void node_free_script(bNode *node)
{
  NodeShaderScript *nss = node->storage;

  if (nss) {
    if (nss->bytecode) {
      MEM_freeN(nss->bytecode);
    }

    MEM_freeN(nss);
  }
}

static void node_copy_script(bNodeTree *UNUSED(dest_ntree),
                             bNode *dest_node,
                             const bNode *src_node)
{
  NodeShaderScript *src_nss = src_node->storage;
  NodeShaderScript *dest_nss = MEM_dupallocN(src_nss);

  if (src_nss->bytecode) {
    dest_nss->bytecode = MEM_dupallocN(src_nss->bytecode);
  }

  dest_node->storage = dest_nss;
}

void register_node_type_sh_script(void)
{
  static bNodeType ntype;

  sh_node_type_base(&ntype, SH_NODE_SCRIPT, "Script", NODE_CLASS_SCRIPT, 0);
  node_type_init(&ntype, init);
  node_type_storage(&ntype, "NodeShaderScript", node_free_script, node_copy_script);

  nodeRegisterType(&ntype);
}
