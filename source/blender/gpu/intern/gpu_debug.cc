/** \file
 * \ingroup gpu
 */

#include "BLI_compiler_attrs.h"
#include "BLI_sys_types.h"
#include "BLI_system.h"
#include "BLI_utildefines.h"

#include "BKE_global.h"

#include "GPU_debug.h"
#include "GPU_glew.h"
#include "intern/gpu_private.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GPU_print_error_debug(const char *str)
{
  if (G.debug & G_DEBUG) {
    fprintf(stderr, "GPU: %s\n", str);
  }
}
