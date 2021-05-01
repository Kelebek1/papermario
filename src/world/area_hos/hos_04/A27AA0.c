#include "hos_04.h"

static s32 N(D_80243380_A2A250);

Script N(802421E0) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(10);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetCamPerspective(0, 3, 45, 16, 4096);
    UseSettingsFrom(0, -280, 0, 0);
    SetPanTarget(0, -280, 0, 0);
    SetCamType(0, 0, 0);
    SetCamDistance(0, 550.0);
    SetCamPosA(0, -688.0, 50.0);
    SetCamPosB(0, -544.0, 50.0);
    SetCamPitch(0, 2.0, -20.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    spawn {
        PlaySound(0x181);
        MakeLerp(0, 900, 45, 1);
        loop {
            UpdateLerp();
            TranslateGroup(171, 0, SI_VAR(0), 0);
            SI_VAR(0) += 520;
            SetPlayerPos(315, SI_VAR(0), 5);
            SetNpcPos(NPC_PARTNER, 313, SI_VAR(0), 5);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    sleep 55;
    GotoMap("hos_20", 0);
    sleep 100;
});

Script N(80242474) = SCRIPT({
    SI_VAR(4) = 0;
    SI_VAR(5) = 100;
10:
    SI_VAR(3) = SI_VAR(4);
    SI_VAR(4) = SI_VAR(5);
    SI_VAR(5) = SI_VAR(3);
    MakeLerp(SI_VAR(3), SI_VAR(4), 30, 10);
    loop {
        UpdateLerp();
        SI_VAR(2) = (float) SI_VAR(0);
        SI_VAR(2) *= 0.1005859375;
        SI_VAR(2) += (float) SI_MAP_VAR(11);
        TranslateGroup(171, SI_MAP_VAR(10), SI_VAR(2), 0);
        RotateGroup(171, SI_MAP_VAR(12), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    goto 10;
});

Script N(802425C0) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(10);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    ModifyColliderFlags(0, 16, 0x7FFFFE00);
    InterpPlayerYaw(90, 0);
    UseSettingsFrom(0, -500, 0, 0);
    SetPanTarget(0, -5000, 0, 0);
    SetCamDistance(0, 350.0);
    SetCamPosA(0, -5000, 50);
    SetCamPosB(0, 5000, 50);
    SetCamPitch(0, 17.0, -7.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    SI_MAP_VAR(13) = 0;
    SI_MAP_VAR(10) = -5000;
    SI_MAP_VAR(11) = -525;
    SI_MAP_VAR(12) = 180;
    spawn N(80242474);
    sleep 1;
    spawn {
        SI_VAR(7) = 45;
        loop 20 {
            SI_MAP_VAR(10) += SI_VAR(7);
            sleep 1;
        }
        SI_VAR(7) = 50;
        loop {
            SI_MAP_VAR(10) += SI_VAR(7);
            sleep 1;
            GetModelCenter(167);
            SI_VAR(0) += 25;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) -= 10;
            SI_VAR(2) += 2;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            GetCamPosition(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
            if (SI_VAR(0) > SI_VAR(3)) {
                if (SI_VAR(7) > 45) {
                    SI_VAR(7) -= 1;
                }
            }
            if (SI_MAP_VAR(10) > 2000) {
                SI_MAP_VAR(13) = 1;
            }
        }
    }
    spawn {
        SI_VAR(0) = -5000;
        loop {
            SI_VAR(0) += 45;
            SetPanTarget(0, SI_VAR(0), 0, 0);
            PanToTarget(0, 0, 1);
            sleep 1;
        }
    }
20:
    if (SI_MAP_VAR(13) == 0) {
        sleep 1;
        goto 20;
    }
    if (STORY_PROGRESS < STORY_UNUSED_5D) {
        GotoMap("hos_00", 3);
    } else {
        SI_VAR(0) = 2;
        loop 10 {
            SI_VAR(0) *= 2;
            SI_MAP_VAR(10) += SI_VAR(0);
            sleep 1;
        }
        sleep 20;
        GotoMap("kpa_60", 4);
    }
    sleep 100;
});

Script N(80242A64) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(10);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    ModifyColliderFlags(0, 16, 0x7FFFFE00);
    UseSettingsFrom(0, -500, 0, 0);
    SetPanTarget(0, -5000, 0, 0);
    SetCamDistance(0, 350.0);
    SetCamPosA(0, -5000, 50);
    SetCamPosB(0, 5000, 50);
    SetCamPitch(0, 17.0, -7.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    SI_MAP_VAR(13) = 0;
    SI_MAP_VAR(10) = -4673;
    SI_MAP_VAR(11) = -525;
    SI_MAP_VAR(12) = 180;
    spawn N(80242474);
    sleep 1;
    spawn {
        loop {
            SI_MAP_VAR(10) += 45;
            sleep 1;
            GetModelCenter(167);
            SI_VAR(0) += 25;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) -= 10;
            SI_VAR(2) += 2;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
    }
    spawn {
        SI_VAR(0) = -5000;
        loop {
            SI_VAR(0) += 45;
            SetPanTarget(0, SI_VAR(0), 0, 0);
            PanToTarget(0, 0, 1);
            sleep 1;
            if (SI_VAR(0) > 0) {
                SI_MAP_VAR(13) = 1;
            }
        }
    }
20:
    if (SI_MAP_VAR(13) == 0) {
        sleep 1;
        goto 20;
    }
    SI_VAR(0) = 2;
    loop 10 {
        SI_VAR(0) *= 2;
        SI_MAP_VAR(10) += SI_VAR(0);
        sleep 1;
    }
    sleep 20;
    GotoMap("osr_03", 3);
    sleep 100;
});

Script N(80242E14) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(10);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    ModifyColliderFlags(0, 16, 0x7FFFFE00);
    SetNpcYaw(NPC_PARTNER, 90);
    UseSettingsFrom(0, -500, 0, 0);
    SetPanTarget(0, 5000, 0, 0);
    SetCamDistance(0, 350.0);
    SetCamPosA(0, -5000, 50);
    SetCamPosB(0, 5000, 50);
    SetCamPitch(0, 17.0, -7.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    SI_MAP_VAR(13) = 0;
    SI_MAP_VAR(10) = 5000;
    SI_MAP_VAR(11) = -525;
    SI_MAP_VAR(12) = 0;
    spawn N(80242474);
    sleep 2;
    spawn {
        InterpPlayerYaw(225, 0);
        SI_VAR(7) = -50;
        loop {
            SI_MAP_VAR(10) += SI_VAR(7);
            GetModelCenter(167);
            SI_VAR(0) += -25;
            SI_VAR(2) += -5;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) += 10;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
            GetCamPosition(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
            if (SI_VAR(0) < SI_VAR(3)) {
                if (SI_VAR(7) < -45) {
                    SI_VAR(7) += 1;
                }
            }
        }
    }
    spawn {
        SI_VAR(0) = 5000;
        loop {
            SI_VAR(0) += -45;
            SetPanTarget(0, SI_VAR(0), 0, 0);
            PanToTarget(0, 0, 1);
            sleep 1;
            if (SI_VAR(0) < -1000) {
                SI_MAP_VAR(13) = 1;
            }
        }
    }
20:
    if (SI_MAP_VAR(13) == 0) {
        sleep 1;
        goto 20;
    }
    SI_VAR(0) = -2;
    loop 10 {
        SI_VAR(0) *= 2;
        SI_MAP_VAR(10) += SI_VAR(0);
        sleep 1;
    }
    GotoMap("hos_05", 1);
    sleep 100;
});

