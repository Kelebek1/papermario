#include "common.h"
#include "map.h"

#define NAMESPACE hos_03

ApiStatus N(Call800E9894)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Call800E98C4SyncStatusMenu)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Call800EB168)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(CamSetFOV)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(DoesPlayerNeedSleep)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetFloorCollider)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetPartnerCall800EB168)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc29)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc32)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc35)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802407E8_A1B8E8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241FBC_A1D0BC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802425E0_A1D6E0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242B90_A1DC90)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242C14_A1DD14)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242E2C_A1DF2C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242EE0_A1DFE0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242F14_A1E014)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242F94_A1E094)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242FAC_A1E0AC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242FC8_A1E0C8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243508_A1E608)(ScriptInstance* script, s32 isInitialCall);

extern u8 N(quizAnswers)[];
extern quizReqStruct N(quizRequirements)[];
extern s32* N(D_8024801C_A2311C);
extern f32 N(D_802457F4_A208F4)[];
extern s16 N(D_80243BCC_A1ECCC);
extern s16 N(D_80243BCE_A1ECCE);
extern s16 N(D_80243BD0_A1ECD0);
extern s16 N(D_80243BD2_A1ECD2);
extern s16 N(D_80243BD4_A1ECD4);
extern NpcGroupList N(npcGroupList_8024BAE4);
extern Script N(80243630);
extern Script N(8024365C);
extern Script N(80243BD8);
extern Script N(80244650);
extern Script N(802456C4);
extern Script N(8024A7E8);
extern Script N(8024AA1C);
extern Script N(8024AAA0);
extern Script N(8024BCBC);
extern Script N(main);
extern Script N(makeEntities);
extern Script N(shakeTree);
extern s16 MessagePlural;
extern s16 MessageSingular;

enum {
    NPC_STAR_KID0,
    NPC_STAR_KID1,
    NPC_STAR_KID2,
    NPC_STAR_KID3,
    NPC_STAR_KID4,
    NPC_STAR_KID5,
    NPC_STAR_KID6,
    NPC_CHUCK_QUIZMO,
};
