#pragma once

/** \file
 * \ingroup bke
 */

#include "DNA_boid_types.h"
#include "DNA_particle_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct RNG;

typedef struct BoidBrainData {
  struct ParticleSimulationData *sim;
  struct ParticleSettings *part;
  float timestep, cfra, dfra;
  float wanted_co[3], wanted_speed;

  /* Goal stuff */
  struct Object *goal_ob;
  float goal_co[3];
  float goal_nor[3];
  float goal_priority;

  struct RNG *rng;
} BoidBrainData;

void boids_precalc_rules(struct ParticleSettings *part, float cfra);
void boid_brain(BoidBrainData *bbd, int p, struct ParticleData *pa);
void boid_body(BoidBrainData *bbd, struct ParticleData *pa);
void boid_default_settings(BoidSettings *boids);
BoidRule *boid_new_rule(int type);
BoidState *boid_new_state(BoidSettings *boids);
BoidState *boid_duplicate_state(BoidSettings *boids, BoidState *state);
void boid_free_settings(BoidSettings *boids);
BoidSettings *boid_copy_settings(const BoidSettings *boids);
BoidState *boid_get_current_state(BoidSettings *boids);

#ifdef __cplusplus
}
#endif
