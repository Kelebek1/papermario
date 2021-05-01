#include "hos_10.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

ApiStatus func_8024032C_A3FA6C(ScriptInstance *script, s32 isInitialCall) {
    if ((u8)gGameStatusPtr->creditsViewportMode < 5) {
        gGameStatusPtr->creditsViewportMode++;
        begin_state_intro();
    }
    return ApiStatus_DONE1;
}

void func_80240364_A3FAA4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    f32 temp_f2 = arg1 - arg2;
    f32 temp_f0 = arg1 - arg0;

    if (temp_f0 > 0.0f) {
        if (temp_f2 < 0.0f) {
            *arg4 = arg1;
        } else if (arg3 < temp_f2) {
            *arg4 += arg3;
        } else {
            *arg4 += temp_f2;
        }
    } else if (temp_f2 > 0.0f) {
        *arg4 = arg1;
    } else if (temp_f2 < -arg3) {
        *arg4 -= arg3;
    } else {
        *arg4 += temp_f2;
    }
}

INCLUDE_ASM(s32, "world/area_hos/hos_10/A3F760", func_80240404_A3FB44);
