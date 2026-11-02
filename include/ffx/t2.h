#ifndef FFX_T2_H
#define FFX_T2_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/r2.h"
#include "ffx/s2.h"
#include "ffx/b0.h"

/* ---- yiImage resource manager (c_17EDC8, strings "yiImageRman_entry", "yiImage_loadTIM") ---- */
typedef struct YiImage {
    u8 pad_000[4];
    char name[0x104];
    u32 bp;            /* 108: GS buffer pointer, in 64-word units */
    u16 psm;           /* 10C: SCE_GS_PSM* */
    u16 tbw;           /* 10E */
    u8 pad_110[8];
    s32 res;           /* 118: index into Sys597F00.res */
    s32 x;             /* 11C */
    s32 y;             /* 120 */
    u8 pad_124[8];
    u32 cbp;           /* 12C: CLUT buffer pointer */
    u8 pad_130[4];
    u16 csa;           /* 134 */
    u8 pad_136[6];
    u32 w;             /* 13C */
    u32 h;             /* 140 */
    u8 pad_144[0x2C];
    struct YiImage *next; /* 170 */
} YiImage;

/* GS pixel storage modes (libgraph names, see the SCE_GS_PSM* strings at 0x56CA78) */
#define SCE_GS_PSMCT32  0x00
#define SCE_GS_PSMCT24  0x01
#define SCE_GS_PSMCT16  0x02
#define SCE_GS_PSMCT16S 0x0A
#define SCE_GS_PSMT8    0x13
#define SCE_GS_PSMT4    0x14
#define SCE_GS_PSMT8H   0x1B
#define SCE_GS_PSMT4HL  0x24
#define SCE_GS_PSMT4HH  0x2C

void func_0017E5A8(Q3Res *r);
int func_0017E688(Q3Res *r, YiImage *img);
int func_0017F630(Sys597F00 *s, Q3Res *r, YiImage *img);
u32 yiImage_printusemem(u32 size, int psm);
int func_0017EAB0(int mask);
int func_0017F148(int a);
int func_0017F448(Q3Res *r, YiImage *list, YiImage *img);
void func_0017F790(Sys597F00 *s);
/* names of the pixel storage modes, terminated by a NULL name */
typedef struct YiPsmName { char *name; u32 psm; } YiPsmName;
extern YiPsmName D_0030EC28[];
int func_002EF240(char *fmt, ...); /* DEBT(NAME): printf */
extern char D_0056CB48[]; /* "mode : '%s' BP:%04x" */
extern char D_0056CB60[]; /* "    name : '%s'" */
extern char D_0056CB78[]; /* "        (bx,by,w,h)(%03d,%03d,%03d,%03d)" */
extern char D_0056CBA8[]; /* "        (CLUT BP:0x%04X OFFSET:%02X)" */
extern char D_0056CBD0[]; /* "..total %5.1f%% used." */
extern char D_0056C960[]; /* "yiImageRman_entry" */
extern char D_0056C978[]; /* "Invalid color mode" */
extern char D_0056C990[]; /* "GSmem overflow.(%dx%d)\n'%s'" */
extern char D_0056CA08[]; /* "GSmem overflow." */

/* ---- fork A ---- */
extern char D_0056CD18[]; /* "Read Error" */
void func_002DD1C8(void *dst, void *src, float a); /* rotations of a matrix, by axis */
void func_002DD270(void *dst, void *src, float a);
void func_002DD318(void *dst, void *src, float a);
int func_00187D40(void *p, int a, int b, int c);
/* ---- end fork A ---- */

