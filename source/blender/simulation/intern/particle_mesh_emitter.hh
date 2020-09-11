#pragma once

#include "simulation_solver_influences.hh"

#include "FN_multi_function.hh"

namespace blender::sim {

class ParticleMeshEmitter final : public ParticleEmitter {
 private:
  std::string own_state_name_;
  Array<std::string> particle_names_;
  const fn::MultiFunction &inputs_fn_;
  const ParticleAction *action_;

 public:
  ParticleMeshEmitter(std::string own_state_name,
                      Array<std::string> particle_names,
                      const fn::MultiFunction &inputs_fn,
                      const ParticleAction *action)
      : own_state_name_(std::move(own_state_name)),
        particle_names_(particle_names),
        inputs_fn_(inputs_fn),
        action_(action)
  {
  }

  ~ParticleMeshEmitter();

  void emit(ParticleEmitterContext &context) const override;
};

}  // namespace blender::sim
