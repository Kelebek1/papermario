#include "hos_01.h"
#include "message_ids.h"
#include "sprite/npc/world_eldstar.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kalmar.h"
#include "sprite/npc/world_klevar.h"
#include "sprite/npc/world_mamar.h"
#include "sprite/npc/world_misstar.h"
#include "sprite/npc/world_muskular.h"
#include "sprite/npc/world_skolar.h"

enum {
    NPC_WORLD_ELDSTAR,
    NPC_WORLD_MAMAR,
    NPC_WORLD_SKOLAR,
    NPC_WORLD_MUSKULAR,
    NPC_WORLD_MISSTAR,
    NPC_WORLD_KLEVAR,
    NPC_WORLD_KALMAR,
};

EntryList N(entryList) = {
    { -400.0f,   0.0f,  410.0f, 45.0f },
    {   22.0f, 285.0f, -190.0f,  0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_hos_01_tattle },
};

Script N(80240E80) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 0) {
        SetMusicTrack(0, SONG_SHOOTING_STAR_SUMMIT, 0, 8);
    }
});

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

static s32 N(pad_ED4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80240EE0) = SCRIPT({
    group 11;
    SI_VAR(13) = 0;
    SI_VAR(14) = 0;
0:
    GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    if (SI_VAR(1) < -50) {
        sleep 1;
        goto 0;
    }
    SI_VAR(8) = 1000;
    SI_VAR(8) -= SI_VAR(1);
    SI_VAR(8) /= 10;
    if (SI_VAR(8) < 20) {
        SI_VAR(8) = 20;
    }
    GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    RandInt(400, SI_VAR(10));
    SI_VAR(11) = 200;
    RandInt(400, SI_VAR(12));
    SI_VAR(12) -= 200;
    SI_VAR(1) += SI_VAR(10);
    SI_VAR(2) += SI_VAR(11);
    SI_VAR(3) += SI_VAR(12);
    SI_VAR(4) = SI_VAR(1);
    RandInt(100, SI_VAR(10));
    SI_VAR(10) += 50;
    SI_VAR(4) -= SI_VAR(10);
    SI_VAR(5) = 0;
    SI_VAR(6) = SI_VAR(3);
    RandInt(4, SI_VAR(7));
    SI_VAR(7) += 10;
    match SI_VAR(3) {
        < -290 {
            SI_VAR(0) = 0;
        }
        < 40 {
            SI_VAR(0) = 2;
        }
        >= 40 {
            SI_VAR(0) = 1;
        }
    }
    if (SI_VAR(14) < 2) {
        PlaySoundAt(0xB0000015, 0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SI_VAR(14) += 1;
    }
    SI_VAR(13) += SI_VAR(8);
    if (SI_VAR(13) > 30) {
        SI_VAR(13) = 0;
        SI_VAR(14) = 0;
    }
    N(func_80240000_A10880)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7));
    sleep SI_VAR(8);
    goto 0;
});

Script N(8024121C) = SCRIPT({
    group 11;
    spawn {
    0:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 10;
        N(func_80240120_A109A0)();
        sleep SI_VAR(0);
        goto 0;
    }
    spawn {
    1:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 20;
        N(func_8024031C_A10B9C)();
        sleep SI_VAR(0);
        goto 1;
    }
    spawn {
    2:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 20;
        N(func_80240534_A10DB4)();
        PlaySoundAt(0xB0000015, 0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        sleep SI_VAR(0);
        goto 2;
    }
});

const char N(kmr_24_name_hack)[];
const char N(hos_00_name_hack)[];

Script N(exitWalk_80241384) = SCRIPT({
    FadeOutMusic(0, 1500);
    GotoMapSpecial(N(kmr_24_name_hack), 0, 11);
    sleep 100;
    // Should be a new script here at 802413BC
    group 27;
    UseExitHeading(60, 0);
    spawn ExitWalk;
    GotoMap(N(hos_00_name_hack), 1);
    sleep 100;
});

const char N(kmr_24_name_hack)[] = "kmr_24";
const char N(hos_00_name_hack)[] = "hos_00";

Script N(80241418) = SCRIPT({
    group 27;
    if (STORY_PROGRESS < STORY_CH8_OPENED_PATH_TO_STAR_WAY) {
        return;
    }
    DisablePlayerInput(TRUE);
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        func_802D2B6C();
        sleep 20;
        loop {
            sleep 1;
            IsPlayerOnValidFloor(SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
        }
    }
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    await N(80245580);
    GotoMap("hos_02", 0);
    sleep 100;
});

Script N(80241540) = SCRIPT({
    // Should be the above weird script
    bind 0x802413BC to TRIGGER_FLOOR_ABOVE 0;
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 1) {
        bind N(80241418) to TRIGGER_FLOOR_TOUCH 4;
    }
});

