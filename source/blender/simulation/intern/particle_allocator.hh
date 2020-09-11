#pragma once

#include "BLI_array.hh"
#include "BLI_vector.hh"

#include "FN_attributes_ref.hh"

#include <atomic>
#include <mutex>

namespace blender::sim {

class AttributesAllocator : NonCopyable, NonMovable {
 private:
  struct AttributesBlock {
    Array<void *> buffers;
    int size;
  };

  const fn::AttributesInfo &attributes_info_;
  Vector<std::unique_ptr<AttributesBlock>> allocated_blocks_;
  Vector<fn::MutableAttributesRef> allocated_attributes_;
  int total_allocated_ = 0;
  std::mutex mutex_;

 public:
  AttributesAllocator(const fn::AttributesInfo &attributes_info)
      : attributes_info_(attributes_info)
  {
  }

  ~AttributesAllocator();

  Span<fn::MutableAttributesRef> get_allocations() const
  {
    return allocated_attributes_;
  }

  int total_allocated() const
  {
    return total_allocated_;
  }

  const fn::AttributesInfo &attributes_info() const
  {
    return attributes_info_;
  }

  fn::MutableAttributesRef allocate_uninitialized(int size);
};

class ParticleAllocator : NonCopyable, NonMovable {
 private:
  AttributesAllocator attributes_allocator_;
  std::atomic<int> next_id_;
  uint32_t hash_seed_;

 public:
  ParticleAllocator(const fn::AttributesInfo &attributes_info, int next_id, uint32_t hash_seed)
      : attributes_allocator_(attributes_info), next_id_(next_id), hash_seed_(hash_seed)
  {
  }

  const fn::AttributesInfo &attributes_info() const
  {
    return attributes_allocator_.attributes_info();
  }

  Span<fn::MutableAttributesRef> get_allocations() const
  {
    return attributes_allocator_.get_allocations();
  }

  int total_allocated() const
  {
    return attributes_allocator_.total_allocated();
  }

  fn::MutableAttributesRef allocate(int size);
};

}  // namespace blender::sim
