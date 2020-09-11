#pragma once

struct Depsgraph;
struct Scene;
struct Simulation;

namespace blender::sim {

void update_simulation_in_depsgraph(Depsgraph *depsgraph,
                                    Scene *scene_cow,
                                    Simulation *simulation_cow);

bool update_simulation_dependencies(Simulation *simulation);

}  // namespace blender::sim
