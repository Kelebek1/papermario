#include "hos_00.h"

void N(func_80240C40_A0C930)(void) {
    s32 lerp = update_lerp(0, 0.0f, 216.0f, gPlayerStatus.position.x - 200.0f, 500);

    if (lerp < 0) {
        lerp = 0;
    }

    if (lerp > 216) {
        lerp = 216;
    }

    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, lerp);
}
