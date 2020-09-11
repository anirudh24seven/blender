/** \file
 * \ingroup modifiers
 */

#pragma once

#include "FX_shader_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ARegionType;
struct bContext;
struct PanelType;
struct uiLayout;
typedef void (*PanelDrawFn)(const bContext *, Panel *);

void shaderfx_panel_end(struct uiLayout *layout, PointerRNA *ptr);

struct PointerRNA *shaderfx_panel_get_property_pointers(struct Panel *panel,
                                                        struct PointerRNA *r_ob_ptr);

PanelType *shaderfx_panel_register(ARegionType *region_type, ShaderFxType type, PanelDrawFn draw);

struct PanelType *shaderfx_subpanel_register(struct ARegionType *region_type,
                                             const char *name,
                                             const char *label,
                                             PanelDrawFn draw_header,
                                             PanelDrawFn draw,
                                             struct PanelType *parent);

#ifdef __cplusplus
}
#endif
