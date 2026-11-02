#ifndef FFX_U2_H
#define FFX_U2_H

/* Declarations added by worker u2 (chunks listed under "u2" in config/ws_assign7.json). */

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* c_1A2D58 */
int func_001B6E48(int id, float *out); /* DEBT(TYPE): defined with u8 id in c_1B6B40.c; callers here pass int unmasked */
float func_001A3200(float a);
float func_002E93A0(float a); /* DEBT(NAME): libm-like helper (atan?) */

/* c_1A65E0 */
int func_001A65E0(int id);

/* c_1E08F0 */
void MsSystemMessageOpen(int a);

/* c_1C7090 */
void MsThreatProcess(int id, BtlChr *c);

/* c_1E1930 */
extern char D_0056F8D0[]; /* source file name string passed to user_malloc */
void Ch_RegMotionEntryCache(s32 h);
void func_001E1AA8();

/* c_1E5EF8, c_1C3578, c_1DC060 */
int MsDeathEffectStart(int id, int kind);
int MsGetRndChr(int id, int b);
int MsGetCommandUse(int id, int k);
extern s8 D_0031732D; /* also in s4.h */
extern s8 D_0031732C; /* also in s4.h */
extern s8 D_00317321; /* also in s4.h */

/* c_1B8BC8, c_1DF4E8, c_1E08F0 */
int func_001B9578(int n);
void MsAtelRequestAdd(int a, int b, int c, int d);
int MsAtelRequestExe(int a, int b, int c, int d, int e, int f);
void func_001B60F8(s32 h);

/* c_1B0528, c_1E2968 */
int MsBtlReadCueRegistWeapon(int p);
void MsBtlReadCueRegist(int a, int b, int c, int d, int e);
OfsTbl *MsGetCommand(int id, int a, int b, void *c, int *d);
void TOBtlInitTidusLimitWindow(void);
void TOBtlOpenTidusLimitWindow(int a);
void TOBtlInitAuronLimitWindow(void);
void func_0021AEB0(int a);
void TOBtlInitLuluLimitWindow(void);
void func_0021BAB8(int a);

/* c_1E8F58, c_1E9F68 */
int func_001B81E8(u8 id, int mask);

/* c_1DAF08 */
int MsDamageCheckDeath(int a, int b, int c, int d);
void func_001C7DC0(int a, BtlChr *c, int n, int x, int y, int flags);

/* c_1CB4E0: debug overlay format strings */
extern char D_0056E7B8[];
extern char D_0056E7D8[];
extern char D_0056E7F0[];
extern char D_0056E800[];
extern char D_0056E818[];
extern char D_0056E830[];
extern char D_0056E848[];
extern char D_0056E858[];
extern char D_0056E870[];
extern char D_0056E890[];
int MsSEPtransCheckWave(void);
int MsGetEndBattleStatus(int a);
int func_002D87D8(void);
int MsGetSummonEnergy(int a);
int MsCheckChrMotionAll(int a);

/* c_1CD748, c_1D1DF8 */
int MsAtelRequestCancel(int a, int b, int c);
void func_001D2958(int id);

void Ch_NeckSetTarget(Chr *chr, s32 v);
typedef struct U2Fx { u8 pad0[4]; void (*f4)(int a); } U2Fx; /* DEBT(NAME): object behind BtlChr.fC4C, only the callback at +4 is known */

typedef struct U2Stats { s32 b[8]; s32 w20; s32 w24; } U2Stats; /* DEBT(NAME): stat block filled by MsGetChrAbilityMap */

/* c_1DD2D0 */
extern s32 D_00662DFC; /* sizes and buffers of two resident files loaded by MsFieldItemRead */
extern s32 D_00662E04;
extern char D_0056F7B8[];
extern char D_0056F7C0[];

/* c_1E9F68, c_1BE1F8 */
extern char D_0056FC98[];
extern s8 D_0031731A; /* also in s4.h */
void MsReturnParty(void);

/* DEBT(TYPE): BtlChr seen from +0x200 (the original code reaches these members through a sub-struct at 0x200;
   offsets below are relative to it: 0x52 = BtlChr.item252, 0x90 = f290, 0x198 = f398) */
typedef struct BtlChr200 {
    u8 pad0[0x52];
    u8 b52;
    u8 b53;
    u8 pad54[0x7B - 0x54];
    u8 b7B;
    u8 b7C;
    u8 b7D;
    u8 pad7E[0x90 - 0x7E];
    s32 w90;
    s32 w94;
    u8 pad98[0x198 - 0x98];
    u8 b198;
} BtlChr200;

/* c_1E08F0 */
int Ch_ModelPurgePacket(Chr *c, int a);

/* c_1C7090, c_1D1DF8 */
int func_001C7BE0(int id);
int func_001D2420(int id, BtlChr *c);
void MsSetEternalRelife(BtlChr *c);
void func_001B7518(Chr **p, float v);

/* c_1E4E08 */
u8 *MsGetTargetList(int id, int *n);
int func_001E5538(int id);

/* c_1CE790, c_1E1930, c_1C7090 */
void MsStatusEffect(int id, BtlChr *c, Ent4 *e, int on, s32 *w);
int MsGetColorStatus(int id);
void op_et_astatus_effect_change(Chr *chr, int v);
typedef struct U2Act { u8 b0; u8 pad1[7]; u16 key[2]; u8 padC[4]; s32 w10; } U2Act; /* DEBT(NAME): argument of MsCalcCostCTB */
typedef struct U2Key { u16 key; u16 h2; u8 pad4[4]; s32 w8; } U2Key; /* DEBT(NAME): lookup key handed to MsGetCommand */

/* c_1B0528 */
extern char D_0056E248[];
void func_001B07A8();
s32 *func_001E4A30(u32 i);

/* c_1BF2B8, c_1CB4E0 */
u8 *MsSaveItemTypeBuffer(int *n);
int MsGetCursorTarget(int id, int kind, OfsTbl *t, int k, int arg);
int func_001CC7E8(int r);

/* DEBT(TYPE): this legacy caller supplies the battle character as an extra argument. */
#define CALL_MsStoneMove_CHR ((int (*)(int, BtlChr *))MsStoneMove)
void MsEffectEndMotion(int id, int value);
/* DEBT(TYPE): preserve the legacy implicit-int call view in the reset loop. */
#define CALL_MsEffectEndMotion_INT ((int (*)(int, int))MsEffectEndMotion)

#endif
