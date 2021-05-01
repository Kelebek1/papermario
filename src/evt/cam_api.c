#include "common.h"

typedef struct {
    char unk_00[0x10];
    CameraController* controller;
    char unk_14[0x8];
} Unk_camera_controller_struct;
extern Unk_camera_controller_struct (*D_800D91D4)[];

Script ShakeCam1 = SCRIPT({
    group 0;
    ShakeCam(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0);
});

Script ShakeCamX = SCRIPT({
    group 0;
    ShakeCam(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
});

ApiStatus SetCamEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        CAM(id)->flags |= 0x2;
    } else {
        CAM(id)->flags &= ~0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamFlag80(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        CAM(id)->flags |= 0x80;
    } else {
        CAM(id)->flags &= ~0x80;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamPerspective(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 mode = get_variable(script, *args++);
    f32 vfov = get_float_variable(script, *args++);
    s16 nearClip = get_variable(script, *args++);
    s16 farClip = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->farClip = farClip;
    camera->mode = mode;
    camera->unk_06 = 1;
    camera->unk_08 = 1;
    camera->vfov = vfov;
    camera->nearClip = nearClip;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA90C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 mode = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->mode = mode;
    camera->unk_06 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA988(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Bytecode outVar4 = *args++;
    f32 temp1, temp2, temp3;

    CAM(id)->mode = 2;
    CAM(id)->unk_06 = 0;
    CAM(id)->unk_1C = -round(CAM(id)->currentPitch);
    CAM(id)->unk_1E = -CAM(id)->currentBlendedYawNegated;

    temp1 = CAM(id)->lookAt_obj.x - CAM(id)->lookAt_eye[0];
    temp2 = CAM(id)->lookAt_obj.y - CAM(id)->lookAt_eye[1];
    temp3 = CAM(id)->lookAt_obj.z - CAM(id)->lookAt_eye[2];

    CAM(id)->unk_20 = round(sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3)));
    CAM(id)->unk_22 = 0;
    CAM(id)->unk_54 = CAM(id)->lookAt_obj.x;
    CAM(id)->unk_58 = CAM(id)->lookAt_obj.y;
    CAM(id)->unk_5C = CAM(id)->lookAt_obj.z;

    set_variable(script, outVar1, CAM(id)->unk_1C);
    set_variable(script, outVar2, CAM(id)->unk_1E);
    set_variable(script, outVar3, CAM(id)->unk_20);
    set_variable(script, outVar4, CAM(id)->unk_22);
    return ApiStatus_DONE2;
}

ApiStatus SetCamViewport(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s16 width = get_variable(script, *args++);
    s16 height = get_variable(script, *args++);

    set_cam_viewport(id, x, y, width, height);
    return ApiStatus_DONE2;
}

ApiStatus func_802CABE8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    s16 value4 = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_22 = value4;
    camera->unk_1C = value1;
    camera->unk_1E = value2;
    camera->unk_20 = value3;
    return ApiStatus_DONE2;
}

ApiStatus func_802CACC0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    s16 zoomPercent = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->zoomPercent = zoomPercent;
    camera->unk_24 = value1;
    camera->unk_26 = value2;
    camera->unk_28 = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamBGColor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 r = get_variable(script, *args++);
    s16 g = get_variable(script, *args++);
    s16 b = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->backgroundColor[0] = r;
    camera->backgroundColor[1] = g;
    camera->backgroundColor[2] = b;
    return ApiStatus_DONE2;
}

ApiStatus func_802CAE50(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_54 = value1;
    camera->unk_58 = value2;
    camera->unk_5C = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->targetPos.x = x;
    camera->targetPos.y = y;
    camera->targetPos.z = z;
    return ApiStatus_DONE2;
}

typedef struct {
    Camera* camera;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    s32 unk_14;
} Unk_cam_struct; // size = 0x18

