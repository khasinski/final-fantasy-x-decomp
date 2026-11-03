#ifndef FFX_P5_OVERLAY_H
#define FFX_P5_OVERLAY_H

/* Package p5: TU rank 1 (family F2) of docs/overlay-tus.tsv, the battle-effect character
 * command library shared by 113 containers (reference file09047, .text 0x01B04A98..0x01B07238).
 * This code is compiled with -O0 (s8 frame pointer, unfilled delay slots, every local on the
 * stack); the first parameter of every function is declared `register` (kept in s0). */

#include "common.h"

typedef struct Chr Chr;

typedef struct P5Vec {
    float x, y, z, w;
} P5Vec;

/* DEBT(NAME): object the effect script binds to a battle character (names offset-derived) */
typedef struct P5Org P5Org;

/* DEBT(NAME): message passed to the bound origin object's handler */
typedef struct P5Msg {
    P5Org *org;
    u8 b4;
    u8 b5;
} P5Msg;

typedef struct P5OrgVt {
    u8 pad00[0x1C];
    void (*f1C)(P5Msg *m);
} P5OrgVt;

struct P5Org {
    P5OrgVt *vt;
    u8 pad04[0x9C];
    u8 mtxA0[0x30];      /* 0xA0: passed to Ch_SetOrgMatrix */
    P5Vec posD0;         /* 0xD0: passed to MsSetChrPos */
};

typedef struct P5Chr {
    void *p00;           /* 0x00: set to the overlay's D_01B02650 */
    u8 pad04[0x1C];
    P5Vec pos20;         /* 0x20 */
    P5Vec pos30;         /* 0x30 */
    float scale[3];      /* 0x40: saved Ch scale */
    u8 pad4C[4];
    P5Org *org;          /* 0x50 */
    int id;              /* 0x54: battle character id (Ms* API) */
    Chr *chr;            /* 0x58 */
    int i5C;             /* 0x5C */
    u32 motion;          /* 0x60: motion frame count (func_001CE050) */
    int i64;             /* 0x64 */
    u32 gravity;         /* 0x68: saved MsSetChrGravity result, ~0 = none */
    int i6C;             /* 0x6C */
    int i70;             /* 0x70: MsEffectEndMotion value */
    float f74;           /* 0x74 */
    float f78;           /* 0x78 */
    float f7C;           /* 0x7C */
    float f80;           /* 0x80 */
    float f84;           /* 0x84 */
    float f88;           /* 0x88 */
    float f8C;           /* 0x8C */
    float f90;           /* 0x90 */
    u16 flags;           /* 0x94: bit0 = attached to a Chr model instead of the Ms character */
    u16 h96;             /* 0x96 */
    u16 h98;             /* 0x98 */
} P5Chr;

/* one script argument word */
typedef union P5Val {
    int i;
    float f;
    u8 b;
    u8 bb[4];
    u16 h;
    void *p;
    float *fp;
    int *ip;
    P5Vec *v;
    P5Org *org;
    Chr *chr;
} P5Val;

/* DEBT(NAME): argument block of a character command */
typedef struct P5Args {
    P5Chr *c;
    P5Val a[7];
} P5Args;

extern float eff_sin_t[];
extern u8 D_01B02650[]; /* overlay .data (relocated per container) */

/* resident: chr */
int Ch_SetSequence(Chr *chr, int v);
int func_001072F8(Chr *chr, int i, void *dst);
void *Ch_GetRootGlobalMatrix(Chr *chr, void *src);
int func_00107428(Chr *chr, int bone, P5Vec *in, P5Vec *out);
void Ch_CalcElement(Chr *chr);
int Ch_OptposGet(Chr *chr, int i, float *out);
void func_00108A28(Chr *chr, void *dst);
void Ch_DrawEnEffect(Chr *chr, s32 v);
void Ch_DrawSetSituation(Chr *chr, u8 v); /* DEBT(TYPE): resident decl has s8; these callers pass the byte unextended */
float Ch_GetJimen(Chr *chr);
void Ch_GetPos(Chr *chr, float *x, float *y, float *z);
float func_00110288(Chr *chr);
void func_00110300(Chr *chr, float v);
void Ch_ResetMotion(Chr *chr);
void Ch_SetShadeCol(Chr *chr, float x, float y, float z, int n);
void func_00110540(Chr *chr, float v, s32 frames);
s32 Ch_EnClip(Chr *chr, s32 v);
s32 func_00110718(Chr *chr, s32 b);
void Ch_SetScale(Chr *chr, s32 mask, float x, float y, float z);
float Ch_GetScaleX(Chr *chr);
float Ch_GetScaleY(Chr *chr);
float Ch_GetScaleZ(Chr *chr);
void func_001107D8(Chr *chr, float *x, float *y, float *z);
void Ch_SetOrgMatrix(Chr *chr, void *m);

float func_00110AF0(Chr *chr);
s8 Ch_GetWaitMotion(Chr *chr);
void Ch_ClothReset2(Chr *chr);
Chr *func_0013B0F8(int a);

/* resident: battle (Ms*) */
Chr *MsGetChrHandle(int id);
Chr *MsGetWeaponHandle(int id, int n);
s8 MsGetChrFly(int id);
float MsGetChrGround(int id);
int MsSetChrVisible(int id, int b);
int MsSetChrTransparent(int id, float f, int b);
float MsGetChrWidth(int id);
int func_001B6790(int id, P5Vec *pos);
int MsGetChrTopPos(int id, P5Vec *pos);
int MsGetChrCenterPos(int id, P5Vec *pos);
int MsGetChrScale(int id, float *out);
void MsSetChrPos(int id, P5Vec *pos);
int MsSetChrGravity(int id, int on);
int func_001B6E48(int id, float *out);
int func_001B6EF8(int id, float v);
void MsGetChrBtlPos(int id, P5Vec *v);
float MsGetChrBtlPosHeight(int id); /* DEBT(TYPE): funcs.h says int; the caller adds the f0 result */
int func_001CE050(int id, int motion);
int MsEffectCheckMotion(int v);
void MsEffectEndMotion(int id, int value);
int func_002985C0(Chr *key);
int func_002985E0(Chr *key);

/* resident: vector math */
void func_002DCFB8(P5Vec *dst, P5Vec *src, float f);
void func_002DD020(P5Vec *dst, P5Vec *a, P5Vec *b);
void func_002DD038(P5Vec *dst, P5Vec *a, P5Vec *b);
void func_002DD068(P5Vec *dst, P5Vec *v, float s);
void func_002DD0B0(P5Vec *dst, P5Vec *src);

#endif
