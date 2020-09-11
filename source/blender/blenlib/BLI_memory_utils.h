#ifndef __BLI_MEMORY_UTILS_H__
#define __BLI_MEMORY_UTILS_H__

/** \file
 * \ingroup bli
 * \brief Generic memory manipulation API.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* it may be defined already */
#ifndef __BLI_UTILDEFINES_H__
bool BLI_memory_is_zero(const void *arr, const size_t size);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __BLI_MEMORY_UTILS_H__ */
