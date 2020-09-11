/** \file
 * \ingroup edgeometry
 */

#include "WM_api.h"

#include "ED_geometry.h"

#include "geometry_intern.h"

/**************************** registration **********************************/

void ED_operatortypes_geometry(void)
{
  WM_operatortype_append(GEOMETRY_OT_attribute_add);
  WM_operatortype_append(GEOMETRY_OT_attribute_remove);
}
