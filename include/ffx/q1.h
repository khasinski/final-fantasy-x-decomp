#ifndef FFX_Q1_H
#define FFX_Q1_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"
#include "ffx/actor_resources.h"

/* ======== 0x130AD8-0x145148: script-VM opcode handlers (continued) ======== */

/* DEBT(NAME): view of the record returned by func_00124828 with the halfword members at 0xB4..0xBA (Rec124828 only
   names 0xBC); the two types describe the same record. */
typedef struct Rec124828H {
    u8 padB4_0[0xB4];
    s16 hB4;
    s16 hB6;
    s16 hB8;
    s16 hBA;
    u8 padBC[0x30];
    u8 bEC[4];
} Rec124828H;

/* DEBT(CAST): the callee ignores its argument and these callers pass none, but funcs.h declares (int idx) */
#define REC124828H() ((Rec124828H *)((Rec124828 *(*)())func_00124828)())

void func_00124550(Rec124828 *r);
void AtelSetEffectFlag(int v);
void func_0014AA30(int v);
void SndMusicCrossStart(u32 id, int v);
void func_002D8478(int v);
void func_002D8480(int a, int v);
void func_002D8488(int a, int b);

void func_0014D960(int v);
void func_0014D970(int v);
void func_002D8508(int v);
void func_002D8510(int a, int b);
void func_0014ABD0(int v);
int func_00138BE8(void);
void AtelBindFp(Actor *a, int v, u16 h);
void func_0014D890(int v);
void func_00138A58(int v);
void func_00138A78(int v);

/* DEBT(CAST): members the shared types leave as padding */
#define ACTOR_HA8(a) (*(u16 *)((u8 *)(a) + 0xA8))
typedef struct EvGameStateF { u8 pad0[0x1F0]; float f1F0; } EvGameStateF;

void func_002D8490(int a, int b, int c);

#define CLAMP_S8(v) ((v) < -128 ? -128 : ((v) < 128 ? (v) : 127))
#define CLAMP_U8(v) ((v) < 0 ? 0 : ((v) < 256 ? (v) : 255))

void func_001746E8(int a, int b, int c);
void yiDisposeAnimDObj(int a, int b);
void func_001747B0(int a, Chr *c, int b);
void func_001747D0(int a, Vec4 *v);

int func_0014ACC0(int v);

/* DEBT(CAST): alternate bit-field view of Actor.flags34 (ActorFlags has no 1-bit members at 22 and 31) */
typedef struct ActorFlagsQ {
    unsigned lo : 22;
    unsigned b22 : 1;
    unsigned mid : 8;
    unsigned b31 : 1;
} ActorFlagsQ;


/* DEBT(CAST): funcs.h declares the byte parameters as s8, the original callers pass them unextended (int) */
#define CALL_func_002D8698 ((void (*)(int, int, int))func_002D8698)
#define CALL_func_002D8700 ((void (*)(int, int, int, int))func_002D8700)

/* DEBT(CAST): views of shared records whose members at these offsets are padding in types.h */
typedef struct PartySlotV { u8 pad00[0x50]; s32 v50; s32 v54; s32 v58; } PartySlotV;
typedef struct EvGameStateG { u8 pad00[0x210]; s32 w210; } EvGameStateG;

/* DEBT(NAME): 0x10-byte per-opcode state block (fields named by offset) */
typedef struct OpBlk {
    int w0;
    int w4;
    u16 h8;
    u8 bA;
    u8 bB;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} OpBlk;

int func_00174810(int a, int b);
void MsBtlGetInit(void);
void func_0014E0A8(int a, int b);
void func_0014E160(void);
int func_0014DE28(void);
void func_001E0DE8(int v);
void func_00148780(u16 v);
void func_0014AD58(int v);
int func_0014AD88(void);
void func_0014ADB8(void);
void func_0014AE00(int a, int b);
void func_0014E068(void);
void func_0014E028(void);
void func_0014DCB8(int v);
void func_0014DC70(int v);
void SaveDataIsScreenClosed(u32 v);
#define CALL_func_002D5E48 ((int (*)(int))func_002D5E48)

/* DEBT(NAME): per-opcode state block of the 0x131F48 handler */
typedef struct OpBlkH {
    int w0;
    int w4;
    u16 h8;
    u16 hA;
    int wC;
} OpBlkH;


void MsSaveItemUse(u16 a, u8 b);
int func_001C0598(Unk1BFED8 *p);

/* DEBT(CAST)/DEBT(NAME): overlay of Actor with the members the shared Actor type still has as padding
   (offset-derived names). Use through AQ(a). */
typedef struct ActorBits2 { unsigned b0 : 1; unsigned b1 : 1; unsigned rest : 30; } ActorBits2;

