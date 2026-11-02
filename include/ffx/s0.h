#ifndef FFX_S0_H
#define FFX_S0_H

#include "common.h"

/* c_1008D8: 8-byte rodata strings (resource-name suffixes: "skl", ...) */
extern char D_00568F60[];
extern char D_00568F68[];
extern char D_00568F70[];
extern char D_00568F78[];
extern char D_00568F80[];
extern char D_00568F88[];
extern char D_00568F90[];

/* DEBT(NAME): view of an opcode record used by func_00132CB8 */
typedef struct OpMove {
    s32 w0;
    s32 w4;
    u8 pad08[3];
    u8 kind;
    s8 mode;
    u8 pad0D[2];
    u8 b0F;
} OpMove;

/* Animation/command-stream interpreter state embedded in Chr at +0x718
 * (overlaps Chr.w720 = pc, Chr.h734, Chr.b743 in types.h). DEBT(CAST): viewed through CHR_VM. */
typedef struct ChrVmRec { /* 16 bytes */
    u8 pad00[8];
    s16 *tab;
    void *arg;
} ChrVmRec;

typedef struct ChrVmRes {
    u8 pad00[0x10];
    ChrVmRec *recs;
} ChrVmRes;

typedef struct ChrVmHdr {
    u8 pad00[8];
    s16 *ofs;
    s8 *base;
} ChrVmHdr;

typedef struct ChrVm {
    ChrVmHdr *hdr;
    ChrVmRes *res;
    s8 *pc;
    u8 pad0C[0x10];
    s16 h1C;
    s16 h1E;
    u8 pad20[0xB];
    s8 b2B;
    u8 pad2C[6];
    u8 b32;
} ChrVm;
#define CHR_VM(c) ((ChrVm *)((u8 *)(c) + 0x718)) /* DEBT(CAST) */

s32 func_00112A70(Chr *chr, void *arg, s32 id, s32 x, s32 y);

/* c_126830 */
extern char D_0056A420[];
u32 func_00138638(void);
void func_00138648(int id); /* v0: was u16; the asm compares and divides it signed */
int Ch_DataReadSync(int chr);
int func_002EF240(const char *fmt, ...);
void MsBindOffCamera(Actor *a);

/* c_1402F8 */
int func_0013F288(Actor *a, void *op, Actor *t);
void func_0013F1D8(Actor *a, void *op);
int func_0013FB40(Actor *a, void *op, Actor *t);
int func_0013F6D8(Actor *a, void *op);
void func_0013DB38(Actor *a, void *op);
void func_0013E150(Actor *a, void *op);
void func_0013EC80(Actor *a, void *op);
void func_0013E9B8(Actor *a, void *op);
void func_001402F8(Actor *a, void *op);
int func_00140038(Actor *a, void *op, Actor *t);

/* DEBT(NAME): result block written by the 0x1406F0/0x140878 opcode handlers */
typedef struct OpVec3 {
    u8 pad00[0x1F];
    u8 b1F;
    u8 pad20[0xC];
    s16 v[3];
} OpVec3;

extern char D_00569C80[]; /* "src/main/mem.c" */

/* c_11D178: 16-byte display-list command written at D_00580928[D_00580920++]: 64-bit tag whose upper word
 * is then overwritten with an argument, followed by a 64-bit command id. DEBT(CAST): Cmd16 is {s64 a, b}. */
typedef struct GsCmd {
    union {
        u64 d;
        struct { u32 lo; s32 w4; } w;
    } q;
    union {
        s64 d;
        s32 w[2];
    } b;
} GsCmd;

/* c_117E18: 16-byte screen-effect slot of D_005803D8[5] (fades / ramps). DEBT(NAME): guessed names */
typedef struct FxSlot {
    u8 kind;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    u8 pad0C[4];
} FxSlot;
extern Cmd16 D_0057F7D0[];
void Sg_GsStart(void);
void Sg_GsEnd(void);
void func_0011DF70(int a, int b, int c, int d, int e, int f, int g, int h);
void func_0011E040(int a, int b, int c, int d, int e);
void graphicAddScreenFadeTask(FxSlot *s, int v);
void func_001181B8(int v);
void func_00118A80(int v);
void func_00118308(int v);
void func_00118470(void);

