#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Main;
struct Object;
struct Scene;

void BKE_gpencil_convert_curve(struct Main *bmain,
                               struct Scene *scene,
                               struct Object *ob_gp,
                               struct Object *ob_cu,
                               const bool use_collections,
                               const float scale_thickness,
                               const float sample);

#ifdef __cplusplus
}
#endif
