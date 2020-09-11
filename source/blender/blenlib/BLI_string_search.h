#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StringSearch StringSearch;

StringSearch *BLI_string_search_new(void);
void BLI_string_search_add(StringSearch *search, const char *str, void *user_data);
int BLI_string_search_query(StringSearch *search, const char *query, void ***r_data);
void BLI_string_search_free(StringSearch *search);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#  include "BLI_linear_allocator.hh"
#  include "BLI_span.hh"
#  include "BLI_string_ref.hh"
#  include "BLI_vector.hh"

namespace blender::string_search {

int damerau_levenshtein_distance(StringRef a, StringRef b);
int get_fuzzy_match_errors(StringRef query, StringRef full);
void extract_normalized_words(StringRef str,
                              LinearAllocator<> &allocator,
                              Vector<StringRef, 64> &r_words);

}  // namespace blender::string_search

#endif
