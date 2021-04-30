#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc46)(ScriptInstance *script, s32 isInitialCall) {
    gCameras->flags |= 0x1000;
    return ApiStatus_DONE2;
}