/* ---- fork C ---- */
/* 16-byte chunk header of the rcbg binary data ("YNED", "YNGM", ... tags in D_003136D8) */
typedef struct YnChunk {
    char tag[4];
    int size;      /* payload size in 16-byte units */
    u16 h8;
    u16 index;     /* 0xA */
    u8 padC[4];
} YnChunk;
extern char *D_003136D8[]; /* NULL-terminated chunk tag table */
extern char D_0056D840[]; /* "rcbgMain.c" */
extern char D_0056D850[]; /* "Error in %s, line %d: " */
extern char D_0056D868[]; /* "Bin Data: Header Error" */
int func_002F0A58(const char *a, const char *b, int n); /* DEBT(NAME): strncmp */
int func_00194F08(char *tag);
void rcdtParseInit(W3Reader *cs);
void rcdtParseSet(W3Reader *cs, W3Pair *p);
W3Pair *rcdtChunkNew(void);
W3Reader *func_0019D648(void);
void func_0019E0D8(W3Reader *r, int mode);
int func_0019E0E0(W3Reader *r);
void rcbgPreInit(void);
void rcbgPreLoad(W3Reader *r);
void rcbgSceneLoad(W3Pool *p, W3Reader *r);
void rcbgSceneModelLoad(void *owner, W3Reader *r);
void func_001941A0(void *owner, W3Reader *r);
void *func_0019A6D8(void);
void func_001949E0(void *o);
#define W3_CORE() (g_pMainWork != 0 ? g_pMainWork->core : 0) /* core of the global owner, or 0 */
/* object read by func_001944C0: two image blocks */
typedef struct W3ImgPair {
    u8 pad0[0x10];
    s16 h10;
    s16 h12;
    u8 pad14[0xC];
    W3Img img20;
    W3Img img60;
} W3ImgPair;
void func_00194420(W3Img *o, W3Reader *r);
void func_001944C0(W3ImgPair *o, W3Reader *r);
W3Item *func_00199288(W3Pool *p, int id, int n);
void func_001992F8(W3Pool *p, W3Item *o);
void func_001993E0(W3Pool *p, int id);
void func_00199448(W3Pool *p);
void func_00199580(W3Pool *p);
void func_001995E0(W3Pool *p);
void func_00199620(W3Pool *p);
void func_00199630(W3Pool *p, int a, int b);
void func_001998D0(W3Pool *p);
void func_001999A8(W3Pool *p);
void func_00199B48(W3Pool *p);
void func_00192A68(W3Voice *v);
void func_002B2E10(void (*fn)(W3Pool *), W3Pool *arg, int a, int b);
extern char D_0056DB10[];
void *_rcCalloc(int n, int size, const char *file, int line); /* allocator taking the caller's file/line */
void *rcbgGuideNew(void);
void func_001910A0(void);
void func_001910A8(void);
void func_001912B8(void);
void rcbgPreFini(void);
void func_00198F10(void);
void func_00198F38(void);
void func_00198F60(void);
void func_00195B40(void *p);
void func_001947E0(void);
void func_00194830(void);
extern float D_003138D0[16];
extern float D_00313950[16];
/* polygon record of an RSD model (0x60 bytes) */
typedef struct RsdPrim {
    u32 flags;     /* bit0: set from the first value of the record */
    u32 vtx[4];    /* vertex indices */
    u32 nrm[4];    /* normal indices */
    int tex;       /* 0x24: texture index, -1: none */
    u8 pad28[8];
    struct RsdUV { int u, v; } uv[4]; /* 0x30 */
    u8 col[4][4];  /* 0x50: RGBA per vertex */
} RsdPrim;

