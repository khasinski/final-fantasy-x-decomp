#ifndef FFX_S5_H
#define FFX_S5_H

#include "ffx/types.h"
#include "ffx/text.h"

extern s32 D_0069BCEC;
/* DEBT(TYPE): func_00249AA8 calls it without setting $a0, so the caller sees no prototype */
int func_0024AE38();
extern s32 D_0069BCE8;

extern u8 D_0069A690[99];
extern s32 D_0069A670;

extern char D_00326E50[], D_00326E60[], D_00326E70[], D_00326E80[], D_00326E90[], D_00326EA0[];
extern char D_00326EB0[], D_00326EC0[], D_00326ED0[], D_00326EE0[], D_00326F58[];
extern s32 D_003263E0;
void TkMenuSetHelpMessage(int a);
void func_00232398(void);
u16 func_00220318(void);
u16 TOMenuGetControlPadRep(void);
u16 TOMenuGetControlPadTrg(void);

extern s32 D_0069BD00[2];
extern s32 D_0032643C;
extern char D_00573240[], D_00573248[], D_00573250[], D_00573258[], D_00573260[], D_00573268[];
void func_0020DC20(int a);

void func_0022B598(Task *o);

Task *TOMenuGetYesNoWindow(void);
int func_00236228(Task *t);
void TOMenuCloseYesNoWindow(void);
extern char D_00694000[];
extern s16 D_003260C2;

/* 4-byte script record walked by func_0024CD78 (DEBT(NAME): fields named by use) */
typedef struct ScriptRec { u8 op; u8 flag; u16 id; } ScriptRec;
extern s16 D_0069BE72;
extern s32 D_00693FF8;
int func_0020CDB8(void);
void func_0020CD30(int a, int b, int c);
Task *func_00224608(void);
int func_00224910(void);
void func_00224920(int a);
void func_00224698(void);
extern char D_005712E0[];

/* 8-byte rows (4 x u16) copied by func_00227FD8 */
extern u16 D_0036E878[][4], D_0036E888[][4], D_0036E8D8[][4], D_0036E898[][4], D_0036E8A8[][4], D_0036E8B8[][4], D_0036E8C8[][4], D_0036E8E8[][4], D_0036E8F8[][4], D_0036E908[][4], D_0036E918[][4], D_0036E928[][4], D_0036E938[][4], D_0036E958[][4], D_0036E948[][4], D_0036E968[][4], D_0036E978[][4], D_0036E988[][4];
Unk1BFED8 *TkSetLegendAbility(int id);

int TkCdReadSync(int v);
void TkCdReadNB(int a, int b, int c);
int TOMenuAtelStart(void);
void func_002369F0(void);
int TOMenuGetFirstReadEndFlag(void);
int TkMenuGetSummonListMax(void);
void func_00242B18(void);
void func_00242AE0(void);
void func_00225500(int a, s32 *b, s32 *c, s32 *d, s32 *e);

int TkMn2CalcStatusBGRatio(void);
void TMn2SetStatusBGDiff(s16 v);
void TkMenuCloseStatusPageWindow(int a);
Task *TkMenuOpenStatusPageWindow(int a0, int idx, int a2, int a3);

extern s32 D_00325F1C;
extern s32 D_00693F60;
extern s32 D_00693F64;
void func_00235390(void);
int TOSwapInternationalEnvExecNonBlock(void);
void TOSwapInternationalEnvInitMenu(int a);
int TOSwapInternationalEnvExecMenu(void);
void func_00201CD0(void);

/* DEBT(TYPE): prototypes inferred from call sites only */
extern s16 D_00324208;
extern s32 D_0032420C;
extern s32 D_00324210;
extern s16 D_00324214;
extern s16 D_00324216;
extern s16 D_00324228;
extern s16 D_0032422A;
extern s16 D_0032422C;
extern s16 D_0032422E;
extern char D_00571280[];
int func_00125D60(int a);
void TODrawMenuPlateXYWC2_Rfix(int a, int b, int c, int d, int e, int f, int g);
void TOMkpShapeXY(int a, int b, int c);
int func_00221128(int a);
void func_001F63B8(int a, int b, int c, int d);
void func_001FE298(int a, int b, int c, int d, int e, int f, int g);
void func_001F5E80(int a, int b, int c, int d);
int func_00221108(int a);
void func_001F64F8(char *s, int b, int c, int d);

/* DEBT(TYPE): the callers of SndSepPlaySimple were compiled against an int-returning prototype (the result is
   never used, but v0 is treated as clobbered). funcs.h declares it void and its definition in c_2D72F8.c is void
   (owned by another worker), so the int view is applied at the call site. */
#define PLAY_SE(h) ((int (*)(int))SndSepPlaySimple)(h)

#define SYS_TBL2 ((u16 *)0x1D56F00)

int func_00242818(void);
extern u8 D_0069BE6C;
extern u16 D_0069BE68;
extern u8 D_0069BE70[];

int func_00242940(void);
int func_002429D0(void);
void TkMenuFlushSummonCommand(int a);
extern char D_00571B18[];

void func_002429F0(void);
void func_00242980(void);

void TkMenuMainFreeWindowGroup(int a);

/* DEBT(TYPE): same situation as PLAY_SE for TMn2SetStatusBGDiff, which is defined void in c_228AD8.c */
#define SET_ANGLE_I(v) ((int (*)(int))TMn2SetStatusBGDiff)(v)

/* DEBT(TYPE): prototypes inferred from the call sites of TkMn2ArmsRefreshArms only */
int AtelGetTotalActorNumber2(void);
Chr *TkCh_Allocate(int id);
void TkCh_BindToElem(int a, Chr *b, Chr *c, int d, int e);
extern s32 D_00693B70;
extern s32 D_00693AF0[];
extern s32 D_00693B10[];

void TkCh_Dispose(int v);
int Ch_DataReadSync(int v);
int func_0013B068(Actor *a);
int ChN_DataDispose(int, int);
int Ch_DataRead(int);

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_TODrawMenuPlateXYWC2_Rfix_INT ((int (*)(int, int, int, int, int, int, int))TODrawMenuPlateXYWC2_Rfix)

#endif
