/** \file
 * \ingroup edinterface
 *
 * General Interface Region Code
 *
 * \note Most logic is now in 'interface_region_*.c'
 */

#include "BLI_listbase.h"
#include "BLI_utildefines.h"
#include "MEM_guardedalloc.h"

#include "BKE_context.h"
#include "BKE_screen.h"

#include "WM_api.h"
#include "wm_draw.h"

#include "ED_screen.h"

#include "interface_regions_intern.h"

ARegion *ui_region_temp_add(bScreen *screen)
{
  ARegion *region;

  region = MEM_callocN(sizeof(ARegion), "area region");
  BLI_addtail(&screen->regionbase, region);

  region->regiontype = RGN_TYPE_TEMPORARY;
  region->alignment = RGN_ALIGN_FLOAT;

  return region;
}

void ui_region_temp_remove(bContext *C, bScreen *screen, ARegion *region)
{
  wmWindow *win = CTX_wm_window(C);

  BLI_assert(region->regiontype == RGN_TYPE_TEMPORARY);
  BLI_assert(BLI_findindex(&screen->regionbase, region) != -1);
  if (win) {
    wm_draw_region_clear(win, region);
  }

  ED_region_exit(C, region);
  BKE_area_region_free(NULL, region); /* NULL: no spacetype */
  BLI_freelinkN(&screen->regionbase, region);
}
