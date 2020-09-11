#pragma once

#include "COM_NodeOperation.h"

class CryptomatteOperation : public NodeOperation {
 private:
  std::vector<float> m_objectIndex;

 public:
  std::vector<SocketReader *> inputs;

  CryptomatteOperation(size_t num_inputs = 6);

  void initExecution();
  void executePixel(float output[4], int x, int y, void *data);

  void addObjectIndex(float objectIndex);
};
