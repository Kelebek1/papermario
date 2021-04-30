#include "hos_00.h"
#include "message_ids.h"
#include "sprite/npc/flying_magikoopa.h"
#include "sprite/npc/three_sisters.h"
#include "sprite/npc/toad_kid.h"
#include "sprite/npc/twink.h"
#include "sprite/npc/world_goombario.h"

EntryList N(entryList) = {
    { -610.0f,   0.0f,  -45.0f,  90.0f },
    {  870.0f,  60.0f, -130.0f, 270.0f },
    {  870.0f, -10.0f,   30.0f, 270.0f },
    {  870.0f, -10.0f,   30.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_hos_00_tattle },
};

Script N(80240D90) = SCRIPT({
    match STORY_PROGRESS {
        -13..5 {
            SetMusicTrack(0, SONG_SHY_GUY_INVASION, 0, 6);
        }
        else {
            SetMusicTrack(0, SONG_TOAD_TOWN, 0, 6);
        }
    }
});

ApiStatus N(func_80240050_A0BD40)(ScriptInstance *script, s32 isInitialCall) {
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

ApiStatus N(func_80240170_A0BE60)(ScriptInstance *script, s32 isInitialCall) {
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

ApiStatus N(func_8024036C_A0C05C)(ScriptInstance *script, s32 isInitialCall) {
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

ApiStatus N(func_80240584_A0C274)(ScriptInstance *script, s32 isInitialCall) {
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

// *INDENT-OFF*
Script N(80240E04) = {
    SI_CMD(ScriptOpcode_CALL, GetEntryID, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_EQ, 0),
            SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80240D90)),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_CALL, SetMusicTrack, 0, 97, 0, 8),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_GOTO, 20),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_LABEL, 10),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
    SI_CMD(ScriptOpcode_IF_GT, SI_VAR(1), 210),
        SI_CMD(ScriptOpcode_CALL, FadeOutMusic, 0, 833),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 25),
        SI_CMD(ScriptOpcode_CALL, SetMusicTrack, 0, 97, 0, 8),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
        SI_CMD(ScriptOpcode_GOTO, 20),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_GOTO, 10),
    SI_CMD(ScriptOpcode_LABEL, 20),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(0), -105),
        SI_CMD(ScriptOpcode_GOTO, 20),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
    SI_CMD(ScriptOpcode_IF_LT, SI_VAR(1), -55),
        SI_CMD(ScriptOpcode_CALL, FadeOutMusic, 0, 833),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 25),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80240D90)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
        SI_CMD(ScriptOpcode_GOTO, 10),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_GOTO, 20),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(8024101C) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        SetMusicTrack(0, SONG_STARSHIP_THEME, 0, 8);
    } else {
        spawn N(80240E04);
    }
});

Script N(80241084) = SCRIPT({
    SetMusicTrack(0, SONG_KAMMY_KOOPA_THEME, 0, 8);
});

Script N(802410B0) = SCRIPT({
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
    N(func_80240050_A0BD40)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7));
    sleep SI_VAR(8);
    goto 0;
});

Script N(802413EC) = SCRIPT({
    group 11;
    spawn {
    0:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 10;
        N(func_80240170_A0BE60)();
        sleep SI_VAR(0);
        goto 0;
    }
    spawn {
    1:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 20;
        N(func_8024036C_A0C05C)();
        sleep SI_VAR(0);
        goto 1;
    }
    spawn {
    2:
        RandInt(50, SI_VAR(0));
        SI_VAR(0) += 20;
        N(func_80240584_A0C274)();
        PlaySoundAt(0xB0000015, 0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        sleep SI_VAR(0);
        goto 2;
    }
});

Script N(exitWalk_80241554) = SCRIPT({
    group 27;
    UseExitHeading(60, 0);
    spawn ExitWalk;
    match STORY_PROGRESS {
        -127..95 {
            GotoMap("osr_01", 1);
        } else {
            GotoMap("osr_00", 1);
        }
    }
    sleep 100;
});

Script N(exitWalk_802415F0) = EXIT_WALK_SCRIPT(60,  1, "hos_01",  0);

Script N(exitWalk_8024164C) = EXIT_WALK_SCRIPT(60,  2, "hos_06",  0);

const s32 N(pad_XXX)[] = { 0, 0 };

Script N(802416A8) = SCRIPT({
    bind N(exitWalk_80241554) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_802415F0) to TRIGGER_FLOOR_ABOVE 4;
    bind N(exitWalk_8024164C) to TRIGGER_FLOOR_ABOVE 8;
});

