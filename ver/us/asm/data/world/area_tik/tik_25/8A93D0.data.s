.include "macro.inc"

.section .data

glabel D_80241450_8A93D0
.word 0x0000000A, 0x00000002, 0xF8405D27, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xF8405D27, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000044, 0x00000001, 0x8024083C, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0187, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, func_80240680_8A8600, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802414F0_8A9470
.word 0x0000000A, 0x00000002, 0xF8405D29, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF8405D29, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C85, 0x000000D2, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFCE, 0xFFFFFFEC, 0x00000008, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, tik_25_SetEntityPosition, 0xFD050F80, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C85, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0xFFFFFF79, 0x00000016, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, tik_25_SetEntityPosition, 0xFD050F80, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C85, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00000048, 0x00000000, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00002086, 0x00000000, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, func_80240770_8A86F0, 0xFD050F80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802416D8_8A9658
.word 0x0000000A, 0x00000002, 0xF8405D2A, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF8405D2A, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C85, 0xFFFFFF88, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFEC, 0x0000000A, 0x00000008, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, tik_25_SetEntityPosition, 0xFD050F81, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C85, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0xFFFFFF79, 0x00000016, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, tik_25_SetEntityPosition, 0xFD050F81, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C85, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00000048, 0x00000000, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00002086, 0x00000000, 0xFE363C85, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, func_80240770_8A86F0, 0xFD050F81, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE0C, 0xFFFFFEF2, 0xFFFFFFA6, 0x00000000, 0x0000005A, 0x00000003, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF8405D27, 0x00000044, 0x00000001, D_80241450_8A93D0, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x000000D2, 0xFFFFFFB5, 0xFFFFFFEC, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_802414F0_8A9470, 0x0000000A, 0x00000002, 0xF8405D29, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0x000000D2, 0xFFFFFFCE, 0xFFFFFFEC, 0x00000000, 0x00000064, D_80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000012, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0x00000096, 0xFFFFFF79, 0xFFFFFFEC, 0x00000000, 0x00000064, D_80000000, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0xFFFFFF88, 0xFFFFFFD3, 0xFFFFFFEC, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_802416D8_8A9658, 0x0000000A, 0x00000002, 0xF8405D2A, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0xFFFFFF88, 0xFFFFFFEC, 0xFFFFFFEC, 0x00000000, 0x00000064, D_80000000, 0x00000024, 0x00000002, 0xFD050F81, 0xFE363C80, 0x00000012, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0xFFFFFFC4, 0xFFFFFF79, 0xFFFFFFEC, 0x00000000, 0x00000064, D_80000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000