#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

struct rcti;

void BLI_lasso_boundbox(struct rcti *rect, const int mcoords[][2], const unsigned int mcoords_len);
bool BLI_lasso_is_point_inside(const int mcoords[][2],
                               const unsigned int mcoords_len,
                               const int sx,
                               const int sy,
                               const int error_value);
bool BLI_lasso_is_edge_inside(const int mcoords[][2],
                              const unsigned int mcoords_len,
                              int x0,
                              int y0,
                              int x1,
                              int y1,
                              const int error_value);

#ifdef __cplusplus
}
#endif
