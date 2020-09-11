/** \file
 * \ingroup spfile
 */

#include "BLI_listbase.h"
#include "BLI_rect.h"

#include "BLO_readfile.h"

#include "BKE_context.h"

#include "ED_fileselect.h"
#include "ED_screen.h"

#include "WM_types.h"

#include "file_intern.h"

void file_tile_boundbox(const ARegion *region, FileLayout *layout, const int file, rcti *r_bounds)
{
  int xmin, ymax;

  ED_fileselect_layout_tilepos(layout, file, &xmin, &ymax);
  ymax = (int)region->v2d.tot.ymax - ymax; /* real, view space ymax */
  BLI_rcti_init(r_bounds,
                xmin,
                xmin + layout->tile_w + layout->tile_border_x,
                ymax - layout->tile_h - layout->tile_border_y,
                ymax);
}
