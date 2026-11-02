#ifndef FFX_V2_H
#define FFX_V2_H

#include "common.h"
#include "ffx/types.h"

/* ======== 0x197xxx: helper object behind W3Owner.sub ======== */
/* DEBT(NAME): member names are guesses from field usage only. */
struct W3Sub {
    int w00;
    int w04;
    int w08;
    u8 pad0C[0x60];
    float f6C;       /* saved/restored through D_0065FD30 */
};

int func_00197C90(struct W3Sub *sub);
int func_00197CB8(void);
int func_00197CC8(void);

/* ======== 0x1785xx: VIF packet builders ======== */
typedef struct V2Blk40 { u64 d[8]; } V2Blk40; /* 64-byte block copied into a packet */

/* argument of func_00178608 (DEBT(NAME): guess from use) */
typedef struct V2Cmd {
    u8 pad00[0x10];
    int addr;   /* 0x10 */
    u8 pad14[2];
    u16 h16;
    u16 kind;   /* 0x18: 0x10 or 0x100 */
    u16 h1A;
} V2Cmd;

typedef struct V2Quad { int w0, w4, w8, wC; } V2Quad;

/* request block built on the stack by func_00178790 and sent with func_00178648. DEBT(NAME): guess */
typedef struct V2SndReq {
    int w00;
    int w04;
    int w08;
    int w0C;
    V2Quad sub;
    u8 pad20[0x20];
} V2SndReq;

/* ======== 0x19Axxx-0x19Bxxx ======== */
void func_0019B420(int a, int b, int c);
typedef struct V2Obj7C { /* DEBT(NAME): scripted sequence object stepped by func_0019B4F8 */
    u8 pad00[0x10];
    int chr;     /* 0x10: character handle */
    int chr2;    /* 0x14 */
    int state;   /* 0x18: selects the step function */
    int time;    /* 0x1C: frames in the current state */
    int active;  /* 0x20 */
    int done;    /* 0x24: set by func_0019B878 */
} V2Obj7C;

/* ======== 0x1921xx ======== */
void func_001921C0(void);
void func_001921C8(void);
void func_001921D0(void);
void func_001921D8(void);
void func_001921E0(float *m);

/* ======== 0x1AAxxx: camera/shake state (DEBT(NAME): guesses) ======== */
extern float D_00317128;
extern s32 D_0065FDF0;
extern u_long128 D_0065FE00;
extern u_long128 D_0065FE10;
typedef union V2Vec4 { u_long128 q; float f[4]; } V2Vec4;
extern V2Vec4 D_0065FE20;

/* ======== 0x1986xx: parts of R2ObjA8 ======== */
/* DEBT(NAME): guesses from use in func_00198690 */
typedef struct V2PartData {
    u8 pad00[8];
    int off8;       /* offset of the vertex data from this header */
    u8 pad0C[6];
    s16 count;      /* 0x12 */
} V2PartData;

typedef struct V2Part {
    u32 id;
    void *p4;
    void (*update)(struct V2Part *p);  /* 0x08 */
    void (*draw)(struct V2Part *p);    /* 0x0C */
    u8 pad10[4];
    V2PartData *data;                  /* 0x14 */
} V2Part;

void rcfxParticleSetTime(struct R2Obj1A44 *o, float f);
float func_00195688(void *p);
struct R2ObjA8;
void func_00198730(struct R2ObjA8 *o);
void func_00198800(struct R2ObjA8 *o, int which, void *dst);

/* ======== 0x19A8xx: matrices ======== */
extern float D_00313890[16];
#ifndef FFX_T2_H
extern float D_003138D0[16];
extern float D_00313950[16];
#endif

/* ======== 0x19D8xx ======== */
int func_0019D808(W3Reader *r);
void *func_0017DC08(int size);

/* ======== 0x1807xx: host file access ======== */
extern char D_0056CD10[] __attribute__((aligned(8))); /* "host0:" */

/* ======== 0x1989xx: W3Blk drawing, dispatched by b0A ======== */
void func_00198908(W3Blk *n);
void func_00198978(W3Blk *n);
void func_00198A68(W3Blk *n);
void func_00198AE8(W3Blk *n);
void func_00198BC8(W3Blk *n);

/* ======== W3 pool access ======== */
/* Pool of the global owner (g_pMainWork must be non-null). DEBT(FAKE): the duplicated test of core
   reproduces the original register use / branch layout of this access, whose real form is unknown. */
#define V2_POOL(c, p) \
    if (g_pMainWork->core) { \
        c = g_pMainWork->core; \
        p = c ? c->pool : (W3Pool *)c; \
    } else { \
        c = g_pMainWork->core; \
        p = c ? c->pool : (W3Pool *)c; \
    }

void func_00199510(W3Pool *p);
void func_001994E0(W3Pool *p);

void rcbgSceneFini(W3Pool *p);
void MsSetCameraMatrix(float f, int a, int b, int c, int d, int e);

void func_001991D8(W3Pool *p, W3Item *o);

void rcbgLayerFini(W3Voice *v);

#ifdef FFX_T2_H
R2AnimFrame *func_00190F20(R2Anim *a);
#endif
void func_00192AD8(W3Voice *v);

void func_002DCE08(void *out, void *m, void *in);
void func_002DD0E8(void *out, void *in);

void func_00199FD8(void *o, short a, short b, short c, short d, short e, short f, short g, int x);
void func_00198888(W3Blk *b, int n);

int func_00193C80(W3Voice *v);