typedef union WordFQ { u32 w; float f; } WordFQ; /* DEBT(FAKE): float member only so float stores are not reordered across reads of the word, as the original does */
typedef struct ActorQ {
    u8 pad00[0x2C];
    u16 h2C;
    u16 id;
    u8 pad30[4];
    WordFQ w34;
    s32 w38;
    int w3C;
    u8 pad40[0x9C - 0x40];
    Chr *ptr9C;
    u8 padA0[8];
    u16 hA8;
    u8 stateAA;
    u8 padAB; s8 bAC; u8 padAD[0xAF4 - 0xAD];
    Chr *arrAF4[4];
    u16 hB04[2];
    ActorBits2 arrB08[3];
    u16 hB14;
} ActorQ;
#define AQ(a) ((ActorQ *)(a))

extern s8 D_005661F4;

int func_00124530(void);
int func_0014F168(void);
void AtelBindEff2On(Actor *a, int v);
void func_00138970(Actor *a, int v);
int func_0013A8C0(int v);
int func_002F05E8(int a, u8 *b);
void func_002D8778(int v);
void Ch_Vu1SetClipmode(Chr *chr, int v);

/* DEBT(CAST): the system vtable of GetCD with the slots at 0x88/0x8C that SysVt leaves as padding */
typedef struct SysVtQ {
    u8 pad00[0x88];
    int (*f88)(int a, int b);
    int (*f8C)(int a);
} SysVtQ;

typedef struct EvGameStateK { u8 pad00[0x44]; int w44; } EvGameStateK;

int func_0014D2F8(int a, int b, int c, int d, int e);
void func_0014D468(int v);
int func_0014CEB0(int v);
void func_00144D48(int v);
void func_0014D3F0(int a, int b, int c);
int func_00173150(void);
int func_00173190(void);
int func_001731C0(int id, float a, float b, float c);
int func_00173240(void);
int func_001731E8(int a, int b, int c);
void func_002D7430(int a, s32 *b, s32 *c);
int func_002D71C0(int a);
int func_002D72F8(int a, s32 *b, s32 *c, int d, int e);

void func_0014D610(int a, char *buf);

int func_00173208(int id, float a, float b);
void func_0014D7F0(float f);
int func_0014D7E0(void);
void TkMenuSetDummyControlerFlag(int v);
void func_002415B8(int v);
void func_001387D0(int a, int b, int c);
int func_00220F10(void);
int func_00220F20(void);
int func_0014F380(int a, int b, int c);

#define CALL_func_001BDE20 ((void (*)(int, int))func_001BDE20) /* DEBT(CAST): funcs.h declares (u8 id, int on) */

void func_00145400(void);
void func_0014AEF8(u16 v);
void func_0014AF68(int v);
int func_0014AF40(int v);
void AtelSetHelpEventFlag(int a, int b);
int AtelGetHelpEventFlag(int v);
typedef struct OpBlkR { int w0; int w4; int w8; u16 hC; u16 hE; } OpBlkR; /* DEBT(NAME): state block of the 0x134360 handler family */
/* DEBT(CAST): bit view of EvGameState.flags (GameFlags has no member for bit 26) */
typedef struct GameFlagsQ { unsigned lo : 26; unsigned b26 : 1; unsigned hi : 5; } GameFlagsQ;

#define CALL_func_0012A7E0 ((int (*)(void))func_0012A7E0) /* DEBT(CAST): funcs.h declares (a, op, ctx); this caller passes nothing */

typedef struct GameFlagsR { unsigned lo : 16; unsigned b16 : 1; unsigned hi : 15; } GameFlagsR;
typedef struct EvGameStateX { GameFlagsR flags; u8 pad4[0x208 - 4]; float f208; } EvGameStateX; /* DEBT(CAST): overlay of EvGameState */
int func_00227FD8(int a, int b);
int func_0014F228(int a, int b, int c, int d);

extern int D_0036E998[];
extern int D_0036F0E0[];
void func_001385A8(int a, int b);
void AtelSetShopRatio(int v);
void func_002415C8(int a, u8 b);
void func_0014B150(int a, int b, int c, int d);
void TkMn2SetMainFrameRatioDiff(int v);
void func_0014B188(void);
int func_0014B240(void);

void AtelSetDolby(int v);
void MsSetSaveStartGame(void);
void MsBattleReadData(void);
void TkCdReadSync(int v);
void func_0014C828(int v);
void MsChangeWeaponInvisible(int a, int b);
void func_00299B90(void);
void func_00299BA8(void);
void func_00299B78(void);

