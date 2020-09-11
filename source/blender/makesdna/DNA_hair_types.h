/** \file
 * \ingroup DNA
 */

#pragma once

#include "DNA_ID.h"
#include "DNA_customdata_types.h"

typedef struct HairCurve {
  /* Index of first point of hair curve. */
  int firstpoint;
  /* Number of points in hair curve, must be 2 or higher. */
  int numpoints;
} HairCurve;

/* Hair attachment to a mesh.
 * TODO: attach to tessellated triangles or polygons?
 * TODO: what type of interpolation to use for uv? */
typedef struct HairMapping {
  float uv[2];
  int poly;
} HairMapping;

typedef struct Hair {
  ID id;
  struct AnimData *adt; /* animation data (must be immediately after id) */

  int flag;
  int _pad1[1];

  /* Geometry */
  float (*co)[3];
  float *radius;
  struct HairCurve *curves;
  struct HairMaping *mapping;
  int totpoint;
  int totcurve;

  /* Custom Data */
  struct CustomData pdata;
  struct CustomData cdata;
  int attributes_active_index;
  int _pad3;

  /* Material */
  struct Material **mat;
  short totcol;
  short _pad2[3];

  /* Draw Cache */
  void *batch_cache;
} Hair;

/* Hair.flag */
enum {
  HA_DS_EXPAND = (1 << 0),
};

/* Only one material supported currently. */
#define HAIR_MATERIAL_NR 1
