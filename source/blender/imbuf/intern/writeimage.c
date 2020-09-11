/** The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 * writeimage.c
 */

/** \file
 * \ingroup imbuf
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "BLI_path_util.h"
#include "BLI_utildefines.h"

#include "IMB_filetype.h"
#include "IMB_imbuf.h"
#include "IMB_imbuf_types.h"

#include "IMB_colormanagement.h"
#include "IMB_colormanagement_intern.h"

static bool prepare_write_imbuf(const ImFileType *type, ImBuf *ibuf)
{
  return IMB_prepare_write_ImBuf((type->flag & IM_FTYPE_FLOAT), ibuf);
}

short IMB_saveiff(struct ImBuf *ibuf, const char *filepath, int flags)
{
  const ImFileType *type;

  errno = 0;

  BLI_assert(!BLI_path_is_rel(filepath));

  if (ibuf == NULL) {
    return false;
  }
  ibuf->flags = flags;

  for (type = IMB_FILE_TYPES; type < IMB_FILE_TYPES_LAST; type++) {
    if (type->save && type->ftype(type, ibuf)) {
      short result = false;

      prepare_write_imbuf(type, ibuf);

      result = type->save(ibuf, filepath, flags);

      return result;
    }
  }

  fprintf(stderr, "Couldn't save picture.\n");

  return false;
}

bool IMB_prepare_write_ImBuf(const bool isfloat, ImBuf *ibuf)
{
  bool changed = false;

  if (isfloat) {
    /* pass */
  }
  else {
    if (ibuf->rect == NULL && ibuf->rect_float) {
      ibuf->rect_colorspace = colormanage_colorspace_get_roled(COLOR_ROLE_DEFAULT_BYTE);
      IMB_rect_from_float(ibuf);
      if (ibuf->rect != NULL) {
        changed = true;
      }
    }
  }

  return changed;
}
