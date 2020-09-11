/** \file
 * \ingroup edinterface
 *
 * Share between interface_region_*.c files.
 */

#pragma once

/* interface_region_menu_popup.c */
uint ui_popup_menu_hash(const char *str);

/* interface_regions_intern.h */
ARegion *ui_region_temp_add(bScreen *screen);
void ui_region_temp_remove(struct bContext *C, bScreen *screen, ARegion *region);
