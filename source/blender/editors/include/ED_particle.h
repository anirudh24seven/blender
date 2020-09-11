/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct PTCacheEdit;
struct ParticleEditSettings;
struct ParticleSystem;
struct Scene;
struct UndoType;
struct ViewLayer;
struct bContext;
struct rcti;

/* particle edit mode */
void PE_free_ptcache_edit(struct PTCacheEdit *edit);
int PE_start_edit(struct PTCacheEdit *edit);

/* access */
struct PTCacheEdit *PE_get_current_from_psys(struct ParticleSystem *psys);
struct PTCacheEdit *PE_get_current(struct Depsgraph *depsgraph,
                                   struct Scene *scene,
                                   struct Object *ob);
struct PTCacheEdit *PE_create_current(struct Depsgraph *depsgraph,
                                      struct Scene *scene,
                                      struct Object *ob);
void PE_current_changed(struct Depsgraph *depsgraph, struct Scene *scene, struct Object *ob);
int PE_minmax(struct Depsgraph *depsgraph,
              struct Scene *scene,
              struct ViewLayer *view_layer,
              float min[3],
              float max[3]);
struct ParticleEditSettings *PE_settings(struct Scene *scene);

/* update calls */
void PE_hide_keys_time(struct Scene *scene, struct PTCacheEdit *edit, float cfra);
void PE_update_object(struct Depsgraph *depsgraph,
                      struct Scene *scene,
                      struct Object *ob,
                      int useflag);

/* selection tools */
bool PE_mouse_particles(
    struct bContext *C, const int mval[2], bool extend, bool deselect, bool toggle);
bool PE_box_select(struct bContext *C, const struct rcti *rect, const int sel_op);
bool PE_circle_select(struct bContext *C, const int sel_op, const int mval[2], float rad);
int PE_lasso_select(struct bContext *C,
                    const int mcoords[][2],
                    const int mcoords_len,
                    const int sel_op);
bool PE_deselect_all_visible_ex(struct PTCacheEdit *edit);
bool PE_deselect_all_visible(struct bContext *C);

/* particle_edit_undo.c */
void ED_particle_undosys_type(struct UndoType *ut);

#ifdef __cplusplus
}
#endif
