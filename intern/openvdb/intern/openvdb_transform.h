#ifndef OPENVDB_TRANSFORM_H
#define OPENVDB_TRANSFORM_H

#include <openvdb/openvdb.h>

struct OpenVDBTransform {
 private:
  openvdb::math::Transform::Ptr transform;

 public:
  OpenVDBTransform();
  ~OpenVDBTransform();
  void create_linear_transform(double voxel_size);
  const openvdb::math::Transform::Ptr &get_transform();
  void set_transform(const openvdb::math::Transform::Ptr &transform);
};

#endif  // OPENVDB_TRANSFORM_H
