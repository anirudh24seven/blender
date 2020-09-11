/** \file
 * \ingroup DNA
 */

#pragma once

#include "DNA_ID.h"
#include "DNA_customdata_types.h"

typedef struct Simulation {
  ID id;
  struct AnimData *adt; /* animation data (must be immediately after id) */

  struct bNodeTree *nodetree;

  uint32_t flag;

  /** This is the frame in scene time, that the states correspond to. */
  float current_frame;

  /** Time since the start of the simulation in simulation time (which might differ from scene
   * time). */
  float current_simulation_time;
  char _pad[4];

  /** List containing SimulationState objects. */
  struct ListBase states;

  /** List containing SimulationDependency objects. */
  struct ListBase dependencies;
} Simulation;

typedef struct SimulationState {
  struct SimulationState *next;
  struct SimulationState *prev;

  char *type;
  char *name;
} SimulationState;

typedef struct ParticleSimulationState {
  SimulationState head;

  /** Contains the state of the particles at time Simulation->current_frame. */
  int32_t tot_particles;
  int32_t next_particle_id;
  struct CustomData attributes;
} ParticleSimulationState;

typedef struct ParticleMeshEmitterSimulationState {
  SimulationState head;

  float last_birth_time;
  char _pad[4];
} ParticleMeshEmitterSimulationState;

/** Stores a reference to data that the simulation depends on. This is partially derived from the
 * simulation node tree. */
typedef struct SimulationDependency {
  struct SimulationDependency *next;
  struct SimulationDependency *prev;
  struct ID *id;
  int32_t handle;
  uint32_t flag;
} SimulationDependency;

/* Simulation.flag */
enum {
  SIM_DS_EXPAND = (1 << 0),
};

/* SimulationDependency.flag */
enum {
  SIM_DEPENDS_ON_TRANSFORM = (1 << 0),
  SIM_DEPENDS_ON_GEOMETRY = (1 << 1),
};

#define SIM_TYPE_NAME_PARTICLE_SIMULATION "Particle Simulation"
#define SIM_TYPE_NAME_PARTICLE_MESH_EMITTER "Particle Mesh Emitter"
