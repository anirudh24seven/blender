#pragma once

/** \file
 * \ingroup bke
 *
 * API to manage data-blocks inside of Blender's Main data-base, or as independent runtime-only
 * data.
 *
 * \note `BKE_lib_` files are for operations over data-blocks themselves, although they might
 * alter Main as well (when creating/renaming/deleting an ID e.g.).
 *
 * \section Function Names
 *
 * \warning Descriptions below is ideal goal, current status of naming does not yet fully follow it
 * (this is WIP).
 *
 *  - `BKE_lib_override_library_` should be used for function affecting a single ID.
 *  - `BKE_lib_override_library_main_` should be used for function affecting the whole collection
 *    of IDs in a given Main data-base.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct IDOverrideLibrary;
struct IDOverrideLibraryProperty;
struct IDOverrideLibraryPropertyOperation;
struct Main;
struct PointerRNA;
struct PropertyRNA;
struct Scene;
struct ViewLayer;

struct IDOverrideLibrary *BKE_lib_override_library_init(struct ID *local_id,
                                                        struct ID *reference_id);
void BKE_lib_override_library_copy(struct ID *dst_id,
                                   const struct ID *src_id,
                                   const bool do_full_copy);
void BKE_lib_override_library_clear(struct IDOverrideLibrary *override, const bool do_id_user);
void BKE_lib_override_library_free(struct IDOverrideLibrary **override, const bool do_id_user);

struct ID *BKE_lib_override_library_create_from_id(struct Main *bmain,
                                                   struct ID *reference_id,
                                                   const bool do_tagged_remap);
bool BKE_lib_override_library_create_from_tag(struct Main *bmain);
void BKE_lib_override_library_dependencies_tag(struct Main *bmain,
                                               struct ID *id_root,
                                               const uint tag,
                                               const bool do_create_main_relashionships);
void BKE_lib_override_library_override_group_tag(struct Main *bmain,
                                                 struct ID *id_root,
                                                 const uint tag,
                                                 const bool do_create_main_relashionships);
bool BKE_lib_override_library_create(struct Main *bmain,
                                     struct Scene *scene,
                                     struct ViewLayer *view_layer,
                                     struct ID *id_root,
                                     struct ID *id_reference);
bool BKE_lib_override_library_resync(struct Main *bmain,
                                     struct Scene *scene,
                                     struct ViewLayer *view_layer,
                                     struct ID *id_root);
void BKE_lib_override_library_delete(struct Main *bmain, struct ID *id_root);

struct IDOverrideLibraryProperty *BKE_lib_override_library_property_find(
    struct IDOverrideLibrary *override, const char *rna_path);
struct IDOverrideLibraryProperty *BKE_lib_override_library_property_get(
    struct IDOverrideLibrary *override, const char *rna_path, bool *r_created);
void BKE_lib_override_library_property_delete(struct IDOverrideLibrary *override,
                                              struct IDOverrideLibraryProperty *override_property);

struct IDOverrideLibraryPropertyOperation *BKE_lib_override_library_property_operation_find(
    struct IDOverrideLibraryProperty *override_property,
    const char *subitem_refname,
    const char *subitem_locname,
    const int subitem_refindex,
    const int subitem_locindex,
    const bool strict,
    bool *r_strict);
struct IDOverrideLibraryPropertyOperation *BKE_lib_override_library_property_operation_get(
    struct IDOverrideLibraryProperty *override_property,
    const short operation,
    const char *subitem_refname,
    const char *subitem_locname,
    const int subitem_refindex,
    const int subitem_locindex,
    const bool strict,
    bool *r_strict,
    bool *r_created);
void BKE_lib_override_library_property_operation_delete(
    struct IDOverrideLibraryProperty *override_property,
    struct IDOverrideLibraryPropertyOperation *override_property_operation);

bool BKE_lib_override_library_property_operation_operands_validate(
    struct IDOverrideLibraryPropertyOperation *override_property_operation,
    struct PointerRNA *ptr_dst,
    struct PointerRNA *ptr_src,
    struct PointerRNA *ptr_storage,
    struct PropertyRNA *prop_dst,
    struct PropertyRNA *prop_src,
    struct PropertyRNA *prop_storage);

bool BKE_lib_override_library_status_check_local(struct Main *bmain, struct ID *local);
bool BKE_lib_override_library_status_check_reference(struct Main *bmain, struct ID *local);

bool BKE_lib_override_library_operations_create(struct Main *bmain, struct ID *local);
void BKE_lib_override_library_main_operations_create(struct Main *bmain, const bool force_auto);

void BKE_lib_override_library_id_reset(struct Main *bmain, struct ID *id_root);
void BKE_lib_override_library_id_hierarchy_reset(struct Main *bmain, struct ID *id_root);

void BKE_lib_override_library_operations_tag(struct IDOverrideLibraryProperty *override_property,
                                             const short tag,
                                             const bool do_set);
void BKE_lib_override_library_properties_tag(struct IDOverrideLibrary *override,
                                             const short tag,
                                             const bool do_set);
void BKE_lib_override_library_main_tag(struct Main *bmain, const short tag, const bool do_set);

void BKE_lib_override_library_id_unused_cleanup(struct ID *local);
void BKE_lib_override_library_main_unused_cleanup(struct Main *bmain);

void BKE_lib_override_library_update(struct Main *bmain, struct ID *local);
void BKE_lib_override_library_main_update(struct Main *bmain);

/* Storage (.blend file writing) part. */

/* For now, we just use a temp main list. */
typedef struct Main OverrideLibraryStorage;

OverrideLibraryStorage *BKE_lib_override_library_operations_store_init(void);
struct ID *BKE_lib_override_library_operations_store_start(
    struct Main *bmain, OverrideLibraryStorage *override_storage, struct ID *local);
void BKE_lib_override_library_operations_store_end(OverrideLibraryStorage *override_storage,
                                                   struct ID *local);
void BKE_lib_override_library_operations_store_finalize(OverrideLibraryStorage *override_storage);

#ifdef __cplusplus
}
#endif