ApiStatus func_802CB008(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Unk_cam_struct* ptr;
    Camera* camera;

    if (isInitialCall) {
        s32 var1 = get_variable(script, *args++);
        s32 var2 = get_variable(script, *args++);
        s32 var3 = get_variable(script, *args++);
        s32 var4 = get_variable(script, *args++);
        s32 var5 = get_variable(script, *args++);
        s32 var6 = get_variable(script, *args++);
        ptr = heap_malloc(0x18);
        script->userData = ptr;
        camera = &gCameras[var1];

        ptr->unk_04 = var2;
        ptr->camera = camera;
        ptr->unk_14 = var6;
        switch (ptr->unk_04) {
            case 0:
                ptr->unk_08 = (var3 - camera->unk_54) / var6;
                ptr->unk_0C = (var4 - camera->unk_58) / ptr->unk_14;
                ptr->unk_10 = (var5 - camera->unk_5C) / ptr->unk_14;
                break;

            case 1:
                ptr->unk_08 = (var3 - camera->targetPos.x) / var6;
                ptr->unk_0C = (var4 - camera->targetPos.y) / ptr->unk_14;
                ptr->unk_10 = (var5 - camera->targetPos.z) / ptr->unk_14;
                break;
        }
    }

    ptr = (Unk_cam_struct*)script->userData;
    camera = ptr->camera;
    switch (ptr->unk_04) {
        case 0:
            camera->unk_54 += ptr->unk_08;
            camera->unk_58 += ptr->unk_0C;
            camera->unk_5C += ptr->unk_10;
            break;

        case 1:
            camera->targetPos.x += ptr->unk_08;
            camera->targetPos.y += ptr->unk_0C;
            camera->targetPos.z += ptr->unk_10;
            break;
    }

    ptr->unk_14--;
    if (ptr->unk_14 == 0) {
        heap_free(script->userData);
        script->userData = NULL;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
    
}

ApiStatus ShakeCam(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    s32 temp_s3 = get_variable(script, *args++);
    s32 temp_s4 = get_variable(script, *args++);
    f32 f1 = get_float_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    f32 temp_f20 = 2.0f * f1;
    f32 freq;
    
    if (isInitialCall) {
        if (temp_s3 >= 0) {
            if (temp_s3 >= 2) {
                if (temp_s3 == 2) {
                    temp_s4 *= 4;
                }
            }
            script->functionTemp[3].f = 1.0f;
        } else {
            script->functionTemp[3].f = 1.0f;
        }

        script->functionTemp[1].s = temp_s4;
        if (!gGameStatusPtr->isBattle) {
            u16 frame;

            if (temp_f20 > 10.0f) {
                temp_f20 = 10.0f;
            }
            if (temp_f20 > 6.0f) {
                freq = 6.0f;
            } else {
                freq = temp_f20;
            }

            freq = (freq * 32.0f) + 64.0f;

            frame = temp_s4;
            if (temp_s4 < 5) {
                frame = 5;
            }

            start_rumble(freq, frame * 2);
        }
    }
    camera->flags |= 8;
    freq = script->functionTemp[3].f;
    switch (temp_s3) {
        case 0:
            guTranslateF(camera->viewMtxShaking, 0.0f, -freq * temp_f20, 0.0f);
            script->functionTemp[3].f = -script->functionTemp[3].f;
            break;

        case 1:
            guRotateF(camera->viewMtxShaking, freq * temp_f20, 0.0f, 0.0f, 1.0f);
            script->functionTemp[3].f = -script->functionTemp[3].f;
            break;

        case 2:
            guTranslateF(camera->viewMtxShaking, 0.0f, -freq * temp_f20, 0.0f);
            if ((script->functionTemp[1].s < (temp_s4 * 2)) && (temp_s4 < script->functionTemp[1].s)) {
                script->functionTemp[3].f = script->functionTemp[3].f * -0.8;
            } else {
                script->functionTemp[3].f = -script->functionTemp[3].f;
            }
            break;
    }

    if (script->functionTemp[1].s == 0) {
        camera->flags &= ~0x8;
        return ApiStatus_DONE2;
    }

    script->functionTemp[1].s--;
    return ApiStatus_BLOCK;
}

void exec_ShakeCam1(s32 arg0, s32 arg1, s32 arg2) {
    ScriptInstance* script;

    script = start_script_in_group(&ShakeCam1, 1, 0, 4);
    script->varTable[0] = arg0;
    script->varTable[1] = arg1;
    script->varTable[2] = arg2;
}

void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    ScriptInstance* script;

    script = start_script_in_group(&ShakeCamX, 1, 0, 4);
    set_variable(script, SI_VAR(0), arg0);
    set_variable(script, SI_VAR(1), arg1);
    set_variable(script, SI_VAR(2), arg2);
    set_float_variable(script, SI_VAR(3), arg3);
}

