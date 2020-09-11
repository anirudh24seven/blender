#pragma once

#include "DNA_simulation_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Main;
struct Scene;

void *BKE_simulation_add(struct Main *bmain, const char *name);

void BKE_simulation_data_update(struct Depsgraph *depsgraph,
                                struct Scene *scene,
                                struct Simulation *simulation);
void BKE_simulation_update_dependencies(struct Simulation *simulation, struct Main *bmain);

SimulationState *BKE_simulation_state_add(Simulation *simulation,
                                          const char *type,
                                          const char *name);
void BKE_simulation_state_remove(Simulation *simulation, SimulationState *state);
void BKE_simulation_state_remove_all(Simulation *simulation);
void BKE_simulation_state_reset(Simulation *simulation, SimulationState *state);
void BKE_simulation_state_reset_all(Simulation *simulation);
SimulationState *BKE_simulation_state_try_find_by_name(Simulation *simulation, const char *name);
SimulationState *BKE_simulation_state_try_find_by_name_and_type(Simulation *simulation,
                                                                const char *name,
                                                                const char *type);
void BKE_simulation_state_copy_data(const SimulationState *src_state, SimulationState *dst_state);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

template<typename StateType> const char *BKE_simulation_get_state_type_name();

#endif
