/** \file
 * \ingroup gpu
 */

#pragma once

#include "BLI_span.hh"

#include "GPU_shader.h"
#include "gpu_shader_interface.hh"
#include "gpu_vertex_buffer_private.hh"

namespace blender {
namespace gpu {

/**
 * Implementation of shader compilation and uniforms handling.
 * Base class which is then specialized for each implementation (GL, VK, ...).
 **/
class Shader {
 public:
  /** Uniform & attribute locations for shader. */
  ShaderInterface *interface = nullptr;

 protected:
  /** For debugging purpose. */
  char name[64];

 public:
  Shader(const char *name);
  virtual ~Shader();

  virtual void vertex_shader_from_glsl(MutableSpan<const char *> sources) = 0;
  virtual void geometry_shader_from_glsl(MutableSpan<const char *> sources) = 0;
  virtual void fragment_shader_from_glsl(MutableSpan<const char *> sources) = 0;
  virtual bool finalize(void) = 0;

  virtual void transform_feedback_names_set(Span<const char *> name_list,
                                            const eGPUShaderTFBType geom_type) = 0;
  virtual bool transform_feedback_enable(GPUVertBuf *) = 0;
  virtual void transform_feedback_disable(void) = 0;

  virtual void bind(void) = 0;
  virtual void unbind(void) = 0;

  virtual void uniform_float(int location, int comp_len, int array_size, const float *data) = 0;
  virtual void uniform_int(int location, int comp_len, int array_size, const int *data) = 0;

  virtual void vertformat_from_shader(GPUVertFormat *) const = 0;

  inline const char *const name_get(void) const
  {
    return name;
  };

 protected:
  void print_errors(Span<const char *> sources, char *log, const char *stage);
};

/* Syntacting suggar. */
static inline GPUShader *wrap(Shader *vert)
{
  return reinterpret_cast<GPUShader *>(vert);
}
static inline Shader *unwrap(GPUShader *vert)
{
  return reinterpret_cast<Shader *>(vert);
}
static inline const Shader *unwrap(const GPUShader *vert)
{
  return reinterpret_cast<const Shader *>(vert);
}

}  // namespace gpu
}  // namespace blender

/* XXX do not use it. Special hack to use OCIO with batch API. */
GPUShader *immGetShader(void);
