#include "gv_01.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { 0.0f, 0.0f, 0.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
};

Script N(80240810) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_STAND_STILL);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
    }
    GetEntryID(SI_VAR(0));
    N(GetEntryPos)();
    SI_VAR(2) -= 40;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    PlaySound(0x163);
    func_802D286C(256);
    func_802D2520(ANIM_STAND_STILL, 5, 2, 1, 1, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    loop 40 {
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    sleep 3;
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            DisablePartnerAI(0);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcFlagBits(NPC_PARTNER, ((0x00000002)), FALSE);
            EnablePartnerAI();
            EnableNpcShadow(NPC_PARTNER, TRUE);
        }
    }
    sleep 2;
    func_802D2520(ANIM_STAND_STILL, 0, 0, 0, 0, 0);
    sleep 1;
    SetPlayerAnimation(ANIM_10002);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
    HidePlayerShadow(FALSE);
0:
    N(GetCurrentFloor)();
    sleep 1;
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    spawn SI_VAR(10);
});

Script N(80240B64) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    GetEntryID(SI_VAR(0));
    N(GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(2) += 2;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    if (SI_VAR(4) == 90) {
        SI_VAR(5) += 40;
    } else {
        SI_VAR(5) -= 40;
    }
    UseSettingsFrom(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetPanTarget(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        DisablePartnerAI(0);
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
        InterpNpcYaw(NPC_PARTNER, SI_VAR(0), 0);
    }
    sleep 1;
    PlaySound(0x163);
    spawn {
        sleep 25;
        HidePlayerShadow(FALSE);
    }
    func_802D286C(2304);
    func_802D2520(ANIM_10002, 5, 3, 1, 1, 0);
    loop 40 {
        N(SomeXYZFunc2)(1.0);
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            EnableNpcShadow(NPC_PARTNER, TRUE);
            EnablePartnerAI();
        }
    }
    sleep 5;
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    ModifyColliderFlags(1, SI_VAR(11), 0x7FFFFE00);
    DisablePlayerInput(FALSE);
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    spawn SI_VAR(10);
});

Script N(80240F54) = SCRIPT({
    N(UnkFunc25)();
    if (SI_VAR(0) == 0) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != PARTNER_NONE) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    await N(80241030);
});

Script N(80241030) = SCRIPT({
    N(SetPlayerStatusAnimFlags100000)();
    group 27;
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    PlayerMoveTo(SI_VAR(1), SI_VAR(3), 3);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SetPlayerFlagBits(0x00200000, 1);
    N(GetCurrentCameraYawClamped180)();
    InterpPlayerYaw(SI_VAR(0), 0);
    sleep 2;
    SetPlayerFlagBits(0x00200000, 0);
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        sleep 4;
        loop 40 {
            SI_VAR(1) -= 1;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    func_802D286C(2048);
    func_802D2520(ANIM_10002, 5, 2, 1, 1, 0);
    sleep 25;
    await SI_VAR(12);
});

Script N(8024120C) = SCRIPT({
    IsPlayerOnValidFloor(SI_VAR(0));
    if (SI_VAR(0) == 0) {
        return;
    }
    GetPlayerActionState(SI_VAR(0));
    if (SI_VAR(0) == 26) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != PARTNER_NONE) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    group 27;
    N(SetPlayerStatusAnimFlags100000)();
    DisablePlayerPhysics(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(6) += 2;
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(8) = SI_VAR(4);
    SI_VAR(8) += 180;
    if (SI_VAR(4) >= 360) {
        SI_VAR(4) -= 360;
    }
    InterpPlayerYaw(SI_VAR(8), 1);
    sleep 1;
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerPos(SI_VAR(0), SI_VAR(6), SI_VAR(7));
    SetPlayerAnimation(ANIM_STAND_STILL);
    func_802D286C(2048);
    func_802D2520(ANIM_STAND_STILL, 5, 3, 1, 1, 0);
    spawn {
        sleep 8;
        HidePlayerShadow(TRUE);
    }
    spawn {
        sleep 3;
        loop 40 {
            N(SomeXYZFunc2)(1.0);
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    sleep 25;
    await SI_VAR(12);
});

Script N(80241540) = SCRIPT({
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

s32 N(intTable_802415DC)[] = {
    0x000000C8, 0x000000AA, 0x0000008C, 0x0000006E, 0x00000050, 0x00000032, 0x00000014, 0x0000000A,
    0x0000001A, 0x0000001D, 0x0000001E, 0x0000001D, 0x0000001A, 0x0000000A, 0x00000000, 0x0000000C,
    0x0000000F, 0x00000010, 0x0000000F, 0x0000000B, 0x00000006, 0x00000000, 0x00000004, 0x00000003,
    0x00000001, 0x00000000,
};

s32 N(intTable_80241644)[] = {
    0x000000C8, 0x000000AA, 0x0000008C, 0x0000006E, 0x00000050, 0x00000032, 0x00000014, 0x00000000,
    0x0000000C, 0x0000000F, 0x00000010, 0x0000000F, 0x0000000B, 0x00000006, 0x00000000, 0x00000004,
    0x00000003, 0x00000001, 0x00000000,
};

// *INDENT-OFF*
Script N(80241690) = {
    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_802415DC)),
    SI_CMD(ScriptOpcode_LOOP, 26),
        SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(1)),
        SI_CMD(ScriptOpcode_CALL, TranslateGroup, SI_VAR(0), 0, SI_VAR(1), 0),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
};

Script N(802416EC) = {
    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80241644)),
    SI_CMD(ScriptOpcode_LOOP, 19),
        SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(1)),
        SI_CMD(ScriptOpcode_CALL, TranslateGroup, SI_VAR(0), 0, SI_VAR(1), 0),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
};
 
