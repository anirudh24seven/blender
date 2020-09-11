#pragma once

/** \file
 * \ingroup bli
 */

#include "BLI_utildefines.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GSQueue GSQueue;

GSQueue *BLI_gsqueue_new(const size_t elem_size);
bool BLI_gsqueue_is_empty(const GSQueue *queue);
size_t BLI_gsqueue_len(const GSQueue *queue);
void BLI_gsqueue_pop(GSQueue *queue, void *r_item);
void BLI_gsqueue_push(GSQueue *queue, const void *item);
void BLI_gsqueue_free(GSQueue *queue);

#ifdef __cplusplus
}
#endif
