#include "hos_04.h"
#include "message_ids.h"
#include "sprite/npc/twink.h"

enum {
    NPC_TWINK,
};

EntryList N(entryList) = {
    {  -565.0f,   0.0f, 0.0f,  90.0f },
    {   100.0f, 100.0f, 0.0f, 270.0f },
    {     0.0f,   0.0f, 0.0f,   0.0f },
    { -1570.0f,   0.0f, 0.0f,  90.0f },
    { -1570.0f,   0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_hos_04_tattle },
};

Script N(80240F20) = SCRIPT({
    sleep 80;
    SetMusicTrack(0, SONG_INTRO_STORY, 2, 8);
});

Script N(80240F58) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 2 {
            SetMusicTrack(0, SONG_STARSHIP_THEME, 0, 8);
        }
        == 3 {}
        == 4 {
            spawn N(80240F20);
        }
        else {
            if (SI_SAVE_FLAG(532) == 0) {
                SetMusicTrack(0, SONG_STAR_SANCTUARY, 1, 8);
            } else {
                SetMusicTrack(0, SONG_STAR_HAVEN, 0, 8);
            }
            PlaySound(0x80000064);
        }
    }
});

static s32 N(pad_1048)[] = {
    0x00000000, 0x00000000,
};

Script N(exitWalk_80241050) = EXIT_WALK_SCRIPT(60,  0, "hos_03",  1);

Script N(exitWalk_802410AC) = EXIT_WALK_SCRIPT(60,  1, "hos_05",  0);

Script N(80241108) = SCRIPT({
    bind N(exitWalk_80241050) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_802410AC) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(enterWalk_80241150) = SCRIPT({
    SI_AREA_FLAG(181) = 0;
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            ModifyColliderFlags(0, 1, 0x7FFFFE00);
            if (SI_SAVE_FLAG(532) == 0) {
                spawn {
                    DisablePlayerInput(TRUE);
                    SetPlayerPos(-630, 0, 0);
                    GetCurrentPartner(SI_VAR(0));
                    if (SI_VAR(0) == 0) {
                        DisablePartnerAI(0);
                        SetNpcPos(NPC_PARTNER, -660, 0, 0);
                        sleep 1;
                        EnablePartnerAI();
                    }
                    UseSettingsFrom(0, -565, 0, 0);
                    SetPanTarget(0, -565, 0, 0);
                    SetCamDistance(0, 1350);
                    SetCamPitch(0, 15.0, -25.0);
                    SetCamPosA(0, -15.0, -100.0);
                    SetCamPosB(0, 87.5, 50.0);
                    SetCamSpeed(0, 90.0);
                    PanToTarget(0, 0, 1);
                    WaitForCam(0, 1.0);
                    sleep 10;
                    SetCamPitch(0, 4.0, -7.5);
                    SetCamSpeed(0, 0.150390625);
                    PanToTarget(0, 0, 1);
                    WaitForCam(0, 1.0);
                    sleep 30;
                    SI_VAR(0) = N(80241108);
                    await EnterWalk;
                    sleep 20;
                    SI_SAVE_FLAG(532) = 1;
                    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    UseSettingsFrom(0, SI_VAR(0), 0, SI_VAR(2));
                    SetPanTarget(0, SI_VAR(0), 0, SI_VAR(2));
                    SetCamSpeed(0, 90.0);
                    PanToTarget(0, 0, 1);
                    WaitForCam(0, 1.0);
                    PanToTarget(0, 0, 0);
                    SI_AREA_FLAG(181) = 1;
                    DisablePlayerInput(FALSE);
                }
            } else {
                SI_VAR(0) = N(80241108);
                spawn EnterWalk;
                sleep 1;
            }
        }
        == 1 {
            ModifyColliderFlags(0, 1, 0x7FFFFE00);
            SI_VAR(0) = N(80241108);
            spawn EnterWalk;
        }
        == 2 {
            spawn N(802421E0);
        }
        == 3 {
            await N(80241E48);
        }
        == 4 {
            await N(80241B8C);
        }
        == 5 {
            EnableGroup(166, 0);
            spawn N(802425C0);
        }
        == 6 {
            EnableGroup(166, 0);
            spawn N(80242A64);
        }
        == 7 {
            EnableGroup(166, 0);
            spawn N(80242E14);
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_STAR_HAVEN;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    spawn {
        MakeNpcs(0, N(npcGroupList_802421C4));
    }
    spawn N(80241790);
    await N(80240F58);
    spawn N(enterWalk_80241150);
    sleep 1;
    spawn N(80243294);
});

static s32 N(pad_16E8)[] = {
    0x00000000, 0x00000000,
};

u16 N(D_802416F0_A285C0) = 0;

Script N(updateTexturePan_802416F4) = SCRIPT({
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

Script N(80241790) = SCRIPT({
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
        spawn N(updateTexturePan_802416F4);
    }
    spawn {
        SI_VAR(0) = 2;
        SI_VAR(1) = 0;
        SI_VAR(2) = -2000;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802416F4);
    }
    EnableTexPanning(9, 1);
    EnableTexPanning(154, 1);
    EnableTexPanning(162, 1);
    func_802C90FC(162, 0, -1);
    func_802C90FC(154, 0, -1);
    func_802C90FC(160, 1, -1);
    func_802C90FC(152, 1, -1);
    func_802C94A0(0, N(func_80240000_A26ED0), 0);
    func_802C94A0(1, N(func_80240154_A27024), 0);
});

static s32 N(pad_1A44)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80241A50) = SCRIPT({

});

