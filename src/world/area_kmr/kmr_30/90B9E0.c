#include "kmr_30.h"

extern u8 D_80240C0F_90C2DF;

INCLUDE_ASM(s32, "world/area_kmr/kmr_30/90B9E0", func_80240310_90B9E0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_30/90B9E0", func_8024045C_90BB2C);
/*
ApiStatus N(func_8024045C_90BB2C)(ScriptInstance *script, s32 isInitialCall) {
    N(D_80240C0C_90C2DC) = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
*/

void func_80240488_90BB58(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80240C0F_90C2DF);
}