void func_00265B58(void *p);
void TOSwapInternationalEnvInit(int v);
int TOSwapInternationalEnvExec(void);
void func_001382C0(int a, float f);
int func_00138220(void);
typedef struct EffectQ { u8 pad00[0x16]; u16 h16; u8 pad18[6]; s8 b1E; s8 b1F; u8 pad20[2]; u8 b22; u8 b23; u8 pad24[4]; int w28; } EffectQ; /* DEBT(CAST): view of Effect (AtelGetMesWinWork) with the member at 0x28 */
/* DEBT(NAME): 16-byte entry of the two 16-entry callback queues at D_0058CF48 (fn, state word, 7-char name) */
typedef struct CbEnt {
    int (*fn)(int *arg);
    int w4;
    char name[8];
} CbEnt;
extern CbEnt D_0058CF48[2][16];
extern char D_0056A510[];

u16 *MsGetSaveWeaponList(int a, int b, int c, s32 *count);
typedef struct Unk1BFED8Q { u8 pad0[3]; u8 b3; } Unk1BFED8Q; /* DEBT(CAST): view of Unk1BFED8 with the byte at 3 */

char *func_002F032C(char *dst, const char *src);
extern char D_0056A400[];
extern char D_0056A3E0[];
extern char D_0056A3E8[];
extern char D_0056A3F0[];
extern char D_0056A3F8[];

char *func_0014F1C0(int i);

extern int D_0058D1E0;
extern float D_0058D1E4;
extern float D_0058D1E8;
extern char D_0056A520[];
extern char D_0056A518[];
extern char D_0030B2C0[];
typedef struct Q1F0Ent { int w0; int w4; u8 pad8[0x18]; u8 b20; u8 b21; u8 pad22[2]; } Q1F0Ent; /* DEBT(NAME): 0x24-byte entry at D_0058D1F0 */
extern Q1F0Ent D_0058D1F0[16];
void func_00139748(int v);
void AtelMapLoadBtl(int v);
void AtelMapLoadNoCache(int v);
void func_0011F990(int a, int b);
void func_0011FA30(int v);
void func_0014D9A0(int v);
int func_2058538(char *name);
void func_20585F0(int h, void *buf, int size);
void func_2058698(int h);
int func_2058460(char *name);
void func_20585B8(int h, void *buf, int size);

extern char D_0056A538[];
extern char D_0056A588[];
int func_002EF240(const char *fmt, ...);
int yiLoadFieldParticleNo(int v);
int yiLoadBattleFieldParticleNo(int v);
void SndStandbyStream(int v);
void SndStartStream(void);
void func_00136520(int i);

void func_002D6E48(int a, int b, int c, int d);

int func_0010AE50(int v);
int func_001BCE30(void);
int MsDebugFullCommand(void);

/* DEBT(CAST): raw byte base of the record returned by func_00124828 (offsets are script-supplied) */
#define REC124828_BASE() ((char *)((void *(*)())func_00124828)())
int SndSepClearAll(void);
int func_0015A550(void);
int func_00158D60(void);

#define CALL_func_002D41F0(v) (((void (*)(int))func_002D41F0)(v)) /* DEBT(CAST): funcs.h declares this without its argument */
#define CALL_func_002D41E8(v) (((void (*)(int))func_002D41E8)(v)) /* DEBT(CAST): funcs.h declares this without its argument */

void TOSetAlbhedFlg(int v);
void func_00124528(int v);
#define CALL_SndMusicStandby(a, b) (((void (*)(int, int))SndMusicStandby)(a, b)) /* DEBT(CAST): funcs.h declares this without its arguments */

#define CALL_func_001BDDC8(v) (((int (*)(int))func_001BDDC8)(v)) /* DEBT(CAST): funcs.h declares this without its argument */

int func_00148390(int a, int b, int c, int d);
void func_001463F0(int v);
void AtelEventRemoveForBattle(int v);
u16 *func_00208448(void);
void SndStartShoutStream(int a, int b, int c);

void func_2059B48(void);

#define CALL0_func_0013A398() (((int (*)(void))func_0013A398)()) /* DEBT(CAST): funcs.h declares an unused id parameter the original caller does not pass */

#define CALL_func_00124618(v) (((void (*)(int))func_00124618)(v)) /* DEBT(CAST): funcs.h declares a u8 parameter, the original caller passes a full int */

#define CALL_func_001072F8(c, i, v) (((s32 (*)(Chr *, int, float *))func_001072F8)(c, i, v)) /* DEBT(CAST): funcs.h declares three ints */

int TkMalloc(int v);
int TkFree(int v);
int MsGetSaveCommandMenuPanel(int v);
void func_001BF888(int a, int b);
int func_002F0008(char *buf, const char *fmt, ...);
void func_0014D7B8(char *s);
void func_002D97C8(int v);
extern char D_0056A628[];
extern char D_0056A638[];
extern float D_0058D448[2];

extern u32 D_0058E440;
extern u32 D_0058E488;
extern u32 D_0058E448[16];
extern char D_0056A688[];
extern int D_0058E434;
extern int D_0058E438;
extern int D_0058E43C;
extern int D_0058E940;
extern int D_0058E948[];
extern int D_0058E968[];
extern u32 D_0058E424;
extern void (*D_0058E934)(void);
extern void (*D_0058E938)(void);

