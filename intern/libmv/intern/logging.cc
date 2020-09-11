#include <gflags/gflags.h>

#include "intern/logging.h"
#include "intern/utildefines.h"
#include "libmv/logging/logging.h"

static bool is_verbosity_set() {
  using LIBMV_GFLAGS_NAMESPACE::GetCommandLineOption;

  std::string verbosity;
  if (!GetCommandLineOption("v", &verbosity)) {
    return false;
  }
  return verbosity != "0";
}

void libmv_initLogging(const char* argv0) {
  using LIBMV_GFLAGS_NAMESPACE::SetCommandLineOption;
  // Make it so ERROR messages are always print into console.
  char severity_fatal[32];
  snprintf(severity_fatal, sizeof(severity_fatal), "%d",
           google::GLOG_ERROR);
  google::InitGoogleLogging(argv0);
  if (!is_verbosity_set()) {
    SetCommandLineOption("v", "0");
  }
  SetCommandLineOption("stderrthreshold", severity_fatal);
  SetCommandLineOption("minloglevel", severity_fatal);
}

void libmv_startDebugLogging(void) {
  using LIBMV_GFLAGS_NAMESPACE::SetCommandLineOption;
  SetCommandLineOption("logtostderr", "1");
  if (!is_verbosity_set()) {
    SetCommandLineOption("v", "2");
  }
  SetCommandLineOption("stderrthreshold", "1");
  SetCommandLineOption("minloglevel", "0");
}

void libmv_setLoggingVerbosity(int verbosity) {
  using LIBMV_GFLAGS_NAMESPACE::SetCommandLineOption;
  char val[10];
  snprintf(val, sizeof(val), "%d", verbosity);
  SetCommandLineOption("v", val);
}
