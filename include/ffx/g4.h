#ifndef FFX_G4_H
#define FFX_G4_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* ---- #82 c_257810 ---- */
int func_00257A08(int ch);

/* ---- #83 c_25A8D0 ---- */
u8 *func_001FE2F8(void *a, int b, int c, int d);

/* ---- #84, #85 c_27EBD8 ---- */
typedef struct G4Hb { /* DEBT(NAME): particle frame/key cursor */
    u16 h0;
    u8 b2;
} G4Hb;

typedef struct G4PtKey { /* DEBT(NAME): particle animation keyframe */
    s16 ofs;
    s16 dur;
    s8 flags;
    u8 pad5[3];
} G4PtKey;

typedef struct G4PtAnim { /* DEBT(NAME): particle animation header */
    u8 pad0[6];
    s16 frames;
    u8 pad8[8];
    G4PtKey keys[1];
} G4PtAnim;

typedef struct G4PtSub { /* DEBT(NAME): sub-block at +0x10 of G4PtPlayer */
    u8 pad0[2];
    u16 h2;
    u8 pad4[4];
    int w8;
    u16 hC;
    u8 padE[6];
    u8 *p14;
    u8 b18;
} G4PtSub;

typedef struct G4PtPlayer { /* DEBT(NAME): particle player passed to func_0027F300/func_0027F3A0 */
    G4PtAnim **anim;
    G4Hb *pos;
    u8 pad8[8];
    G4PtSub sub;
} G4PtPlayer;

void func_0027F300(G4PtPlayer *p);
void func_0027F3A0(G4PtPlayer *p);

/* ---- #88 c_29B560 ---- */
extern int D_00703E28;
void op_et_encount_effect_on(int a, int b);

/* ---- #89 c_2AE200 ---- */
typedef struct G4AnimWork { /* DEBT(NAME): AnimWork view with word fields for opp_anmm_anm */
    int w0;
    int w4;
    int w8;
    int wC;
    float f10;
    float f14;
    float f18;
    int w1C;
    u8 pad20[0xC];
    int w2C;
    u8 pad30[0xC];
    int w3C;
    float f40;
    float f44;
    float f48;
    u16 h4C;
    u8 b4E;
    u8 b4F;
} G4AnimWork;

typedef struct G4AnimRes { /* DEBT(NAME): AnimRes view with table at +0x60 */
    u8 pad00[0x20];
    u8 *p20;
    u8 pad24[0x3C];
    u8 *p60[1];
} G4AnimRes;

/* ---- #91, #92 c_2D1D68 ---- */
extern s8 D_00561F10[];
extern char D_00575FF0[];
int func_002D25F0(int a, int b, int c);
int TkGetControlerBindAnalogIndex(int a, int b, int c);

/* ---- #93, #94, #95 c_2D6260 ---- */
s32 *func_002D6818(s32 a, s32 b, s32 c);
void func_002D64E0(void);
void SndSetFootSep(s32 a, s32 b, s32 c, s32 d);

/* ---- #96 c_2D9398 ---- */
extern char D_00576468[];
void FFXSetVideoMode(int a);

/* ---- #97 c_2DB640 ---- */
#define G4_DMAC_ENABLER (*(volatile u32 *)0x1000F520)
#define G4_DMAC_ENABLEW (*(volatile u32 *)0x1000F590)
int func_002DC110(volatile u32 *p);

/* ---- #98 c_2E9828 ---- */
double func_002EA450(s64 u);

/* ---- #99 c_2F8FC8 ---- */
extern u8 D_00791E40[];
typedef struct G4SifReq { /* DEBT(NAME): 16-byte stack command packet for func_002F8810 */
    int w0;
    int w4;
    int w8;
    int wC;
} G4SifReq;
int func_002F94C8(u16 a, int b, int c);

/* ---- #100 c_2FE618 ---- */
extern u8 D_0056862C[4];
extern void *D_00568E90;
int func_002EEE88(); /* DEBT(TYPE): unprototyped for K&R argument evaluation order */
int func_002FF370(void);

#endif
