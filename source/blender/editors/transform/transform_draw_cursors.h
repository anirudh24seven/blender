/** \file
 * \ingroup edtransform
 */

#pragma once

/* Callbacks for #WM_paint_cursor_activate */
bool transform_draw_cursor_poll(struct bContext *C);
void transform_draw_cursor_draw(struct bContext *C, int x, int y, void *customdata);