ApiStatus SetCamLeadPlayer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    if (enabled) {
        camera->flags |= 0x4;
    } else {
        camera->flags &= ~0x4;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802CB710(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 value = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_520 = (value / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus PanToTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 panPhase = get_float_variable(script, *args++);
    s32 targetType = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_506 = 1;
    if (targetType != 0) {
        camera->boolTargetPlayer = 1;
        camera->panPhase = panPhase;
    } else {
        camera->boolTargetPlayer = 0;
        camera->panPhase = 0.0f;
        camera->moveSpeed = 1.0f;
    }
    return ApiStatus_DONE2;
}

ApiStatus UseSettingsFrom(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);
    f32 f1, f2, f3, f4, f5, f6, f7;
    s32 controllerIdx;

    f4 = 32767.0f;
    controllerIdx = test_ray_zones(var1, var2 + 10.0f, var3, 0.0f, -1.0f, 0.0f, &f1, &f2, &f3, &f4, &f5, &f6, &f7);

    if (controllerIdx >= 0) {
        camera->controller = *(*D_800D91D4)[controllerIdx].controller;
    }

    return ApiStatus_DONE2;
}

ApiStatus LoadSettings(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    CameraController* controller = get_variable(script, *args++);

    camera->controller = *controller;
    
    return ApiStatus_DONE2;
}

ApiStatus SetCamType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    s32 controllerType = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    camera->controller.flag = enabled;
    camera->controller.type = controllerType;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPitch(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 boomPitch = get_float_variable(script, *args++);
    f32 viewPitch = get_float_variable(script, *args++);

    camera->controller.boomPitch = boomPitch;
    camera->controller.viewPitch = viewPitch;
    return ApiStatus_DONE2;
}

ApiStatus SetCamDistance(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 boomLength = get_float_variable(script, *args++);

    camera->controller.boomLength = boomLength;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosA(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->controller.position.x = x;
    camera->controller.position.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosB(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->controller.orientation.x = x;
    camera->controller.orientation.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 y1 = get_float_variable(script, *args++);
    f32 y2 = get_float_variable(script, *args++);

    camera->controller.position.y = y1;
    camera->controller.orientation.y = y2;
    return ApiStatus_DONE2;
}

ApiStatus SetPanTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->movePos.x = x;
    camera->movePos.y = y;
    camera->movePos.z = z;
    camera->unk_506 = 1;
    return ApiStatus_DONE2;
}

ApiStatus SetCamSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 speed = get_float_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus GetCamType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_variable(script, outVar1, camera->controller.type);
    set_variable(script, outVar2, camera->controller.flag);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPitch(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controller.boomPitch);
    set_float_variable(script, outVar2, camera->controller.viewPitch);
    return ApiStatus_DONE2;
}

ApiStatus GetCamDistance(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controller.boomLength);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosA(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controller.position.x);
    set_float_variable(script, outVar2, camera->controller.position.z);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosB(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controller.orientation.x);
    set_float_variable(script, outVar2, camera->controller.orientation.z);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controller.position.y);
    set_float_variable(script, outVar2, camera->controller.orientation.y);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosition(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->movePos.x);
    set_float_variable(script, outVar2, camera->movePos.y);
    set_float_variable(script, outVar3, camera->movePos.z);
    return ApiStatus_DONE2;
}

