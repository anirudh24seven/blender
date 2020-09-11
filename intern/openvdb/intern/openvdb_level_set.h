#ifndef __OPENVDB_LEVEL_SET_H__
#define __OPENVDB_LEVEL_SET_H__

#include "openvdb_capi.h"
#include <openvdb/math/FiniteDifference.h>
#include <openvdb/openvdb.h>
#include <openvdb/tools/GridTransformer.h>
#include <openvdb/tools/LevelSetFilter.h>
#include <openvdb/tools/MeshToVolume.h>
#include <openvdb/tools/VolumeToMesh.h>

struct OpenVDBLevelSet {
 private:
  openvdb::FloatGrid::Ptr grid;

 public:
  OpenVDBLevelSet();
  ~OpenVDBLevelSet();
  const openvdb::FloatGrid::Ptr &get_grid();
  void set_grid(const openvdb::FloatGrid::Ptr &grid);

  void mesh_to_level_set(const float *vertices,
                         const unsigned int *faces,
                         const unsigned int totvertices,
                         const unsigned int totfaces,
                         const openvdb::math::Transform::Ptr &transform);

  void volume_to_mesh(struct OpenVDBVolumeToMeshData *mesh,
                      const double isovalue,
                      const double adaptivity,
                      const bool relax_disoriented_triangles);
  void filter(OpenVDBLevelSet_FilterType filter_type,
              int width,
              float distance,
              OpenVDBLevelSet_FilterBias filter_bias);
  openvdb::FloatGrid::Ptr CSG_operation_apply(const openvdb::FloatGrid::Ptr &gridA,
                                              const openvdb::FloatGrid::Ptr &gridB,
                                              OpenVDBLevelSet_CSGOperation operation);
};

#endif /* __OPENVDB_LEVEL_SET_H__ */