extern s8 D_0058E931;
extern int D_0058E408;
extern u8 D_0058E932;
extern s8 D_0058E930;

extern char D_0056A5E0[];
extern char D_0056A5F8[];
int func_00125268(int a, int b, int c);

void Sg_LightGetColor(int i, float *v);
void Sg_LightGetDir(int i, float *v);
#define CALL_func_001382E0(s, v) (((void (*)(const char *, float *))func_001382E0)(s, v)) /* DEBT(CAST): debug-print stub, declared without arguments */
#define CALL_func_001382E8(s, v) (((void (*)(const char *, float *))func_001382E8)(s, v)) /* DEBT(CAST): debug-print stub, declared without arguments */
extern float D_0058E5C0[4];
extern float D_0058E5D0[4];
extern float D_0058E5E0[4];
extern float D_0058E5F0[4];
extern float D_0058E600[4];
extern float D_0058E610[4];
extern float D_0058E620[4];
extern char D_0056A650[];
extern char D_0056A658[];
extern char D_0056A660[];
extern char D_0056A668[];
extern char D_0056A670[];
extern char D_0056A678[];
extern char D_0056A680[];

extern int D_00325A34;
extern int D_003258F4;
extern int D_00326404;
extern int D_00325A94;
extern int D_0032586C;
extern int D_00325ABC;
extern int D_00325D54;
extern int D_00326024;
extern int D_0032605C;
extern int D_00326164;
extern int D_0032631C;

void func_002996E0(Chr *key);
#define CALL_op_et_bindeff2(c) (((void (*)(Chr *))op_et_bindeff2)(c)) /* DEBT(CAST): funcs.h declares this without its argument */

typedef struct ActorBits38 { unsigned lo : 5; unsigned b5 : 1; unsigned b6 : 1; unsigned b7 : 1; unsigned hi : 24; } ActorBits38; /* DEBT(CAST): bit view of the word at Actor+0x38 */
#define ACTOR_BITS38(a) ((ActorBits38 *)&AQ(a)->w38)

extern u32 D_0058E93C;

typedef struct Fmt138 { u8 p0[4]; int w4; int w8; int wC; int w10; float f14; int w18; int w1C; int w20; int w24; int w28; int w2C; int w30; int w34; int w38; int w3C; } Fmt138; /* DEBT(NAME): header of the data blob handled by 0x138D60.. (offsets only) */
typedef struct Sub138 { u8 p0[4]; int w4; int w8; int wC; u8 p10[0x34]; float f44[1]; } Sub138; /* DEBT(NAME): sub-block of Fmt138 at +w3C */
extern char D_0056A6A0[];

Fmt138 *func_00138D60(char *p);
Sub138 *func_00138D78(char *p);
float func_00138FC8(char *p);

typedef struct Ent138 { int w0; int w4; } Ent138; /* DEBT(NAME): 8-byte table entry of the 0x138D60 data blob */

extern int D_0058E40C;
extern int D_0058E410;
extern int D_0058E414;
extern char D_0030B900[];
typedef struct Flg210 { unsigned b0 : 1; unsigned rest : 31; } Flg210; /* DEBT(NAME): flag word at +0x210 of the block behind D_0058E3D8 */
typedef struct Ent3D8 { int w0; int w4; int w8; u8 pC[2]; u8 bE; u8 bF; } Ent3D8; /* DEBT(NAME): four 16-byte entries at +0x64 of the block behind D_0058E3D8 */
typedef struct Sys3D8 { u32 flags; u8 pad4[6]; u16 hA; u16 hC; u8 padE[0x14 - 0xE]; u16 h14; u16 h16; u16 h18; u16 h1A; u8 pad1C[0x2C - 0x1C]; int w2C; int w30; char *p34; char *p38; u8 pad3C[8]; int w44; char *p48; u8 pad4C[0x54 - 0x4C]; int (*f54)(Actor *a, u32 off); u8 pad58[8]; int (*f60)(void); Ent3D8 ent[4]; u8 padA4[0x1E4 - 0xA4]; u8 b1E4; u8 pad1E5; u8 b1E6; u8 pad1E7; u16 h1E8; u8 pad1EA[0x204 - 0x1EA]; int w204; u8 pad208[8]; Flg210 f210; u8 pad214[4]; float cur[4]; float prev[4]; } Sys3D8; /* DEBT(NAME): block at *D_0058E3D8, only the used members */
extern Sys3D8 *D_0058E3D8;
void func_00172FC8(int a, int b);
void func_00172F80(int a, int b);
void TkSetEventJumpMapNo(int a, int b);
void func_00139700(int a, int b, int c);

