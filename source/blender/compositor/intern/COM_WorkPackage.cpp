/** Copyright 2011, Blender Foundation.
 */

#include "COM_WorkPackage.h"

WorkPackage::WorkPackage(ExecutionGroup *group, unsigned int chunkNumber)
{
  this->m_executionGroup = group;
  this->m_chunkNumber = chunkNumber;
}
