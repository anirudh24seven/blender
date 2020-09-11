/** Copyright 2011, Blender Foundation.
 */

#include "COM_CompositorContext.h"
#include "COM_defines.h"
#include <stdio.h>

CompositorContext::CompositorContext()
{
  this->m_scene = NULL;
  this->m_rd = NULL;
  this->m_quality = COM_QUALITY_HIGH;
  this->m_hasActiveOpenCLDevices = false;
  this->m_fastCalculation = false;
  this->m_viewSettings = NULL;
  this->m_displaySettings = NULL;
}

int CompositorContext::getFramenumber() const
{
  if (this->m_rd) {
    return this->m_rd->cfra;
  }

  return -1; /* this should never happen */
}