void func_001397F0(char *p, int b, int c);
void func_00149080(int a, int b, int c, int d, int e);
void func_00136430(float v);
void func_00139A00(char *p, int b);

typedef struct TblEnt138 { u16 a; u16 b; int pad; } TblEnt138; /* DEBT(NAME): 8-byte entry */
typedef struct Tbl138 { int n; TblEnt138 e[1]; } Tbl138; /* DEBT(NAME): table returned by func_001392C8 */

int func_00124BC8(void);
int func_00124BE8(void);
int func_00124C08(void);
int func_00124C28(void);
int func_00124C48(void);
int func_00124CA8(void);
int TkGetNowEventJumpMapNo(void);
int func_00124C88(void);
void func_00139D48(int a, int b, int c);
#define CALL0_AtelChangeCurrentCtrl() (((int (*)(void))AtelChangeCurrentCtrl)()) /* DEBT(CAST): funcs.h declares a parameter the original caller does not pass */

void func_0013A510(u8 *d, const u8 *s);

#define CALL0_AtelGetBasicWork() (((Actor *(*)(void))AtelGetBasicWork)()) /* DEBT(CAST): funcs.h declares an id parameter the original caller does not pass */
char *func_0013A468(char *p);
char *func_0013A470(void);
void *AtelGetCtrlWork(int i);
char *func_0013A7E0(char *p, int i);
char *func_0013A7F8(char *p, int i);
int func_0013A810(char *p, int i);

typedef struct Q1D450 { u8 d[0x238]; } Q1D450; /* DEBT(NAME): 0x238-byte element of D_0058D450 */
extern Q1D450 D_0058D450[];

typedef struct Ofs8 { u16 off; u16 h2; int w4; } Ofs8; /* DEBT(NAME): 8-byte offset-table entry */

extern u16 D_0058E988;
extern u16 D_0058E98A;
extern u16 D_0058E98C;
extern u16 D_0058E98E;
extern u16 D_0058E990;
extern u16 D_0058E992;
extern int D_0058E994;
extern int D_0058E99C;
char *func_0013A820(int a, int b, int c);

extern EffectQ D_0058E630[][8];
extern char D_0030B8C0[];

int func_00138C68(void);

extern char D_0030B908[];
char *func_0013A2E8(char *p, int k);

u16 *func_0014B4F8(int type);
void func_0013A3B8(Actor *a, int b, int i, int v);

int AtelGetActorNumber(Actor *a);
int AtelGetLineNumber(Actor *a);
int AtelGetELineNumber(Actor *a);
int AtelGetBgNumber(Actor *a);
int AtelGetNamespaceNumber(Actor *a);
int AtelGetActorBufferSize(Actor *a);

int AtelSetUpMesWin(Effect *e, int flags);

void func_00124CC8(int a, int b);
void MsBattleExeClear(void);
void func_00117E18(int v);
void func_00117E08(int v);
void func_00138B58(void);

typedef struct EvGameStateW { int flags; u8 pad4[0x20C]; int w210; } EvGameStateW; /* DEBT(CAST): signed-flags view of the block at D_0058E3D8 */

#define EVW() ((EvGameStateW *)D_0058E3D8) /* DEBT(CAST): see EvGameStateW */

extern char D_0056A6A8[];
extern char D_0056A6E0[];
extern char D_0056A6C0[];
int AtelGetMapIndex(char *p, int i);

