/** \file
 * \ingroup bke
 */

#include <string.h>

#include "MEM_guardedalloc.h"

#include "DNA_ID.h"
#include "DNA_customdata_types.h"
#include "DNA_hair_types.h"
#include "DNA_mesh_types.h"
#include "DNA_meshdata_types.h"
#include "DNA_pointcloud_types.h"

#include "BLI_string_utf8.h"

#include "BKE_attribute.h"
#include "BKE_customdata.h"
#include "BKE_hair.h"
#include "BKE_pointcloud.h"
#include "BKE_report.h"

#include "RNA_access.h"

typedef struct DomainInfo {
  CustomData *customdata;
  int length;
} DomainInfo;

static void get_domains(ID *id, DomainInfo info[ATTR_DOMAIN_NUM])
{
  memset(info, 0, sizeof(DomainInfo) * ATTR_DOMAIN_NUM);

  switch (GS(id->name)) {
    case ID_PT: {
      PointCloud *pointcloud = (PointCloud *)id;
      info[ATTR_DOMAIN_POINT].customdata = &pointcloud->pdata;
      info[ATTR_DOMAIN_POINT].length = pointcloud->totpoint;
      break;
    }
    case ID_ME: {
      Mesh *mesh = (Mesh *)id;
      info[ATTR_DOMAIN_VERTEX].customdata = &mesh->vdata;
      info[ATTR_DOMAIN_VERTEX].length = mesh->totvert;
      info[ATTR_DOMAIN_EDGE].customdata = &mesh->edata;
      info[ATTR_DOMAIN_EDGE].length = mesh->totedge;
      info[ATTR_DOMAIN_CORNER].customdata = &mesh->ldata;
      info[ATTR_DOMAIN_CORNER].length = mesh->totloop;
      info[ATTR_DOMAIN_POLYGON].customdata = &mesh->pdata;
      info[ATTR_DOMAIN_POLYGON].length = mesh->totpoly;
      break;
    }
    case ID_HA: {
      Hair *hair = (Hair *)id;
      info[ATTR_DOMAIN_POINT].customdata = &hair->pdata;
      info[ATTR_DOMAIN_POINT].length = hair->totpoint;
      info[ATTR_DOMAIN_CURVE].customdata = &hair->cdata;
      info[ATTR_DOMAIN_CURVE].length = hair->totcurve;
      break;
    }
    default:
      break;
  }
}

static CustomData *attribute_customdata_find(ID *id, CustomDataLayer *layer)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata && ARRAY_HAS_ITEM(layer, customdata->layers, customdata->totlayer)) {
      return customdata;
    }
  }

  return NULL;
}

bool BKE_id_attributes_supported(struct ID *id)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);
  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    if (info[domain].customdata) {
      return true;
    }
  }
  return false;
}

bool BKE_id_attribute_rename(ID *id,
                             CustomDataLayer *layer,
                             const char *new_name,
                             ReportList *reports)
{
  if (BKE_id_attribute_required(id, layer)) {
    BLI_assert(!"Required attribute name is not editable");
    return false;
  }

  CustomData *customdata = attribute_customdata_find(id, layer);
  if (customdata == NULL) {
    BKE_report(reports, RPT_ERROR, "Attribute is not part of this geometry");
    return false;
  }

  BLI_strncpy_utf8(layer->name, new_name, sizeof(layer->name));
  CustomData_set_layer_unique_name(customdata, layer - customdata->layers);
  return true;
}

CustomDataLayer *BKE_id_attribute_new(
    ID *id, const char *name, const int type, const AttributeDomain domain, ReportList *reports)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  CustomData *customdata = info[domain].customdata;
  if (customdata == NULL) {
    BKE_report(reports, RPT_ERROR, "Attribute domain not supported by this geometry type");
    return NULL;
  }

  CustomData_add_layer_named(customdata, type, CD_DEFAULT, NULL, info[domain].length, name);
  const int index = CustomData_get_named_layer_index(customdata, type, name);
  return (index == -1) ? NULL : &(customdata->layers[index]);
}

