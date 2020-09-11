#pragma once

/** \file
 * \ingroup bke
 * \brief General operations for point-clouds.
 */
#ifdef __cplusplus
extern "C" {
#endif

struct BoundBox;
struct CustomDataLayer;
struct Depsgraph;
struct Main;
struct Object;
struct PointCloud;
struct Scene;

void *BKE_pointcloud_add(struct Main *bmain, const char *name);
struct PointCloud *BKE_pointcloud_copy(struct Main *bmain, const struct PointCloud *pointcloud);

struct BoundBox *BKE_pointcloud_boundbox_get(struct Object *ob);

void BKE_pointcloud_update_customdata_pointers(struct PointCloud *pointcloud);
bool BKE_pointcloud_customdata_required(struct PointCloud *pointcloud,
                                        struct CustomDataLayer *layer);

/* Dependency Graph */

struct PointCloud *BKE_pointcloud_new_for_eval(const struct PointCloud *pointcloud_src,
                                               int totpoint);
struct PointCloud *BKE_pointcloud_copy_for_eval(struct PointCloud *pointcloud_src, bool reference);

void BKE_pointcloud_data_update(struct Depsgraph *depsgraph,
                                struct Scene *scene,
                                struct Object *object);

/* Draw Cache */

enum {
  BKE_POINTCLOUD_BATCH_DIRTY_ALL = 0,
};

void BKE_pointcloud_batch_cache_dirty_tag(struct PointCloud *pointcloud, int mode);
void BKE_pointcloud_batch_cache_free(struct PointCloud *pointcloud);

extern void (*BKE_pointcloud_batch_cache_dirty_tag_cb)(struct PointCloud *pointcloud, int mode);
extern void (*BKE_pointcloud_batch_cache_free_cb)(struct PointCloud *pointcloud);

#ifdef __cplusplus
}
#endif
