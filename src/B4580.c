#include "common.h"

INCLUDE_ASM(s32, "B4580", func_8011DE80);

INCLUDE_ASM(s32, "B4580", func_8011DFD0);

INCLUDE_ASM(s32, "B4580", func_8011E014);

INCLUDE_ASM(s32, "B4580", func_8011E058);

INCLUDE_ASM(s32, "B4580", func_8011E09C);

INCLUDE_ASM(s32, "B4580", func_8011E0DC);

void *func_8011E150(Unk_AnimatedMesh_struct_at_unk_10* ptr, s32 arg1) {
    s32 i;
    void* ret;

    if (ptr->unk_FC == arg1) {
        return ptr;
    }

    for (i = 0; i < 32; i++) {
        if (ptr->unk_04[i] != 0) {
            ret = func_8011E150(ptr->unk_04[i], arg1);
            if (ret != NULL) {
                return ret;
            }
        }
    }

    return NULL;
}

INCLUDE_ASM(s32, "B4580", func_8011E1C4);

INCLUDE_ASM(s32, "B4580", func_8011E224);

INCLUDE_ASM(s32, "B4580", func_8011E310);

INCLUDE_ASM(s32, "B4580", func_8011E398);

INCLUDE_ASM(s32, "B4580", func_8011E400);

INCLUDE_ASM(s32, "B4580", func_8011E438);

INCLUDE_ASM(s32, "B4580", func_8011E4B8);

INCLUDE_ASM(s32, "B4580", func_8011E5E0);

INCLUDE_ASM(s32, "B4580", func_8011E718);

INCLUDE_ASM(s32, "B4580", func_8011E8BC);

INCLUDE_ASM(s32, "B4580", func_8011EA54);

INCLUDE_ASM(s32, "B4580", func_8011EBF0);

INCLUDE_ASM(s32, "B4580", func_8011F058);

INCLUDE_ASM(s32, "B4580", func_8011F118);

INCLUDE_ASM(s32, "B4580", func_8011F304);

INCLUDE_ASM(s32, "B4580", func_8011F3E8);

INCLUDE_ASM(s32, "B4580", func_8011F4D4);

INCLUDE_ASM(s32, "B4580", func_8011FA54);

INCLUDE_ASM(s32, "B4580", func_8011FF74);

void* func_8011FF98(AnimatedMesh* mesh, s32 arg1) {
    return func_8011E150(mesh->unk_10, arg1);
}

INCLUDE_ASM(s32, "B4580", func_8011FFB4);

AnimatedMesh* get_anim_mesh(s32 animModelID) {
    return (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];
}

AnimatedMesh* func_80120000(s32 animModelID, s32 arg1, s32 arg2) {
    AnimatedMesh* ret = (*gCurrentAnimMeshListPtr)[animModelID & ~0x800];

    ret->unk_2D4 = arg2;
    ret->unk_2D8 = arg1;
    return ret;
}

INCLUDE_ASM(s32, "B4580", func_80120028);

INCLUDE_ASM(s32, "B4580", func_8012003C);

INCLUDE_ASM(s32, "B4580", func_8012004C);

INCLUDE_ASM(s32, "B4580", func_80120064);

INCLUDE_ASM(s32, "B4580", func_8012008C);

INCLUDE_ASM(s32, "B4580", func_8012009C);

INCLUDE_ASM(s32, "B4580", func_801200B8);

INCLUDE_ASM(s32, "B4580", func_801200EC);

INCLUDE_ASM(s32, "B4580", func_80120118);

INCLUDE_ASM(s32, "B4580", play_model_animation);

INCLUDE_ASM(s32, "B4580", func_80120198);

INCLUDE_ASM(s32, "B4580", func_80120234);

INCLUDE_ASM(s32, "B4580", func_801203AC);

INCLUDE_ASM(s32, "B4580", func_80120420);

INCLUDE_ASM(s32, "B4580", func_80120474);

INCLUDE_ASM(s32, "B4580", func_80120530);

INCLUDE_ASM(s32, "B4580", func_80120678);

INCLUDE_ASM(s32, "B4580", func_801206F8);
