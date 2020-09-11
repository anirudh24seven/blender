#ifndef __OPENVDB_READER_H__
#define __OPENVDB_READER_H__

#include <openvdb/openvdb.h>

struct OpenVDBReader {
 private:
  openvdb::MetaMap::Ptr m_meta_map;
  openvdb::io::File *m_file;

  void cleanupFile();

 public:
  OpenVDBReader();
  ~OpenVDBReader();

  void open(const openvdb::Name &filename);

  void floatMeta(const openvdb::Name &name, float &value) const;
  void intMeta(const openvdb::Name &name, int &value) const;
  void vec3sMeta(const openvdb::Name &name, float value[3]) const;
  void vec3IMeta(const openvdb::Name &name, int value[3]) const;
  void mat4sMeta(const openvdb::Name &name, float value[4][4]) const;

  bool hasGrid(const openvdb::Name &name) const;
  openvdb::GridBase::Ptr getGrid(const openvdb::Name &name) const;
  size_t numGrids() const;
};

#endif /* __OPENVDB_READER_H__ */
