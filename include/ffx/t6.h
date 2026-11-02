#ifndef FFX_T6_H
#define FFX_T6_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/s6.h"

/* ---- callees of TkMenuCtrlAbility (battle menu state machine) ---- */
extern s32 D_003258C8;
extern s32 D_003258CC;
extern s32 D_003258D0;
extern s32 D_003258D4;
extern u16 D_0069BE6A;
extern u8 D_0069BE6D;
extern s16 D_0069BE78[];
extern s16 D_0069BE88[];
extern s16 D_0069BE98[];
int func_00242818(void);
int func_002429D0(void);
void func_002429F0(u16 a);
void func_00242980(u16 a);
void func_0024CD78(int idx);
int func_0024CD68(void);
void func_0024E378(Task *t);
int func_0024D888();
void TkMenuMainFreeWindowGroup(int a0);
void func_0024E1C0(int a, int b, int c);
u8 TkMenuGetPlayerFromIndex(int i);
u8 func_00242798(int i);
void func_0024D2B0(int a, int idx);
void func_0024E358(void);
void func_0024C8C0(void);

/* ---- func_0025B6E8 (list window draw) ---- */
#ifndef SCE_GS_SET_SCISSOR
#define SCE_GS_SET_SCISSOR(x0, x1, y0, y1) \
    ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#endif
#ifndef GS_REG_SCISSOR_1
#define GS_REG_SCISSOR_1 0x40
#endif
typedef struct T6GsEnv { u8 pad0[0x50]; u64 scissor; } T6GsEnv; /* DEBT(NAME): only the default SCISSOR_1 at 0x50 is known */
extern T6GsEnv D_006F2CE0;
void func_00256B78(int x0, int y0, int x1, int y1);
void func_00257048(s64 val, s64 reg);
void func_0025B558(s16 x, s16 y, s16 h, int pos, int count);
void func_0025B4E0(ChrWork *w, int top, int ofs);

/* ---- NkzSetLuluLimitTbl: per-level growth digit tables ("1122333344444444") ---- */
void TOBtlSetLuluLimitTbl(u8 *s);
extern u8 D_00573B20[];
extern u8 D_00573B38[];
extern u8 D_00573B50[];
extern u8 D_00573B68[];
extern u8 D_00573B80[];
extern u8 D_00573B98[];
extern u8 D_00573BB0[];
extern u8 D_00573BC8[];
extern u8 D_00573BE0[];
extern u8 D_00573BF8[];
extern u8 D_00573C10[];
extern u8 D_00573C28[];
extern u8 D_00573C40[];
extern u8 D_00573C58[];
extern u8 D_00573C70[];
extern u8 D_00573C88[];
extern u8 D_00573CA0[];

/* ---- func_0029CBD0 (script opcode: camera/actor link) ---- */
extern s16 D_00703FFC;
void func_002B5978(float *dst, float *src, float s);
void MsCameraSetRect(int h, int i, float *v);
void MsCameraSetRoll(int h, float a);
int MsCameraSetScrDpt(int h, float a);
int MsCameraResetMove(int h, int i);
int MsEffectCameraGet(int a, int b, int c);
void MsEffectCameraEnd(int flag);
void func_001AAC18(float a, float b);
void MsCameraGetPosNow(int i, float *out);
void func_001AA360(float *a, float *b, float x, float y);
void func_001AA3A8(void);
void opus_camera_limit(void *obj300, int v);
int func_001A6828(int h);

/* ---- func_00263DE8 ---- */
void func_002632D8(int a);
void func_00263580(void);
void func_00263CE8(int id, float f);
void func_00263D68(ChrWork *chr, ChrSub *sub, int cancel, int ok);

/* ---- opu_et_etc (script opcode: conditional jumps) ---- */
extern u8 D_00703FFE;
extern u16 D_00704010;
void func_002992B8(Chr *key, u16 v);

/* ---- func_0025B050 ---- */
/* DEBT(NAME): view of ChrSub (12-byte menu entry) */
typedef struct T6_MenuEnt { int id; u8 off; u8 pad5[3]; u32 arg; } T6_MenuEnt;
extern char D_005739D0[]; /* "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n" */

