#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Object;
struct Scene;
struct SoftBody;

typedef struct BodyPoint {
  float origS[3], origE[3], origT[3], pos[3], vec[3], force[3];
  float goal;
  float prevpos[3], prevvec[3], prevdx[3], prevdv[3]; /* used for Heun integration */
  float impdv[3], impdx[3];
  int nofsprings;
  int *springs;
  float choke, choke2, frozen;
  float colball;
  short loc_flag;  // reserved by locale module specific states
  // char octantflag;
  float mass;
  float springweight;
} BodyPoint;

/* allocates and initializes general main data */
extern struct SoftBody *sbNew(struct Scene *scene);

/* frees internal data and softbody itself */
extern void sbFree(struct Object *ob);

/* frees simulation data to reset simulation */
extern void sbFreeSimulation(struct SoftBody *sb);

/* do one simul step, reading and writing vertex locs from given array */
extern void sbObjectStep(struct Depsgraph *depsgraph,
                         struct Scene *scene,
                         struct Object *ob,
                         float cfra,
                         float (*vertexCos)[3],
                         int numVerts);

/* makes totally fresh start situation, resets time */
extern void sbObjectToSoftbody(struct Object *ob);

/* links the softbody module to a 'test for Interrupt' function */
/* pass NULL to unlink again */
extern void sbSetInterruptCallBack(int (*f)(void));

extern void SB_estimate_transform(Object *ob, float lloc[3], float lrot[3][3], float lscale[3][3]);

#ifdef __cplusplus
}
#endif
