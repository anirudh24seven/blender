/** \file
 * \ingroup collada
 */

#include "io_ops.h" /* own include */

#include "WM_api.h"

#ifdef WITH_COLLADA
#  include "io_collada.h"
#endif

#ifdef WITH_ALEMBIC
#  include "io_alembic.h"
#endif

#ifdef WITH_USD
#  include "io_usd.h"
#endif

#include "io_cache.h"

void ED_operatortypes_io(void)
{
#ifdef WITH_COLLADA
  /* Collada operators: */
  WM_operatortype_append(WM_OT_collada_export);
  WM_operatortype_append(WM_OT_collada_import);
#endif
#ifdef WITH_ALEMBIC
  WM_operatortype_append(WM_OT_alembic_import);
  WM_operatortype_append(WM_OT_alembic_export);
#endif
#ifdef WITH_USD
  WM_operatortype_append(WM_OT_usd_export);
#endif

  WM_operatortype_append(CACHEFILE_OT_open);
  WM_operatortype_append(CACHEFILE_OT_reload);
}
