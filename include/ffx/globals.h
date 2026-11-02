#ifndef FFX_GLOBALS_H
#define FFX_GLOBALS_H

/* Every global of the image, declared exactly once, sorted by address. */

#include "ffx/types.h"

extern Chr *D_00300664; /* character pool base */
extern s32 D_00300668; /* pool size */
extern s32 D_00303550;
extern RegEntry D_00303558[];
extern V128 D_003035C0;
extern s8 D_00303634;
extern s8 D_00303636;
extern s8 D_00303637;
extern s16 D_00303638;
extern s32 D_00303650;
extern s8 D_00303690;
extern s32 D_003036A0;
extern s8 EnableClothSystem;
extern s8 D_003036A5;
extern s8 D_003036A6;
extern s8 D_003036A7;
extern s32 D_003036B0;
extern s32 D_00303714;
extern s8 D_00303860;
extern s32 D_00303868[];
extern s32 D_003038B8;
extern s32 D_003038E0;
extern s8 D_003038E4;
extern s8 D_003038EC;
extern s32 D_00303904;
extern s32 D_00307EAC;
extern s8 D_00307EB4;
extern s8 D_00307EB5;
extern float D_00307ED0[];
extern s32 D_00307F08;
extern s32 D_00307F38;
extern float D_00307F3C;
extern s32 D_00307F40;
extern s32 D_00307F44;
extern s32 D_00307F58;
extern s32 D_00307FA0;
extern s8 D_00307FDE;
extern s8 D_00307FDF;
extern s32 D_00307FE0;
extern float D_00308904;
extern s32 D_00308910;
extern u8 D_00308935;
extern void (*D_0030E070)(void);
extern void (*D_0030E07C)(void);
extern ChrRec1D8 *D_0030E0C0;
extern W3Owner *g_pMainWork; /* single global instance pointer; DEBT(NAME): the type name W3Owner is a guess */
extern int D_00313CB4; /* DEBT(NAME): role guess; only evidence: read and passed as the sole argument to func_0029B830 and MsEffectMotionLevel */
extern W3Sched D_00313CCC; /* DEBT(NAME): guess: the global scheduler */
extern int D_00313EAC;
extern int D_00313ED0;
extern int D_00313EE4;
extern u8 D_00314260[];
extern u8 D_003142A0[]; /* DEBT(NAME): unknown block */
extern Rec142F0 ms_screen[];
extern Unk314840 D_00314840[];
extern Unk317120 *ms_camera_now;
extern s32 ms_effect_camera_flag;
extern s32 D_00317130; /* seed of the LCG in c_1ABFD8.c (x * 0x5D588B65 + 0x3C35) */
extern s8 D_003172E0[];
extern GameState D_003172F0;
extern s8 D_00317300;
extern s8 D_00317302;
extern u8 D_00317304;
extern u8 D_00317317;
extern u8 D_0031731C;
extern s8 D_00317335;
extern s8 D_0031733B;
extern void *D_0031734C; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_00317350; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_00317354; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_00317358; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_00317360; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_00317364; /* table pointer (MsGetExcelData reads s16 count at +0, entries from +8) */
extern void *D_0031736C; /* table pointer, see D_0031734C */
extern u16 *D_00317370;
extern W5OffTbl *D_00317374;
extern RangeTbl *D_00317378; /* table pointer, also read by MsGetExcelDataNum */
extern s32 D_0031737C;
extern s8 *D_003173D0; /* DEBT(TYPE): pointer to an unknown struct; asm reads bytes +1 (func_001B3AD0) and +9 (loop test before func_001ACEA0) */
extern s32 D_003173EC;
extern u8 D_003173F4;
extern u8 D_003173F7;
extern GsEnt48 D_00317690[];
extern u8 D_0031880D;
extern u8 D_00318858[];
extern s32 D_003188B0;
extern u8 D_00318A41;
extern u8 D_00318A42;
extern s32 D_00318C6C;
extern u8 D_003192B5[3];
extern u8 D_003192C3[17];
extern s32 D_003192F0;
extern s32 D_003192F8;
extern s32 D_00319308;
extern s32 D_00319310;
extern s32 D_00319314;
extern s32 D_0031931C;
extern s16 D_00319368;
extern s16 D_0031936E;
extern s8 D_003193EC;
extern s8 D_003193ED;
extern s8 D_003193EE;
extern u8 D_003193F6;
extern u8 D_003193F8;
extern s8 D_003193FC;
extern u8 D_003193FE;
extern s8 D_00319404;
extern s8 D_00319407;
extern u8 D_00319411;
extern u8 D_00319417;
extern u8 D_0031941E;
extern u8 D_0031941F;
extern u8 D_00319420;
extern s8 D_00319423;
extern s8 D_00319426;
extern s8 D_0031942E;
extern s8 D_00319430;
extern u8 D_00319431;
extern u8 D_00319432;
extern s8 D_00319437;
extern u16 D_00319468[];
extern s32 btl_ply_win;
extern SaveData D_003194D0;
extern u8 D_0031B6BC[];
extern u8 D_0031C9DC[];
extern s32 D_0031D1DC; /* bit-flag word, accessors in c_1BD188.c (bit 0, 1, 2, ...) */
extern s32 D_0031D1E4;
extern u8 D_0031D1F8[];
extern s32 D_0031D218; /* gil, clamped to 0..999999999 by MsSetGIL */
extern u8 D_0031D228[3];
extern s32 D_0031D274;
extern s32 D_0031D278;
extern u8 D_0031D29C[];
extern u8 D_0031D31C[];
extern u8 D_0031D69C[];
extern u8 D_0031D6BC[];
extern u8 D_0031D8DC[];
extern u8 D_0031D91C[];
extern W5Ent16 D_0031D96C[200];
extern PartySlot D_0031EA9C[];
extern Rec14 D_0031F81C[];
extern u8 D_0031F988[];
extern Ent4 D_0031FA18[];
extern Ent4 D_0031FA50[];
extern Ent4 D_0031FA88[];
extern W5Buf btlgetdata;
extern W5Buf btlgetdata_mes;
extern int D_00326FFC;
extern int D_00327004;
extern int D_00327008;
extern int D_00327010[2];
extern int *D_00327018;
extern int *D_0032701C;
extern int *D_00327020;
extern int *D_00327024;
extern void (*D_00327070[])(u8 *p, int a, int *out);
extern CfgBlock D_00327160;
extern CfgBlock D_00327190;
extern s8 D_003271BC;
extern int D_003271C0;
extern int D_00327910;
extern int D_00327928;
extern int D_00327970;
extern u8 D_0036E698[][0x20]; /* 0x20-byte entries (asm indexes with sll 5) */
extern ObjTable D_0036F1F0;
extern int D_003708B8;
extern int D_003708BC;
extern int D_003708C0;
extern int D_003708C4;
extern int D_003708D0;
extern int D_003708D4;
extern int D_003708D8;
extern int D_003708DC;
extern int D_003708E0;
extern int D_003708E4;
extern int D_00372FF4;
extern u32 D_00373050;
extern u8 D_003730E4;
extern ResEntry owu_chr_status[0xF0];
extern SysObj *D_0054D5E0;
extern SlotEntry owu_eff_status[0x200];
extern Chr *owu_chr_hd[0xF0];
extern u8 owu_chr_drawoff_back[];
extern u8 owu_chr_drawoff[];
extern u8 D_00565F28[];
extern int D_005661E8;
extern int D_005661EC;
extern s8 ffx_debugmode;
extern u8 D_00566210[];
/* volatile: the original codegen keeps the access out of the jr delay slot, which only a volatile
 * access gives (decomp-permuter, ~700k iterations without type mutations: no plain form matches).
 * No interrupt user known for these sound-module bytes. */
