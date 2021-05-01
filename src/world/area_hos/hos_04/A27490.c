#include "hos_04.h"

ApiStatus N(func_802405C0_A27490)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