/* DEBT(CAST): accessor view of the object handled by 0x13B068..0x13B330; members the shared Actor leaves as padding */
typedef struct ObjSlotR { u16 h0; u16 h2; s16 h4; u16 h6; float f08; float fC; float f10; int w14; u8 p18[4]; float f1C; float f20; float f24; float f28; float f2C; float f30; float f34; float f38; float f3C; float f40; float f44; float f48; } ObjSlotR;
typedef struct ObjSlotBR { u16 h0; u16 h2; s16 h4; u16 h6; float f08; float fC; float f10; float f14; float f18; float f1C; float f20; float f24; float f28; float f2C; float f30; float f34; float f38; float f3C; float f40; } ObjSlotBR;
typedef struct ObjBindR { u8 p00[0x44]; ObjSlotR *s44; ObjSlotBR *s48; } ObjBindR; /* DEBT(CAST): ActorBind members at 0x44/0x48 */
#define OBJBIND(a, i) ((ObjBindR *)func_0013C9C8((a), (i)))
typedef struct NodeQ { struct NodeQ *next; struct NodeQ *prev; } NodeQ; /* DEBT(NAME): doubly linked list node, next at 0 and prev at 4 */
typedef struct ObjNodeR { struct ObjNodeR *next; u8 p04[4]; u16 h08; u16 h0A; u8 p0C[2]; u16 h0E; u16 h10; u16 h12; u16 h14; } ObjNodeR; /* DEBT(NAME): list node; byte 0xF aliases the high byte of h0E */
/* DEBT(NAME): free-node pool and slot metadata reconstructed from func_001440C8 / func_00143E18. */
typedef struct ObjPoolNode { NodeQ link; u8 payload[0x10]; } ObjPoolNode;
typedef struct ObjPoolSlot { u16 id; u16 count; u8 flags; u8 pad5[3]; } ObjPoolSlot;
typedef struct ObjExtraPool { ObjPoolSlot slot[8]; ObjPoolNode node[16]; } ObjExtraPool;
typedef struct ObjR {
    int *hdr;
    u8 *p4;
    u8 p08[0xC];
    u16 h14;
    u16 h16;
    u16 h18;
    u8 p1A[2];
    u16 h1C;
    u8 p1E[0x28 - 0x1E];
    float f28;
    u8 p2C[0x34 - 0x2C];
    u16 h34;
    u16 h36;
    u32 w38;
    u8 p3C[4];
    int w40;
    u8 p44[0x80 - 0x44];
    struct ObjNodeR *head80;
    u8 p84[4];
    struct NodeQ *p88;
    u8 p8C[0x94 - 0x8C];
    float f94;
    u8 p98[4];
    int w9C;
    int wA0;
    u8 pA4[0xB8 - 0xA4];
    u8 *pB8;
    u8 pBC[0x1C4 - 0xBC];
    ObjPoolNode node1C4[8];
    u8 pad284[0x60];
    ObjExtraPool *extraPool;
    u8 pad2E8[0xF0];
    ObjPoolNode node3D8[16];
    u8 pad558[0x60];
    ObjSlotR slot[9];
    ObjSlotBR slotB[9];
    u8 pAC8[0xAF4 - 0xAC8];
    int wAF4[4];
} ObjR;
#define OBJR(a) ((ObjR *)(a))
int func_0013B068(Actor *a);
int AtelGetBindPCFromID(void);
int func_0013B098(Actor *a);
int AtelGetHideStatusFromID(void);
int func_0013B0C0(Actor *a);
int AtelGetKeepBattlePartyFromID(void);
int func_0013B298(Actor *a);
char *AtelGetIndexWork(Actor *a, int i);
float func_0013B2D8(Actor *a);
int func_0013B318(Actor *a, int i);
void func_0013B328(Actor *a, int i, int v);

void func_0013B3F8(Actor *a, int i, float f);



void func_0013B458(Actor *a, int v);
ObjSlotR *func_0013BCC8(Actor *a);

int func_0013AF90(int id);
float func_0013B7B8(void);
float func_0013B7E0(void);
float func_0013B808(void);
float func_0013B830(void);
float func_0013B858(void);
int AtelIsBind(int id);
int func_0013B8C0(int id, int idx);
Chr *func_0013B150(int id);
int func_0013B1A8(int id, int idx);
int func_0013B210(int id, int idx);
void graphicPreviousLevelGetNameHash(Chr *c, float x, float y, float z);

void func_0013BCE0(Actor *a, float x, float y, float z);
void func_0013BD60(Actor *a, float x, float z);

void func_0013BF20(Actor *a, int n, int mask, int flags);

void Ch_SetPos3(Chr *c, float x, float y, float z);

/* DEBT(CAST): script-resource reader used by 0x13C9C8..0x13CE70: a header of table offsets plus the data blob it indexes */
typedef struct ScrHdrQ { u8 p00[0x14]; int o14; u8 p18[8]; int o20; int o24; int o28; int o2C; int o30; } ScrHdrQ;
typedef struct ScrBlobQ { u8 p00[0x20]; int o20; u8 p24[0xC]; int o30; } ScrBlobQ;
typedef struct ScrQ { ScrHdrQ *hdr; ScrBlobQ *blob; } ScrQ;
typedef struct ScrEntQ { u8 p00[0x10]; u16 h10[4]; char *p18; u8 b1C; s8 b1D; u8 b1E; } ScrEntQ;
typedef ScrEntQ ScrEntQ2;
typedef struct StkQ { int n; int v[0x14]; u8 tag[0x14]; } StkQ; /* DEBT(CAST): operand stack of the script VM, as seen from a ScriptCtx pointer */
void func_0013C308(int v);
void func_0013C330(void);
void func_0013C340(int *w, int a, int b);
void func_0013C710(int *w, int a);
void func_0013C920(int *w);
int func_0013CA30(ScrQ *s, int i);
int func_0013CA50(int id, int i);
int func_0013CA80(ScrQ *s, int i);
int func_0013CAA0(int id, int i);
void func_0013CAD0(ScrQ *s, ScrEntQ2 *e, int off);
int func_0013CB48(ScrQ *s, ScrEntQ *e);
char *func_0013CBF8(ScrQ *s, ScrEntQ *e);
char *func_0013CC00(ScrQ *s, int off);
char *func_0013CC18(ScrQ *s, int i);
int func_0013CC40(ScrQ *s, int i);
int func_0013CC60(ScrQ *s, int i);
int func_0013CC80(ScrQ *s, int i);
int func_0013CCA0(int v);
int func_0013CCA8(int flag, u8 *p);
int func_0013CD18(ScrQ *s, ScrEntQ *e);
int func_0013CE70(int a, StkQ *k);
int func_0013AB38(int a, int b);

