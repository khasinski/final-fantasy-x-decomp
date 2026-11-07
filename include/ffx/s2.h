#ifndef FFX_S2_H
#define FFX_S2_H

#include "common.h"
#include "ffx/types.h"

typedef struct S2Load {
    s32 w0;
    u32 buf;
    s32 w8;
    u32 state;
} S2Load;

extern u32 yiImage_printusemem(u32 a, int b);

/* DEBT(CAST): q1.h declares func_0013B7B8(void) but its callers pass an id in a0 */
extern float func_0013B7B8(void);
#define S2_func_0013B7B8(id) (((float (*)(int))func_0013B7B8)(id))

extern char D_0056DFC8[], D_0056DFD0[], D_0056DFD8[], D_0056DFE0[], D_0056DFE8[], D_0056DFF0[], D_0056DFF8[];

typedef struct S2Ent {
    s16 id;
    s16 arg;
    s16 arg2;
    u8 type;
    u8 active;
    u8 pad[0x38];
} S2Ent;

typedef struct S2EntObj {
    u32 flags;
    u8 pad[0xC];
    u8 sub[1];
} S2EntObj;

extern void func_0019A910(S2Ent *e, void *sub);

extern int D_0065FF44, D_0065FF68, D_0065FF6C;
extern void MsBattleExe(int a, int b, int c, int d);
extern void MsBtlReadSetScene(void);
extern void func_001AF990(void);
extern int func_001AF648(int a);
extern int MsImportantRead(void);
extern void MsWeaponNameRead(void);
extern void eiAbmSetLang(void);

extern char D_0056E170[], D_0056E178[], D_0056E180[], D_0056E190[], D_0056E198[], D_0056E1A8[];
extern int MsGetFileSize(int a, int b, int c);
extern void MsMemCheckRegist(void *handle, int size);

extern void func_001B69D0(int id, float *pos);
extern float func_001B6AD0(int id, float f);
extern void MsGetChrPredictPos(int id, float *pos);
extern void func_001AC3E8(float *dst, float *a, float *b);
extern void func_001AC3D0(float *dst, float *a, float *b);

typedef struct S2Ctx {
    u8 pad0[0x67F38];
    u32 mode;
} S2Ctx;

typedef struct S2Disp {
    u8 pad0[0x10C];
    u16 type;
    u8 pad10E[0x12C - 0x10E];
    s32 w12C;
    u8 pad130[4];
    u16 h134;
    u8 pad136[2];
    u16 h138;
} S2Disp;

extern u32 D_0030ECAC, D_0030ECB0, D_0030ECB4;
extern int yiImage_GSmallocclut(int n);
extern int func_0018AAC8(int mode);
extern void func_0018B558(S2Ctx *ctx, int a, int b);
extern void func_0018B5A8(S2Ctx *ctx, int a, int b, int c);
extern int func_002DA928(void *buf, short h, int a, int b, int c, int d, int e, int f);

/* DEBT(CAST): funcs.h declares func_001072F8 with three ints; this is the (Chr *, int, float *) view the q1.h users take */
#define S2_func_001072F8(c, i, v) (((s32 (*)(Chr *, int, float *))func_001072F8)(c, i, v))
extern void func_001A2CC8(float *v);
extern int func_001A3080(int a, int b);
extern void func_001A2F00(int a, int b, float *c);
extern void func_001A2FD8(int a, int b, float *c);

typedef struct S2CamEnt { u8 pad0[0xC5]; u8 fC5; u8 padC6; u8 fC7; u8 padC8[0x130 - 0xC8]; } S2CamEnt;

