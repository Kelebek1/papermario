#include "hos_04.h"

static f32 N(D_80243370_A2A240);
static f32 N(D_80243374_A2A244);

#include "world/common/SetCamVfov.inc.c"

ApiStatus N(func_80240654_A27524)(ScriptInstance *script, s32 isInitialCall) {
    if ((u8)gGameStatusPtr->creditsViewportMode < 5) {
        gGameStatusPtr->creditsViewportMode++;
        begin_state_intro();
    }
    return ApiStatus_DONE1;
}

ApiStatus N(func_8024068C_A2755C)(ScriptInstance *script, s32 isInitialCall) {
    return ApiStatus_BLOCK;
}

void N(func_80240694_A27564)(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    f32 temp_f2 = arg1 - arg2;
    f32 temp_f0 = arg1 - arg0;

    if (temp_f0 > 0.0f) {
        if (temp_f2 < 0.0f) {
            *arg4 = arg1;
        } else if (arg3 < temp_f2) {
            *arg4 += arg3;
        } else {
            *arg4 += temp_f2;
        }
    } else if (temp_f2 > 0.0f) {
        *arg4 = arg1;
    } else if (temp_f2 < -arg3) {
        *arg4 -= arg3;
    } else {
        *arg4 += temp_f2;
    }
}

void N(func_80240734_A27604)(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    if (arg4 < arg3) {
        arg3 = arg4;
    }
    
    switch (arg0) {
        case 1:
            arg3 = sin_deg((arg3 / arg4) * 90.0f);
            break;

        case 2:
            if (arg3 < 30.0f) {
                arg3 = 0.0f;
            } else {
                arg3 = (((arg3 - 30.0f) / (arg4 - 30.0f)) * 90.0f) + -90.0f;
                arg3 = sin_deg(arg3) + 1.0f;
            }
            break;

        case 3:
            arg3 = (sin_deg(((arg3 / arg4) * 180.0f) - 90.0f) + 1.0f) * 0.5;
            break;

        case 4:
            arg3 = ((arg3 / arg4) * 90.0f) - 90.0f;
            arg3 = sin_deg(arg3) + 1.0f;
            break;

        case 5:
            // PI / 4 and PI_D / 2 doesn't match
            arg3 = (2.0 * (sin_deg(((arg3 / arg4) * 60.0f) - 60.0f) + 0.8660254f)) / 1.73205077648162841796875;
            break;

        default:
            arg3 = arg3 / arg4;
            break;
    }

    *arg5 = arg1 + ((arg2 - arg1) * arg3);
}

ApiStatus N(func_802408F8_A277C8)(ScriptInstance *script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (D_8009A64C == N(D_80241B80_A28A50)) {
        return ApiStatus_BLOCK;
    }

    N(D_80241B80_A28A50) = D_8009A64C;
    N(func_80240694_A27564)(700.0f, 300.0f, N(D_80241B7C_A28A4C), 1.2f, &N(D_80241B7C_A28A4C));
    camera->unk_506 = 1;
    camera->controller.boomLength = N(D_80241B7C_A28A4C);

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802409B0_A27880)(ScriptInstance *script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        N(D_80243370_A2A240) = N(D_80241B50_A28A20).boomLength;
    }

    N(func_80240734_A27604)(1, N(D_80241B50_A28A20).boomLength, 700.0f, N(D_80241B84_A28A54), 70.0f, &N(D_80243370_A2A240));
    camera->unk_506 = 1;
    camera->controller.boomLength = N(D_80243370_A2A240);
    N(D_80241B84_A28A54)++;

    return N(D_80241B84_A28A54) < 70 == FALSE;
}

ApiStatus N(func_80240A84_A27954)(ScriptInstance *script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        N(D_80243374_A2A244) = N(D_80241B50_A28A20).viewPitch;
    }

    N(func_80240734_A27604)(5, N(D_80241B50_A28A20).viewPitch, -80.0f, N(D_80241B88_A28A58), 200.0f, &N(D_80243374_A2A244));
    camera->unk_506 = 1;
    camera->controller.viewPitch = N(D_80243374_A2A244);
    N(D_80241B88_A28A58)++;

    return (N(D_80241B88_A28A58) == 200) * ApiStatus_DONE2;
}
