#pragma once

/** \file
 * \ingroup bke
 * \brief General operations for hairs.
 */
#ifdef __cplusplus
extern "C" {
#endif

struct BoundBox;
struct CustomDataLayer;
struct Depsgraph;
struct Hair;
struct Main;
struct Object;
struct Scene;

void *BKE_hair_add(struct Main *bmain, const char *name);
struct Hair *BKE_hair_copy(struct Main *bmain, const struct Hair *hair);

struct BoundBox *BKE_hair_boundbox_get(struct Object *ob);

void BKE_hair_update_customdata_pointers(struct Hair *hair);
bool BKE_hair_customdata_required(struct Hair *hair, struct CustomDataLayer *layer);

/* Depsgraph */

struct Hair *BKE_hair_new_for_eval(const struct Hair *hair_src, int totpoint, int totcurve);
struct Hair *BKE_hair_copy_for_eval(struct Hair *hair_src, bool reference);

void BKE_hair_data_update(struct Depsgraph *depsgraph, struct Scene *scene, struct Object *object);

/* Draw Cache */

enum {
  BKE_HAIR_BATCH_DIRTY_ALL = 0,
};

void BKE_hair_batch_cache_dirty_tag(struct Hair *hair, int mode);
void BKE_hair_batch_cache_free(struct Hair *hair);

extern void (*BKE_hair_batch_cache_dirty_tag_cb)(struct Hair *hair, int mode);
extern void (*BKE_hair_batch_cache_free_cb)(struct Hair *hair);

#ifdef __cplusplus
}
#endif
