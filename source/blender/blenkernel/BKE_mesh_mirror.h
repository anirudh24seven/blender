#pragma once

/** \file
 * \ingroup bke
 */

#include "BLI_utildefines.h"

#ifdef __cplusplus
extern "C" {
#endif

struct MirrorModifierData;
struct ModifierEvalContext;
struct Object;

struct Mesh *BKE_mesh_mirror_bisect_on_mirror_plane(struct MirrorModifierData *mmd,
                                                    const struct Mesh *mesh,
                                                    int axis,
                                                    const float plane_co[3],
                                                    float plane_no[3]);

struct Mesh *BKE_mesh_mirror_apply_mirror_on_axis(struct MirrorModifierData *mmd,
                                                  const struct ModifierEvalContext *UNUSED(ctx),
                                                  struct Object *ob,
                                                  const struct Mesh *mesh,
                                                  int axis);

#ifdef __cplusplus
}
#endif
