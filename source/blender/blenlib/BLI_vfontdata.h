#pragma once

/** \file
 * \ingroup bli
 * \brief A structure to represent vector fonts,
 *   and to load them from PostScript fonts.
 */

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PackedFile;
struct VFont;

typedef struct VFontData {
  struct GHash *characters;
  char name[128];
  float scale;
  /* Calculated from the font. */
  float em_height;
  float ascender;
} VFontData;

typedef struct VChar {
  ListBase nurbsbase;
  unsigned int index;
  float width;
} VChar;

VFontData *BLI_vfontdata_from_freetypefont(struct PackedFile *pf);
VFontData *BLI_vfontdata_copy(const VFontData *vfont_src, const int flag);

VChar *BLI_vfontchar_from_freetypefont(struct VFont *vfont, unsigned long character);
VChar *BLI_vfontchar_copy(const VChar *vchar_src, const int flag);

#ifdef __cplusplus
}
#endif
