#include "hos_02.h"

ApiStatus N(func_80240FD0_A171F0)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
