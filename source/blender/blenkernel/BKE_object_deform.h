#pragma once

/** \file
 * \ingroup bke
 * \brief Functions for dealing with objects and deform verts,
 *        used by painting and tools.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct MDeformVert;
struct Object;
struct bDeformGroup;

/* General vgroup operations */
void BKE_object_defgroup_remap_update_users(struct Object *ob, const int *map);

bool BKE_object_defgroup_array_get(struct ID *id, struct MDeformVert **dvert_arr, int *dvert_tot);

struct bDeformGroup *BKE_object_defgroup_add(struct Object *ob);
struct bDeformGroup *BKE_object_defgroup_add_name(struct Object *ob, const char *name);
struct MDeformVert *BKE_object_defgroup_data_create(struct ID *id);

bool BKE_object_defgroup_clear(struct Object *ob,
                               struct bDeformGroup *dg,
                               const bool use_selection);
bool BKE_object_defgroup_clear_all(struct Object *ob, const bool use_selection);

void BKE_object_defgroup_remove(struct Object *ob, struct bDeformGroup *defgroup);
void BKE_object_defgroup_remove_all_ex(struct Object *ob, bool only_unlocked);
void BKE_object_defgroup_remove_all(struct Object *ob);

int *BKE_object_defgroup_index_map_create(struct Object *ob_src,
                                          struct Object *ob_dst,
                                          int *r_map_len);
void BKE_object_defgroup_index_map_apply(struct MDeformVert *dvert,
                                         int dvert_len,
                                         const int *map,
                                         int map_len);

/* Select helpers */
enum eVGroupSelect;
bool *BKE_object_defgroup_subset_from_select_type(struct Object *ob,
                                                  enum eVGroupSelect subset_type,
                                                  int *r_defgroup_tot,
                                                  int *r_subset_count);
void BKE_object_defgroup_subset_to_index_array(const bool *defgroup_validmap,
                                               const int defgroup_tot,
                                               int *r_defgroup_subset_map);

/* ********** */

bool *BKE_object_defgroup_lock_flags_get(struct Object *ob, const int defbase_tot);
bool *BKE_object_defgroup_validmap_get(struct Object *ob, const int defbase_tot);
bool *BKE_object_defgroup_selected_get(struct Object *ob,
                                       int defbase_tot,
                                       int *r_dg_flags_sel_tot);

bool BKE_object_defgroup_check_lock_relative(const bool *lock_flags,
                                             const bool *validmap,
                                             int index);
bool BKE_object_defgroup_check_lock_relative_multi(int defbase_tot,
                                                   const bool *lock_flags,
                                                   const bool *selected,
                                                   int sel_tot);
void BKE_object_defgroup_split_locked_validmap(
    int defbase_tot, const bool *locked, const bool *deform, bool *r_locked, bool *r_unlocked);

void BKE_object_defgroup_mirror_selection(struct Object *ob,
                                          int defbase_tot,
                                          const bool *selection,
                                          bool *dg_flags_sel,
                                          int *r_dg_flags_sel_tot);

#ifdef __cplusplus
}
#endif