Script N(8024170C) = SCRIPT({
    group 0;
    SI_VAR(0) = 0;
    loop {
        SetTexPanOffset(13, 0, SI_VAR(0), 0);
        SI_VAR(0) += 16384;
        sleep 15;
    }
});

Script N(enterWalk_80241784) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn N(80244AF0);
        spawn EnterSavePoint;
        spawn N(802416A8);
        return;
    }
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        SetGroupEnabled(1, 0);
        spawn N(80241B60);
        return;
    } else {
        spawn N(80244AF0);
        SI_VAR(0) = N(802416A8);
        spawn EnterWalk;
        sleep 1;
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_SHOOTING_STAR_SUMMIT;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SI_SAVE_FLAG(1964) = 1;
    SI_SAVE_FLAG(263) = 0;
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        MakeNpcs(0, N(npcGroupList_80242810));
    } else {
        MakeNpcs(0, N(npcGroupList_802427EC));
    }
    await N(makeEntities);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 3) {
        spawn N(802410B0);
    }
    await N(8024101C);
    if (STORY_PROGRESS == STORY_CH0_BEGAN_PEACH_MISSION) {
        if (SI_AREA_FLAG(180) == 0) {
            sleep 50;
            SI_AREA_FLAG(180) = 1;
        }
        spawn N(80242F20);
    }
    spawn N(enterWalk_80241784);
    spawn N(8024170C);
});

static s32 N(pad_1A28)[] = {
    0x00000000, 0x00000000,
};

Script N(80241A30) = SCRIPT({
0:
    SetTexPanOffset(13, 0, 0, 0);
    sleep 10;
    SetTexPanOffset(13, 0, 16384, 0);
    sleep 10;
    goto 0;
});

static s32 N(pad_1AA8)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80241AB0) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80241ADC) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

s32 N(unk_missing_80241B08)[] = {
    0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00630000,
};

NpcSettings N(npcSettings_80241B34) = {
    .height = 34,
    .radius = 24,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 26,
};

const char N(osr_01_name_hack)[];

Script N(80241B60) = SCRIPT({
    DisablePlayerInput(TRUE);
    UseSettingsFrom(0, 305, -10, -50);
    SetPanTarget(0, 305, -10, -50);
    SetCamDistance(0, 400.0);
    SetCamPitch(0, 9.0, -10.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 30;
    SpeakToPlayer(NPC_TOAD_KID, NPC_ANIM(toad_kid, Palette_00, Anim_4), NPC_ANIM(toad_kid, Palette_00, Anim_6), 0, MESSAGE_ID(0x0A, 0x006C));
    sleep 10;
    SetNpcAnimation(NPC_TOAD_KID, NPC_ANIM(toad_kid, Palette_00, Anim_1));
    SpeakToPlayer(NPC_THREE_SISTERS, NPC_ANIM(three_sisters, Palette_01, Anim_4), NPC_ANIM(three_sisters, Palette_01, Anim_1), 0, MESSAGE_ID(0x0A, 0x006D));
    sleep 10;
    SpeakToPlayer(NPC_TOAD_KID, NPC_ANIM(toad_kid, Palette_00, Anim_4), NPC_ANIM(toad_kid, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x006E));
    sleep 50;
    GotoMap(N(osr_01_name_hack), 3);
    sleep 100;
});

Script N(defeat_80241CE8) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            GetPlayerPos(SI_VAR(3), SI_VAR(1), SI_VAR(2));
            SetPlayerPos(SI_VAR(3), SI_VAR(1), -45);
            SI_VAR(3) += 40;
            SetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(1), -45);
            GetNpcPos(NPC_TWINK, SI_VAR(3), SI_VAR(1), SI_VAR(2));
            SI_VAR(3) += -25;
            SetNpcPos(NPC_TWINK, SI_VAR(3), SI_VAR(1), -45);
            spawn N(80244210);
            DoNpcDefeat();
        }
        == 1 {}
        == 2 {
        }
    }
});

