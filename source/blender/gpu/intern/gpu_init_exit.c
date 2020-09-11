/** \file
 * \ingroup gpu
 */

#include "GPU_init_exit.h" /* interface */
#include "BKE_global.h"
#include "BLI_sys_types.h"
#include "GPU_batch.h"
#include "GPU_buffers.h"
#include "GPU_context.h"
#include "GPU_immediate.h"

#include "intern/gpu_codegen.h"
#include "intern/gpu_material_library.h"
#include "intern/gpu_private.h"

/**
 * although the order of initialization and shutdown should not matter
 * (except for the extensions), I chose alphabetical and reverse alphabetical order
 */

static bool initialized = false;

void GPU_init(void)
{
  /* can't avoid calling this multiple times, see wm_window_ghostwindow_add */
  if (initialized) {
    return;
  }

  initialized = true;

  gpu_codegen_init();
  gpu_material_library_init();

  gpu_batch_init();

#ifndef GPU_STANDALONE
  gpu_pbvh_init();
#endif
}

void GPU_exit(void)
{
#ifndef GPU_STANDALONE
  gpu_pbvh_exit();
#endif

  gpu_batch_exit();

  gpu_material_library_exit();
  gpu_codegen_exit();

  initialized = false;
}

bool GPU_is_init(void)
{
  return initialized;
}
