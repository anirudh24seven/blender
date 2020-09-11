/** \file
 * \ingroup imbdds
 */

/*
 * This file is based on a similar file from the NVIDIA texture tools
 * (http://nvidia-texture-tools.googlecode.com/)
 *
 * Original license from NVIDIA follows.
 */

// This code is in the public domain -- castanyo@yahoo.es

#pragma once

#include <Color.h>
#include <Image.h>

/// Uncompressed 4x4 color block.
struct ColorBlock {
  ColorBlock();
  ColorBlock(const uint *linearImage);
  ColorBlock(const ColorBlock &block);
  ColorBlock(const Image *img, uint x, uint y);

  void init(const Image *img, uint x, uint y);
  void init(uint w, uint h, const uint *data, uint x, uint y);
  void init(uint w, uint h, const float *data, uint x, uint y);

  void swizzle(uint x, uint y, uint z, uint w);  // 0=r, 1=g, 2=b, 3=a, 4=0xFF, 5=0

  bool isSingleColor(Color32 mask = Color32(0xFF, 0xFF, 0xFF, 0x00)) const;
  bool hasAlpha() const;

  // Accessors
  const Color32 *colors() const;

  Color32 color(uint i) const;
  Color32 &color(uint i);

  Color32 color(uint x, uint y) const;
  Color32 &color(uint x, uint y);

 private:
  Color32 m_color[4 * 4];
};

/// Get pointer to block colors.
inline const Color32 *ColorBlock::colors() const
{
  return m_color;
}

/// Get block color.
inline Color32 ColorBlock::color(uint i) const
{
  return m_color[i];
}

/// Get block color.
inline Color32 &ColorBlock::color(uint i)
{
  return m_color[i];
}

/// Get block color.
inline Color32 ColorBlock::color(uint x, uint y) const
{
  return m_color[y * 4 + x];
}

/// Get block color.
inline Color32 &ColorBlock::color(uint x, uint y)
{
  return m_color[y * 4 + x];
}
