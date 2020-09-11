/** \file
 * \ingroup gpu
 */

#pragma once

#include "gpu_backend.hh"

#include "BLI_vector.hh"

#include "gl_batch.hh"
#include "gl_context.hh"
#include "gl_drawlist.hh"
#include "gl_framebuffer.hh"
#include "gl_index_buffer.hh"
#include "gl_query.hh"
#include "gl_shader.hh"
#include "gl_texture.hh"
#include "gl_uniform_buffer.hh"
#include "gl_vertex_buffer.hh"

namespace blender {
namespace gpu {

class GLBackend : public GPUBackend {
 private:
  GLSharedOrphanLists shared_orphan_list_;

 public:
  GLBackend()
  {
    /* platform_init needs to go first. */
    GLBackend::platform_init();

    GLBackend::capabilities_init();
    GLTexture::samplers_init();
  }
  ~GLBackend()
  {
    GLTexture::samplers_free();

    GLBackend::platform_exit();
  }

  static GLBackend *get(void)
  {
    return static_cast<GLBackend *>(GPUBackend::get());
  }

  void samplers_update(void) override
  {
    GLTexture::samplers_update();
  };

  Context *context_alloc(void *ghost_window) override
  {
    return new GLContext(ghost_window, shared_orphan_list_);
  };

  Batch *batch_alloc(void) override
  {
    return new GLBatch();
  };

  DrawList *drawlist_alloc(int list_length) override
  {
    return new GLDrawList(list_length);
  };

  FrameBuffer *framebuffer_alloc(const char *name) override
  {
    return new GLFrameBuffer(name);
  };

  IndexBuf *indexbuf_alloc(void) override
  {
    return new GLIndexBuf();
  };

  QueryPool *querypool_alloc(void) override
  {
    return new GLQueryPool();
  };

  Shader *shader_alloc(const char *name) override
  {
    return new GLShader(name);
  };

  Texture *texture_alloc(const char *name) override
  {
    return new GLTexture(name);
  };

  UniformBuf *uniformbuf_alloc(int size, const char *name) override
  {
    return new GLUniformBuf(size, name);
  };

  VertBuf *vertbuf_alloc(void) override
  {
    return new GLVertBuf();
  };

  GLSharedOrphanLists &shared_orphan_list_get(void)
  {
    return shared_orphan_list_;
  };

 private:
  static void platform_init(void);
  static void platform_exit(void);

  static void capabilities_init(void);
};

}  // namespace gpu
}  // namespace blender
