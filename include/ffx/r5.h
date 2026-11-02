#ifndef FFX_R5_H
#define FFX_R5_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* DEBT(NAME): menu list view; the byte index selects a one-based halfword entry. */
typedef struct R5ChoiceList {
    u8 pad0[0xB];
    u8 selection;
    u8 padC[2];
    u16 entries[1]; /* C89 trailing array; allocation determines the entry count. */
} R5ChoiceList;

int func_002249B8(R5ChoiceList *choices);

#ifndef SYS_TBL
#define SYS_TBL ((SysEntry *)0x1D57300)
#endif

extern s32 *D_00692CF0;
extern s32 D_00693030;
extern int D_00693AB0;
extern int D_00694090;

/* DEBT(NAME): record with a halfword counter at 0x30 (D_00693E40) */
typedef struct R5A { u8 pad00[0x30]; u16 h30; } R5A;
extern R5A *D_00693E40;
extern u8 *D_0069BCD8;
extern char D_00573300[];
extern char D_00573310[];
extern s16 D_0069BEC8[];
extern s16 D_0069BED0[];

extern Task *D_00693AA8;
extern Task *D_00693B78;
extern Task *D_00693FD0;
extern Task *D_00326030;
extern s32 D_00693BEC;
extern int D_00693AC0;
extern s16 D_00693888[];
extern char D_00571E00[];
extern char D_00571E08[];
extern u16 *D_00693D60;
extern int D_00694110;
extern int D_00694118;
extern int D_00693E20;
/* 4-byte records, first byte is an in-use flag */
typedef struct Flag4 { u8 on; u8 b1; u8 b2; u8 pad3; } Flag4; /* D_00693E48: text cells, on = first byte of the character */
extern Flag4 D_00693E48[];
extern Task *func_002373D8();
extern long func_00266DE8();

extern Task D_0069A880[32];
extern char D_005726B8[];
extern char D_005726C8[];
extern char D_00326EF0[];
extern int D_00693FF4;
extern s16 D_00693A74;
extern s16 D_00693A76;
extern u16 D_0069BCE4;
extern int func_002381F0();
extern int TODapsPrintf();

/* DEBT(NAME): two floats, the second one is an angle kept in [-pi, pi] */
typedef struct R5Ang { float f0; float ang; } R5Ang;
extern R5Ang D_006929C0;
extern u16 D_006938B8[];
extern u16 D_006939A8[];
extern u16 D_00693960[];
extern u16 D_006939C0[];
extern u16 D_00693978[];
extern char D_00571838[];
extern char D_005717D0[];
extern char D_00571B70[];
extern Task *D_00693B7C;
extern s16 D_00693C38[];
extern s16 D_00693C30[2]; /* x, y */
extern u32 D_0032587C;
extern u32 D_00325880;
extern s16 D_00693D6A;
extern u8 D_00693F68;
extern FlagRec **D_00693F70;
/* 4-byte records ended by b0 == 0xFF */
typedef struct R5Rec4 { u8 b0; u8 b1; u8 b2; u8 b3; } R5Rec4;

/* DEBT(CAST): view of btlgetdata (W5Buf) with the members at 0xD0..0xEC that W5Buf leaves as padding; names offset-derived */
typedef struct R5Buf {
    u8 pad00[0xD0];
    s8 bD0;
    u8 padD1[3];
    u16 hD4[8];
    u8 bE4[8];
} R5Buf;
typedef struct R5Rec1C { u8 pad00[4]; int w4; u8 pad08[0x14]; } R5Rec1C;
extern R5Rec1C D_00325900[];
extern u8 D_006930B0;
extern s32 D_006930A0;
extern s32 D_006930A4;
extern u8 D_006930B2;
extern s16 D_00693C08[];
extern s16 D_00693C10[];
extern int D_0069411C;
extern char D_00571860[];
extern char D_00571870[];
extern char D_00571880[];
extern char D_00571890[];
extern char D_005718A0[];
extern CmdRec *D_0069384C;
extern s16 D_00693AC8[];
extern s16 D_00693AD0[];
extern s16 D_00693AD8[];
extern s16 D_00693AE0[];
extern s16 D_00693AE8[];
extern void (*D_00325678[])();

extern s32 D_003258C8;
extern s32 D_003258CC;
extern s32 D_003258D0;
extern s32 D_003258D4;
extern s32 D_00693878;
extern char D_00571830[];
extern char D_00571CB8[];
extern char D_00571B68[];
extern s32 D_00693340;
extern s32 D_00693334;
extern s32 D_0069333C;
extern s32 D_00693328;
extern u16 *D_003257B4;
extern void func_0022F3A8();
extern void func_0022F918();
extern int func_0022F9E8();
extern void TOMenuDrawWorldMapWindow();
extern void func_0022ACF8();
extern void func_00231840();
extern void func_00232180();
extern void func_00232350();
extern void func_00238440();
extern void func_00238718();
extern void func_0023B1C0();
extern void func_0023B4C8();
extern void func_0023BD68();
extern void func_00243800();
extern void func_00243880();

extern u16 D_00693D64;
extern u16 D_00693FF0;
extern u16 D_00694114;
extern Task *D_0069BB88;

void func_0022BBC8(void);
/* DEBT(TYPE): this caller retains the legacy implicit-int declaration view. */
#define CALL_func_0022BBC8_INT ((int (*)(void))func_0022BBC8)

#endif
