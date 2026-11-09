#ifndef FFX_U4_H

#define FFX_U4_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"
#include "ffx/w9.h"

/* assert strings (file name / expression) passed to func_001577A8 */
extern char D_00573850[];
extern char D_00573860[];

/* initializer of a local 3-pointer table, D_00573F88 = { D_00370918, D_006A3A70, D_006A3970 } */
typedef struct PtrTab3 { void *p[3]; } PtrTab3;
extern PtrTab3 D_00573F88;

/* DEBT(NAME): script work area with floats at 0x10..0x24 (func_00270898) */
typedef struct U4Wk10 {
    u8 pad0[0x10];
    float f10;
    float f14;
    u8 pad18[4];
    float f1C;
    float f20;
    float f24;
} U4Wk10;

typedef struct Wkf0f4f8wC {
    float f0;
    float f4;
    float f8;
    int wC;
} Wkf0f4f8wC;

typedef struct WkfCw1C {
    u8 pad0[0xC];
    float fC;
    u8 pad10[0xC];
    int w1C;
} WkfCw1C;

typedef struct WkfCb10 {
    u8 pad0[0xC];
    float fC;
    s8 b10;
} WkfCb10;

typedef struct Wkf54f58f60f64 {
    u8 pad0[0x54];
    float f54;
    float f58;
    u8 pad5C[4];
    float f60;
    float f64;
} Wkf54f58f60f64;

typedef struct WkfBCfC0fC8fCC {
    u8 pad0[0xBC];
    float fBC;
    float fC0;
    u8 padC4[4];
    float fC8;
    float fCC;
} WkfBCfC0fC8fCC;

typedef struct Wkf74f78f80f84 {
    u8 pad0[0x74];
    float f74;
    float f78;
    u8 pad7C[4];
    float f80;
    float f84;
} Wkf74f78f80f84;

typedef struct Wkf0f4f8fCf10f14 {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
} Wkf0f4f8fCf10f14;

extern char D_005745E0[]; /* printf format of func_00293FD8/op_dvd_debug_print2 */

typedef struct WkM40fAC {
    u8 pad0[0x40];
    u8 m40[0x6C];
    float fAC;
} WkM40fAC;

void func_00245548(void);
void func_00245598(void);
void func_002492A0(u8 *buf);

/* GS privileged registers of read circuit 2 */
#define GS_DISPFB2  (*(volatile unsigned long *)0x12000090) /* hardware register */
#define GS_DISPLAY2 (*(volatile unsigned long *)0x120000A0) /* hardware register */

/* display environment: pmode, smode2, dispfb, display, bgcolor (sceGsDispEnv-like, 0x28 bytes) */
typedef struct U4DispEnv {
    unsigned long pmode;
    unsigned long smode2;
    unsigned long dispfb;
    unsigned long display;
    unsigned long bgcolor;
} U4DispEnv;
#define GS_PMODE    (*(volatile unsigned long *)0x12000000) /* hardware register */
#define GS_DISPFB1  (*(volatile unsigned long *)0x12000070) /* hardware register */
#define GS_DISPLAY1 (*(volatile unsigned long *)0x12000080) /* hardware register */

/* initializers of local 4-word tables (func_00265F78, func_00265FB8) */
typedef struct IntTab4 { int v[4]; } IntTab4;
extern IntTab4 D_00573AA8;
extern IntTab4 D_00573AB8;

Chr *func_00102A60(void);

double func_002E9290(double a); /* DEBT(NAME): soft-float double helper (unary) */
double func_002EBC70(double a, double b); /* DEBT(NAME): __muldf3 guess */

extern char D_005723C0[];
extern char D_005726C0[];
/* 2-byte string ("x\0") copied as an array initializer by func_0023CDB0 */
typedef struct U4Str2 { char c[2]; } U4Str2;
extern U4Str2 D_00572CB0;

extern u8 D_0069A688;
extern s16 D_003261D0[2];
void func_00227C88(int x, int y, int n);
void op_oef2_tex_clut_ovl_clear(u32 mask);

extern s16 D_00694138[2]; /* text origin x, y */
extern s16 D_00694140;    /* alternative x origin */
extern char D_00572CB8[];

int opus_get_eff_status_index(Chr *key, int a, int b);
extern char D_00574FE0[];
extern char D_00575010[];
extern Pt16 D_00325BD8[];
extern Pt16 D_00325BF0[];
extern Pt16 D_00325C20[];
extern Pt16 D_00325C38[];

int func_002982B0(Chr *key, int b);

typedef struct U4Obj14 { u8 pad0[0x14]; void (*fn14)(struct U4Obj14 *o); } U4Obj14;
extern int D_0036F204;
extern char D_00573FB0[];
extern char D_00574C88[];
typedef struct U4Id4 { u16 id; u8 pad2[2]; } U4Id4;
extern U4Id4 D_00325B18[];
extern U4Id4 D_00325B60[];
void func_00233060(int a);

/* script work area holding a 4x4 matrix at 0x10 */
typedef struct WkMtx10 {
    u8 pad0[0x10];
    float m[4][4];
} WkMtx10;

/* layout names looked up by TkMn2GetMainPos */
extern char D_00573090[], D_005730A0[], D_005730B0[], D_005730C0[], D_005730D0[], D_005730E0[];
extern s16 D_00326DA8[4];
extern s16 D_0069BE30[4];
extern s16 D_0069BE38[4];

