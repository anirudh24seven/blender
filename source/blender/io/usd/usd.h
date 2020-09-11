#pragma once

#include "DEG_depsgraph.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Scene;
struct bContext;

struct USDExportParams {
  bool export_animation;
  bool export_hair;
  bool export_uvmaps;
  bool export_normals;
  bool export_materials;
  bool selected_objects_only;
  bool visible_objects_only;
  bool use_instancing;
  enum eEvaluationMode evaluation_mode;
};

/* The USD_export takes a as_background_job parameter, and returns a boolean.
 *
 * When as_background_job=true, returns false immediately after scheduling
 * a background job.
 *
 * When as_background_job=false, performs the export synchronously, and returns
 * true when the export was ok, and false if there were any errors.
 */

bool USD_export(struct bContext *C,
                const char *filepath,
                const struct USDExportParams *params,
                bool as_background_job);

int USD_get_version(void);

#ifdef __cplusplus
}
#endif
