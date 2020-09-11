/** \file
 * \ingroup modifiers
 */

#pragma once

struct GHash;
struct MDeformVert;
struct Main;
struct Material;
struct Object;
struct bGPDlayer;
struct bGPDstroke;

bool is_stroke_affected_by_modifier(struct Object *ob,
                                    char *mlayername,
                                    struct Material *material,
                                    const int mpassindex,
                                    const int gpl_passindex,
                                    const int minpoints,
                                    bGPDlayer *gpl,
                                    bGPDstroke *gps,
                                    const bool inv1,
                                    const bool inv2,
                                    const bool inv3,
                                    const bool inv4);

float get_modifier_point_weight(struct MDeformVert *dvert, bool inverse, int def_nr);
