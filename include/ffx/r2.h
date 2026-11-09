#ifndef FFX_R2_H
#define FFX_R2_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* ---- r2 area (0x17B178-0x1BA050) ---- */

typedef struct R2Cam30 { u8 pad0[0x30]; float f30; float f34; u8 pad38[8]; float f40, f44, f48, f4C; float f50, f54, f58, f5C; u8 pad60[0xC1 - 0x60]; u8 bC1; u8 padC2[2]; int wC4; } R2Cam30;
extern R2Cam30 *ms_screen_now;

/* object with a float vector at 0xC0 and a sub-object pointer at 0x14 */
typedef struct R2Obj195 { u8 pad0[0x14]; void *f14; u8 pad18[0xA8]; float fC0; } R2Obj195;

void func_0018F260(float *m, float x, float y, float z);
void func_2038588(void);

/* 0x58-byte record initialised by func_001A1780 */
typedef struct R2Rec1A17 { int f0; int f4; u8 pad8[0x18]; void *f20; u8 pad24[0x24]; void *f48; void *f4C; u8 f50[1]; } R2Rec1A17;

typedef struct R2Pair08 { int f0; int f4; int f8; } R2Pair08;
typedef struct R2Obj6C { u8 pad0[0x6C]; float f6C; } R2Obj6C;


extern u32 D_0030ECA4;
extern u32 D_0030ECA8;
extern char D_0056C928[];
extern char D_0056C940[];
void yiAssert(int a, char *file, char *fmt, ...);
extern float D_0056D3AC;
extern float D_0056D3B0;
extern float D_0065FD30;
extern int D_00313724;

/* record whose int at 0 is the key (searched by rcbgSceneAddObject) */
typedef struct R2Key { int key; } R2Key;
typedef struct R2KeyList { u8 pad0[0xC]; int count; R2Key **arr; } R2KeyList;


typedef struct Obj1A89B0 { u8 pad0[0x8C]; int w8C; } Obj1A89B0;
typedef struct Out1A89B0 { u8 pad0[0x30]; float v30[4]; float v40[4]; float v50[4]; } Out1A89B0;


/* ---- batch 6 ---- */
typedef struct R2Quad { int a, b, c, d; } R2Quad;
typedef struct R2Rec460 { u8 pad0[0x60]; R2Quad q[64]; } R2Rec460; /* DEBT(NAME): guess, from func_0018B558 */
typedef struct R2Sys460 { u8 pad0[0x10]; R2Rec460 rec[1]; } R2Sys460;
typedef struct R2Buf { void *base; void *cur; u8 pad8[8]; } R2Buf;
typedef struct R2Obj1A14 { u8 pad0[0x5C]; float f5C; u8 pad60[0xC]; int w6C; u8 pad70[0x30]; float fA0, fA4, fA8; int wAC; } R2Obj1A14;
void func_00190408(int a, float *v, int n, int b);


/* ---- batch 7 ---- */
typedef struct R2Tbl50 { u8 pad0[0x20]; struct { u8 b[0x50]; } ent[1]; } R2Tbl50;
typedef struct R2Obj1A14D0 { int f0, f4, f8; void *fC; u8 pad10[0x60]; float f70, f74, f78; u8 pad7C[0x14]; void *f90, *f94, *f98; } R2Obj1A14D0;
typedef struct R2Hdr0 { int w0; int w4; int w8; int wC; u8 pad10[8]; int w18; int w1C; } R2Hdr0;
typedef struct R2Ptr20 { u8 pad0[0x20]; void *p20; void *p24; } R2Ptr20;
typedef struct R2Mark { u8 pad0[0x3A]; s8 b3A; } R2Mark;
typedef struct R2Obj3A { void *p0; u8 pad4[0x36]; s8 b3A; } R2Obj3A;
void MsRegistSEdata(void *a, void *p);
void func_001B0940(void);
void *func_001B1C70(int a, int b, int c, int *out);


/* ---- batch 8 ---- */
extern u8 D_00313710[];
extern const u64 D_0056D948[];
extern char D_0056D3A0[];
void func_00192708(u64 *pkt);
typedef union R2Qw { struct { u64 lo, hi; } d; u_long128 q; u32 w[4]; struct { u16 qwc; u16 id; u32 addr; u64 pad; } tag; } R2Qw; /* one quadword of a DMA packet */
typedef struct R2Pkt { R2Qw *base; R2Qw *cur; } R2Pkt; /* DMA packet being built: base is the tag quadword */
typedef struct R2Sub195 { int w0; int w4; int w8; int wC; s16 h10; s16 h12; s16 h14; } R2Sub195;
typedef struct R2Obj195b { u8 pad0[0x14]; R2Sub195 *f14; } R2Obj195b;
typedef struct R2Vt { u32 id; void *fn4; void *fn8; int wC; } R2Vt;


