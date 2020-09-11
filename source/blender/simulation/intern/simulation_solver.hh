#pragma once

#include "simulation_collect_influences.hh"

struct Depsgraph;

namespace blender::sim {

void initialize_simulation_states(Simulation &simulation,
                                  Depsgraph &depsgraph,
                                  const SimulationInfluences &influences,
                                  const bke::PersistentDataHandleMap &handle_map);

void solve_simulation_time_step(Simulation &simulation,
                                Depsgraph &depsgraph,
                                const SimulationInfluences &influences,
                                const bke::PersistentDataHandleMap &handle_map,
                                const DependencyAnimations &dependency_animations,
                                float time_step);

}  // namespace blender::sim
