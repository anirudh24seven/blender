/** \file
 * \ingroup depsgraph
 *
 * Evaluation engine entry-points for Depsgraph Engine.
 */

#include "MEM_guardedalloc.h"

#include "BLI_listbase.h"
#include "BLI_utildefines.h"

#include "BKE_scene.h"

#include "DNA_object_types.h"
#include "DNA_scene_types.h"

#include "DEG_depsgraph.h"
#include "DEG_depsgraph_query.h"

#include "intern/eval/deg_eval.h"
#include "intern/eval/deg_eval_flush.h"

#include "intern/node/deg_node.h"
#include "intern/node/deg_node_operation.h"
#include "intern/node/deg_node_time.h"

#include "intern/depsgraph.h"

namespace deg = blender::deg;

static void deg_flush_updates_and_refresh(deg::Depsgraph *deg_graph)
{
  /* Update the time on the cow scene. */
  if (deg_graph->scene_cow) {
    BKE_scene_frame_set(deg_graph->scene_cow, deg_graph->ctime);
  }

  deg::deg_graph_flush_updates(deg_graph);
  deg::deg_evaluate_on_refresh(deg_graph);
}

/* Evaluate all nodes tagged for updating. */
void DEG_evaluate_on_refresh(Depsgraph *graph)
{
  deg::Depsgraph *deg_graph = reinterpret_cast<deg::Depsgraph *>(graph);
  const Scene *scene = DEG_get_input_scene(graph);
  const float ctime = BKE_scene_frame_get(scene);

  if (ctime != deg_graph->ctime) {
    deg_graph->tag_time_source();
    deg_graph->ctime = ctime;
  }

  deg_flush_updates_and_refresh(deg_graph);
}

/* Frame-change happened for root scene that graph belongs to. */
void DEG_evaluate_on_framechange(Depsgraph *graph, float ctime)
{
  deg::Depsgraph *deg_graph = reinterpret_cast<deg::Depsgraph *>(graph);
  deg_graph->tag_time_source();
  deg_graph->ctime = ctime;
  deg_flush_updates_and_refresh(deg_graph);
}