/* ---- batch 9 ---- */
typedef struct R2Cam314870 { Unk317120Rec rec[2]; u8 padC40[0xDA0 - 0xC40]; } R2Cam314870; /* DEBT(NAME): same layout as Unk314840 at +0x30 */
extern R2Cam314870 D_00314870[];
typedef struct R2Vec4 { float x, y, z, w; } R2Vec4;
struct R2Obj1A44;
typedef struct R2Cb { u8 pad0[0x10]; void (*fn10)(struct R2Cb *, struct R2Obj1A44 *); } R2Cb;
typedef struct R2Obj1A44 { int w0; float f4; int w8; float fC; int w10; float f14; void *p18, *p1C; R2Vec4 *p20; void *p24; int w28; R2Cb **p2C; int w30; } R2Obj1A44;
typedef struct R2Obj19B1 { int w0, w4; float f8; int wC, w10; } R2Obj19B1;

extern u8 D_00661920[];


/* ---- batch 10 ---- */
char *func_00180968(u32 group, int idx);
int func_001807A8(char *name);
int func_001808C8(int a, int b, int c);
void func_00180950(int a);
void *rcbgModelNew(void);
void rcbgModelCreateFromOMD(int *p, int v);
void rcbgModelSetScale(void *p, float v);
void func_00197E10(void *o, void *t);
typedef struct R2Obj18 { u8 pad0[0x18]; void *f18; } R2Obj18;
typedef struct R2OwnerBC { u8 pad0[0xBC]; void *fBC; } R2OwnerBC;

extern s32 D_00317138[];
extern s32 D_0065FE30[];
extern u16 D_00317248[];
extern s32 D_00319464;
float MsCalcChrDir(int id, BtlChr *c);
int MsBattleReadDataNB(int i);
void func_0011BFD0(void);
void Sg_DebugFill(int a);

float func_00110288(Chr *chr);

void func_0019DE78(W3Reader *r, void *dst, int n);
void func_0019A420(W3Img *o);
void func_001A47F0(struct R2Obj1A44 *o);
void rcfxWindCalc(void *p, int a, int b, float f); /* DEBT(TYPE): argument types guessed */
void func_001B6660(BtlChr *c, float *v);
void func_001BF470(int i, int v);
void func_001BF4C0(int i, int v);
void MsGetChrBtlPos(int id, float *v);
void Ch_SetPos3(Chr *chr, float x, float y, float z);
int MsCameraIDcheck(u32 a);
void MsSetCheckChange(int a, int b, int c, int d);

void *_rcRealloc(void *p, int size, const char *file, int line);

#define R2_CALL0(f) (((int (*)(void))(f))())
int AtelGetCtrlworkActorTotal(); /* DEBT(TYPE): q1.h takes char *; this caller passes nothing */
int AtelDecodeCommand(int id, int c);
void AtelDecodeSignal(int i, int v);
int AtelGetRequestLevel(int id);
void MsMotionProcess(void);
void MsBattleSpecial(void);

void MsLimitStatusProcess(int a, BtlChr *c, int b);

void func_001AC258(float t, float *dst, float *src, int n); /* DEBT(TYPE): argument types guessed */

void Ch_BindToElem(Chr *a, Chr *b, int c);
int Ch_OptposGet(); /* DEBT(TYPE): q7.h declares (int, int, int); this caller passes (Chr *, int, float *) */

/* ---- batch 12 ---- */
typedef struct R2Cpy20 { int w0, w4, w8, wC, w10, w14; u8 pad18[8]; u64 q20; } R2Cpy20; /* DEBT(NAME): guess */
typedef struct R2Cpy38 { int w0, w4, w8, wC, w10, w14; u8 pad18[0x20]; u64 q38; } R2Cpy38; /* DEBT(NAME): guess */
typedef struct R2Cpy10 { u16 h0, h2; int w4, w8; u8 padC[4]; u8 sub[4][0x10]; } R2Cpy10; /* DEBT(NAME): guess */
typedef struct R2Big68 { u8 pad0[0x68260]; int w68260; u8 pad68264[0xC]; float m68270[16][4]; } R2Big68; /* DEBT(NAME): guess */
typedef struct R2Mat40 { u8 pad0[4]; int w4; u8 pad8[0x38]; float m40[16][4]; } R2Mat40; /* DEBT(NAME): guess */
void func_0017AB10(void *dst, void *src);
void func_0017B1F8(R2Cpy10 *d, R2Cpy10 *s);