/* c_103C28: 100 records of 0x14 bytes; func_00104718 chains records with equal h4 into lists. DEBT(NAME) */
typedef struct HdlRec {
    struct RelObj *w0;
    s16 h4;
    s16 h6;
    struct HdlRec *next;
    struct HdlRec *link;
    s32 w10;
} HdlRec;
/* c_103C28: relocatable record sets; wC/w10 are addresses of 16-byte entries (stored as ints, rebased by func_00104528) */
typedef struct RelEnt { u8 pad00[8]; s32 w8; s32 wC; } RelEnt;
typedef struct RelObj { s32 w0; u16 h4; u16 h6; u16 h8; u16 hA; s32 wC; s32 w10; } RelObj;
typedef struct RelTop { struct RelTop *self; s32 count; s32 w8; RelObj *objs; } RelTop;
extern HdlRec D_0057DAD8[100];
extern char D_005693F0[], D_00569400[], D_00569410[], D_00569420[];
void func_00104838(RelObj *src, s32 arg);
void func_00104528(RelObj *o, s32 d);
void func_001049F8(int top);
void func_001048D8(RelObj *src);
s32 func_00104948(int a, int b, int c);
void func_001049A0(s32 w);
extern HdlRec *D_0057E2A8;
void func_00104718(void);

/* c_103C28: save-block helpers (DEBT(TYPE): argument meanings guessed from register use) */
void func_002DA928(void *ctx, int a, int b, int c, int d, int e, int f, int g);
void func_002DAB10(void *ctx, int a, int b, int c, int d, int e, int f, int g);
void func_002DADD0(void *ctx, int dst);
void func_00104248(int idx, char *str);
void func_00104358(void);
void Sg_LoadVramResource(void);

/* c_103C28: parsed view of a packed resource block (header at D_0057D688) */
typedef struct ResParse {
    s32 flags;
    u8 *p4;
    u8 *p8;
    u8 *pC;
    u8 *p10;
} ResParse;
ResParse *func_00103C88(ResParse *out);
void func_002EA328(s32 status) __attribute__((noreturn)); /* never returns: the error exit */

/* c_111500 */
extern Handle *D_0057F450[]; /* DEBT(TYPE): second pointer table of handles, sorted by func_00111798 */
extern char D_00569658[], D_005696C8[], D_005696F0[], D_005696F8[], D_00569700[];
char *ch_create_name(int v);
void func_00111798(int n, int desc);

/* c_11D178: command writers (DEBT(NAME): argument names guessed) */
typedef struct GsPt {
    union {
        struct {
            s16 x;
            s16 y;
            s32 z;
        } v;
        s64 raw;
    } q;
    union {
        s64 d;
        s32 w[2];
    } id;
} GsPt;
void Sg_GsXYOFFSET2(int x, int y);
void Sg_GsXYOFFSET(int x, int y);
void Sg_GsSCISSOR2(int a, int b, int c, int d);
void Sg_GsSCISSOR(int a, int b, int c, int d);
void Sg_GsXYZF2(int x, int y);

/* c_11C0B0: heap block helpers (DEBT(TYPE): prototypes inferred from the asm) */
void func_002EEFCC(void *dst, void *src, int n);
void func_0011C838(R0Blk *blk);
void *func_0011CC78(void *mem);
R0Blk *func_0011C8B8(R0Blk *blk);
void *func_0011CD30(void *a, void *b);
extern char D_00569C30[], D_00569C50[];
void func_0011BA60(void *p);
void func_0011C140(R0Blk *blk, char *msg, int c);

/* c_101B70: character pool setup */
typedef struct ChrSrc { u16 h00; u8 pad02[2]; ChrHdr *hdr; } ChrSrc; /* DEBT(NAME): only the fields func_00102AF8 reads */
ChrSlotData *func_00100178(int i, int a, int b);
extern u8 D_00569338[];
void func_00102AF8(Chr *chr, ChrSrc *src);
void Ch_Allocate_InitAll(int n);
void ChN_DisposeSystemMGRP(int, int);
int Sg_CacheDisposeChr(int);
int ch_create_chrname(int id);
extern char D_005692A0[], D_005692B8[];
int ChN_DataDispose(int id, int quiet);

/* c_102B98 */
void func_2026AC0(void);
void Sg_InitFilter(void);
void func_0011EA98(void);
void func_00112F08(int v);
void func_00117608(void);
void Sg_InitAll(void);

/* c_10D380 */
s32 func_0010DE98(s32 a);

#endif