/* ---- func_002671C0 ---- */
/* DEBT(NAME): object/class views of the 0x2671C0 family (class def with a 0x10-byte property table at 0x28) */
typedef struct T6_PrOps { u8 pad0[0x1C]; void (*f1C)(); void (*f20)(); void (*f24)(); } T6_PrOps;
typedef struct T6_PrEnt { T6_PrOps *ops; u8 pad4[4]; int init; u8 padC[4]; } T6_PrEnt;
typedef struct T6_PrDef { u8 pad0[0x20]; int ofs; u8 pad24[2]; s16 n; T6_PrEnt ent[1]; } T6_PrDef;
typedef struct T6_PrObj T6_PrObj;
typedef struct T6_PrCls { T6_PrDef *def; T6_PrObj *last; u8 pad8[4]; u16 refs; } T6_PrCls;
struct T6_PrObj { T6_PrObj *next; u8 pad4[4]; T6_PrCls *cls; };

/* ---- pppFpSaveStat ---- */
typedef struct T6_Slot50 { u32 flags; u32 id; u32 idx; u8 padC[0x44]; } T6_Slot50; /* DEBT(NAME): view of Slot50 with the words printed by pppFpDispDebug */
int func_00269BA8(u16 id);

/* ---- func_0026FAF0 ---- */
/* DEBT(NAME): key records of the 0x26FA88 effect channels (key = owner, dst = work-area offset or -1) */
typedef struct T6_FxKeyF { int key; int dst; u8 pad8[8]; float d[3]; u8 pad1C[4]; u8 range; } T6_FxKeyF;
typedef struct T6_FxKeyB { int key; int dst; s8 d[4]; u8 range; } T6_FxKeyB;
typedef struct T6_FxKeyH { int key; int dst; s16 d[4]; u8 range; } T6_FxKeyH;
extern u8 D_006EA450[];
float func_0026FA98(u8 range);
float func_0026FA88(float a, float b);

/* ---- func_00270E40 ---- */
float func_002B3DB0(float range);
float func_002B3DF8(float range);

/* ---- func_00270FA8 ---- */
extern char D_00574270[]; /* "TBP0:%04xh TBW:%d PSM:%xh TW:%d TH:%d TCC:%d TFX:%d\n" */
extern char D_005742A8[]; /* "CBP:%04xh CPSM:%xh CSM:%d CSA:%d CLD:%d\n" */
int func_002EF240(char *fmt, ...);

/* ---- func_002713C0 ---- */
/* DEBT(NAME): particle emitter views (0x27A078 family) */
typedef struct T6_PLife { u8 pad0[0x10]; int start; int len; int start2; int len2; } T6_PLife;
typedef struct T6_PObj { u8 pad0[8]; T6_PLife **life; int t; } T6_PObj;
typedef struct T6_PKey { u8 pad0[4]; u32 id; int count; } T6_PKey;
typedef struct T6_PRec { u16 h[4]; } T6_PRec;
typedef struct T6_PSysW {
    u8 pad0[0x40];
    u32 *parts;                 /* 0xA0-byte particles, flag word first */
    void *aux;
    int w48;
    int w4C;
    T6_PRec *rec;
    u32 nrec;
    int done;
} T6_PSysW;

/* ---- func_002781D8 ---- */
/* DEBT(NAME): views used by the 0x278000 point-light emitters */
typedef struct T6_LtKey { u8 pad0[4]; float f4; u8 b8; u8 pad9[3]; float size; u32 id; } T6_LtKey;
typedef struct T6_LtRot { s16 x; s16 y; s16 z; u16 s; } T6_LtRot;
typedef struct T6_LtShape { u8 pad0[8]; int ofs; u8 padC[6]; s16 n; } T6_LtShape;
typedef struct T6_LtPt { s16 x; s16 y; s16 z; } T6_LtPt;
typedef struct T6_LtRes { u8 pad0[0x14]; T6_LtPt *pts; u8 pad18[4]; T6_LtShape *shape; } T6_LtRes;
typedef struct T6_LtGrp { s16 res; s16 n; u16 *idx; } T6_LtGrp;
typedef struct T6_LtHeap { u8 pad0[0x20]; T6_LtRes *res; u8 pad24[4]; T6_LtGrp *grp; } T6_LtHeap;
typedef struct T6_LtKeyG { u8 pad0[4]; float f4; u8 b8; u8 pad9[3]; float size; s16 grp; } T6_LtKeyG;
typedef struct T6_LtWork { u8 pad0[0x90]; T6_LtPt *pts; } T6_LtWork;
typedef struct T6_LtCam { u8 pad0[0x30]; float x; float y; float z; } T6_LtCam;
extern u8 D_006A3930[];
void Sg_PLightDefine(float x, float y, float z, float w, int idx, int a, int b, int c, int d);