typedef struct R2Big4000 {
    R2Quad q[0x400];
    int w4000;
    u8 pad4004[4];
    int w4008;
    u8 pad400C[0x44];
    int a4050[4];
    int a4060[4];
    u8 pad4070[4];
    int w4074, w4078, w407C, w4080, w4084, w4088;
    u8 b408C;
    u8 b408D;
} R2Big4000; /* DEBT(NAME): guess */

typedef struct R2CfgC0 {
    u8 pad0[0xC0DE4];
    int wDE4, wDE8, wDEC, wDF0, wDF4;
    float fDF8, fDFC, fE00, fE04;
    int wE08;
    u8 bE0C, bE0D, bE0E;
} R2CfgC0; /* DEBT(NAME): guess */

typedef struct R2ResEnt { u16 h0; u8 pad2[2]; u16 h4; u16 h6; u16 h8; u16 hA; u8 padC[8]; int w14; int w18; u8 pad1C[0x28 - 0x1C]; } R2ResEnt; /* DEBT(NAME): guess */
typedef struct R2ResTbl { u8 pad0[0x9F200]; u32 cnt; R2ResEnt ent[0x40]; } R2ResTbl; /* DEBT(NAME): guess */

typedef struct R2Obj1A52 {
    int w0;
    void *p4;
    int w8, wC, w10;
    void *p14;
    int w18;
    u8 pad1C[4];
    float f20, f24;
    int w28, w2C, w30, w34;
    float f38;
    int w3C;
    float f40, f44, f48, f4C, f50;
} R2Obj1A52; /* DEBT(NAME): guess */

typedef struct R2Vt2 { u32 id; void *p4; void *p8; void *pC; } R2Vt2; /* DEBT(NAME): guess, object head: id and two code pointers */
struct R2ObjA8;
void func_00198690(struct R2ObjA8 *o);
void *func_0019ACB8(void);
void rcbgFPm097Proc010(void *p);
void *rcbgFPm173New(void);
void func_0019B4F0(void *p);
void *func_0019B888(void);
void rcbgFPm565Proc010(void *p);
void *rcfxNailNew(void);
void func_001A4F20(void);

typedef struct R2Obj1A4E { u32 id; void *p4; int w8, wC; void *p10; void *p14; int w18, w1C, w20, w24, w28, w2C, w30, w34; } R2Obj1A4E; /* DEBT(NAME): guess */

extern u32 D_0030ECB8;
extern u32 D_0030ECBC;
extern u32 D_0030ECC0;
extern u32 D_0030ECC4;
extern u32 D_0030ECC8;
extern u32 D_0030ECCC;
extern u32 D_0030ECD0;
extern u32 D_0030ECD4;
extern u32 D_0030ECD8;
extern u32 D_0030ECDC;
extern u32 D_0030ECE0;
extern u32 D_0030ECE4;
extern u32 D_0030ECE8;
extern u32 D_0030ECEC;
extern u32 D_0030ECF0;
extern u32 D_0030ECF4;

extern int D_00313728;
extern int D_0031372C;
extern int D_00313730;
void func_00197C08(struct W3Sub *sub, int a);
int func_00197C70(struct W3Sub *sub);

typedef struct R2F1C { u8 pad0[0x1C]; float f1C; } R2F1C; /* DEBT(NAME): guess */
typedef struct R2ObjA8 { u32 id; void *p4; void *p8; void *pC; u32 w10; struct V2Part *p14; struct R2Obj1A44 *p18; u8 pad1C[0x34]; float v50[4]; u8 pad60[0x30]; float v90[4]; int setA0; int setA4; int wA8; float fAC; } R2ObjA8; /* DEBT(NAME): guess; 0xB0 bytes (func_00197CF8) */
void rcfxParticleAddForce(void *a, void *b);
void rcfxParticleResetForce(struct R2Obj1A44 *o);

#endif
