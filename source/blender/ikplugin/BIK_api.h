/** The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 * Original author: Benoit Bolsee
 */

/** \file
 * \ingroup ikplugin
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Object;
struct Scene;
struct bConstraint;
struct bPose;
struct bPoseChannel;

void BIK_init_tree(struct Depsgraph *depsgraph,
                   struct Scene *scene,
                   struct Object *ob,
                   float ctime);
void BIK_execute_tree(struct Depsgraph *depsgraph,
                      struct Scene *scene,
                      struct Object *ob,
                      struct bPoseChannel *pchan,
                      float ctime);
void BIK_release_tree(struct Scene *scene, struct Object *ob, float ctime);
void BIK_clear_data(struct bPose *pose);
void BIK_clear_cache(struct bPose *pose);
void BIK_update_param(struct bPose *pose);
void BIK_test_constraint(struct Object *ob, struct bConstraint *cons);

#ifdef __cplusplus
}
#endif
