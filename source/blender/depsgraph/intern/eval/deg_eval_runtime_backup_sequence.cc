/** \file
 * \ingroup depsgraph
 */

#include "intern/eval/deg_eval_runtime_backup_sequence.h"

#include "DNA_sequence_types.h"

namespace blender {
namespace deg {

SequenceBackup::SequenceBackup(const Depsgraph * /*depsgraph*/)
{
  reset();
}

void SequenceBackup::reset()
{
  scene_sound = nullptr;
}

void SequenceBackup::init_from_sequence(Sequence *sequence)
{
  scene_sound = sequence->scene_sound;

  sequence->scene_sound = nullptr;
}

void SequenceBackup::restore_to_sequence(Sequence *sequence)
{
  sequence->scene_sound = scene_sound;
  reset();
}

bool SequenceBackup::isEmpty() const
{
  return (scene_sound == nullptr);
}

}  // namespace deg
}  // namespace blender
