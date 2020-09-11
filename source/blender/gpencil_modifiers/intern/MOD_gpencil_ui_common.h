/** \file
 * \ingroup modifiers
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "MOD_gpencil_modifiertypes.h"

struct ARegionType;
struct bContext;
struct PanelType;
struct uiLayout;
typedef void (*PanelDrawFn)(const bContext *, Panel *);

void gpencil_modifier_masking_panel_draw(Panel *panel, bool use_material, bool use_vertex);

void gpencil_modifier_curve_header_draw(const bContext *UNUSED(C), Panel *panel);
void gpencil_modifier_curve_panel_draw(const bContext *UNUSED(C), Panel *panel);

void gpencil_modifier_panel_end(struct uiLayout *layout, PointerRNA *ptr);

struct PointerRNA *gpencil_modifier_panel_get_property_pointers(struct Panel *panel,
                                                                struct PointerRNA *r_ob_ptr);

PanelType *gpencil_modifier_panel_register(struct ARegionType *region_type,
                                           GpencilModifierType type,
                                           PanelDrawFn draw);

struct PanelType *gpencil_modifier_subpanel_register(struct ARegionType *region_type,
                                                     const char *name,
                                                     const char *label,
                                                     PanelDrawFn draw_header,
                                                     PanelDrawFn draw,
                                                     struct PanelType *parent);

#ifdef __cplusplus
}
#endif
