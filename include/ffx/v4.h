#ifndef FFX_V4_H
#define FFX_V4_H
/* declarations added by worker v4 (chunks c_1EC020..c_221418) */

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* menu message names (rodata strings) */
extern char D_00570CC8[];
extern char D_00570CD0[];
extern char D_00570CE0[];
extern char D_00570CE8[];
extern char D_00570CF8[];
extern char D_00570D00[];

/* same prototypes as in t4.h (not included by these chunks) */
int MsCheckLeftWindow(int id);
int func_00210898();

extern s8 D_003249AD;
/* popup window rectangle (follows the four U3Popup records at D_00692560) */
extern s16 D_006925B6;
extern s16 D_006925B8;
extern s16 D_006925BA;
extern s16 D_006925BC;
void func_001F1D60(int x0, int y0, int x1, int y1);

int MsGetCommandMP(int owner, OfsTbl *ent); /* as in t4.h */
void func_001F35D0(int a, int text, int x, int y, int c);

struct MenuCmd;
s32 func_00202AD8(struct MenuCmd *m);
void func_00203FC0(struct MenuCmd *m);

int AtelGetHyoukaMenuEnable(void);
void func_0020CA38(void);
void TOSeqBuffFlashScene(int i);
void TkMenuStart(int a);
void TOSwapInternationalMessageWindow(void);
extern s32 D_00325798;

/* id lists filled from TOGetSaveWindow (count word, then u16 ids) */
extern s32 D_00692008;
extern u16 D_00692010[];
extern s32 D_00692020;
extern u16 D_00692028[];

/* 0x24-byte menu command definitions: handlers copied into MenuCmd.fn[0..4], fD4, fD8, f10C */
typedef struct V4MenuDef {
    s32 (*fn[5])();
    s32 (*f14)();
    s32 (*f18)();
    s32 (*f1C)();
    u8 pad20[4];
} V4MenuDef;
extern V4MenuDef D_00323648[];
s32 TOGetMessageWindowMode(void);
s32 _TODrawMovieMessageWaitNamesp(struct MenuCmd *m);

extern s16 D_00692478[]; /* text size (w, h) of D_00692480 */
extern s16 D_0069247A; /* height half of the pair above (passed separately to _TOGetMessageWH) */

int MsSetVoice(int id, int a, int b, int c, int d); /* as defined in c_1DF4E8.c */

/* 16-byte per-member records cleared by TOBtlInitEnemyLimit. DEBT(NAME) */
typedef struct V4Bar {
    s32 w0;
    s32 w4;
    u8 pad8[8];
} V4Bar;
extern V4Bar D_006928A8[];
extern s16 D_00324354;
int func_001B7028(int id);

void *TODVDFileReadAuto(const char *name, int id); /* as defined in c_20C700.c */
extern void *D_0066AF40; /* last block returned by TODVDFileReadAuto */

/* 4 x s16 rectangle and 4-byte colour views of MenuSlot members (copied whole by _TODrawWindowHelp) */
typedef struct V4Rect4 {
    s16 v[4];
} V4Rect4;
typedef struct V4Rgba4 {
    u8 c[4];
} V4Rgba4;
typedef struct V4ColRect {
    V4Rgba4 col;
    s16 rc[4];
    u8 pad0C[0x20 - 0x0C]; /* DEBT(PADDING): rest of the record unknown (frame size) */
} V4ColRect;
/* window layout constants (D_00324248..) */
extern s16 D_00324248;
extern s16 D_0032424A;
extern s16 D_0032424C;
extern s32 D_00324250;
extern s32 D_00324254;
extern s16 D_0032425C;
extern s16 D_0032425E;
extern s16 D_00324260;

void TOTransTexture(void);

int MsGetCommandTarget2(int id, int a, int b, int c);
/* debug format strings (rodata) */
extern char D_0056FCE0[];
extern char D_0056FD08[];
extern char D_0056FD10[];

extern char D_00570080[]; /* number format string */

extern s32 D_003241C4; /* window colours */
extern s32 D_003241C8;

int func_00160C20(void);
int func_00160C30(void);
void func_0020C660(int dst, int a, int b, int c, int d, int e, int f); /* as defined in c_20B6A8.c */
/* GS frame-buffer setup (c_20C700) */
extern s32 D_0068F424;
extern s32 D_0068F428;
extern s32 D_0068F430;
extern s32 D_0068F434;
extern s32 D_0068F438;
extern s16 D_003238CC;
extern s16 D_003238CE;

void func_002040F8(int i);
void func_00206860(int r, int c, int v);
void func_00206888(int r, int c, int v);
int TkBtlEndGetText(int a);
extern s32 D_003257A8;

/* icon tables copied to the stack by func_00219688 */
extern V4Rect4 D_00570E38;
extern V4Rect4 D_00570E40;

extern char D_0056FD48[];

void *func_001FE1C8(void *list, int b, int c, int d, int e, int f, u32 g, u32 h); /* as defined in c_1FDD78.c */

s32 TOFuncPadMessageInputValue();

extern V4Rgba4 D_00570A60; /* replacement characters for '-', '.', '/' (func_0020E508) */

/* c_21D038 initialisers */
void func_0021D7A0(int a, int b);
void func_0021D820(void);
void TOBtlMakeTargetGroupBit(void);
void TOBtlMakeTargetChrStatusBit(void);
void func_0021DBF0(void);
void TOBtlMakeTargetTargetBit(void);
extern s32 D_003249A4;

/* icon id tables copied to the stack by func_001FC9B0 */
typedef struct V4IconTbl {
    s16 id[9][4];
} V4IconTbl;
typedef struct V4IconTbl2 {
    s16 id[10];
} V4IconTbl2;
extern V4IconTbl D_00570020;
extern V4IconTbl2 D_00570068;

#endif
