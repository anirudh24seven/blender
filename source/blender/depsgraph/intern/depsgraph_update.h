/** \file
 * \ingroup depsgraph
 */

#pragma once

struct DEGEditorUpdateContext;
struct ID;

namespace blender {
namespace deg {

void deg_editors_id_update(const DEGEditorUpdateContext *update_ctx, struct ID *id);

void deg_editors_scene_update(const DEGEditorUpdateContext *update_ctx, bool updated);

}  // namespace deg
}  // namespace blender
