/** \file
 * \ingroup depsgraph
 */

#pragma once

#include "BKE_modifier.h"

struct ModifierData;

namespace blender {
namespace deg {

class ModifierDataBackup {
 public:
  explicit ModifierDataBackup(ModifierData *modifier_data);

  ModifierType type;
  void *runtime;
};

}  // namespace deg
}  // namespace blender