extern int D_0069A7CC;
extern Task *D_0069A640;
extern u8 D_0069A660[2];
void func_0023ED40(void);

extern Rec124828 *D_0069A60C; /* backup copy of the save block taken before a menu edits it */

extern s16 D_00325878[2];
void func_00226D88(int x, int y, int a);
void func_00226E10(int x, int y, int a);
void func_00226350(int x, int y, int v, int a);

extern u8 D_0069BC70[]; /* GS image transfer context */
void func_00264B20(void);
void eiAbmCalc(void);

/* script object with a basis (rows at 0x10..0x40) and its world matrix at 0x50 */
typedef struct U4Xform {
    u8 pad0[0x10];
    float axis[4][4];
    float m[4][4];
} U4Xform;

/* also declared in s0.h / r0.h / q5.h (headers these chunks do not include) */
void func_002DA928(void *ctx, int a, int b, int c, int d, int e, int f, int g);
void func_002DAC50(void *dst, int n);
void *func_001F6F88(void *list, int a, int b, int c, int d);

extern s16 D_0032628C;
extern int D_0069408C;
void func_00237630(int a, int b, int c, int d, int e, int f);
/* DEBT(CAST): the callers pass two int arrays and see an int-returning declaration (v0/v1 choice after the call) */
#define FUNC_00237630(a, vals, maxs, n, b, c) \
    (((int (*)(int, int *, int *, int, int, int))func_00237630)((a), (vals), (maxs), (n), (b), (c)))
Task *func_002397D8(void);
Task *func_0023BDD0(void);
void func_002421B0(int dst, int src, int size);

/* 0x28-byte records returned by Sg_GetDBuffDC */
typedef struct U4Rec28 { u8 pad0[0x10]; int w10; u8 pad14[0x14]; } U4Rec28;

/* record of func_00228220 with an id list from offset 2 */
typedef struct U4IdList { u16 h0; u16 ids[16]; } U4IdList;

extern char D_00574D28[];
void opus_check_forced_draw(void);
void opus_map_rgba_free(void);
void func_0014D468(int v);
int func_00274BC8(void *k, int *w);
void func_00275320(void *buf);
void func_00274A30(char *m, void *k, void *buf, int a);
void func_00274D80(char *base, void *k, ScriptCtx *ctx);
void func_00274FB0(char *base, void *k, ScriptCtx *ctx);

/* script key with two wrap sizes (in 1/256 units) and a step */
typedef struct U4WrapKey {
    u8 pad0[0xC];
    int w;
    int h;
    u8 pad14[8];
    int dx;
    int dy;
} U4WrapKey;
typedef struct U4WrapPos {
    int w0;
    int x;
    int y;
} U4WrapPos;

void func_002331A8(void);
extern u16 D_0069BEA8[7][2]; /* sizes of the two halves of 7 blocks */
void func_0024B900(int base, int ofs, int size);

/* script work area that follows a vector source (func_0026DAD8) */
typedef struct U4VecSrc {
    float v[3];
    u8 padC[4];
    float *src;
} U4VecSrc;

/* flag tables picked by func_00235AA8 */
extern FlagRec *D_00325F70[];
extern FlagRec *D_00325F98[];
extern FlagRec *D_00325FB8[];
extern FlagRec *D_00325FE0[];
void func_00234A30(void);

extern struct Pt16s D_00693D88; /* list origin x, y (Pt16s, q6.h) */
void func_00231E68(int a, int x, int y, int i, int b);
void func_00232560(int a, int x, int y, int i, int b);
void func_00238440(Task *t);

typedef struct U4Obj18 { u8 pad0[0x10]; void (*fn10)(struct U4Obj18 *o); u8 pad14[4]; s8 b18; u8 b19; } U4Obj18;

extern u8 D_0069BC00[]; /* GS image transfer context */
void func_002DAB10(void *ctx, int a, int b, int c, int d, int e, int f, int g);
void func_002DADD0(void *ctx, int dst);
extern DrawArgs D_00693F30;
void func_00226FE0(DrawArgs *a);
void func_002341E8(int a);
void func_00234428(int a);
void func_00234100(int a, int b, int c);
extern float D_006A3BB0[2];

int func_00241FE0(void);
extern int D_003708C8;
extern char D_00573FF0[];

void func_002384D8(int a, int x, int y, int i, int b, int c);
void func_00238A08(int a, int x, int y, int i, int b, int c);

extern struct Pt16s D_00326110;
int func_00226018(int x, int y, int n);
void func_00237F28(Task *t, int a);
void func_002346D8(int a, int b);

void func_0014D610(int a, char *buf); /* as in q1.h */

void *func_001F7FC0(void *list, void *p, int a, int b, int c); /* as in r4.h */

void *func_001F78C8(void *list, void *a, int b, int c, int d); /* as in r4.h */

void *func_001F41C0(void *list, void *a, int b, int c, int d); /* as in q5.h */
WorkEnt2 *func_00257BE8(WorkEnt2 *p, int id, u16 *out);
void _pppAllFreePObject(Slot80 *s);

void op_fp_effect_init(void);
void op_oef2_texture_load(int *p, int a);
void op_oef2_clut_load(int *p, int a);

/* resource header with the counts of its type-2 and type-3 entries (pppSetFpTex) */
typedef struct U4ResHdr { u8 pad0[0x44]; u16 n2; u16 n3; } U4ResHdr;

void func_00235718(int a, int b, int i);


#endif
