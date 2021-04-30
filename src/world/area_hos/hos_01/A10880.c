#include "hos_01.h"

ApiStatus N(func_80240000_A10880)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);
    f32 var4 = get_float_variable(script, *args++);
    f32 var5 = get_float_variable(script, *args++);
    f32 var6 = get_float_variable(script, *args++);
    f32 var7 = get_float_variable(script, *args++);
    f32 var8 = get_float_variable(script, *args++);

    func_8006FE30(var1, var2, var3, var4, var5, var6, var7, var8);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_01/A10880", func_80240120_A109A0);

INCLUDE_ASM(s32, "world/area_hos/hos_01/A10880", func_8024031C_A10B9C);

INCLUDE_ASM(s32, "world/area_hos/hos_01/A10880", func_80240534_A10DB4);

/*
ApiStatus N(func_80240120_A109A0)(ScriptInstance *script, s32 isInitialCall) {
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    s32 rand4;
    f32 xTemp;

    f32 temp_f26 = (gCameras->currentYaw / 180.0f) * PI;
    f32 temp_f22 = temp_f26 + 1.570796;
    f32 temp_f20 = temp_f26 - 1.570796;
    f32 rand1 = rand_int(500) - 250;
    f32 rand2 = rand_int(500) - 250;
    f32 rand3 = rand_int(100) + 600;

    xTemp = gPlayerStatus.position.x + (rand3 * sin_rad(temp_f26));
    x = xTemp + (rand1 * sin_rad(temp_f22));

    y = gPlayerStatus.position.y + 200.0f;

    z = gPlayerStatus.position.z - (rand3 * cos_rad(temp_f26));
    z -= (rand1 * cos_rad(temp_f22));

    x2 = gPlayerStatus.position.x + (rand3 * sin_rad(temp_f26));
    x2 += (rand2 * sin_rad(temp_f20));

    y2 = gPlayerStatus.position.y;

    z2 = gPlayerStatus.position.z - (rand3 * cos_rad(temp_f26));
    z2 -= (rand2 * cos_rad(temp_f20));

    rand4 = rand_int(10) + 10;

    func_8006FE30(0, x, y, z, x2, y2, z2, rand4);
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024031C_A10B9C)(ScriptInstance *script, s32 isInitialCall) {
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 rand4;

    f32 temp_f30 = (gCameras->currentYaw / 180.0f) * PI;
    f32 temp_f22 = temp_f30 + 1.570796;
    f32 temp_f20 = temp_f30 - 1.570796;

    f32 rand1 = rand_int(300) - 150;
    f32 rand2 = rand_int(300) - 150;
    f32 rand3;

    if (gPlayerStatus.position.y){};
    rand3 = rand_int(100) + 50;

    if (gPlayerStatus.position.y >= 250.0f) {
        return ApiStatus_DONE2;
    }

    x = gPlayerStatus.position.x - (rand3 * sin_rad(temp_f30));
    x += (rand1 * sin_rad(temp_f22));

    y = gPlayerStatus.position.y + 200.0f;

    z = gPlayerStatus.position.z + (rand3 * cos_rad(temp_f30));
    z -= (rand1 * cos_rad(temp_f22));

    x2 = gPlayerStatus.position.x - (rand3 * sin_rad(temp_f30));
    x2 += (rand2 * sin_rad(temp_f20));

    y2 = gPlayerStatus.position.y;

    z2 = gPlayerStatus.position.z + (rand3 * cos_rad(temp_f30));
    z2 -= (rand2 * cos_rad(temp_f20));

    rand4 = rand_int(10) + 10;

    func_8006FE30(1, x, y, z, x2, y2, z2, rand4);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240534_A10DB4)(ScriptInstance *script, s32 isInitialCall) {
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 rand4;

    f32 temp_f30 = (gCameras->currentYaw / 180.0f) * PI;
    f32 temp_f22 = temp_f30 + 1.570796;
    f32 temp_f20 = temp_f30 - 1.570796;

    f32 rand1 = rand_int(150);
    f32 rand2 = rand_int(150);
    f32 rand3;

    if (gPlayerStatus.position.z){};
    rand3 = rand_int(100) - 50;

    if (gPlayerStatus.position.z < 200.0f) {
        return ApiStatus_DONE2;
    }

    x = gPlayerStatus.position.x - (rand3 * sin_rad(temp_f30));
    x += (rand1 * sin_rad(temp_f22));

    y = gPlayerStatus.position.y + 200.0f;

    z = gPlayerStatus.position.z + (rand3 * cos_rad(temp_f30));
    z -= (rand1 * cos_rad(temp_f22));

    script->varTable[1] = x;
    script->varTable[2] = y;
    script->varTable[3] = z;

    x2 = gPlayerStatus.position.x - (rand3 * sin_rad(temp_f30));
    x2 += (rand2 * sin_rad(temp_f20));

    y2 = gPlayerStatus.position.y;

    z2 = gPlayerStatus.position.z + (rand3 * cos_rad(temp_f30));
    z2 -= (rand2 * cos_rad(temp_f20));

    rand4 = rand_int(4) + 10;

    func_8006FE30(2, x, y, z, x2, y2, z2, rand4);
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetFloorCollider.inc.c"
