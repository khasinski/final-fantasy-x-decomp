#ifndef FFX_Q4_H
#define FFX_Q4_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* q4 area: globals and records first seen in chunks c_1A8850..c_1EC020 */
extern u8 D_0056DFB0[];
extern s32 D_00662628;
extern u8 D_00662CA0[];
extern s32 ZanmatoSep;
extern s32 D_00662E0C;
extern s32 D_00662E10;
extern s32 D_00662E14;
extern s32 D_00662E18;
extern s32 D_00662EE4;
extern s32 D_00662FE0;
extern s32 D_00662FE4;
extern s32 D_00662FE8;
extern struct Q4Node *D_00662FF0;
extern u8 D_00663000[];
extern s8 D_003193EF;
extern s8 D_00319405;
extern u8 D_00319415;
extern u8 D_00663280;
extern u8 D_00663281;

typedef struct Q4Obj176 { u8 pad[0x176]; u8 f176; } Q4Obj176;
typedef struct Q4Link { u8 pad[0xC]; int fC; } Q4Link;

extern s32 D_00662660[];
extern float D_00663200[];
extern s32 D_00663240[];
extern s32 D_003188A0[];
extern u16 D_006632A8;
extern float D_00318804;

void func_002156C0(int);
void MsRegMotionDispose(void);
int MsGetVoiceEventFlag(void);

typedef struct Q4Rec12 { s8 f0; u8 pad1[3]; s32 f4; s32 f8; } Q4Rec12; /* DEBT(NAME): 12-byte records at D_00662D30 */
extern Q4Rec12 D_00662D30[];
extern s32 D_00662D1C;
typedef struct Q4Node { u8 b0; u8 b1; u8 b2; u8 b3; s16 h4; s16 h6; s32 key; struct Q4Node *next; float pos[4]; } Q4Node; /* pos: DEBT(TYPE) length guessed (MsSEP3Dprocess) */ /* DEBT(NAME): list at D_00662FF0 */

/* DEBT(NAME): battle-action style record seen through h14/h16/w1C/h20 by the c_1C3578 damage modifiers */
typedef struct Q4Act { u8 pad0[0x7]; u8 b07; u8 pad8[0xC]; u16 h14; u16 h16; u8 pad18[2]; u16 h1A; u32 w1C; u16 h20; u8 pad22[5]; u8 b27; } Q4Act;
typedef struct Q4Flags { u8 pad0[0xA]; u8 b0A; u8 b0B; u8 pad0C; u8 b0D; u8 b0E; u8 b0F; u8 b10; } Q4Flags; /* DEBT(NAME) */
void func_00110540(Chr *chr, int b, float f);

typedef struct Q4Ent12 { u8 pad0[8]; u8 f8; u8 pad9[3]; } Q4Ent12; /* DEBT(NAME): 12-byte records at D_00662E20 */
extern Q4Ent12 D_00662E20[];
extern s32 D_00662EE0;
extern u16 D_00663288[];
u32 func_001DFD60(u32 id, int b);
int func_001C5A80(int a, int b);
int MsActionRequest(int a, int b, int c, int d, int e, void *f);
void TkChPatchM160(Chr *chr, int v);
int MsDetachWeapon(int a, int b);
void func_001B38E8(int a);
typedef struct Q4Ev { u16 key; u16 v[2]; } Q4Ev; /* DEBT(NAME): 6-byte records at D_00662630 */
extern Q4Ev D_00662630[];
typedef struct Q4Rec1C { u8 pad[0x1C]; } Q4Rec1C; /* DEBT(NAME): 28-byte records at D_00662EF0 */
extern Q4Rec1C D_00662EF0[];
extern s16 D_0031D1DE;
void MsSetRamChr(int a, int b);
int func_001E8DF0(int a, int b, int c);
void MsRelife(int a, BtlChr *chr, int on);
void func_001B09F0(int a);
void func_001B0940(void);
typedef struct Q4Link2 { u8 pad0[0xC]; int fC; int f10; } Q4Link2;
extern s32 D_00317134;
extern s32 D_00662E00;
extern s32 D_00662E08;
int MsSaveItemUse(int a, int b);
int func_001EC5D0(int a, int b);
int func_001CF6F8(int a, int b, int c, int d, int e);
typedef struct Q4Cnt { u8 pad0[0x10]; int w10; int w14; } Q4Cnt; /* DEBT(NAME) */
typedef struct Q4Ev8 { s16 h0, h2, h4, h6; } Q4Ev8; /* DEBT(NAME): 8-byte records at D_00661890 */
extern Q4Ev8 D_00661890[];
int MsSetChrWeak(int a, int b);
s32 MsCameraGet(s32 a, s32 b, s32 c);
typedef struct Q4ObjC { u8 pad0[0xC]; u8 fC; } Q4ObjC; /* DEBT(NAME) */
void Ch_SetPos(Chr *chr, float x, float z);
void func_00299218(Chr *chr);
int op_et_eff(int a, int b, int c, int d);
void Ch_SetPos3(Chr *chr, float x, float y, float z);
BtlChr *MsGetWeaponSpecial(int kind, int flag);
extern float D_00318808;
int MsSetChrSpecular(int id, int a, float f);
void func_001E2560(int id);
void MsSetChrHeight(int id);
float MsGetChrHeight(int id);
float MsGetChrWidth(int id);
float MsGetChrCamWidth(int id);
float MsGetChrCamHeight(int id);
float func_001B7448(int id);

/* Data used by the newly recovered script/debug helpers. */
extern char D_0056F7E0[];

#endif
