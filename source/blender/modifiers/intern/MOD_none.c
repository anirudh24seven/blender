/** \file
 * \ingroup modifiers
 */

#include <stdio.h>

#include "BLI_utildefines.h"

#include "MOD_modifiertypes.h"

/* We only need to define isDisabled; because it always returns 1,
 * no other functions will be called
 */

static bool isDisabled(const struct Scene *UNUSED(scene),
                       ModifierData *UNUSED(md),
                       bool UNUSED(userRenderParams))
{
  return true;
}

ModifierTypeInfo modifierType_None = {
    /* name */ "None",
    /* structName */ "ModifierData",
    /* structSize */ sizeof(ModifierData),
    /* type */ eModifierTypeType_None,
    /* flags */ eModifierTypeFlag_AcceptsMesh | eModifierTypeFlag_AcceptsCVs,

    /* copyData */ NULL,

    /* deformVerts */ NULL,
    /* deformMatrices */ NULL,
    /* deformVertsEM */ NULL,
    /* deformMatricesEM */ NULL,
    /* modifyMesh */ NULL,
    /* modifyHair */ NULL,
    /* modifyPointCloud */ NULL,
    /* modifyVolume */ NULL,

    /* initData */ NULL,
    /* requiredDataMask */ NULL,
    /* freeData */ NULL,
    /* isDisabled */ isDisabled,
    /* updateDepsgraph */ NULL,
    /* dependsOnTime */ NULL,
    /* dependsOnNormals */ NULL,
    /* foreachObjectLink */ NULL,
    /* foreachIDLink */ NULL,
    /* foreachTexLink */ NULL,
    /* freeRuntimeData */ NULL,
    /* panelRegister */ NULL,
    /* blendWrite */ NULL,
    /* blendRead */ NULL,
};