Script N(idle_80241DFC) = SCRIPT({
0:
    GetSelfVar(0, SI_VAR(0));
    match SI_VAR(0) {
        == 0 {}
        == 1 {
            StartBossBattle(3);
        }
    }
    sleep 1;
    goto 0;
});

Script N(init_80241E80) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH0_TWINK_GAVE_LUCKY_STAR) {
        BindNpcIdle(NPC_SELF, N(idle_80241DFC));
        BindNpcDefeat(NPC_SELF, N(defeat_80241CE8));
    } else {
        RemoveNpc(NPC_SELF);
    }
});

Script N(idle_80241EE8) = SCRIPT({
    SetSelfVar(0, 0);
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            break loop;
        }
        sleep 1;
    }
    EnablePartner(11);
    N(func_802407C0_A0C4B0)(11);
    StartBattle();
});

Script N(interact_80241F8C) = SCRIPT({

});

Script N(defeat_80241F9C) = SCRIPT({
    SetSelfVar(0, 2);
    DisablePartner(11);
    N(func_802407C0_A0C4B0)(1);
});

Script N(init_80241FE0) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_80241EE8));
    BindNpcInteract(NPC_SELF, N(interact_80241F8C));
    BindNpcDefeat(NPC_SELF, N(defeat_80241F9C));
});

StaticNpc N(npcGroup_8024202C) = {
    .id = NPC_TWINK,
    .settings = &N(npcSettings_80241AB0),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241FE0),
    .yaw = 90,
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

StaticNpc N(npcGroup_8024221C) = {
    .id = NPC_FLYING_MAGIKOOPA,
    .settings = &N(npcSettings_80241B34),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_40000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_80241E80),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_0),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_4),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_4),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_2),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_3),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
        NPC_ANIM(flying_magikoopa, Palette_00, Anim_1),
    },
};

StaticNpc N(npcGroup_8024240C)[] = {
    {
        .id = NPC_THREE_SISTERS,
        .settings = &N(npcSettings_80241ADC),
        .pos = { 280.0f, -10.0f, -50.0f },
        .flags = NPC_FLAG_PASSIVE,
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_2),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
        },
    },
    {
        .id = NPC_TOAD_KID,
        .settings = &N(npcSettings_80241ADC),
        .pos = { 330.0f, -10.0f, -40.0f },
        .flags = NPC_FLAG_PASSIVE,
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(toad_kid, Palette_00, Anim_1),
            NPC_ANIM(toad_kid, Palette_00, Anim_2),
            NPC_ANIM(toad_kid, Palette_00, Anim_3),
            NPC_ANIM(toad_kid, Palette_00, Anim_3),
            NPC_ANIM(toad_kid, Palette_00, Anim_1),
            NPC_ANIM(toad_kid, Palette_00, Anim_1),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
            NPC_ANIM(toad_kid, Palette_00, Anim_0),
        },
    },
};

NpcGroupList N(npcGroupList_802427EC) = {
    NPC_GROUP(N(npcGroup_8024202C), BATTLE_ID(4, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_8024221C), BATTLE_ID(4, 3, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80242810) = {
    NPC_GROUP(N(npcGroup_8024240C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_2828)[] = {
    0x00000000, 0x00000000,
};

Script N(80242830) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x016E), 160, 40);
    DisablePlayerInput(FALSE);
});

Script N(80242878) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x016D), 160, 40);
    DisablePlayerInput(FALSE);
});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAFDC, 450, 10, -185, 0, MAKE_ENTITY_END);
    AssignScript(N(80242830));
    MakeEntity(0x802EAFDC, 855, -10, -40, 0, MAKE_ENTITY_END);
    AssignScript(N(80242878));
    MakeEntity(0x802EAB04, 380, -10, 25, 0, ITEM_FORTRESS_KEY, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(538));
});

s32* N(D_80242970_A0E660) = NULL;

Script N(80242974) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

