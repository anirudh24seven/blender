#include "openvdb_transform.h"

OpenVDBTransform::OpenVDBTransform()
{
}

OpenVDBTransform::~OpenVDBTransform()
{
}

void OpenVDBTransform::create_linear_transform(double voxel_size)
{
  this->transform = openvdb::math::Transform::createLinearTransform(voxel_size);
}

const openvdb::math::Transform::Ptr &OpenVDBTransform::get_transform()
{
  return this->transform;
}

void OpenVDBTransform::set_transform(const openvdb::math::Transform::Ptr &transform)
{
  this->transform = transform;
}
