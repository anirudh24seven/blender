/** \file
 * \ingroup freestyle
 * \brief Classes to render a stroke with OpenGL
 */

#include "StrokeRenderer.h"

#include "../geometry/GeomUtils.h"

using namespace std;

namespace Freestyle {

/**********************************/
/*                                */
/*                                */
/*         StrokeRenderer         */
/*                                */
/*                                */
/**********************************/

TextureManager *StrokeRenderer::_textureManager = 0;

StrokeRenderer::StrokeRenderer()
{
}

StrokeRenderer::~StrokeRenderer()
{
}

bool StrokeRenderer::loadTextures()
{
  _textureManager->load();
  return true;
}

/**********************************/
/*                                */
/*                                */
/*         TextureManager         */
/*                                */
/*                                */
/**********************************/

TextureManager *TextureManager::_pInstance = 0;

string TextureManager::_patterns_path;

string TextureManager::_brushes_path;

TextureManager::TextureManager()
{
  _hasLoadedTextures = false;
  _pInstance = this;
  _defaultTextureId = 0;
}

TextureManager::~TextureManager()
{
  if (!_brushesMap.empty()) {
    _brushesMap.clear();
  }
  _pInstance = 0;
}

void TextureManager::load()
{
  if (_hasLoadedTextures) {
    return;
  }
  loadStandardBrushes();
  _hasLoadedTextures = true;
}

unsigned TextureManager::getBrushTextureIndex(string name, Stroke::MediumType iType)
{
  BrushTexture bt(name, iType);
  brushesMap::iterator b = _brushesMap.find(bt);
  if (b == _brushesMap.end()) {
    unsigned texId = loadBrush(name, iType);
    _brushesMap[bt] = texId;
    return texId;
    // XXX!
    cerr << "brush file " << name << " not found" << endl;
    return 0;
  }

  return _brushesMap[bt];
}

void TextureManager::Options::setPatternsPath(const string &path)
{
  _patterns_path = path;
}

string TextureManager::Options::getPatternsPath()
{
  return _patterns_path;
}

void TextureManager::Options::setBrushesPath(const string &path)
{
  _brushes_path = path;
}

string TextureManager::Options::getBrushesPath()
{
  return _brushes_path;
}

} /* namespace Freestyle */
