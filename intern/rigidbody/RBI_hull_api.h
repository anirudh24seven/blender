/** The Original Code is Copyright (C) 2020 Blender Foundation,
 * All rights reserved.
 */

#ifndef __RB_HULL_API_H__
#define __RB_HULL_API_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct plConvexHull__ {
  int unused;
} * plConvexHull;

plConvexHull plConvexHullCompute(float (*coords)[3], int count);
void plConvexHullDelete(plConvexHull hull);
int plConvexHullNumVertices(plConvexHull hull);
int plConvexHullNumFaces(plConvexHull hull);
void plConvexHullGetVertex(plConvexHull hull, int n, float coords[3], int *original_index);
int plConvexHullGetFaceSize(plConvexHull hull, int n);
void plConvexHullGetFaceVertices(plConvexHull hull, int n, int *vertices);

#ifdef __cplusplus
}
#endif

#endif /* __RB_HULL_API_H__ */
