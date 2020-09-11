#pragma once

/** \file
 * \ingroup bke
 */

#include "DNA_scene_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct FreestyleConfig;
struct FreestyleLineSet;
struct FreestyleModuleConfig;
struct Main;

/* RNA aliases */
typedef struct FreestyleModuleSettings FreestyleModuleSettings;
typedef struct FreestyleSettings FreestyleSettings;

/* FreestyleConfig */
void BKE_freestyle_config_init(FreestyleConfig *config);
void BKE_freestyle_config_free(FreestyleConfig *config, const bool do_id_user);
void BKE_freestyle_config_copy(FreestyleConfig *new_config,
                               const FreestyleConfig *config,
                               const int flag);

/* FreestyleConfig.modules */
FreestyleModuleConfig *BKE_freestyle_module_add(FreestyleConfig *config);
bool BKE_freestyle_module_delete(FreestyleConfig *config, FreestyleModuleConfig *module_conf);
bool BKE_freestyle_module_move(FreestyleConfig *config,
                               FreestyleModuleConfig *module_conf,
                               int direction);

/* FreestyleConfig.linesets */
FreestyleLineSet *BKE_freestyle_lineset_add(struct Main *bmain,
                                            FreestyleConfig *config,
                                            const char *name);
bool BKE_freestyle_lineset_delete(FreestyleConfig *config, FreestyleLineSet *lineset);
FreestyleLineSet *BKE_freestyle_lineset_get_active(FreestyleConfig *config);
short BKE_freestyle_lineset_get_active_index(FreestyleConfig *config);
void BKE_freestyle_lineset_set_active_index(FreestyleConfig *config, short index);
void BKE_freestyle_lineset_unique_name(FreestyleConfig *config, FreestyleLineSet *lineset);

#ifdef __cplusplus
}
#endif
