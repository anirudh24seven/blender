/** Copyright 2011, Blender Foundation.
 */

#include "COM_CPUDevice.h"

CPUDevice::CPUDevice(int thread_id) : Device(), m_thread_id(thread_id)
{
}

void CPUDevice::execute(WorkPackage *work)
{
  const unsigned int chunkNumber = work->getChunkNumber();
  ExecutionGroup *executionGroup = work->getExecutionGroup();
  rcti rect;

  executionGroup->determineChunkRect(&rect, chunkNumber);

  executionGroup->getOutputOperation()->executeRegion(&rect, chunkNumber);

  executionGroup->finalizeChunkExecution(chunkNumber, NULL);
}