ApiStatus WaitForCam(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, args[0]);
    f32 endInterpValue = get_float_variable(script, args[1]);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    if (isInitialCall || !(endInterpValue <= camera->sinInterpAlpha)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamProperties(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    f32 var2 = get_float_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);
    f32 var4 = get_float_variable(script, *args++);
    f32 var5 = get_float_variable(script, *args++);
    f32 var6 = get_float_variable(script, *args++);
    f32 var7 = get_float_variable(script, *args++);
    f32 var8 = get_float_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 f1, f2, f3, f5, f6, f7;
        f32 f4 = 32767.0f;
        s32 controllerIdx = test_ray_zones(var3, var4 + 10.0f, var5, 0.0f, -1.0f, 0.0f, &f1, &f2, &f3, &f4, &f5, &f6, &f7);
        
        if (controllerIdx >= 0) {
            camera->controller = *(*D_800D91D4)[controllerIdx].controller;
        }

        camera->movePos.x = var3;
        camera->movePos.y = var4;
        camera->movePos.z = var5;
        camera->controller.boomLength = var6;
        camera->controller.boomPitch = var7;
        camera->controller.viewPitch = var8;
        camera->moveSpeed = var2;
        camera->unk_506 = 1;
        camera->boolTargetPlayer = 1;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;
        
    } else if (camera->sinInterpAlpha >= 1.0f) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus AdjustCam(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    f32 var2 = get_float_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);
    f32 var4 = get_float_variable(script, *args++);
    f32 var5 = get_float_variable(script, *args++);
    f32 var6 = get_float_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 f1, f2, f3, f5, f6, f7;
        f32 x = playerStatus->position.x;
        f32 y = playerStatus->position.y;
        f32 z = playerStatus->position.z;
        f32 f4 = 32767.0f;
        s32 controllerIdx = test_ray_zones(x, y + 10.0f, z, 0.0f, -1.0f, 0.0f, &f1, &f2, &f3, &f4, &f5, &f6, &f7);
        
        if (controllerIdx >= 0) {
            camera->controller = *(*D_800D91D4)[controllerIdx].controller;
        }

        camera->movePos.x = x + var3;
        camera->movePos.y = y;
        camera->movePos.z = z;
        camera->controller.boomLength = var4;
        camera->controller.boomPitch = var5;
        camera->controller.viewPitch = var6;
        camera->moveSpeed = var2;
        camera->unk_506 = 1;
        camera->boolTargetPlayer = 1;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;
        
    } else if (camera->sinInterpAlpha >= 1.0f) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus ResetCam(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 cameraIdx = get_variable(script, *args++);
    Camera* camera = &gCameras[cameraIdx];
    f32 var2 = get_float_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 f1, f2, f3, f5, f6, f7;
        f32 x = playerStatus->position.x;
        f32 y = playerStatus->position.y;
        f32 z = playerStatus->position.z;
        f32 f4 = 32767.0f;
        s32 controllerIdx = test_ray_zones(x, y + 10.0f, z, 0.0f, -1.0f, 0.0f, &f1, &f2, &f3, &f4, &f5, &f6, &f7);
        
        if (controllerIdx >= 0) {
            camera->controller = *(*D_800D91D4)[controllerIdx].controller;
        }

        camera->movePos.x = x;
        camera->movePos.y = y;
        camera->movePos.z = z;
        camera->moveSpeed = var2;
        camera->unk_506 = 1;
        camera->boolTargetPlayer = 1;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;

    } else if (camera->sinInterpAlpha >= 1.0f) {
        camera->unk_506 = 1;
        camera->boolTargetPlayer = 0;
        camera->moveSpeed = 1.0f;
        camera->panPhase = 0.0f;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

void func_802CCAC0(void) {
    s32 i;

    for (i = 0; i < MAX_ANIMATED_MODELS; i++) {
        AnimatedModel* anim = (*gCurrentMeshAnimationListPtr)[i];

        if (anim->animModelID >= 0) {
            func_8011EA54(anim->animModelID, &anim->mtx);
        }
    }
}

void draw_anim_models(void) {
    Matrix4f arg6;
    Matrix4f arg86;
    Matrix4f arg26;
    Matrix4f arg36;
    Matrix4f arg46;
    Matrix4f arg56;
    Matrix4f arg66;
    Matrix4f arg76;
    s32 i;

    for (i = 0; i < MAX_ANIMATED_MESHES; i++) {
        AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[i];

        if (model->animModelID >= 0) {
            guTranslateF(arg6, model->pos.x, model->pos.y, model->pos.z);
            guRotateF(arg86, model->rot.x, 1.0f, 0.0f, 0.0f);
            guRotateF(arg26, model->rot.y, 0.0f, 1.0f, 0.0f);
            guRotateF(arg36, model->rot.z, 0.0f, 0.0f, 1.0f);
            guScaleF(arg76, model->scale.x, model->scale.y, model->scale.z);
            guMtxCatF(arg36, arg86, arg56);
            guMtxCatF(arg56, arg26, arg46);
            guMtxCatF(arg76, arg46, arg56);
            guMtxCatF(arg56, arg6, arg66);
            guMtxF2L(arg66, &model->mtx);
            func_8011F304(model->animModelID, &model->mtx);
        }
    }
}

ApiStatus func_802CCCB0(ScriptInstance* script, s32 isInitialCall) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }

    return ApiStatus_DONE2;
}

