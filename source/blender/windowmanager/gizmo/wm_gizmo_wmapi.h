/** \file
 * \ingroup wm
 *
 * \name Gizmos Window Manager API
 * API for usage in window manager code only. It should contain all functionality
 * needed to hook up the gizmo system with Blender's window manager. It's
 * mostly the event system that needs to communicate with gizmo code.
 *
 * Only included in wm.h and lower level files.
 */

#pragma once

struct wmEventHandler_Gizmo;
struct wmEventHandler_Op;
struct wmGizmoMap;
struct wmOperatorType;

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------- */
/* wmGizmo */

/* wm_gizmo_type.c, for init/exit */
void wm_gizmotype_free(void);
void wm_gizmotype_init(void);

/* wm_gizmogroup_type.c, for init/exit */
void wm_gizmogrouptype_free(void);
void wm_gizmogrouptype_init(void);

/* -------------------------------------------------------------------- */
/* wmGizmoGroup */

void GIZMOGROUP_OT_gizmo_select(struct wmOperatorType *ot);
void GIZMOGROUP_OT_gizmo_tweak(struct wmOperatorType *ot);

bool wm_gizmogroup_is_any_selected(const struct wmGizmoGroup *gzgroup);

/* -------------------------------------------------------------------- */
/* wmGizmoMap */

void wm_gizmomap_remove(struct wmGizmoMap *gzmap);

void wm_gizmos_keymap(struct wmKeyConfig *keyconf);

void wm_gizmomaps_handled_modal_update(bContext *C,
                                       struct wmEvent *event,
                                       struct wmEventHandler_Op *handler);
void wm_gizmomap_handler_context_op(bContext *C, struct wmEventHandler_Op *handler);
void wm_gizmomap_handler_context_gizmo(bContext *C, struct wmEventHandler_Gizmo *handler);

struct wmGizmo *wm_gizmomap_highlight_find(struct wmGizmoMap *gzmap,
                                           bContext *C,
                                           const struct wmEvent *event,
                                           int *r_part);
bool wm_gizmomap_highlight_set(struct wmGizmoMap *gzmap,
                               const bContext *C,
                               struct wmGizmo *gz,
                               int part);
struct wmGizmo *wm_gizmomap_highlight_get(struct wmGizmoMap *gzmap);
void wm_gizmomap_modal_set(struct wmGizmoMap *gzmap,
                           bContext *C,
                           struct wmGizmo *gz,
                           const struct wmEvent *event,
                           bool enable);

struct wmGizmo *wm_gizmomap_modal_get(struct wmGizmoMap *gzmap);
struct wmGizmo **wm_gizmomap_selected_get(wmGizmoMap *gzmap, int *r_selected_len);
struct ListBase *wm_gizmomap_groups_get(wmGizmoMap *gzmap);

/* -------------------------------------------------------------------- */
/* wmGizmoMapType */

void wm_gizmomaptypes_free(void);

#ifdef __cplusplus
}
#endif
