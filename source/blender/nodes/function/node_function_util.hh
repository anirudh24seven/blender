#pragma once

#include <string.h>

#include "BLI_float3.hh"
#include "BLI_utildefines.h"

#include "MEM_guardedalloc.h"

#include "DNA_node_types.h"

#include "BKE_node.h"

#include "BLT_translation.h"

#include "NOD_function.h"
#include "NOD_node_tree_multi_function.hh"

#include "node_util.h"

#include "FN_multi_function_builder.hh"

void fn_node_type_base(
    struct bNodeType *ntype, int type, const char *name, short nclass, short flag);
bool fn_node_poll_default(struct bNodeType *ntype, struct bNodeTree *ntree);