/* ---- func_00279080 ---- */
/* DEBT(NAME): key records of the 0x279008 vector channels (key = owner, d = per-frame delta) */
typedef struct T6_VKeyF { int key; u8 pad4[0xC]; float d[3]; } T6_VKeyF;
typedef struct T6_VKeyI { int key; u8 pad4[0xC]; int d[3]; } T6_VKeyI;
void func_00279008(int a, R6Fvec *v);

/* ---- pppFpLoadStat ---- */
void pppFpIDon(u16 id);

/* ---- pppFpDispDebug ---- */
extern char D_00574088[];   /* "---- FP Disp Status Start\n\n" */
extern char D_005740A8[];   /* "FP Disp:%s\n\n" */
extern char D_005740B8[];   /* "ON" */
extern char D_005740C0[];   /* "OFF" */
extern char D_005740C8[];   /* table header */
extern char D_005740F8[];   /* table rule */
extern char D_00574168[];   /* "%02d %02d %d %s %s  %s %08x %04x %04x\n" */
extern char D_00574190[];   /* "ON " */
extern char D_00574198[];   /* "\n---- FP Disp Status End\n" */
extern char *D_003708F0[];  /* "END ", "RUN ", "STOP" */
extern char *D_00370900[];  /* "-----", "MAP-D", ... */

/* ---- func_002791A0 ---- */
void func_00279128(int a, R6Wvec *w);

/* ---- func_002792C0 ---- */
void func_00279248(int a, R6Fvec *v);

/* ---- func_0027C478 ---- */
typedef struct T6_PSysB { u8 pad0[0x40]; u32 *parts; int w44; int w48; T6_PRec *rec; u32 nrec; int done; } T6_PSysB;
typedef struct T6_PSysC { u8 pad0[0x40]; u32 *parts; void *aux; int w48; int w4C; T6_PRec *rec; float (*vec)[4]; u32 nrec; int done; } T6_PSysC;

/* ---- func_0026FC68 ---- */
float func_0026FC00(u8 range);
float func_0026FBF8(float a, float b);

/* ---- func_0026FDE0 ---- */
float func_0026FD78(u8 range);
float func_0026FD70(float a, float b);

/* ---- func_0026FF70 ---- */
float func_0026FF18(u8 range);
s8 func_0026FEE8(s8 a, float s);

/* ---- func_002702B0 ---- */
float func_00270248(u8 range);
s8 func_00270220(s8 a, float s);

/* ---- func_00270448 ---- */
float func_002703F0(u8 range);
s8 func_002703C0(s16 a, float s);

/* ---- func_002705E8 ---- */
float func_00270580(u8 range);
s8 func_00270558(s16 a, float s);

/* ---- func_00270788 ---- */
float func_00270720(u8 range);
s8 func_002706F8(s16 a, float s);

/* ---- func_0027A078 ---- */
typedef struct T6_RKey { u8 pad0[0xD]; u8 bD; u8 bE; u8 bF; } T6_RKey; /* DEBT(NAME) */

/* ---- func_00270110 ---- */
float func_002700A8(u8 range);
s8 func_00270080(s8 a, float s);

/* ---- func_002851D8 ---- */
/* DEBT(NAME): 16-byte entries of the table at ppvMng->p3C; base points at another script memory */
typedef struct T6_MemEnt {
    int w0;
    char *base;
    int w8;
    int wC;
} T6_MemEnt;
/* DEBT(NAME): object at ppvMng; table at 0x3C, block at 0x60 handed to func_002DD0B0, colour scale (4.12 fixed) at 0x70 */
typedef struct T6_ColMgr {
    u8 pad0[8];
    int w8;                     /* age limit compared with T6_MemEnt.w8 (func_00267F10) */
    u8 padC[0x18 - 0xC];
    int count;                  /* 0x18: entries in p3C */
    u8 pad1C[0x3C - 0x1C];
    T6_MemEnt *p3C;
    u8 pad40[0x20];
    float m60[4];
    u16 scale[4];
    int w78;
} T6_ColMgr;
extern T6_ColMgr *ppvMng;
/* DEBT(NAME): script memory handed out by func_00267320; word 4 records the requester */
typedef struct T6_Mem {
    int w0;
    ScriptWork *user;
} T6_Mem;
T6_Mem *func_00267320(T6_ColMgr *mgr, T6_MemEnt *e);
void func_00282798(void *dst, void *src);
void func_002DCE08(void *out, void *m, void *in);
void func_002DD068(void *dst, void *v, float s);
/* DEBT(NAME): EvMsgA as seen by the frame callbacks (members beyond EvMsgA's named ones) */
typedef struct T6_EvA {
    u8 pad0[8];
    float f8;
    u8 padC[4];
    int idx;
    int ofs14;
    u8 pad18[4];
    int ofs1C;
} T6_EvA;

