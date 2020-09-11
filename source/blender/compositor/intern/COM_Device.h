/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_WorkPackage.h"

/**
 * \brief Abstract class for device implementations to be used by the Compositor.
 * devices are queried, initialized and used by the WorkScheduler.
 * work are packaged as a WorkPackage instance.
 */
class Device {

 public:
  /**
   * \brief Declaration of the virtual destructor
   * \note resolve warning gcc 4.7
   */
  virtual ~Device()
  {
  }

  /**
   * \brief initialize the device
   */
  virtual bool initialize()
  {
    return true;
  }

  /**
   * \brief deinitialize the device
   */
  virtual void deinitialize()
  {
  }

  /**
   * \brief execute a WorkPackage
   * \param work: the WorkPackage to execute
   */
  virtual void execute(WorkPackage *work) = 0;

#ifdef WITH_CXX_GUARDEDALLOC
  MEM_CXX_CLASS_ALLOC_FUNCS("COM:Device")
#endif
};
