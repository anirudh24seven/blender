/** \file
 * \ingroup nodes
 */

#pragma once

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct bNodeTree;

void node_group_label(struct bNodeTree *ntree, struct bNode *node, char *label, int maxlen);
bool node_group_poll_instance(struct bNode *node, struct bNodeTree *nodetree);

void ntree_update_reroute_nodes(struct bNodeTree *ntree);

#ifdef __cplusplus
}
#endif
