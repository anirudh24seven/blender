#include "FN_cpp_type.hh"

#include "BLI_color.hh"
#include "BLI_float2.hh"
#include "BLI_float3.hh"
#include "BLI_float4x4.hh"

namespace blender::fn {

MAKE_CPP_TYPE(bool, bool)

MAKE_CPP_TYPE(float, float)
MAKE_CPP_TYPE(float3, blender::float3)
MAKE_CPP_TYPE(float4x4, blender::float4x4)

MAKE_CPP_TYPE(int32, int32_t)
MAKE_CPP_TYPE(uint32, uint32_t)
MAKE_CPP_TYPE(uint8, uint8_t)

MAKE_CPP_TYPE(Color4f, blender::Color4f)
MAKE_CPP_TYPE(Color4b, blender::Color4b)

MAKE_CPP_TYPE(string, std::string)

}  // namespace blender::fn
