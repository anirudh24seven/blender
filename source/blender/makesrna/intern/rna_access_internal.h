/** \file
 * \ingroup RNA
 */

#pragma once

#include "BLI_utildefines.h"

#include "rna_internal_types.h"

struct IDProperty;
struct PropertyRNAOrID;

void rna_property_rna_or_id_get(PropertyRNA *prop,
                                PointerRNA *ptr,
                                PropertyRNAOrID *r_prop_rna_or_id);

void rna_idproperty_touch(struct IDProperty *idprop);
struct IDProperty *rna_idproperty_find(PointerRNA *ptr, const char *name);
