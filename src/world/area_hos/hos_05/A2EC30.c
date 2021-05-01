#include "hos_05.h"

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_802449F0_A2EC30);

ApiStatus func_80244C60_A2EEA0(ScriptInstance* script, s32 isInitialCall) {
    set_curtain_draw_callback(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_80244C8C_A2EECC);
/*
void N(func_80244C8C_A2EECC)(void) {
    N(func_80243100_A2D340)(N(D_8024DBCC_A37E0C));
}
*/
