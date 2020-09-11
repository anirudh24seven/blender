#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct ReportList;
struct Scene;
struct bAnimVizSettings;
struct bMotionPath;
struct bPoseChannel;

/* ---------------------------------------------------- */
/* Animation Visualization */

void animviz_settings_init(struct bAnimVizSettings *avs);

struct bMotionPath *animviz_copy_motionpath(const struct bMotionPath *mpath_src);

void animviz_free_motionpath_cache(struct bMotionPath *mpath);
void animviz_free_motionpath(struct bMotionPath *mpath);

struct bMotionPath *animviz_verify_motionpaths(struct ReportList *reports,
                                               struct Scene *scene,
                                               struct Object *ob,
                                               struct bPoseChannel *pchan);

#ifdef __cplusplus
}
#endif
