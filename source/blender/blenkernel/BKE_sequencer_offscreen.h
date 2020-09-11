/** The Original Code is Copyright (C) 2004 Blender Foundation.
 * All rights reserved.
 */

#pragma once

/** \file
 * \ingroup bke
 */

#include "DNA_object_enums.h"

#include "DNA_view3d_types.h"

#include "IMB_imbuf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ImBuf *(*SequencerDrawView)(struct Depsgraph *depsgraph,
                                           struct Scene *scene,
                                           struct View3DShading *shading_override,
                                           eDrawType drawtype,
                                           struct Object *camera,
                                           int width,
                                           int height,
                                           eImBufFlags flag,
                                           eV3DOffscreenDrawFlag draw_flags,
                                           int alpha_mode,
                                           const char *viewname,
                                           struct GPUOffScreen *ofs,
                                           char err_out[256]);
extern SequencerDrawView sequencer_view3d_fn;

#ifdef __cplusplus
}
#endif
