.include "macro.inc"

.section .data

glabel D_80240CD0_A55620
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000026, 0x00000002, 0xFE363C80, 0xF24A7A80, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C81, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C83, 0x0000002D, 0x00000002, 0xFE363C80, 0xF24A7C80, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFFD8, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFFD8, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, func_80240350_A54CA0, 0xFE363C8B, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C83, 0xFE363C8B, 0x0000000B, 0x00000002, 0xFE363C8C, 0x00000003, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x0000002C, 0x00000002, 0xFE363C80, 0xF24A7E80, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C81, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, func_80240350_A54CA0, 0xFE363C8B, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C83, 0xFE363C8B, 0x0000000B, 0x00000002, 0xFE363C8C, 0x00000003, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240EA8_A557F8
.word 0x00000024, 0x00000002, 0xFE363C81, 0x0000005B, 0x00000024, 0x00000002, 0xFE363C83, 0x00000015, 0x00000046, 0x00000001, D_80240CD0_A55620, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240EE4_A55834
.word 0x00000024, 0x00000002, 0xFE363C81, 0x0000005E, 0x00000024, 0x00000002, 0xFE363C83, 0x00000017, 0x00000046, 0x00000001, D_80240CD0_A55620, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240F20_A55870
.word 0x00000024, 0x00000002, 0xFE363C81, 0x00000061, 0x00000024, 0x00000002, 0xFE363C83, 0x00000019, 0x00000046, 0x00000001, D_80240CD0_A55620, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240F5C_A558AC
.word 0x00000024, 0x00000002, 0xFE363C81, 0x00000064, 0x00000024, 0x00000002, 0xFE363C83, 0x0000001B, 0x00000046, 0x00000001, D_80240CD0_A55620, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240F98_A558E8
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFFD, 0x00000014, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C82, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFFD, 0x00000000, 0x00000014, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C82, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802410CC_A55A1C
.word 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x0000005B, 0x00000046, 0x00000001, D_80240F98_A558E8, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x0000005E, 0x00000046, 0x00000001, D_80240F98_A558E8, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000061, 0x00000046, 0x00000001, D_80240F98_A558E8, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C82, 0x00000064, 0x00000046, 0x00000001, D_80240F98_A558E8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802411A0_A55AF0
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000001D, 0x00000065, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x0000007D, 0x00000028, 0x00000002, 0xFE363C81, 0xFE363C80, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0x0000007D, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000067, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000001D, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C84, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000043, 0x00000003, func_8024037C_A54CCC, 0xFE363C84, 0x0000001D, 0x0000000D, 0x00000002, 0xFE363C80, 0x0000005F, 0x00000043, 0x00000001, func_80240444_A54D94, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000001, 0x00000043, 0x00000002, func_80240350_A54CA0, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000051, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0x00000000, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000067, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000001D, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C84, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000043, 0x00000003, func_8024037C_A54CCC, 0xFE363C84, 0x0000001D, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000001, func_80240444_A54D94, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000001, 0x00000043, 0x00000002, func_80240350_A54CA0, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000050, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000015, 0x0000005A, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000017, 0x0000005D, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000019, 0x00000060, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000001B, 0x00000063, 0x00000047, 0x00000005, D_80240EA8_A557F8, 0x00000080, 0x00000015, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240EE4_A55834, 0x00000080, 0x00000017, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240F20_A55870, 0x00000080, 0x00000019, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240F5C_A558AC, 0x00000080, 0x0000001B, 0x00000001, 0x00000000, 0x00000044, 0x00000001, D_802410CC_A55A1C, 0x00000044, 0x00000001, D_802411A0_A55AF0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000