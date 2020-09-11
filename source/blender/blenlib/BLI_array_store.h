#pragma once

/** \file
 * \ingroup bli
 * \brief Efficient in-memory storage of multiple similar arrays.
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BArrayState BArrayState;
typedef struct BArrayStore BArrayStore;

BArrayStore *BLI_array_store_create(unsigned int stride, unsigned int chunk_count);
void BLI_array_store_destroy(BArrayStore *bs);
void BLI_array_store_clear(BArrayStore *bs);

/* find the memory used by all states (expanded & real) */
size_t BLI_array_store_calc_size_expanded_get(const BArrayStore *bs);
size_t BLI_array_store_calc_size_compacted_get(const BArrayStore *bs);

BArrayState *BLI_array_store_state_add(BArrayStore *bs,
                                       const void *data,
                                       const size_t data_len,
                                       const BArrayState *state_reference);
void BLI_array_store_state_remove(BArrayStore *bs, BArrayState *state);

size_t BLI_array_store_state_size_get(BArrayState *state);
void BLI_array_store_state_data_get(BArrayState *state, void *data);
void *BLI_array_store_state_data_get_alloc(BArrayState *state, size_t *r_data_len);

/* only for tests */
bool BLI_array_store_is_valid(BArrayStore *bs);

#ifdef __cplusplus
}
#endif
