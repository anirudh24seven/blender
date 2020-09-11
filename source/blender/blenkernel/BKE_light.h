#pragma once

/** \file
 * \ingroup bke
 * \brief General operations, lookup, etc. for blender lights.
 */

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Light;
struct Main;

struct Light *BKE_light_add(struct Main *bmain, const char *name) ATTR_WARN_UNUSED_RESULT;
struct Light *BKE_light_copy(struct Main *bmain, const struct Light *la) ATTR_WARN_UNUSED_RESULT;
struct Light *BKE_light_localize(struct Light *la) ATTR_WARN_UNUSED_RESULT;

void BKE_light_eval(struct Depsgraph *depsgraph, struct Light *la);

#ifdef __cplusplus
}
#endif
