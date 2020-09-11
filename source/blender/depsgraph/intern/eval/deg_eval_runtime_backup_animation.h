/** \file
 * \ingroup depsgraph
 */

#pragma once

#include "BKE_modifier.h"

#include "intern/depsgraph_type.h"

namespace blender {
namespace deg {

struct Depsgraph;

class AnimationValueBackup {
 public:
  AnimationValueBackup();
  AnimationValueBackup(const string &rna_path, int array_index, float value);
  ~AnimationValueBackup();

  AnimationValueBackup(const AnimationValueBackup &other) = default;
  AnimationValueBackup(AnimationValueBackup &&other) noexcept = default;

  AnimationValueBackup &operator=(const AnimationValueBackup &other) = default;
  AnimationValueBackup &operator=(AnimationValueBackup &&other) = default;

  string rna_path;
  int array_index;
  float value;
};

/* Backup of animated properties values. */
class AnimationBackup {
 public:
  AnimationBackup(const Depsgraph *depsgraph);

  void reset();

  void init_from_id(ID *id);
  void restore_to_id(ID *id);

  bool meed_value_backup;
  Vector<AnimationValueBackup> values_backup;
};

}  // namespace deg
}  // namespace blender
