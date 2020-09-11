/** \file
 * \ingroup editors
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ARegion;
struct SpaceText;
struct Text;
struct UndoStep;
struct UndoType;
struct bContext;

bool ED_text_region_location_from_cursor(struct SpaceText *st,
                                         struct ARegion *region,
                                         const int cursor_co[2],
                                         int r_pixel_co[2]);

/* text_undo.c */
void ED_text_undosys_type(struct UndoType *ut);

struct UndoStep *ED_text_undo_push_init(struct bContext *C);

/* text_format.c */
bool ED_text_is_syntax_highlight_supported(struct Text *text);

#ifdef __cplusplus
}
#endif
