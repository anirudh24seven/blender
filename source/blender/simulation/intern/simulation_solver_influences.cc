#include "simulation_solver_influences.hh"

#include "DNA_object_types.h"

namespace blender::sim {

ParticleForce::~ParticleForce()
{
}

ParticleEmitter::~ParticleEmitter()
{
}

ParticleAction::~ParticleAction()
{
}

ParticleEvent::~ParticleEvent()
{
}

DependencyAnimations::~DependencyAnimations()
{
}

bool DependencyAnimations::is_object_transform_changing(Object &UNUSED(object)) const
{
  return false;
}

void DependencyAnimations::get_object_transforms(Object &object,
                                                 Span<float> simulation_times,
                                                 MutableSpan<float4x4> r_transforms) const
{
  assert_same_size(simulation_times, r_transforms);
  float4x4 world_matrix = object.obmat;
  r_transforms.fill(world_matrix);
}

}  // namespace blender::sim
