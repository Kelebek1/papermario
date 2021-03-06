.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D490
/* 28890 8004D490 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 28894 8004D494 AFB20018 */  sw        $s2, 0x18($sp)
/* 28898 8004D498 0080902D */  daddu     $s2, $a0, $zero
/* 2889C 8004D49C AFB50024 */  sw        $s5, 0x24($sp)
/* 288A0 8004D4A0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 288A4 8004D4A4 AFB40020 */  sw        $s4, 0x20($sp)
/* 288A8 8004D4A8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 288AC 8004D4AC AFB10014 */  sw        $s1, 0x14($sp)
/* 288B0 8004D4B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 288B4 8004D4B4 8E540000 */  lw        $s4, ($s2)
/* 288B8 8004D4B8 8E530010 */  lw        $s3, 0x10($s2)
/* 288BC 8004D4BC 12800074 */  beqz      $s4, .L8004D690
/* 288C0 8004D4C0 0000A82D */   daddu    $s5, $zero, $zero
/* 288C4 8004D4C4 0C013511 */  jal       func_8004D444
/* 288C8 8004D4C8 0280202D */   daddu    $a0, $s4, $zero
/* 288CC 8004D4CC 0040802D */  daddu     $s0, $v0, $zero
/* 288D0 8004D4D0 52000070 */  beql      $s0, $zero, .L8004D694
/* 288D4 8004D4D4 24150002 */   addiu    $s5, $zero, 2
/* 288D8 8004D4D8 8E020064 */  lw        $v0, 0x64($s0)
/* 288DC 8004D4DC 8E450004 */  lw        $a1, 4($s2)
/* 288E0 8004D4E0 10A00008 */  beqz      $a1, .L8004D504
/* 288E4 8004D4E4 24510010 */   addiu    $s1, $v0, 0x10
/* 288E8 8004D4E8 28A22711 */  slti      $v0, $a1, 0x2711
/* 288EC 8004D4EC 14400003 */  bnez      $v0, .L8004D4FC
/* 288F0 8004D4F0 28A200FA */   slti     $v0, $a1, 0xfa
/* 288F4 8004D4F4 08013541 */  j         .L8004D504
/* 288F8 8004D4F8 24052710 */   addiu    $a1, $zero, 0x2710
.L8004D4FC:
/* 288FC 8004D4FC 54400001 */  bnel      $v0, $zero, .L8004D504
/* 28900 8004D500 240500FA */   addiu    $a1, $zero, 0xfa
.L8004D504:
/* 28904 8004D504 8E460008 */  lw        $a2, 8($s2)
/* 28908 8004D508 28C20080 */  slti      $v0, $a2, 0x80
/* 2890C 8004D50C 50400001 */  beql      $v0, $zero, .L8004D514
/* 28910 8004D510 2406007F */   addiu    $a2, $zero, 0x7f
.L8004D514:
/* 28914 8004D514 10C00002 */  beqz      $a2, .L8004D520
/* 28918 8004D518 00061200 */   sll      $v0, $a2, 8
/* 2891C 8004D51C 344600FF */  ori       $a2, $v0, 0xff
.L8004D520:
/* 28920 8004D520 8E47000C */  lw        $a3, 0xc($s2)
/* 28924 8004D524 28E20080 */  slti      $v0, $a3, 0x80
/* 28928 8004D528 50400001 */  beql      $v0, $zero, .L8004D530
/* 2892C 8004D52C 2407007F */   addiu    $a3, $zero, 0x7f
.L8004D530:
/* 28930 8004D530 10E00003 */  beqz      $a3, .L8004D540
/* 28934 8004D534 00071200 */   sll      $v0, $a3, 8
/* 28938 8004D538 08013551 */  j         .L8004D544
/* 2893C 8004D53C 344700FF */   ori      $a3, $v0, 0xff
.L8004D540:
/* 28940 8004D540 24077FFF */  addiu     $a3, $zero, 0x7fff
.L8004D544:
/* 28944 8004D544 0C014D89 */  jal       func_80053624
/* 28948 8004D548 2604002C */   addiu    $a0, $s0, 0x2c
/* 2894C 8004D54C 0200202D */  daddu     $a0, $s0, $zero
/* 28950 8004D550 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 28954 8004D554 A6020044 */  sh        $v0, 0x44($s0)
/* 28958 8004D558 24020001 */  addiu     $v0, $zero, 1
/* 2895C 8004D55C A6020046 */  sh        $v0, 0x46($s0)
/* 28960 8004D560 92220000 */  lbu       $v0, ($s1)
/* 28964 8004D564 3C050002 */  lui       $a1, 2
/* 28968 8004D568 30420007 */  andi      $v0, $v0, 7
/* 2896C 8004D56C 3C068008 */  lui       $a2, %hi(D_800784E0)
/* 28970 8004D570 00C23021 */  addu      $a2, $a2, $v0
/* 28974 8004D574 90C684E0 */  lbu       $a2, %lo(D_800784E0)($a2)
/* 28978 8004D578 0C01394C */  jal       func_8004E530
/* 2897C 8004D57C 34A5625A */   ori      $a1, $a1, 0x625a
/* 28980 8004D580 2E620004 */  sltiu     $v0, $s3, 4
/* 28984 8004D584 10400005 */  beqz      $v0, .L8004D59C
/* 28988 8004D588 00131040 */   sll      $v0, $s3, 1
/* 2898C 8004D58C 02221021 */  addu      $v0, $s1, $v0
/* 28990 8004D590 94420004 */  lhu       $v0, 4($v0)
/* 28994 8004D594 14400003 */  bnez      $v0, .L8004D5A4
/* 28998 8004D598 00131040 */   sll      $v0, $s3, 1
.L8004D59C:
/* 2899C 8004D59C 0000982D */  daddu     $s3, $zero, $zero
/* 289A0 8004D5A0 00131040 */  sll       $v0, $s3, 1
.L8004D5A4:
/* 289A4 8004D5A4 02221021 */  addu      $v0, $s1, $v0
/* 289A8 8004D5A8 AE130060 */  sw        $s3, 0x60($s0)
/* 289AC 8004D5AC 94420004 */  lhu       $v0, 4($v0)
/* 289B0 8004D5B0 8E030064 */  lw        $v1, 0x64($s0)
/* 289B4 8004D5B4 00021080 */  sll       $v0, $v0, 2
/* 289B8 8004D5B8 00431021 */  addu      $v0, $v0, $v1
/* 289BC 8004D5BC AE02006C */  sw        $v0, 0x6c($s0)
/* 289C0 8004D5C0 AE020068 */  sw        $v0, 0x68($s0)
/* 289C4 8004D5C4 9622000C */  lhu       $v0, 0xc($s1)
/* 289C8 8004D5C8 1040001F */  beqz      $v0, .L8004D648
/* 289CC 8004D5CC 00021080 */   sll      $v0, $v0, 2
/* 289D0 8004D5D0 00431021 */  addu      $v0, $v0, $v1
/* 289D4 8004D5D4 AE020078 */  sw        $v0, 0x78($s0)
/* 289D8 8004D5D8 9222000F */  lbu       $v0, 0xf($s1)
/* 289DC 8004D5DC A202021C */  sb        $v0, 0x21c($s0)
/* 289E0 8004D5E0 304200FF */  andi      $v0, $v0, 0xff
/* 289E4 8004D5E4 1040000C */  beqz      $v0, .L8004D618
/* 289E8 8004D5E8 0000182D */   daddu    $v1, $zero, $zero
/* 289EC 8004D5EC 0200282D */  daddu     $a1, $s0, $zero
/* 289F0 8004D5F0 0060202D */  daddu     $a0, $v1, $zero
.L8004D5F4:
/* 289F4 8004D5F4 8E020078 */  lw        $v0, 0x78($s0)
/* 289F8 8004D5F8 24630001 */  addiu     $v1, $v1, 1
/* 289FC 8004D5FC 00441021 */  addu      $v0, $v0, $a0
/* 28A00 8004D600 ACA20080 */  sw        $v0, 0x80($a1)
/* 28A04 8004D604 24A50004 */  addiu     $a1, $a1, 4
/* 28A08 8004D608 9202021C */  lbu       $v0, 0x21c($s0)
/* 28A0C 8004D60C 0062102B */  sltu      $v0, $v1, $v0
/* 28A10 8004D610 1440FFF8 */  bnez      $v0, .L8004D5F4
/* 28A14 8004D614 2484000C */   addiu    $a0, $a0, 0xc
.L8004D618:
/* 28A18 8004D618 2C62000C */  sltiu     $v0, $v1, 0xc
/* 28A1C 8004D61C 1040000C */  beqz      $v0, .L8004D650
/* 28A20 8004D620 00031080 */   sll      $v0, $v1, 2
/* 28A24 8004D624 00502021 */  addu      $a0, $v0, $s0
.L8004D628:
/* 28A28 8004D628 8E020080 */  lw        $v0, 0x80($s0)
/* 28A2C 8004D62C 24630001 */  addiu     $v1, $v1, 1
/* 28A30 8004D630 AC820080 */  sw        $v0, 0x80($a0)
/* 28A34 8004D634 2C62000C */  sltiu     $v0, $v1, 0xc
/* 28A38 8004D638 1440FFFB */  bnez      $v0, .L8004D628
/* 28A3C 8004D63C 24840004 */   addiu    $a0, $a0, 4
/* 28A40 8004D640 08013594 */  j         .L8004D650
/* 28A44 8004D644 00000000 */   nop
.L8004D648:
/* 28A48 8004D648 AE000078 */  sw        $zero, 0x78($s0)
/* 28A4C 8004D64C A200021C */  sb        $zero, 0x21c($s0)
.L8004D650:
/* 28A50 8004D650 96220010 */  lhu       $v0, 0x10($s1)
/* 28A54 8004D654 10400007 */  beqz      $v0, .L8004D674
/* 28A58 8004D658 00021080 */   sll      $v0, $v0, 2
/* 28A5C 8004D65C 8E030064 */  lw        $v1, 0x64($s0)
/* 28A60 8004D660 00431021 */  addu      $v0, $v0, $v1
/* 28A64 8004D664 AE02007C */  sw        $v0, 0x7c($s0)
/* 28A68 8004D668 92220013 */  lbu       $v0, 0x13($s1)
/* 28A6C 8004D66C 0801359F */  j         .L8004D67C
/* 28A70 8004D670 A202021D */   sb       $v0, 0x21d($s0)
.L8004D674:
/* 28A74 8004D674 AE00007C */  sw        $zero, 0x7c($s0)
/* 28A78 8004D678 A200021D */  sb        $zero, 0x21d($s0)
.L8004D67C:
/* 28A7C 8004D67C AE14001C */  sw        $s4, 0x1c($s0)
/* 28A80 8004D680 0C0138A2 */  jal       func_8004E288
/* 28A84 8004D684 0200202D */   daddu    $a0, $s0, $zero
/* 28A88 8004D688 080135A6 */  j         .L8004D698
/* 28A8C 8004D68C 02A0102D */   daddu    $v0, $s5, $zero
.L8004D690:
/* 28A90 8004D690 24150003 */  addiu     $s5, $zero, 3
.L8004D694:
/* 28A94 8004D694 02A0102D */  daddu     $v0, $s5, $zero
.L8004D698:
/* 28A98 8004D698 8FBF0028 */  lw        $ra, 0x28($sp)
/* 28A9C 8004D69C 8FB50024 */  lw        $s5, 0x24($sp)
/* 28AA0 8004D6A0 8FB40020 */  lw        $s4, 0x20($sp)
/* 28AA4 8004D6A4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 28AA8 8004D6A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 28AAC 8004D6AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 28AB0 8004D6B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 28AB4 8004D6B4 03E00008 */  jr        $ra
/* 28AB8 8004D6B8 27BD0030 */   addiu    $sp, $sp, 0x30