int func_0013CF40(Actor *a, ScriptCtx *ctx);

void func_0013CAF0(int id, int slot, int off);
void func_0013CB60(ScrQ *s, ScrEntQ *e, int i);
void func_0013CD40(ScrQ *s, ScrEntQ *e, int c);
void func_0013CDC8(int id, int off);

int AtelCheckCallbackQue(int i);
int AtelExecCallbackQue(int i);
void func_0013C000(Actor *a, int slot, int p, int q);
void func_0013C170(Actor *a, int p, int q, int h);
void AtelExecCtrlEvent(int *w);

void func_0013C0E0(Actor *a, int p, int q, int h);

extern char D_0056A860[];
extern char D_0056A878[];
int func_00140B48(Actor *a, int c, int d);
void AtelDecodeSignal(int i, int v);
void AtelExecInitFunc(u32 *p);

int AtelGetCtrlworkActorTotal(char *p);

extern float D_0058E590;
int func_002D4850(float w, float x, float y, float z);
void TkMtCalcSpline_f(int a, int *b, int c, float f) __asm__("TkMtCalcSpline"); /* DEBT(CAST): funcs.h omits the float argument; same symbol, distinct prototype */
void func_002D5188_f(int a, int *b, int c, float f) __asm__("func_002D5188"); /* DEBT(CAST): funcs.h omits the float argument; same symbol, distinct prototype */
void func_002D5450_f(int a, int *b, int c, float f) __asm__("func_002D5450"); /* DEBT(CAST): funcs.h omits the float argument; same symbol, distinct prototype */
void func_002D5448_f(int a, int *b, int c, float f) __asm__("func_002D5448"); /* DEBT(CAST): funcs.h omits the float argument; same symbol, distinct prototype */
int func_0013D068(Actor *a, int i);
int func_0013D098(ScrQ *s, int i);
int func_0013D0B8(ScrQ *s, int i);
int func_0013D0D8(unsigned n);
void func_0013D5D8(Actor *a, ScriptCtx *ctx, int idx, int v);
void func_0013D680(Actor *a, ScriptCtx *ctx, int idx);
void func_0013D688(Actor *a, ScriptCtx *ctx, int idx);
int func_0013D790(int *p);
void func_0013D798(int *p, int v);
void func_0013D7A0(int *p);
float func_0013D818(Actor *a);
void func_0013D830(int id, float f);
void func_0013D858(float f);
int func_0013D868(Actor *a, float w, float x, float y, float z);
int func_0013D8D0(Actor *a, float w, float x, float y, float z);
void func_0013D928(int a, int *p, float f);
void func_0013D960(int a, int *p, float f);
void func_0013D998(int a, int *p, float f);
void func_0013D9D0(int a, int *p, float f);

ObjNodeR *func_0013D7A8(Actor *a, u8 *op);

float func_0013D4C8(Actor *a, int idx, int v);
int func_0013D410(Actor *a, int idx, int v);

void func_0013D6D8(Actor *a, ScriptCtx *ctx, int idx);
int func_0013D120(Actor *a, int idx, int n);

typedef struct StateQ { float x, y, z; u8 p0C[4]; float px, py, pz; } StateQ; /* DEBT(CAST): ActorState members at 0x10..0x18 that the shared type leaves as padding */
#define STATEQ(s) ((StateQ *)(s))
void func_0013DA08(); /* DEBT(TYPE): defined as (Actor *a); func_00140468 passes a second argument */

void Ch_SetPos(Chr *chr, float x, float z);
void AtelSetPos(Actor *a, int flag, float x, float z);

void MsCameraSetRect(int a, int b, float *v);
void AtelSetPos3d(Actor *a, int flag, float x, float y, float z);

float func_00110288(Chr *chr);
void func_0013E850(Actor *a);
void func_0013E8A8(Actor *a);
void func_0013E908(Actor *a);
void func_0013E968(Actor *a, void *op);
void func_0013EB88(Actor *a, float x, float y, float z);

typedef struct Req142 { int w0, w4, w8, wC, w10; } Req142; /* DEBT(NAME): request block built on the stack by the 0x142530/0x1425E0 wrappers */
int AtelDecodeCommand(int id, int c);
void func_00142190(NodeQ *p, NodeQ *n);
void func_001421B0(NodeQ *p, NodeQ *n);
void func_001421F8(NodeQ *n);
void func_00142218(Actor *a, NodeQ *n);
void AtelDeleteSignal(int id, NodeQ *n);
int func_001422A0(Req142 *r, int x);
int AtelRegistSignal2(Req142 *r);
int func_00142530(int a, int b, int c, int d, int e);
int func_00142560(Req142 *r);
int func_001425E0(int a, int b, int c, int d, int e);

