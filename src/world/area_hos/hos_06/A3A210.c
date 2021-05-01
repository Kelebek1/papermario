#include "hos_06.h"

ApiStatus N(func_80240D30_A3A210)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
