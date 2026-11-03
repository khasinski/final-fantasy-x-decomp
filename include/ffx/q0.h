#ifndef FFX_Q0_H
#define FFX_Q0_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

#include "ffx/w0.h"

/* Callees of q0 wrappers not yet declared in funcs.h. DEBT(TYPE): argument counts/types guessed from the callee's register use. */
void func_00110F48(void);
void func_00110FA8(void);
void func_0011CA28(s32 a, s32 b);
void func_00120D18(s32 a);
void func_0011EDD8(s32 a, s32 n);
void func_0011FE00(s32 a, s32 b);
void func_00122A40(s32 a);
void AtelDrawSemiTrans(void);
void func_001258D0(s32 a);
void func_00125E20(void);
void func_0012EFA0(s32 a, s32 b, s32 c, s32 d);
void func_0012F2F8(s32 a, s32 b, s32 c, s32 d);


s32 func_00126F20(); /* DEBT(TYPE): opcode handler (Actor *, op, ScriptCtx *); some callers forward their registers */
s32 func_001296B8(Actor *a, void *op, ScriptCtx *ctx); /* v0: was (void) */
s32 func_00129738(Actor *a, void *op, ScriptCtx *ctx); /* v0: was (void) */
s32 func_0012A5D8(void);
s32 func_0012A6B0(); /* DEBT(TYPE): asm takes (Actor *, OpArgs *, ScriptCtx *); the stub callers pass their args through */
s32 func_0012F208(); /* DEBT(TYPE): defined as (Actor *, OpArgs *, ScriptCtx *) in c_12EA30; the stub callers pass their args through */
s32 func_00138520(void);
s32 func_0014A190(void);
s32 AtelPopMember(void);
s32 func_0014A330(void);
float func_001A9FB0(void);
s32 func_002023C0(void);

s32 Cache_SweepBG(s32 a);
s32 func_0010AE50(s32 a);
void func_0010AEE0(void);
void Sg_PcWrite(s32 *p, s32 a1, s32 a2);
extern s32 (*D_0078E4A0)(void);
extern s32 D_005804F0;
extern s32 D_00307F2C;
extern s32 D_00580910;
extern u8 D_00580449;
extern u8 D_0058044A;
extern u8 D_0058044B;
extern u8 D_0058044C;
extern s32 D_00580460;
extern float D_00580464;
extern float D_00580468;
extern s32 D_00580838;

