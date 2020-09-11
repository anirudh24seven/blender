/** \file
 * \ingroup gpu
 */

#pragma once

#include "MEM_guardedalloc.h"

#include "glew-mx.h"

#include "gpu_shader_private.hh"

namespace blender {
namespace gpu {

/**
 * Implementation of shader compilation and uniforms handling using OpenGL.
 **/
class GLShader : public Shader {
 private:
  /** Handle for full program (links shader stages below). */
  GLuint shader_program_ = 0;
  /** Individual shader stages. */
  GLuint vert_shader_ = 0;
  GLuint geom_shader_ = 0;
  GLuint frag_shader_ = 0;
  /** True if any shader failed to compile. */
  bool compilation_failed_ = false;

  eGPUShaderTFBType transform_feedback_type_ = GPU_SHADER_TFB_NONE;

 public:
  GLShader(const char *name);
  ~GLShader();

  /* Return true on success. */
  void vertex_shader_from_glsl(MutableSpan<const char *> sources) override;
  void geometry_shader_from_glsl(MutableSpan<const char *> sources) override;
  void fragment_shader_from_glsl(MutableSpan<const char *> sources) override;
  bool finalize(void) override;

  void transform_feedback_names_set(Span<const char *> name_list,
                                    const eGPUShaderTFBType geom_type) override;
  bool transform_feedback_enable(GPUVertBuf *buf) override;
  void transform_feedback_disable(void) override;

  void bind(void) override;
  void unbind(void) override;

  void uniform_float(int location, int comp_len, int array_size, const float *data) override;
  void uniform_int(int location, int comp_len, int array_size, const int *data) override;

  void vertformat_from_shader(GPUVertFormat *format) const override;

 private:
  char *glsl_patch_get(void);

  GLuint create_shader_stage(GLenum gl_stage, MutableSpan<const char *> sources);

  MEM_CXX_CLASS_ALLOC_FUNCS("GLShader");
};

}  // namespace gpu
}  // namespace blender
