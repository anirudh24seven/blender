/** \file
 * \ingroup gpu
 *
 * GPUBackend derived class contain allocators that do not need a context bound.
 * The backend is init at startup and is accessible using GPU_backend_get() */

#pragma once

namespace blender {
namespace gpu {

class Context;

class Batch;
class DrawList;
class FrameBuffer;
class IndexBuf;
class QueryPool;
class Shader;
class Texture;
class UniformBuf;
class VertBuf;

class GPUBackend {
 public:
  virtual ~GPUBackend(){};

  static GPUBackend *get(void);

  virtual void samplers_update(void) = 0;

  virtual Context *context_alloc(void *ghost_window) = 0;

  virtual Batch *batch_alloc(void) = 0;
  virtual DrawList *drawlist_alloc(int list_length) = 0;
  virtual FrameBuffer *framebuffer_alloc(const char *name) = 0;
  virtual IndexBuf *indexbuf_alloc(void) = 0;
  virtual QueryPool *querypool_alloc(void) = 0;
  virtual Shader *shader_alloc(const char *name) = 0;
  virtual Texture *texture_alloc(const char *name) = 0;
  virtual UniformBuf *uniformbuf_alloc(int size, const char *name) = 0;
  virtual VertBuf *vertbuf_alloc(void) = 0;
};

}  // namespace gpu
}  // namespace blender