/* ---- func_002853C0 ---- */
double func_002E76D0(double x); /* DEBT(NAME): atan guess */

/* ---- pppKeLnsLpDraw ---- */
/* DEBT(NAME): message of pppKeLnsLpDraw */
typedef struct T6_MsgB480 {
    int id;
    float f4;
    float f8;
    u8 bC;
    u8 bD;
} T6_MsgB480;
/* DEBT(NAME): slot-0 work of pppKeLnsLpDraw */
typedef struct T6_WkB480 {
    u8 pad0[0x80];
    float f80;
    float f84;
    float f88;
    u8 pad8C[2];
    u8 b8E;
    u8 b8F;
    u8 m90[0xC];
    float f9C;
    u8 padA0[8];
    float fA8;
} T6_WkB480;
/* DEBT(NAME): script memory header as seen by pppKeLnsLpDraw */
typedef struct T6_SWorkB480 {
    u8 pad0[0xC];
    int owner;
    u8 m10[0x30];
    float f40;
    float f44;
    float f48;
} T6_SWorkB480;
typedef struct T6_ReqB480 {
    void *self;
    void *pos;
    void *a;
    void *b;
} T6_ReqB480;
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
void KeLnsLp_Update(T6_ReqB480 *req);
void pppKeLnsLpDraw(ScriptWork *base, void *msg, ScriptCtx *ctx);

/* ---- func_0028B658 ---- */
/* DEBT(NAME): colour message of the 0x28C230 family */
typedef struct T6_ColMsg {
    int id;
    int idx;
    u8 col[4];
    float fC;
    u16 h10;
    u16 h12;
    u16 h14;
} T6_ColMsg;
typedef struct T6_WkCol30 {
    u8 pad0[0x10];
    u8 m10[0x20];
    float f30;
    u8 col[4];
    float f38;
    float f3C;
} T6_WkCol30;
typedef struct T6_WkCol30h {
    u8 pad0[0x10];
    u8 m10[0x20];
    float f30;
    u8 col[4];
    float f38;
    u16 h3C;
} T6_WkCol30h;
typedef struct T6_WkCol50 {
    u8 pad0[0x30];
    u8 m30[0x20];
    float f50;
    float f54;
    u8 col[4];
} T6_WkCol50;
/* DEBT(NAME): R6Req5 with its word at 4 filled byte by byte (colour) */
typedef struct T6_ColReq {
    void *self;
    u8 col[4];
    void *tbl;
    float fC;
    void *sub;
} T6_ColReq;

/* ---- func_0028B808 ---- */
/* DEBT(NAME): R6Req6 with its word at 4 filled byte by byte (colour) */
typedef struct T6_ColReq6 {
    void *self;
    u8 col[4];
    void *tbl;
    float fC;
    float f10;
    void *sub;
} T6_ColReq6;

/* ---- func_0028B9B8 ---- */
/* DEBT(NAME): request of func_0027FF18/func_00280180 */
typedef struct T6_ColReqH {
    void *self;
    u8 col[4];
    void *tbl;
    float fC;
    u16 h10;
    u16 h12;
    void *sub;
} T6_ColReqH;
void func_0027FF18(T6_ColReqH *req, int n);
void func_00280180(T6_ColReqH *req, int n);

