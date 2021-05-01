#include "common.h"
#include "map.h"

#define NAMESPACE hos_04

ApiStatus N(SetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc2)(ScriptInstance* script, s32 isInitialCall);
void N(func_80240000_A26ED0)(void);
void N(func_80240154_A27024)(void);
ApiStatus N(func_802405C0_A27490)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240654_A27524)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024068C_A2755C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802408F8_A277C8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802409B0_A27880)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240A84_A27954)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240E40_A27D10)(ScriptInstance* script, s32 isInitialCall);
void N(func_80240E6C_A27D3C)(void);

typedef struct {
    s32 unk_00;
    s32 unk_04;
} N(Unk_struct);

extern CameraController N(D_80241B50_A28A20);
extern f32 N(D_80241B7C_A28A4C);
extern s32 N(D_80241B80_A28A50);
extern s32 N(D_80241B84_A28A54);
extern s32 N(D_80241B88_A28A58);

extern s32 N(D_80243250_A2A120);
extern s32 N(D_80243254_A2A124);
extern N(Unk_struct)* N(D_80243258_A2A128);
extern s32 N(D_80243284_A2A154)[];



extern NpcGroupList N(npcGroupList_802421C4);
extern Script N(80241790);
extern Script N(80241B8C);
extern Script N(80241C5C);
extern Script N(80241E48);
extern Script N(802421E0);
extern Script N(802425C0);
extern Script N(80242A64);
extern Script N(80242E14);
extern Script N(80243294);
extern Script N(main);


