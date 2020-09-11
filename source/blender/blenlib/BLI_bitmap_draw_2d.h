#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

void BLI_bitmap_draw_2d_line_v2v2i(const int p1[2],
                                   const int p2[2],
                                   bool (*callback)(int, int, void *),
                                   void *user_data);

void BLI_bitmap_draw_2d_tri_v2i(const int p1[2],
                                const int p2[2],
                                const int p3[2],
                                void (*callback)(int x, int x_end, int y, void *),
                                void *user_data);

void BLI_bitmap_draw_2d_poly_v2i_n(const int xmin,
                                   const int ymin,
                                   const int xmax,
                                   const int ymax,
                                   const int verts[][2],
                                   const int verts_len,
                                   void (*callback)(int x, int x_end, int y, void *),
                                   void *user_data);

#ifdef __cplusplus
}
#endif
