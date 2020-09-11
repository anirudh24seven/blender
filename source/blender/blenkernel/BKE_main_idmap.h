#pragma once

/** \file
 * \ingroup bke
 *
 * API to generate and use a mapping from [ID type & name] to [id pointer], within a given Main
 * data-base.
 *
 * \note `BKE_main` files are for operations over the Main database itself, or generating extra
 * temp data to help working with it. Those should typically not affect the data-blocks themselves.
 *
 * \section Function Names
 *
 * - `BKE_main_idmap_` Should be used for functions in that file.
 */

#include "BLI_compiler_attrs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct IDNameLib_Map;
struct Main;

enum {
  MAIN_IDMAP_TYPE_NAME = 1 << 0,
  MAIN_IDMAP_TYPE_UUID = 1 << 1,
};

struct IDNameLib_Map *BKE_main_idmap_create(struct Main *bmain,
                                            const bool create_valid_ids_set,
                                            struct Main *old_bmain,
                                            const int idmap_types) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);
void BKE_main_idmap_destroy(struct IDNameLib_Map *id_map) ATTR_NONNULL();
struct Main *BKE_main_idmap_main_get(struct IDNameLib_Map *id_map) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();
struct ID *BKE_main_idmap_lookup_name(struct IDNameLib_Map *id_map,
                                      short id_type,
                                      const char *name,
                                      const struct Library *lib) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1, 3);
struct ID *BKE_main_idmap_lookup_id(struct IDNameLib_Map *id_map,
                                    const struct ID *id) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1, 2);

struct ID *BKE_main_idmap_lookup_uuid(struct IDNameLib_Map *id_map,
                                      const uint session_uuid) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL(1);

#ifdef __cplusplus
}
#endif
