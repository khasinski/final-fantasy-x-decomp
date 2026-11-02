#ifndef FFX_U0_H
#define FFX_U0_H
#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"
/* ---- worker u0: chunks c_1008D8 .. c_14C478 ---- */

/* DEBT(NAME): word-array view of the records handled by Ch_RomReadChrCB / func_0014BF70 (callers are function tables) */
typedef struct U0Args { s32 w0; s32 w4; s32 w8; s32 wC; s32 w10; s32 w14; u8 pad18[0xB8 - 0x18]; s32 wB8; } U0Args;

void func_00104F28(int a, int b);
struct R0Heap;
void func_0011BF50(struct R0Heap *h);
void Sg_MemCheckHeap(struct R0Heap *h, void *b, s32 c);
void AtelActorSetUp2(int a, int b, int c, int d, int e, int f, int g);
extern float D_0057F664;
extern s32 D_003038F0;
float func_00119810(void);
typedef struct U0Rec70 { u8 pad00[0x60]; s32 w60; u8 pad64[0xC]; } U0Rec70; /* DEBT(NAME): 0x70-byte records behind Chr.w6F0 */
extern u8 D_0058E9A0;
extern s32 D_0058E3F0;
extern s32 D_0058E3F4;
extern char D_0056ADD8[];
extern char D_0056AE90[];
void func_00146180(void);
void func_00147BA0(void);
int func_00121038(float *v);
int func_002F46B0(char *buf, char *fmt, char *ap);
int func_002EF240(const char *fmt, ...);
/* <stdarg.h> as ee-gcc's va-mips.h defines it for the EE EABI: the unnamed GPR arguments are saved
 * as 8-byte slots just below the incoming argument pointer. */
typedef char *va_list;
#define va_start(ap, last) \
    ((ap) = (char *)__builtin_next_arg(last) - (__builtin_args_info(0) >= 8 ? 0 : (8 - __builtin_args_info(0)) * 8))
#define va_end(ap)
/* EE timer 0 counter (hardware register) */
#define T0_COUNT (*(volatile u32 *)0x10000800)
void func_2035A80(void);
void func_20318A8(void);
void Ch_EffectPacketSetPtr(int v);
void Ch_EffectPacketCreateMain(ChrEnt *e);
void func_0011D998(int r, int g, int b, int a);
void Sg_GsPRIM(s64 v);
void Sg_GsXYZF2(int x, int y);
extern s32 D_00307F34;
extern s32 D_003036A8;
extern char D_00569B58[];
int TkGetControlerBindAnalogIndex(int a, int b, int c);
void func_0019CE30(int v);
extern s32 D_00307F30;
typedef struct U0Ops { int (*invoke)(void *, int, int); int (*fn4)(int a, int b); float (*floatResult)(Actor *, int, ScriptCtx *); int (*intResult)(Actor *, int, ScriptCtx *); } U0Ops; /* DEBT(NAME): record returned by func_0014B8C0 */
void func_0014CED0(int a, int b);
void func_00252768(int a, int b);
int func_00126DA0(Actor *a, void *op, ScriptCtx *ctx);
extern char D_0056A1D8[];
extern char D_0056A1E8[];
typedef struct U0Tbl { s32 n; struct { s32 a; s32 b; } e[1]; } U0Tbl; /* DEBT(NAME): counted table behind Fmt138.wC */
typedef struct U0TblH { s32 n; struct { s32 a; u16 h; u16 pad; } e[1]; } U0TblH; /* DEBT(NAME): counted table behind Fmt138.w18 */
typedef struct U0Blk60 { u64 d[12]; } U0Blk60; /* DEBT(NAME): 0x60-byte block copied by func_00116E50 */
int func_2065BA8(int a, int b, int c);
int func_0012E998(Actor *a, void *op, ScriptCtx *ctx);
void func_001478B8(void);
extern char D_0056AE78[];
extern char D_0056AE80[];
void func_0013BD60(Actor *a, float x, float z);
typedef struct U0Vec { float x, y, z, w; } __attribute__((aligned(8))) U0Vec; /* DEBT(TYPE): 8-byte aligned float vector (copied with ld/sd) */
extern U0Vec D_00580480;
extern float D_0057F688;
extern float D_0057F68C;
extern float D_0057F690;
extern float D_0057F694;
void func_00122BF0(void);
extern s32 D_00580E44;
void func_00124E00(int v);
void func_0014E638(void);
void func_00124E70(void);
#define CALL0_func_00124828() (((Rec124828 *(*)())func_00124828)()) /* DEBT(CAST): the callee reads no argument */
extern s8 D_005661F4;
extern char D_0056A320[];
extern char D_0056A178[];
extern char D_0056A188[];
char *get_hdd_name(int a);
void func_001386A0(int id);
int func_0015A550(void);
u32 func_00138638(void);
void AtelSetPos(Actor *a, int flag, float x, float z);
void func_00149E88(char *p, int v);
void func_00149E00(int v);
int func_00138DF0(); /* DEBT(TYPE): takes the data blob (c_138D78.c); AtelEventLoadMusic passes nothing */
extern char D_0056AF30[];
extern char D_0056AF48[];
extern u64 D_006F2D58;
void func_002B2B30(void *p, int a, int b, int c);
extern u16 D_0058F91C;
void func_00118CD8(void);
Cmd16 *Sg_GsEnd2(void);
void Sg_GsFRAME_16(int a, int b);
void Sg_GsFRAME2_16(int a, int b);
extern s16 *D_00308900;
extern u8 *D_00580B2C;
void func_00120DE8(u8 *a, u8 *b, u8 *c, int d);
void MsCameraInit(void);
void func_00124DA0(void);
void AtelEventSetUp(int v);
void MsCameraGetPosNow(int i, float *out);
void AtelRegistShape(int a, int b);
int func_00139080(char *p);
void func_00104248(int idx, char *str);
extern char D_0057DAA8[];
extern char D_005693E0[];
extern char D_005693E8[];
int func_002F0008(char *buf, const char *fmt, ...);
float func_002D46B0(float a, float b, float c);
typedef struct U0Q1F0 { s32 w0; u16 *p4; u16 h8; } U0Q1F0; /* DEBT(CAST): view of Q1F0Ent (q1.h) where that header is not visible */
#endif
