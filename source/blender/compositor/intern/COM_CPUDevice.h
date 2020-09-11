/** Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_Device.h"

/**
 * \brief class representing a CPU device.
 * \note for every hardware thread in the system a CPUDevice instance
 * will exist in the workscheduler.
 */
class CPUDevice : public Device {
 public:
  CPUDevice(int thread_id);

  /**
   * \brief execute a WorkPackage
   * \param work: the WorkPackage to execute
   */
  void execute(WorkPackage *work);

  int thread_id()
  {
    return m_thread_id;
  }

 protected:
  int m_thread_id;
};
