#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ListBase;
struct Object;
struct Path;

/* ---------------------------------------------------- */
/* Curve Paths */

void free_path(struct Path *path);
void calc_curvepath(struct Object *ob, struct ListBase *nurbs);
bool where_on_path(const struct Object *ob,
                   float ctime,
                   float r_vec[4],
                   float r_dir[3],
                   float r_quat[4],
                   float *r_radius,
                   float *r_weight);

#ifdef __cplusplus
}
#endif
