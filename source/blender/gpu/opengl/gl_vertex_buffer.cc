/** \file
 * \ingroup gpu
 */

#include "gl_context.hh"

#include "gl_vertex_buffer.hh"

namespace blender::gpu {

void GLVertBuf::acquire_data(void)
{
  /* Discard previous data if any. */
  MEM_SAFE_FREE(data);
  data = (uchar *)MEM_mallocN(sizeof(uchar) * this->size_alloc_get(), __func__);
}

void GLVertBuf::resize_data(void)
{
  data = (uchar *)MEM_reallocN(data, sizeof(uchar) * this->size_alloc_get());
}

void GLVertBuf::release_data(void)
{
  if (vbo_id_ != 0) {
    GLContext::buf_free(vbo_id_);
    vbo_id_ = 0;
    memory_usage -= vbo_size_;
  }

  MEM_SAFE_FREE(data);
}

void GLVertBuf::duplicate_data(VertBuf *dst_)
{
  BLI_assert(GLContext::get() != NULL);
  GLVertBuf *src = this;
  GLVertBuf *dst = static_cast<GLVertBuf *>(dst_);

  if (src->vbo_id_ != 0) {
    dst->vbo_size_ = src->size_used_get();

    glGenBuffers(1, &dst->vbo_id_);
    glBindBuffer(GL_COPY_WRITE_BUFFER, dst->vbo_id_);
    glBufferData(GL_COPY_WRITE_BUFFER, dst->vbo_size_, NULL, to_gl(dst->usage_));

    glBindBuffer(GL_COPY_READ_BUFFER, src->vbo_id_);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, dst->vbo_size_);

    memory_usage += dst->vbo_size_;
  }

  if (data != nullptr) {
    dst->data = (uchar *)MEM_dupallocN(src->data);
  }
}

void GLVertBuf::upload_data(void)
{
  this->bind();
}

void GLVertBuf::bind(void)
{
  BLI_assert(GLContext::get() != NULL);

  if (vbo_id_ == 0) {
    glGenBuffers(1, &vbo_id_);
  }

  glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);

  if (flag & GPU_VERTBUF_DATA_DIRTY) {
    vbo_size_ = this->size_used_get();
    /* Orphan the vbo to avoid sync then upload data. */
    glBufferData(GL_ARRAY_BUFFER, vbo_size_, NULL, to_gl(usage_));
    glBufferSubData(GL_ARRAY_BUFFER, 0, vbo_size_, data);

    memory_usage += vbo_size_;

    if (usage_ == GPU_USAGE_STATIC) {
      MEM_SAFE_FREE(data);
    }
    flag &= ~GPU_VERTBUF_DATA_DIRTY;
    flag |= GPU_VERTBUF_DATA_UPLOADED;
  }
}

void GLVertBuf::update_sub(uint start, uint len, void *data)
{
  glBufferSubData(GL_ARRAY_BUFFER, start, len, data);
}

}  // namespace blender::gpu