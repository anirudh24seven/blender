/** \file
 * \ingroup DNA
 */

#pragma once

#include "DNA_ID.h"
#include "DNA_defs.h"

struct AnimData;
struct BPoint;
struct Ipo;
struct Key;
struct MDeformVert;

#
#
typedef struct EditLatt {
  struct Lattice *latt;

  int shapenr;

  /**
   * ID data is older than edit-mode data.
   * Set #Main.is_memfile_undo_flush_needed when enabling.
   */
  char needs_flush_to_id;
} EditLatt;

typedef struct Lattice {
  ID id;
  struct AnimData *adt;

  short pntsu, pntsv, pntsw, flag;
  short opntsu, opntsv, opntsw;
  char _pad2[3];
  char typeu, typev, typew;
  /** Active element index, unset with LT_ACTBP_NONE. */
  int actbp;

  float fu, fv, fw, du, dv, dw;

  struct BPoint *def;

  /** Old animation system, deprecated for 2.5. */
  struct Ipo *ipo DNA_DEPRECATED;
  struct Key *key;

  struct MDeformVert *dvert;
  /** Multiply the influence, MAX_VGROUP_NAME. */
  char vgroup[64];

  struct EditLatt *editlatt;
  void *batch_cache;
} Lattice;

/* ***************** LATTICE ********************* */

/* flag */
#define LT_GRID 1
#define LT_OUTSIDE 2

#define LT_DS_EXPAND 4

#define LT_ACTBP_NONE -1
