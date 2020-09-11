/** \file
 * \ingroup eevee
 */

#pragma once

#include "BLI_sys_types.h" /* for bool */

struct EEVEE_Data;
struct EEVEE_ViewLayerData;
struct LightCache;
struct Scene;
struct SceneEEVEE;
struct ViewLayer;

/* Light Bake */
struct wmJob *EEVEE_lightbake_job_create(struct wmWindowManager *wm,
                                         struct wmWindow *win,
                                         struct Main *bmain,
                                         struct ViewLayer *view_layer,
                                         struct Scene *scene,
                                         int delay,
                                         int frame);
void *EEVEE_lightbake_job_data_alloc(struct Main *bmain,
                                     struct ViewLayer *view_layer,
                                     struct Scene *scene,
                                     bool run_as_job,
                                     int frame);
void EEVEE_lightbake_job_data_free(void *custom_data);
void EEVEE_lightbake_update(void *custom_data);
void EEVEE_lightbake_job(void *custom_data, short *stop, short *do_update, float *progress);

void EEVEE_lightbake_update_world_quick(struct EEVEE_ViewLayerData *sldata,
                                        struct EEVEE_Data *vedata,
                                        const Scene *scene);

/* Light Cache */
struct LightCache *EEVEE_lightcache_create(const int grid_len,
                                           const int cube_len,
                                           const int cube_size,
                                           const int vis_size,
                                           const int irr_size[3]);
void EEVEE_lightcache_free(struct LightCache *lcache);
bool EEVEE_lightcache_load(struct LightCache *lcache);
void EEVEE_lightcache_info_update(struct SceneEEVEE *eevee);