typedef struct RsdUV RsdUV;
/* RSD model description loaded by func_0019E248 (strings "rcdtRsd2.c", "rcdtRsdLoad") */
typedef struct RsdData {
    int nvtx;
    Vec4 *vtx;
    int nnrm;
    Vec4 *nrm;
    int nprim;
    RsdPrim *prim;
    int count;     /* 0x18: entries of names */
    char **names;  /* 0x1C */
} RsdData;
typedef struct RsdKeys { u8 *key[7]; } RsdKeys; /* NULL-terminated keyword table */
extern RsdKeys D_0056DC10; /* DEBT(CAST): the original is probably an initialised local array; kept as extern data */
extern char D_0056DC30[]; /* "Error in %s, line %d: " */
extern char D_0056DC48[]; /* "rcdtRsdLoad : File not found." */
extern char D_0056DC68[]; /* "[]=" */
extern char D_0056DC88[];
extern char D_0056DCB0[]; /* "mat" */
extern char D_0056DCB8[]; /* "ma2" */
extern char D_0056DCC0[]; /* "rcdtRsdLoad::LoadMatRsd : File not found." */
extern char D_0056DCF0[]; /* "Assertion failed : %s, file:%s, line:%d" */
extern char D_0056DD18[]; /* "cnt == self->m_cntPolygon" */
extern char D_0056DD88[];
extern char D_0056DDB8[];
int func_002F0278(const char *a, const char *b); /* DEBT(NAME): strcmp */
void func_0019E960(RsdData *d, char *file);
void func_0019EEB0(RsdData *d, char *file);
int rcdtChunkLoadFromFile(W3Pair *p, char *file);
char *func_002F0DD0(char *s, int c); /* DEBT(NAME): strrchr */
void func_0017A930(char *s);
void func_0019E550(RsdData *d, char *file);
void func_0019E8A8(RsdData *d, char *file);
/* TIM2 picture header (strings "rcdtTm2.c", "Image Type Error") */
typedef struct Tim2Pic {
    u32 totalSize;
    u32 clutSize;
    u32 imageSize;
    u16 headerSize;
    u16 clutColors;
    u8 picFormat;
    u8 mipMaps;
    u8 clutType;
    u8 imageType;   /* 4: 4 bit, 5: 8 bit */
    u16 width;
    u16 height;
    u64 gsTex0;
    u64 gsTex1;
    u32 gsRegs;
    u32 gsTexClut;
} Tim2Pic;
/* TIM2 image loaded by func_0019F258 (the W3Obj50 object) */
typedef struct Tim2Img {
    u8 fileHdr[0x10];
    Tim2Pic pic;
    void *image;   /* 0x40 */
    void *clut;    /* 0x44 */
    int texType;   /* 0x48: from func_0019FB60 */
    u8 pad4C[4];
} Tim2Img;
extern char D_0056DDC8[]; /* "Error in %s, line %d: " */
extern char D_0056DDE0[]; /* "File not found" */
extern char D_0056DDF0[]; /* "Image Type Error" */
void rcefMainInit(void *clut);
int func_0019F258(W3Obj50 *o, char *file, int swizzle);
void func_0019F658(Tim2Img *t, u8 *dst, int x, int y, int w, int h);
void func_002DAC50(void *dst, int n); /* same as r0.h; sceGsExecLoadImage-like */
typedef struct Tim2Clut16 { u32 c[16]; } Tim2Clut16; /* a 16 colour CLUT */
/* guide map source data returned by Sg_IdGetPtr (string "rcbgGuide.c") */
typedef struct GuideTri { u16 v[3]; u8 pad6[10]; } GuideTri;
typedef struct GuideGrp { u8 pad0[8]; s16 ntri; u8 padA[2]; GuideTri *tri; } GuideGrp;
typedef struct GuideVtx { s16 x; s16 y; s16 z; s16 pad6; } GuideVtx;
typedef struct GuideSrc {
    u8 pad0[6];
    s16 ngrp;
    u8 pad8[2];
    s16 nvtx;
    float scale;
    u8 pad10[8];
    GuideVtx *vtx;
    GuideGrp *grp;
} GuideSrc;
/* polygon written into the model by func_00195C58 */
typedef struct GuidePoly { u8 col[3][4]; u16 v[3]; u16 h12; } GuidePoly;
/* the W3Sub object (0x80 bytes, see rcbgGuideNew). DEBT(NAME): guess */
typedef struct GuideMap {
    int id;
    GuideSrc *src;
    S2Vt *model;
} GuideMap;
extern char D_0056D980[];
extern char D_0056D990[]; /* "Guide Map Error:ID MAP no POLYGON oosugi desu!! [%d MAX:%d]" */
void func_00195378(S2Vt *m, int type, int n, int nvtx, int nidx);
void rcBBoxSet(W3Obj20 *box, Vec4 *v, int n);
float func_0018F458(W3Obj20 *box);
void rcbgModelFToS0(void *dst, Vec4 *v, int n, float f);
u8 *func_001958F0(R2Obj195b *o, int n);
void rcbgGuideSetModelSub(GuideMap *g);
void func_00195C58(GuideMap *g);
/* ---- end fork C ---- */

