#ifndef FFX_R0_H
#define FFX_R0_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* r0 range (0x1008D8..0x1402F8): callees not declared elsewhere.
   DEBT(TYPE): argument lists and void returns read from the disassembly only. */
void func_0010DF20(void);
void func_0010CA88(void);
void func_0010E2B0(void);
void Sg_MFIFOSync(void);
void func_002D0AD0(void);
void func_002DAC50(void *dst, int n);
void func_002DCE38(void *a, void *b, void *c);

/* the original caller passes no argument to func_0010C780 */
#define CALL0_func_0010C780() (((void (*)(void))func_0010C780)()) /* DEBT(CAST) */

typedef struct R0Obj104158 {
    u8 pad00[8];
    s32 w08;
    s32 w0C;
    u8 u10[0x60];
    u8 u70[0x60];
} R0Obj104158; /* DEBT(NAME): two 0x60-byte blocks at +0x10/+0x70 handed to func_002DAC50 */

typedef struct R0Ent12 { s32 w0; s16 h4; s16 h6; s32 w8; } R0Ent12; /* DEBT(NAME): 12-byte records at D_0057E2B0 */
extern R0Ent12 D_0057E2B0[50];

extern V128 D_003035D0, D_003035E0, D_003035F0, D_00303600, D_00303610, D_00303620;
void func_002DD5A8(void *a, void *b, void *c, void *d, void *e);
void func_002DD4E8(void *a, void *b, void *c, void *d);

void Ch_RomReadEventMGRP(int a, int b);
int func_00113820(int a);
void func_0010D3D0(Chr *chr);
void func_00118150(void);
typedef struct R0Cmd8 { u8 b0, b1, b2, b3; u16 h4, h6; } R0Cmd8; /* DEBT(NAME): same layout as Cmd8 */
extern R0Cmd8 D_005803E8;
extern char D_00569AD0[];

void func_2031678(int a);
extern s32 D_003038E8;
extern char D_00569B78[], D_00569B90[];
int func_0011C000(); /* DEBT(TYPE): takes the block header (Sg_MemCheckPtr); _Sg_MemCheckMCBerr passes nothing */
void yiAssert(int a, char *b, char *c, ...); /* DEBT(TYPE): some callers pass a 4th argument, some do not */
void func_00138BF8(int v);
typedef struct R0Pkt { u32 w0; u32 w4; u64 q8; } R0Pkt; /* DEBT(NAME): 16-byte packet header written by func_0010B978 */

int func_00104A88(int a, int b, int c, int d);
void Cache_Entry_NotYet(int a, int b, int c);
void func_00111AA0(void);
int Sg_GetFocus(int a);
void _Sg_MemDump(void *heap);
typedef struct R0Blk { struct R0Blk *end; struct R0Blk *next; u32 w08; u32 flags; } R0Blk; /* DEBT(NAME): 16-byte heap block header; end = start of the following block */
typedef struct R0Heap { s8 b00; u8 flag01; u8 pad02[6]; u8 *p08; R0Blk *first; R0Blk *last; u8 pad14[4]; } R0Heap; /* DEBT(NAME): 0x18-byte heap descriptor */
extern R0Heap D_005808C8[3];
extern R0Blk *D_005808D8;
extern u8 D_00569C70[];
extern u8 *D_00580930;
extern char D_00569D50[];
typedef struct R0Blk32 { V128 a, b; } R0Blk32;

typedef struct R0Sort { u8 pad00[4]; s32 w04; u8 pad08[4]; u8 b0C; } R0Sort; /* DEBT(NAME): record compared by func_00119F30 */

void func_002E9C18(int a);
void func_0011BE48(void);
void SgStrdupD(int a, int b);
void Sg_MainInit(void);
void Sg_MainLoop(void);
/* the original caller passes a second argument that func_0011CB08 ignores */
void func_0011CB08(); /* DEBT(TYPE): defined with one AllocHdr * parameter in c_11C0B0.c; func_0011C140 passes a second argument */

void func_001385F8(void);
int func_001458A8(void);
void func_002D3AA8(int a, int b);
void func_002D24F8(void);
void func_2064640(void);
void func_002DDE58(void);
void func_00124D70(int a);


/* DEBT(TYPE): preserve the unsigned argument view used by func_00126F20. */
#define CALL_Ch_SoundSetId_U8 ((void (*)(Chr *, int))Ch_SoundSetId)

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_func_002ED0E0_INT ((int (*)(u8 *, u32))func_002ED0E0)

#endif /* FFX_R0_H */
