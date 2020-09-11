/** \file
 * \ingroup depsgraph
 */

#pragma once

struct Sequence;

namespace blender {
namespace deg {

struct Depsgraph;

/* Backup of a single strip. */
class SequenceBackup {
 public:
  SequenceBackup(const Depsgraph *depsgraph);

  void reset();

  void init_from_sequence(Sequence *sequence);
  void restore_to_sequence(Sequence *sequence);

  bool isEmpty() const;

  void *scene_sound;
};

}  // namespace deg
}  // namespace blender
