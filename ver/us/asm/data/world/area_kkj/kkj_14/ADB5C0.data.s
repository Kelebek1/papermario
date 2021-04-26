.include "macro.inc"

.section .data

glabel D_80240720_ADB5C0
.word 0xE7000000, 0x00000000, 0xD7000002, 0xFFFFFFFF, 0xE3000A01, 0x00100000, 0xE3000C00, 0x00080000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xFA000000, 0x4B1F13FF, 0xFB000000, 0xFF764D00, 0xFC10E5E0, 0x230B1D52, 0xE200001C, 0x0C184B50, 0xD9FDFFFF, 0x00000000, 0xD9FFFFFF, 0x00200404, 0xDF000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xF5DE01CE, 0x00000043, 0x00000001, func_8024035C_ADB1FC, 0x00000043, 0x00000002, PlaySound, 0x000000DC, 0x00000043, 0x00000004, GotoMapSpecial, 0x8024A6B8, 0x00000004, 0x0000000C, 0x00000008, 0x00000001, 0x00000064

glabel D_802407F0_ADB690
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xF9718893, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000043, 0x00000003, GotoMap, 0x8024A6C8, 0x00000004, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x8024A6C0, 0x00000004, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802408E8_ADB788
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xF9718893, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000005, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000007, 0x00000024, 0x00000002, 0xFE363C82, 0x0000007D, 0x00000024, 0x00000002, 0xFE363C83, 0x00000080, 0x00000024, 0x00000002, 0xFE363C84, 0x0000007C, 0x00000024, 0x00000002, 0xFE363C85, 0x0000007F, 0x00000044, 0x00000001, 0x80285E9C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x8024A6D0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802409CC_ADB86C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000024, 0x00000002, 0xF9718893, 0x00000000, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x0000000A, 0x00000002, 0xF8405D61, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x8024A6E0, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x8024A6D8, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240A6C_ADB90C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0163, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240AB4_ADB954
.word 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000047, 0x00000005, D_80240A6C_ADB90C, 0x00000100, 0x00000007, 0x00000001, 0x00000000, 0x00000012, 0x00000000, 0x00000047, 0x00000005, D_802408E8_ADB788, 0x00000100, 0x00000007, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802409CC_ADB86C, 0x00080000, 0x0000001A, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000047, 0x00000005, D_802407F0_ADB690, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240B54_ADB9F4
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000005, 0x00000024, 0x00000002, 0xFE363C82, 0x0000007D, 0x00000024, 0x00000002, 0xFE363C83, 0x00000080, 0x00000024, 0x00000002, 0xFE363C84, 0x0000007C, 0x00000024, 0x00000002, 0xFE363C85, 0x0000007F, 0x00000046, 0x00000001, 0x80285EC4, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, D_80240AB4_ADB954, 0x00000044, 0x00000001, EnterWalk, 0x00000016, 0x00000001, 0x00000003, 0x00000044, 0x00000001, 0x80244E54, 0x00000016, 0x00000001, 0x00000004, 0x00000044, 0x00000001, 0x80246C90, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000005, 0x00000044, 0x00000001, 0x8024739C, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000006, 0x00000044, 0x00000001, 0x80247F7C, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000007, 0x00000044, 0x00000001, 0x802482C0, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000008, 0x00000044, 0x00000001, 0x80248430, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x00000009, 0x00000044, 0x00000001, 0x80248770, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000016, 0x00000001, 0x0000000A, 0x00000044, 0x00000001, 0x802497B4, 0x00000016, 0x00000001, 0x0000000B, 0x00000044, 0x00000001, 0x80242A60, 0x00000044, 0x00000001, D_80240AB4_ADB954, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000F, 0x00000002, 0xFE363C80, 0x00000003, 0x0000000B, 0x00000002, 0xFE363C80, 0x0000000B, 0x00000024, 0x00000002, 0xF8405D60, 0x00000000, 0x00000024, 0x00000002, 0xF8405D5F, 0x00000000, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000003, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFF97, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80243E3C, 0x00000016, 0x00000001, 0x00000004, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFB4, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000000, 0x00000016, 0x00000001, 0x00000005, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFCA, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000000, 0x00000024, 0x00000002, 0xF9718886, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802442D0, 0x00000016, 0x00000001, 0x00000006, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFF2, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000000, 0x00000016, 0x00000001, 0x00000007, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000006, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000001, 0x00000016, 0x00000001, 0x00000008, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000026, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000001, 0x00000016, 0x00000001, 0x00000009, 0x00000043, 0x00000001, func_80240384_ADB224, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000003A, 0x00000024, 0x00000002, 0xF5DE01CF, 0x00000000, 0x00000024, 0x00000002, 0xF8405D61, 0x00000001, 0x00000016, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80244B94, 0x00000016, 0x00000001, 0x0000000B, 0x00000027, 0x00000002, 0xF5DE01CF, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802439B4, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, 0x80242744, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000005, 0x00000044, 0x00000001, 0x802405C0, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80240B54_ADB9F4, 0x00000043, 0x00000003, SetTexPanner, 0x00000036, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000028, 0x00000024, 0x00000002, 0xFE363C84, 0x00000384, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, 0x80240680, 0x00000057, 0x00000000, 0x00000043, 0x00000004, func_802C90FC, 0x00000036, 0x00000000, 0xFFFFFFFF, 0x00000043, 0x00000004, func_802C9428, 0x00000000, D_80240720_ADB5C0, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000