/** \file
 * \ingroup gpu
 *
 * Mimics old style opengl immediate mode drawing.
 */

#pragma once

#include "GPU_batch.h"
#include "GPU_primitive.h"
#include "GPU_shader.h"
#include "GPU_vertex_format.h"

namespace blender::gpu {

class Immediate {
 public:
  /** Pointer to the mapped buffer data for the currect vertex. */
  uchar *vertex_data = NULL;
  /** Current vertex index. */
  uint vertex_idx = 0;
  /** Length of the buffer in vertices. */
  uint vertex_len = 0;
  /** Which attributes of current vertex have not been given values? */
  uint16_t unassigned_attr_bits = 0;
  /** Attributes that needs to be set. One bit per attribute. */
  uint16_t enabled_attr_bits = 0;

  /** Current draw call specification. */
  GPUPrimType prim_type = GPU_PRIM_NONE;
  GPUVertFormat vertex_format;
  GPUShader *shader = NULL;
  /** Enforce strict vertex count (disabled when using immBeginAtMost). */
  bool strict_vertex_len = true;

  /** Batch in construction when using immBeginBatch. */
  GPUBatch *batch = NULL;

 public:
  Immediate(){};
  virtual ~Immediate(){};

  virtual uchar *begin(void) = 0;
  virtual void end(void) = 0;
};

}  // namespace blender::gpu

void immActivate(void);
void immDeactivate(void);