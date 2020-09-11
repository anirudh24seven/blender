/** \file
 * \ingroup draw
 */

#pragma once

struct BoundBox;

void DRW_debug_modelmat_reset(void);
void DRW_debug_modelmat(const float modelmat[4][4]);

void DRW_debug_line_v3v3(const float v1[3], const float v2[3], const float color[4]);
void DRW_debug_polygon_v3(const float (*v)[3], const int vert_len, const float color[4]);
void DRW_debug_m4(const float m[4][4]);
void DRW_debug_m4_as_bbox(const float m[4][4], const float color[4], const bool invert);
void DRW_debug_bbox(const BoundBox *bbox, const float color[4]);
void DRW_debug_sphere(const float center[3], const float radius, const float color[4]);
