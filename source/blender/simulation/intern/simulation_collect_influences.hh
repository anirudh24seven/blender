#pragma once

#include "NOD_derived_node_tree.hh"

#include "BLI_resource_collector.hh"

#include "simulation_solver_influences.hh"

namespace blender::sim {

class RequiredStates {
 private:
  Map<std::string, const char *> state_type_by_state_name_;

 public:
  void add(std::string state_name, const char *state_type)
  {
    BLI_assert(state_type != nullptr);
    const char *type_name = state_type_by_state_name_.lookup_default(state_name, nullptr);
    if (type_name != nullptr) {
      if (!STREQ(state_type, type_name)) {
        std::cout << "Warning: Tried to have two different states with the same name.\n";
        std::cout << "    Name: " << state_name << "\n";
        std::cout << "    Type 1: " << state_type << "\n";
        std::cout << "    Type 2: " << type_name << "\n";
      }
      return;
    }

    state_type_by_state_name_.add(std::move(state_name), state_type);
  }

  const Map<std::string, const char *> &states() const
  {
    return state_type_by_state_name_;
  }

  bool is_required(StringRef state_name, StringRef state_type) const
  {
    return state_type_by_state_name_.lookup_default_as(state_name, "") == state_type;
  }
};

void collect_simulation_influences(Simulation &simulation,
                                   ResourceCollector &resources,
                                   SimulationInfluences &r_influences,
                                   RequiredStates &r_required_states);

}  // namespace blender::sim
