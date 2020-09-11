#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

int BLI_convexhull_2d_sorted(const float (*points)[2], const int n, int r_points[]);
int BLI_convexhull_2d(const float (*points)[2], const int n, int r_points[]);

float BLI_convexhull_aabb_fit_hull_2d(const float (*points_hull)[2], unsigned int n);
float BLI_convexhull_aabb_fit_points_2d(const float (*points)[2], unsigned int n);

#ifdef __cplusplus
}
#endif
