/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ARegionType;
struct bContext;

void ED_spacetypes_init(void);
void ED_spacemacros_init(void);

/* the pluginnable API for export to editors */

/* calls for registering default spaces */
void ED_spacetype_outliner(void);
void ED_spacetype_view3d(void);
void ED_spacetype_ipo(void);
void ED_spacetype_image(void);
void ED_spacetype_node(void);
void ED_spacetype_buttons(void);
void ED_spacetype_info(void);
void ED_spacetype_file(void);
void ED_spacetype_action(void);
void ED_spacetype_nla(void);
void ED_spacetype_script(void);
void ED_spacetype_text(void);
void ED_spacetype_sequencer(void);
void ED_spacetype_logic(void);
void ED_spacetype_console(void);
void ED_spacetype_userpref(void);
void ED_spacetype_clip(void);
void ED_spacetype_statusbar(void);
void ED_spacetype_topbar(void);

/* calls for instancing and freeing spacetype static data
 * called in WM_init_exit */
/* in space_file.c */
void ED_file_init(void);
void ED_file_exit(void);

#define REGION_DRAW_POST_VIEW 0
#define REGION_DRAW_POST_PIXEL 1
#define REGION_DRAW_PRE_VIEW 2
#define REGION_DRAW_BACKDROP 3

void *ED_region_draw_cb_activate(struct ARegionType *art,
                                 void (*draw)(const struct bContext *, struct ARegion *, void *),
                                 void *customdata,
                                 int type);
void ED_region_draw_cb_draw(const struct bContext *, struct ARegion *, int);
void ED_region_draw_cb_exit(struct ARegionType *, void *);
/* generic callbacks */
/* ed_util.c */
void ED_region_draw_mouse_line_cb(const struct bContext *C,
                                  struct ARegion *region,
                                  void *arg_info);

#ifdef __cplusplus
}
#endif
