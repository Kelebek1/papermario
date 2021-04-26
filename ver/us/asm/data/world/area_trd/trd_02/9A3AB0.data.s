.include "macro.inc"

.section .data

glabel D_80242AD0_9A3AB0
.word 0x3FC00000, 0x0000003C, 0x0000000A, 0x42DC0000, 0x42820000, 0x00000008, 0x4059999A, 0x00000078, 0x00000002, 0x42DC0000, 0x42820000, 0x00000001

glabel D_80242B00_9A3AE0
.word 0x00000043, 0x00000002, DoBasicAI, D_80242AD0_9A3AB0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80242B20_9A3B00
.word 0x00000000, 0x00170014, 0x00000000, 0x00000000, D_80242B00_9A3AE0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

glabel D_80242B4C_9A3B2C
.word 0x3FC00000, 0x0000002D, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40F00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

glabel D_80242B7C_9A3B5C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000000, 0x00000043, 0x00000002, func_80240474_9A1454, D_80242B4C_9A3B2C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80242B7C_9A3B5C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

glabel D_80242C18_9A3BF8
.word 0x3FC00000, 0x00000019, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40E00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

glabel D_80242C48_9A3C28
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000002, func_80241744_9A2724, D_80242C18_9A3BF8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80242CA4_9A3C84
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80242C48_9A3C28, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

glabel D_80242CD0_9A3CB0
.word 0x00000000, D_80242B20_9A3B00, 0xC28C0000, 0x00000000, 0x42A00000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800500A4, 0x00050000, 0x00800005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0xFFFFFFBA, 0x00000000, 0x00000050, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000023, 0x000000FA, 0x000000AF, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002C0002, 0x002C0004, 0x002C0006, 0x002C0006, 0x002C0002, 0x002C0002, 0x002C000E, 0x002C000E, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x00000001, 0x00000000, 0x00000000, 0x00000000

glabel D_80242EC0_9A3EA0
.word 0x00000001, D_80242B20_9A3B00, 0x430C0000, 0x00000000, 0x42A00000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x800500A4, 0x00050000, 0x00800005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x0000008C, 0x00000000, 0x00000050, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000023, 0x000000FA, 0x000000AF, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002C0002, 0x002C0004, 0x002C0006, 0x002C0006, 0x002C0002, 0x002C0002, 0x002C000E, 0x002C000E, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x00000001, 0x00000000, 0x00000000, 0x00000000

glabel D_802430B0_9A4090
.word 0x00000002, D_80242CA4_9A3C84, 0x42480000, 0x433B0000, 0x43370000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x00000002, 0x00000046, 0x000000BB, 0x000000B7, 0xFFFFFFEC, 0x000000BB, 0x000000B7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000014, 0x000000BB, 0x000000CF, 0x00000096, 0x00000050, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242CD0_9A3CB0, 0x0610000A, 0x00000001, D_80242EC0_9A3EA0, 0x0610000A, 0x00000001, D_802430B0_9A4090, 0x0607000D, 0x00000000, 0x00000000, 0x00000000