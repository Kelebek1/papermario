.include "macro.inc"

.section .data

glabel D_80242930_C70C60
.float 0.02, 0.02, 0.04, 0.08, 0.11, 0.2, 0.3, 0.31, 0.42, 0.46, 0.5, 0.53, 0.56, 0.59, 0.62, 0.65, 0.68, 0.71, 0.74, 0.77, 0.8, 0.83, 0.86, 0.89, 0.92, 0.95, 0.98, 1.0

glabel D_802429A0_C70CD0
.word 0x0000000A, 0x00000002, 0xF84060A3, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xF84060A3, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000044, 0x00000001, 0x8024239C, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0186, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, func_802407F4_C6EB24, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000001C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80242A50_C70D80
.word 0x00000024, 0x00000002, 0xF84060A2, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE0C, 0x00000000, 0x0000002D, 0xFFFFFEDE, 0x00000000, 0x00000006, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF84060A3, 0x00000044, 0x00000001, D_802429A0_C70CD0, 0x0000000A, 0x00000002, 0xF84060A2, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA274, 0x000000AF, 0x00000023, 0xFFFFFF47, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80242A50_C70D80, 0x00000013, 0x00000000, 0x00000043, 0x00000008, CreatePushBlockGrid, 0x00000000, 0x0000000F, 0x00000005, 0xFFFFFFC2, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000003, SetPushBlockFallEffect, 0x00000000, func_80240720_C6EA50, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x0000000B, 0x00000004, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000