Script N(main) = {
    SI_CMD(ScriptOpcode_CALL, DisablePlayerInput, 1),
    SI_CMD(ScriptOpcode_CALL, func_802D585C, 0, 131072),
    SI_CMD(ScriptOpcode_CALL, SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CMD(ScriptOpcode_CALL, SetCamBGColor, 0, 0, 0, 0),
    SI_CMD(ScriptOpcode_CALL, SetCamEnabled, 0, 1),
    SI_CMD(ScriptOpcode_CALL, SetCamLeadPlayer, 0, 0),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, GetCurrentPartnerID, SI_VAR(0)),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(0), 0),
            SI_CMD(ScriptOpcode_CALL, DisablePartnerAI, 0),
            SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, -4, 512, 0),
            SI_CMD(ScriptOpcode_CALL, SetNpcPos, -4, 0, -1000, 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, SetPlayerFlagBits, 0x00200000, 1),
        SI_CMD(ScriptOpcode_CALL, InterpPlayerYaw, 90, 0),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, RandInt, 4, SI_VAR(0)),
        SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
            SI_CMD(ScriptOpcode_CASE_EQ, 0),
                SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65549),
            SI_CMD(ScriptOpcode_CASE_EQ, 1),
                SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65556),
            SI_CMD(ScriptOpcode_CASE_EQ, 2),
                SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65571),
            SI_CMD(ScriptOpcode_CASE_EQ, 3),
                SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65580),
            SI_CMD(ScriptOpcode_CASE_EQ, 4),
                SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65551),
        SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, SetMusicTrack, 0, 135, 0, 8),
    SI_CMD(ScriptOpcode_CALL, ClearAmbientSounds, 0),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 200),
        SI_CMD(ScriptOpcode_CALL, N(func_802405EC_E1EA4C)),
        SI_CMD(ScriptOpcode_CALL, N(func_80240688_E1EAE8)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 100),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, Spawn802D9D50, 0, 0, 0, 320, 240, 128, 10),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 4, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 6, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 8, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 10, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 12, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 14, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 16, 0, 200, 0),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 18, 0, 200, 0),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 4),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 6),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 12),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 8),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 10),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 12),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 14),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 16),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241690)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 18),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 18),
        SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(802416EC)),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, 0, 10, 0),
        SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, 0, 0, 0),
        SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(0.30078125)),
        SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 94),
        SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, 0, 0, 1000),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

ApiStatus N(func_802405EC_E1EA4C)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        set_curtain_scale_goal(1.0);
        set_curtain_fade(0);
    }

    script->functionTemp[0].s += 5;
    if (script->functionTemp[0].s > 255) {
        script->functionTemp[0].s = 255;
    }

    set_transition_stencil_color(1, 208, 208, 208);
    set_transition_stencil_zoom_1(0, script->functionTemp[0].s);
    set_transition_stencil_alpha(1, 0);
    return script->functionTemp[0].s == 255;
}

ApiStatus N(func_80240688_E1EAE8)(ScriptInstance* script, s32 isInitialCall) {
    gGameStatusPtr->isBattle = 0;
    gGameStatusPtr->unk_76 = 0;
    gGameStatusPtr->disableScripts = 0;
    gGameStatusPtr->unk_7D = 0;
    gOverrideFlags &= ~8;
    general_heap_create(&gOverrideFlags);
    func_8011D890();
    clear_dynamic_entity_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(0);
    clear_entity_models();
    func_8011E224();
    clear_model_data();
    func_80148040();
    use_default_background_settings();
    func_80141100();
    clear_trigger_data();
    clear_printers();
    clear_entity_data(0);
    clear_transition_stencil();
    clear_player_status();
    npc_list_clear();
    clear_player_data();
    func_80072B30();
    func_8003E338();
    clear_effect_data();
    clear_item_entity_data();
    clear_saved_variables();
    initialize_collision();
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(208);
    set_game_mode(2);
    return ApiStatus_FINISH;
}