/* ---- pppKeLnsLpTDraw ---- */
/* DEBT(NAME): message of pppKeLnsLpTDraw */
typedef struct T6_MsgBC58 {
    int id;
    u8 pad4[0xA];
    u8 bE;
    u8 bF;
    u8 b10;
} T6_MsgBC58;
/* DEBT(NAME): view of WkB0 with the block at 0xC0 (inside WkB0.sub) */
typedef struct T6_WkBC58 {
    u8 pad0[0x8D];
    u8 b8D;
    u8 pad8E[0x32];
    u8 mC0[0xC];
    u16 hCC;
    u8 padCE[2];
    u8 bD0;
    u8 bD1;
} T6_WkBC58;

/* ---- func_0028C940 ---- */
typedef struct T6_Wkf9CfA8 {
    u8 pad0[0x9C];
    float f9C;
    u8 padA0[8];
    float fA8;
} T6_Wkf9CfA8;

/* ---- func_0028CDB0 ---- */
typedef struct T6_MsgCDB0 {
    int id;
    int idx;
    int ofs;
    u8 bC;
} T6_MsgCDB0;
typedef struct T6_WkB10 {
    u8 pad0[0x10];
    u8 b10;
} T6_WkB10;

/* ---- func_0028D250 ---- */
/* DEBT(NAME): object with a parent pointer at 4 and a matrix at 0x10 (rows 0x10..0x4F) */
typedef struct T6_MtxNode {
    u8 pad0[4];
    struct T6_MtxNode *parent;
    u8 pad8[8];
    float m[4][4];
} T6_MtxNode;

/* ---- func_0028D7D0 ---- */
/* DEBT(NAME): script memory header seen as two matrices (rows at 0x10 and 0x50) */
typedef struct T6_SWorkMtx {
    u8 pad0[0x10];
    float a[4][4];
    float b[4][4];
} T6_SWorkMtx;

/* ---- func_0028DA50 ---- */
typedef float T6_Row[4]; /* one matrix row / vector */

/* ---- op_et_tex_load_triger ---- */
extern s8 D_00703FF3;

/* ---- func_00294188 ---- */
/* DEBT(NAME): R6W8 with the grid handle at 0xC */
typedef struct T6_R6W8C {
    u8 pad0[8];
    int *p8;
    int hC;
} T6_R6W8C;
void SndStandbyBattleWave(int h, u8 *p);
int func_00294130(R6W8 *o);

/* ---- op_oef2_sep_wave_load_all ---- */
int *op_oef2_a_get(int a, int b, int c);
int func_00294188(R6W8 *o, int flags);
/* DEBT(NAME): resource header with an entry count at 0x4C */
typedef struct T6_ResHdr {
    u8 pad0[0x4C];
    u16 count;
} T6_ResHdr;

/* ---- op_oef2_sound_cue_multi ---- */
void func_00294408(u8 *ent, int arg);

/* ---- op_oef2_sound_cue_check ---- */
/* DEBT(CAST): SndDataSendSync is void but this caller tests the value left in v0 (SqsDataSendingCompleted's result) */
#define T6_D85A8(a) (((int (*)(int))SndDataSendSync)(a))

/* ---- op_oef2_se_3d_on ---- */
int op_3d_vol_pan_get(int a, int b, int *pan);
void func_00120108(char *fmt, ...); /* DEBT(NAME): debug print */
extern PtrHolder8 *D_006EA8A0[2]; /* DEBT(NAME): the two entries currently on the streaming channels */
extern char D_005745F0[];

/* ---- op_oef2_se_3d_move ---- */
void func_002D8508(int v);

/* ---- opu_end ---- */
void func_00295EB8(void *obj300, int id, ScriptSub *sub, u16 *pc);
void func_2069EB8(int id); /* DEBT(NAME): jal target outside the image (address 0x2069EB8) */

/* ---- opu_et_end ---- */
extern char D_00574610[];
extern char D_00574638[];
extern char D_00574660[];
extern char D_00574688[];
u16 *opu_end(ScriptThread *th, u16 *pc);
void MsEffectTerminate(int key);

/* ---- func_00295418 ---- */
int func_002B3D68(int n);
ScriptSub *opus_no_get(void *obj300, ScriptSub *sub, int id); /* same as s6.h */ /* random number below n (role guess) */
/* DEBT(NAME): view of the sub-object at ScriptThread.obj300 with its current entry at 0x20 */
typedef struct T6_Th300c {
    u8 pad0[0x20];
    ScriptSub *cur;
} T6_Th300c;

