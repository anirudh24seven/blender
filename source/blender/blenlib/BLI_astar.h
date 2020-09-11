#pragma once

/** \file
 * \ingroup bli
 * \brief An implementation of the A* (AStar) algorithm to solve shortest path problem.
 */

#include "BLI_utildefines.h"

#include "BLI_bitmap.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------- */

typedef struct BLI_AStarGNLink {
  int nodes[2];
  float cost;

  void *custom_data;
} BLI_AStarGNLink;

typedef struct BLI_AStarGNode {
  struct ListBase neighbor_links;

  void *custom_data;
} BLI_AStarGNode;

typedef struct BLI_AStarSolution {
  /* Final 'most useful' data. */
  /** Number of steps (i.e. walked links) in path
   * (nodes num, including start and end, is steps + 1). */
  int steps;
  /** Store the path, in reversed order (from destination to source node), as indices. */
  int *prev_nodes;
  /** Indices are nodes' ones, as prev_nodes, but they map to relevant link. */
  BLI_AStarGNLink **prev_links;

  void *custom_data;

  /* Mostly runtime data. */
  BLI_bitmap *done_nodes;
  float *g_costs;
  int *g_steps;

  struct MemArena *mem; /* Memory arena. */
} BLI_AStarSolution;

typedef struct BLI_AStarGraph {
  int node_num;
  BLI_AStarGNode *nodes;

  void *custom_data;

  struct MemArena *mem; /* Memory arena. */
} BLI_AStarGraph;

void BLI_astar_node_init(BLI_AStarGraph *as_graph, const int node_index, void *custom_data);
void BLI_astar_node_link_add(BLI_AStarGraph *as_graph,
                             const int node1_index,
                             const int node2_index,
                             const float cost,
                             void *custom_data);
int BLI_astar_node_link_other_node(BLI_AStarGNLink *lnk, const int idx);

void BLI_astar_solution_init(BLI_AStarGraph *as_graph,
                             BLI_AStarSolution *as_solution,
                             void *custom_data);
void BLI_astar_solution_clear(BLI_AStarSolution *as_solution);
void BLI_astar_solution_free(BLI_AStarSolution *as_solution);

/**
 * Callback computing the current cost (distance) to next node,
 * and the estimated overall cost to destination node
 * (A* expects this estimation to always be less or equal than actual shortest path
 * from next node to destination one).
 *
 * \param link: the graph link between current node and next one.
 * \param node_idx_curr: current node index.
 * \param node_idx_next: next node index.
 * \param node_idx_dst: destination node index.
 */
typedef float (*astar_f_cost)(BLI_AStarGraph *as_graph,
                              BLI_AStarSolution *as_solution,
                              BLI_AStarGNLink *link,
                              const int node_idx_curr,
                              const int node_idx_next,
                              const int node_idx_dst);

void BLI_astar_graph_init(BLI_AStarGraph *as_graph, const int node_num, void *custom_data);
void BLI_astar_graph_free(BLI_AStarGraph *as_graph);
bool BLI_astar_graph_solve(BLI_AStarGraph *as_graph,
                           const int node_index_src,
                           const int node_index_dst,
                           astar_f_cost f_cost_cb,
                           BLI_AStarSolution *r_solution,
                           const int max_steps);

#ifdef __cplusplus
}
#endif
