#include "hos_01.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

ApiStatus N(func_80240AAC_A1132C)(ScriptInstance* script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_78 = 190.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_7C = 220.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_68 = 0.7f;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240B10_A11390)(ScriptInstance* script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_78 = 170.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_7C = 170.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_68 = 2.0f;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240B64_A113E4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Effect* effect = get_variable(script, *args++);

    ((EffectInstanceDataThing*)effect->unk_0C)->unk_38 = get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(func_80240BB8_A11438)(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_80241C2C_A124AC));
}

ApiStatus N(func_80240C08_A11488)(ScriptInstance *script, s32 isInitialCall) {
    N(D_80241C2C_A124AC) = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

void N(func_80240C34_A114B4)(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_80241C30_A124B0));
}

ApiStatus N(func_80240C84_A11504)(ScriptInstance *script, s32 isInitialCall) {
    N(D_80241C30_A124B0) = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240CB0_A11530)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240CDC_A1155C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);

    func_8006FEF0(var0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}