/* GS TEX0 register (sceGsTex0 layout) */
typedef struct V2Tex0 {
    u64 tbp0 : 14; u64 tbw : 6; u64 psm : 6; u64 tw : 4; u64 th : 4; u64 tcc : 1; u64 tfx : 2;
    u64 cbp : 14; u64 cpsm : 4; u64 csm : 1; u64 csa : 5; u64 cld : 3;
} V2Tex0;

void func_0019A610(void *o, V2Tex0 tex); /* (moved here from funcs.h: needs V2Tex0) */

/* ======== 0x19AB50: model data reached through an entity slot (DEBT(NAME): guesses) ======== */
typedef struct V2MdlEnt { u8 pad00[0xC]; int *offs; } V2MdlEnt; /* 0x10 */
typedef struct V2MdlHdr { u8 pad00[0x28]; V2MdlEnt ent[1]; } V2MdlHdr;
typedef struct V2Mdl { u8 pad00[8]; V2MdlHdr **hdr; } V2Mdl;

void func_0019B4F8(V2Obj7C *o);
void rcbgFPm173ProcJect(V2Obj7C *o);
void rcbgFPm173ProcKonjyo(V2Obj7C *o);
void func_0019B6F0(V2Obj7C *o);


/* 4-byte value returned in a register (big-endian reader func_0019DF10) */
typedef union V2Word { u32 u; float f; u8 b[4]; } V2Word;

#ifdef FFX_S2_H
void rcefObjProc(S2Obj1A *o);
void func_001A0C70(S2Obj1A *o);
#endif
#if defined(FFX_R2_H) && defined(FFX_Q3_H) && defined(FFX_S2_H)
/* ======== 0x1A0Bxx ======== */
void func_001A0B38(void *p);
void rcefParInit(R2Obj1A14 *o);
void rcefAnimeInit(Obj1A1740 *o);
void func_001A19F0(void *b);
#endif

/* ======== 0x1A2400: GS draw block (DEBT(NAME): guesses) ======== */
typedef struct V2GsSub {
    int w00;
    int p04;       /* buffer address (D_00303550) */
    u8 b08;
    u8 pad09[0xF];
    u8 c18[4];     /* rgba */
    u8 pad1C[4];
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u8 pad30[0x1C];
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} V2GsSub; /* 0x70 */
typedef struct V2GsObj {
    int w00;
    int w04;
    int w08;
    u8 pad0C[4];
    V2GsSub sub;   /* 0x10 */
    float m80[16];
    float mC0[16];
} V2GsObj;

int Sg_MemGetSize(u8 *p);

void func_0018F1F0(Vec4 *dst, Vec4 *a, Vec4 *b, float t);

/* ======== 0x17AFxx: saved copy of an Obj17A110 (DEBT(NAME): guesses) ======== */
typedef struct V2Save17A {
    s16 h00, h02, h04, h06;
    float f08;
    s32 w0C;
    u8 v10[0x10];
    u8 v20[0x10];
    u8 v30[0x10];
} V2Save17A;
void func_0017AB10(void *dst, void *src);

int func_002F2110(int c); /* toupper */
int func_002F2130(int c); /* tolower */

/* ======== 0x17A1xx: debug dumps ======== */
/* printf (func_002EF240) is called without a prototype here: these callers evaluate the arguments in K&R order. DEBT(TYPE) */
extern char D_0056C3E8[]; /* "%f " style format */
extern char D_0056C3F0[]; /* "\n" */

extern char D_0056C3F8[];
extern char D_0056C408[];
extern char D_0056C410[];
extern char D_0056C418[];

/* texture slot whose VRAM block is allocated by func_0017E5A8 (DEBT(NAME): guess) */
typedef struct V2VramReq { u8 pad00[4]; u32 addr; u8 pad08[4]; u32 psm; } V2VramReq;


void func_00110548(Chr *chr, float f, int b);
int MsSetChrTransparent(int id, float f, int b);

int func_001B6310(BtlChr *c, int i, int v);

int MsSetChrTransparentVisible(int id, float f1, float f2, int a, int flags);

#ifndef FFX_Q2_H
float Ch_SetClipZ(Chr *chr, float v);
#endif

/* 0x478-byte records at btl_ply_win (DEBT(NAME): guess): two lists of 0x5000-based command ids */
typedef struct V2CmdSet { u8 pad000[0x158]; u16 list[2][200]; } V2CmdSet;

/* command reference resolved by MsGetChrID (DEBT(NAME): guess) */
typedef struct V2CmdRef { u8 pad00[4]; int w04; int w08; u8 pad0C[2]; u16 cmd; u8 pad10[0xD]; u8 b1D; } V2CmdRef;
extern int D_00319478[];

#ifndef FFX_Q2_H
u8 func_0014ABB0();
#endif

int MsBattleFree(void);
int func_001DBCB8(int);
int func_001DD520(void);
int MsWeaponNameFree(void);
int MsMemCheckFree(void);

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_func_0017AB10_INT ((int (*)(void *, void *))func_0017AB10)

/* DEBT(NAME): paired state/save layouts inferred from func_0017ADF8 and func_0017AE98. */
typedef struct V2State17AE {
    u16 h00, h02;
    int w04, w08;
    u8 pad0C[4];
    u8 v10[16], v20[16];
    u16 h30;
    u8 pad32[2];
    int w34;
    u16 h38[4];
} V2State17AE;
typedef struct V2Save17AE {
    u8 pad00[0x50];
    u8 v50[16], v60[16];
    u8 pad70[16];
    u16 h80, h82, h84, h86;
    int w88, w8C;
    u16 h90[4];
} V2Save17AE;

#endif
