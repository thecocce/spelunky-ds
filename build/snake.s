
@{{BLOCK(snake)

@=======================================================================
@
@	snake, 64x32@4, 
@	Transparent color : 20,9C,00
@	+ palette 256 entries, not compressed
@	+ 32 tiles Metatiled by 2x2 not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2018-04-03, 19:49:54
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global snakeTiles		@ 1024 unsigned chars
	.hidden snakeTiles
snakeTiles:
	.word 0x00000000,0x04444400,0x46787640,0x67333364,0x73644448,0x33555680,0x63568800,0x86355400
	.word 0x00000000,0x00000000,0x00000000,0x00000004,0x00000004,0x00000008,0x00000008,0x00000008
	.word 0x44435180,0x73335580,0x15555180,0x81111800,0x08888000,0x00000000,0x00000000,0x00000000
	.word 0x00000044,0x44004477,0x83447351,0x08355518,0x00888880,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x04444400,0x46787640,0x67333364,0x73644448,0x33555680,0x63568800,0x86355400
	.word 0x00000000,0x00000000,0x00000000,0x00000004,0x00000004,0x00000008,0x00000008,0x00000008
	.word 0x34435180,0x53335580,0x15555180,0x81111800,0x08888000,0x00000000,0x00000000,0x00000000
	.word 0x00000047,0x00000473,0x00444475,0x00833551,0x00088888,0x00000000,0x00000000,0x00000000

	.word 0x44444000,0x67876400,0x73333640,0x36444480,0x35556800,0x33688400,0x83355140,0x78635518
	.word 0x00000000,0x00000004,0x00000046,0x00000047,0x00000083,0x00000008,0x00000000,0x00000004
	.word 0x33443558,0x55333518,0x51555180,0x18111800,0x80888000,0x00000000,0x00000000,0x00000000
	.word 0x00000047,0x00000043,0x00004443,0x00008355,0x00000888,0x00000000,0x00000000,0x00000000
	.word 0x04444400,0x46787640,0x67333364,0x73644448,0x33555680,0x83368840,0x83355140,0x78635518
	.word 0x00000000,0x00000000,0x00000004,0x00000004,0x00000008,0x00000000,0x00000000,0x00000004
	.word 0x33443558,0x55333518,0x51555180,0x18111800,0x80888000,0x00000000,0x00000000,0x00000000
	.word 0x00000047,0x00000043,0x00004443,0x00008355,0x00000888,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x40000000,0x40000000,0x80000000,0x00000000,0x00000000,0x40000000
	.word 0x00444440,0x04678764,0x46333376,0x84444637,0x08655533,0x04886338,0x04155338,0x81553687
	.word 0x74000000,0x34000000,0x34440000,0x55380000,0x88800000,0x22222222,0x22222222,0x22222222
	.word 0x85534433,0x81533355,0x08155515,0x00811181,0x00088808,0x22222222,0x22222222,0x22222222
	.word 0x00000000,0x40000000,0x64000000,0x74000000,0x38000000,0x80000000,0x00000000,0x40000000
	.word 0x00044444,0x00467876,0x04633337,0x08444463,0x00865553,0x00488633,0x04155338,0x81553687
	.word 0x74000000,0x34000000,0x34440000,0x55380000,0x88800000,0x22222222,0x22222222,0x22222222
	.word 0x85534433,0x81533355,0x08155515,0x00811181,0x00088808,0x22222222,0x22222222,0x22222222

	.word 0x00000000,0x00000000,0x00000000,0x40000000,0x40000000,0x80000000,0x80000000,0x80000000
	.word 0x00000000,0x00444440,0x04678764,0x46333376,0x84444637,0x08655533,0x00886536,0x00455368
	.word 0x74000000,0x37400000,0x57444400,0x15533800,0x88888000,0x22222222,0x22222222,0x22222222
	.word 0x08153443,0x08553335,0x08155551,0x00811118,0x00088880,0x22222222,0x22222222,0x22222222
	.word 0x00000000,0x00000000,0x00000000,0x40000000,0x40000000,0x80000000,0x80000000,0x80000000
	.word 0x00000000,0x00444440,0x04678764,0x46333376,0x84444637,0x08655533,0x00886536,0x00455368
	.word 0x44000000,0x77440044,0x15374438,0x81555380,0x08888800,0x22222222,0x22222222,0x22222222
	.word 0x08153444,0x08553337,0x08155551,0x00811118,0x00088880,0x22222222,0x22222222,0x22222222

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
