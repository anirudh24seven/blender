/** \file
 * \ingroup nodes
 */

#include "node_composite_util.h"

bool cmp_node_poll_default(bNodeType *UNUSED(ntype), bNodeTree *ntree)
{
  return STREQ(ntree->idname, "CompositorNodeTree");
}

void cmp_node_update_default(bNodeTree *UNUSED(ntree), bNode *node)
{
  bNodeSocket *sock;
  for (sock = node->outputs.first; sock; sock = sock->next) {
    if (sock->cache) {
      // free_compbuf(sock->cache);
      // sock->cache = NULL;
    }
  }
  node->need_exec = 1;
}

void cmp_node_type_base(bNodeType *ntype, int type, const char *name, short nclass, short flag)
{
  node_type_base(ntype, type, name, nclass, flag);

  ntype->poll = cmp_node_poll_default;
  ntype->updatefunc = cmp_node_update_default;
  ntype->insert_link = node_insert_link_default;
  ntype->update_internal_links = node_update_internal_links_default;
}
