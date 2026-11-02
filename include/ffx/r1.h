#ifndef FFX_R1_H
#define FFX_R1_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* ---- worker r1: chunks c_141FF0 .. c_17A110 ---- */

/* view of Actor with the packed word at +0xAC (halfword view at +0xAE) */
typedef struct ActorV {
    u8 pad0[0xAC];
    union { u32 w; struct { u16 lo; u16 hi; } h; } fAC; /* DEBT(NAME): packed attribute word, fields at bit 16 and 20 */
} ActorV;

/* thread context slot of the c_170BC4 scheduler, size 0x1310 */
typedef struct Ctx171 {
    u8 pad0[0xB0];
    u_long128 entry; /* 0 = slot free */
} Ctx171;

void func_00105320(Chr *c);
void func_00104FC0(int v);
void ChN_ReadSystemMGRP(int a, int b);
int func_00104F88(int v);

/* DEBT(TYPE): the originals pass the full int to these narrow-parameter setters (no sign/zero extension at the call),
   so the callers see them unprototyped. */
void func_00118A50();
void func_00118A60();
void func_00118A70();
void func_001163B8();
void Sg_SetMovieGomiAvoid();
void func_0011BD80();
void Sg_SetMapAlphaFast();

extern s32 D_0058E3F8;
extern u8 D_0058F918;
extern u8 D_0058F919;
void func_0010A220(Chr *c);
int func_001AC128(int v);
int Ch_CheckHandle(int v);
void Ch_Dispose(int v);

#ifdef FFX_Q2_H
/* table indices clamped to the table size */
static inline int Ent1CIdx(int i)
{
    if (i >= 0) {
        if (i >= 0x80) {
            return 0x7F;
        }
        return i;
    }
    return 0;
}

static inline int Ent24Idx(int i)
{
    if (i >= 0) {
        if (i >= 8) {
            return 7;
        }
        return i;
    }
    return 0;
}

#define ENT1C(i) (&IsAtelTextureLoaded[Ent1CIdx(i)])
#define ENT24(i) (&D_0058F7F8[Ent24Idx(i)])
void func_0014D078(Rec14CE48 *r, u8 *p);
#endif /* FFX_Q2_H */

extern u8 D_0030B9C0[];

/* DEBT(CAST)/DEBT(NAME): bit view of the flag word at +0 of the block behind D_0058E3D8 (Sys3D8.flags is a plain u32) */
typedef union SysFlagsR1 {
    u32 w;
    s32 i; /* signed view: masks like ~0x40 are then a single addiu */
    struct {
        unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 1; unsigned b3 : 1;
        unsigned b4 : 1; unsigned b5 : 1; unsigned b6 : 1; unsigned rest : 25;
    } b;
} SysFlagsR1;

struct SysR1;
typedef struct SysR1 {
    SysFlagsR1 flags;
    u8 pad4[4];
    u8 b8;
    u8 pad9;
    u16 hA;
    u8 padC[2];
    u16 hE;
    u16 h10;
    u8 pad12[2];
    u16 h14;
    u16 h16;
    u16 h18;
    u8 pad1A[0x4C - 0x1A];
    void (*f4C)(struct SysR1 *);
    void (*f50)(struct SysR1 *);
    u8 pad54[0x1F4 - 0x54];
    int w1F4;
} SysR1;
#define SYS() ((SysR1 *)D_0058E3D8) /* DEBT(CAST): see SysR1 */

/* DEBT(CAST)/DEBT(NAME): Actor overlay with the flag word at +0x34 as bits */
typedef union ActorWordR1 {
    u32 w;
    struct {
        unsigned b0 : 5; unsigned b5 : 1; unsigned b6 : 3; unsigned b9 : 1;
        unsigned b10 : 9; unsigned b19 : 1; unsigned b20 : 9; unsigned f29 : 2; unsigned b31 : 1;
    } b;
} ActorWordR1;

/* 16-byte effect slot at Actor+0xB18 (DEBT(NAME): guessed from its users) */
typedef struct ActorEntR1 {
    u16 h0;
    u16 h2;
    float f4;
    float f8;
    float fC;
} ActorEntR1;

typedef struct ActorR1 {
    u8 pad0[0x2E];
    u16 id;
    u8 pad30[3];
    u8 b33;
    ActorWordR1 w34;
    int w38;
    u8 pad3C[4];
    int w40;
    u8 pad44[0x9C - 0x44];
    Chr *ptr9C;
    int wA0;
    int wA4;
    u16 hA8;
    u8 stateAA;
    u8 padAB[0xAF4 - 0xAB];
    Chr *arrAF4[4];
    u16 hB04[2];
    u8 padB08[0xB14 - 0xB08];
    u16 hB14;
    u8 padB16[2];
    ActorEntR1 ent[4];
} ActorR1;
#define AR(a) ((ActorR1 *)(a)) /* DEBT(CAST): see ActorR1 */

void pppFpSetStickChr(int v, Chr *c, int b);
void pppFpSetStickPos(int v, float *vec);
void func_00102288(Chr *c, int v);
void func_00138C08(void);
void func_00265F18(void);
extern char D_0056AD50[];
extern s32 D_0058E42C;

/* DEBT(CAST)/DEBT(NAME): record returned by func_00124828, byte buffer of 0x1000 at +0x1EC */
typedef struct Rec124828Buf { u8 pad0[0x1EC]; u8 buf[0x1000]; } Rec124828Buf;

/* DEBT(CAST)/DEBT(NAME): resource returned by AtelGetCtrlWork, members at 0 and 0x1F4 */
typedef struct Res588R1 { int w0; u8 pad4[0x1F0]; int w1F4; } Res588R1;

/* DEBT(CAST)/DEBT(NAME): record returned by AtelGetBasicWork as func_001458B0 initialises it */
typedef struct ActorH1 { char *p0; int w4; int w8; int wC[8]; } ActorH1;

extern int D_0058E3E0;
void func_0013A940();
void AtelUpdateWindowStatus(void);
void func_0014E800(void);
void func_0013AC00(int id);

int func_00171680(int a, int b, int c, int d);

extern s32 D_0058F924;
extern s32 D_0058F928;
extern s32 D_0058F92C;

/* DEBT(NAME): script I/O work fields inferred from func_0015FC20. */
typedef struct ScriptIoWork {
    u8 pad0[0xF7120];
    int source;
    u8 pad24[0x14];
    int handle;
    u8 pad3C[0x24];
    int buffer;
} ScriptIoWork;

/* DEBT(NAME): allocation flag at +0x24 controls whether the slot context is freed. */
typedef struct SlotTaskContext { u8 pad0[0x24]; int owned; } SlotTaskContext;
extern SlotTaskContext *D_00597E38[8];

#endif
