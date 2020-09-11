/** \file
 * \ingroup draw
 */

#pragma once

#include "BLI_compiler_attrs.h"
#include "BLI_sys_types.h"

#include "GPU_batch.h"

#define MAX_INSTANCE_DATA_SIZE 64 /* Can be adjusted for more */

#define DRW_BUFFER_VERTS_CHUNK 128

typedef struct DRWInstanceData DRWInstanceData;
typedef struct DRWInstanceDataList DRWInstanceDataList;

void *DRW_instance_data_next(DRWInstanceData *idata);
DRWInstanceData *DRW_instance_data_request(DRWInstanceDataList *idatalist, uint attr_size);

GPUVertBuf *DRW_temp_buffer_request(DRWInstanceDataList *idatalist,
                                    GPUVertFormat *format,
                                    int *vert_len);
GPUBatch *DRW_temp_batch_instance_request(DRWInstanceDataList *idatalist,
                                          GPUVertBuf *buf,
                                          GPUBatch *instancer,
                                          GPUBatch *geom);
GPUBatch *DRW_temp_batch_request(DRWInstanceDataList *idatalist,
                                 GPUVertBuf *buf,
                                 GPUPrimType type);

/* Upload all instance data to the GPU as soon as possible. */
void DRW_instance_buffer_finish(DRWInstanceDataList *idatalist);

void DRW_instance_data_list_reset(DRWInstanceDataList *idatalist);
void DRW_instance_data_list_free_unused(DRWInstanceDataList *idatalist);
void DRW_instance_data_list_resize(DRWInstanceDataList *idatalist);
