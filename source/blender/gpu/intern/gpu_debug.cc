/** \file
 * \ingroup gpu
 *
 * Debug features of OpenGL.
 */

#include "BKE_global.h"

#include "BLI_string.h"

#include "gpu_context_private.hh"

#include "GPU_debug.h"

using namespace blender;
using namespace blender::gpu;

void GPU_debug_group_begin(const char *name)
{
  if (!(G.debug & G_DEBUG_GPU)) {
    return;
  }
  Context *ctx = Context::get();
  DebugStack &stack = ctx->debug_stack;
  stack.append(StringRef(name));
  ctx->debug_group_begin(name, stack.size());
}

void GPU_debug_group_end(void)
{
  if (!(G.debug & G_DEBUG_GPU)) {
    return;
  }
  Context *ctx = Context::get();
  ctx->debug_stack.pop_last();
  ctx->debug_group_end();
}

/**
 * Return a formatted string showing the current group hierarchy in this format:
 * "Group1 > Group 2 > Group3 > ... > GroupN : "
 */
void GPU_debug_get_groups_names(int name_buf_len, char *r_name_buf)
{
  Context *ctx = Context::get();
  if (ctx == nullptr) {
    return;
  }
  DebugStack &stack = ctx->debug_stack;
  if (stack.size() == 0) {
    r_name_buf[0] = '\0';
    return;
  }
  size_t sz = 0;
  for (StringRef &name : stack) {
    sz += BLI_snprintf_rlen(r_name_buf + sz, name_buf_len - sz, "%s > ", name.data());
  }
  r_name_buf[sz - 2] = ':';
}

/* Return true if inside a debug group with the same name. */
bool GPU_debug_group_match(const char *ref)
{
  /* Otherwise there will be no names. */
  BLI_assert(G.debug & G_DEBUG_GPU);
  Context *ctx = Context::get();
  if (ctx == nullptr) {
    return false;
  }
  DebugStack &stack = ctx->debug_stack;
  for (StringRef &name : stack) {
    if (STREQ(name.data(), ref)) {
      return true;
    }
  }
  return false;
}
