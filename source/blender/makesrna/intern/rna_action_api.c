/** \file
 * \ingroup RNA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "BLI_utildefines.h"

#include "RNA_define.h"

#include "DNA_action_types.h"

#include "rna_internal.h" /* own include */

#ifdef RNA_RUNTIME

#  include "BKE_action.h"

#  include "DNA_anim_types.h"
#  include "DNA_curve_types.h"

#else

void RNA_api_action(StructRNA *UNUSED(srna))
{
}

#endif