Script N(80241A60) = SCRIPT({
    N(func_802405C0_A27490)();
    match SI_VAR(0) {
        == 0 {
            SI_VAR(0) = -1;
            spawn N(80241A50);
        }
    }
});

static s32 N(pad_1AB8)[] = {
    0x00000000, 0x00000000,
};

Vec3f N(vectorList_80241AC0)[] = {
     { -669.0, 98.0, -34.0 }, { -669.0, 68.0, -34.0 },
     { -644.0, 14.0, -23.0 }, { -564.0, 8.0, 40.0 },
     { -324.0, 136.0, 175.0 }, { -38.0, 118.0, 0.0 },
     { 205.0, 111.0, 0.0 }, { 305.0, 101.0, 0.0 },
    
};

static s32 N(pad_1B20) = {
    0x00000000,
};

CameraController N(D_80241B24_A289F4) = {
    .type = 0,
    .boomLength = 700.0f,
    .boomPitch = -0.9f,
    .position = { 0.0f, -1.0f, 0.0f },
    .orientation = { 500.0f, -1.0f, 0.0f},
    .viewPitch = -17.4f,
    .flag = 0
};

CameraController N(D_80241B50_A28A20) = {
    .type = 0,
    .boomLength = 665.0f,
    .boomPitch = -0.9f,
    .position = { 0.0f, -1.0f, 0.0f },
    .orientation = { 500.0f, -1.0f, 0.0f},
    .viewPitch = -17.4f,
    .flag = 0
};

f32 N(D_80241B7C_A28A4C) = 700.0f;

s32 N(D_80241B80_A28A50) = {
    0x00000000,
};

s32 N(D_80241B84_A28A54) = {
    0x00000000,
};

s32 N(D_80241B88_A28A58) = {
    0x00000000,
};

Script N(80241B8C) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetCamLeadPlayer(0, 0);
    N(SetCamVfov)(0, 75);
    SetPanTarget(0, 0, 30, 0);
    LoadSettings(0, N(D_80241B50_A28A20));
    PanToTarget(0, 0, 1);
    SetCamSpeed(0, 90.0);
    spawn {
        spawn N(80241C5C);
    }
});

Script N(80241C5C) = SCRIPT({
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1A));
    SetNpcYaw(NPC_TWINK, 180);
    N(func_802409B0_A27880)();
    sleep 15;
    spawn {
        sleep 10;
        InterpNpcYaw(NPC_TWINK, 0, 0);
        sleep 2;
        SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_0));
        sleep 20;
        InterpNpcYaw(NPC_TWINK, 180, 0);
        sleep 2;
        SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1A));
    }
    spawn {
        sleep 100;
        N(func_80240A84_A27954)();
    }
    LoadPath(200, N(vectorList_80241AC0), 8, 0);
0:
    GetNextPathPos();
    SetNpcPos(NPC_TWINK, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 0;
    }
    SetNpcPos(NPC_TWINK, 0, -1000, 0);
    spawn {
        sleep 85;
        N(func_8024068C_A2755C)();
    }
    sleep 120;
    N(func_80240654_A27524)();
});

Script N(80241E48) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetCamLeadPlayer(0, 0);
    N(SetCamVfov)(0, 75);
    SetPanTarget(0, 0, 30, 0);
    LoadSettings(0, N(D_80241B24_A289F4));
    PanToTarget(0, 0, 1);
    SetCamSpeed(0, 90.0);
    spawn {
        N(func_802408F8_A277C8)();
    }
    spawn {
        sleep 300;
        N(func_80240654_A27524)();
    }
});

NpcSettings N(npcSettings_80241F40) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80241F6C) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80241F98) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

Script N(init_80241FC4) = SCRIPT({

});

StaticNpc N(npcGroup_80241FD4) = {
    .id = NPC_TWINK,
    .settings = &N(npcSettings_80241F40),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241FC4),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_5),
        NPC_ANIM(twink, Palette_00, Anim_8),
        NPC_ANIM(twink, Palette_00, Anim_8),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
        NPC_ANIM(twink, Palette_00, Anim_1),
    },
};

NpcGroupList N(npcGroupList_802421C4) = {
    NPC_GROUP(N(npcGroup_80241FD4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_21DC) = {
    0x00000000,
};

void N(func_80240000_A26ED0)(void) {
    f32 temp_f0 = (sin_rad(N(D_802416F0_A285C0) * 0.03125f) + 1.0f) * 0.25f + 0.75;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (temp_f0 * 0.3) + 0.5, temp_f0, (temp_f0 * 0.3) + 0.5);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    N(D_802416F0_A285C0)++;
}

void N(func_80240154_A27024)(void) {
    f64 temp_f20 = (sin_rad(N(D_802416F0_A285C0) * 0.03125f) * 10.0f + 1.5);
    f64 temp_f4 = (sin_rad(N(D_802416F0_A285C0) * 0.25f) * 2.5);

    guTranslate(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, temp_f20 + temp_f4, 0.0f);
    
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"
