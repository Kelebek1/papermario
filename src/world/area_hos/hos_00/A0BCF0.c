#include "hos_00.h"

extern s32 D_800D9668;

ApiStatus N(func_80240000_A0BCF0)(ScriptInstance* script, s32 isInitialCall) {
    if (gGameStatusPtr->entryID == 3) {
        sprintf(&D_800D9668, "hos_bg");
    }
    return ApiStatus_BLOCK;
}