Script N(802415B0) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(10);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    UseSettingsFrom(0, -30, 250, -160);
    SetPanTarget(0, -30, 250, -160);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SI_VAR(2) = 360;
    MakeLerp(500, 250, 60, 4);
    loop {
        UpdateLerp();
        SetPlayerPos(-30, SI_VAR(0), -160);
        SetNpcPos(NPC_PARTNER, -30, SI_VAR(0), -170);
        SI_VAR(2) += 40;
        InterpPlayerYaw(SI_VAR(2), 0);
        SetNpcRotation(NPC_PARTNER, 0, SI_VAR(2), 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    SI_VAR(0) = SI_VAR(2);
    SI_VAR(0) -= 360;
    SI_VAR(2) -= SI_VAR(0);
    SI_VAR(0) = 40;
10:
    if (SI_VAR(2) < 540) {
        InterpPlayerYaw(SI_VAR(2), 0);
        SetNpcRotation(NPC_PARTNER, 0, SI_VAR(2), 0);
        SI_VAR(2) += SI_VAR(0);
        sleep 1;
        goto 10;
    }
    SI_VAR(2) = 180;
    SI_VAR(0) -= 5;
    if (SI_VAR(0) > 20) {
        goto 10;
    }
    SetNpcRotation(NPC_PARTNER, 0, 0, 0);
    N(func_80240AAC_A1132C)(SI_MAP_VAR(10));
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE);
    EnablePartnerAI();
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    SetMusicTrack(0, SONG_SHOOTING_STAR_SUMMIT, 0, 8);
    DisablePlayerInput(FALSE);
20:
    N(GetFloorCollider)(SI_VAR(0));
    if (SI_VAR(0) != 16) {
        sleep 1;
        goto 20;
    }
    bind N(80241418) to TRIGGER_FLOOR_TOUCH 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_SHOOTING_STAR_SUMMIT;
    SetSpriteShading(196608);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    spawn {
    1:
        if (STORY_PROGRESS != STORY_CH0_MET_STAR_SPIRITS) {
            sleep 1;
            goto 1;
        }
        DisablePlayerInput(TRUE);
        await N(exitWalk_80241384);
    }
    MakeNpcs(0, N(npcGroupList_80244FC0));
    await N(makeEntities);
    spawn N(80241D48);
    spawn N(8024121C);
    spawn N(80240E80);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(0) = N(80241540);
            spawn EnterWalk;
            sleep 1;
        }
        == 1 {
            spawn {
                await N(802415B0);
                spawn N(80241540);
            }
        }
    }
    if (STORY_PROGRESS == STORY_CH7_STAR_SPRIT_DEPARTED) {
        spawn N(80245050);
    }
});

