/** \file
 * \ingroup gpu
 *
 * Intermediate node graph for generating GLSL shaders.
 */

#pragma once

#include "DNA_customdata_types.h"
#include "DNA_listBase.h"

#include "GPU_material.h"
#include "GPU_shader.h"

struct GPUNode;
struct GPUOutput;
struct GPUShader;
struct GPUVertAttrLayers;
struct ListBase;

typedef enum eGPUDataSource {
  GPU_SOURCE_OUTPUT,
  GPU_SOURCE_CONSTANT,
  GPU_SOURCE_UNIFORM,
  GPU_SOURCE_ATTR,
  GPU_SOURCE_BUILTIN,
  GPU_SOURCE_STRUCT,
  GPU_SOURCE_TEX,
  GPU_SOURCE_TEX_TILED_MAPPING,
  GPU_SOURCE_VOLUME_GRID,
  GPU_SOURCE_VOLUME_GRID_TRANSFORM,
} eGPUDataSource;

typedef enum {
  GPU_NODE_LINK_NONE = 0,
  GPU_NODE_LINK_ATTR,
  GPU_NODE_LINK_BUILTIN,
  GPU_NODE_LINK_COLORBAND,
  GPU_NODE_LINK_CONSTANT,
  GPU_NODE_LINK_IMAGE,
  GPU_NODE_LINK_IMAGE_TILED,
  GPU_NODE_LINK_IMAGE_TILED_MAPPING,
  GPU_NODE_LINK_VOLUME_GRID,
  GPU_NODE_LINK_VOLUME_GRID_TRANSFORM,
  GPU_NODE_LINK_OUTPUT,
  GPU_NODE_LINK_UNIFORM,
} GPUNodeLinkType;

struct GPUNode {
  struct GPUNode *next, *prev;

  const char *name;

  /* Internal flag to mark nodes during pruning */
  bool tag;

  ListBase inputs;
  ListBase outputs;
};

struct GPUNodeLink {
  GPUNodeStack *socket;

  GPUNodeLinkType link_type;
  int users; /* Refcount */

  union {
    /* GPU_NODE_LINK_CONSTANT | GPU_NODE_LINK_UNIFORM */
    const float *data;
    /* GPU_NODE_LINK_BUILTIN */
    eGPUBuiltin builtin;
    /* GPU_NODE_LINK_COLORBAND */
    struct GPUTexture **colorband;
    /* GPU_NODE_LINK_VOLUME_GRID */
    struct GPUMaterialVolumeGrid *volume_grid;
    /* GPU_NODE_LINK_OUTPUT */
    struct GPUOutput *output;
    /* GPU_NODE_LINK_ATTR */
    struct GPUMaterialAttribute *attr;
    /* GPU_NODE_LINK_IMAGE_BLENDER */
    struct GPUMaterialTexture *texture;
  };
};

typedef struct GPUOutput {
  struct GPUOutput *next, *prev;

  GPUNode *node;
  eGPUType type;     /* data type = length of vector/matrix */
  GPUNodeLink *link; /* output link */
  int id;            /* unique id as created by code generator */
} GPUOutput;

typedef struct GPUInput {
  struct GPUInput *next, *prev;

  GPUNode *node;
  eGPUType type; /* data-type. */
  GPUNodeLink *link;
  int id; /* unique id as created by code generator */

  eGPUDataSource source; /* data source */

  /* Content based on eGPUDataSource */
  union {
    /* GPU_SOURCE_CONSTANT | GPU_SOURCE_UNIFORM */
    float vec[16]; /* vector data */
    /* GPU_SOURCE_BUILTIN */
    eGPUBuiltin builtin; /* builtin uniform */
    /* GPU_SOURCE_TEX | GPU_SOURCE_TEX_TILED_MAPPING */
    struct GPUMaterialTexture *texture;
    /* GPU_SOURCE_ATTR */
    struct GPUMaterialAttribute *attr;
    /* GPU_SOURCE_VOLUME_GRID | GPU_SOURCE_VOLUME_GRID_TRANSFORM */
    struct GPUMaterialVolumeGrid *volume_grid;
  };
} GPUInput;

typedef struct GPUNodeGraph {
  /* Nodes */
  ListBase nodes;

  /* Output. */
  GPUNodeLink *outlink;

  /* Requested attributes and textures. */
  ListBase attributes;
  ListBase textures;
  ListBase volume_grids;
} GPUNodeGraph;

/* Node Graph */

void gpu_node_graph_prune_unused(GPUNodeGraph *graph);
void gpu_node_graph_free_nodes(GPUNodeGraph *graph);
void gpu_node_graph_free(GPUNodeGraph *graph);

/* Material calls */

struct GPUNodeGraph *gpu_material_node_graph(struct GPUMaterial *material);
struct GPUTexture **gpu_material_ramp_texture_row_set(struct GPUMaterial *mat,
                                                      int size,
                                                      float *pixels,
                                                      float *row);

struct GSet *gpu_material_used_libraries(struct GPUMaterial *material);
