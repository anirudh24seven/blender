/** \file
 * \ingroup edscr
 */

#pragma once

struct Main;
struct bContext;
struct bContextDataResult;

/* internal exports only */

#define AZONESPOTW UI_HEADER_OFFSET         /* width of corner azone - max */
#define AZONESPOTH (0.6f * U.widget_unit)   /* height of corner azone */
#define AZONEFADEIN (5.0f * U.widget_unit)  /* when azone is totally visible */
#define AZONEFADEOUT (6.5f * U.widget_unit) /* when we start seeing the azone */

#define AREAJOINTOLERANCE (1.0f * U.widget_unit) /* Edges must be close to allow joining. */

/* Expanded interaction influence of area borders. */
#define BORDERPADDING (U.dpi_fac + U.pixelsize)

/* area.c */
void ED_area_data_copy(ScrArea *area_dst, ScrArea *area_src, const bool do_free);
void ED_area_data_swap(ScrArea *area_dst, ScrArea *area_src);
void region_toggle_hidden(struct bContext *C, ARegion *region, const bool do_fade);

/* screen_edit.c */
bScreen *screen_add(struct Main *bmain, const char *name, const rcti *rect);
void screen_data_copy(bScreen *to, bScreen *from);
void screen_new_activate_prepare(const wmWindow *win, bScreen *screen_new);
void screen_change_update(struct bContext *C, wmWindow *win, bScreen *screen);
void screen_change_prepare(bScreen *screen_old,
                           bScreen *screen_new,
                           struct Main *bmain,
                           struct bContext *C,
                           wmWindow *win);
ScrArea *area_split(
    const wmWindow *win, bScreen *screen, ScrArea *area, char dir, float fac, int merge);
int screen_area_join(struct bContext *C, bScreen *screen, ScrArea *sa1, ScrArea *sa2);
int area_getorientation(ScrArea *area, ScrArea *sb);

struct AZone *ED_area_actionzone_find_xy(ScrArea *area, const int xy[2]);

/* screen_geometry.c */
int screen_geom_area_height(const ScrArea *area);
int screen_geom_area_width(const ScrArea *area);
ScrVert *screen_geom_vertex_add_ex(ScrAreaMap *area_map, short x, short y);
ScrVert *screen_geom_vertex_add(bScreen *screen, short x, short y);
ScrEdge *screen_geom_edge_add_ex(ScrAreaMap *area_map, ScrVert *v1, ScrVert *v2);
ScrEdge *screen_geom_edge_add(bScreen *screen, ScrVert *v1, ScrVert *v2);
bool screen_geom_edge_is_horizontal(ScrEdge *se);
ScrEdge *screen_geom_area_map_find_active_scredge(const struct ScrAreaMap *area_map,
                                                  const rcti *bounds_rect,
                                                  const int mx,
                                                  const int my);
ScrEdge *screen_geom_find_active_scredge(const wmWindow *win,
                                         const bScreen *screen,
                                         const int mx,
                                         const int my);
void screen_geom_vertices_scale(const wmWindow *win, bScreen *screen);
short screen_geom_find_area_split_point(const ScrArea *area,
                                        const rcti *window_rect,
                                        char dir,
                                        float fac);
void screen_geom_select_connected_edge(const wmWindow *win, ScrEdge *edge);

/* screen_context.c */
int ed_screen_context(const struct bContext *C,
                      const char *member,
                      struct bContextDataResult *result);

extern const char *screen_context_dir[]; /* doc access */

/* screendump.c */
void SCREEN_OT_screenshot(struct wmOperatorType *ot);

/* workspace_layout_edit.c */
bool workspace_layout_set_poll(const struct WorkSpaceLayout *layout);
