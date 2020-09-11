/** The Original Code is Copyright (C) 2006 by Blender Foundation
 * All rights reserved.
 */
/** \file
 * \ingroup render
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* this include is for texture exports                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* localized texture result data */
/* note; tr tg tb ta has to remain in this order */
typedef struct TexResult {
  float tin, tr, tg, tb, ta;
  int talpha;
  float *nor;
} TexResult;

typedef struct BakeImBufuserData {
  float *displacement_buffer;
  char *mask_buffer;
} BakeImBufuserData;

/* node shaders... */
struct ImagePool;
struct MTex;
struct Tex;

/* this one uses nodes */
int multitex_ext(struct Tex *tex,
                 float texvec[3],
                 float dxt[3],
                 float dyt[3],
                 int osatex,
                 struct TexResult *texres,
                 const short thread,
                 struct ImagePool *pool,
                 bool scene_color_manage,
                 const bool skip_load_image);
/* nodes disabled */
int multitex_ext_safe(struct Tex *tex,
                      float texvec[3],
                      struct TexResult *texres,
                      struct ImagePool *pool,
                      bool scene_color_manage,
                      const bool skip_load_image);
/* only for internal node usage */
int multitex_nodes(struct Tex *tex,
                   float texvec[3],
                   float dxt[3],
                   float dyt[3],
                   int osatex,
                   struct TexResult *texres,
                   const short thread,
                   short which_output,
                   struct MTex *mtex,
                   struct ImagePool *pool);

#ifdef __cplusplus
}
#endif
