#include "hos_00.h"

ApiStatus N(func_802407F0_A0C4E0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242970_A0E660) == NULL) {
        N(D_80242970_A0E660) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242970_A0E660)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242970_A0E660)[i];
        }
        heap_free(N(D_80242970_A0E660));
        N(D_80242970_A0E660) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

ApiStatus N(func_80240908_A0C5F8)(ScriptInstance *script, s32 isInitialCall) {
    gPlayerData.hasActionCommands = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024091C_A0C60C)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);

    set_float_variable(script, *args++, var1 * sin_deg(var2));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240994_A0C684)(ScriptInstance *script, s32 isInitialCall) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Npc* twink = get_npc_unsafe(NPC_TWINK);

    partner->yaw = atan2(partner->pos.x, partner->pos.z, twink->pos.x, twink->pos.z);
    gPlayerStatus.targetYaw = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, twink->pos.x, twink->pos.z);
    twink->yaw = atan2(N(D_80242B9C_A0E88C), N(D_80242BA0_A0E890), twink->pos.x,twink->pos.z);
    N(D_80242B9C_A0E88C) = twink->pos.x;
    N(D_80242BA0_A0E890) = twink->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240A54_A0C744)(ScriptInstance *script, s32 isInitialCall) {
    Npc* flyingMagikoopa = get_npc_unsafe(NPC_FLYING_MAGIKOOPA);

    if (flyingMagikoopa->yaw < 180.0f) {
        script->varTable[0] = flyingMagikoopa->pos.x - 40.0f;
        script->varTable[1] = flyingMagikoopa->pos.y + 10.0f;
        script->varTable[2] = flyingMagikoopa->pos.z;
    } else {
        script->varTable[0] = flyingMagikoopa->pos.x + 40.0f;
        script->varTable[1] = flyingMagikoopa->pos.y + 10.0f;
        script->varTable[2] = flyingMagikoopa->pos.z;
    }
    flyingMagikoopa->yaw = atan2(script->varTable[6], script->varTable[8], flyingMagikoopa->pos.x, flyingMagikoopa->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240B20_A0C810)(ScriptInstance *script, s32 isInitialCall) {
    gCameras->flags |= 0x1000;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240B3C_A0C82C)(ScriptInstance *script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var2 = script->varTable[2];

    script->varTable[0] = (var0 + (sin_deg(310.0f) * 100.0f));
    script->varTable[1] = (var2 - (cos_deg(310.0f) * 100.0f));
    script->varTable[2] = (var0 + (sin_deg(130.0f) * 100.0f));
    script->varTable[3] = (var2 - (cos_deg(130.0f) * 100.0f));
    return ApiStatus_DONE2;
}
