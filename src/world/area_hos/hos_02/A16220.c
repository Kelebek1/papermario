#include "hos_02.h"
#include "message_ids.h"
#include "sprite/npc/bubble.h"

enum {
    NPC_BUBBLE0,
    NPC_BUBBLE1,
    NPC_BUBBLE2,
};

EntryList N(entryList) = {
    { -1005.0f, -171.0f, 225.0f,  90.0f },
    {  1160.0f,  503.0f, 350.0f, 270.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {     0.0f,    0.0f,   0.0f,   0.0f },
    {   354.0f,    0.0f, 294.0f, 117.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_hos_02_tattle },
};

Script N(80242BD0) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        SetMusicTrack(0, SONG_STAR_WAY_OPENS, 3, 8);
    }
});

static s32 N(pad_2C24)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80242C30) = SCRIPT({
    group 27;
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
    await N(80244B80);
    GotoMap("hos_01", 1);
    sleep 100;
});

Script N(exitWalk_80242D38) = EXIT_WALK_SCRIPT(60,  1, "hos_03",  0);

Script N(80242D94) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        bind N(80242C30) to TRIGGER_FLOOR_TOUCH 0;
    }
    bind N(exitWalk_80242D38) to TRIGGER_FLOOR_ABOVE 2;
});

Script N(80242E04) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    UseSettingsFrom(0, -1105, -171, 225);
    SetPanTarget(0, -1105, -171, 225);
    SetCamDistance(0, 300.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SI_VAR(2) = 360;
    MakeLerp(-400, -171, 60, 4);
    loop {
        UpdateLerp();
        SetPlayerPos(-1105, SI_VAR(0), 225);
        SetNpcPos(NPC_PARTNER, -1105, SI_VAR(0), 215);
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
    if (SI_VAR(2) < 450) {
        InterpPlayerYaw(SI_VAR(2), 0);
        SetNpcRotation(NPC_PARTNER, 0, SI_VAR(2), 0);
        SI_VAR(2) += SI_VAR(0);
        sleep 1;
        goto 10;
    }
    SI_VAR(2) = 90;
    SI_VAR(0) -= 5;
    if (SI_VAR(0) > 20) {
        goto 10;
    }
    SetNpcRotation(NPC_PARTNER, 0, 0, 0);
    N(func_80240EF4_A17114)(SI_MAP_VAR(10));
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE);
    EnablePartnerAI();
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    SetMusicTrack(0, SONG_STAR_WAY_OPENS, 3, 8);
    DisablePlayerInput(FALSE);
    AwaitPlayerLeave(-1105, 225, 40);
    bind N(80242C30) to TRIGGER_FLOOR_TOUCH 0;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_STAR_WAY;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SI_SAVE_FLAG(1991) = 1;
    MakeNpcs(0, N(npcGroupList_80244B44));
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            spawn {
                await N(80242E04);
                spawn N(80242D94);
            }
        }
        == 1 {
            ModifyColliderFlags(0, 3, 0x7FFFFE00);
            SI_VAR(0) = N(80242D94);
            spawn EnterWalk;
        }
    }
    spawn N(802433B8);
    spawn N(80244480);
    spawn N(80242BD0);
});

static s32 N(pad_330C) = {
    0x00000000,
};

