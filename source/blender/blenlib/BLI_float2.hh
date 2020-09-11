#pragma once

#include "BLI_float3.hh"

namespace blender {

struct float2 {
  float x, y;

  float2() = default;

  float2(const float *ptr) : x{ptr[0]}, y{ptr[1]}
  {
  }

  float2(float x, float y) : x(x), y(y)
  {
  }

  float2(const float3 &other) : x(other.x), y(other.y)
  {
  }

  operator float *()
  {
    return &x;
  }

  operator const float *() const
  {
    return &x;
  }

  float length() const
  {
    return len_v2(*this);
  }

  float2 &operator+=(const float2 &other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  float2 &operator-=(const float2 &other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  float2 &operator*=(float factor)
  {
    x *= factor;
    y *= factor;
    return *this;
  }

  float2 &operator/=(float divisor)
  {
    x /= divisor;
    y /= divisor;
    return *this;
  }

  friend float2 operator+(const float2 &a, const float2 &b)
  {
    return {a.x + b.x, a.y + b.y};
  }

  friend float2 operator-(const float2 &a, const float2 &b)
  {
    return {a.x - b.x, a.y - b.y};
  }

  friend float2 operator*(const float2 &a, float b)
  {
    return {a.x * b, a.y * b};
  }

  friend float2 operator/(const float2 &a, float b)
  {
    BLI_assert(b != 0.0f);
    return {a.x / b, a.y / b};
  }

  friend float2 operator*(float a, const float2 &b)
  {
    return b * a;
  }

  friend std::ostream &operator<<(std::ostream &stream, const float2 &v)
  {
    stream << "(" << v.x << ", " << v.y << ")";
    return stream;
  }

  static float dot(const float2 &a, const float2 &b)
  {
    return a.x * b.x + a.y * b.y;
  }

  static float2 interpolate(const float2 &a, const float2 &b, float t)
  {
    return a * (1 - t) + b * t;
  }

  static float2 abs(const float2 &a)
  {
    return float2(fabsf(a.x), fabsf(a.y));
  }

  static float distance(const float2 &a, const float2 &b)
  {
    return (a - b).length();
  }

  static float distance_squared(const float2 &a, const float2 &b)
  {
    return float2::dot(a, b);
  }

  struct isect_result {
    enum {
      LINE_LINE_COLINEAR = -1,
      LINE_LINE_NONE = 0,
      LINE_LINE_EXACT = 1,
      LINE_LINE_CROSS = 2,
    } kind;
    float lambda;
    float mu;
  };

  static isect_result isect_seg_seg(const float2 &v1,
                                    const float2 &v2,
                                    const float2 &v3,
                                    const float2 &v4);

  friend bool operator==(const float2 &a, const float2 &b)
  {
    return a.x == b.x && a.y == b.y;
  }

  friend bool operator!=(const float2 &a, const float2 &b)
  {
    return !(a == b);
  }
};

}  // namespace blender
