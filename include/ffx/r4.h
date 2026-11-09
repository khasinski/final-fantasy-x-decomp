#ifndef FFX_R4_H
#define FFX_R4_H

/* Declarations for the 0x1EE1C8-0x21E178 chunks (r4). */

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"
#include "ffx/q5.h"

/* DEBT(NAME): record layouts and names below are guessed from use. */
typedef struct R4Rec16 {
    s32 w0;
    s32 w4;
    s32 w8;
    s16 hC;
    s16 hE;
} R4Rec16;

/* menu task object with handler slots at 0x7C..0x90. DEBT(NAME): guessed from use */
typedef struct R4Task {
    u8 pad00;
    u8 b01;
    u8 pad02[4];
    s16 h6;
    s16 h8;
    u8 pad0A[2];
    u16 hC;
    u8 pad0E[0x20 - 0xE];
    u16 *w20; /* from TOGetSaveWindow */
    u8 pad24[0x42 - 0x24];
    s16 h42;
    u8 pad44[0x7C - 0x44];
    int (*f7C)();
    int (*f80)(void);
    int (*f84)();
    int (*f88)(void);
    int (*f8C)(void);
    int (*f90)(void);
} R4Task;

/* Animation track (0x14 bytes, c_20F850): w0 is the track id (bit31 active, bit30 ...), h8/hA the
   current/previous command offset (in u16 units), h4 the frames left, h6 the frame count of the step. */
typedef struct R4Anim {
    s32 w0;
    u16 h4;
    s16 h6;
    u16 h8;
    u16 hA;
    s16 hC; /* track index of a jump target, -1 when not looked up */
    u16 hE; /* loop start */
    s16 h10; /* loop counter */
    u8 pad12[2];
} R4Anim; /* DEBT(NAME) */

typedef struct R4Pmode {
    u64 en1 : 1;
    u64 en2 : 1;
    u64 crtmd : 3;
    u64 mmod : 1;
    u64 amod : 1;
    u64 slbg : 1;
    u64 alp : 8;
    u64 pad : 48;
} R4Pmode;

#define GS_PMODE (*(volatile u64 *)0x12000000)

typedef struct R4Obj {
    s32 w[0x20]; /* DEBT(NAME): 0x206EB0 indexes it as w[i - 19] */
} R4Obj;

typedef struct R4Vt { /* view of the SysVt of GetCD */
    int (*f0)();
    u8 pad04[4];
    int (*fn8)(int);
    u8 pad0C[4];
    int (*f10)();
    int (*f14)();
} R4Vt;

typedef struct R4Quad {
    s16 x[4];
    s16 y[4];
    u8 r[4]; /* per-corner colour */
    u8 g[4];
    u8 b[4];
    u8 a[4];
} R4Quad;

typedef struct R4Pair {
    s16 on;
    s16 val;
} R4Pair;

extern s8 *D_003173E0;
extern s32 D_00319320;
extern R4Rec16 D_0066B530[];
extern R4Rec16 D_00692458[];
extern TblEntry *D_00690268[];
extern R4Obj *D_0066AF00[];
extern SysVt *D_0068F420;
extern u32 *D_006632B0;

