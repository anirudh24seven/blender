/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ARegion;
struct Object;
struct UndoType;
struct ViewContext;
struct bContext;
struct rcti;

/* sculpt.c */
void ED_operatortypes_sculpt(void);
void ED_sculpt_redraw_planes_get(float planes[4][4], struct ARegion *region, struct Object *ob);
bool ED_sculpt_mask_box_select(struct bContext *C,
                               struct ViewContext *vc,
                               const struct rcti *rect,
                               bool select);

/* transform */
void ED_sculpt_update_modal_transform(struct bContext *C);
void ED_sculpt_init_transform(struct bContext *C);
void ED_sculpt_end_transform(struct bContext *C);

/* sculpt_undo.c */
void ED_sculpt_undosys_type(struct UndoType *ut);

void ED_sculpt_undo_geometry_begin(struct Object *ob, const char *name);
void ED_sculpt_undo_geometry_end(struct Object *ob);

/* Face sets. */
int ED_sculpt_face_sets_find_next_available_id(struct Mesh *mesh);
void ED_sculpt_face_sets_initialize_none_to_id(struct Mesh *mesh, const int new_id);

int ED_sculpt_face_sets_active_update_and_get(struct bContext *C,
                                              struct Object *ob,
                                              const float mval[2]);

/* Undo for changes happening on a base mesh for multires sculpting.
 * if there is no multires sculpt active regular undo is used. */
void ED_sculpt_undo_push_multires_mesh_begin(struct bContext *C, const char *str);
void ED_sculpt_undo_push_multires_mesh_end(struct bContext *C, const char *str);

#ifdef __cplusplus
}
#endif
