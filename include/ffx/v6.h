#ifndef FFX_V6_H
#define FFX_V6_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* DEBT(NAME): object with an operation table at +0x350 (opu_part_kill) */
typedef struct V6Ops {
    u8 pad[0x54];
    void (*fn54)(int);
} V6Ops;

typedef struct V6Obj {
    u8 pad[0x220];
    int h220;
    u8 pad224[0x12C];
    V6Ops *ops;
} V6Obj;

/* DEBT(NAME): script work area at slot[0] reset by func_00283B00/func_00283B60 */
typedef struct V6Sub {
    u8 pad0[0xC];
    int wC;
    u8 pad10[0x14];
    int w24;
    u8 pad28[4];
    int w2C;
} V6Sub;

typedef struct V6Wk {
    Pair p;
    u8 pad8[8];
    V6Sub s;
    u8 pad40[0x2C];
    int w6C;
    long d70;
    long d78;
    long d80;
    long d88;
} V6Wk;

typedef struct Wkf0f4f8f10f14f18f1Cf20f24 {
    float f0;
    float f4;
    float f8;
    u8 padC[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
} Wkf0f4f8f10f14f18f1Cf20f24;

typedef struct Wkp40p4C {
    u8 pad0[0x40];
    void *p40;
    u8 pad44[8];
    void *p4C;
} Wkp40p4C;

typedef struct Wkp68p6C {
    u8 pad0[0x68];
    void *p68;
    void *p6C;
} Wkp68p6C;

/* DEBT(NAME): ring of positions at slot[0]: count, current index, then the entries */
typedef struct WkRing {
    u8 count;
    u8 cur;
    u8 pad2[0xE];
    Vec4 v[1];
} WkRing;

/* DEBT(NAME): reference to a work area in another script memory (ppvMng->p3C[idx], slot offset ofs) */
typedef struct EvRef {
    int idx;
    int ofs;
} EvRef;

/* DEBT(NAME): work area holding a position pointer and an s16 rotation (1/16384 units) */
typedef struct WkPosRot {
    u8 pad0[8];
    float w;
    Vec4 *pos;
    s16 *rot;
} WkPosRot;

/* ---- particle update (func_002725B8, func_0027BA78). DEBT(NAME): names guessed from the use ---- */
void func_002DD020(Vec4 *dst, Vec4 *a, Vec4 *b); /* DEBT(NAME): dst = a + b guess */

typedef struct PtKey {      /* one frame of a particle animation */
    u8 pad0[2];
    s16 dur;
    s8 flags;               /* 0x80: loop */
    u8 pad5[3];
} PtKey;

typedef struct PtAnim {     /* D_006A3924->tbl[] entry */
    u8 pad0[6];
    s16 frames;
    u8 pad8[8];
    PtKey keys[1];
} PtAnim;

typedef struct Particle {   /* 0xA0 bytes */
    u32 flags;              /* bit 0: alive */
    u16 time;
    u16 frame;
    u32 age;
    u8 padC[4];
    Vec4 v10;
    Vec4 vel;
    Vec4 pos;
    Vec4 acc;
    u8 pad50[0x50];
} Particle;

typedef struct PtEmitter {
    u8 pad0[4];
    int anim;
    int count;
    union {                 /* DEBT(TYPE): union guessed; the load must alias the float stores */
        u16 h;
        float f;
    } speed;
    u8 pad10[0x50];
    Vec4 vel;
    u8 pad70[0x30];
    Vec4 acc;
} PtEmitter;

typedef struct PtOwner {
    u8 pad0[0x40];
    Particle *parts;
    u8 pad44[0x10];
    u32 life;
} PtOwner;

typedef struct PtEmitterB { /* PtEmitter with the vectors 0x10 earlier (func_00276C38, func_00278000) */
    u8 pad0[4];
    int anim;
    int count;
    union {                 /* DEBT(TYPE): see PtEmitter */
        u16 h;
        float f;
    } speed;
    u8 pad10[0x40];
    Vec4 vel;
    u8 pad60[0x30];
    Vec4 acc;
} PtEmitterB;

typedef struct PtOwnerB {
    u8 pad0[0x40];
    Particle *parts;
    u8 pad44[0xC];
    u32 life;
} PtOwnerB;

/* DEBT(NAME): simple block heap (pppCreateHeap init, pppAlloc alloc). Blocks are 16-byte headers
 * chained by next/prev; the last block is a used sentinel. */
typedef struct HBlk {
    struct HBlk *next;
    struct HBlk *prev;
    int used;
    int pad;
} HBlk;

typedef struct HHead {
    HBlk *cur;
    HBlk *first;
    HBlk *last;
    int used;
} HHead;

int pppFree(HHead *h, HBlk *p);

/* DEBT(NAME): heap manager setup block (pppInitEnv) and a full view of HeapMgr (types.h keeps sub as bytes) */
typedef struct HeapCfg {
    u8 pad0[0x14];
    int w14;
    DataRef **tbl;
    char *p1C;
} HeapCfg;

typedef struct HeapMgrV {
    HHead main;
    HHead sub;
    int w20;
    DataRef **tbl;
    char *p28;
} HeapMgrV;

void pppCreateHeap(HHead *h, HBlk *buf, int size);

/* DEBT(NAME): per-slot callback table, indexed by the script header's byte 0xE (func_0026ABD8) */
extern void (**D_006A3BC8)(char *base, int arg);
struct T6_PrObj;
void pppDeletePObject(struct T6_PrObj *o);

/* DEBT(NAME): views used by func_0026ABD8: event word 4, script memory header with an info block at +8 */
typedef struct ScrInfoE {
    u8 pad0[0xE];
    u8 bE;
} ScrInfoE;

typedef struct ScrMemE {
    u8 pad0[8];
    ScrInfoE *info;
} ScrMemE;

typedef struct EvW4 {
    int w0;
    int w4;
} EvW4;

extern char D_005750C0[]; /* "\n(op)\tshut down\tet forced draw !!!\n\n" */

extern char D_00573818[]; /* "0" */
extern char D_00573820[]; /* "decode.c" */

/* DEBT(NAME): GIF A+D packet of 11 GS registers (data, address) copied from the default environment D_006F2CE0 */
typedef struct V6GsReg {
    u64 data;
    u64 addr;
} V6GsReg;

typedef struct V6GsPkt {
    V6GsReg reg[11];
} V6GsPkt;

extern V6GsPkt D_006A3510;

/* DEBT(NAME): 16-byte segment records stored below a block (func_00293CD8): index k lives at p - k * 16,
 * the count of records is the u16 just below p */
typedef struct V6Seg {
    int start;
    int end;
    u16 h8;
    u16 next;
    u8 padC[4];
} V6Seg;

void func_002D76F0(int a, int b);
/* DEBT(CAST): callers in c_293C08 treat func_002D76F0 as returning int (v0 stays reserved after the call) */
#define V6_D76F0(a, b) (((int (*)(int, int))func_002D76F0)(a, b))

extern char D_00574FC0[]; /* "(op)\tet_eff_off_signal:id(%x)\n" */
extern char D_00575048[]; /* "(op)\tet_eff_send_common_signal:id(0x%x),signal(0x%x)\n" */
extern char D_00575080[]; /* "(op)\tet_eff_send_common_andsignal:id(0x%x),signal(0x%x)\n" */

/* DEBT(NAME): fog/depth-like parameter block: colour bytes, near/far/limit from func_00173828, derived
 * scale terms at 0x10..0x1C (func_00293E70) and three float vectors reset by func_00293E08 */
typedef struct V6Env {
    u8 col[3];
    u8 pad3;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float v20[4];
    float v30[4];
    float v40[4];
} V6Env;
extern V6Env D_00703FA0;

void func_00173828(float *x, float *y, float *z); /* as in t2.h */
void func_00173888(int *v); /* as in t2.h */

/* DEBT(NAME): view of ScriptThread.obj300 (current sub at 0x20) */
typedef struct V6Obj300 {
    u8 pad0[0x20];
    ScriptSub *cur;
    u8 pad24[4];
    int w28;
    u8 pad2C[0x54 - 0x2C];
    int w54;
    u8 pad58[8];
    int res[4];                 /* = ScriptThread.res */
} V6Obj300;

/* DEBT(NAME): objects whose frame callbacks fill a T6_ColReqH (func_0028C690, func_0028C868) */
typedef struct V6EmitH {
    u8 pad0[0x10];
    u8 sub[0x20];
    float f30;
    int w34;                    /* copied as the request colour word */
    float f38;
    float f3C;
} V6EmitH;

typedef struct V6EmitH2 {
    u8 pad0[0x10];
    u8 sub[0x20];
    float f30;
    int w34;
    float f38;
    u16 h3C;
} V6EmitH2;

void func_00262740(void);
void func_00262360(void);

/* DEBT(NAME): object with a 16-entry key table at 0x60 (func_00299E68, see also func_00299EE0) */
typedef struct V6Keys {
    u8 pad0[0x60];
    int key[16];
} V6Keys;

int Ch_CheckHandle(int v); /* as in r1.h */

struct U4WrapKey;
void func_0027EED0(char *base, struct U4WrapKey *k, ScriptCtx *ctx);

extern char D_00574CD8[]; /* "(op)\top_et_battle_effect_free( battle end )\n" */
void func_00298D80(void);
void op_et_battle_init(int h);

/* DEBT(NAME): heap manager used by the 0x2B1448 wrappers; owner block holding its setup at +0xD0 */
extern HeapMgrV D_006F2CB0;
extern u8 D_0036F210[];
typedef struct V6HeapOwner {
    u8 pad0[0xBC];
    Slot80 *slot;
    u8 padC0[0x10];
    HeapCfg *cfg;
} V6HeapOwner;
extern void *D_006EA8B0[];

/* DEBT(NAME): argument block of func_00262E58 (halfword at 8) */
typedef struct V6Arg8 {
    u8 pad0[8];
    u16 h8;
} V6Arg8;

/* DEBT(NAME): words saved/restored around func_00294CD8 by func_002B19C8 */
extern int D_003F3940;
extern int D_003F3944;
extern int D_003F3948;
void func_00294CD8(int a, int b);

int Ch_IdGetEffectTable(Chr *c);
extern char D_005757F0[]; /* "(op)\topu_bind2\t\tno ground id(%d)\n" */
void func_002EA328(int a) __attribute__((noreturn)); /* exit(), as in t6.h */
void func_00120108(char *fmt, ...); /* debug print, as in t6.h */

/* DEBT(NAME): message naming a work field in another script memory (entry idx, slot offset) */
typedef struct V6EvRefC {
    u8 pad0[0xC];
    int idx;
    int ofs;
} V6EvRefC;

/* DEBT(NAME): pool of 256 Slot80 records with an in-use table (func_002B1720 init, func_002B1CF8 release) */
extern Slot80 D_006EACB0[0x100];
extern void *D_00764A80;
extern u8 D_003737A0[];
extern u8 D_00373820[];

int _pppRunPart(void *a, int b); /* as in s6.h */

int opus_get_weapon_index_by_chrid(int v); /* as in s6.h */

int yiDObjToOMD(int a, int b); /* defined in c_172DA0.c */
void op_unit_m_scale(void *m, float a);
void *opus_local_get(ScriptThread *th, ScriptSub *sub);
u16 *func_002A4AA0(ScriptThread *thread, u16 *op);
void op_md_draw_map_test(int a, int b, int c); /* defined in c_2B7AC0.c */

/* DEBT(NAME): pool object released by KeThBP_Quit: two runs of 0x30-byte LinkOwner records at 0x40
 * (count h3C from 0, count h38 from index h34) and a next/pprev chain link at 8/0xC */
typedef struct V6Link30 {
    LinkOwner o;
    u8 pad1C[0x14];
} V6Link30;

typedef struct V6LinkObj {
    u8 pad0[8];
    struct V6LinkObj *next;
    struct V6LinkObj **pprev;
    u8 pad10[0x24];
    u16 h34;
    u8 pad36[2];
    u16 h38;
    u8 pad3A[2];
    u16 h3C;
    u16 h3E;
    V6Link30 ent[1];
} V6LinkObj;

struct T6_PObj;
struct T6_PKey;
struct T6_PSysB;
void func_00275F00(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx);
void func_00276008(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx, struct T6_PSysB *s);

void func_00277298(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx);
void func_002773A0(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx, struct T6_PSysB *s);
void func_00278000(PtEmitterB *e, PtOwnerB *o);

struct T6_PSysW;
void func_002718A0(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx);
void func_00271988(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx, struct T6_PSysW *s);
void func_0027AD60(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx);
void func_0027AE48(struct T6_PObj *o, struct T6_PKey *k, ScriptCtx *ctx, struct T6_PSysW *s);
void func_0027BA78(PtEmitter *e, PtOwner *o);
void func_002725B8(PtEmitter *e, PtOwner *o);

/* Resource color/visibility helpers used by op_et_astatus_effect_off. */
void func_002A2558(Chr *, int, s32);
void opus_chara_status_rgb_set(Chr *, s32);
extern s8 D_00575378;

#endif