/* DEBT(NAME): header word block in front of an allocation (pointer - 0x10) */
typedef struct { s32 w0, w4, w8, wC; } AllocHdr;
typedef struct { s32 w0; void *w4; s32 w8, wC; } Quad4; /* DEBT(NAME): 16-byte table record */
#define CHR_PTR(c, off, T) (*(T **)((u8 *)(c) + (off)))
s32 func_00207A80(s32 v);
s32 func_002D4888(float v);
s32 func_002D48F8(float v);
s32 func_002D4968(s32 v);
s32 func_002D49A8(s32 v);
s32 func_002E8370(float v);
typedef struct { s32 w0, w4; } Pair32; /* DEBT(NAME) */
Pair32 *func_00126C20(Actor *a, void *op, ScriptCtx *ctx); /* v0: was (void) */
Chr *func_00102B98(s32 id);
void Ch_ClothReset2(void *a);
void Sg_FilterAdd(int a, int b, int c, int d);
char *func_0011BAB8(AllocHdr *p);
s32 func_0011C6E0(s32 a, s32 b, s32 c, s32 d);
void *func_0011D420(s32 a, s32 b, u8 *c, s32 d);
s32 func_001250E8(s32 a, s32 b);
extern s32 (*D_0078E518)(s32 a, s32 b);
extern u8 D_00580408;
extern s32 D_00580918;
extern s32 D_0058091C;
extern s32 D_005808D4;
extern s32 D_0030893C;
extern u8 D_00569D40[];
extern s32 D_00580B08;
extern u8 D_00580B98[];
extern s32 D_0030890C;
#define PARAM_F32(p, off) (*(float *)((u8 *)(p) + (off))) /* DEBT(CAST) */
void func_00124CC8(s32 a, s32 b);
void Sg_SetFocus(s32 a, s32 b);
s32 Ch_MemMove(void);
void Ch_DisposeAll(void);
void func_00101DA8(void);
void Ch_DisposeAllMGRP(void);
s32 func_00110E38(s32 a, s32 b, s32 c); /* v0: returns -1/0/1 */
void func_002F8270(s32 tid, s32 prio);
typedef struct {
    s32 w0;
    s32 w4;
    u8 pad08[0xC];
    s32 w14;
    u8 pad18[0x50];
    s32 w68;
    s32 w6C;
    s32 w70;
    u8 pad74[0x8C];
    s32 w100;
    u8 pad104[0x4];
    s32 w108;
    s32 w10C;
    u8 pad110[0xC];
    s32 w11C;
    u8 pad120[0x4];
    s32 w124;
    u8 pad128[0x4];
} Rec12C; /* DEBT(NAME): 0x12C-byte record, only the fields Ch_BlkDispose touches are named */
extern Rec12C chrblk[];
Rec12C *Ch_BlkGetHandleFast(s32 id);
extern s32 D_00580E4C;
extern u8 D_005803D8[];
extern s32 D_00580428;
extern s8 D_0058044D;
extern s32 D_00580454;
extern s32 D_00580440;
extern u16 D_00308940[];
void func_0014CAB8(s32 v);
void func_00124528(int i);
void func_002D85E0(s32 v);
void func_0014B0B0(Actor *a, s32 v);
void SndStandbyStream(s32 v);
typedef struct { u8 b0, b1, b2, b3; u16 h4, h6; } Cmd8; /* DEBT(NAME): 8-byte command record */
extern Cmd8 D_005803F8;
typedef struct { u8 b[0x40]; } Rec64; /* DEBT(NAME) */
extern Rec64 D_00580C58[];
extern Rec64 D_00580D18[];
extern s32 D_00580E70;
#define ACTOR_H(a, off) (*(s16 *)((u8 *)(a) + (off))) /* DEBT(CAST) */
s32 func_0014D990(void);
s32 func_0014D980(void);
void SndStartStream2(s32 a, s32 b);
void func_00104358(void);
extern s32 D_0057DA90;
extern s32 D_0057DA94;
extern float D_0058046C;
extern float D_00580470;
typedef struct { u32 *arr; u32 count; } OfsList; /* DEBT(NAME): relocation list */
s32 AtelCheckEventEffectStart(s32 id);
void *AtelGetSnd3dWork(s32 id);
void func_00136428(void *p, s32 v);
void func_0020A7B8(void);
void AtelEventRemove(void);
void func_0011C328(s32 a, void *b, s32 c);
extern u8 D_0056A080[];
void TOSetAlbhedFlg(u32 v);
extern s8 D_0057F681;
/* DEBT(NAME): record with a backup copy of its first 0xE bytes at +0xC0 (func_00124550 saves, func_001245A8/C0 restore) */
typedef struct {
    u16 h00, h02, h04, h06, h08, h0A;
    u8 b0C, b0D;
    u8 pad0E[0x1D];
    u8 b2B;
    u8 pad2C[0x94];
    u16 hC0, hC2, hC4, hC6, hC8, hCA, hCC;
    union { u16 h; u8 b; } vCE;
} RecBackup;
void func_00116280(s32 a, float v);
void func_0013B3F8(Actor *a, s32 slot, float v);
s32 func_001253A0(s32 a, s32 b, s32 c);
extern s32 D_00308938;
void func_0014AD28(s32 v);
#define ACTOR_W(a, off) (*(u32 *)((u8 *)(a) + (off))) /* DEBT(CAST) */
typedef struct { s64 q[8]; } Blk64; /* DEBT(NAME): 0x40-byte block copied with ld/sd */
void func_001103B0(Chr *chr, float v, s32 frames);
s32 AtelGetElemId(s32 a, s32 v);
s32 func_001300A0(Actor *a, void *op, ScriptCtx *ctx);
s32 func_001300D8(Actor *a, void *op, ScriptCtx *ctx);
s32 func_00130170(Actor *a, void *op, ScriptCtx *ctx);
s32 func_001301A8(Actor *a, void *op, ScriptCtx *ctx);
s32 MsCameraGet(s32 a, s32 b, s32 c);
void MsCameraSetRect(s32 h, s32 i, float *v);
extern float D_00307EC0[];
void func_0011C348(s32 a);
u32 yiGetDrawMask(void);
void yiSetDrawMask(u32 mask);
void func_0011BB08(void *h, u8 *s, s32 v);
void *Sg_MemGet(s32 a, s32 b, s32 c, s32 d, void *buf);
extern u8 D_00568F00[];
extern u8 D_00569320[];
#define OFF_W(p, off) (*(u32 *)((u8 *)(p) + (off))) /* DEBT(CAST) */
/* DEBT(NAME)/DEBT(CAST): Handle viewed with its state bitfield (low 3 bits of w8, byte-sized container) */
typedef struct {
    s32 w0;
    s8 b4;
    u8 b5;
    s8 b6;
    s8 b7;
    unsigned char st : 3;
    unsigned char rest : 5;
    u8 pad9[3];
    s32 wC;
} HandleB;
void func_0014C8D8(s32 a, s32 b);
void func_0014C9B0(s32 a, s32 b);
void func_0014CA78(s32 a, s32 b);
void func_002D85E8(s32 a, s32 b);
void Ch_BlkDispose(Rec12C *r);
void AtelDrawNoTrans(void);
void func_00125028(void);
extern s32 D_00580E00;
extern s32 D_005808C0;
extern s32 D_0057EAF0;
extern s32 D_0057EAF4;
extern s32 dmaGif;
extern s32 D_00580E00;
extern s32 D_00580E04;
typedef int Quad __attribute__((mode(TI))); /* DEBT(TYPE): 128-bit value (lq/sq) */
extern Quad D_00580DF0;
extern s32 D_005808B8;
extern s32 D_00308914;
extern s32 D_00580430[];
extern u8 D_00580821;
extern s32 D_00580B18;
extern s32 D_00580B1C;
extern s32 D_00580B20;
extern s32 D_00580B38[];
extern u8 D_00308908;
extern float D_0057F634;
extern float D_0057F638;
extern float D_0057F63C;
extern s32 D_0057EB8C;
void func_00125268(s32 a, s32 b, s32 *c);
void func_002EA328(s32 a);
void tex_anim_no_set(s32 a);
void tex_anim_timer(s32 a);

