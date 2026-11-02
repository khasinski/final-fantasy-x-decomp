#ifndef FFX_R3_H
#define FFX_R3_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* r3 area: globals/prototypes first needed by chunks c_1BB140..c_1ED130 */
extern u8 D_0031D22B[];
extern u8 D_0031D39C[];
extern u8 D_0031D59C[];
int func_001E7D80(Actor *a, void *u, ScriptCtx *c, int flag);
BtlChr *func_001ECB50(Actor *a, void *b, ScriptCtx *c, float f);
extern s32 D_00662EE8;
extern s8 D_00317318;
extern s8 D_00317319;
void MsGetChrBtlPos(int id, float *v);
int MsSetChrPosReset(int id, float *v);
void func_00104EA8(void);
typedef struct Q4Slot2D8 { u8 pad0[2]; u8 b2; u8 pad3[0x2D5]; } Q4Slot2D8; /* DEBT(NAME) */
void MsNumberRegist(); /* DEBT(TYPE): callers pass 6 or 7 arguments */
extern u8 D_00662CC8[];
extern s32 D_00662CC0;
extern s32 D_00662CBC;
extern s32 D_00662D20;
extern s32 *D_00662D24;
extern char D_0056F6A8[];
extern u8 D_00662D10[];
extern char D_0056FA38[];
extern char D_0056FA58[];
typedef struct Q4Bits2C { u16 bits[22]; } Q4Bits2C; /* DEBT(NAME): 0x2C-byte records at D_0031F504 */
extern Q4Bits2C D_0031F504[];
extern char D_0056FA20[];
extern char D_0056FA78[];
int MsGetChrEscapePos(int id, int v);
float MsNearRag(float a, float b);
void MsBattleLabelExe(int a, int b, int c);
void MsSetChrMotionInfo(int id, int a, float f);
int func_001C2C98(int id, int a, int b);
int func_001D5260(int id, int a, int b, int c);
int func_001EB898(Actor *a, int b, int c);
int func_001EC1B8(int id, int a, int b);
int func_001D8CD0(int id);
typedef struct Q4ActB { u8 pad0[0x1E]; u16 h1E; } Q4ActB; /* DEBT(NAME): upper half of Q4Act.w1C */
typedef struct Q4Arg4 { u8 id; u8 kind; u8 pad2[2]; } Q4Arg4; /* DEBT(NAME): 4-byte struct passed by value */
void MsGetDamageInfo(int a, int b, int *x, int *y, int *z);
int func_001D53E0(int id, int a, int b);
int MsSetVoiceCheck(int a, int b, int c, int d, int e);
int MsSetHeadTarget(int a, int b);
int MsAtelRequestCamera(int a, int b, int c, int d, int e, int f, void *g, void *h);
#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif
typedef struct Q4Rec16 { u8 b0; u8 b1; u8 pad2[0x14]; } Q4Rec16; /* DEBT(NAME) */
void yiAssert(int a, const char *b, const char *c, int d);
extern char D_0056E930[];
extern char D_0056E948[];
void MsEventEffectProcess(void);
int func_001CF7D8(int a, int b);
void TOBtlCloseSignWindow(void);
float MsGetMoveTargetDist(int id, int v, int flag);
int MsSetChrDirF(int id, float v); /* DEBT(TYPE): defined with u8 id, callers do not mask */
void func_0014D718(u8 *a, u8 *b);
extern s8 D_00317325;
extern s8 D_00319402;
extern s8 D_00319403;
extern s8 D_0031941A;
void func_001C8740(int a, int b, int c, int d, int e);
u8 func_001D1DF8(int a, BtlChr *c, int d);
void MsUseChrMpLimit(int id);

extern s8 D_00318800;
extern s8 D_00318801;
int MsDeleteCommandCue(int a, int b, int c);
int MsDeleteInputCue(int a, int b, int c, int d);
void MsMoveSplineRegist(int a, int b, int c, void *d);
void op_et_prayeff_send_read_through(int h);
int MsSystemMessageCheck(void);
u32 func_001E0030(int id, int b);
u32 MsRegSEplay2(int id, u32 v);
int func_001DF970(int a, int b);
int MsAutoCommandStatusCheck(BtlChr *c, int b, int d, int e);
extern u8 D_003192BC[7];
void MsBtlChrFree(int id, int v);
void MsGetChrInfo(int a, int b, int c, void *d);
void func_0010A230(Chr *chr, float a, float b);
typedef struct Ent3174A0 { u8 b0; u8 b1; u8 b2; u8 b3; u8 pad4[4]; } Ent3174A0; /* 8-byte entries indexed by BtlChr.fAA4 */
typedef struct Tbl3174A0 { Ent3174A0 e[620]; s8 id; } Tbl3174A0; /* DEBT(TYPE): length guessed from the offset of id (0x1360) */
extern Tbl3174A0 D_003174A0;
void MsMessageCueRegist(int a, int b, int c, int d, int e);
int MsActChangeCommand(int id, int a, int b);
float MsGetChrGround(int id); /* DEBT(TYPE): defined with u8 id in c_1B4900.c; callers here pass the int unextended */
float func_001AC348(float *a, float *b);
float func_001AC388(float *a, float *b);
int func_001CF558(int id, int a, int b);
int func_001CF4B0(int id, int a, int b);
void MsSetTargetDir(int a, int b);
extern char D_0056FA90[];
extern char D_0056FAB0[];
void MsSetChrTransparentVisible(int id, float f1, float f2, int a, int b);
int func_001E1020(int id, int a, int b);
int func_001B2DF0(int a, int b, Actor *act, int *out);
int ms_motion_trans(BtlChr *c, int v);
void MsActCommandAdd(int id, int a, int b, int c, int d);
int MsActTargetSearch(int a, int b, int c, int d, int e, int f, int g, int *out);
float func_001D3B10(int id, int v);
void func_0010A1F8(Chr *c, float *v);
extern char D_0056FD18[];
int MsCheckUseCommand(int id, OfsTbl *t, int v);
void MsMoveSpline(int a, int b, int c, float f, int d);
extern s8 D_0031732B;
extern char D_0056FB38[];
extern char D_0056FB88[];
int MsRegistCommandCue(int id, u8 *p, int a, int b, int c);
int MsSetBtlCommand(u8 *p, int a, int b);
void MsGetMoveTargetPos(int id, BtlChr *c, int a, float *out, int b);
int func_001EB048(int id, int a, int b, int c, int d, int e);
void MsCameraFree(int h);
/* DEBT(NAME): command work has a count at zero and a 0x210-byte stride, indexed by channel 0..2. */
typedef struct BtlCommandWork { int count; u8 pad4[0x20C]; } BtlCommandWork;
extern BtlCommandWork D_00662670[3];

void func_001CD900(int id, BtlChr *chr);

void MsProvOff(int id);

#endif
