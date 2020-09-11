/** \file
 * \ingroup imbuf
 */

#include <stddef.h>

#include "BLI_utildefines.h"

#include "IMB_filetype.h"
#include "IMB_imbuf.h"
#include "IMB_imbuf_types.h"

#include "IMB_colormanagement.h"

#ifdef WITH_OPENIMAGEIO
#  include "oiio/openimageio_api.h"
#endif

#ifdef WITH_OPENEXR
#  include "openexr/openexr_api.h"
#endif

#ifdef WITH_DDS
#  include "dds/dds_api.h"
#endif

static int imb_ftype_default(const ImFileType *type, const ImBuf *ibuf)
{
  return (ibuf->ftype == type->filetype);
}
static int imb_ftype_iris(const ImFileType *type, const ImBuf *ibuf)
{
  (void)type;
  return (ibuf->ftype == IMB_FTYPE_IMAGIC);
}

const ImFileType IMB_FILE_TYPES[] = {
    {NULL,
     NULL,
     imb_is_a_jpeg,
     NULL,
     imb_ftype_default,
     imb_load_jpeg,
     NULL,
     imb_savejpeg,
     NULL,
     0,
     IMB_FTYPE_JPG,
     COLOR_ROLE_DEFAULT_BYTE},
    {NULL,
     NULL,
     imb_is_a_png,
     NULL,
     imb_ftype_default,
     imb_loadpng,
     NULL,
     imb_savepng,
     NULL,
     0,
     IMB_FTYPE_PNG,
     COLOR_ROLE_DEFAULT_BYTE},
    {NULL,
     NULL,
     imb_is_a_bmp,
     NULL,
     imb_ftype_default,
     imb_bmp_decode,
     NULL,
     imb_savebmp,
     NULL,
     0,
     IMB_FTYPE_BMP,
     COLOR_ROLE_DEFAULT_BYTE},
    {NULL,
     NULL,
     imb_is_a_targa,
     NULL,
     imb_ftype_default,
     imb_loadtarga,
     NULL,
     imb_savetarga,
     NULL,
     0,
     IMB_FTYPE_TGA,
     COLOR_ROLE_DEFAULT_BYTE},
    {NULL,
     NULL,
     imb_is_a_iris,
     NULL,
     imb_ftype_iris,
     imb_loadiris,
     NULL,
     imb_saveiris,
     NULL,
     0,
     IMB_FTYPE_IMAGIC,
     COLOR_ROLE_DEFAULT_BYTE},
#ifdef WITH_CINEON
    {NULL,
     NULL,
     imb_is_dpx,
     NULL,
     imb_ftype_default,
     imb_load_dpx,
     NULL,
     imb_save_dpx,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_DPX,
     COLOR_ROLE_DEFAULT_FLOAT},
    {NULL,
     NULL,
     imb_is_cineon,
     NULL,
     imb_ftype_default,
     imb_load_cineon,
     NULL,
     imb_save_cineon,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_CINEON,
     COLOR_ROLE_DEFAULT_FLOAT},
#endif
#ifdef WITH_TIFF
    {imb_inittiff,
     NULL,
     imb_is_a_tiff,
     NULL,
     imb_ftype_default,
     imb_loadtiff,
     NULL,
     imb_savetiff,
     imb_loadtiletiff,
     0,
     IMB_FTYPE_TIF,
     COLOR_ROLE_DEFAULT_BYTE},
#endif
#ifdef WITH_HDR
    {NULL,
     NULL,
     imb_is_a_hdr,
     NULL,
     imb_ftype_default,
     imb_loadhdr,
     NULL,
     imb_savehdr,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_RADHDR,
     COLOR_ROLE_DEFAULT_FLOAT},
#endif
#ifdef WITH_OPENEXR
    {imb_initopenexr,
     imb_exitopenexr,
     imb_is_a_openexr,
     NULL,
     imb_ftype_default,
     imb_load_openexr,
     NULL,
     imb_save_openexr,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_OPENEXR,
     COLOR_ROLE_DEFAULT_FLOAT},
#endif
#ifdef WITH_OPENJPEG
    {NULL,
     NULL,
     imb_is_a_jp2,
     NULL,
     imb_ftype_default,
     imb_load_jp2,
     NULL,
     imb_save_jp2,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_JP2,
     COLOR_ROLE_DEFAULT_BYTE},
#endif
#ifdef WITH_DDS
    {NULL,
     NULL,
     imb_is_a_dds,
     NULL,
     imb_ftype_default,
     imb_load_dds,
     NULL,
     NULL,
     NULL,
     0,
     IMB_FTYPE_DDS,
     COLOR_ROLE_DEFAULT_BYTE},
#endif
#ifdef WITH_OPENIMAGEIO
    {NULL,
     NULL,
     NULL,
     imb_is_a_photoshop,
     imb_ftype_default,
     NULL,
     imb_load_photoshop,
     NULL,
     NULL,
     IM_FTYPE_FLOAT,
     IMB_FTYPE_PSD,
     COLOR_ROLE_DEFAULT_FLOAT},
#endif
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0},
};

const ImFileType *IMB_FILE_TYPES_LAST = &IMB_FILE_TYPES[ARRAY_SIZE(IMB_FILE_TYPES) - 1];

void imb_filetypes_init(void)
{
  const ImFileType *type;

  for (type = IMB_FILE_TYPES; type < IMB_FILE_TYPES_LAST; type++) {
    if (type->init) {
      type->init();
    }
  }
}

void imb_filetypes_exit(void)
{
  const ImFileType *type;

  for (type = IMB_FILE_TYPES; type < IMB_FILE_TYPES_LAST; type++) {
    if (type->exit) {
      type->exit();
    }
  }
}
