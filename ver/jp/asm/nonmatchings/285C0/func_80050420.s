.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050420
/* 2B820 80050420 44852000 */  mtc1      $a1, $f4
/* 2B824 80050424 3C014000 */  lui       $at, 0x4000
/* 2B828 80050428 44810800 */  mtc1      $at, $f1
/* 2B82C 8005042C 44800000 */  mtc1      $zero, $f0
/* 2B830 80050430 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2B834 80050434 AFB00010 */  sw        $s0, 0x10($sp)
/* 2B838 80050438 0080802D */  daddu     $s0, $a0, $zero
/* 2B83C 8005043C 460020A1 */  cvt.d.s   $f2, $f4
/* 2B840 80050440 4622003C */  c.lt.d    $f0, $f2
/* 2B844 80050444 00000000 */  nop
/* 2B848 80050448 45000005 */  bc1f      .L80050460
/* 2B84C 8005044C AFBF0014 */   sw       $ra, 0x14($sp)
/* 2B850 80050450 3C014000 */  lui       $at, 0x4000
/* 2B854 80050454 44812000 */  mtc1      $at, $f4
/* 2B858 80050458 08014122 */  j         .L80050488
/* 2B85C 8005045C 00000000 */   nop
.L80050460:
/* 2B860 80050460 3C013FD0 */  lui       $at, 0x3fd0
/* 2B864 80050464 44810800 */  mtc1      $at, $f1
/* 2B868 80050468 44800000 */  mtc1      $zero, $f0
/* 2B86C 8005046C 00000000 */  nop
/* 2B870 80050470 4620103C */  c.lt.d    $f2, $f0
/* 2B874 80050474 00000000 */  nop
/* 2B878 80050478 45000003 */  bc1f      .L80050488
/* 2B87C 8005047C 00000000 */   nop
/* 2B880 80050480 3C013E80 */  lui       $at, 0x3e80
/* 2B884 80050484 44812000 */  mtc1      $at, $f4
.L80050488:
/* 2B888 80050488 96050208 */  lhu       $a1, 0x208($s0)
/* 2B88C 8005048C 0200202D */  daddu     $a0, $s0, $zero
/* 2B890 80050490 0C013E2E */  jal       func_8004F8B8
/* 2B894 80050494 E60400D0 */   swc1     $f4, 0xd0($s0)
/* 2B898 80050498 00021880 */  sll       $v1, $v0, 2
/* 2B89C 8005049C 00621821 */  addu      $v1, $v1, $v0
/* 2B8A0 800504A0 00031840 */  sll       $v1, $v1, 1
/* 2B8A4 800504A4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 2B8A8 800504A8 AE030008 */  sw        $v1, 8($s0)
/* 2B8AC 800504AC AE0000BC */  sw        $zero, 0xbc($s0)
/* 2B8B0 800504B0 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 2B8B4 800504B4 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 2B8B8 800504B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2B8BC 800504BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B8C0 800504C0 03E00008 */  jr        $ra
/* 2B8C4 800504C4 27BD0018 */   addiu    $sp, $sp, 0x18
