#pragma once

#include "FN_attributes_ref.hh"
#include "FN_multi_function.hh"

#include "BLI_resource_collector.hh"

#include "simulation_solver.hh"

namespace blender::sim {

struct ParticleFunctionInputContext {
  const SimulationSolveContext &solve_context;
  const ParticleChunkContext &particles;
};

class ParticleFunctionInput {
 public:
  virtual ~ParticleFunctionInput() = default;
  virtual void add_input(ParticleFunctionInputContext &context,
                         fn::MFParamsBuilder &params,
                         ResourceCollector &resources) const = 0;
};

class ParticleFunction {
 private:
  const fn::MultiFunction *global_fn_;
  const fn::MultiFunction *per_particle_fn_;
  Array<const ParticleFunctionInput *> global_inputs_;
  Array<const ParticleFunctionInput *> per_particle_inputs_;
  Array<bool> output_is_global_;
  Vector<int> global_output_indices_;
  Vector<int> per_particle_output_indices_;
  Vector<fn::MFDataType> output_types_;
  Vector<StringRefNull> output_names_;

  friend class ParticleFunctionEvaluator;

 public:
  ParticleFunction(const fn::MultiFunction *global_fn,
                   const fn::MultiFunction *per_particle_fn,
                   Span<const ParticleFunctionInput *> global_inputs,
                   Span<const ParticleFunctionInput *> per_particle_inputs,
                   Span<bool> output_is_global);
};

class ParticleFunctionEvaluator {
 private:
  ResourceCollector resources_;
  const ParticleFunction &particle_fn_;
  const SimulationSolveContext &solve_context_;
  const ParticleChunkContext &particles_;
  IndexMask mask_;
  fn::MFContextBuilder global_context_;
  fn::MFContextBuilder per_particle_context_;
  Vector<void *> outputs_;
  bool is_computed_ = false;

 public:
  ParticleFunctionEvaluator(const ParticleFunction &particle_fn,
                            const SimulationSolveContext &solve_context,
                            const ParticleChunkContext &particles);
  ~ParticleFunctionEvaluator();

  void compute();
  fn::GVSpan get(int output_index, StringRef expected_name = "") const;

  template<typename T> fn::VSpan<T> get(int output_index, StringRef expected_name = "") const
  {
    return this->get(output_index, expected_name).typed<T>();
  }

 private:
  void compute_globals();
  void compute_per_particle();
};

}  // namespace blender::sim