Script N(updateTexturePan_80241B90) = SCRIPT({
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

s32 N(D_80241C2C_A124AC) = 255;

s32 N(D_80241C30_A124B0) = 255;

Script N(80241C34) = SCRIPT({
    loop {
        MakeLerp(180, 80, 45, 10);
        loop {
            UpdateLerp();
            N(func_80240C84_A11504)(SI_VAR(0));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        MakeLerp(80, 180, 35, 10);
        loop {
            UpdateLerp();
            N(func_80240C84_A11504)(SI_VAR(0));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
});

Script N(80241D48) = SCRIPT({
    spawn {
        SI_VAR(0) = 4;
        SI_VAR(1) = 0;
        SI_VAR(2) = 0;
        SI_VAR(3) = -170;
        SI_VAR(4) = -70;
        SI_VAR(5) = 0;
        SI_VAR(6) = 0;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80241B90);
    }
    spawn {
        SI_VAR(0) = 5;
        SI_VAR(1) = 0;
        SI_VAR(2) = 0;
        SI_VAR(3) = 200;
        SI_VAR(4) = -100;
        SI_VAR(5) = 0;
        SI_VAR(6) = 0;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80241B90);
    }
    SetTexPanner(5, 4);
    SetTexPanner(6, 4);
    SetTexPanner(12, 5);
    SetTexPanner(20, 5);
    if (STORY_PROGRESS < STORY_CH7_STAR_SPRIT_DEPARTED) {
        EnableModel(90, 0);
        if (STORY_PROGRESS < STORY_CH6_STAR_SPIRIT_RESCUED) {
            EnableModel(89, 0);
            if (STORY_PROGRESS < STORY_CH5_STAR_SPRIT_DEPARTED) {
                EnableModel(88, 0);
                if (STORY_PROGRESS < STORY_CH4_STAR_SPRIT_DEPARTED) {
                    EnableModel(87, 0);
                    if (STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
                        EnableModel(86, 0);
                        if (STORY_PROGRESS < STORY_CH2_STAR_SPRIT_DEPARTED) {
                            EnableModel(85, 0);
                            if (STORY_PROGRESS < STORY_CH1_STAR_SPRIT_DEPARTED) {
                                EnableModel(84, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    if (STORY_PROGRESS < STORY_CH8_OPENED_PATH_TO_STAR_WAY) {
        EnableModel(83, 0);
    } else {
        PlayEffect(0x75, 0, -30, 250, -160, 1, -1, 0, 0, 0, 0, 0, 0, 0);
        SI_MAP_VAR(10) = SI_VAR(15);
        SI_VAR(0) = 255;
        N(func_80240B64_A113E4)(SI_MAP_VAR(10), SI_VAR(0));
        GetEntryID(SI_VAR(0));
        if (SI_VAR(0) == 1) {
            N(func_80240B10_A11390)(SI_MAP_VAR(10));
        } else {
            N(func_80240AAC_A1132C)(SI_MAP_VAR(10));
        }
    }
    SetRenderMode(84, 22);
    SetRenderMode(85, 22);
    SetRenderMode(86, 22);
    SetRenderMode(87, 22);
    SetRenderMode(88, 22);
    SetRenderMode(89, 22);
    SetRenderMode(90, 22);
    func_802C90FC(84, 0, -1);
    func_802C90FC(85, 0, -1);
    func_802C90FC(86, 0, -1);
    func_802C90FC(87, 0, -1);
    func_802C90FC(88, 0, -1);
    func_802C90FC(89, 0, -1);
    func_802C90FC(90, 0, -1);
    func_802C94A0(0, N(func_80240BB8_A11438), 0);
    TranslateModel(83, 0, 2, 0);
    func_802C90FC(83, 1, -1);
    func_802C94A0(1, N(func_80240C34_A114B4), 0);
    spawn {
        loop {
            MakeLerp(255, 100, 60, 10);
            loop {
                UpdateLerp();
                N(func_80240C08_A11488)(SI_VAR(0));
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            MakeLerp(100, 255, 35, 10);
            loop {
                UpdateLerp();
                N(func_80240C08_A11488)(SI_VAR(0));
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
        }
    }
    spawn {
        if (STORY_PROGRESS >= STORY_CH8_OPENED_PATH_TO_STAR_WAY) {
            await N(80241C34);
        } else {
            N(func_80240C84_A11504)(0);
        10:
            if (SI_MAP_VAR(11) != 1) {
                sleep 1;
                goto 10;
            }
            MakeLerp(0, 180, 55, 10);
            loop {
                UpdateLerp();
                N(func_80240C84_A11504)(SI_VAR(0));
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            SI_MAP_VAR(11) = 2;
            await N(80241C34);
        }
    }
});

static s32 N(pad_2578)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80242580) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_802425AC) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_802425C8) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

Script N(80242604) = SCRIPT({
    SI_VAR(10) = 0;
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) >= 245) {
        IsPlayerWithin(-30, -165, 180, SI_VAR(3));
        if (SI_VAR(3) == 1) {
            goto 10;
        }
    }
    sleep 1;
    goto 0;
10:
    SI_VAR(10) = 1;
    FadeOutMusic(0, 2000);
    sleep 60;
20:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) < 245) {
        IsPlayerWithin(-30, -165, 180, SI_VAR(3));
        if (SI_VAR(3) == 0) {
            goto 30;
        }
    }
    sleep 1;
    goto 20;
30:
    SetMusicTrack(0, SONG_SHOOTING_STAR_SUMMIT, 0, 8);
    sleep 30;
    goto 0;
});

Script N(802427C8) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    UseSettingsFrom(0, -35, 250, -145);
    SetPanTarget(0, -35, 250, -145);
    SetCamDistance(0, 450);
    SetCamPitch(0, 20.0, -5.5);
    SetCamSpeed(0, 0.5);
    PanToTarget(0, 0, 1);
    func_802D2C14(2);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    spawn {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(2) += 30;
        SetNpcJumpscale(NPC_PARTNER, 0);
        NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15);
        SetNpcAnimation(NPC_PARTNER, 0x106);
    }
    SetMusicTrack(0, SONG_STAR_SPIRIT_THEME, 1, 8);
    SpeakToPlayer(NPC_WORLD_ELDSTAR, NPC_ANIM(world_eldstar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0000));
    sleep 10;
    sleep 1;
    PlayerFaceNpc(0, 1);
    SetNpcFlagBits(NPC_WORLD_ELDSTAR, ((NPC_FLAG_100)), TRUE);
    SetNpcJumpscale(NPC_WORLD_ELDSTAR, 0);
    NpcJump0(NPC_WORLD_ELDSTAR, 21, 260, -277, 30);
    EnableModel(84, 1);
    PlaySound(0x64);
    GetNpcPos(NPC_WORLD_MAMAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetNpcPos(NPC_WORLD_MUSKULAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetNpcPos(NPC_WORLD_MISSTAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetNpcPos(NPC_WORLD_KALMAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    N(func_80240CDC_A1155C)(0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    EnableModel(85, 1);
    EnableModel(86, 1);
    EnableModel(87, 1);
    EnableModel(88, 1);
    EnableModel(89, 1);
    EnableModel(90, 1);
    SI_MAP_VAR(1) = -80.0;
    loop 20 {
        SI_MAP_VAR(1) += 6.0;
        sleep 1;
    }
    EnableNpcShadow(NPC_WORLD_MAMAR, TRUE);
    EnableNpcShadow(NPC_WORLD_SKOLAR, TRUE);
    EnableNpcShadow(NPC_WORLD_MUSKULAR, TRUE);
    EnableNpcShadow(NPC_WORLD_MISSTAR, TRUE);
    EnableNpcShadow(NPC_WORLD_KLEVAR, TRUE);
    EnableNpcShadow(NPC_WORLD_KALMAR, TRUE);
    sleep 10;
    SpeakToPlayer(NPC_WORLD_ELDSTAR, NPC_ANIM(world_eldstar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0001));
    SetCamDistance(0, 270);
    SetCamSpeed(0, 2.80078125);
    GetNpcPos(NPC_WORLD_ELDSTAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -6.5);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_ELDSTAR, NPC_ANIM(world_eldstar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0002));
    GetNpcPos(NPC_WORLD_MAMAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -6.8994140625);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_MAMAR, NPC_ANIM(world_mamar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0003));
    GetNpcPos(NPC_WORLD_SKOLAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -7.2998046875);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_SKOLAR, NPC_ANIM(world_skolar, Palette_00, Anim_2), NPC_ANIM(world_mamar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0004));
    GetNpcPos(NPC_WORLD_MUSKULAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -7.69921875);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_MUSKULAR, NPC_ANIM(world_muskular, Palette_00, Anim_2), NPC_ANIM(world_muskular, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0005));
    GetNpcPos(NPC_WORLD_MISSTAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -7.69921875);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_MISSTAR, NPC_ANIM(world_misstar, Palette_00, Anim_2), NPC_ANIM(world_misstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0006));
    GetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -7.2998046875);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_3), NPC_ANIM(world_klevar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0007));
    GetNpcPos(NPC_WORLD_KALMAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamPitch(0, 20.0, -6.8994140625);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_KALMAR, NPC_ANIM(world_kalmar, Palette_00, Anim_2), NPC_ANIM(world_kalmar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0008));
    SI_AREA_VAR(6) = 200;
    sleep 30;
    SI_AREA_VAR(6) = 0;
    sleep 20;
    SpeakToPlayer(NPC_WORLD_KALMAR, NPC_ANIM(world_kalmar, Palette_00, Anim_2), NPC_ANIM(world_kalmar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0009));
    GetNpcPos(NPC_WORLD_ELDSTAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, -300);
    SetCamPitch(0, 16.0, -6.0);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_ELDSTAR, NPC_ANIM(world_eldstar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x000A));
    SI_AREA_VAR(0) = 200;
    SI_AREA_VAR(1) = 200;
    SI_AREA_VAR(2) = 200;
    SI_AREA_VAR(3) = 200;
    SI_AREA_VAR(4) = 200;
    SI_AREA_VAR(5) = 200;
    SI_AREA_VAR(6) = 200;
    sleep 30;
    SI_AREA_VAR(0) = 0;
    SI_AREA_VAR(1) = 0;
    SI_AREA_VAR(2) = 0;
    SI_AREA_VAR(3) = 0;
    SI_AREA_VAR(4) = 0;
    SI_AREA_VAR(5) = 0;
    SI_AREA_VAR(6) = 0;
    SpeakToPlayer(NPC_WORLD_ELDSTAR, NPC_ANIM(world_eldstar, Palette_00, Anim_2), NPC_ANIM(world_eldstar, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x000B));
    EnableNpcShadow(NPC_WORLD_ELDSTAR, FALSE);
    EnableNpcShadow(NPC_WORLD_MAMAR, FALSE);
    EnableNpcShadow(NPC_WORLD_SKOLAR, FALSE);
    EnableNpcShadow(NPC_WORLD_MUSKULAR, FALSE);
    EnableNpcShadow(NPC_WORLD_MISSTAR, FALSE);
    EnableNpcShadow(NPC_WORLD_KLEVAR, FALSE);
    EnableNpcShadow(NPC_WORLD_KALMAR, FALSE);
    FullyRestoreHPandFP();
    SI_AREA_VAR(0) = 100;
    SI_AREA_VAR(1) = 100;
    SI_AREA_VAR(2) = 100;
    SI_AREA_VAR(3) = 100;
    SI_AREA_VAR(4) = 100;
    SI_AREA_VAR(5) = 100;
    SI_AREA_VAR(6) = 100;
    SI_MAP_VAR(0) = 40.0;
    SI_MAP_VAR(1) = 40.0;
    loop 20 {
        SI_MAP_VAR(0) += -6.0;
        SI_MAP_VAR(1) += -6.0;
        sleep 1;
    }
    SI_MAP_FLAG(0) = 1;
    SI_AREA_VAR(0) = 0;
    SI_AREA_VAR(1) = 0;
    SI_AREA_VAR(2) = 0;
    SI_AREA_VAR(3) = 0;
    SI_AREA_VAR(4) = 0;
    SI_AREA_VAR(5) = 0;
    SI_AREA_VAR(6) = 0;
    EnableModel(84, 0);
    EnableModel(85, 0);
    EnableModel(86, 0);
    EnableModel(87, 0);
    EnableModel(88, 0);
    EnableModel(89, 0);
    EnableModel(90, 0);
    DisablePartnerAI(0);
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300);
    SetCamSpeed(0, 2.0);
    N(func_80240CB0_A11530)(1);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SI_VAR(2) += 30;
    SetNpcSpeed(NPC_PARTNER, 2.0);
    NpcMoveTo(NPC_PARTNER, SI_VAR(0), SI_VAR(2), 0);
    WaitForCam(0, 1.0);
    sleep 10;
    PlayerFaceNpc(-4, 0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0, MESSAGE_ID(0x0A, 0x000C));
    EnablePartnerAI();
    spawn {
        STORY_PROGRESS = STORY_CH0_MET_STAR_SPIRITS;
        ResetCam(0, 1.5);
    }
    FadeOutMusic(0, 3000);
    sleep 10;
    DisablePlayerInput(FALSE);
});

