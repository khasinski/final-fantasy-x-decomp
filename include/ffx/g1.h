#ifndef FFX_G1_H
#define FFX_G1_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Declarations for Gemini batch slice 1 (#26..#43). */

/* ---- c_15E858 (func_0015F198, func_0015F1F8, func_0015F258, func_0015F2C8) ---- */
#define G1_HW32_P(addr) ((u32 *volatile)(addr)) /* DEBT(FAKE): volatile pointer so gcc materializes the address and fills the jr delay slot */

/* ---- c_160BA8 (func_00160C38, func_00161A20) ---- */
/* DEBT(NAME): 0x34-byte channel entry inside the sub-table at Rec78D898.w04 */
typedef struct G1Sub160BA8Ent {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s16 h14;
    s16 h16;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
} G1Sub160BA8Ent;

/* DEBT(NAME): header at Rec78D898.w04 with 64 channel entries at +0x8 */
typedef struct G1Sub160BA8Hdr {
    s32 w00;
    s32 w04;
    G1Sub160BA8Ent ent[64];
} G1Sub160BA8Hdr;

/* ---- c_161DA0 (func_00162CE8, func_00162D78) ---- */
extern int D_0030DE30;
#ifndef FFX_V1_H
extern volatile u8 D_0030DE34;
#endif
void cd_decode_data(s32 a);
void hd_file_read_th_main(void);

/* ---- c_162DE0 (func_00162E00, func_001630B0, func_00163110, func_00163710) ---- */
/* DEBT(NAME): 0x38-byte record at D_0078E530 */
typedef struct G1Rec78E530 {
    s32 w00;
    s32 w04;
    s32 w08;
    u8 pad0C[0x18];
    s32 id;
    u8 pad28[0x8];
    s8 b30;
    s8 used;
    s8 flag;
    s8 b33;
    u8 pad34[0x4];
} G1Rec78E530;

/* DEBT(NAME): view of Unk78E498 (D_0078E498) exposing the table offset at +0x20 and table pointer at +0x28 */
typedef struct G1Vt78E498 {
    u8 pad00[0x20];
    s32 w20;
    s32 w24;
    u32 *p28;
} G1Vt78E498;
#define G1_VT78E498 ((G1Vt78E498 *)&D_0078E498) /* DEBT(CAST): Unk78E498 in types.h has pad18[0x18] over 0x20..0x2B */

extern s32 D_0078E4B0;
extern u8 D_0078F330[][0x80];
extern G1Rec78E530 D_0078E530[];
extern u8 D_0030DE20[];
int func_0015B850(void);
int func_002E1700(int a);
s32 func_002E1FB8(void);
void func_001631F0(s32 a, s32 b, s32 c, void *d);

/* ---- c_16BB88 (func_0016BC30) ---- */
extern s32 D_00597A24;
extern char D_0056C020[];
extern char D_0056C140[];
void yiAssert(int a, char *b, char *c);

/* ---- c_171718 (func_00171898) ---- */
/* DEBT(NAME): view of SlotTaskContext (D_00597E38[n]) with fields used by func_00171898 */
typedef struct G1SlotTaskCtx {
    u8 pad00[0xC];
    s32 w0C;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 owned;
} G1SlotTaskCtx;

extern s32 D_0057CB98;
extern s32 D_0057CB9C;
extern s32 D_0057CBA0;
extern s32 D_0057CBA4;
extern s32 D_0057CBA8;
void func_001710D4(void);

#endif