/* ---- fork E ---- */
extern u8 D_00319400;
int func_00144810(int a);
void AtelBattleSetUp(void **list, s32 *flags, int n, void *buf, void *local, void *work, int kind, void (*cb)(void));
void MsBattleError(char *name);
void func_001B1960(void);
void func_001B1A18(void);
void func_001B1AC0(void);
extern u8 D_00660088[];
extern u8 D_00661088[];
extern char D_0056E2A0[]; /* "act_work" */
extern char D_0056E2B0[]; /* "act_local" */
extern char D_0056E2C0[]; /* "cam" */
/* ---- end fork E ---- */

/* ---- fork B ---- */
#include "ffx/r2.h"
#include "ffx/s2.h"
/* event-script opcode handlers of c_18D310 (table at D_00312F00): int f(Actor *a, void *op, ScriptCtx *ctx) */
typedef struct ScrOpId { u16 id; u16 pad; int w4; } ScrOpId; /* DEBT(NAME): op block of func_0018D310, layout from use */
int func_002EF240(char *fmt, ...);
extern char D_0056D378[]; /* "**** mpfpbindpos id:%d pos:%f,%f,%f" */
void AtelBindFp(Actor *a, int b, int c);
void func_0014A650(Actor *a, int id, float x, float y, float z);
void func_0014A730(Actor *a, int v);
void func_0014D800(int v);
void yiGetBackColor(int *v);
void func_00173828(float *x, float *y, float *z);
void func_00173888(int *v);
void func_001739D0(float x, float y, float z);
void func_00173A38(int *v);
int func_00173B30(int v);
void func_001750A8(int v);
void func_001750E8(float a, float b, float c, float d);
void func_00175110(float a, float b, float c, float d, float e, float f);
void func_0018D2B0(Actor *a, void *op, ScriptCtx *ctx);
void func_0019BBA0(int v);
int func_0019C280(int idx);
void func_0019C580(float a, float b);
int func_0019C5C0(void);
int func_0019C5F8(void);
void func_0019C630(int idx, float f, int a, int b, int c);
void func_0019C678(void);
void func_0019C6A8(float f);
int func_0019C6E0(void);
void func_0019C718(int idx, float a, int b, float c);
void func_0019C758(void);
void func_0019C7C8(void);
void func_0019C980(int idx, float a, float b, int c);
void func_0019CB98(int idx, float a, float b, int c);
void Yn_GuideMapSetMapNo(int v);
void func_0019D038(void);
void func_00269978(u16 id);
void pppFpSetStickChr(int a, Chr *b, int c);
void pppFpSetStickPos(int a, float *v);
void func_00269E50(void);
void func_00269EC0(void);
void func_0026A770(u16 id);
/* debug dumps of c_18EF98 (printf stub func_0018F5E8) */
typedef struct RsdPoly { s32 type; s32 v[4]; u8 pad14[0x10]; s32 w24; u8 pad28[0x38]; } RsdPoly; /* 0x60 bytes */
typedef struct Rsd { s32 nvert; float (*vert)[4]; s32 nnorm; float (*norm)[4]; s32 npoly; RsdPoly *poly; } Rsd;
typedef struct OmdPrimH { s8 flag; s8 ptype; s16 pc; u8 tno; u8 timposx; u8 res[2]; u32 tex0[2]; } OmdPrimH; /* header of a variable-size primitive record */
typedef struct OmdH { s32 flag; s32 pa, va, na; s16 pc, vc, nc; u8 alpha, alphafix; s16 res[2]; s32 vna; OmdPrimH prim[1]; } OmdH;
typedef struct OmdPrimSize { u8 size[8]; } OmdPrimSize;   /* per-ptype word count of a primitive */
typedef struct OmdPrimName { char *name[8]; } OmdPrimName; /* "OMD_G3", "OMD_G3L", ... */
extern OmdPrimSize D_0056D490;
extern OmdPrimName D_0056D4E8;
extern char D_0056D3B8[], D_0056D3F0[], D_0056D418[], D_0056D428[], D_0056D438[], D_0056D448[], D_0056D458[], D_0056D468[], D_0056D480[];
extern char D_0056D508[], D_0056D518[], D_0056D520[], D_0056D538[], D_0056D550[], D_0056D568[], D_0056D578[], D_0056D580[];
extern char D_0056D590[], D_0056D5A8[], D_0056D5B0[], D_0056D5C8[], D_0056D5D8[], D_0056D5E8[];
extern int D_003135B0;
int func_002ED670(char *name, char *mode); /* fopen */
void func_002ED128(int h);
/* GIF packet helpers of c_1921B8 (R2Pkt = DMA packet being built) */
typedef struct R2DbgWork { u8 pad0[0x174]; char dir[1]; } R2DbgWork; /* DEBT(NAME): only the members used so far */
typedef struct R2GsReg { u64 data; u64 addr; } R2GsReg; /* one A+D register write */
typedef struct R2GsEnv { u8 pad0[0x30]; R2GsReg r30; u8 pad40[0x20]; R2GsReg r60, r70, r80; } R2GsEnv; /* DEBT(NAME): GS environment block at D_006F2CE0 */
extern R2GsEnv D_006F2CE0;
void func_0018FCE0(R2Pkt *pkt);
void func_0018FD88(R2Pkt *pkt, void *buf);
int func_0018FDD0(R2Pkt *pkt);
void func_0018FE28(R2Pkt *pkt);
int rcLog2(int n);
R2Qw *func_00192848(R2Qw *p);
void func_00198870(void *p);
void func_00198880(void *p);
int func_0011D678(int size);
extern char D_0056D7F8[];
/* debug work area; its pointer is kept at the fixed address 0x02000088 (devkit memory above the 32 MB of retail RAM) */
#define R2_DBGWORK (*(struct R2DbgWork **)0x02000088)
void func_00192990(W3Voice *v);
/* frame-animation block at W3Voice+0x90 (0x20 bytes, cleared by func_00190E38) */
typedef struct R2AnimFrame { u8 cell; u8 time; u16 h2; } R2AnimFrame;
typedef struct R2Anim {
    u32 flags;      /* bit0: stopped, bit1: backwards, 0xF00: end mode (0 loop, 0x100 hold) */
    s16 time;       /* 4: ticks spent in the current frame */
    s16 cur;        /* 6: current frame */
    s32 n;          /* 8: frame count */
    R2AnimFrame *frames; /* C */
    W3Img *img;     /* 10 */
    s32 speed;      /* 14: 0x100 = one tick per update */
    s32 frac;       /* 18 */
    u8 pad1C[4];
} R2Anim;
void rcbgAnimeSetDataCnt(R2Anim *a, int n);
void func_00190E38(R2Anim *a);
void func_00190E70(R2Anim *a);
extern char D_0056D630[];
void *func_00199ED8(void);
void func_00194420(W3Img *o, W3Reader *r);
void rcbgLayerLoad(W3Voice *v, W3Reader *r);
void func_00194318(W3Voice *v);
void rcbgModelLoad(S2Vt *o, W3Reader *r);
extern char D_0056D810[];
/* ---- end fork B ---- */

/* ---- fork D ---- */
float sqrtf(float x);
float func_002E8370(float x); /* atanf (newlib s_atan.c) */
int func_001ACD48(float nx, float nz, float dx, float dz);

typedef struct R2MoveOut {
    u8 pad_00[0x30];
    float pos[3];
    u8 pad_3C[0x30];
    float dy;
} R2MoveOut;
void func_001AC750(float *pos, int w, float x, float y, float z);
void func_001A8518(Unk317120Rec *rec, R2Area *area);
/* ---- end fork D ---- */

#endif
