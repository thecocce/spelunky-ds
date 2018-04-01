
@{{BLOCK(snake)

@=======================================================================
@
@	snake, 64x32@8, 
@	Transparent color : 20,9C,00
@	+ palette 256 entries, not compressed
@	+ 32 tiles Metatiled by 2x2 not compressed
@	Total size: 512 + 2048 = 2560
@
@	Time-stamp: 2018-04-01, 19:09:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global snakeTiles		@ 2048 unsigned chars
	.hidden snakeTiles
snakeTiles:
	.word 0x00000000,0x00000000,0x04040000,0x00040404,0x07060400,0x04060708,0x03030604,0x06070303
	.word 0x04040408,0x07030604,0x05060800,0x03030505,0x08080000,0x06030506,0x05040000,0x08060305
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000
	.word 0x00000004,0x00000000,0x00000008,0x00000000,0x00000008,0x00000000,0x00000008,0x00000000
	.word 0x05010800,0x04040403,0x05050800,0x07030303,0x05010800,0x01050505,0x01080000,0x08010101
	.word 0x08000000,0x00080808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000404,0x00000000,0x04040707,0x04040000,0x07030501,0x08030404,0x05050108,0x00080305
	.word 0x08080800,0x00000808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x04040000,0x00040404,0x07060400,0x04060708,0x03030604,0x06070303
	.word 0x04040408,0x07030604,0x05060800,0x03030505,0x08080000,0x06030506,0x05040000,0x08060305
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000
	.word 0x00000004,0x00000000,0x00000008,0x00000000,0x00000008,0x00000000,0x00000008,0x00000000
	.word 0x05010800,0x03040403,0x05050800,0x05030303,0x05010800,0x01050505,0x01080000,0x08010101
	.word 0x08000000,0x00080808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000407,0x00000000,0x00040703,0x00000000,0x04040705,0x00000404,0x03050501,0x00000803
	.word 0x08080808,0x00000008,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x04000000,0x04040404,0x06040000,0x06070807,0x03060400,0x07030303,0x04040800,0x03060404
	.word 0x06080000,0x03050505,0x08040000,0x03030608,0x05010400,0x08030305,0x05050108,0x07080603
	.word 0x00000000,0x00000000,0x00000004,0x00000000,0x00000406,0x00000000,0x00000407,0x00000000
	.word 0x00000803,0x00000000,0x00000008,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000
	.word 0x03050508,0x03030404,0x03050108,0x05050303,0x05010800,0x05010505,0x01080000,0x01080101
	.word 0x08000000,0x08000808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000407,0x00000000,0x00000403,0x00000000,0x04040403,0x00000000,0x08030505,0x00000000
	.word 0x00080808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x04040000,0x00040404,0x07060400,0x04060708,0x03030604,0x06070303,0x04040408,0x07030604
	.word 0x05060800,0x03030505,0x08080400,0x08030306,0x05010400,0x08030305,0x05050108,0x07080603
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000,0x00000004,0x00000000
	.word 0x00000008,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000004,0x00000000
	.word 0x03050508,0x03030404,0x03050108,0x05050303,0x05010800,0x05010505,0x01080000,0x01080101
	.word 0x08000000,0x08000808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000407,0x00000000,0x00000403,0x00000000,0x04040403,0x00000000,0x08030505,0x00000000
	.word 0x00080808,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000,0x00000000,0x04000000
	.word 0x00000000,0x08000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000
	.word 0x04040400,0x00000404,0x08070604,0x00040607,0x03030706,0x04060303,0x04060307,0x08040404
	.word 0x05050303,0x00080605,0x06030308,0x00040808,0x05030308,0x00040105,0x03060807,0x08010505
	.word 0x00000000,0x07040000,0x00000000,0x03040000,0x00000000,0x03040404,0x00000000,0x05050308
	.word 0x00000000,0x08080800,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202
	.word 0x04040303,0x08050503,0x03030505,0x08010503,0x05050105,0x00080105,0x01010801,0x00000801
	.word 0x08080008,0x00000008,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202

	.word 0x00000000,0x00000000,0x00000000,0x04000000,0x00000000,0x06040000,0x00000000,0x07040000
	.word 0x00000000,0x03080000,0x00000000,0x08000000,0x00000000,0x00000000,0x00000000,0x04000000
	.word 0x04040404,0x00000004,0x07080706,0x00000406,0x03030307,0x00040603,0x04040603,0x00080404
	.word 0x05050503,0x00000806,0x08060303,0x00000408,0x05030308,0x00040105,0x03060807,0x08010505
	.word 0x00000000,0x07040000,0x00000000,0x03040000,0x00000000,0x03040404,0x00000000,0x05050308
	.word 0x00000000,0x08080800,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202
	.word 0x04040303,0x08050503,0x03030505,0x08010503,0x05050105,0x00080105,0x01010801,0x00000801
	.word 0x08080008,0x00000008,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000
	.word 0x00000000,0x04000000,0x00000000,0x08000000,0x00000000,0x08000000,0x00000000,0x08000000
	.word 0x00000000,0x00000000,0x04040400,0x00000404,0x08070604,0x00040607,0x03030706,0x04060303
	.word 0x04060307,0x08040404,0x05050303,0x00080605,0x06050306,0x00000808,0x05030608,0x00000405
	.word 0x00000000,0x07040000,0x00000000,0x03070400,0x04040000,0x05070404,0x03080000,0x01050503
	.word 0x08000000,0x08080808,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202
	.word 0x03040403,0x00080105,0x03030305,0x00080505,0x05050501,0x00080105,0x01010108,0x00000801
	.word 0x08080800,0x00000008,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000
	.word 0x00000000,0x04000000,0x00000000,0x08000000,0x00000000,0x08000000,0x00000000,0x08000000
	.word 0x00000000,0x00000000,0x04040400,0x00000404,0x08070604,0x00040607,0x03030706,0x04060303
	.word 0x04060307,0x08040404,0x05050303,0x00080605,0x06050306,0x00000808,0x05030608,0x00000405
	.word 0x00000000,0x04040000,0x00000404,0x07070404,0x04040308,0x01050307,0x05030800,0x08010505
	.word 0x08080000,0x00080808,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202
	.word 0x03040404,0x00080105,0x03030307,0x00080505,0x05050501,0x00080105,0x01010108,0x00000801
	.word 0x08080800,0x00000008,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202

	.section .rodata
	.align	2
	.global snakePal		@ 512 unsigned chars
	.hidden snakePal
snakePal:
	.hword 0x0264,0x258E,0x0000,0x1F11,0x04E4,0x3675,0x0D88,0x1778
	.hword 0x0480,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(snake)
