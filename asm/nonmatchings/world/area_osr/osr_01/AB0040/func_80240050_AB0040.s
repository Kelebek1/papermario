.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_AB0040
/* AB0040 80240050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB0044 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* AB0048 80240058 0080802D */  daddu     $s0, $a0, $zero
/* AB004C 8024005C AFBF0014 */  sw        $ra, 0x14($sp)
/* AB0050 80240060 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AB0054 80240064 8E020088 */  lw        $v0, 0x88($s0)
/* AB0058 80240068 00621821 */  addu      $v1, $v1, $v0
/* AB005C 8024006C 04610004 */  bgez      $v1, .L80240080
/* AB0060 80240070 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AB0064 80240074 3C020002 */  lui       $v0, 2
/* AB0068 80240078 08090024 */  j         .L80240090
/* AB006C 8024007C 00621021 */   addu     $v0, $v1, $v0
.L80240080:
/* AB0070 80240080 3C040002 */  lui       $a0, 2
/* AB0074 80240084 0083102A */  slt       $v0, $a0, $v1
/* AB0078 80240088 10400002 */  beqz      $v0, .L80240094
/* AB007C 8024008C 00641023 */   subu     $v0, $v1, $a0
.L80240090:
/* AB0080 80240090 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240094:
/* AB0084 80240094 8E0300AC */  lw        $v1, 0xac($s0)
/* AB0088 80240098 8E02008C */  lw        $v0, 0x8c($s0)
/* AB008C 8024009C 00621821 */  addu      $v1, $v1, $v0
/* AB0090 802400A0 04610004 */  bgez      $v1, .L802400B4
/* AB0094 802400A4 AE0300AC */   sw       $v1, 0xac($s0)
/* AB0098 802400A8 3C020002 */  lui       $v0, 2
/* AB009C 802400AC 08090031 */  j         .L802400C4
/* AB00A0 802400B0 00621021 */   addu     $v0, $v1, $v0
.L802400B4:
/* AB00A4 802400B4 3C040002 */  lui       $a0, 2
/* AB00A8 802400B8 0083102A */  slt       $v0, $a0, $v1
/* AB00AC 802400BC 10400002 */  beqz      $v0, .L802400C8
/* AB00B0 802400C0 00641023 */   subu     $v0, $v1, $a0
.L802400C4:
/* AB00B4 802400C4 AE0200AC */  sw        $v0, 0xac($s0)
.L802400C8:
/* AB00B8 802400C8 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AB00BC 802400CC 8E020090 */  lw        $v0, 0x90($s0)
/* AB00C0 802400D0 00621821 */  addu      $v1, $v1, $v0
/* AB00C4 802400D4 04610004 */  bgez      $v1, .L802400E8
/* AB00C8 802400D8 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AB00CC 802400DC 3C020002 */  lui       $v0, 2
/* AB00D0 802400E0 0809003E */  j         .L802400F8
/* AB00D4 802400E4 00621021 */   addu     $v0, $v1, $v0
.L802400E8:
/* AB00D8 802400E8 3C040002 */  lui       $a0, 2
/* AB00DC 802400EC 0083102A */  slt       $v0, $a0, $v1
/* AB00E0 802400F0 10400002 */  beqz      $v0, .L802400FC
/* AB00E4 802400F4 00641023 */   subu     $v0, $v1, $a0
.L802400F8:
/* AB00E8 802400F8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400FC:
/* AB00EC 802400FC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AB00F0 80240100 8E020094 */  lw        $v0, 0x94($s0)
/* AB00F4 80240104 00621821 */  addu      $v1, $v1, $v0
/* AB00F8 80240108 04610004 */  bgez      $v1, .L8024011C
/* AB00FC 8024010C AE0300B4 */   sw       $v1, 0xb4($s0)
/* AB0100 80240110 3C020002 */  lui       $v0, 2
/* AB0104 80240114 0809004B */  j         .L8024012C
/* AB0108 80240118 00621021 */   addu     $v0, $v1, $v0
.L8024011C:
/* AB010C 8024011C 3C040002 */  lui       $a0, 2
/* AB0110 80240120 0083102A */  slt       $v0, $a0, $v1
/* AB0114 80240124 10400002 */  beqz      $v0, .L80240130
/* AB0118 80240128 00641023 */   subu     $v0, $v1, $a0
.L8024012C:
/* AB011C 8024012C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240130:
/* AB0120 80240130 8E040084 */  lw        $a0, 0x84($s0)
/* AB0124 80240134 0C046F07 */  jal       set_main_pan_u
/* AB0128 80240138 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AB012C 8024013C 8E040084 */  lw        $a0, 0x84($s0)
/* AB0130 80240140 0C046F0D */  jal       set_main_pan_v
/* AB0134 80240144 8E0500AC */   lw       $a1, 0xac($s0)
/* AB0138 80240148 8E040084 */  lw        $a0, 0x84($s0)
/* AB013C 8024014C 0C046F13 */  jal       set_aux_pan_u
/* AB0140 80240150 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AB0144 80240154 8E040084 */  lw        $a0, 0x84($s0)
/* AB0148 80240158 0C046F19 */  jal       set_aux_pan_v
/* AB014C 8024015C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AB0150 80240160 8FBF0014 */  lw        $ra, 0x14($sp)
/* AB0154 80240164 8FB00010 */  lw        $s0, 0x10($sp)
/* AB0158 80240168 0000102D */  daddu     $v0, $zero, $zero
/* AB015C 8024016C 03E00008 */  jr        $ra
/* AB0160 80240170 27BD0018 */   addiu    $sp, $sp, 0x18