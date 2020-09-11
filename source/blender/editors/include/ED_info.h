/** The Original Code is Copyright (C) 2009, Blender Foundation
 */

/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Main;

/* info_stats.c */
void ED_info_stats_clear(struct ViewLayer *view_layer);
const char *ED_info_statusbar_string(struct Main *bmain,
                                     struct Scene *scene,
                                     struct ViewLayer *view_layer);

const char *ED_info_statistics_string(struct Main *bmain,
                                      struct Scene *scene,
                                      struct ViewLayer *view_layer);

void ED_info_draw_stats(
    struct Main *bmain, Scene *scene, ViewLayer *view_layer, int x, int *y, int height);

#ifdef __cplusplus
}
#endif