int func_00142610(Req142 *r);
void func_001426B8(Actor *a, ObjNodeR *n);
void func_001426F0(Actor *a, ObjNodeR *n);
int AtelGetRequestLevel(int id);
int func_00142748(int id, int x);



int func_00142530_k() __asm__("func_00142530"); /* DEBT(CAST): same symbol without a prototype, so the five-argument call keeps its sibcall form */

int func_00142988(Actor *a, int b, int c);
void AtelSkipReqLevel(int id, int x);
int AtelGetActorType(int id);
void AtelExecReturn(int id, int b, int c);
void AtelExecReturn2(int id, int b, int c);
void func_00142F88(int id, int b, int c);

void func_00142988_v(Actor *a, int b, int c) __asm__("func_00142988"); /* DEBT(CAST): same symbol seen as returning nothing, so the caller keeps its tail call */

typedef struct SlotCQ { u8 p0[0x1D]; u8 b1D; u8 p1E; u8 b1F; u8 pad20[8]; int pending; u8 pad2C[0x10]; u16 h3C; u16 h3E; u16 h40; } SlotCQ; /* DEBT(CAST): bind-slot members at 0x3C..0x40 */
typedef struct Res588Q { u8 p0[0x1F8]; int *a1F8; int *a1FC; } Res588Q; /* DEBT(CAST): resource returned by AtelGetCtrlWork, tables at 0x1F8/0x1FC */
void func_001458B0(int id, int a, int b, int c);
void func_00141FF0(Actor *a, SlotCQ *s);

void func_00142B50(Actor *a, SlotCQ *s, int n);
void func_00142070(Actor *a, ObjNodeR *n);

void func_00142C40(Actor *a, ObjBindR *b, int n);

typedef struct Rec124828F { u8 p0[0x10]; unsigned lo : 25; unsigned b25 : 1; unsigned b26 : 1; unsigned hi : 5; } Rec124828F; /* DEBT(NAME): flag word at +0x10 of the func_00124828 record */
#define REC124828F() ((Rec124828F *)((Rec124828 *(*)())func_00124828)()) /* DEBT(CAST): funcs.h declares an index parameter the original caller does not pass */
void func_00143270(int v);
int func_001432B8(void);

int MsBattleCheck(void);
int func_00173690(void);
int func_001432E0(void);

int func_00143AF8(void);
void func_00143BD0(void);
int AtelGetMyWorkSize(int id);
void func_00143C60(Actor *a);
void func_00143CD8(int id, int v);
void AtelInitInternalActorWork(int id);

extern int D_0058E3DC;
void func_00142FF0(int id, float *px, float *py, float *pz);
int func_00143DB8(Actor *a);
void func_00143E18(Actor *a);
void func_00143E78(Actor *a);

typedef struct PoolEntQ { u16 h0; u16 h2; u8 b4; u8 p5[3]; } PoolEntQ; /* DEBT(NAME): 8-byte entry of the pool at Actor+0x2E4 */

/* DEBT(TYPE): callers use only the side effects; no return-value contract recovered. */
void func_0013EF90(Actor *a, void *op, u16 id, PoolEntQ *entry);

void func_001430B0(int id, float *a, float *b, float *c);
void func_00143608(int id, float x, float y, float z);
int func_00143910(int id, int b, int a);
int func_00143988(int id, int off);

void func_00143A00(int id, int slot, int a, int b, int c);
void func_00143AE8(int id, int slot);
int func_00143B30(int id, int off);

void func_001436A8(int id, float x, float y, float z);
void func_00143748(int id, int mode, float *a, float *b, float *c);
void func_00143850(int id, int mode, float x, float y, float z);

void *AtelGetCtrlWork_0(void) __asm__("AtelGetCtrlWork"); /* DEBT(CAST): the original caller passes no index */
Effect *AtelGetMesWinWork_0(void) __asm__("AtelGetMesWinWork"); /* DEBT(CAST): the original caller passes no id */
typedef struct ResQ2 { int w0; u8 p4[0x44]; int w48; } ResQ2; /* DEBT(CAST): resource returned by AtelGetCtrlWork, members at 0 and 0x48 */
u8 *AtelGetBattleIdAdrs(int id);
void func_00144938(void);
void func_001449D0(int i);
void func_00144A90(void);
int func_00144AC8(void);

void AtelSetSndCameraPos(void);

void func_00145E58(Actor *a);
void func_00145EC0(Actor *a, int v);

#endif
