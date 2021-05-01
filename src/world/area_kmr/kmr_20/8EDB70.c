#include "kmr_20.h"

#define NAMESPACE dup2_kmr_20
#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup2_kmr_20
#include "world/common/GetCurrentFloor.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup2_kmr_20
#include "world/common/UnkFunc25.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup2_kmr_20
#include "world/common/GetEntryPos.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup2_kmr_20
#include "world/common/GetCurrentCameraYawClamped180.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup2_kmr_20
#include "world/common/SomeXYZFunc2.inc.c"
#define NAMESPACE kmr_20

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDB70", func_80242030_8EDE50);

ApiStatus func_80242084_8EDEA4(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDB70", func_802420EC_8EDF0C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDB70", func_80242144_8EDF64);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDB70", func_8024216C_8EDF8C);