Script N(updateTexturePan_80243310) = SCRIPT({
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

u16 N(D_802433AC_A195CC) = 0;
u16 N(D_802433AE_A195CE) = 0;
u16 N(D_802433B0_A195D0) = 0;
u16 N(D_802433B2_A195D2) = 0;
u16 N(D_802433B4_A195D4) = 0;

Script N(802433B8) = SCRIPT({
    PlayEffect(0x75, 1, -1105, -86, 230, 1, -1, 0, 0, 0, 0, 0, 0, 0);
    SI_MAP_VAR(10) = SI_VAR(15);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            N(func_80240F68_A17188)(SI_MAP_VAR(10));
        }
        == 1 {
            N(func_80240EF4_A17114)(SI_MAP_VAR(10));
        }
    }
    EnableTexPanning(1, 1);
    EnableTexPanning(4, 1);
    EnableTexPanning(5, 1);
    EnableTexPanning(6, 1);
    spawn {
        SI_VAR(0) = 1;
        SI_VAR(1) = 80;
        SI_VAR(2) = -200;
        SI_VAR(3) = -50;
        SI_VAR(4) = 100;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80243310);
    }
    func_802C90FC(20, 0, -1);
    func_802C90FC(22, 0, -1);
    func_802C90FC(37, 0, -1);
    func_802C90FC(39, 0, -1);
    func_802C90FC(54, 0, -1);
    func_802C90FC(56, 0, -1);
    func_802C94A0(0, N(func_8024030C_A1652C), 0);
    SetModelFlags(20, 256, 1);
    SetModelFlags(22, 256, 1);
    SetModelFlags(37, 256, 1);
    SetModelFlags(39, 256, 1);
    SetModelFlags(54, 256, 1);
    SetModelFlags(56, 256, 1);
    SetModelFlags(16, 256, 1);
    SetModelFlags(17, 256, 1);
    SetModelFlags(18, 256, 1);
    SetModelFlags(33, 256, 1);
    SetModelFlags(34, 256, 1);
    SetModelFlags(35, 256, 1);
    SetModelFlags(50, 256, 1);
    SetModelFlags(51, 256, 1);
    SetModelFlags(52, 256, 1);
    func_802C9C70(0, 60, 1);
    func_802C94A0(1, N(func_80240434_A16654), 0);
    func_802C90FC(60, 1, -1);
    func_802C90FC(62, 1, -1);
    func_802C90FC(64, 1, -1);
    func_802C90FC(66, 1, -1);
    func_802C90FC(68, 1, -1);
    func_802C90FC(70, 1, -1);
    func_802C90FC(72, 1, -1);
    func_802C90FC(74, 1, -1);
    func_802C90FC(76, 1, -1);
    func_802C90FC(82, 1, -1);
    func_802C90FC(88, 1, -1);
    SetModelFlags(60, 128, 1);
    SetModelFlags(62, 128, 1);
    SetModelFlags(64, 128, 1);
    SetModelFlags(66, 128, 1);
    SetModelFlags(68, 128, 1);
    SetModelFlags(70, 128, 1);
    SetModelFlags(72, 128, 1);
    SetModelFlags(74, 128, 1);
    SetModelFlags(76, 128, 1);
    SetModelFlags(82, 128, 1);
    SetModelFlags(88, 128, 1);
    func_802C9C70(1, 60, 1);
    func_802C94A0(2, N(func_80240610_A16830), 0);
    func_802C90FC(78, 2, -1);
    func_802C90FC(90, 2, -1);
    SetModelFlags(78, 128, 1);
    SetModelFlags(90, 128, 1);
    func_802C9C70(2, 60, 1);
    func_802C94A0(3, N(func_80240904_A16B24), 0);
    func_802C90FC(84, 3, -1);
    func_802C90FC(92, 3, -1);
    SetModelFlags(84, 128, 1);
    SetModelFlags(92, 128, 1);
    func_802C9C70(3, 60, 1);
    func_802C94A0(4, N(func_80240BFC_A16E1C), 0);
    func_802C90FC(80, 4, -1);
    func_802C90FC(86, 4, -1);
    SetModelFlags(80, 128, 1);
    SetModelFlags(86, 128, 1);
    spawn {
        loop {
            MakeLerp(-13, 13, 20, 10);
            loop {
                UpdateLerp();
                TranslateModel(60, 0, SI_VAR(0), 0);
                TranslateModel(68, 0, SI_VAR(0), 0);
                TranslateModel(70, 0, SI_VAR(0), 0);
                TranslateModel(72, 0, SI_VAR(0), 0);
                TranslateModel(74, 0, SI_VAR(0), 0);
                TranslateModel(78, 0, SI_VAR(0), 0);
                TranslateModel(82, 0, SI_VAR(0), 0);
                TranslateModel(86, 0, SI_VAR(0), 0);
                TranslateModel(90, 0, SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            MakeLerp(13, -13, 20, 10);
            loop {
                UpdateLerp();
                TranslateModel(60, 0, SI_VAR(0), 0);
                TranslateModel(68, 0, SI_VAR(0), 0);
                TranslateModel(70, 0, SI_VAR(0), 0);
                TranslateModel(72, 0, SI_VAR(0), 0);
                TranslateModel(74, 0, SI_VAR(0), 0);
                TranslateModel(78, 0, SI_VAR(0), 0);
                TranslateModel(82, 0, SI_VAR(0), 0);
                TranslateModel(86, 0, SI_VAR(0), 0);
                TranslateModel(90, 0, SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
        }
    }
    spawn {
        loop {
            MakeLerp(13, -13, 20, 10);
            loop {
                UpdateLerp();
                TranslateModel(62, 0, SI_VAR(0), 0);
                TranslateModel(64, 0, SI_VAR(0), 0);
                TranslateModel(66, 0, SI_VAR(0), 0);
                TranslateModel(76, 0, SI_VAR(0), 0);
                TranslateModel(80, 0, SI_VAR(0), 0);
                TranslateModel(84, 0, SI_VAR(0), 0);
                TranslateModel(88, 0, SI_VAR(0), 0);
                TranslateModel(92, 0, SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            MakeLerp(-13, 13, 20, 10);
            loop {
                UpdateLerp();
                TranslateModel(62, 0, SI_VAR(0), 0);
                TranslateModel(64, 0, SI_VAR(0), 0);
                TranslateModel(66, 0, SI_VAR(0), 0);
                TranslateModel(76, 0, SI_VAR(0), 0);
                TranslateModel(80, 0, SI_VAR(0), 0);
                TranslateModel(84, 0, SI_VAR(0), 0);
                TranslateModel(88, 0, SI_VAR(0), 0);
                TranslateModel(92, 0, SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
        }
    }
    spawn {
        loop {
            MakeLerp(0, 360, 50, 10);
            loop {
                UpdateLerp();
                RotateModel(60, SI_VAR(0), 0, 1, 0);
                RotateModel(68, SI_VAR(0), 0, 1, 0);
                RotateModel(70, SI_VAR(0), 0, 1, 0);
                RotateModel(72, SI_VAR(0), 0, 1, 0);
                RotateModel(74, SI_VAR(0), 0, 1, 0);
                RotateModel(78, SI_VAR(0), 0, 1, 0);
                RotateModel(82, SI_VAR(0), 0, 1, 0);
                RotateModel(86, SI_VAR(0), 0, 1, 0);
                RotateModel(90, SI_VAR(0), 0, 1, 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
        }
    }
    loop {
        MakeLerp(360, 0, 44, 10);
        loop {
            UpdateLerp();
            RotateModel(62, SI_VAR(0), 0, 1, 0);
            RotateModel(64, SI_VAR(0), 0, 1, 0);
            RotateModel(66, SI_VAR(0), 0, 1, 0);
            RotateModel(76, SI_VAR(0), 0, 1, 0);
            RotateModel(80, SI_VAR(0), 0, 1, 0);
            RotateModel(84, SI_VAR(0), 0, 1, 0);
            RotateModel(88, SI_VAR(0), 0, 1, 0);
            RotateModel(92, SI_VAR(0), 0, 1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
});

static s32 N(pad_447C) = {
    0x00000000,
};

Script N(80244480) = SCRIPT({

});

f32 N(D_80244490_A1A6B0)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_802444A8) = {
    .moveSpeed = 0.8f,
    .moveTime = 100,
    .alertRadius = 90.0f,
    .unk_14 = 4,
    .chaseSpeed = 3.8f,
    .unk_1C = { .s = 10 },
    .unk_20 = 1,
    .chaseRadius = 100.0f,
    .unk_2C = 1,
};

Script N(npcAI_802444D8) = SCRIPT({
    SetSelfVar(0, 1);
    SetSelfVar(5, 0);
    SetSelfVar(6, 0);
    SetSelfVar(1, 0);
    N(func_802428F4_A18B14)(N(npcAISettings_802444A8));
});

NpcSettings N(npcSettings_80244548) = {
    .height = 20,
    .radius = 22,
    .ai = &N(npcAI_802444D8),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 24,
};

StaticNpc N(npcGroup_80244574) = {
    .id = NPC_BUBBLE0,
    .settings = &N(npcSettings_80244548),
    .pos = { -410.0f, -15.0f, 260.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SHOOTING_STAR, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -410, -15, 260, 30, 0, -32767, 0, -410, -15, 260, 1000, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_2),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_4),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244764) = {
    .id = NPC_BUBBLE1,
    .settings = &N(npcSettings_80244548),
    .pos = { 220.0f, 200.0f, -205.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SHOOTING_STAR, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { 220, 200, -205, 30, 0, -32767, 0, 220, 200, -205, 1000, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_2),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_4),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244954) = {
    .id = NPC_BUBBLE2,
    .settings = &N(npcSettings_80244548),
    .pos = { -135.0f, 370.0f, 270.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SHOOTING_STAR, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -135, 370, 270, 30, 0, -32767, 0, -135, 370, 270, 1000, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_2),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_3),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_7),
        NPC_ANIM(bubble, Palette_01, Anim_4),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
        NPC_ANIM(bubble, Palette_01, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244B44) = {
    NPC_GROUP(N(npcGroup_80244574), BATTLE_ID(4, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_80244764), BATTLE_ID(4, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_80244954), BATTLE_ID(4, 1, 0, 2)),
    {},
};

static s32 N(pad_4B74)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80244B80) = SCRIPT({
    SetMusicTrack(0, SONG_STAR_WAY_OPENS, 2, 8);
    N(func_80240F68_A17188)(SI_MAP_VAR(10));
    SetPlayerSpeed(3.0);
    PlayerMoveTo(-1105, 230, 0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_PARTNER, ((0x00000040)), TRUE);
    SetNpcJumpscale(NPC_PARTNER, 0.5);
    NpcJump0(NPC_PARTNER, -1105, -171, 220, 5);
    spawn {
        SI_VAR(0) = 0;
        SI_VAR(1) = 90;
        loop {
            SI_VAR(0) += 2;
            SI_VAR(1) += SI_VAR(0);
            InterpPlayerYaw(SI_VAR(1), 0);
            SetNpcRotation(NPC_PARTNER, 0, SI_VAR(1), 0);
            sleep 1;
        }
    }
    sleep 60;
    GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
    SI_VAR(5) = SI_VAR(4);
    SI_VAR(5) += -10;
    MakeLerp(SI_VAR(3), -600, 40, 1);
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

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

extern 
extern 

void N(func_8024030C_A1652C)(void) {
    f32 temp_a1 = ((sins( N(D_802433AC_A195CC)) * 0.000030517578f) * 0.5 * 0.5) + 1.05;

     N(D_802433AC_A195CC) += 0x199;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], temp_a1, temp_a1, temp_a1);
    
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

#ifdef NON_MATCHING
// functions below this are the same weird thing

typedef struct {
    /* 0x00 */s16 unk_00;
    /* 0x02 */s16 unk_02;
    /* 0x04 */s16 unk_04;
    /* 0x06 */char unk_06[0x6];
    /* 0x0C */u8 unk_0C;
    /* 0x0D */u8 unk_0D;
    /* 0x0E */u8 unk_0E;
    /* 0x0F */char unk_0F[0x1];
} N(UnkStruct); // size = 0x10

void N(func_80240434_A16654)(void) {
    s32 i;
    s32 x;
    N(UnkStruct)* y;
    s32 z;
    s16 sin;
    s32 temp_v0;

    func_8011C2B0(0, &x, &y, &z);

    for (i = 0; i < z; i++) {
        N(UnkStruct)* ptr = &y[i];
        temp_v0 = sins(N(D_802433AE_A195CE) * ((i % 3) + 1) + i) * 0x9F;

        temp_v0 /= 0x8000;
        temp_v0 += 100;

        ptr->unk_0C = temp_v0;
        ptr->unk_0D = ptr->unk_0C;
        
        temp_v0 = ptr->unk_0C * sins((N(D_802433AE_A195CE) * ((i / 2) % 3) + 1) + N(D_802433AE_A195CE) + i);
        if (temp_v0 <= 0) {
            ptr->unk_0E = (u16)temp_v0;
        } else {
            ptr->unk_0E = (s16)temp_v0;
        }
    }

    gSPDisplayList(gMasterGfxPos++, func_8011C2EC(0));
     N(D_802433AE_A195CE) += 0x253;
}
#else
INCLUDE_ASM(void, "world/area_hos/hos_02/A16220", hos_02_func_80240434_A16654, void);
#endif

INCLUDE_ASM(void, "world/area_hos/hos_02/A16220", hos_02_func_80240610_A16830, void);

INCLUDE_ASM(void, "world/area_hos/hos_02/A16220", hos_02_func_80240904_A16B24, void);

INCLUDE_ASM(void, "world/area_hos/hos_02/A16220", hos_02_func_80240BFC_A16E1C, void);

ApiStatus N(func_80240EF4_A17114)(ScriptInstance *script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);

    ((EffectInstanceDataThing*)effect->unk_0C)->unk_78 = 190.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_7C = 220.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_68 = 0.7f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_38 = 0xFF;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240F68_A17188)(ScriptInstance *script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);

    ((EffectInstanceDataThing*)effect->unk_0C)->unk_78 = 170.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_7C = 170.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_68 = 2.0f;
    ((EffectInstanceDataThing*)effect->unk_0C)->unk_38 = 0xFF;
    return ApiStatus_DONE2;
}
