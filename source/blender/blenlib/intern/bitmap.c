/** The Original Code is Copyright (C) 2012 by Nicholas Bishop
 * All rights reserved.
 */

/** \file
 * \ingroup bli
 *
 * Utility functions for variable size bit-masks.
 */

#include <limits.h>
#include <string.h>

#include "BLI_bitmap.h"
#include "BLI_utildefines.h"

/** Set or clear all bits in the bitmap. */
void BLI_bitmap_set_all(BLI_bitmap *bitmap, bool set, size_t bits)
{
  memset(bitmap, set ? UCHAR_MAX : 0, BLI_BITMAP_SIZE(bits));
}

/** Invert all bits in the bitmap. */
void BLI_bitmap_flip_all(BLI_bitmap *bitmap, size_t bits)
{
  size_t num_blocks = _BITMAP_NUM_BLOCKS(bits);
  for (size_t i = 0; i < num_blocks; i++) {
    bitmap[i] ^= ~(BLI_bitmap)0;
  }
}

/** Copy all bits from one bitmap to another. */
void BLI_bitmap_copy_all(BLI_bitmap *dst, const BLI_bitmap *src, size_t bits)
{
  memcpy(dst, src, BLI_BITMAP_SIZE(bits));
}

/** Combine two bitmaps with boolean AND. */
void BLI_bitmap_and_all(BLI_bitmap *dst, const BLI_bitmap *src, size_t bits)
{
  size_t num_blocks = _BITMAP_NUM_BLOCKS(bits);
  for (size_t i = 0; i < num_blocks; i++) {
    dst[i] &= src[i];
  }
}

/** Combine two bitmaps with boolean OR. */
void BLI_bitmap_or_all(BLI_bitmap *dst, const BLI_bitmap *src, size_t bits)
{
  size_t num_blocks = _BITMAP_NUM_BLOCKS(bits);
  for (size_t i = 0; i < num_blocks; i++) {
    dst[i] |= src[i];
  }
}