/* ---- opus_cscale_get ---- */
float MsGetChrHeight(int id); /* same as q4.h */
float MsGetChrWidth(int id);
/* DEBT(CAST): the original called these two without a prototype and converted the int left in v0 */
#define T6_INTCALL(f, a) (((int (*)(Chr *))(f))(a))

/* ---- opu_mfifo ---- */
typedef struct T6_Th300Subs { u8 pad00[0x20]; u8 *subs; } T6_Th300Subs; /* DEBT(NAME): obj300 + 0x20 = base of the 0x100-byte sub blocks */
void op_mfifo_set(void *p, int q, int r, int s);

/* ---- opu_damage ---- */
extern char D_005754D8[];
extern char D_00575510[];
int MsMergeDamage(int key, int id);

/* ---- opu_damage_motion ---- */
float op_deg_get(float *v, float x0, float z0, float x1, float z1);

/* ---- func_0029FD20 ---- */
float MsGetChrGround(int id);
float op_length_get(float *a, float *b);
int op_deg_in_check(float v, float lo, float hi);

/* ---- opu_s_div ---- */
typedef struct T6_SubVel { u8 pad00[0x50]; float a[4]; float b[4]; float da[4]; float db[4]; } T6_SubVel; /* DEBT(NAME): ScriptSub 0x50..0x8F as two value/step vector pairs */

/* ---- func_0029FF10 ---- */
extern s16 D_003735B0[]; /* byte offsets of the vectors inside ScriptSub */

/* ---- opus_set_chr_pos ---- */
void Ch_SetPos3(Chr *chr, float x, float y, float z);
int MsSetChrDirF(int id, float v); /* DEBT(TYPE): defined with u8 id, callers do not mask */
void MsSetChrPos(int id, float *pos);

/* ---- func_002A0820 ---- */
/* DEBT(NAME): pool of 0x100-byte script blocks (func_002A0820) */
typedef struct T6_Blk { int w0; u8 pad04[0x14]; u8 b18; u8 pad19; u16 serial; u8 pad1C[0x14]; float f30[8]; } T6_Blk;
typedef struct T6_BlkPool { u8 pad00[2]; s16 serial; u8 pad04[0x1C]; u8 *blocks; } T6_BlkPool;
int func_00295D58(T6_BlkPool *p, int key);
void func_00295C50(T6_Blk *b);
void func_00295CA0(T6_BlkPool *p, T6_Blk *b, int arg);

/* ---- func_002A0FF0 ---- */
/* DEBT(NAME): view of ScriptThread.sub used by the move opcodes (0x2A0FF0) */
typedef struct T6_SubMove {
    u8 pad00[0x40];
    float v40[3];
    u8 pad4C[0x44];
    float pos[3];
    u8 pad9C[4];
    u16 hA0;
    u16 hA2;
    float fA4;
    u8 padA8[0x12];
    u8 bBA;
} T6_SubMove;

/* ---- func_002A1538 ---- */
/* DEBT(NAME): ScriptSub as seen by the motion opcodes (0x2A1538); 0xF2/0xF4 lie past ScriptSub's known end */
typedef struct T6_SubAnim {
    u8 pad00[0x18];
    u8 b18;
    u8 pad19[0xA7];
    u16 hC0;
    u16 hC2;
    s16 hC4;
    s16 hC6;
    u8 padC8[0x2A];
    s16 hF2;
    s16 hF4;
} T6_SubAnim;
float opus_cwidth_scale_get(int id, int v);

/* ---- func_002A3BD8 ---- */
typedef struct T6_PackBuf { u16 n; u16 len[15]; u8 data[1]; } T6_PackBuf; /* DEBT(NAME): count, per-entry sizes, then packed data at 0x20 */

/* ---- op_chara_hsv ---- */
u8 *op_hsv_to_rgba(void *src, u8 *dst, int len, int a, int b, int c, int d);

/* ---- func_002A7420 ---- */
typedef struct T6_Slot16 { int id; int val; int w8; int wC; } T6_Slot16; /* DEBT(NAME): D_006F37E0 entries with their second word */
extern char D_005756A0[];
void func_002EA328(int a) __attribute__((noreturn)); /* exit(): never returns */

/* ---- opu_unit_ex ---- */
typedef struct T6_ThBlk { T6_Blk *blk; } T6_ThBlk; /* DEBT(NAME): ScriptThread word 0 used as the current block by 0x2A08D8 */
u16 *opu_unit(ScriptThread *th, u16 *pc);

