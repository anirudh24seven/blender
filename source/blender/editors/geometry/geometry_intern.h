/** \file
 * \ingroup edgeometry
 */

#ifndef __GEOMETRY_INTERN_H__
#define __GEOMETRY_INTERN_H__

struct wmOperatorType;

/* *** geometry_attributes.c *** */
void GEOMETRY_OT_attribute_add(struct wmOperatorType *ot);
void GEOMETRY_OT_attribute_remove(struct wmOperatorType *ot);

#endif /* __GEOMETRY_INTERN_H__ */