static s32 N(pad_324C) = {
    0x00000000,
};

s32 N(D_80243250_A2A120) = 0;

s32 N(D_80243254_A2A124) = 0;

N(Unk_struct)* N(D_80243258_A2A128) = NULL;

s32 N(D_8024325C_A2A12C)[] = {
    0xFFFFFFFF, 0x00000059, 
    0x0000001B, 0x0000002C, 
    0x0000001C, 0x0000002C, 
    0x0000001D, 0x0000002C,
};

s32 N(pad_XXXX)[] = { 0, 0 };

s32 N(D_80243284_A2A154)[] = {
    N(D_8024325C_A2A12C), N(D_8024325C_A2A12C), N(D_8024325C_A2A12C), N(D_8024325C_A2A12C),
};

Script N(80243294) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 4 {
            N(func_80240E40_A27D10)(N(func_80240E6C_A27D3C));
        }
    }
});

void N(func_80240BD0_A27AA0)(N(Unk_struct)* arg0[]) {
    f32 f1, f2, f3;
    s32 temp_s1;
    s32 phi_s0;

    if (N(D_80243258_A2A128) == NULL) {
       N(D_80243258_A2A128) = arg0[D_800779B0];
    }

    switch (N(D_80243250_A2A120)) {
        case 0:
            if (N(D_80243258_A2A128)->unk_00 == -1) {
                N(D_80243250_A2A120) = 4;
                N(D_80243380_A2A250) = N(D_80243258_A2A128)->unk_04;
                break;
            }
            N(D_80243254_A2A124) += 10;
            if (N(D_80243254_A2A124) > 255) {
                N(D_80243254_A2A124) = 255;
                N(D_80243250_A2A120) = 1;
                N(D_80243380_A2A250) = N(D_80243258_A2A128)->unk_04;
            }
            break;

        case 1:
            if (N(D_80243380_A2A250) == 0) {
                N(D_80243250_A2A120) = 2;
            } else {
                N(D_80243380_A2A250)--;
            }
            break;

        case 2:
            N(D_80243254_A2A124) -= 10;
            if (N(D_80243254_A2A124) < 0) {
                N(D_80243254_A2A124) = 0;
                N(D_80243258_A2A128) += 1;
                if (N(D_80243258_A2A128)->unk_00 == 0) {
                    N(D_80243250_A2A120) = 3;
                } else {
                    N(D_80243250_A2A120) = 0;
                }
            }
            break;

        case 4:
            if (N(D_80243380_A2A250) != 0) {
                N(D_80243380_A2A250)--;
            } else {
                N(D_80243258_A2A128) += 1;
                if (N(D_80243258_A2A128)->unk_00 == 0) {
                   N(D_80243250_A2A120) = 3;
                } else {
                   N(D_80243250_A2A120) = 0;
                }
            }
            break;

        case 3:
            break;
    }

    func_80137DC0(1, &f1, &f2);
    func_80137DC0(0, &f1, &f3);
    temp_s1 = (N(D_80243254_A2A124) * (255.0f - f2) * (255.0f - f3)) / 255.0f / 255.0f;
    if (temp_s1 > 0) {
        if (N(D_80243258_A2A128)->unk_00 != 0) {
            phi_s0 = 0;
            if (get_msg_lines(N(D_80243258_A2A128)->unk_00) >= 2) {
                phi_s0 = -7;
            }
            draw_msg(N(D_80243258_A2A128)->unk_00, 0, phi_s0 + 196, temp_s1, -1, 0);
        }
    }
}

ApiStatus N(func_80240E40_A27D10)(ScriptInstance* script, s32 isInitialCall) {
    set_curtain_draw_callback(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

void N(func_80240E6C_A27D3C)(void) {
    N(func_80240BD0_A27AA0)(N(D_80243284_A2A154));
}

