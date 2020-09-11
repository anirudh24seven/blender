#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Main;
struct World;

struct World *BKE_world_add(struct Main *bmain, const char *name);
struct World *BKE_world_copy(struct Main *bmain, const struct World *wrld);
struct World *BKE_world_localize(struct World *wrld);
void BKE_world_eval(struct Depsgraph *depsgraph, struct World *world);

#ifdef __cplusplus
}
#endif
