#include "hos_03.h"

#define UNK_ALPHA_FUNC_NPC 7

typedef struct {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 instanceCounter;
    /* 0x0C */ EffectInstanceDataThing* unk_0C;
    /* 0x10 */ void (*update)(EffectInstance* effectInst);
    /* 0x14 */ void (*renderWorld)(EffectInstance* effectInst);
    /* 0x18 */ void (*unk_18)(EffectInstance* effectInst);
    /* 0x1C */ void* unk_1C;
} N(temp);

static s32 N(D_8024BDD0);
static s8 N(pad_D_8024BDD4)[0x10];
static s32 N(D_8024BDE8);
static s8 N(pad_D_8024BDEC)[0x4];
static N(temp)* N(D_8024BDF0);
static N(temp)* N(D_8024BDF4);
static N(temp)* N(D_8024BDF8);

void N(func_80240CB0_A1BDB0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}

#ifdef NON_MATCHING
void N(func_802404D0_CB54D0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        // original m2c reference:
        //if ((temp_s0->flags & 8) != 0) {
        //    phi_f0 = temp_f20 + ((temp_f24 - temp_f20) * D_802441A8_CB91A8);
        //    phi_f4 = temp_f24;
        //} else {
        //    func_800DCB7C(temp_s0->unk_80, &subroutine_argA, &subroutine_argB, &subroutine_argC, &subroutine_argD, temp_s0->pos.x, temp_f20, temp_s0->pos.z, 1000.0f);
        //    temp_f4 = subroutine_argB + temp_f26;
        //    phi_f0 = temp_f20 + ((temp_f4 - temp_f20) * D_802441B0_CB91B0);
        //    phi_f4 = temp_f4;
        //}
        //temp_s0->pos.y = phi_f0;

        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY + temp_f26;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1].s <= 0) {
                script->functionTemp[1].s = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    func_800494C0(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0].s = 10;
                    } else {
                        script->functionTemp[0].s = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1].s--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1].s < 3)) {
                script->functionTemp[0].s = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(ApiStatus, "world/area_hos/hos_03/A1BDB0", hos_03_func_80240E60_A1BF60, ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241904_A1CA04)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802457F4_A208F4)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_80241FBC_A1D0BC)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240CB0_A1BDB0)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240E60_A1BF60)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241904_A1CA04)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

#include "world/common/UnkFunc32.inc.c"

#include "world/common/CamSetFOV.inc.c"

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

#include "world/common/DoesPlayerNeedSleep.inc.c"

#include "world/common/UnkFunc35.inc.c"

#include "world/common/GetPartnerCall800EB168.inc.c"

#include "world/common/UnkFunc36.inc.c"

ApiStatus N(func_802424A4_A1D5A4)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_8024801C_A2311C) == NULL) {
        N(D_8024801C_A2311C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_8024801C_A2311C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_8024801C_A2311C)[i];
        }
        heap_free(N(D_8024801C_A2311C));
        N(D_8024801C_A2311C) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

ApiStatus N(func_802425E0_A1D6E0)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemyID;
    u16 phi_s0 = get_variable(script, SI_SAVE_FLAG(1768));
    u16 phi_s7 = get_variable(script, SI_SAVE_FLAG(1769));
    u16 temp_s6 = get_variable(script, SI_SAVE_VAR(350));
    u16 phi_s5 = get_variable(script, SI_SAVE_VAR(351));
    s32 var;
    s32 i;

    s32 test2;
    u16 temp_s3 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 sp_10 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 temp_s2 = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 sp_1e = (enemy->varTable[0] & 0xFF) >> 0;
    s32 temp_v0;
    s32 temp_s0_2;

    if (temp_s3 != temp_s6) {
        phi_s7 = 0;
        phi_s0 = 0;
    }

    if (phi_s0 == 0) {
        if (rand_int(100) < 30) {
            phi_s5 = rand_int(temp_s2 - 1);
            temp_s6 = temp_s3;
            set_variable(script, SI_SAVE_VAR(350), temp_s6);
            set_variable(script, SI_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    set_variable(script, SI_SAVE_FLAG(1768), phi_s0);
    set_variable(script, SI_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = get_variable(NULL, SI_SAVE_VAR(352));
    temp_v0 = get_variable(NULL, SI_SAVE_VAR(0));

    for (i = 0; i < 8; i++) {
        if (temp_v0 < N(quizRequirements)[i].unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < N(quizRequirements)[i].unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) ||
        ((gGameStatusPtr->debugQuizmo != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc31.inc.c"

ApiStatus N(func_80242B90_A1DC90)(ScriptInstance *script, s32 isInitialCall) {
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 0x3E7) {
        gPlayerData.quizzesAnswered++;
    }

    if (script->varTable[0] == N(quizAnswers)[get_variable(NULL, SI_SAVE_VAR(352))]) {
        script->varTable[0] = 1;
        gPlayerData.quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242C14_A1DD14)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        Effect** effect = &N(D_8024BDF0);

        *effect = func_800715D0(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        N(D_8024BDF4) = func_80071810(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        N(D_8024BDF8) = func_80072890(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)), 1.0f, 0);

        effectPtr = (*effect)->unk_0C;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = N(D_8024BDF0)->unk_0C;

    effectPtr->unk_20 += 10;
    effectPtr->unk_28 += 10;
    effectPtr->unk_24.s += 10;
    effectPtr->unk_18 += 10;
    effectPtr->unk_1C += 10;
    if (effectPtr->unk_18 >= 255) {
        effectPtr->unk_18 = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242E2C_A1DF2C)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(D_8024BDF4)->flags |= 0x10;
        N(D_8024BDF8)->flags |= 0x10;
    }

    effectPtr = N(D_8024BDF0)->unk_0C;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(N(D_8024BDF0), effectPtr);
        free_dynamic_entity(N(D_8024BDD0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242EE0_A1DFE0)(ScriptInstance *script, s32 isInitialCall) {
    N(D_8024BDF0)->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242F14_A1E014)(ScriptInstance *script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    EffectInstanceDataThing* effectPtr = N(D_8024BDF0)->unk_0C;

    switch (var) {
        case 0:
            effectPtr->unk_38 = 0xC0;
            break;
        case 1:
            effectPtr->unk_38 = 0x80;
            break;
        case 2:
            effectPtr->unk_38 = 0x40;
            break;
        default:
            effectPtr->unk_38 = 0;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242F94_A1E094)(ScriptInstance *script, s32 isInitialCall) {
    N(D_8024BDF8)->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242FAC_A1E0AC)(ScriptInstance *script, s32 isInitialCall) {
    N(D_8024BDF8)->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242FC8_A1E0C8)(ScriptInstance *script, s32 isInitialCall) {
    N(D_8024BDF8)->unk_0C->unk_1C = 2;
    return ApiStatus_DONE2;
}

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

void N(func_8024349C_A1E59C)(void) {
    s32 var = get_variable(NULL, N(D_8024BDE8));

    if (var == 1) {
        func_80071690(0, 0, 0, 0);
    } else if (var == 2) {
        func_80071690(1, 0, 0, 0);
    }
}

ApiStatus N(func_80243508_A1E608)(ScriptInstance *script, s32 isInitialCall) {
    N(D_8024BDD0) = create_dynamic_entity_frontUI(NULL, N(func_8024349C_A1E59C));
    return ApiStatus_DONE2;
}
