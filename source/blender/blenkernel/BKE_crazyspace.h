/** \file
 * \ingroup bke
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
struct BMEditMesh;
struct Depsgraph;
struct Mesh;
struct Object;
struct Scene;

/* crazyspace.c */
float (*BKE_crazyspace_get_mapped_editverts(struct Depsgraph *depsgraph,
                                            struct Object *obedit))[3];
void BKE_crazyspace_set_quats_editmesh(struct BMEditMesh *em,
                                       float (*origcos)[3],
                                       float (*mappedcos)[3],
                                       float (*quats)[4],
                                       const bool use_select);
void BKE_crazyspace_set_quats_mesh(struct Mesh *me,
                                   float (*origcos)[3],
                                   float (*mappedcos)[3],
                                   float (*quats)[4]);
int BKE_crazyspace_get_first_deform_matrices_editbmesh(struct Depsgraph *depsgraph,
                                                       struct Scene *,
                                                       struct Object *,
                                                       struct BMEditMesh *em,
                                                       float (**deformmats)[3][3],
                                                       float (**deformcos)[3]);
int BKE_sculpt_get_first_deform_matrices(struct Depsgraph *depsgraph,
                                         struct Scene *scene,
                                         struct Object *ob,
                                         float (**deformmats)[3][3],
                                         float (**deformcos)[3]);
void BKE_crazyspace_build_sculpt(struct Depsgraph *depsgraph,
                                 struct Scene *scene,
                                 struct Object *ob,
                                 float (**deformmats)[3][3],
                                 float (**deformcos)[3]);

#ifdef __cplusplus
}
#endif