ApiStatus LoadModelAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = func_8011E4B8(0);

    func_801203AC(animModelID, var1);
    animModel->animModelID = animModelID;
    animModel->pos.x = 0;
    animModel->pos.y = 0;
    animModel->pos.z = 0;
    animModel->rot.x = 0;
    animModel->rot.y = 0;
    animModel->rot.z = 0;
    animModel->scale.x = 1.0f;
    animModel->scale.y = 1.0f;
    animModel->scale.z = 1.0f;
    animModel->currentAnimData = NULL;
    guMtxIdent(&animModel->mtx);

    return ApiStatus_DONE2;
}

ApiStatus func_802CCDAC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = func_8011E4B8(0);

    func_80120474(animModelID, var1);
    animModel->animModelID = animModelID;
    animModel->pos.x = 0;
    animModel->pos.y = 0;
    animModel->pos.z = 0;
    animModel->rot.x = 0;
    animModel->rot.y = 0;
    animModel->rot.z = 0;
    animModel->scale.x = 1.0f;
    animModel->scale.y = 1.0f;
    animModel->scale.z = 1.0f;
    animModel->currentAnimData = NULL;
    guMtxIdent(&animModel->mtx);

    return ApiStatus_DONE2;
}

ApiStatus PlayModelAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);

    return ApiStatus_DONE2;
}

ApiStatus func_802CCEDC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    func_80120198(model->animModelID, var2, var3);

    return ApiStatus_DONE2;
}

ApiStatus ChangeModelAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    if (model->currentAnimData == var2) {
        return ApiStatus_DONE2;
    }

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);
    return ApiStatus_DONE2;
}

ApiStatus SetAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x = x;
    model->pos.y = y;
    model->pos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    set_float_variable(script, outX, model->pos.x);
    set_float_variable(script, outY, model->pos.y);
    set_float_variable(script, outZ, model->pos.z);

    return ApiStatus_DONE2;
}

ApiStatus AddAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x += x;
    model->pos.y += y;
    model->pos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimModelRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->rot.x = x;
    model->rot.y = y;
    model->rot.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimModelScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->scale.x = x;
    model->scale.y = y;
    model->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus func_802CD348(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 renderMode = get_float_variable(script, *args++);

    get_anim_mesh((*gCurrentMeshAnimationListPtr)[index]->animModelID)->renderMode = renderMode;
    return ApiStatus_DONE2;
}

ApiStatus func_802CD3C0(ScriptInstance* script, s32 isInitialCall) {
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[get_variable(script, *script->ptrReadPos)];

    func_8011E438(get_anim_mesh(model->animModelID));
    model->animModelID = -1;
    return ApiStatus_DONE2;
}

