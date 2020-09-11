/** \file
 * \ingroup edlattice
 */

#include "DNA_scene_types.h"

#include "RNA_access.h"

#include "WM_api.h"
#include "WM_types.h"

#include "ED_lattice.h"
#include "ED_object.h"
#include "ED_screen.h"
#include "ED_select_utils.h"

#include "lattice_intern.h"

void ED_operatortypes_lattice(void)
{
  WM_operatortype_append(LATTICE_OT_select_all);
  WM_operatortype_append(LATTICE_OT_select_more);
  WM_operatortype_append(LATTICE_OT_select_less);
  WM_operatortype_append(LATTICE_OT_select_ungrouped);
  WM_operatortype_append(LATTICE_OT_select_random);
  WM_operatortype_append(LATTICE_OT_select_mirror);
  WM_operatortype_append(LATTICE_OT_make_regular);
  WM_operatortype_append(LATTICE_OT_flip);
}

void ED_keymap_lattice(wmKeyConfig *keyconf)
{
  wmKeyMap *keymap = WM_keymap_ensure(keyconf, "Lattice", 0, 0);
  keymap->poll = ED_operator_editlattice;
}
