/** \file
 * \ingroup nodes
 */

#pragma once

#include "DNA_ID.h"
#include "DNA_movieclip_types.h"
#include "DNA_node_types.h"

#include "BLI_blenlib.h"
#include "BLI_math.h"

#include "BLT_translation.h"

#include "BKE_colorband.h"
#include "BKE_colortools.h"
#include "BKE_image.h"
#include "BKE_texture.h"
#include "BKE_tracking.h"

#include "node_util.h"

#include "IMB_imbuf.h"
#include "IMB_imbuf_types.h"

#include "RE_pipeline.h"

/* only for forward declarations */
#include "NOD_composite.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CMP_SCALE_MAX 12000

bool cmp_node_poll_default(struct bNodeType *ntype, struct bNodeTree *ntree);
void cmp_node_update_default(struct bNodeTree *UNUSED(ntree), struct bNode *node);
void cmp_node_type_base(
    struct bNodeType *ntype, int type, const char *name, short nclass, short flag);

#ifdef __cplusplus
}
#endif
