#ifndef FFX_V3_H
#define FFX_V3_H

/* Declarations added by worker v3 (chunks listed under "v3" in config/ws_assign8.json). */
#include "ffx/types.h"
#include "ffx/q4.h"

extern char D_0056FBA8[]; /* source file name string passed to user_malloc */

extern s8 D_0031941C;
typedef struct Blk662D28 { u8 pad0[0x810]; s32 f810; } Blk662D28; /* DEBT(NAME): block allocated for c_1D9F08 (matrix at 0x7C0, floats at 0x808/0x844) */
extern Blk662D28 *D_00662D28;
void MsTransSpPos(int a, int b);
void MsSetNormalUpVector(int a);
void op_et_encount_effect_on(int a, u32 b);
void MsScreenResetShake(int a);

extern char D_0056E950[];
void MsBattleError(char *name);

typedef struct V3TxtOfs { u16 ofs; u16 pad; } V3TxtOfs;
typedef struct V3TxtEnt { V3TxtOfs a[7]; V3TxtOfs b[7]; u16 n[7]; } V3TxtEnt; /* DEBT(NAME): entry of the D_00662E18 table, 7 per-language offsets (index from MsGetSaveConfigHiragana) */
int func_002EF240(char *fmt, ...);
extern char D_0056FB50[];
void MsSetRamChrParam(int id);
void MsSetWeaponEffectAttribute(int id, BtlChr *c);

typedef struct Ent48Tbl { GsEnt48 e[62]; s8 f1170; s8 n; } Ent48Tbl; /* view of D_00317690 == &D_003172F0.ent48 up to GameState.f1511 */

typedef struct BtlEvt { s8 b0; u8 b1; u8 b2; u8 b3; u8 b4; s8 b5; s8 b6; s8 b7; u16 h8; u16 hA; u8 bC; u8 bD; u8 padE[2]; struct BtlEvt *next; } BtlEvt; /* DEBT(NAME): 0x14-byte records of the 0x80-entry pool at D_00662D1C, queued on D_00662D20 */

int MsCalcDamageCommand(BtlChr *a, BtlChr *b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern char D_0056F7F8[];
extern char D_0056F800[];

void MsInsertBtlCommand(GsEnt48 *e, int a, int b, int c);
extern s8 D_00319419;
void MsEffectCameraEnd(int flag);
typedef struct CbObj { void *f0; int (*f4)(int); } CbObj; /* DEBT(TYPE): callback result is unused; int matches the call site. */ /* DEBT(NAME): object behind the D_00662614 handle, callback at +4 */

int MsEffectResetMotionDisable(BtlChr *c);
int MsGetFileSize(int a, int b, int c);
extern char D_0056F7D0[];
extern u8 D_0031FF50[8][8];
void SndStartShoutStream(int a, int b, int c);

void func_001D1CE0(u16 *src, u16 *dst, int n);
extern char D_0056E958[];

extern char D_0056FBB0[];
int MsGetCommandTarget(int id, int v, int flag, int d);
void MsInsertInputCue(int id, int a, int b, int c, int d, int e);
void MsInsertCommandCue(int id, GsEnt48 *e, int n, int a, int b, int c, int d);

extern Unk1BFED8 D_0031FCEE[8];
extern Unk1BFED8 D_0031FE9E[8];
extern s32 D_0031FA14;
void MsSetChrPos(int id, float *pos);

extern char D_0056E960[];
extern char D_0056E970[];
void op_et_battle_init(int h);
void MsExchangeChr(int a, int b, int c, int d);
extern s8 D_00319427;
int MsEffectLimitStart(int a, int b);

typedef struct BtlRec434 { u8 pad0[2]; u8 b2; u8 b3; u8 pad4[0x11]; u8 b15; u8 pad16[0x2D8 - 0x16]; } BtlRec434; /* DEBT(NAME): two 0x2D8-byte records at BtlChr+0x434 (the second overlaps the named f7C0.. members) */

typedef struct BtlChrRecs { u8 pad0[0x434]; BtlRec434 rec[2]; } BtlChrRecs; /* DEBT(CAST): view of BtlChr with the two BtlRec434 records */

extern s8 D_00317346;

int MsCheckWrongStatus(Q4Act *act);

int MsGetNextCTB(BtlChr *c, int a, int b, int d);
extern char D_0056F710[];
void func_001DBB60(Q4Link *p);

void func_001B96E8(int id, int a, int b);
void func_001CDB68(BtlChr *c, int a, int b, int d);
void MsEffectCameraCall(int arg, int b);
extern u8 *D_003173D8;

extern s8 D_00317337;

#endif
