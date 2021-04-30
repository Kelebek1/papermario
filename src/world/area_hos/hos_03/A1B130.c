#include "hos_03.h"
#include "message_ids.h"
#include "sprite/npc/chuck_quizmo.h"
#include "sprite/npc/star_kid.h"

EntryList N(entryList) = {
    { -497.0f, 0.0f, 479.0f,  45.0f },
    {  705.0f, 0.0f,   0.0f, 270.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {    0.0f, 0.0f,   0.0f,   0.0f },
    {  354.0f, 0.0f, 294.0f, 117.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_hos_03_tattle },
};

Script N(80243630) = SCRIPT({
    SetMusicTrack(0, SONG_STAR_HAVEN, 0, 8);
});

Script N(8024365C) = SCRIPT({
    SetMusicTrack(0, SONG_TAKING_REST, 0, 8);
});

static s32 N(pad_3688)[] = {
    0x00000000, 0x00000000,
};

Script N(exitWalk_80243690) = EXIT_WALK_SCRIPT(60,  0, "hos_02",  1);

Script N(exitWalk_802436EC) = EXIT_WALK_SCRIPT(60,  1, "hos_04",  0);

Script N(80243748) = SCRIPT({
    bind N(exitWalk_80243690) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_802436EC) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(80243790) = SCRIPT({
0:
    N(GetFloorCollider)(SI_VAR(0));
    match SI_VAR(0) {
        == 12 {
            goto 10;
        }
        == 13 {
            goto 10;
        }
        == 27 {
            goto 10;
        }
        == 20 {
            goto 10;
        }
        == 28 {
            goto 10;
        }
        == 14 {
        10:
            EnableGroup(131, 0);
            EnableGroup(94, 0);
            sleep 1;
        15:
            N(GetFloorCollider)(SI_VAR(1));
            if (SI_VAR(1) == -1) {
                sleep 1;
                goto 15;
            }
            if (SI_VAR(0) == SI_VAR(1)) {
                sleep 1;
                goto 15;
            }
            EnableGroup(131, 1);
            EnableGroup(94, 1);
        }
    }
    sleep 1;
    goto 0;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_STAR_HAVEN;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    if (STORY_PROGRESS == STORY_CH8_OPENED_PATH_TO_STAR_WAY) {
        STORY_PROGRESS = STORY_CH8_REACHED_STAR_HAVEN;
    }
    SI_SAVE_FLAG(1992) = 1;
    MakeNpcs(0, N(npcGroupList_8024BAE4));
    await N(makeEntities);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(80243748);
    } else {
        SI_VAR(0) = N(80243748);
        spawn EnterWalk;
        sleep 1;
    }
    spawn N(80243BD8);
    func_802D6340(6);
    spawn N(80243630);
    PlaySound(0x80000063);
    spawn N(80244650);
    spawn N(8024BCBC);
    spawn N(802456C4);
    spawn N(80243790);
});

static s32 N(pad_3B2C) = {
    0x00000000,
};

Script N(updateTexturePan_80243B30) = SCRIPT({
    group 0;
    if (SI_VAR(5) == 1) {
        if (SI_VAR(6) == 1) {
            if (SI_VAR(7) == 1) {
                if (SI_VAR(8) == 1) {
                    N(UnkTexturePanFunc)();
                    return;
                }
            }
        }
    }
    N(UnkTexturePanFunc2)();
});

s16 N(D_80243BCC_A1ECCC) = 0;
s16 N(D_80243BCE_A1ECCE) = 0;
s16 N(D_80243BD0_A1ECD0) = 0;
s16 N(D_80243BD2_A1ECD2) = 0;
s16 N(D_80243BD4_A1ECD4) = 0;

Script N(80243BD8) = SCRIPT({
    spawn {
        SI_VAR(0) = 1;
        SI_VAR(1) = 100;
        SI_VAR(2) = -80;
        SI_VAR(3) = -50;
        SI_VAR(4) = 120;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(194, 1);
    SetTexPanner(185, 1);
    spawn {
        SI_VAR(0) = 3;
        SI_VAR(1) = -300;
        SI_VAR(2) = 500;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(51, 3);
    SetTexPanner(80, 3);
    SetTexPanner(119, 3);
    spawn {
        SI_VAR(0) = 4;
        SI_VAR(1) = 0;
        SI_VAR(2) = -800;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(52, 4);
    SetTexPanner(81, 4);
    SetTexPanner(120, 4);
    spawn {
        SI_VAR(0) = 5;
        SI_VAR(1) = 0;
        SI_VAR(2) = -1500;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(53, 5);
    SetTexPanner(82, 5);
    SetTexPanner(121, 5);
    spawn {
        SI_VAR(0) = 6;
        SI_VAR(1) = 0;
        SI_VAR(2) = 3000;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(109, 6);
    spawn {
        SI_VAR(0) = 7;
        SI_VAR(1) = 0;
        SI_VAR(2) = 4000;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243B30);
    }
    SetTexPanner(110, 7);
    func_802C9C70(0, 0, 1);
    func_802C94A0(1, N(func_802407E8_A1B8E8), 0);
    func_802C90FC(0, 1, -1);
});

static s32 N(pad_42BC) = {
    0x00000000,
};

Script N(openDoor_802442C0) = SCRIPT({
    RotateGroup(123, SI_VAR(0), 0, 1, 0);
});

Script N(moveWalls_802442F0) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -1.0;
    RotateGroup(125, SI_VAR(1), 0, 0, 1);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -0.5;
    RotateGroup(127, SI_VAR(1), 0, 1, 0);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= 0.5;
    RotateGroup(129, SI_VAR(1), 0, 1, 0);
});

Script N(dropDoor_802443C0) = SCRIPT({
    RotateGroup(123, SI_VAR(0), 1, 0, 0);
});

Script N(openDoor_802443F0) = SCRIPT({
    RotateGroup(84, SI_VAR(0), 0, 1, 0);
});

Script N(moveWalls_80244420) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -1.0;
    RotateGroup(86, SI_VAR(1), 0, 0, 1);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -0.5;
    RotateGroup(88, SI_VAR(1), 0, 1, 0);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= 0.5;
    RotateGroup(90, SI_VAR(1), 0, 1, 0);
});

s32 N(npcList_802444F0)[] = {
    0x00000006, 0xFFFFFFFF,
};

Script N(openDoor_802444F8) = SCRIPT({
    RotateGroup(55, SI_VAR(0), 0, 1, 0);
});

Script N(moveWalls_80244528) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -1.0;
    RotateGroup(50, SI_VAR(1), 0, 0, 1);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= -0.5;
    RotateGroup(46, SI_VAR(1), 0, 1, 0);
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) *= 0.5;
    RotateGroup(48, SI_VAR(1), 0, 1, 0);
    match SI_VAR(0) {
        == 90 {
            EnableModel(49, 0);
        }
        else {
            EnableModel(49, 1);
        }
    }
});

s32 N(npcList_80244648)[] = {
    0x00000005, 0xFFFFFFFF,
};

Script N(80244650) = SCRIPT({
    MakeDoorAdvanced(0, N(openDoor_802442C0), N(moveWalls_802442F0), N(dropDoor_802443C0), 0, 52, 53, 0, 0);
    MakeDoorAdvanced(0, N(openDoor_802443F0), N(moveWalls_80244420), 0, 0, 40, 41, 0, N(npcList_802444F0));
    MakeDoorAdvanced(0, N(openDoor_802444F8), N(moveWalls_80244528), 0, 0, 31, 32, 0, N(npcList_80244648));
});

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

// see func_80240434_A16654
INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", hos_03_func_8024033C_A1B43C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", hos_03_func_8024060C_A1B70C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", hos_03_func_802407E8_A1B8E8);

void N(func_80240928_A1BA28)(void) {
    f32 temp_a1 = ((sins(N(D_80243BD4_A1ECD4)) * 0.000030517578f) * 0.5 * 0.5) + 1.05;

    N(D_80243BD4_A1ECD4) += 0x199;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], temp_a1, temp_a1, temp_a1);
    
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

ApiStatus N(func_80240A50_A1BB50)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
