/** \file
 * \ingroup wm
 *
 * Panel Registry.
 *
 * \note Unlike menu, and other registries, this doesn't *own* the PanelType.
 *
 * For popups/popovers only, regions handle panel types by including them in local lists.
 */

#include <stdio.h>

#include "BLI_sys_types.h"

#include "DNA_windowmanager_types.h"

#include "BLI_ghash.h"
#include "BLI_utildefines.h"

#include "BKE_screen.h"

#include "WM_api.h"

static GHash *g_paneltypes_hash = NULL;

PanelType *WM_paneltype_find(const char *idname, bool quiet)
{
  PanelType *pt;

  if (idname[0]) {
    pt = BLI_ghash_lookup(g_paneltypes_hash, idname);
    if (pt) {
      return pt;
    }
  }

  if (!quiet) {
    printf("search for unknown paneltype %s\n", idname);
  }

  return NULL;
}

bool WM_paneltype_add(PanelType *pt)
{
  BLI_ghash_insert(g_paneltypes_hash, pt->idname, pt);
  return true;
}

void WM_paneltype_remove(PanelType *pt)
{
  bool ok;

  ok = BLI_ghash_remove(g_paneltypes_hash, pt->idname, NULL, NULL);

  BLI_assert(ok);
  (void)ok;
}

/* called on initialize WM_init() */
void WM_paneltype_init(void)
{
  /* reserve size is set based on blender default setup */
  g_paneltypes_hash = BLI_ghash_str_new_ex("g_paneltypes_hash gh", 512);
}

void WM_paneltype_clear(void)
{
  BLI_ghash_free(g_paneltypes_hash, NULL, NULL);
}