extern float func_001AC348(float *a, float *b);
typedef struct S2Four { u32 id; void *dtor; int w08; int w0C; void *fn10; void *fn14; int w18; int w1C; void *p20, *p24, *p28, *p2C; int w30; int w34; } S2Four; /* 0x38 bytes (rcfxNailNew); DEBT(NAME) */
extern void MsAtelRegistInit(void);extern char D_0056CDC8[], D_0056D820[];
extern int func_001808E8(int h);
extern int func_00180818(int h, char *buf, int size);
typedef struct S2TableEnt { u32 w0; u8 pad4[4]; int w8; u8 padC[0xC0 - 0xC]; } S2TableEnt;
typedef struct S2Table { u8 pad0[4]; int count; S2TableEnt *ent; u8 padC[0x100 - 0xC]; int w100; int w104; } S2Table;
extern void rcbgSceneChkSortLayer(S2Table *t);
extern void func_0018F5E8(char *fmt, ...);extern void rcbgPreDummyInit(void);
extern void rcbgFpSaveSub(void);
extern void func_00194948(int a);
extern int func_001AEBD8(void);
typedef struct S2Obj1C { u8 pad0[0x10]; HeapMgr *w10; u8 pad14[8]; u8 sub[1]; } S2Obj1C;
extern void *rcefObjNew(void);
extern void rcefObjInit(void *p);
extern void func_001A1FF0(void *sub, void *p);/* DEBT(CAST): the 32 twelve-byte command records at D_003172F0 + 0x15D0 (GameState.ent starts 8 bytes earlier) */
typedef struct S2Cmd { u8 b0, b1, b2, b3, b4, pad5; u16 h6; int w8; } S2Cmd;
#define S2_CMDQ ((S2Cmd *)((u8 *)&D_003172F0 + 0x15D0))
extern void MsBtlReadCueManage(void);typedef struct S2RecTail { u8 pad0[0x5B0]; struct { u8 b0; u8 pad1[0x23]; } e[3]; } S2RecTail;
extern void func_001B3160(int a, int b, int c, int d);extern char D_0056D810[], D_0056DB00[];
extern float eff_sin_t[];
extern void rcbgSceneInit(W3Pool *p);extern float D_00313910[16];typedef struct S2Obj1A { u8 pad0[0xB0]; void *fnB0; void *fnB4; u8 padB8[4]; u32 flagsBC; u8 padC0[0x130 - 0xC0]; float v130[3]; int i13C; u8 pad140[0x160 - 0x140]; float v160[3]; int i16C; float v170[4]; u8 pad180[0x1B0 - 0x180]; float m1B0[16]; float m1F0[16]; float m230[16]; int f270; int f274; u8 pad278[8]; u8 b280[0xB0]; u8 b330[0x90]; u8 b3C0[1]; } S2Obj1A;
extern void rcefObjCalcLocalMatrix(S2Obj1A *o);
extern void func_001A0F58(S2Obj1A *o);
extern void rcefParProc(void *b);
extern void func_001A17A0(void *b);
extern void func_001A1A68(void *b);
extern void func_001A1A00(void *b);
extern void func_001A14C8(void *b);
extern void func_001A1778(void *b);

