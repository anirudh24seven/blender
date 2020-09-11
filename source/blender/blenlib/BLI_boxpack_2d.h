#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ListBase;

/* Box Packer */

typedef struct BoxPack {
  float x;
  float y;
  float w;
  float h;

  /* Verts this box uses
   * (BL,TR,TL,BR) / 0,1,2,3 */
  struct BoxVert *v[4];

  int index;
} BoxPack;

void BLI_box_pack_2d(BoxPack *boxarray, const unsigned int len, float *r_tot_x, float *r_tot_y);

typedef struct FixedSizeBoxPack {
  struct FixedSizeBoxPack *next, *prev;
  int x, y;
  int w, h;
} FixedSizeBoxPack;

void BLI_box_pack_2d_fixedarea(struct ListBase *boxes,
                               int width,
                               int height,
                               struct ListBase *packed);

#ifdef __cplusplus
}
#endif