/* ---- func_00251EE8 ---- */
extern int D_0069CD40;

/* ---- PcReadFunc_set ---- */
/* DEBT(NAME): view of the callback table D_0078E498 (Unk78E498 only knows 0x10/0x14/0x30/0x68) */
typedef struct T6_Vt {
    int (*f00)();
    int (*f04)();
    int (*f08)();
    int (*f0C)();
    int (*f10)();
    int (*f14)();
    u8 pad18[0x3C];
    int (*f54)();
    int (*f58)();
    u8 pad5C[4];
    int (*f60)();
    u8 pad64[4];
    int (*f68)();
    u8 pad6C[0xC];
    int (*f78)();
    u8 pad7C[0xC];
    int (*f88)();
    int (*f8C)();
} T6_Vt;
#define T6_VT ((T6_Vt *)&D_0078E498) /* DEBT(CAST): see T6_Vt */
int CDfileSize_PC();
int func_00255238();

/* ---- func_00256708 ---- */
#ifndef GIF_CHCR
#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */

/* ---- func_00257090 ---- */
void func_00256970(int x0, int y0, int x1, int y1, u64 c0, u64 c1, u64 c2, u64 c3, int z);

/* ---- func_00257F20 ---- */
/* DEBT(NAME): request block handed to func_00257E60 / func_00258060 (R6Req is the same block seen from 0xC) */
typedef struct T6_Req { Pt16 *tbl; int ch; int bit; int result; u8 mask; } T6_Req;
void func_00257C68(int (*fn)(), T6_Req *req);
void func_00257D00(u16 id, int (*fn)(), T6_Req *req);
int func_00258060(R6Fb *a, R6Req *b);

/* ---- func_00258140 ---- */
WorkEnt2 *func_00258140(u16 id, WorkEnt2 *from, u16 *other, u8 mask, u8 val);

/* ---- func_00258618 ---- */
void func_00258278(u8 mask);
void func_002584C0(u16 id, int a);

/* ---- func_002595E8 ---- */
/* DEBT(NAME): view of WorkEnt2 for the word at 0x10 */
typedef struct T6_Link { u16 a; u16 b; u16 c; u8 pad06[7]; u8 flags[3]; int seed; } T6_Link;
/* DEBT(NAME): view of GlobalWork for the word at 0x1161C */
typedef struct T6_GwSeed { u8 pad[0x1161C]; int seed; } T6_GwSeed;
int func_00259510(T6_Link *l);

/* ---- func_00260980 ---- */
extern int D_006A38F8;
void func_002D02E8(int a, int b, int c, int d);
void func_00260600(void);
void func_00260670(void);
void func_0025EDA0(void);
void func_0025EFC0(void);
void func_0025C350(void);
void func_0025CD18(void);
void func_0025F770(void);
void func_0025E950(void);
void func_0025F2A0(void);
void func_0025D050(void);
void func_0025CB68(void);
void func_00260930(void);
void func_00260370(void);
void func_0025F898(void);
void func_0025BE90(void);

/* ---- func_00262ED8 ---- */
extern int D_006A3600;
void func_00262A40(void);
void func_00264248(void);
void func_00262C40(int i, int a, int b, int c, int d);

/* ---- func_00263CE8 ---- */
void func_00264210(void);
void func_002613B8(void);
void func_00263C98(void);

/* ---- func_002644C0 ---- */
/* DEBT(NAME): view of PartySlot for the bit set at 0x3E (one bit per menu entry id) */
typedef struct T6_SlotBits { u8 pad[0x3E]; u16 bits[1]; } T6_SlotBits;

/* ---- func_002659F8 ---- */
/* DEBT(NAME): 0x80-byte register block copied between the display environments */
typedef struct T6_GsBlk { u64 q[16]; } T6_GsBlk;
/* DEBT(NAME): display environment returned by func_00245470 */
typedef struct T6_GsSrc { u8 pad0[0x60]; T6_GsBlk a; u8 padE0[0xF0]; T6_GsBlk b; } T6_GsSrc;
/* DEBT(NAME): display environment at D_006A36C0 */
typedef struct T6_GsDst { u8 pad0[0x60]; T6_GsBlk a; u8 padE0[0x70]; T6_GsBlk b; } T6_GsDst;
extern int D_006A36BC;
extern T6_GsDst D_006A36C0;
void func_00293570(void);
void op_loop_ffx_after(void);
void func_002D0408(void);
void func_002D0698(u32 mask);
void func_00260980(void);
void func_002B2810(void);
int func_00293740(void);

