/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Scene;
struct TimeMarker;
struct bAnimContext;
struct bContext;
struct wmKeyConfig;

/* Drawing API ------------------------------ */

/* flags for drawing markers */
enum {
  DRAW_MARKERS_LINES = (1 << 0),
  DRAW_MARKERS_LOCAL = (1 << 1),
  DRAW_MARKERS_MARGIN = (1 << 2),
};

void ED_markers_draw(const struct bContext *C, int flag);

/* Backend API ----------------------------- */

ListBase *ED_context_get_markers(const struct bContext *C);
ListBase *ED_animcontext_get_markers(const struct bAnimContext *ac);

int ED_markers_post_apply_transform(
    ListBase *markers, struct Scene *scene, int mode, float value, char side);

struct TimeMarker *ED_markers_find_nearest_marker(ListBase *markers, float x);
int ED_markers_find_nearest_marker_time(ListBase *markers, float x);

void ED_markers_get_minmax(ListBase *markers, short sel, float *first, float *last);

void ED_markers_make_cfra_list(ListBase *markers, ListBase *lb, short sel);

void ED_markers_deselect_all(ListBase *markers, int action);

struct TimeMarker *ED_markers_get_first_selected(ListBase *markers);

/* Operators ------------------------------ */

/* called in screen_ops.c:ED_operatortypes_screen() */
void ED_operatortypes_marker(void);
/* called in screen_ops.c:ED_keymap_screen() */
void ED_keymap_marker(struct wmKeyConfig *keyconf);

/* debugging only */
void debug_markers_print_list(struct ListBase *markers);

#ifdef __cplusplus
}
#endif
