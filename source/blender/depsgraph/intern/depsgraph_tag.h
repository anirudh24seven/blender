/** \file
 * \ingroup depsgraph
 */

#include "intern/node/deg_node.h"

struct ID;
struct Main;

namespace blender {
namespace deg {

struct Depsgraph;

/* Get type of a node which corresponds to a ID_RECALC_GEOMETRY tag.  */
NodeType geometry_tag_to_component(const ID *id);

/* Tag given ID for an update in all registered dependency graphs. */
void id_tag_update(Main *bmain, ID *id, int flag, eUpdateSource update_source);

/* Tag given ID for an update with in a given dependency graph. */
void graph_id_tag_update(
    Main *bmain, Depsgraph *graph, ID *id, int flag, eUpdateSource update_source);

}  // namespace deg
}  // namespace blender
