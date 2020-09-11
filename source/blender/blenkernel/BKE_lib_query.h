/** The Original Code is Copyright (C) 2014 by Blender Foundation.
 * All rights reserved.
 */
#pragma once

/** \file
 * \ingroup bke
 *
 * API to perform operations over all ID pointers used by a given data-block.
 *
 * \note `BKE_lib_` files are for operations over data-blocks themselves, although they might
 * alter Main as well (when creating/renaming/deleting an ID e.g.).
 *
 * \section Function Names
 *
 * \warning Descriptions below is ideal goal, current status of naming does not yet fully follow it
 * (this is WIP).
 *
 * - `BKE_lib_query_` should be used for functions in that file.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct IDProperty;
struct Main;

/* Tips for the callback for cases it's gonna to modify the pointer. */
enum {
  IDWALK_CB_NOP = 0,
  IDWALK_CB_NEVER_NULL = (1 << 0),
  IDWALK_CB_NEVER_SELF = (1 << 1),

  /**
   * Indicates whether this is direct (i.e. by local data) or indirect (i.e. by linked data) usage.
   * \note Object proxies are half-local, half-linked...
   */
  IDWALK_CB_INDIRECT_USAGE = (1 << 2),

  /**
   * That ID is used as mere sub-data by its owner (only case currently: those root nodetrees in
   * materials etc., and the Scene's master collections).
   * This means callback shall not *do* anything, only use this as informative data if it needs it.
   */
  IDWALK_CB_EMBEDDED = (1 << 3),

  /**
   * That ID is not really used by its owner, it's just an internal hint/helper.
   * This addresses Their Highest Ugliness the 'from' pointers: Object->from_proxy and Key->from.
   * How to handle that kind of cases totally depends on what caller code is doing... */
  IDWALK_CB_LOOPBACK = (1 << 4),

  /** That ID is used as library override's reference by its owner. */
  IDWALK_CB_OVERRIDE_LIBRARY_REFERENCE = (1 << 5),

  /**
   * This ID usage is fully refcounted.
   * Callback is responsible to deal accordingly with #ID.us if needed.
   */
  IDWALK_CB_USER = (1 << 8),
  /**
   * This ID usage is not refcounted, but at least one user should be generated by it (to avoid
   * e.g. loosing the used ID on save/reload).
   * Callback is responsible to deal accordingly with #ID.us if needed.
   */
  IDWALK_CB_USER_ONE = (1 << 9),
};

enum {
  IDWALK_RET_NOP = 0,
  /** Completely stop iteration. */
  IDWALK_RET_STOP_ITER = 1 << 0,
  /** Stop recursion, that is, do not loop over ID used by current one. */
  IDWALK_RET_STOP_RECURSION = 1 << 1,
};

typedef struct LibraryIDLinkCallbackData {
  void *user_data;
  /** Main database used to call `BKE_library_foreach_ID_link()`. */
  struct Main *bmain;
  /**
   * 'Real' ID, the one that might be in bmain, only differs from self_id when the later is an
   * embedded one.
   */
  struct ID *id_owner;
  /**
   * ID from which the current ID pointer is being processed. It may be an embedded ID like master
   * collection or root node tree.
   */
  struct ID *id_self;
  struct ID **id_pointer;
  int cb_flag;
} LibraryIDLinkCallbackData;

/**
 * Call a callback for each ID link which the given ID uses.
 *
 * \return a set of flags to control further iteration (0 to keep going).
 */
typedef int (*LibraryIDLinkCallback)(LibraryIDLinkCallbackData *cb_data);

/* Flags for the foreach function itself. */
enum {
  IDWALK_NOP = 0,
  IDWALK_READONLY = (1 << 0),
  IDWALK_RECURSE = (1 << 1),    /* Also implies IDWALK_READONLY. */
  IDWALK_INCLUDE_UI = (1 << 2), /* Include UI pointers (from WM and screens editors). */
  /** Do not process ID pointers inside embedded IDs. Needed by depsgraph processing e.g. */
  IDWALK_IGNORE_EMBEDDED_ID = (1 << 3),

  IDWALK_NO_INDIRECT_PROXY_DATA_USAGE = (1 << 8), /* Ugly special case :(((( */
};

typedef struct LibraryForeachIDData LibraryForeachIDData;

bool BKE_lib_query_foreachid_process(struct LibraryForeachIDData *data,
                                     struct ID **id_pp,
                                     int cb_flag);
int BKE_lib_query_foreachid_process_flags_get(struct LibraryForeachIDData *data);
int BKE_lib_query_foreachid_process_callback_flag_override(struct LibraryForeachIDData *data,
                                                           const int cb_flag,
                                                           const bool do_replace);

#define BKE_LIB_FOREACHID_PROCESS_ID(_data, _id, _cb_flag) \
  { \
    CHECK_TYPE_ANY((_id), ID *, void *); \
    if (!BKE_lib_query_foreachid_process((_data), (ID **)&(_id), (_cb_flag))) { \
      return; \
    } \
  } \
  ((void)0)

#define BKE_LIB_FOREACHID_PROCESS(_data, _id_super, _cb_flag) \
  { \
    CHECK_TYPE(&((_id_super)->id), ID *); \
    if (!BKE_lib_query_foreachid_process((_data), (ID **)&(_id_super), (_cb_flag))) { \
      return; \
    } \
  } \
  ((void)0)

bool BKE_library_foreach_ID_embedded(struct LibraryForeachIDData *data, struct ID **id_pp);
void BKE_lib_query_idpropertiesForeachIDLink_callback(struct IDProperty *id_prop, void *user_data);

/* Loop over all of the ID's this datablock links to. */
void BKE_library_foreach_ID_link(
    struct Main *bmain, struct ID *id, LibraryIDLinkCallback callback, void *user_data, int flag);
void BKE_library_update_ID_link_user(struct ID *id_dst, struct ID *id_src, const int cb_flag);

int BKE_library_ID_use_ID(struct ID *id_user, struct ID *id_used);

bool BKE_library_id_can_use_idtype(struct ID *id_owner, const short id_type_used);

bool BKE_library_ID_is_locally_used(struct Main *bmain, void *idv);
bool BKE_library_ID_is_indirectly_used(struct Main *bmain, void *idv);
void BKE_library_ID_test_usages(struct Main *bmain,
                                void *idv,
                                bool *is_used_local,
                                bool *is_used_linked);

void BKE_library_unused_linked_data_set_tag(struct Main *bmain, const bool do_init_tag);
void BKE_library_indirectly_used_data_tag_clear(struct Main *bmain);

#ifdef __cplusplus
}
#endif