/* ---- func_00251178 ---- */
extern u8 D_0069BF20[];
extern int *D_00327020;
int func_002FB6B8(void *cd);

/* ---- func_00251260 ---- */
extern u8 D_0069BF48[];

/* ---- func_002517A8 ---- */
int func_002F8780(int a);

/* ---- func_002518C8 ---- */
/* D_00327010 is advanced by the SIF RPC end callback (interrupt context); func_002518C8 busy-waits on it and the
   original reloads it every pass, hence the volatile view. */
#define T6_REQ_CNT ((volatile int *)D_00327010) /* DEBT(CAST): globals.h declares it non-volatile */
extern int *D_00327028;
extern int *D_0032702C;

/* ---- SqsMusicDataSend ---- */
/* NOTE: funcs.h declares `int SqsMusicDataSend(void);` -- needs `int SqsMusicDataSend(T6_Music *m);` (declare T6_Music first) */
/* DEBT(NAME): music data block sent to the IOP by SqsMusicDataSend */
typedef struct T6_Music { u8 *head; int pad4[3]; int size; } T6_Music;
extern char D_00573700[]; /* "Music Data Head Error !! ( Head = %2.2X %2.2X %2.2X %2.2X )\n" */
extern char D_00573740[]; /* "Music Data Size Error !! ( Size = 0x%8.8X )\n" */

/* @@T6_INSERT@@ */

/* DEBT(NAME): transform views inferred from func_0027A3F0. */
/* DEBT(TYPE): payload is a variable-sized C89 trailing byte region. */
typedef struct T6TransformFrame {
    u8 pad0[0xC];
    int idC;
    float matrix[4][4];
    float world[4][4];
    u8 pad90[0x10];
    u8 payload[1];
} T6TransformFrame;
typedef struct T6TransformInput {
    u8 pad0[0xC];
    int *offsets;
} T6TransformInput;

/* DEBT(NAME): transform fields inferred from func_002560D0. */
typedef struct T6TransformRecord {
    u8 pad0[0x1E];
    s16 enabled;
    u8 pad20[0x20];
    float position[4];
    int rotation[3];
    int flag5C;
    float scale[4];
} T6TransformRecord;
extern int *D_00327980; /* DEBT(TYPE): table of word-sized resource handles. */
void _pppStartPart(T6TransformRecord *, int, int, int); /* DEBT(TYPE): unused result; task view inferred from caller. */

/* DEBT(NAME): language-bearing resource configurations used by pc_fat_index_filename_set. */
typedef struct T6LanguageConfig {
    u8 pad0[0x16];
    u8 language[2];
} T6LanguageConfig;
extern T6LanguageConfig D_00327080, D_003270B0, D_003270E0;
extern CfgBlock D_00327110, D_00327138;
extern s8 D_005661F4;
/* DEBT(TYPE): the helper returns int; its shared declaration is still void. */
#define CALL_MsSetCountryName_INT ((int (*)(void *))MsSetCountryName)

/* DEBT(NAME)/DEBT(TYPE): payload attribute views inferred from func_00284328. */
typedef struct T6AttributeDelta {
    int id;
    u8 pad4[4];
    u16 channels[16];
    float values[4];
    u8 enabled;
} T6AttributeDelta;
typedef struct T6AttributeValues {
    u16 channels[16];
    float values[4];
} T6AttributeValues;
typedef struct T6AttributeVectors {
    u8 pad0[0xC];
    float value0C;
    u8 pad10[0x14];
    float value24;
    u8 pad28[4];
    float value2C;
    u8 pad30[0x10];
} T6AttributeVectors;
typedef struct T6AttributeOutput {
    u8 pad0[0x10];
    T6AttributeVectors vectors;
    u8 enabled;
    u8 pad51[0x1B];
    float value6C;
    u16 channels[16];
} T6AttributeOutput;

/* ---- func_0025D750 ---- */
typedef struct T6_AbmDrawWork {
    Vec4 v[3];
    u8 pad30[0x1B0];
    int abe;
    int z;
    int w1E8;
    int w1EC;
} T6_AbmDrawWork;

#endif
