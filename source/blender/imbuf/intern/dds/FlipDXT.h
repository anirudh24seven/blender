#pragma once

#include "BLI_sys_types.h"

/* flip compressed DXT image vertically to fit OpenGL convention */
int FlipDXTCImage(
    unsigned int width, unsigned int height, unsigned int levels, int fourcc, uint8_t *data);
