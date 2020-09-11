#ifndef __OPENVDB_UTIL_H__
#define __OPENVDB_UTIL_H__

#include <openvdb/openvdb.h>
#include <openvdb/util/CpuTimer.h>

#define CATCH_KEYERROR \
  catch (const openvdb::KeyError &e) \
  { \
    std::cerr << e.what() << '\n'; \
  }

//#define DEBUG_TIME

/* A utility class which prints the time elapsed during its lifetime, useful for
 * e.g. timing the overall execution time of a function */
class ScopeTimer {
  std::string m_message;
  openvdb::util::CpuTimer m_timer;

 public:
  ScopeTimer(const std::string &message);
  ~ScopeTimer();
};

#ifdef DEBUG_TIME
#  define Timer(x) ScopeTimer prof(x);
#else
#  define Timer(x)
#endif

#endif /* __OPENVDB_UTIL_H__ */
