/** \file
 * \ingroup gpu
 */

#include "gl_context.hh"
#include "gl_debug.hh"

#include "gl_index_buffer.hh"

namespace blender::gpu {

GLIndexBuf::~GLIndexBuf()
{
  GLContext::buf_free(ibo_id_);
}

void GLIndexBuf::bind(void)
{
  if (is_subrange_) {
    static_cast<GLIndexBuf *>(src_)->bind();
    return;
  }

  if (ibo_id_ == 0) {
    glGenBuffers(1, &ibo_id_);

    if (data_ == nullptr) {
      debug::raise_gl_error("Trying to use Index Buffer but the buffer contains no data");
    }
  }

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_id_);

  if (data_ != nullptr) {
    size_t size = this->size_get();
    /* Sends data to GPU. */
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data_, GL_STATIC_DRAW);
    /* No need to keep copy of data in system memory. */
    MEM_SAFE_FREE(data_);
  }
}

}  // namespace blender::gpu