Script N(802429A4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

Vec3f N(vectorList_802429D4)[] = {
     { 0.0, 0.0, 2.0 }, { 73.0, -6.0, 2.0 },
     { 106.0, 32.0, 2.0 }, { 70.0, 43.0, 2.0 },
     { 30.0, 12.0, 2.0 }, { -17.0, -19.0, 2.0 },
     { -35.0, 29.0, 2.0 }, { -20.0, 43.0, 2.0 },
     { -11.0, 39.0, 2.0 }, { 0.0, -1.0, 0.0 },
    
};

Vec3f N(vectorList_80242A4C)[] = {
     { 15.0, 174.0, -45.0 }, { -157.0, 92.0, -44.0 },
     { -371.0, 103.0, -45.0 }, { -350.0, 75.0, -45.0 },
     { -250.0, 40.0, -45.0 },
};

Vec3f N(vectorList_80242A88)[] = {
     { 0.0, 0.0, 0.0 }, { -60.0, 3.0, -11.0 },
     { -55.0, 13.0, 0.0 }, { 4.0, 40.0, -5.0 },
     { 23.0, 35.0, -10.0 }, { 63.0, 25.0, -20.0 },
     { 94.0, 30.0, -40.0 }, { 134.0, 250.0, -80.0 },
    
};

Vec3f N(vectorList_80242AE8)[] = {
     { -72.0, 318.0, -80.0 }, { -127.0, 153.0, -60.0 },
     { -174.0, 114.0, -44.0 }, { -243.0, 90.0, -45.0 },
     { -268.0, 50.0, -46.0 }, { -174.0, 10.0, -43.0 },
    
};

Vec3f N(vectorList_80242B30)[] = {
     { 0.0, 0.0, 0.0 }, { -30.0, 3.0, -11.0 },
     { -55.0, 13.0, 0.0 }, { -73.0, 20.0, -5.0 },
     { -103.0, 40.0, 0.0 }, { -143.0, 60.0, 0.0 },
     { -173.0, 50.0, 26.0 }, { -126.0, 35.0, 16.0 },
     { 1111.0, 570.0, -527.0 },
};

f32 N(D_80242B9C_A0E88C) = 0.0f;

f32 N(D_80242BA0_A0E890) = 0.0f;

Script N(80242BA4) = SCRIPT({
    GetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(6), SI_VAR(7), SI_VAR(8));
0:
    GetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(9) = SI_VAR(3);
    SI_VAR(10) = SI_VAR(4);
    SI_VAR(11) = SI_VAR(5);
    SI_VAR(3) -= SI_VAR(6);
    SI_VAR(4) -= SI_VAR(7);
    SI_VAR(5) -= SI_VAR(8);
    N(func_80240A54_A0C744)();
    SI_VAR(6) = SI_VAR(9);
    SI_VAR(7) = SI_VAR(10);
    SI_VAR(8) = SI_VAR(11);
    PlayerFaceNpc(1, 0);
    GetAngleBetweenNPCs(0, 1, SI_VAR(0));
    InterpNpcYaw(NPC_TWINK, SI_VAR(0), 0);
    GetAngleBetweenNPCs(-4, 1, SI_VAR(0));
    InterpNpcYaw(NPC_PARTNER, SI_VAR(0), 0);
    sleep 1;
    goto 0;
});

Script N(80242D20) = SCRIPT({
    loop {
        InterpNpcYaw(NPC_TWINK, 270, 0);
        sleep 10;
        InterpNpcYaw(NPC_TWINK, 90, 0);
        sleep 10;
    }
});

Script N(80242D8C) = SCRIPT({
    loop {
        loop 5 {
            GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 3;
        }
        sleep 3;
        loop 5 {
            GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += -1;
            SetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 3;
        }
        sleep 3;
    }
});

