#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Object;
struct Scene;

void BKE_mball_polygonize(struct Depsgraph *depsgraph,
                          struct Scene *scene,
                          struct Object *ob,
                          struct ListBase *dispbase);

void BKE_mball_cubeTable_free(void);

#ifdef __cplusplus
}
#endif
