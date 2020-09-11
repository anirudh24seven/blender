/** \file
 * \ingroup collada
 */

#pragma once

typedef struct ImportSettings {
  bool import_units;
  bool find_chains;
  bool auto_connect;
  bool fix_orientation;
  int min_chain_length;
  char *filepath;
  bool keep_bind_info;
} ImportSettings;
