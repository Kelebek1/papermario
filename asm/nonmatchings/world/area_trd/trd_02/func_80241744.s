.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241744
/* 9A2724 80241744 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 9A2728 80241748 AFB3005C */  sw        $s3, 0x5c($sp)
/* 9A272C 8024174C 0080982D */  daddu     $s3, $a0, $zero
/* 9A2730 80241750 AFBF0068 */  sw        $ra, 0x68($sp)
/* 9A2734 80241754 AFB50064 */  sw        $s5, 0x64($sp)
/* 9A2738 80241758 AFB40060 */  sw        $s4, 0x60($sp)
/* 9A273C 8024175C AFB20058 */  sw        $s2, 0x58($sp)
/* 9A2740 80241760 AFB10054 */  sw        $s1, 0x54($sp)
/* 9A2744 80241764 AFB00050 */  sw        $s0, 0x50($sp)
/* 9A2748 80241768 8E710148 */  lw        $s1, 0x148($s3)
/* 9A274C 8024176C 86240008 */  lh        $a0, 8($s1)
/* 9A2750 80241770 0C00EABB */  jal       get_npc_unsafe
/* 9A2754 80241774 00A0802D */   daddu    $s0, $a1, $zero
/* 9A2758 80241778 8E63000C */  lw        $v1, 0xc($s3)
/* 9A275C 8024177C 0260202D */  daddu     $a0, $s3, $zero
/* 9A2760 80241780 8C650000 */  lw        $a1, ($v1)
/* 9A2764 80241784 0C0B1EAF */  jal       get_variable
/* 9A2768 80241788 0040902D */   daddu    $s2, $v0, $zero
/* 9A276C 8024178C AFA00028 */  sw        $zero, 0x28($sp)
/* 9A2770 80241790 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A2774 80241794 8C630094 */  lw        $v1, 0x94($v1)
/* 9A2778 80241798 AFA3002C */  sw        $v1, 0x2c($sp)
/* 9A277C 8024179C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A2780 802417A0 8C630080 */  lw        $v1, 0x80($v1)
/* 9A2784 802417A4 AFA30030 */  sw        $v1, 0x30($sp)
/* 9A2788 802417A8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A278C 802417AC 8C630088 */  lw        $v1, 0x88($v1)
/* 9A2790 802417B0 AFA30034 */  sw        $v1, 0x34($sp)
/* 9A2794 802417B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A2798 802417B8 8C63008C */  lw        $v1, 0x8c($v1)
/* 9A279C 802417BC 27B50028 */  addiu     $s5, $sp, 0x28
/* 9A27A0 802417C0 AFA30038 */  sw        $v1, 0x38($sp)
/* 9A27A4 802417C4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A27A8 802417C8 3C0142C8 */  lui       $at, 0x42c8
/* 9A27AC 802417CC 44810000 */  mtc1      $at, $f0
/* 9A27B0 802417D0 8C630090 */  lw        $v1, 0x90($v1)
/* 9A27B4 802417D4 0040A02D */  daddu     $s4, $v0, $zero
/* 9A27B8 802417D8 E7A00040 */  swc1      $f0, 0x40($sp)
/* 9A27BC 802417DC A7A00044 */  sh        $zero, 0x44($sp)
/* 9A27C0 802417E0 12000007 */  beqz      $s0, .L80241800
/* 9A27C4 802417E4 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9A27C8 802417E8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A27CC 802417EC 864300A8 */  lh        $v1, 0xa8($s2)
/* 9A27D0 802417F0 34420008 */  ori       $v0, $v0, 8
/* 9A27D4 802417F4 AE230084 */  sw        $v1, 0x84($s1)
/* 9A27D8 802417F8 08090604 */  j         .L80241810
/* 9A27DC 802417FC AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241800:
/* 9A27E0 80241800 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A27E4 80241804 30420004 */  andi      $v0, $v0, 4
/* 9A27E8 80241808 10400048 */  beqz      $v0, .L8024192C
/* 9A27EC 8024180C 00000000 */   nop      
.L80241810:
/* 9A27F0 80241810 A640008E */  sh        $zero, 0x8e($s2)
/* 9A27F4 80241814 AE600070 */  sw        $zero, 0x70($s3)
/* 9A27F8 80241818 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A27FC 8024181C 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9A2800 80241820 A2200007 */  sb        $zero, 7($s1)
/* 9A2804 80241824 8E420000 */  lw        $v0, ($s2)
/* 9A2808 80241828 8C630000 */  lw        $v1, ($v1)
/* 9A280C 8024182C 00441024 */  and       $v0, $v0, $a0
/* 9A2810 80241830 AE420000 */  sw        $v0, ($s2)
/* 9A2814 80241834 AE430028 */  sw        $v1, 0x28($s2)
/* 9A2818 80241838 96220086 */  lhu       $v0, 0x86($s1)
/* 9A281C 8024183C A64200A8 */  sh        $v0, 0xa8($s2)
/* 9A2820 80241840 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9A2824 80241844 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9A2828 80241848 AE20008C */  sw        $zero, 0x8c($s1)
/* 9A282C 8024184C 8C420098 */  lw        $v0, 0x98($v0)
/* 9A2830 80241850 14400006 */  bnez      $v0, .L8024186C
/* 9A2834 80241854 2403FDFF */   addiu    $v1, $zero, -0x201
/* 9A2838 80241858 8E420000 */  lw        $v0, ($s2)
/* 9A283C 8024185C 2403FFF7 */  addiu     $v1, $zero, -9
/* 9A2840 80241860 34420200 */  ori       $v0, $v0, 0x200
/* 9A2844 80241864 0809061E */  j         .L80241878
/* 9A2848 80241868 00431024 */   and      $v0, $v0, $v1
.L8024186C:
/* 9A284C 8024186C 8E420000 */  lw        $v0, ($s2)
/* 9A2850 80241870 00431024 */  and       $v0, $v0, $v1
/* 9A2854 80241874 34420008 */  ori       $v0, $v0, 8
.L80241878:
/* 9A2858 80241878 AE420000 */  sw        $v0, ($s2)
/* 9A285C 8024187C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A2860 80241880 30420004 */  andi      $v0, $v0, 4
/* 9A2864 80241884 1040001E */  beqz      $v0, .L80241900
/* 9A2868 80241888 24040002 */   addiu    $a0, $zero, 2
/* 9A286C 8024188C 0240282D */  daddu     $a1, $s2, $zero
/* 9A2870 80241890 0000302D */  daddu     $a2, $zero, $zero
/* 9A2874 80241894 24020063 */  addiu     $v0, $zero, 0x63
/* 9A2878 80241898 AE620070 */  sw        $v0, 0x70($s3)
/* 9A287C 8024189C AE600074 */  sw        $zero, 0x74($s3)
/* 9A2880 802418A0 864300A8 */  lh        $v1, 0xa8($s2)
/* 9A2884 802418A4 3C013F80 */  lui       $at, 0x3f80
/* 9A2888 802418A8 44810000 */  mtc1      $at, $f0
/* 9A288C 802418AC 3C014000 */  lui       $at, 0x4000
/* 9A2890 802418B0 44811000 */  mtc1      $at, $f2
/* 9A2894 802418B4 3C01C1A0 */  lui       $at, 0xc1a0
/* 9A2898 802418B8 44812000 */  mtc1      $at, $f4
/* 9A289C 802418BC 24020028 */  addiu     $v0, $zero, 0x28
/* 9A28A0 802418C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9A28A4 802418C4 44833000 */  mtc1      $v1, $f6
/* 9A28A8 802418C8 00000000 */  nop       
/* 9A28AC 802418CC 468031A0 */  cvt.s.w   $f6, $f6
/* 9A28B0 802418D0 44073000 */  mfc1      $a3, $f6
/* 9A28B4 802418D4 27A20048 */  addiu     $v0, $sp, 0x48
/* 9A28B8 802418D8 AFA20020 */  sw        $v0, 0x20($sp)
/* 9A28BC 802418DC E7A00010 */  swc1      $f0, 0x10($sp)
/* 9A28C0 802418E0 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9A28C4 802418E4 0C01BFA4 */  jal       fx_emote
/* 9A28C8 802418E8 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9A28CC 802418EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A28D0 802418F0 2403FFFB */  addiu     $v1, $zero, -5
/* 9A28D4 802418F4 00431024 */  and       $v0, $v0, $v1
/* 9A28D8 802418F8 0809064B */  j         .L8024192C
/* 9A28DC 802418FC AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241900:
/* 9A28E0 80241900 8E220000 */  lw        $v0, ($s1)
/* 9A28E4 80241904 3C034000 */  lui       $v1, 0x4000
/* 9A28E8 80241908 00431024 */  and       $v0, $v0, $v1
/* 9A28EC 8024190C 10400007 */  beqz      $v0, .L8024192C
/* 9A28F0 80241910 3C03BFFF */   lui      $v1, 0xbfff
/* 9A28F4 80241914 2402000C */  addiu     $v0, $zero, 0xc
/* 9A28F8 80241918 AE620070 */  sw        $v0, 0x70($s3)
/* 9A28FC 8024191C 8E220000 */  lw        $v0, ($s1)
/* 9A2900 80241920 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9A2904 80241924 00431024 */  and       $v0, $v0, $v1
/* 9A2908 80241928 AE220000 */  sw        $v0, ($s1)
.L8024192C:
/* 9A290C 8024192C 8E630070 */  lw        $v1, 0x70($s3)
/* 9A2910 80241930 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9A2914 80241934 1040003A */  beqz      $v0, .L80241A20
/* 9A2918 80241938 00031080 */   sll      $v0, $v1, 2
/* 9A291C 8024193C 3C018024 */  lui       $at, 0x8024
/* 9A2920 80241940 00220821 */  addu      $at, $at, $v0
/* 9A2924 80241944 8C2234E0 */  lw        $v0, 0x34e0($at)
/* 9A2928 80241948 00400008 */  jr        $v0
/* 9A292C 8024194C 00000000 */   nop      
/* 9A2930 80241950 0260202D */  daddu     $a0, $s3, $zero
/* 9A2934 80241954 0280282D */  daddu     $a1, $s4, $zero
/* 9A2938 80241958 0C09022D */  jal       func_802408B4
/* 9A293C 8024195C 02A0302D */   daddu    $a2, $s5, $zero
/* 9A2940 80241960 96220086 */  lhu       $v0, 0x86($s1)
/* 9A2944 80241964 A64200A8 */  sh        $v0, 0xa8($s2)
/* 9A2948 80241968 0260202D */  daddu     $a0, $s3, $zero
/* 9A294C 8024196C 0280282D */  daddu     $a1, $s4, $zero
/* 9A2950 80241970 0C090283 */  jal       func_80240A0C
/* 9A2954 80241974 02A0302D */   daddu    $a2, $s5, $zero
/* 9A2958 80241978 08090688 */  j         .L80241A20
/* 9A295C 8024197C 00000000 */   nop      
/* 9A2960 80241980 0260202D */  daddu     $a0, $s3, $zero
/* 9A2964 80241984 0280282D */  daddu     $a1, $s4, $zero
/* 9A2968 80241988 0C09032D */  jal       func_80240CB4
/* 9A296C 8024198C 02A0302D */   daddu    $a2, $s5, $zero
/* 9A2970 80241990 0260202D */  daddu     $a0, $s3, $zero
/* 9A2974 80241994 0280282D */  daddu     $a1, $s4, $zero
/* 9A2978 80241998 0C09035D */  jal       func_80240D74
/* 9A297C 8024199C 02A0302D */   daddu    $a2, $s5, $zero
/* 9A2980 802419A0 08090688 */  j         .L80241A20
/* 9A2984 802419A4 00000000 */   nop      
/* 9A2988 802419A8 0260202D */  daddu     $a0, $s3, $zero
/* 9A298C 802419AC 0280282D */  daddu     $a1, $s4, $zero
/* 9A2990 802419B0 0C0903CC */  jal       func_80240F30
/* 9A2994 802419B4 02A0302D */   daddu    $a2, $s5, $zero
/* 9A2998 802419B8 08090688 */  j         .L80241A20
/* 9A299C 802419BC 00000000 */   nop      
/* 9A29A0 802419C0 0260202D */  daddu     $a0, $s3, $zero
/* 9A29A4 802419C4 0280282D */  daddu     $a1, $s4, $zero
/* 9A29A8 802419C8 0C090038 */  jal       func_802400E0
/* 9A29AC 802419CC 02A0302D */   daddu    $a2, $s5, $zero
/* 9A29B0 802419D0 0260202D */  daddu     $a0, $s3, $zero
/* 9A29B4 802419D4 0280282D */  daddu     $a1, $s4, $zero
/* 9A29B8 802419D8 0C090057 */  jal       func_8024015C
/* 9A29BC 802419DC 02A0302D */   daddu    $a2, $s5, $zero
/* 9A29C0 802419E0 08090688 */  j         .L80241A20
/* 9A29C4 802419E4 00000000 */   nop      
/* 9A29C8 802419E8 0260202D */  daddu     $a0, $s3, $zero
/* 9A29CC 802419EC 0280282D */  daddu     $a1, $s4, $zero
/* 9A29D0 802419F0 0C0900A4 */  jal       func_80240290
/* 9A29D4 802419F4 02A0302D */   daddu    $a2, $s5, $zero
/* 9A29D8 802419F8 08090688 */  j         .L80241A20
/* 9A29DC 802419FC 00000000 */   nop      
/* 9A29E0 80241A00 0260202D */  daddu     $a0, $s3, $zero
/* 9A29E4 80241A04 0280282D */  daddu     $a1, $s4, $zero
/* 9A29E8 80241A08 0C0900FD */  jal       func_802403F4
/* 9A29EC 80241A0C 02A0302D */   daddu    $a2, $s5, $zero
/* 9A29F0 80241A10 08090688 */  j         .L80241A20
/* 9A29F4 80241A14 00000000 */   nop      
/* 9A29F8 80241A18 0C0129CF */  jal       func_8004A73C
/* 9A29FC 80241A1C 0260202D */   daddu    $a0, $s3, $zero
.L80241A20:
/* 9A2A00 80241A20 8FBF0068 */  lw        $ra, 0x68($sp)
/* 9A2A04 80241A24 8FB50064 */  lw        $s5, 0x64($sp)
/* 9A2A08 80241A28 8FB40060 */  lw        $s4, 0x60($sp)
/* 9A2A0C 80241A2C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 9A2A10 80241A30 8FB20058 */  lw        $s2, 0x58($sp)
/* 9A2A14 80241A34 8FB10054 */  lw        $s1, 0x54($sp)
/* 9A2A18 80241A38 8FB00050 */  lw        $s0, 0x50($sp)
/* 9A2A1C 80241A3C 0000102D */  daddu     $v0, $zero, $zero
/* 9A2A20 80241A40 03E00008 */  jr        $ra
/* 9A2A24 80241A44 27BD0070 */   addiu    $sp, $sp, 0x70
/* 9A2A28 80241A48 00000000 */  nop       
/* 9A2A2C 80241A4C 00000000 */  nop       