#include "common.h"
#include "map.h"

#define NAMESPACE hos_01

ApiStatus N(GetFloorCollider)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_GetFloorCollider)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnsetCamera0MoveFlag1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240000_A10880)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240120_A109A0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024031C_A10B9C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240534_A10DB4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240AAC_A1132C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240B10_A11390)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240B64_A113E4)(ScriptInstance* script, s32 isInitialCall);
void N(func_80240BB8_A11438)(void);
ApiStatus N(func_80240C08_A11488)(ScriptInstance* script, s32 isInitialCall);
void N(func_80240C34_A114B4)(void);
ApiStatus N(func_80240C84_A11504)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240CB0_A11530)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240CDC_A1155C)(ScriptInstance* script, s32 isInitialCall);

extern s32 N(D_80241C2C_A124AC);
extern s32 N(D_80241C30_A124B0);
extern NpcGroupList N(npcGroupList_80244FC0);
extern Script N(80241D48);
extern Script N(80245050);
extern Script N(80245580);
extern Script N(main);
extern Script N(makeEntities);