s8 func_001EE238(void);
float func_001EED50(void);
s32 func_0020B880(int i);
s32 TOGetFontWidthTblAdrs(int i);
void func_0020E388(u8 *s, s16 x, s16 y, int a);
void func_0020E370(u8 *s, s16 x, s16 y);
void func_00217180(int i);
void TOBtlCloseSimpleHelpMes(void);
void TOBtlCloseSignWindow(void);
s32 func_00206ED8(int i);
s32 func_00206EB0(int a, int b);
void func_00207AA0(int id);
s32 func_002080D8(int a);
int func_0020CDB8(void);
void func_001EFAD0(s16 a, s16 b);
void func_001EF910(void);
void func_001F25D8(R4Quad *q, int x, int y, int w, int h);
void func_001F2608(R4Quad *q, int x0, int y0, int x1, int y1);
/* display-list builders: first argument is the write cursor (InvokedFromSelectCursor), returned advanced */
void *TOAddPktBaseMesFontLClutTypeRGBA(void *list, int a, void *b, int c, int d, int e, int f, int g, int h, int i, int j);
void *func_001F46D0(void *list, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void *func_001F7920(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void *func_001F7BC8(void *list, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void *func_001F7898(void *list, int a, int b, int c);
void *func_001F78C8(void *list, void *a, int b, int c, int d);
void *func_001F78F8(void *list, int a, int b, int c, int d, int e);
void *func_001F7B38(void *list, int a, int b, int c, int d);

extern s8 D_00668FEA;
extern char D_00570A70[];

void *func_00201250(void *list, int a, int b, int c, int d);
void *func_00201410(void *list, int a, int b, int c, int d);
void *func_00201210(void *list, int a, int b, int c);
void *func_00201230(void *list, int a, int b, int c);
void *func_001F7B68(void *list, int a, int b, int c, int d, int e);
void *func_001F7B98(void *list, int a, int b, int c, int d, int e, int f);
void *func_001F4350(void *list, int a, void *b, int c, int d, int e, int f, int g, int h, int i);
void *func_001F4388(void *list, int a, void *b, int c, int d, int e, int f, int g, int h, int i);
int func_00203108(MenuCmd *m);
int func_00205DB8(int a);
void TODapsString(char *s);
void func_0021A7C0(float f);

float func_00201BE0(int a, int b);
void func_00205A10(int i, int x, int y, int w, int h);
void func_002096F0(int i, int x, int y, int w, int h);
int TOGetInternationalBaseDicType(void);
void TOSetEnvMovieMessage(void);
u16 *func_0020FA18(u16 *pc, R4Anim *a, u8 *root, int pos, s32 *ofs, int flag);
void func_00210358(R4Task *o);
int func_002130C0(R4Task *o);
void func_00216FA0(int i);
void func_001F3028(u8 *s, int b, int c);
int func_00207EE0(int a);

int func_00212EB0(void);
int func_002109C0(void *o);

extern int D_006672D0;

/* The display-list cursor InvokedFromSelectCursor is advanced one 16-byte quadword at a time; packet words are stored through the
 * Qword union (types.h), so GIF_CUR() is the quadword the next store goes to. */
#define GIF_CUR() ((Qword *)InvokedFromSelectCursor)
#define GIF_NEXT() (InvokedFromSelectCursor = GIF_CUR() + 1)

/* one GIF A+D entry: register data, register address. Plain braces on purpose: a do { } while (0) wrapper changes the
 * instruction scheduling of the functions that use it. */
#define GIF_AD(data, reg) \
    { \
        GIF_CUR()->ul64[0] = (data); \
        GIF_CUR()->ul64[1] = (reg); \
        GIF_NEXT(); \
    }

/* GIF tag for NLOOP entries, EOP set, packed A+D */
#define GIF_AD_TAG(nloop) \
    { \
        GIF_CUR()->ul64[0] = 0x1000000000008000UL | (nloop); \
        GIF_CUR()->ul64[1] = 0xE; \
        GIF_NEXT(); \
    }

/* GS register values (same shape as the SCE_GS_SET_xxx macros) */
#define GS_SET_SCISSOR(x0, x1, y0, y1) ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GS_SET_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) \
    ((u64)(sbp) | ((u64)(sbw) << 16) | ((u64)(spsm) << 24) | ((u64)(dbp) << 32) | ((u64)(dbw) << 48) | ((u64)(dpsm) << 56))
#define GS_SET_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))

u8 *TOSkipCode(u8 *s);
int TOGetGroup(u8 c);
int func_001EF940(void);
void func_0020E5B0(int a, int b, int c);
TblEntry *func_0020EE38(int a, int idx);
TblEntry *TkMenuIsTermScene(int a, int idx);
u16 *func_0020F9D8(u16 *pc, R4Anim *a, int op, int flag);
int func_001EED60(void);
void *func_001F4178(void *list, void *a, int b, int c);
void func_001F5538(int a, int b, int c, int d);
void func_001F5580(int a, int b, int c, int d);
int TOControlWindow(int i);
extern u8 D_00324978[];

void *TOAddPktMenuIconRGBA(void *list, int a, int b, int c, int d, int e, int f, int g);
void *func_001F4260(void *list, void *a, int b, int c, int d, int e, int f, int g, int h);
void *func_001F5918(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F5790(int a, int b, int c);
void *func_001F5FF0(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void TOMkpEasyStrFontM(int a, int b, int c);
void *TOAdpFontM_ASCII(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F60B0(int a, int b, int c);
void *func_001F6628(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F64A0(int a, int b, int c);
void *func_001F6B18(void *list, int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F6990(int a, int b, int c);
void func_001FE240(int a, int b, int c, int d, int e);
void func_001F57E8(int a, int b, int c, int d);
void func_001F5848(int a, int b, int c, int d, int e);
void func_001F5D08(int a, int b, int c, int d);
void func_001F5D68(int a, int b, int c, int d, int e);
void func_001F64F8(int a, int b, int c, int d);
void func_001F6558(int a, int b, int c, int d, int e);
void func_001F69E8(int a, int b, int c, int d);
void func_001F6A48(int a, int b, int c, int d, int e);
void func_001FE298(int a, int b, int c, int d, int e, int f, int g);
void func_001F38A0(void *a, int b, int c, int d, int e, int f, int g, int h);
void func_001F58A8(int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F5DC8(int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F65B8(int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F6AA8(int a, int b, int c, int d, int e, int f, int g, int h);
void func_001F3A00(int a, void *b, int c, int d, int e, int f, int g, int h, int i);

extern u32 D_0066B584;
int func_001AF320(void);

#endif

int func_001CF458(int a, int b, int c, int d);
int func_001D1FA8(int a, int b, int c);
int func_001CFA38(int id, int v);
int MsCheckStartEffect(int id, int v);
extern char D_0056FE48[];
int func_002EF240(char *fmt, ...);
float MsGetChrCamWidth(int id);
extern const MenuFn D_00323710[][6];
extern u8 D_006926D8[];
void func_0020DD38(void);
void TOSeqInitParam(void);
int TOControlMessage(int i);

/* Work object of the 0x2151F8 task callbacks. DEBT(NAME): guessed from use */
typedef struct R4Wk {
    u8 pad00[8];
    s16 h8;
    u8 pad0A[0x20 - 0x0A];
    u16 *list;
    s32 w24;
    s16 h28;
    u8 pad2A[2];
    u16 ops[8];
    s16 h3C;
    u8 pad3E[0x62 - 0x3E];
    s16 h62;
    s16 h64;
    s16 h66;
    u8 pad68[0x78 - 0x68];
    void (*f78)(void);
    u8 pad7C[0xA0 - 0x7C];
    s32 wA0;
    u8 *txt[1];
} R4Wk;
u16 *TOGetSaveWindow(int a, int b, s32 *out);
void func_0020DC20(int a);

/* No stdarg.h with this compiler: the register save area of a0..t3 ends where the stack arguments begin, so the
   first variadic argument lives 7 slots below __builtin_next_arg(). */
#define R4_VA_START(ap, last) ((ap) = (char *)__builtin_next_arg(last) - 56)
int func_002F46B0(char *buf, char *fmt, char *ap);

int TOSeqGetSceneStatus(int i, const char *name);
int func_0020DCC0(int i, int name);

/* Same packet writers on an explicit list pointer (builders that take and return the cursor). */
#define GIFP_AD(p, data, reg) \
    { \
        (p)->ul64[0] = (data); \
        (p)->ul64[1] = (reg); \
        (p)++; \
    }
#define GIFP_AD_TAG(p, nloop) GIFP_AD(p, 0x1000000000008000UL | (nloop), 0xE)
extern char D_0056FF90[];
void *func_001F59F0(void *list, u8 *s, int x, int y, int a, int b, int c, int d, int e);
void *func_001F66E8(void *list, int a, int b, int c, int d, int e, int f, int g, int h);

void func_00219DA0(int v);
void TOBtlDrawChangeSeqAnm0(int a, int b, int c);
void *func_001F7FC0(void *list, void *p, int a, int b, int c);
int func_0020E508(int a, void *out);
extern char D_00570090[];
typedef struct R4Rgb3 {
    s8 c[3];
} R4Rgb3; /* DEBT(NAME) */
extern R4Rgb3 D_00571140;

/* Message window object. DEBT(NAME): guessed from use */
typedef struct R4Msg {
    u8 pad00[0x0C];
    s16 hC;
    s16 hE;
    u8 pad10[0x0C];
    s16 h1C;
} R4Msg;

#define R4PT(i) (D_0068F0A8[i])
s32 TOFuncPadMessageSelect();

/* 0xCC-byte record of D_003249C0. DEBT(NAME): guessed */
typedef struct R4Rec {
    u8 pad00;
    s8 state;
    s8 b2;
    u8 pad03[0x42 - 0x03];
    s16 h42;
    u8 pad44[0x84 - 0x44];
    int (*f84)(struct R4Rec *);
    int (*f88)(struct R4Rec *);
    int (*f8C)(struct R4Rec *);
    int (*f90)(struct R4Rec *);
    u8 pad94[0x96 - 0x94];
    u16 h96;
    u8 pad98[0xC8 - 0x98];
    s32 wC8;
} R4Rec;
extern R4Rec D_003249C0[];

/* Init block toTarget (0x134 bytes). DEBT(NAME): guessed */
typedef struct R4Init {
    s16 h0;
    s16 h2;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    u8 pad14[0x84 - 0x14];
    s32 w84;
    u8 pad88[0x8C - 0x88];
    s32 w8C;
    u8 pad90[0xA8 - 0x90];
    s32 wA8;
    s16 hAC;
    u8 padAE[0xB0 - 0xAE];
    s32 wB0;
    u8 padB4[0x124 - 0xB4];
    s16 h124;
    s16 h126;
    s32 *p128;
    u16 h12C;
    s16 h12E;
    s16 h130;
    u8 pad132[0x134 - 0x132];
} R4Init;
extern R4Init toTarget;
extern s8 D_00325020;
int TOCheckBtlCommandTarget(int a, int b);
void *func_001FF020(void *list, int a, int b, int c, int d, int e, u32 f, u32 g);
void *func_00201760(void *list, int a, int b, int c, u32 d);
extern s32 D_003238BC;
extern s32 D_003238C0;
extern s32 D_003238C4;

/* Menu state object, members used by the 0x2030B0 init callbacks. DEBT(NAME): guessed from use */
typedef struct R4Menu {
    u8 pad00[0x2E];
    s16 h2E;
    u8 pad30[0x48 - 0x30];
    u8 b48;
    u8 b49;
    u8 b4A;
    u8 b4B;
    u8 pad4C[0x90 - 0x4C];
    s32 w90;
    u8 pad94[0x9C - 0x94];
    s32 w9C;
    s32 wA0;
    s32 wA4;
    u8 padA8[0xF8 - 0xA8];
    MenuFn fF8;
} R4Menu;
void TOMkpShapeXY(int a, int b, int c);
int TOGetFFXVideoMode(void);
s32 _TOInitMessageWaitNormal();

extern s32 D_003249B4;
extern s32 D_00690674;

/* Glyph metrics filled by func_0020E468. DEBT(NAME): guessed from use */
typedef struct R4CharInfo {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    s16 h10;
    s16 h12;
    u8 pad14[2];
    s16 h16;
    u8 pad18[8];
} R4CharInfo;
int func_0020E468(u8 *s, R4CharInfo *out);

typedef struct R4S4 {
    s8 c[4];
} R4S4; /* DEBT(NAME) */
extern R4S4 D_00570D08;

/* Step-table walker object. DEBT(NAME): guessed from use */
typedef struct R4Walk {
    s8 b00;
    u8 pad01[0x0B];
    s8 b0C;
    s8 b0D;
    u8 pad0E;
    s8 b0F;
    s16 h10;
    s16 h12;
    s32 (*f14)();
} R4Walk;
s32 func_00213F70();
typedef struct R4Fx {
    s32 on;
    s16 x4;
    s16 x6;
    s32 w8;
    s32 wC;
    float f10;
    float f14;
    float f18;
} R4Fx;
extern char D_00570F78[];
s32 func_00213EF8();

/* 16-byte entry of the table D_00692050 (count in D_00692450, at most 0x3F). DEBT(NAME): guessed */
typedef struct R4Ent16 {
    s16 x;
    s16 y;
    s32 w4;
    s32 w8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} R4Ent16;
extern R4Ent16 D_00692050[];
extern s16 D_00692450;
void func_00207648(int a, void *out, int c);

/* Item record read by TOAdpMenuIconWeaponName2. DEBT(NAME): guessed from use */
typedef struct R4Item {
    u16 h0;
    u8 pad02[2];
    u8 b4;
    u8 b5;
    u8 b6;
} R4Item;

int func_001CF4B0(int id, int b, int c);
int func_001CF558(int id, int b, int c);
float func_001B6AD0(int id, float a);
float MsNearRag(float a, float b);
int op_et_weapon_afterimage(void *chr, int a, int b, int c, int d, int e, int f);
int func_001B6E48(int id, float *out);