Script N(80242E98) = SCRIPT({
    loop {
        GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 15;
        SI_VAR(2) += 2;
        SetItemPos(SI_MAP_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
});

Script N(80242F20) = SCRIPT({
    loop {
        sleep 1;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(0) < -100) {
            break loop;
        }
    }
    DisablePlayerInput(TRUE);
    func_802CF56C(2);
    spawn {
        SI_VAR(0) += -20;
        PlayerMoveTo(SI_VAR(0), SI_VAR(2), 10);
    }
    SetNpcPos(NPC_TWINK, 50, 180, 0);
    SetNpcJumpscale(NPC_TWINK, 0);
    SI_VAR(0) += -10;
    NpcJump0(NPC_TWINK, SI_VAR(0), 20, SI_VAR(2), 15);
    PlaySoundAtPlayer(225, 0);
    SetPlayerAnimation(ANIM_SHOCK_STILL);
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_E));
    spawn {
        SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_16));
        SetNpcJumpscale(NPC_TWINK, 0.6005859375);
        GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += -100;
        NpcJump0(NPC_TWINK, SI_VAR(0), 10, SI_VAR(2), 20);
        SetPlayerAnimation(ANIM_10002);
    }
    spawn {
        ShakeCam(0, 0, 5, 2.0);
    }
    spawn {
        SI_VAR(3) = 360;
        loop 3 {
        22:
            sleep 1;
            SI_VAR(3) -= 45;
            if (SI_VAR(3) > 0) {
                SetNpcRotation(NPC_TWINK, 0, SI_VAR(3), 0);
                if (SI_VAR(3) == 270) {
                    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1A));
                }
                if (SI_VAR(3) == 90) {
                    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_16));
                }
                goto 22;
            }
        }
        SetNpcRotation(NPC_TWINK, 0, 0, 0);
    }
    ShowMessageAtScreenPos(MESSAGE_ID(0x0A, 0x000D), 160, 40);
    SetMusicTrack(0, SONG_TWINK_THEME, 0, 8);
    SetPlayerAnimation(ANIM_10002);
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1));
    NpcFacePlayer(NPC_TWINK, 0);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_C), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x000E));
    N(func_80240B20_A0C810)();
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -20;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 275);
    SetCamPitch(0, 16.0, -8.5);
    SetCamSpeed(0, 3.0);
    PanToTarget(0, 0, 1);
    SetNpcSpeed(NPC_TWINK, 3.0);
    GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 40;
    NpcMoveTo(NPC_TWINK, SI_VAR(0), SI_VAR(2), 0);
    ShowEmote(0, EMOTE_SHOCK, 45, 20, 1, 0, 0, 0, 0);
    sleep 20;
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_F));
    SetNpcJumpscale(NPC_TWINK, 1.0);
    loop 2 {
        GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcJump0(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15);
    }
    DisablePartnerAI(0);
    SetNpcJumpscale(NPC_PARTNER, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 25;
    NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x000F));
    sleep 5;
    GetNpcPos(NPC_TWINK, SI_VAR(4), SI_VAR(5), SI_VAR(6));
    LoadPath(70, N(vectorList_802429D4), 10, 0);
