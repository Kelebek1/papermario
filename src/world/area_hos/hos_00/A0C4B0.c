#include "hos_00.h"

ApiStatus N(func_802407C0_A0C4B0)(ScriptInstance *script, s32 isInitialCall) {
    gPlayerData.currentPartner = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
