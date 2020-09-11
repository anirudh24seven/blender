/** \file
 * \ingroup edinterface
 *
 * Share between interface_eyedropper_*.c files.
 */

#pragma once

/* interface_eyedropper.c */
void eyedropper_draw_cursor_text(const struct bContext *C,
                                 const struct ARegion *region,
                                 const char *name);
uiBut *eyedropper_get_property_button_under_mouse(bContext *C, const wmEvent *event);

/* interface_eyedropper_color.c (expose for color-band picker) */
void eyedropper_color_sample_fl(bContext *C, int mx, int my, float r_col[3]);

/* Used for most eye-dropper operators. */
enum {
  EYE_MODAL_CANCEL = 1,
  EYE_MODAL_SAMPLE_CONFIRM,
  EYE_MODAL_SAMPLE_BEGIN,
  EYE_MODAL_SAMPLE_RESET,
};

/* Color-band point sample. */
enum {
  EYE_MODAL_POINT_CANCEL = 1,
  EYE_MODAL_POINT_SAMPLE,
  EYE_MODAL_POINT_CONFIRM,
  EYE_MODAL_POINT_RESET,
  EYE_MODAL_POINT_REMOVE_LAST,
};