ApiStatus func_802CD418(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 a1 = *args++;
    s32 enable = get_variable(script, *args++);
    AnimatedMesh* animMesh = get_anim_mesh((*gCurrentMeshAnimationListPtr)[index]->animModelID);

    if (enable) {
        animMesh->flags |= a1;
    } else {
        animMesh->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}


void func_802CD4B4(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = gBattleMeshAnimationList;
    }

    for (i = 0; i < MAX_ANIMATED_MESHES; i++) {
        (*gCurrentMeshAnimationListPtr)[i] = heap_malloc(0x70);

        if ((*gCurrentMeshAnimationListPtr)[i] == NULL) {
            {} while(1);
        }

        (*gCurrentMeshAnimationListPtr)[i]->animModelID = -1;
    }

    create_dynamic_entity_world(func_802CCAC0, draw_anim_models);
}

void func_802CD57C(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }
}

ApiStatus func_802CD5C0(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = *args++;
    s32 var4 = *args++;
    s32 var5 = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];
    AnimatedMesh* animMesh = get_anim_mesh(model->animModelID);
    Unk_AnimatedMesh_struct_at_unk_10* temp_v0 = (Unk_AnimatedMesh_struct_at_unk_10*)func_8011FF98(animMesh, var2);
    f32 x, y, z;

    guMtxXFML(&model->mtx, temp_v0->unk_90, temp_v0->unk_94,temp_v0->unk_98, &x, &y, &z);
    set_variable(script, var3, x);
    set_variable(script, var4, y);
    set_variable(script, var5, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802CD6E0(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = *args++;
    s32 var4 = *args++;
    s32 var5 = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];
    AnimatedMesh* animMesh = get_anim_mesh(model->animModelID);
    Unk_AnimatedMesh_struct_at_unk_10* temp_v0 = (Unk_AnimatedMesh_struct_at_unk_10*)func_8011FF98(animMesh, var2);

    set_variable(script, var3, temp_v0->unk_9C);
    set_variable(script, var4, temp_v0->unk_A0);
    set_variable(script, var5, temp_v0->unk_A4);
    return ApiStatus_DONE2;
}

ApiStatus func_802CD7D8(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = *args++;
    s32 var4 = *args++;
    s32 var5 = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];
    AnimatedMesh* animMesh = get_anim_mesh(model->animModelID);
    Unk_AnimatedMesh_struct_at_unk_10* temp_v0 = (Unk_AnimatedMesh_struct_at_unk_10*)func_8011FF74(animMesh, var2);
    f32 x, y, z;

    guMtxXFML(&model->mtx, temp_v0->unk_90, temp_v0->unk_94,temp_v0->unk_98, &x, &y, &z);
    set_variable(script, var3, x);
    set_variable(script, var4, y);
    set_variable(script, var5, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802CD8F8(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = *args++;
    s32 var4 = *args++;
    s32 var5 = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];
    AnimatedMesh* animMesh = get_anim_mesh(model->animModelID);
    Unk_AnimatedMesh_struct_at_unk_10* temp_v0 = (Unk_AnimatedMesh_struct_at_unk_10*)func_8011FF74(animMesh, var2);

    set_variable(script, var3, temp_v0->unk_9C);
    set_variable(script, var4, temp_v0->unk_A0);
    set_variable(script, var5, temp_v0->unk_A4);
    return ApiStatus_DONE2;
}

ApiStatus func_802CD9F0(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = *args++;
    s32 var4 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];
    AnimatedMesh* animMesh = get_anim_mesh(model->animModelID);
    Unk_AnimatedMesh_struct_at_unk_10* temp_v0 = (Unk_AnimatedMesh_struct_at_unk_10*)func_8011FF98(animMesh, var2);

    if (var4 != 0) {
        temp_v0->unk_F4 |= var3;
    } else {
        temp_v0->unk_F4 &= ~var3;
    }
    return ApiStatus_DONE2;
}