1:
    GetNextPathPos();
    SI_VAR(1) += (float) SI_VAR(4);
    SI_VAR(2) += (float) SI_VAR(5);
    SI_VAR(3) += (float) SI_VAR(6);
    SetNpcPos(NPC_TWINK, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    N(func_80240994_A0C684)();
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 1;
    }
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1));
    sleep 10;
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0010));
    SetNpcYaw(NPC_TWINK, 270);
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1A));
    SpeakToPlayer(NPC_TWINK, -1, -1, 5, MESSAGE_ID(0x0A, 0x0011));
    GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    MakeItemEntity(ITEM_LUCKY_STAR, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
    SI_MAP_VAR(10) = SI_VAR(0);
    SI_VAR(8) = spawn N(80242D8C);
    SI_VAR(9) = spawn N(80242E98);
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_17));
    ContinueSpeech(0, -1, -1, 512, MESSAGE_ID(0x0A, 0x0012));
    GetPlayerPos(SI_VAR(5), SI_VAR(3), SI_VAR(4));
    SI_VAR(5) += -30;
    NpcMoveTo(NPC_TWINK, SI_VAR(5), SI_VAR(4), 15);
    kill SI_VAR(9);
    kill SI_VAR(8);
    spawn {
        GetNpcPos(NPC_TWINK, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 15;
        SI_VAR(4) = SI_VAR(1);
        SI_VAR(4) += 30;
        SI_VAR(3) = SI_VAR(0);
        MakeLerp(SI_VAR(1), SI_VAR(4), 7, 4);
        loop {
            UpdateLerp();
            SetItemPos(SI_MAP_VAR(10), SI_VAR(3), SI_VAR(0), SI_VAR(2));
            sleep 1;
            SI_VAR(3) += 2;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        GetPlayerPos(SI_VAR(5), SI_VAR(6), SI_VAR(7));
        SI_VAR(6) += 38;
        MakeLerp(SI_VAR(0), SI_VAR(6), 7, 1);
        loop {
            UpdateLerp();
            SetItemPos(SI_MAP_VAR(10), SI_VAR(3), SI_VAR(0), SI_VAR(2));
            sleep 1;
            SI_VAR(3) += 2;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        RemoveItemEntity(SI_MAP_VAR(10));
    }
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_14));
    sleep 11;
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_15));
    SI_VAR(0) = 7;
    SI_VAR(1) = 4;
    ShowGotItem(SI_VAR(0), 1, 0);
    AddKeyItem(SI_VAR(0));
    N(func_80240908_A0C5F8)();
    SetNpcAnimation(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_1));
    sleep 20;
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0013));
    ShowChoice(MESSAGE_ID(0x1E, 0x0013));
    if (SI_VAR(0) == 1) {
        ContinueSpeech(0, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0014));
        ShowChoice(MESSAGE_ID(0x1E, 0x0013));
        if (SI_VAR(0) != 0) {
            ContinueSpeech(0, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0015));
        } else {
            goto 15;
        }
    } else {
    15:
        ContinueSpeech(0, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0016));
        SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0, MESSAGE_ID(0x0A, 0x0017));
        SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0018));
        SetPlayerAnimation(ANIM_80007);
        SetNpcVar(0, 0, 1);
        loop {
            GetNpcVar(0, 0, SI_VAR(0));
            if (SI_VAR(0) == 2) {
                break loop;
            }
            sleep 1;
        }
    }
    DisablePartnerAI(0);
    SetNpcAnimation(NPC_PARTNER, 0x106);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x002F));
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0, MESSAGE_ID(0x0A, 0x0030));
    sleep 20;
    spawn N(80241084);
    ShowMessageAtScreenPos(MESSAGE_ID(0x0A, 0x0031), 320, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 3.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    spawn {
        sleep 20;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += -250;
        SI_VAR(0) /= 2;
        SetPanTarget(0, -250, 53, 0);
        SetCamSpeed(0, 1.400390625);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        sleep 10;
        SetPanTarget(0, SI_VAR(0), 0, 0);
        SetCamSpeed(0, 2.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
    }
    SI_VAR(10) = spawn N(80242BA4);
    LoadPath(67, N(vectorList_80242A4C), 5, 0);
2:
    GetNextPathPos();
    SetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 2;
    }
    kill SI_VAR(10);
    parallel {
        loop {
            loop 10 {
                GetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SI_VAR(1) += 1;
                SetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                sleep 2;
            }
            sleep 3;
            loop 10 {
                GetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SI_VAR(1) += -1;
                SetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                sleep 2;
            }
            sleep 3;
        }
    }
    SetNpcAnimation(NPC_FLYING_MAGIKOOPA, NPC_ANIM(flying_magikoopa, Palette_00, Anim_0));
    loop 3 {
        SetNpcRotation(NPC_FLYING_MAGIKOOPA, 0, 0, 10);
        sleep 1;
        SetNpcRotation(NPC_FLYING_MAGIKOOPA, 0, 0, 0);
        sleep 1;
    }
    sleep 20;
    SI_VAR(10) = spawn N(80242D20);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_0), 5, MESSAGE_ID(0x0A, 0x0032));
    kill SI_VAR(10);
    sleep 10;
    GetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), 0, SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 260.0);
    SetCamPitch(0, 13.0, -8.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 1;
    SpeakToPlayer(NPC_FLYING_MAGIKOOPA, NPC_ANIM(flying_magikoopa, Palette_00, Anim_9), NPC_ANIM(flying_magikoopa, Palette_00, Anim_0), 512, MESSAGE_ID(0x0A, 0x0033));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -250;
    SI_VAR(0) /= 2;
    UseSettingsFrom(0, SI_VAR(0), 0, 0);
    SetPanTarget(0, SI_VAR(0), 0, 0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    SetNpcVar(1, 0, 1);
    EnablePartnerAI();
    unbind;
});