extern volatile u8 D_00567EB0;
extern volatile u8 D_00567EB1;
extern u8 D_00567EB2;
extern volatile u8 D_00567EB3;
extern W11Reent *D_005681A4; /* DEBT(NAME): _impure_ptr guess: newlib default reent pointer */
extern int D_00568E7C; /* kernel semaphore id stored from func_002F83E0 and passed to func_002F8420/func_002F8400 */
extern s32 D_0056A3C8;
extern s32 D_0056A408;
extern s8 D_00576479;
extern s32 D_0057CE80;
extern s32 D_0057CE84;
extern s8 D_0057CE88;
extern s32 D_0057CE8C;
extern Rec16 D_0057CE90[];
extern s32 D_0057D680;
extern s32 D_0057D684;
extern s32 D_0057D688;
extern u8 D_0057D690[];
extern s32 D_0057E8B0; /* DEBT(TYPE): asm copies 0x40 bytes here (8x ld/sd in func_00106380), a 0x40-byte object (matrix?); only its address is taken in C */
extern s32 D_0057E8F0; /* DEBT(TYPE): same as D_0057E8B0 (func_001063D0 copies 0x40 bytes) */
extern s32 D_0057E970;
extern s32 D_0057E9B0[];
extern float D_0057E9D0;
extern float D_0057E9D4;
extern s32 D_0057E9D8;
extern s8 D_0057E9DC;
extern s32 D_0057E9E0;
extern s8 D_0057EA08;
extern s8 D_0057EABC;
extern s8 D_0057EABD;
extern s8 D_0057EAE8;
extern s8 D_0057EAE9;
extern u8 D_0057EAEA;
extern u8 D_0057EAEB;
extern u8 D_0057EAEC;
extern u8 D_0057EAED;
extern u8 D_0057EAEE;
extern s8 D_0057EAF8;
extern TblEntry30 *D_0057EAFC; /* entry array */
extern s32 D_0057EB00; /* entry count */
extern s32 D_0057EB30;
extern s32 D_0057EB34;
extern s32 D_0057EB38;
extern s32 D_0057EB3C;
extern s8 D_0057EB40;
extern s8 D_0057EB41;
extern s8 D_0057EB42;
extern s8 D_0057EB43;
extern s8 D_0057EB44;
extern s8 D_0057EB45;
extern s8 D_0057EB46;
extern s8 D_0057EB47;
extern s8 D_0057EB48;
extern u8 D_0057EB49;
extern float D_0057EB4C;
extern float D_0057EB50;
extern s8 D_0057EB54;
extern s8 D_0057EB55;
extern s8 D_0057EB56;
extern s8 D_0057EB57;
extern s32 D_0057EB58;
extern u8 D_0057EB74;
extern s32 D_0057EB7C;
extern float D_0057EB80;
extern float D_0057EB84;
extern float D_0057EB88;
extern s32 D_0057EBA0;
extern Handle D_0057EC80[100];
extern Handle *D_0057F2C0[100];
extern s32 D_0057F5E0;
extern s32 D_0057F60C;
extern s32 D_0057F610;
extern s16 D_0057F620;
extern s16 D_0057F624;
extern s16 D_0057F628;
extern s16 D_0057F62C;
extern float D_0057F640;
extern s8 D_0057F644;
extern float D_0057F648;
extern float D_0057F64C;
extern s32 D_0057F650;
extern s32 D_0057F654;
extern s32 D_0057F658;
extern s32 D_0057F65C;
extern s32 D_0057F660;
extern s8 D_0057F680;
extern s8 D_0057F682;
extern s8 D_0057F683;
extern s8 D_0057F6A0;
extern s32 D_0057F6B0;
extern s32 D_0057F6B4;
extern s32 D_0057F6B8;
extern s32 D_0057F6BC;
extern s32 D_0057F6C0;
extern s32 D_0057F7B0;
extern s32 D_005803D0;
extern s32 D_005803D4;
extern s16 D_005803DE;
extern s16 D_005803EE;
extern u16 D_005803FC;
extern u16 D_0058040C;
extern s16 D_0058041C;
extern s32 D_00580444;
extern s8 D_0058044E;
extern s8 D_0058044F;
extern s8 D_00580450;
extern s32 D_005804D0;
extern u8 D_005804E4;
extern Triple *D_005804E8;
extern s8 D_00580820;
extern s8 D_00580822;
extern s8 D_00580823;
extern s8 D_00580824;
extern s8 D_00580825;
extern s8 D_00580826;
extern s8 D_00580827;
extern s8 D_00580828;
extern s8 D_00580829;
extern s8 D_0058082A;
extern s8 D_0058082B;
extern s8 D_0058082C;
extern s8 D_0058082D;
extern s8 D_0058082E;
extern s8 D_0058082F;
extern s8 D_00580830;
extern s8 D_00580831;
extern s8 D_00580832;
extern s8 D_00580833;
extern s32 D_00580870;
extern s32 D_005808AC;
extern s8 D_005808B4;
extern s32 D_005808BC;
extern u8 D_00580914;
extern u8 D_00580915;
extern s32 D_00580920;
extern Cmd16 *D_00580928;
extern u8 *D_00580934; /* write cursor of a record stream (advanced by 4 in c_11E180.c) */
extern s32 D_00580B00;
extern s8 D_00580B04;
extern s8 D_00580B05;
extern s8 D_00580B24;
extern float D_00580B30;
extern s32 D_00580B34;
extern s8 D_00580BA0;
extern s8 D_00580C50;
extern s8 D_00580DE0;
extern s32 D_00580E40;
extern s32 D_00580E48;
extern s32 D_00580E50;
extern s32 D_00580E54;
extern s32 D_00580E58;
extern s32 D_00580E5C;
extern s32 D_00580E60;
extern u8 D_00580E64;
extern u8 D_00580E65;
extern u8 D_00580E66;
extern u8 D_00580E67;
extern u8 D_00580E68;
extern s32 D_00580E6C;
extern s32 D_00580E80;
extern s32 D_00588E80;
extern s32 D_00588EC0;
extern s32 D_0058CEC0;
extern struct W3Whole D_0065FD40; /* DEBT(NAME): guess: global object operated on by func_002DD0C0 */
extern s32 D_0065FF40;
extern s32 D_0065FF70;
extern struct R2Hdr0 *D_0065FF74;
extern Unk65FF88 D_0065FF88[];
extern s32 D_00661888;
extern s8 D_00661910;
extern s32 D_00661914;
extern s32 D_00661918;
extern s32 D_00662570;
extern BtlChr *D_00662574;
extern s32 D_00662578;
extern s32 D_006625E0;
extern s32 D_006625E8;
extern u8 D_006625F0[];
extern s32 D_00662610;
extern s32 D_00662614;
extern s8 D_00662618;
extern s32 D_0066261C;
extern s32 D_00662620;
extern s32 D_00662624;
extern void *InvokedFromSelectCursor; /* GS display-list write cursor: lw, store packet words, sw advanced pointer (238 loads, 413 stores) */
extern Task *D_0069BE40;
extern u8 D_0069BE54;
extern Task *D_0069BE58;
extern Task *D_0069BE5C;
extern Task *D_0069BE60;
extern u16 D_0069BEF0;
extern int D_0069BEF4;
extern int D_0069BF70;
extern int D_0069BF74;
extern int D_0069BF78;
extern int D_0069BF80[]; /* DEBT(NAME): guess, table of ints at 0x69BF80.. */
extern int D_0069BF90;
extern int D_0069BF94;
extern int D_0069BF98;
extern int D_0069BFA0;
extern int D_0069BFC8;
extern int D_0069C8CC;
extern int D_0069C8E8;
extern int D_0069C8EC;
extern void (*D_0069C8F4)(int);
extern int D_0069C8F8;
extern int D_0069C90C;
extern int D_0069C92C;
extern int D_0069C93C;
extern int D_006A3190[16];
extern int D_006A31D0[16];
extern GlobalWork *lpamng;
extern u8 D_006A3610[0x1E];
extern u16 D_006A362E;
extern void *D_006A38F0; /* table pointer for MsGetExcelData */
extern void *D_006A38F4; /* table pointer for MsGetExcelData */
extern int D_006A3900[2];
extern ChrWork *D_006A391C;
extern HeapMgr *D_006A3924;
extern int D_006A3BC4;
extern u8 *D_006A3BCC; /* write cursor of a packet buffer (read at start, written back at end: c_2567F0.c) */
extern Slot80 D_006E3BD0[];
extern SizeInfo D_006E7BD0;
extern Ent50Tbl *D_006E7BFC;
extern Slot50 D_006E7C00[];
extern PtrSlots D_006EA790;
extern s8 D_006F2F60[]; /* per bank: ordered list of active record ids, -1 = end */
extern W10Callback D_006F2FE0[]; /* records, bank * 0x20 + id */
extern HandlePool D_00703E20;
extern SysFlags D_00703FF0;
extern u8 D_00703FF6;
extern u8 D_00703FF7;
extern W10Dual D_00764990;
extern s8 D_007649A0;
extern s32 D_00788BC0[];
extern s32 D_0078AC50[]; /* thread ids */
extern s32 D_0078AC58[]; /* semaphore ids */
extern void (*D_0078AC60[])(void);
extern s32 D_0078AC80; /* semaphore id */
extern SemaParam D_0078AC88;
extern s32 D_0078ACA0[3];
extern void (*D_0078ACB0[3])(void); /* handlers installed by func_002D3F30 */
extern s32 D_0078ACBC;
extern s32 D_0078ACC0[2]; /* per-port bit mask of connected slots */
extern W10Pad D_0078ACC8[8][1]; /* DEBT(TYPE): inner dimension 1 reproduces the two equal-stride index terms; real shape unknown */
extern W10PadInfo D_0078AE80[2][1]; /* [port][slot] */
extern u8 D_0078AEC0[2][1][0x100]; /* [port][slot] DMA buffers */
extern u8 D_0078B0C0[8][1][16]; /* DEBT(TYPE): see above; button-bit remap tables */
/* volatile: shared with the vblank interrupt handler func_002D3E78 (sync ... ei, registered via
 * func_002D20D0), which bumps B100/B110 in func_002D3E08 and stores GS_CSR into B134; func_002D3FF0
 * polls B100 and reads B130/B134 in the main thread. */