Script N(interact_8024373C) = SCRIPT({
    spawn N(802427C8);
});

Script N(aux_80243758) = SCRIPT({
    SI_AREA_VAR(0) = 0;
    SI_AREA_VAR(1) = 0;
    SI_AREA_VAR(2) = 0;
    SI_AREA_VAR(3) = 0;
    SI_AREA_VAR(4) = 0;
    SI_AREA_VAR(5) = 0;
    SI_AREA_VAR(6) = 0;
    spawn {
        loop {
            if (SI_AREA_VAR(0) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(0) = 200;
                sleep 10;
                SI_AREA_VAR(0) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(1) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(1) = 200;
                sleep 10;
                SI_AREA_VAR(1) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(2) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(2) = 200;
                sleep 10;
                SI_AREA_VAR(2) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(3) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(3) = 200;
                sleep 10;
                SI_AREA_VAR(3) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(4) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(4) = 200;
                sleep 10;
                SI_AREA_VAR(4) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(5) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(5) = 200;
                sleep 10;
                SI_AREA_VAR(5) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    spawn {
        loop {
            if (SI_AREA_VAR(6) == 0) {
                RandInt(45, SI_VAR(1));
                SI_VAR(1) += 105;
                SI_AREA_VAR(6) = 200;
                sleep 10;
                SI_AREA_VAR(6) = 0;
                sleep SI_VAR(1);
            } else {
                sleep 1;
            }
        }
    }
    loop {
        SI_VAR(0) = (float) 0;
        SI_VAR(1) = (float) 0;
        loop 20 {
            SI_VAR(0) += 4.0;
            SI_VAR(1) += 4.0;
            SI_VAR(2) = (float) SI_VAR(0);
            SI_VAR(2) += (float) SI_MAP_VAR(0);
            SI_VAR(3) = (float) SI_VAR(1);
            SI_VAR(3) += (float) SI_MAP_VAR(1);
            if (SI_VAR(2) < 0) {
                SI_VAR(2) = 0.0;
            }
            if (SI_VAR(3) < 0) {
                SI_VAR(3) = 0.0;
            }
            func_802CFD30(NPC_WORLD_ELDSTAR, 13, 0, SI_AREA_VAR(0), 1, SI_VAR(2));
            func_802CFD30(NPC_WORLD_MAMAR, 13, 0, SI_AREA_VAR(1), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_SKOLAR, 13, 0, SI_AREA_VAR(2), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_MUSKULAR, 13, 0, SI_AREA_VAR(3), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_MISSTAR, 13, 0, SI_AREA_VAR(4), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_KLEVAR, 13, 0, SI_AREA_VAR(5), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_KALMAR, 13, 0, SI_AREA_VAR(6), 1, SI_VAR(3));
            sleep 1;
        }
        loop 20 {
            SI_VAR(0) += -4.0;
            SI_VAR(1) += -4.0;
            SI_VAR(2) = (float) SI_VAR(0);
            SI_VAR(2) += (float) SI_MAP_VAR(0);
            SI_VAR(3) = (float) SI_VAR(1);
            SI_VAR(3) += (float) SI_MAP_VAR(1);
            if (SI_VAR(2) < 0) {
                SI_VAR(2) = 0.0;
            }
            if (SI_VAR(3) < 0) {
                SI_VAR(3) = 0.0;
            }
            func_802CFD30(NPC_WORLD_ELDSTAR, 13, 0, SI_AREA_VAR(0), 1, SI_VAR(2));
            func_802CFD30(NPC_WORLD_MAMAR, 13, 0, SI_AREA_VAR(1), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_SKOLAR, 13, 0, SI_AREA_VAR(2), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_MUSKULAR, 13, 0, SI_AREA_VAR(3), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_MISSTAR, 13, 0, SI_AREA_VAR(4), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_KLEVAR, 13, 0, SI_AREA_VAR(5), 1, SI_VAR(3));
            func_802CFD30(NPC_WORLD_KALMAR, 13, 0, SI_AREA_VAR(6), 1, SI_VAR(3));
            sleep 1;
        }
    }
});

Script N(init_80244058) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024373C));
    BindNpcAux(-1, N(aux_80243758));
    if (STORY_PROGRESS < STORY_CH0_MET_STAR_SPIRITS) {
        spawn N(80242604);
    }
    if (STORY_PROGRESS >= STORY_CH0_MET_STAR_SPIRITS) {
        SetNpcPos(NPC_WORLD_ELDSTAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_MAMAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_SKOLAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_MUSKULAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_MISSTAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_KLEVAR, 0, -1000, 0);
        SetNpcPos(NPC_WORLD_KALMAR, 0, -1000, 0);
        return;
    }
    EnableNpcShadow(NPC_WORLD_MAMAR, FALSE);
    EnableNpcShadow(NPC_WORLD_SKOLAR, FALSE);
    EnableNpcShadow(NPC_WORLD_MUSKULAR, FALSE);
    EnableNpcShadow(NPC_WORLD_MISSTAR, FALSE);
    EnableNpcShadow(NPC_WORLD_KLEVAR, FALSE);
    EnableNpcShadow(NPC_WORLD_KALMAR, FALSE);
    SI_MAP_VAR(0) = 40;
    SI_MAP_VAR(1) = -80;
});

