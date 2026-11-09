#ifndef FFX_S6_H
#define FFX_S6_H

#include "common.h"

extern char D_00573DF0[];

int MsEffectReady(int id, int flag);

ScriptSub *opus_no_get(void *obj300, ScriptSub *sub, int id); /* DEBT(TYPE): guessed from caller func_0029DED8 */

extern char D_005753E0[];
extern char D_00575408[];
extern char D_00575438[];

extern int D_00326D98;
extern int D_00326DA4;
typedef struct S6Pt { s16 x; s16 y; } S6Pt; /* DEBT(NAME) */
extern S6Pt D_00326DA0;
extern s16 D_00326DAE;
typedef struct S6Task { u8 pad0[0x1E]; u16 h1E; } S6Task; /* DEBT(NAME) */
typedef struct S6Rpc { int w0; int w4; int w8; int wC; } S6Rpc; /* DEBT(NAME) */
extern S6Rpc D_0069BF00;
extern int D_0069C8C0;
int func_002014E0(int a, int b, int c);
u16 func_00220318(void);
u16 TOMenuGetControlPadRep(void);
u16 TOMenuGetControlPadTrg(void);
int func_002F87A0(S6Rpc *p, int n);
int func_00242900(void);
u8 TkMenuGetCurrentPlayer(void);

int func_00251720(int unused, int a, int b, int c);
typedef struct S6Q4 { int w0; int w4; int w8; int wC; } S6Q4; /* DEBT(NAME) */
extern S6Q4 D_0069C900;
extern int D_0069BFC0;
extern char D_00573770[];
extern char D_005736D8[];

typedef struct S6Ent { u8 pad0[0x10]; u16 h10; u8 pad12[4]; u8 b16; } S6Ent; /* DEBT(NAME): fields from abmap_special_sphere_select_check */

extern char D_005742F8[];
extern char D_00574328[];
extern char D_00574338[];
extern char D_00574340[];
extern char D_00574350[];
extern char D_00574360[];
extern char D_00574370[];
extern char D_00574380[];

/* DEBT(NAME): view of the object at ScriptThread.sub in the 0x2A81D0 opcode handlers (not a ScriptSub) */
typedef struct S6Sub {
    u8 pad00[0x18];
    u8 b18;
    u8 pad19[0x27];
    float f40;
    u8 pad44[0x64];
    int wA8;
    u8 padAC[0xF];
    u8 bBB;
    void *pBC;
    u8 padC0[0x10];
    u16 hD0;
    u16 hD2;
    u16 hD4;
} S6Sub;
int op_et_weapon_afterimage(Chr *c, int a, int b, int d, int e, int f, int g); /* DEBT(TYPE): guessed */
void *op_malloc(void *a, int b);
void op_2point_shadow(void *list, void *a, void *b);
void opus_get_bone_matrix(void *dst, Chr *chr, int id);
void func_002B56D8(void *a, void *b, void *c);

extern int D_0069C8C4;
extern int D_0069C8D0;
extern char D_005737C8[];
long func_002E9C38(long a, long b); /* DEBT(TYPE): guessed 64-bit divide */

u8 *func_001F4260(void *a, int b, int c, int d, int e, int f, int g, int h, int i);
u8 *func_001F5918(void *a, int b, int c, int d, int e, int f, int g, int h, int i);
u8 *func_001F46D0(void *a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
u8 *func_001F3D30(void *a, int b, int c, int d, int e, int f, int g, int h, int i);
void func_002B2A28(); /* DEBT(TYPE): same shape as func_002B2A80 */

u8 *func_001F4178(void *a, int b, int c, int d);
u8 *func_001F4350(void *a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern char D_005738C8[];
extern char D_005738E0[];
extern char D_005738F0[];
extern char D_005738F8[];

extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern int D_00327914;
typedef struct T6_LtCam { u8 pad0[0x30]; float x; float y; float z; } T6_LtCam; /* DEBT(NAME) */
extern HeapMgr D_006A3690[];
extern u8 D_006A39B0[];
extern u8 D_006A3970[];
extern T6_LtCam D_006A3930[];
int _pppRunPart(void *a, int b);
void pppSetMatrix(void);

u8 *func_001F3B60(void *a, int b, int c, int d, int e, int f, int g, int h, int i);

typedef struct S6Pt50 { float x; float y; int w8; float wC; u8 pad10[0x2C]; float f3C; u8 pad40[4]; u16 h44; u8 pad46[0xA]; } S6Pt50; /* DEBT(NAME): 0x50-byte records at lpamng+0x11090 */
typedef struct S6Hdr { u8 pad0[0xC]; s16 x; s16 y; } S6Hdr; /* DEBT(NAME) */
extern u8 D_00327920[];
void *op_oef2_a_get(int a, int b, int c);
int func_00259DB0(float a, float b, float c, float d);

typedef struct S6Row { u8 pad0[0x7834]; u16 h7834; } S6Row; /* DEBT(NAME) */

void func_00262C40(int a, int b, int c, int d, int e);
void func_00262930(int a, int b, int c);

#endif