Script N(80244210) = SCRIPT({
    func_802D5830(1);
    SetMusicTrack(0, SONG_TWINK_THEME, 0, 8);
    sleep 60;
    SetCamLeadPlayer(0, 1);
    GetNpcPos(NPC_TWINK, SI_VAR(3), SI_VAR(1), SI_VAR(2));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(0) /= 2;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 275.0);
    SetCamPitch(0, 16.0, -9.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 1;
    InterpNpcYaw(NPC_TWINK, 90, 0);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0034));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerJumpscale(0.5);
    PlayerJump(SI_VAR(0), SI_VAR(1), SI_VAR(2), 15);
    sleep 10;
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0035));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 700.0);
    SetCamSpeed(0, 1.30078125);
    PanToTarget(0, 0, 1);
    GetNpcPos(NPC_TWINK, SI_VAR(4), SI_VAR(5), SI_VAR(6));
    LoadPath(85, N(vectorList_80242A88), 8, 0);
0:
    GetNextPathPos();
    SI_VAR(1) += (float) SI_VAR(4);
    SI_VAR(2) += (float) SI_VAR(5);
    SI_VAR(3) += (float) SI_VAR(6);
    SetNpcPos(NPC_TWINK, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    N(func_80240994_A0C684)();
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 0;
    }
    sleep 45;
    spawn {
        LoadPath(60, N(vectorList_80242AE8), 6, 0);
    1:
        GetNextPathPos();
        SetNpcPos(NPC_TWINK, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        N(func_80240994_A0C684)();
        sleep 1;
        if (SI_VAR(0) == 1) {
            goto 1;
        }
    }
    sleep 30;
    GetNpcPos(NPC_TWINK, SI_VAR(3), SI_VAR(1), SI_VAR(2));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(0) /= 2;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 275.0);
    SetCamPitch(0, 16.0, -8.5);
    SetCamSpeed(0, 2.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_TWINK, NPC_ANIM(twink, Palette_00, Anim_9), NPC_ANIM(twink, Palette_00, Anim_1), 0, MESSAGE_ID(0x0A, 0x0036));
    spawn {
        GetNpcPos(NPC_TWINK, SI_VAR(4), SI_VAR(5), SI_VAR(6));
        LoadPath(120, N(vectorList_80242B30), 9, 1);
    2:
        GetNextPathPos();
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        SI_VAR(3) += (float) SI_VAR(6);
        SetNpcPos(NPC_TWINK, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        N(func_80240994_A0C684)();
        sleep 1;
        if (SI_VAR(0) == 1) {
            goto 2;
        }
    }
    SetCamDistance(0, 300.0);
    SetCamPitch(0, 12.5, -10.0);
    N(func_80240B3C_A0C82C)();
    SetCamPosA(0, SI_VAR(0), SI_VAR(1));
    SetCamPosB(0, SI_VAR(2), SI_VAR(3));
    SetCamSpeed(0, 0.5);
    PanToTarget(0, 0, 1);
    sleep 30;
    SetNpcFlagBits(NPC_TWINK, ((NPC_FLAG_40000)), TRUE);
    SI_VAR(0) = 0.0;
    loop 10 {
        SI_VAR(0) += 36.0;
        SetNpcRotation(NPC_TWINK, 0, SI_VAR(0), 0);
        sleep 1;
    }
    SetNpcFlagBits(NPC_TWINK, ((NPC_FLAG_40000)), FALSE);
    sleep 120;
    InterpNpcYaw(NPC_PARTNER, 270, 0);
    PlayerFaceNpc(-4, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 275.0);
    SetCamPitch(0, 13.0, -7.5);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 10;
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0, MESSAGE_ID(0x0A, 0x0037));
    EnablePartnerAI();
    SetPlayerAnimation(ANIM_NOD_YES);
    sleep 30;
    SetPlayerAnimation(ANIM_10002);
    spawn {
        STORY_PROGRESS = STORY_CH0_TWINK_GAVE_LUCKY_STAR;
        func_802D5830(0);
        ResetCam(0, 4.0);
    }
    sleep 10;
    DisablePlayerInput(FALSE);
});

static s32 N(pad_4AE4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80244AF0) = SCRIPT({
    func_802C90FC(1, 1, -1);
    func_802C94A0(1, N(func_80240C40_A0C930), 0);
});

const char N(osr_01_name_hack)[] = "osr_01";
