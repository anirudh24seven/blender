/** \file
 * \ingroup bke
 */

#pragma once

#include "BKE_customdata.h" /* For cd_datatransfer_interp */

struct CustomData;
struct CustomDataTransferLayerMap;
struct ListBase;

float data_transfer_interp_float_do(const int mix_mode,
                                    const float val_dst,
                                    const float val_src,
                                    const float mix_factor);

void data_transfer_layersmapping_add_item(struct ListBase *r_map,
                                          const int data_type,
                                          const int mix_mode,
                                          const float mix_factor,
                                          const float *mix_weights,
                                          const void *data_src,
                                          void *data_dst,
                                          const int data_src_n,
                                          const int data_dst_n,
                                          const size_t elem_size,
                                          const size_t data_size,
                                          const size_t data_offset,
                                          const uint64_t data_flag,
                                          cd_datatransfer_interp interp,
                                          void *interp_data);

/* Type-specific. */

bool data_transfer_layersmapping_vgroups(struct ListBase *r_map,
                                         const int mix_mode,
                                         const float mix_factor,
                                         const float *mix_weights,
                                         const int num_elem_dst,
                                         const bool use_create,
                                         const bool use_delete,
                                         struct Object *ob_src,
                                         struct Object *ob_dst,
                                         struct CustomData *cd_src,
                                         struct CustomData *cd_dst,
                                         const bool use_dupref_dst,
                                         const int fromlayers,
                                         const int tolayers);

/* Defined in customdata.c */
void customdata_data_transfer_interp_normal_normals(const CustomDataTransferLayerMap *laymap,
                                                    void *data_dst,
                                                    const void **sources,
                                                    const float *weights,
                                                    const int count,
                                                    const float mix_factor);
