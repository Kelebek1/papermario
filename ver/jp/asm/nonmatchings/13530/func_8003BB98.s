.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003BB98
/* 16F98 8003BB98 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 16F9C 8003BB9C AFB40030 */  sw        $s4, 0x30($sp)
/* 16FA0 8003BBA0 0080A02D */  daddu     $s4, $a0, $zero
/* 16FA4 8003BBA4 AFB60038 */  sw        $s6, 0x38($sp)
/* 16FA8 8003BBA8 00A0B02D */  daddu     $s6, $a1, $zero
/* 16FAC 8003BBAC AFBF0040 */  sw        $ra, 0x40($sp)
/* 16FB0 8003BBB0 AFB7003C */  sw        $s7, 0x3c($sp)
/* 16FB4 8003BBB4 AFB50034 */  sw        $s5, 0x34($sp)
/* 16FB8 8003BBB8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 16FBC 8003BBBC AFB20028 */  sw        $s2, 0x28($sp)
/* 16FC0 8003BBC0 AFB10024 */  sw        $s1, 0x24($sp)
/* 16FC4 8003BBC4 AFB00020 */  sw        $s0, 0x20($sp)
/* 16FC8 8003BBC8 828200B6 */  lb        $v0, 0xb6($s4)
/* 16FCC 8003BBCC 10400041 */  beqz      $v0, .L8003BCD4
/* 16FD0 8003BBD0 00C0B82D */   daddu    $s7, $a2, $zero
/* 16FD4 8003BBD4 8E820000 */  lw        $v0, ($s4)
/* 16FD8 8003BBD8 3C034000 */  lui       $v1, 0x4000
/* 16FDC 8003BBDC 00431024 */  and       $v0, $v0, $v1
/* 16FE0 8003BBE0 14400004 */  bnez      $v0, .L8003BBF4
/* 16FE4 8003BBE4 00000000 */   nop
/* 16FE8 8003BBE8 0C044964 */  jal       func_80112590
/* 16FEC 8003BBEC 96840028 */   lhu      $a0, 0x28($s4)
/* 16FF0 8003BBF0 AE8200C4 */  sw        $v0, 0xc4($s4)
.L8003BBF4:
/* 16FF4 8003BBF4 8E8400C4 */  lw        $a0, 0xc4($s4)
/* 16FF8 8003BBF8 A28000C1 */  sb        $zero, 0xc1($s4)
/* 16FFC 8003BBFC 8C830000 */  lw        $v1, ($a0)
/* 17000 8003BC00 2402FFFF */  addiu     $v0, $zero, -1
/* 17004 8003BC04 1062000B */  beq       $v1, $v0, .L8003BC34
/* 17008 8003BC08 0080182D */   daddu    $v1, $a0, $zero
/* 1700C 8003BC0C 0040202D */  daddu     $a0, $v0, $zero
.L8003BC10:
/* 17010 8003BC10 928200C1 */  lbu       $v0, 0xc1($s4)
/* 17014 8003BC14 24420001 */  addiu     $v0, $v0, 1
/* 17018 8003BC18 A28200C1 */  sb        $v0, 0xc1($s4)
/* 1701C 8003BC1C 00021600 */  sll       $v0, $v0, 0x18
/* 17020 8003BC20 00021583 */  sra       $v0, $v0, 0x16
/* 17024 8003BC24 00431021 */  addu      $v0, $v0, $v1
/* 17028 8003BC28 8C420000 */  lw        $v0, ($v0)
/* 1702C 8003BC2C 1444FFF8 */  bne       $v0, $a0, .L8003BC10
/* 17030 8003BC30 00000000 */   nop
.L8003BC34:
/* 17034 8003BC34 828300B6 */  lb        $v1, 0xb6($s4)
/* 17038 8003BC38 24020001 */  addiu     $v0, $zero, 1
/* 1703C 8003BC3C 14620004 */  bne       $v1, $v0, .L8003BC50
/* 17040 8003BC40 240200FF */   addiu    $v0, $zero, 0xff
/* 17044 8003BC44 A28000B7 */  sb        $zero, 0xb7($s4)
/* 17048 8003BC48 0800EF16 */  j         .L8003BC58
/* 1704C 8003BC4C A68000BE */   sh       $zero, 0xbe($s4)
.L8003BC50:
/* 17050 8003BC50 A28000B7 */  sb        $zero, 0xb7($s4)
/* 17054 8003BC54 A68200BE */  sh        $v0, 0xbe($s4)
.L8003BC58:
/* 17058 8003BC58 828200C1 */  lb        $v0, 0xc1($s4)
/* 1705C 8003BC5C 18400018 */  blez      $v0, .L8003BCC0
/* 17060 8003BC60 0000202D */   daddu    $a0, $zero, $zero
/* 17064 8003BC64 0280302D */  daddu     $a2, $s4, $zero
/* 17068 8003BC68 240500C8 */  addiu     $a1, $zero, 0xc8
.L8003BC6C:
/* 1706C 8003BC6C 8E8300C4 */  lw        $v1, 0xc4($s4)
/* 17070 8003BC70 00041080 */  sll       $v0, $a0, 2
/* 17074 8003BC74 00431021 */  addu      $v0, $v0, $v1
/* 17078 8003BC78 8C520000 */  lw        $s2, ($v0)
/* 1707C 8003BC7C 02858021 */  addu      $s0, $s4, $a1
/* 17080 8003BC80 12400009 */  beqz      $s2, .L8003BCA8
/* 17084 8003BC84 ACD002C8 */   sw       $s0, 0x2c8($a2)
/* 17088 8003BC88 0000882D */  daddu     $s1, $zero, $zero
.L8003BC8C:
/* 1708C 8003BC8C 96420000 */  lhu       $v0, ($s2)
/* 17090 8003BC90 26520002 */  addiu     $s2, $s2, 2
/* 17094 8003BC94 26310001 */  addiu     $s1, $s1, 1
/* 17098 8003BC98 A6020000 */  sh        $v0, ($s0)
/* 1709C 8003BC9C 2A220010 */  slti      $v0, $s1, 0x10
/* 170A0 8003BCA0 1440FFFA */  bnez      $v0, .L8003BC8C
/* 170A4 8003BCA4 26100002 */   addiu    $s0, $s0, 2
.L8003BCA8:
/* 170A8 8003BCA8 24C60004 */  addiu     $a2, $a2, 4
/* 170AC 8003BCAC 828200C1 */  lb        $v0, 0xc1($s4)
/* 170B0 8003BCB0 24840001 */  addiu     $a0, $a0, 1
/* 170B4 8003BCB4 0082102A */  slt       $v0, $a0, $v0
/* 170B8 8003BCB8 1440FFEC */  bnez      $v0, .L8003BC6C
/* 170BC 8003BCBC 24A50020 */   addiu    $a1, $a1, 0x20
.L8003BCC0:
/* 170C0 8003BCC0 9682030C */  lhu       $v0, 0x30c($s4)
/* 170C4 8003BCC4 A68000BE */  sh        $zero, 0xbe($s4)
/* 170C8 8003BCC8 A28000B7 */  sb        $zero, 0xb7($s4)
/* 170CC 8003BCCC A28000B6 */  sb        $zero, 0xb6($s4)
/* 170D0 8003BCD0 A68200BC */  sh        $v0, 0xbc($s4)
.L8003BCD4:
/* 170D4 8003BCD4 828300B7 */  lb        $v1, 0xb7($s4)
/* 170D8 8003BCD8 10600005 */  beqz      $v1, .L8003BCF0
/* 170DC 8003BCDC 24020001 */   addiu    $v0, $zero, 1
/* 170E0 8003BCE0 1062000C */  beq       $v1, $v0, .L8003BD14
/* 170E4 8003BCE4 24020002 */   addiu    $v0, $zero, 2
/* 170E8 8003BCE8 0800EF9B */  j         .L8003BE6C
/* 170EC 8003BCEC 00000000 */   nop
.L8003BCF0:
/* 170F0 8003BCF0 868200BC */  lh        $v0, 0xbc($s4)
/* 170F4 8003BCF4 968300BC */  lhu       $v1, 0xbc($s4)
/* 170F8 8003BCF8 10400003 */  beqz      $v0, .L8003BD08
/* 170FC 8003BCFC 2462FFFF */   addiu    $v0, $v1, -1
/* 17100 8003BD00 0800EF99 */  j         .L8003BE64
/* 17104 8003BD04 A68200BC */   sh       $v0, 0xbc($s4)
.L8003BD08:
/* 17108 8003BD08 24020001 */  addiu     $v0, $zero, 1
/* 1710C 8003BD0C A68000BE */  sh        $zero, 0xbe($s4)
/* 17110 8003BD10 A28200B7 */  sb        $v0, 0xb7($s4)
.L8003BD14:
/* 17114 8003BD14 8682030E */  lh        $v0, 0x30e($s4)
/* 17118 8003BD18 24036400 */  addiu     $v1, $zero, 0x6400
/* 1711C 8003BD1C 14400002 */  bnez      $v0, .L8003BD28
/* 17120 8003BD20 0062001A */   div      $zero, $v1, $v0
/* 17124 8003BD24 0007000D */  break     7
.L8003BD28:
/* 17128 8003BD28 2401FFFF */   addiu    $at, $zero, -1
/* 1712C 8003BD2C 14410004 */  bne       $v0, $at, .L8003BD40
/* 17130 8003BD30 3C018000 */   lui      $at, 0x8000
/* 17134 8003BD34 14610002 */  bne       $v1, $at, .L8003BD40
/* 17138 8003BD38 00000000 */   nop
/* 1713C 8003BD3C 0006000D */  break     6
.L8003BD40:
/* 17140 8003BD40 00001812 */   mflo     $v1
/* 17144 8003BD44 968200BE */  lhu       $v0, 0xbe($s4)
/* 17148 8003BD48 00431021 */  addu      $v0, $v0, $v1
/* 1714C 8003BD4C A68200BE */  sh        $v0, 0xbe($s4)
/* 17150 8003BD50 00021400 */  sll       $v0, $v0, 0x10
/* 17154 8003BD54 00021403 */  sra       $v0, $v0, 0x10
/* 17158 8003BD58 2842639D */  slti      $v0, $v0, 0x639d
/* 1715C 8003BD5C 14400003 */  bnez      $v0, .L8003BD6C
/* 17160 8003BD60 3C0651EB */   lui      $a2, 0x51eb
/* 17164 8003BD64 2402639C */  addiu     $v0, $zero, 0x639c
/* 17168 8003BD68 A68200BE */  sh        $v0, 0xbe($s4)
.L8003BD6C:
/* 1716C 8003BD6C 34C6851F */  ori       $a2, $a2, 0x851f
/* 17170 8003BD70 269300C8 */  addiu     $s3, $s4, 0xc8
/* 17174 8003BD74 0000882D */  daddu     $s1, $zero, $zero
/* 17178 8003BD78 86820308 */  lh        $v0, 0x308($s4)
/* 1717C 8003BD7C 8E8500C4 */  lw        $a1, 0xc4($s4)
/* 17180 8003BD80 968300BE */  lhu       $v1, 0xbe($s4)
/* 17184 8003BD84 00021080 */  sll       $v0, $v0, 2
/* 17188 8003BD88 00451021 */  addu      $v0, $v0, $a1
/* 1718C 8003BD8C 00031C00 */  sll       $v1, $v1, 0x10
/* 17190 8003BD90 00032403 */  sra       $a0, $v1, 0x10
/* 17194 8003BD94 8C520000 */  lw        $s2, ($v0)
/* 17198 8003BD98 8682030A */  lh        $v0, 0x30a($s4)
/* 1719C 8003BD9C 00860018 */  mult      $a0, $a2
/* 171A0 8003BDA0 00021080 */  sll       $v0, $v0, 2
/* 171A4 8003BDA4 00451021 */  addu      $v0, $v0, $a1
/* 171A8 8003BDA8 8C500000 */  lw        $s0, ($v0)
/* 171AC 8003BDAC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 171B0 8003BDB0 AE9302C8 */  sw        $s3, 0x2c8($s4)
/* 171B4 8003BDB4 00004010 */  mfhi      $t0
/* 171B8 8003BDB8 00081143 */  sra       $v0, $t0, 5
/* 171BC 8003BDBC 0043A823 */  subu      $s5, $v0, $v1
.L8003BDC0:
/* 171C0 8003BDC0 96440000 */  lhu       $a0, ($s2)
/* 171C4 8003BDC4 26520002 */  addiu     $s2, $s2, 2
/* 171C8 8003BDC8 96050000 */  lhu       $a1, ($s0)
/* 171CC 8003BDCC 26100002 */  addiu     $s0, $s0, 2
/* 171D0 8003BDD0 32A600FF */  andi      $a2, $s5, 0xff
/* 171D4 8003BDD4 0C00ED8B */  jal       func_8003B62C
/* 171D8 8003BDD8 26310001 */   addiu    $s1, $s1, 1
/* 171DC 8003BDDC A6620000 */  sh        $v0, ($s3)
/* 171E0 8003BDE0 2A220010 */  slti      $v0, $s1, 0x10
/* 171E4 8003BDE4 1440FFF6 */  bnez      $v0, .L8003BDC0
/* 171E8 8003BDE8 26730002 */   addiu    $s3, $s3, 2
/* 171EC 8003BDEC 26930128 */  addiu     $s3, $s4, 0x128
/* 171F0 8003BDF0 86820314 */  lh        $v0, 0x314($s4)
/* 171F4 8003BDF4 8E8400C4 */  lw        $a0, 0xc4($s4)
/* 171F8 8003BDF8 86830316 */  lh        $v1, 0x316($s4)
/* 171FC 8003BDFC 00021080 */  sll       $v0, $v0, 2
/* 17200 8003BE00 00441021 */  addu      $v0, $v0, $a0
/* 17204 8003BE04 00031880 */  sll       $v1, $v1, 2
/* 17208 8003BE08 00641821 */  addu      $v1, $v1, $a0
/* 1720C 8003BE0C 8C520000 */  lw        $s2, ($v0)
/* 17210 8003BE10 8C700000 */  lw        $s0, ($v1)
/* 17214 8003BE14 0000882D */  daddu     $s1, $zero, $zero
/* 17218 8003BE18 AE9302D4 */  sw        $s3, 0x2d4($s4)
.L8003BE1C:
/* 1721C 8003BE1C 96440000 */  lhu       $a0, ($s2)
/* 17220 8003BE20 26520002 */  addiu     $s2, $s2, 2
/* 17224 8003BE24 96050000 */  lhu       $a1, ($s0)
/* 17228 8003BE28 26100002 */  addiu     $s0, $s0, 2
/* 1722C 8003BE2C 32A600FF */  andi      $a2, $s5, 0xff
/* 17230 8003BE30 0C00ED8B */  jal       func_8003B62C
/* 17234 8003BE34 26310001 */   addiu    $s1, $s1, 1
/* 17238 8003BE38 A6620000 */  sh        $v0, ($s3)
/* 1723C 8003BE3C 2A220010 */  slti      $v0, $s1, 0x10
/* 17240 8003BE40 1440FFF6 */  bnez      $v0, .L8003BE1C
/* 17244 8003BE44 26730002 */   addiu    $s3, $s3, 2
/* 17248 8003BE48 32A300FF */  andi      $v1, $s5, 0xff
/* 1724C 8003BE4C 240200FF */  addiu     $v0, $zero, 0xff
/* 17250 8003BE50 14620004 */  bne       $v1, $v0, .L8003BE64
/* 17254 8003BE54 24020002 */   addiu    $v0, $zero, 2
/* 17258 8003BE58 96830310 */  lhu       $v1, 0x310($s4)
/* 1725C 8003BE5C A28200B7 */  sb        $v0, 0xb7($s4)
/* 17260 8003BE60 A68300BC */  sh        $v1, 0xbc($s4)
.L8003BE64:
/* 17264 8003BE64 828300B7 */  lb        $v1, 0xb7($s4)
/* 17268 8003BE68 24020002 */  addiu     $v0, $zero, 2
.L8003BE6C:
/* 1726C 8003BE6C 10620005 */  beq       $v1, $v0, .L8003BE84
/* 17270 8003BE70 24020003 */   addiu    $v0, $zero, 3
/* 17274 8003BE74 1062000A */  beq       $v1, $v0, .L8003BEA0
/* 17278 8003BE78 00000000 */   nop
/* 1727C 8003BE7C 0800EFFD */  j         .L8003BFF4
/* 17280 8003BE80 00000000 */   nop
.L8003BE84:
/* 17284 8003BE84 868200BC */  lh        $v0, 0xbc($s4)
/* 17288 8003BE88 968300BC */  lhu       $v1, 0xbc($s4)
/* 1728C 8003BE8C 14400058 */  bnez      $v0, .L8003BFF0
/* 17290 8003BE90 2462FFFF */   addiu    $v0, $v1, -1
/* 17294 8003BE94 24020003 */  addiu     $v0, $zero, 3
/* 17298 8003BE98 A68000BE */  sh        $zero, 0xbe($s4)
/* 1729C 8003BE9C A28200B7 */  sb        $v0, 0xb7($s4)
.L8003BEA0:
/* 172A0 8003BEA0 86820312 */  lh        $v0, 0x312($s4)
/* 172A4 8003BEA4 24036400 */  addiu     $v1, $zero, 0x6400
/* 172A8 8003BEA8 14400002 */  bnez      $v0, .L8003BEB4
/* 172AC 8003BEAC 0062001A */   div      $zero, $v1, $v0
/* 172B0 8003BEB0 0007000D */  break     7
.L8003BEB4:
/* 172B4 8003BEB4 2401FFFF */   addiu    $at, $zero, -1
/* 172B8 8003BEB8 14410004 */  bne       $v0, $at, .L8003BECC
/* 172BC 8003BEBC 3C018000 */   lui      $at, 0x8000
/* 172C0 8003BEC0 14610002 */  bne       $v1, $at, .L8003BECC
/* 172C4 8003BEC4 00000000 */   nop
/* 172C8 8003BEC8 0006000D */  break     6
.L8003BECC:
/* 172CC 8003BECC 00001812 */   mflo     $v1
/* 172D0 8003BED0 968200BE */  lhu       $v0, 0xbe($s4)
/* 172D4 8003BED4 00431021 */  addu      $v0, $v0, $v1
/* 172D8 8003BED8 A68200BE */  sh        $v0, 0xbe($s4)
/* 172DC 8003BEDC 00021400 */  sll       $v0, $v0, 0x10
/* 172E0 8003BEE0 00021403 */  sra       $v0, $v0, 0x10
/* 172E4 8003BEE4 2842639D */  slti      $v0, $v0, 0x639d
/* 172E8 8003BEE8 14400003 */  bnez      $v0, .L8003BEF8
/* 172EC 8003BEEC 3C0651EB */   lui      $a2, 0x51eb
/* 172F0 8003BEF0 2402639C */  addiu     $v0, $zero, 0x639c
/* 172F4 8003BEF4 A68200BE */  sh        $v0, 0xbe($s4)
.L8003BEF8:
/* 172F8 8003BEF8 34C6851F */  ori       $a2, $a2, 0x851f
/* 172FC 8003BEFC 269300C8 */  addiu     $s3, $s4, 0xc8
/* 17300 8003BF00 0000882D */  daddu     $s1, $zero, $zero
/* 17304 8003BF04 8682030A */  lh        $v0, 0x30a($s4)
/* 17308 8003BF08 8E8500C4 */  lw        $a1, 0xc4($s4)
/* 1730C 8003BF0C 968300BE */  lhu       $v1, 0xbe($s4)
/* 17310 8003BF10 00021080 */  sll       $v0, $v0, 2
/* 17314 8003BF14 00451021 */  addu      $v0, $v0, $a1
/* 17318 8003BF18 00031C00 */  sll       $v1, $v1, 0x10
/* 1731C 8003BF1C 00032403 */  sra       $a0, $v1, 0x10
/* 17320 8003BF20 8C520000 */  lw        $s2, ($v0)
/* 17324 8003BF24 86820308 */  lh        $v0, 0x308($s4)
/* 17328 8003BF28 00860018 */  mult      $a0, $a2
/* 1732C 8003BF2C 00021080 */  sll       $v0, $v0, 2
/* 17330 8003BF30 00451021 */  addu      $v0, $v0, $a1
/* 17334 8003BF34 8C500000 */  lw        $s0, ($v0)
/* 17338 8003BF38 00031FC3 */  sra       $v1, $v1, 0x1f
/* 1733C 8003BF3C AE9302C8 */  sw        $s3, 0x2c8($s4)
/* 17340 8003BF40 00004010 */  mfhi      $t0
/* 17344 8003BF44 00081143 */  sra       $v0, $t0, 5
/* 17348 8003BF48 0043A823 */  subu      $s5, $v0, $v1
.L8003BF4C:
/* 1734C 8003BF4C 96440000 */  lhu       $a0, ($s2)
/* 17350 8003BF50 26520002 */  addiu     $s2, $s2, 2
/* 17354 8003BF54 96050000 */  lhu       $a1, ($s0)
/* 17358 8003BF58 26100002 */  addiu     $s0, $s0, 2
/* 1735C 8003BF5C 32A600FF */  andi      $a2, $s5, 0xff
/* 17360 8003BF60 0C00ED8B */  jal       func_8003B62C
/* 17364 8003BF64 26310001 */   addiu    $s1, $s1, 1
/* 17368 8003BF68 A6620000 */  sh        $v0, ($s3)
/* 1736C 8003BF6C 2A220010 */  slti      $v0, $s1, 0x10
/* 17370 8003BF70 1440FFF6 */  bnez      $v0, .L8003BF4C
/* 17374 8003BF74 26730002 */   addiu    $s3, $s3, 2
/* 17378 8003BF78 269300E8 */  addiu     $s3, $s4, 0xe8
/* 1737C 8003BF7C 0000882D */  daddu     $s1, $zero, $zero
/* 17380 8003BF80 86830316 */  lh        $v1, 0x316($s4)
/* 17384 8003BF84 8E8400C4 */  lw        $a0, 0xc4($s4)
/* 17388 8003BF88 86820314 */  lh        $v0, 0x314($s4)
/* 1738C 8003BF8C 00031880 */  sll       $v1, $v1, 2
/* 17390 8003BF90 00641821 */  addu      $v1, $v1, $a0
/* 17394 8003BF94 00021080 */  sll       $v0, $v0, 2
/* 17398 8003BF98 00441021 */  addu      $v0, $v0, $a0
/* 1739C 8003BF9C 8C720000 */  lw        $s2, ($v1)
/* 173A0 8003BFA0 8C500000 */  lw        $s0, ($v0)
/* 173A4 8003BFA4 26820128 */  addiu     $v0, $s4, 0x128
/* 173A8 8003BFA8 AE8202D4 */  sw        $v0, 0x2d4($s4)
.L8003BFAC:
/* 173AC 8003BFAC 96440000 */  lhu       $a0, ($s2)
/* 173B0 8003BFB0 26520002 */  addiu     $s2, $s2, 2
/* 173B4 8003BFB4 96050000 */  lhu       $a1, ($s0)
/* 173B8 8003BFB8 26100002 */  addiu     $s0, $s0, 2
/* 173BC 8003BFBC 32A600FF */  andi      $a2, $s5, 0xff
/* 173C0 8003BFC0 0C00ED8B */  jal       func_8003B62C
/* 173C4 8003BFC4 26310001 */   addiu    $s1, $s1, 1
/* 173C8 8003BFC8 A6620000 */  sh        $v0, ($s3)
/* 173CC 8003BFCC 2A220010 */  slti      $v0, $s1, 0x10
/* 173D0 8003BFD0 1440FFF6 */  bnez      $v0, .L8003BFAC
/* 173D4 8003BFD4 26730002 */   addiu    $s3, $s3, 2
/* 173D8 8003BFD8 32A300FF */  andi      $v1, $s5, 0xff
/* 173DC 8003BFDC 240200FF */  addiu     $v0, $zero, 0xff
/* 173E0 8003BFE0 14620004 */  bne       $v1, $v0, .L8003BFF4
/* 173E4 8003BFE4 00000000 */   nop
/* 173E8 8003BFE8 9682030C */  lhu       $v0, 0x30c($s4)
/* 173EC 8003BFEC A28000B7 */  sb        $zero, 0xb7($s4)
.L8003BFF0:
/* 173F0 8003BFF0 A68200BC */  sh        $v0, 0xbc($s4)
.L8003BFF4:
/* 173F4 8003BFF4 828300B7 */  lb        $v1, 0xb7($s4)
/* 173F8 8003BFF8 28620004 */  slti      $v0, $v1, 4
/* 173FC 8003BFFC 1040001B */  beqz      $v0, .L8003C06C
/* 17400 8003C000 00000000 */   nop
/* 17404 8003C004 04600019 */  bltz      $v1, .L8003C06C
/* 17408 8003C008 3C034000 */   lui      $v1, 0x4000
/* 1740C 8003C00C 8E820000 */  lw        $v0, ($s4)
/* 17410 8003C010 00431024 */  and       $v0, $v0, $v1
/* 17414 8003C014 14400015 */  bnez      $v0, .L8003C06C
/* 17418 8003C018 02C0282D */   daddu    $a1, $s6, $zero
/* 1741C 8003C01C 928200AC */  lbu       $v0, 0xac($s4)
/* 17420 8003C020 928300AD */  lbu       $v1, 0xad($s4)
/* 17424 8003C024 00430018 */  mult      $v0, $v1
/* 17428 8003C028 00001012 */  mflo      $v0
/* 1742C 8003C02C 3C038080 */  lui       $v1, 0x8080
/* 17430 8003C030 34638081 */  ori       $v1, $v1, 0x8081
/* 17434 8003C034 00430018 */  mult      $v0, $v1
/* 17438 8003C038 8E830024 */  lw        $v1, 0x24($s4)
/* 1743C 8003C03C 268702C8 */  addiu     $a3, $s4, 0x2c8
/* 17440 8003C040 AFB70010 */  sw        $s7, 0x10($sp)
/* 17444 8003C044 00004810 */  mfhi      $t1
/* 17448 8003C048 01221021 */  addu      $v0, $t1, $v0
/* 1744C 8003C04C 0002A9C2 */  srl       $s5, $v0, 7
/* 17450 8003C050 32A600FF */  andi      $a2, $s5, 0xff
/* 17454 8003C054 2CC400FF */  sltiu     $a0, $a2, 0xff
/* 17458 8003C058 000427C0 */  sll       $a0, $a0, 0x1f
/* 1745C 8003C05C 3C022000 */  lui       $v0, 0x2000
/* 17460 8003C060 00822025 */  or        $a0, $a0, $v0
/* 17464 8003C064 0C0447CA */  jal       func_80111F28
/* 17468 8003C068 00642025 */   or       $a0, $v1, $a0
.L8003C06C:
/* 1746C 8003C06C 8FBF0040 */  lw        $ra, 0x40($sp)
/* 17470 8003C070 8FB7003C */  lw        $s7, 0x3c($sp)
/* 17474 8003C074 8FB60038 */  lw        $s6, 0x38($sp)
/* 17478 8003C078 8FB50034 */  lw        $s5, 0x34($sp)
/* 1747C 8003C07C 8FB40030 */  lw        $s4, 0x30($sp)
/* 17480 8003C080 8FB3002C */  lw        $s3, 0x2c($sp)
/* 17484 8003C084 8FB20028 */  lw        $s2, 0x28($sp)
/* 17488 8003C088 8FB10024 */  lw        $s1, 0x24($sp)
/* 1748C 8003C08C 8FB00020 */  lw        $s0, 0x20($sp)
/* 17490 8003C090 03E00008 */  jr        $ra
/* 17494 8003C094 27BD0048 */   addiu    $sp, $sp, 0x48