extern volatile s32 D_0078B0E0;
extern volatile s32 D_0078B0F0;
extern volatile s32 D_0078B100;
extern volatile s64 D_0078B110; /* frame counter */
extern volatile s32 D_0078B120;
extern s32 D_0078B124;
extern s32 D_0078B128;
extern s32 D_0078B12C;
extern volatile s32 D_0078B130;
extern volatile s32 D_0078B134;
extern s32 D_0078B138[]; /* parallel to D_0078B160 */
extern s32 D_0078B160[];
extern s32 D_0078BA08;
extern s32 D_0078BA0C;
extern s32 D_0078BA10;
extern s32 D_0078BA14;
extern s32 D_0078BA18;
extern u32 D_0078BA1C;
extern s32 D_0078BA20;
extern W10Evt D_0078BA28; /* bit flag sets: cur / pend, set bitwise by index */
extern W10Evt D_0078BA30;
extern W10Evt D_0078BA38;
extern W10Evt D_0078BA40;
extern s32 D_0078BA48;
extern s32 D_0078BA4C;
extern u32 *D_0078BA50; /* table: word 0 = entry count, entries follow (func_002D6E10) */
extern int D_0078BA58[];
extern s32 D_0078BA98[16];
extern s32 D_0078BAD8[1]; /* single handle slot, -1 = none (c_2D6260.c loops run i < 1) */
extern W10Cmd D_0078BAE0[17];
extern s32 D_0078BB68; /* number of queued commands */
extern W10Evt D_0078BB70;
extern W10Evt D_0078BB80;
extern W10Evt D_0078BB90;
extern u8 D_0078BB9C;
extern u8 D_0078BB9D;
extern u8 D_0078BB9E;
extern u8 D_0078BB9F;
extern u8 D_0078BBA0;
extern u8 D_0078BBA1;
extern u8 D_0078BBA2;
extern s32 D_0078BBA4;
extern int D_0078BBA8;
extern char D_0078BBB0[];
extern char D_0078BBD0[];
extern int D_0078BC00;
extern int D_0078BC04;
extern int D_0078BC0C;
extern int D_0078BC10[];
extern Unk78E498 D_0078E498;
extern u8 *D_0078E4B8;
extern s16 *D_0078E4C4;
extern fp_number_type D_00791608; /* DEBT(NAME): __thenan_df guess: libgcc quiet NaN constant */
extern fp_number_sf D_00791620; /* DEBT(NAME): __thenan_sf guess: libgcc quiet NaN constant */
extern HwRegs2008250 D_2008250;

/* DMA from scratchpad channel control register; hardware clears STR (bit 8). */
#define DMA_FROM_SPR_CHCR (*(volatile u32 *)0x1000D000)

extern s32 D_0031D1E0;

#endif /* FFX_GLOBALS_H */
