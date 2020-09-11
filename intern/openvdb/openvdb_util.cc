#include "openvdb_util.h"

#include <cstdio>

ScopeTimer::ScopeTimer(const std::string &message) : m_message(message), m_timer()
{
}

ScopeTimer::~ScopeTimer()
{
#if OPENVDB_LIBRARY_MAJOR_VERSION_NUMBER >= 7
  double delta = m_timer.milliseconds();
#else
  double delta = m_timer.delta(); /* Deprecated in OpenVDB 7. */
#endif
  std::printf("%s: %fms\n", m_message.c_str(), delta);
}