bool BKE_id_attribute_remove(ID *id, CustomDataLayer *layer, ReportList *reports)
{
  CustomData *customdata = attribute_customdata_find(id, layer);
  const int index = (customdata) ?
                        CustomData_get_named_layer_index(customdata, layer->type, layer->name) :
                        -1;

  if (index == -1) {
    BKE_report(reports, RPT_ERROR, "Attribute is not part of this geometry");
    return false;
  }

  if (BKE_id_attribute_required(id, layer)) {
    BKE_report(reports, RPT_ERROR, "Attribute is required and can't be removed");
    return false;
  }

  const int length = BKE_id_attribute_data_length(id, layer);
  CustomData_free_layer(customdata, layer->type, length, index);
  return true;
}

int BKE_id_attributes_length(ID *id, const CustomDataMask mask)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  int length = 0;

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata) {
      length += CustomData_number_of_layers_typemask(customdata, mask);
    }
  }

  return length;
}

AttributeDomain BKE_id_attribute_domain(ID *id, CustomDataLayer *layer)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata && ARRAY_HAS_ITEM(layer, customdata->layers, customdata->totlayer)) {
      return domain;
    }
  }

  BLI_assert(!"Custom data layer not found in geometry");
  return ATTR_DOMAIN_NUM;
}

int BKE_id_attribute_data_length(ID *id, CustomDataLayer *layer)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata && ARRAY_HAS_ITEM(layer, customdata->layers, customdata->totlayer)) {
      return info[domain].length;
    }
  }

  BLI_assert(!"Custom data layer not found in geometry");
  return 0;
}

bool BKE_id_attribute_required(ID *id, CustomDataLayer *layer)
{
  switch (GS(id->name)) {
    case ID_PT: {
      return BKE_pointcloud_customdata_required((PointCloud *)id, layer);
    }
    case ID_HA: {
      return BKE_hair_customdata_required((Hair *)id, layer);
    }
    default:
      return false;
  }
}

CustomDataLayer *BKE_id_attributes_active_get(ID *id)
{
  int active_index = *BKE_id_attributes_active_index_p(id);
  if (active_index > BKE_id_attributes_length(id, CD_MASK_PROP_ALL)) {
    active_index = 0;
  }

  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  int index = 0;

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata) {
      for (int i = 0; i < customdata->totlayer; i++) {
        CustomDataLayer *layer = &customdata->layers[i];
        if (CD_MASK_PROP_ALL & CD_TYPE_AS_MASK(layer->type)) {
          if (index == active_index) {
            return layer;
          }
          index++;
        }
      }
    }
  }

  return NULL;
}

void BKE_id_attributes_active_set(ID *id, CustomDataLayer *active_layer)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  int index = 0;

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata) {
      for (int i = 0; i < customdata->totlayer; i++) {
        CustomDataLayer *layer = &customdata->layers[i];
        if (layer == active_layer) {
          *BKE_id_attributes_active_index_p(id) = index;
          return;
        }
        if (CD_MASK_PROP_ALL & CD_TYPE_AS_MASK(layer->type)) {
          index++;
        }
      }
    }
  }
}

int *BKE_id_attributes_active_index_p(ID *id)
{
  switch (GS(id->name)) {
    case ID_PT: {
      return &((PointCloud *)id)->attributes_active_index;
    }
    case ID_ME: {
      return &((Mesh *)id)->attributes_active_index;
    }
    case ID_HA: {
      return &((Hair *)id)->attributes_active_index;
    }
    default:
      return NULL;
  }
}

CustomData *BKE_id_attributes_iterator_next_domain(ID *id, CustomDataLayer *layers)
{
  DomainInfo info[ATTR_DOMAIN_NUM];
  get_domains(id, info);

  bool use_next = (layers == NULL);

  for (AttributeDomain domain = 0; domain < ATTR_DOMAIN_NUM; domain++) {
    CustomData *customdata = info[domain].customdata;
    if (customdata && customdata->layers) {
      if (customdata->layers == layers) {
        use_next = true;
      }
      else if (use_next) {
        return customdata;
      }
    }
  }

  return NULL;
}
