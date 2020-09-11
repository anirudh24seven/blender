/** \file
 * \ingroup modifiers
 */

#pragma once

/* so modifier types match their defines */
#include "MOD_modifiertypes.h"

#include "DEG_depsgraph_build.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ARegionType;
struct bContext;
struct PanelType;
struct uiLayout;
typedef void (*PanelDrawFn)(const bContext *, struct Panel *);

void modifier_panel_buttons(const struct bContext *C, struct Panel *panel);

void modifier_vgroup_ui(struct uiLayout *layout,
                        struct PointerRNA *ptr,
                        struct PointerRNA *ob_ptr,
                        const char *vgroup_prop,
                        const char *invert_vgroup_prop,
                        const char *text);

void modifier_panel_end(struct uiLayout *layout, PointerRNA *ptr);

struct PointerRNA *modifier_panel_get_property_pointers(struct Panel *panel,
                                                        struct PointerRNA *r_ob_ptr);

struct PanelType *modifier_panel_register(struct ARegionType *region_type,
                                          ModifierType type,
                                          PanelDrawFn draw);

struct PanelType *modifier_subpanel_register(struct ARegionType *region_type,
                                             const char *name,
                                             const char *label,
                                             PanelDrawFn draw_header,
                                             PanelDrawFn draw,
                                             struct PanelType *parent);

#ifdef __cplusplus
}
#endif
