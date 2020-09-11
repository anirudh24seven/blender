/** \file
 * \ingroup gpu
 */

#pragma once

#include "glew-mx.h"

#include "GPU_batch.h"
#include "gl_shader_interface.hh"

namespace blender {
namespace gpu {

namespace GLVertArray {

void update_bindings(const GLuint vao,
                     const GPUBatch *batch,
                     const ShaderInterface *interface,
                     const int base_instance);

void update_bindings(const GLuint vao,
                     const uint v_first,
                     const GPUVertFormat *format,
                     const ShaderInterface *interface);

}  // namespace GLVertArray

}  // namespace gpu
}  // namespace blender
