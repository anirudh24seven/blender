#pragma once

#include "BLI_utildefines.h"

namespace blender::sim {

/**
 * The start time is exclusive and the end time is inclusive. If the duration is zero, the interval
 * describes a single point in time.
 */
class TimeInterval {
 private:
  float start_;
  float duration_;

 public:
  TimeInterval(float start, float duration) : start_(start), duration_(duration)
  {
    BLI_assert(duration_ >= 0.0f);
  }

  float start() const
  {
    return start_;
  }

  float stop() const
  {
    return start_ + duration_;
  }

  float duration() const
  {
    return duration_;
  }

  float time_at_factor(float factor) const
  {
    return start_ + factor * duration_;
  }

  float factor_at_time(float time) const
  {
    BLI_assert(duration_ > 0.0f);
    return (time - start_) / duration_;
  }

  float safe_factor_at_time(float time) const
  {
    if (duration_ > 0.0f) {
      return this->factor_at_time(time);
    }
    return 0.0f;
  }

  void compute_uniform_samples(MutableSpan<float> r_samples) const
  {
    int64_t amount = r_samples.size();
    if (amount == 0) {
      return;
    }
    if (amount == 1) {
      r_samples[0] = this->time_at_factor(0.5f);
      return;
    }

    const float step = duration_ / (float)(amount - 1);
    for (int64_t i : r_samples.index_range()) {
      r_samples[i] = start_ + i * step;
    }
  }
};

}  // namespace blender::sim
