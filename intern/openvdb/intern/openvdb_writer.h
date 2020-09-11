#ifndef __OPENVDB_WRITER_H__
#define __OPENVDB_WRITER_H__

#include <openvdb/openvdb.h>

struct OpenVDBWriter {
 private:
  openvdb::GridPtrVecPtr m_grids;
  openvdb::MetaMap::Ptr m_meta_map;

  int m_compression_flags;
  bool m_save_as_half;

 public:
  OpenVDBWriter();
  ~OpenVDBWriter();

  void insert(const openvdb::GridBase::Ptr &grid);
  void insert(const openvdb::GridBase &grid);

  void insertFloatMeta(const openvdb::Name &name, const float value);
  void insertIntMeta(const openvdb::Name &name, const int value);
  void insertVec3sMeta(const openvdb::Name &name, const openvdb::Vec3s &value);
  void insertVec3IMeta(const openvdb::Name &name, const openvdb::Vec3I &value);
  void insertMat4sMeta(const openvdb::Name &name, const float value[4][4]);

  void setFlags(const int compression, const bool save_as_half);

  void write(const openvdb::Name &filename) const;
};

#endif /* __OPENVDB_WRITER_H__ */