StaticNpc N(npcGroup_80244230)[] = {
    {
        .id = NPC_WORLD_ELDSTAR,
        .settings = &N(npcSettings_80242580),
        .pos = { -30.0f, 260.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80244058),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_0),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
            NPC_ANIM(world_eldstar, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x000A),
    },
    {
        .id = NPC_WORLD_MAMAR,
        .settings = &N(npcSettings_80242580),
        .pos = { 100.0f, 260.0f, -215.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_0),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
            NPC_ANIM(world_mamar, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_WORLD_SKOLAR,
        .settings = &N(npcSettings_80242580),
        .pos = { -145.0f, 260.0f, -225.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_0),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
            NPC_ANIM(world_skolar, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_WORLD_MUSKULAR,
        .settings = &N(npcSettings_80242580),
        .pos = { 20.0f, 260.0f, -45.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_0),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
            NPC_ANIM(world_muskular, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_WORLD_MISSTAR,
        .settings = &N(npcSettings_80242580),
        .pos = { -155.0f, 260.0f, -125.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_0),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
            NPC_ANIM(world_misstar, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_WORLD_KLEVAR,
        .settings = &N(npcSettings_80242580),
        .pos = { 90.0f, 260.0f, -110.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_0),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
            NPC_ANIM(world_klevar, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_WORLD_KALMAR,
        .settings = &N(npcSettings_80242580),
        .pos = { -75.0f, 260.0f, -290.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_0),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
            NPC_ANIM(world_kalmar, Palette_00, Anim_1),
        },
    },
};

NpcGroupList N(npcGroupList_80244FC0) = {
    NPC_GROUP(N(npcGroup_80244230), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_4FD8)[] = {
    0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAB04, -210, 30, 285, 0, ITEM_CASTLE_KEY1, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(539));
    MakeItemEntity(ITEM_STAR_PIECE, -350, 0, -275, 17, SI_SAVE_FLAG(544));
});

static s32 N(pad_504C) = {
    0x00000000,
};

Script N(80245050) = SCRIPT({
0:
    N(dup_GetFloorCollider)(SI_VAR(0));
    if (SI_VAR(0) != 16) {
        sleep 1;
        goto 0;
    }
    DisablePlayerInput(TRUE);
    func_802D5830(1);
    func_802D2884(-30, -160, 0);
    sleep 15;
    ShowMessageAtScreenPos(MESSAGE_ID(0x0A, 0x005C), 160, 40);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -100;
    SI_VAR(0) /= 2;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300);
    SetCamPitch(0, 17.0, -9.0);
    SetCamSpeed(0, 3);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    ShowMessageAtScreenPos(MESSAGE_ID(0x0A, 0x005D), 160, 40);
    SetMusicTrack(0, SONG_STAR_WAY_OPENS, 0, 8);
    sleep 10;
    EnableModel(83, 1);
    SI_MAP_VAR(11) = 1;
10:
    if (SI_MAP_VAR(11) != 2) {
        sleep 1;
        goto 10;
    }
    UseSettingsFrom(0, -100, 245, 0);
    SetPanTarget(0, -100, 245, 0);
    SetCamDistance(0, 600);
    SetCamPitch(0, 17.0, -11.0);
    SetCamSpeed(0, 1.5);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PlayEffect(0x75, 0, -30, 250, -160, 1, -1, 0, 0, 0, 0, 0, 0, 0);
    SI_MAP_VAR(10) = SI_VAR(15);
    N(func_80240AAC_A1132C)(SI_MAP_VAR(10));
    MakeLerp(1, 255, 55, 1);
    loop {
        UpdateLerp();
        N(func_80240B64_A113E4)(SI_MAP_VAR(10), SI_VAR(0));
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    sleep 45;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -100;
    SI_VAR(0) /= 2;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300);
    SetCamPitch(0, 17.0, -9.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    ShowMessageAtScreenPos(MESSAGE_ID(0x0A, 0x005E), 160, 40);
    ResetCam(0, 5.0);
    STORY_PROGRESS = STORY_CH8_OPENED_PATH_TO_STAR_WAY;
    SetMusicTrack(0, SONG_SHOOTING_STAR_SUMMIT, 0, 8);
    func_802D5830(0);
    DisablePlayerInput(FALSE);
});

Script N(80245580) = SCRIPT({
    N(func_80240B10_A11390)(SI_MAP_VAR(10));
    UseSettingsFrom(0, -30, 250, -160);
    SetPanTarget(0, -30, 250, -160);
    SetCamSpeed(0, 1.0);
    PanToTarget(0, 0, 1);
    SetPlayerSpeed(3.0);
    PlayerMoveTo(-30, -160, 0);
    InterpPlayerYaw(90, 0);
    SetMusicTrack(0, SONG_STAR_WAY_OPENS, 1, 8);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_PARTNER, ((0x00000040 | NPC_FLAG_100)), TRUE);
    SetNpcJumpscale(NPC_PARTNER, 1.0);
    NpcJump0(NPC_PARTNER, -30, 250, -170, 15);
    spawn {
        SI_VAR(2) = 90;
        MakeLerp(1, 90, 60, 1);
        loop {
            UpdateLerp();
            SI_VAR(2) += SI_VAR(0);
            InterpPlayerYaw(SI_VAR(2), 0);
            SetNpcRotation(NPC_PARTNER, 0, SI_VAR(2), 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        loop {
            SI_VAR(2) += SI_VAR(0);
            InterpPlayerYaw(SI_VAR(2), 0);
            SetNpcRotation(NPC_PARTNER, 0, SI_VAR(2), 0);
            sleep 1;
        }
    }
    sleep 30;
    N(UnsetCamera0MoveFlag1)();
    spawn {
    10:
        SetCamSpeed(0, 90.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(1) < 430) {
            sleep 1;
            goto 10;
        }
    }
    GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
    SI_VAR(5) = SI_VAR(4);
    SI_VAR(5) += -10;
    MakeLerp(SI_VAR(3), 700, 90, 1);
    loop {
        UpdateLerp();
        SetPlayerPos(SI_VAR(2), SI_VAR(0), SI_VAR(4));
        SetNpcPos(NPC_PARTNER, SI_VAR(2), SI_VAR(0), SI_VAR(5));
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

#include "world/common/GetFloorCollider.inc.c"