/* DEBT(CAST)/DEBT(NAME): the 0x30-byte ChrEnt record with the members touched by q0 accessors */
typedef struct {
    u8 pad00[0x4];
    s32 w4;
    s32 w8;
    u8 pad0C[0x8];
    float f14;
    s8 b18;
    u8 pad19[0x17];
} ChrEntX;
#define CHR_ENT(c, i) (((ChrEntX *)(c)->ents)[i])

/* DEBT(CAST): Chr members not yet in the struct, accessed by byte offset */
#define CHR_F32(c, off) (*(float *)((u8 *)(c) + (off)))
#define CHR_S32(c, off) (*(s32 *)((u8 *)(c) + (off)))

/* Data used by the newly recovered script/debug helpers. */
extern s8 D_00308918;
extern char D_00569480[];
extern char D_00569770[];
extern char D_00569788[];
extern char D_0056A158[];
extern char D_0056A160[];
extern char D_0056A168[];
extern char D_0056A170[];
extern char D_0056A198[];
extern char D_0056A1A8[];
extern char D_0056A1B8[];
extern char D_0056A1C8[];
extern char D_0056A2B0[];
extern char D_0056A2C0[];
extern char D_0056A2D0[];
extern char D_0056A2E0[];
extern char D_0056A2F0[];
extern char D_0056A300[];
extern char D_0056A310[];
extern char D_0056A318[];
extern char D_00580C98[0x40];
extern char D_00580CD8[0x40];
extern char D_00580D58[0x40];
extern char D_00580D98[0x40];

extern char D_0056A088[];
extern char D_0056A098[];
extern char D_0056A0B0[];
extern char D_0056A0C0[];

/* Format strings used by the debug memory dump writer. */
extern char D_00569DF0[], D_00569DF8[], D_00569E00[], D_00569E10[];

/* DEBT(TYPE): legacy opcode shim forwards the argument registers without a typed argument list. */
#define CALL0_func_00126F20() ((s32 (*)())func_00126F20)()

void Ch_TextureReMapping(Chr *chr);
extern char D_005699E8[], D_005699F0[];

extern s32 D_003038F8;
extern s32 D_005808B0;

void func_00123878(s32 a, s32 b);
/* DEBT(TYPE): this caller used the legacy implicit-int helper view; result unused. */
#define CALL_func_00123878_INT ((int (*)(s32, s32))func_00123878)

void func_00112100(Chr *chr, int mode);

#endif
