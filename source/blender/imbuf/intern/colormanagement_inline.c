/** The Original Code is Copyright (C) 2015 by Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup imbuf
 */

#ifndef __IMB_COLORMANAGEMENT_INLINE_C__
#define __IMB_COLORMANAGEMENT_INLINE_C__

#include "BLI_math_vector.h"
#include "IMB_colormanagement_intern.h"

/* Convert a float RGB triplet to the correct luminance weighted average.
 *
 * Grayscale, or Luma is a distillation of RGB data values down to a weighted average
 * based on the luminance positions of the red, green, and blue primaries.
 * Given that the internal reference space may be arbitrarily set, any
 * effort to glean the luminance coefficients must be aware of the reference
 * space primaries.
 *
 * See http://wiki.blender.org/index.php/User:Nazg-gul/ColorManagement#Luminance
 */

float IMB_colormanagement_get_luminance(const float rgb[3])
{
  return dot_v3v3(imbuf_luma_coefficients, rgb);
}

/* Byte equivalent of IMB_colormanagement_get_luminance(). */
unsigned char IMB_colormanagement_get_luminance_byte(const unsigned char rgb[3])
{
  float rgbf[3];
  float val;

  rgb_uchar_to_float(rgbf, rgb);
  val = dot_v3v3(imbuf_luma_coefficients, rgbf);

  return unit_float_to_uchar_clamp(val);
}

void IMB_colormangement_xyz_to_rgb(float rgb[3], const float xyz[3])
{
  mul_v3_m3v3(rgb, imbuf_xyz_to_rgb, xyz);
}

void IMB_colormangement_rgb_to_xyz(float xyz[3], const float rgb[3])
{
  mul_v3_m3v3(xyz, imbuf_rgb_to_xyz, rgb);
}

#endif /* __IMB_COLORMANAGEMENT_INLINE_H__ */
