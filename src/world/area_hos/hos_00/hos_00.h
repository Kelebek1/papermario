#include "common.h"
#include "map.h"

#define NAMESPACE hos_00

ApiStatus N(func_80240050_A0BD40)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240170_A0BE60)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024036C_A0C05C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240584_A0C274)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802407C0_A0C4B0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240908_A0C5F8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240994_A0C684)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240A54_A0C744)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240B20_A0C810)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240B3C_A0C82C)(ScriptInstance* script, s32 isInitialCall);
void N(func_80240C40_A0C930)(void);

extern s32* N(D_80242970_A0E660);
extern f32 N(D_80242B9C_A0E88C);
extern f32 N(D_80242BA0_A0E890);
extern NpcGroupList N(npcGroupList_802427EC);
extern NpcGroupList N(npcGroupList_80242810);
extern Script N(80241B60);
extern Script N(80242F20);
extern Script N(80244210);
extern Script N(80244AF0);
extern Script N(main);
extern Script N(makeEntities);

enum {
    NPC_TWINK,
    NPC_FLYING_MAGIKOOPA,
    NPC_THREE_SISTERS,
    NPC_TOAD_KID,
};
