/** \file
 * \ingroup nodes
 */

#pragma once

#include "BKE_node.h"

#ifdef __cplusplus
extern "C" {
#endif

void register_node_type_frame(void);
void register_node_type_reroute(void);

void register_node_type_group_input(void);
void register_node_type_group_output(void);

/* internal functions for editor */
struct bNodeSocket *node_group_find_input_socket(struct bNode *groupnode, const char *identifier);
struct bNodeSocket *node_group_find_output_socket(struct bNode *groupnode, const char *identifier);
void node_group_update(struct bNodeTree *ntree, struct bNode *node);

struct bNodeSocket *node_group_input_find_socket(struct bNode *node, const char *identifier);
struct bNodeSocket *node_group_output_find_socket(struct bNode *node, const char *identifier);
void node_group_input_update(struct bNodeTree *ntree, struct bNode *node);
void node_group_output_update(struct bNodeTree *ntree, struct bNode *node);

#ifdef __cplusplus
}
#endif