extern void func_0019A078(void *o, int a, int b, int c, int d, int e, int f, int g);
extern void func_0019A100(void *o, short a, short b, short c, int d);
typedef struct S2Vt { int w0; void *p4; void *p8; void *pC; int w10; void *w14; u8 pad18[8]; u8 body20[0x70]; W3Obj20 v90; float fB0, fB4, fB8, fBC; u8 matC0[0x40]; u8 mat100[0x40]; } S2Vt;
extern void rcbgModelDelete(void *p);
extern void func_001956B0(void);
extern void rcbgModelDraw(void);
extern void rcbgModelInit(void *p);
extern char D_0056E258[];
extern float func_001AC2D0(float *v);
extern void func_001ACB10(float *v, float f);
typedef struct S2DmaCtl { u8 f0 : 1; u8 f1 : 1; u8 f2 : 2; u8 f4 : 2; u8 f6 : 1; u8 f7 : 1; } S2DmaCtl; /* DEBT(NAME): field names guessed, first byte of a DMA channel block */
extern void func_002DBB00(S2DmaCtl *ch, int a, int b);
typedef struct S2BitChr { u8 pad0[0x324]; u16 a324[0x16]; u16 a350[0x16]; } S2BitChr; /* DEBT(NAME): two bit sets in the character record */
extern char D_0056E430[], D_0056E440[];
extern char D_0056D5F0[];
extern s8 D_00317316;
extern char D_00319438[], D_0056E048[], D_0056E078[];
#define S2_PcFileTblSet(s, n) (((void (*)(char *, int))PcFileTblSet)((s), (n))) /* DEBT(CAST): C definition takes one int, the original callers pass a string and a count */
extern void func_001A46E8(void *o);
extern char D_0056DB70[], D_0056DE30[], D_0056DE40[];
typedef struct S2Obj9A { int w0; void *p4; int w8; void *pC; s16 h10; s16 h12; int w14; u64 f18; u8 sub20[0x40]; u8 sub60[0x40]; } S2Obj9A; /* DEBT(NAME): guessed */
extern void func_0019A4E8(void *p);
extern void func_001A4A78(void *p);
extern void func_001A4E18(void *p);
extern void func_0019A510(void *p);
extern void func_001A4AA0(void *p);
extern void func_001A4E40(void *p);
extern void func_0019A578(void *p);
extern void func_001A4B60(void);
extern void func_001A4F20(void);
struct R2Ptr20;
extern void func_001A4B10(struct R2Ptr20 *o);
extern void func_001A4EA0(S2Four *p);
extern char D_0056DB98[], D_0056DBD0[];
struct R2Vt2;
extern void func_0019AD20(struct R2Vt2 *p);
extern void func_0019B498(struct R2Vt2 *p);
extern void func_0019B8F0(struct R2Vt2 *p);
extern void func_0019ACF8(void *p);
extern void func_0019B3F8(void *p);
extern void func_0019B8C8(void *p);
typedef struct S2W8 { u8 pad0[8]; int w8; } S2W8; /* DEBT(NAME): object with a value at 8 */
extern void func_0019E128(void *p);
typedef struct S2ChrB { u8 pad0[0x1BC]; s8 a1BC, a1BD, a1BE; } S2ChrB; /* DEBT(CAST): signed view of the byte triple Trio f1BC */
extern void MsBtlGetPos(int a, BtlChr *c, int b, int d, int e, int f);
extern float MsNearRag(float a, float b);
#define S2_MsGetMon(i) (((BtlChr *(*)(int))MsGetMon)(i)) /* DEBT(CAST): funcs.h takes a u8, this caller passes the int unmasked */
extern char D_0056E370[], D_0056E378[];
extern void MsBtlChrGetMem(void);
extern void func_001B51A0(int id, int a);
extern int graphicCharacterInstanceSetMeshSegmentAlpha(int, int, int);
extern int func_001B2330(int a, int b, int c, int v);
extern int MsAtelRegist(int a, int b, int c);
extern void func_001B3388(void);
extern u8 *AtelGetBattleIdAdrs(int id);
extern char *func_0013A468(char *p);
extern int MsBindCamera(int a, int b, int c);
typedef struct S2Hdr { int w0; int off4; int off8; } S2Hdr;
extern void func_001B1700(int a);
extern void MsAtelActorWorkInit(int a, int b, int c);
typedef struct S2Obj1A5 { int w0; void *p4; int w8; int wC; int w10; void *p14; int w18; float f1C; } S2Obj1A5;
extern void func_001A5698(void);
extern void Ch_Dispose(int v);
extern int func_001B4350(int id, BtlChr *c, int flags);
extern int Ch_DataReadSync(int h);
extern int MsCDreadWeapon(int id, BtlChr *c, int mode);
extern void MsBtlReadPlayerProcess(int id, int v);
extern void MsBtlReadMonsterProcess(int id, int v);
extern void MsBtlWeaponRegist(int a, int b, int c);

/* DEBT(TYPE): in[] is really 64 entries overlapping t0..; sizes fixed to match stride 0x720 */
typedef struct { int a, b, c, d, e, f, g; } S2ClrIn;
typedef struct { int w00, w04, w08, w0C, w10, w14, w18, w1C, w20; S2ClrIn in[63]; int t0, t1, t2, t3, t4, t5; } S2ClrEnt;
typedef struct { char pad[0xA0108]; S2ClrEnt e[64]; } S2ClrBig;


void AtelExecReturn2(int id, int b, int c);
/* DEBT(TYPE): legacy no-result view used by the resource reset sequence. */
#define CALL_AtelSkipReqLevel2_VOID ((void (*)(int, int))AtelSkipReqLevel2)

#endif
