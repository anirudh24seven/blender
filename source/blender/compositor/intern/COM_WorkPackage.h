/** Copyright 2011, Blender Foundation.
 */

class WorkPackage;

#pragma once

class ExecutionGroup;
#include "COM_ExecutionGroup.h"

/**
 * \brief contains data about work that can be scheduled
 * \see WorkScheduler
 */
class WorkPackage {
 private:
  /**
   * \brief executionGroup with the operations-setup to be evaluated
   */
  ExecutionGroup *m_executionGroup;

  /**
   * \brief number of the chunk to be executed
   */
  unsigned int m_chunkNumber;

 public:
  /**
   * constructor
   * \param group: the ExecutionGroup
   * \param chunkNumber: the number of the chunk
   */
  WorkPackage(ExecutionGroup *group, unsigned int chunkNumber);

  /**
   * \brief get the ExecutionGroup
   */
  ExecutionGroup *getExecutionGroup() const
  {
    return this->m_executionGroup;
  }

  /**
   * \brief get the number of the chunk
   */
  unsigned int getChunkNumber() const
  {
    return this->m_chunkNumber;
  }

#ifdef WITH_CXX_GUARDEDALLOC
  MEM_CXX_CLASS_ALLOC_FUNCS("COM:WorkPackage")
#endif
};
