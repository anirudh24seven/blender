/** \file
 * \ingroup gpu
 */

#include "gl_query.hh"

namespace blender::gpu {

#define QUERY_CHUNCK_LEN 256

GLQueryPool::~GLQueryPool()
{
  glDeleteQueries(query_ids_.size(), query_ids_.data());
}

void GLQueryPool::init(GPUQueryType type)
{
  BLI_assert(initialized_ == false);
  initialized_ = true;
  type_ = type;
  gl_type_ = to_gl(type);
  query_issued_ = 0;
}

#if 0 /* TODO to avoid realloc of permanent query pool. */
void GLQueryPool::reset(GPUQueryType type)
{
  initialized_ = false;
}
#endif

void GLQueryPool::begin_query(void)
{
  /* TODO add assert about expected usage. */
  while (query_issued_ >= query_ids_.size()) {
    int64_t prev_size = query_ids_.size();
    query_ids_.resize(prev_size + QUERY_CHUNCK_LEN);
    glGenQueries(QUERY_CHUNCK_LEN, &query_ids_[prev_size]);
  }
  glBeginQuery(gl_type_, query_ids_[query_issued_++]);
}

void GLQueryPool::end_query(void)
{
  /* TODO add assert about expected usage. */
  glEndQuery(gl_type_);
}

void GLQueryPool::get_occlusion_result(MutableSpan<uint32_t> r_values)
{
  BLI_assert(r_values.size() == query_issued_);

  for (int i = 0; i < query_issued_; i++) {
    /* Note: This is a sync point. */
    glGetQueryObjectuiv(query_ids_[i], GL_QUERY_RESULT, &r_values[i]);
  }
}

}  // namespace blender::gpu
