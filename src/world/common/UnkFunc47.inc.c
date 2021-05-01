#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc47)(ScriptInstance *script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1].s = 0;
    }

    script->functionTemp[1].s += 16;
    if (script->functionTemp[1].s > 255) {
        script->functionTemp[1].s = 255;
    }

    set_transition_stencil_zoom_0(0, script->functionTemp[1].s);

    return (script->functionTemp[1].s == 255) * ApiStatus_DONE2;
}