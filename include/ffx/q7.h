#ifndef FFX_Q7_H
#define FFX_Q7_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

extern u8 D_007649A1;
extern int D_00566278;
extern int D_00568630;
extern u32 D_00578988[];
extern u32 D_00792398[];
extern int D_007924C0[];

/* ---- animation bytecode interpreter (0x2AE200) ---- */
typedef struct AnimCtx { /* DEBT(NAME): guessed from the 0x2AE200 handlers; offsets are byte(b)/half(h) + hex */
    u8 pad000[0x210];
    u8 b210;
    u8 pad211[9];
    u16 h21A;
    u8 pad21C[4];
    void *p220;
} AnimCtx;

typedef struct AnimTgt { /* DEBT(NAME): object at AnimCtx.p220 */
    u8 pad00[0x19];
    u8 b19;
    u8 pad1A[0x8E];
    s16 *pA8;
    u8 padAC[0xC];
    u16 hB8;
} AnimTgt;

typedef struct AnimWork {
    u8 pad00[8];
    u8 b08;
    u8 pad09[7];
    float f10;
    float f14;
    float f18;
    u16 h1C;
    u16 h1E;
    u8 pad20[0xC];
    u16 h2C;
    u16 h2E;
    u8 pad30[0x10];
    float f40;
    float f44;
    float f48;
    u16 h4C;
    u8 b4E;
    u8 b4F;
} AnimWork;

typedef struct AnimRes {
    u8 pad00[0x20];
    u8 *p20;
} AnimRes;

extern s16 D_00373720[];

typedef struct Slot16 { int id; int pad[3]; } Slot16; /* DEBT(NAME) */
extern Slot16 D_006F37E0[8];

typedef struct Ent20 { u8 pad[0x20]; } Ent20; /* DEBT(NAME) */
typedef struct EntList { /* DEBT(NAME) */
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u8 pad0A[0xE];
    Ent20 *p18;
    Ent20 *p1C;
} EntList;

extern u32 D_00703F20;
extern u32 D_00764130;
extern u8 D_004F3F80;
extern u8 D_004F4110;
#define GIF_CHCR (*(volatile u32 *)0x1000A000)

int op_mdc_size_get_main(int a, int b, int c, int d);
void func_002B1E30(void);
void func_002B37C0(void);

float func_00110288(Chr *chr);
void func_00173720(float *v);
int Ch_OptposGet(int a, int b, int c);
int func_00107428(Chr *chr, int bone, Vec4 *in, Vec4 *out); /* in may be 0 */
void op_m_copy(void *dst, void *src);

void func_2067600(void);
int *op_oef2_a_get(int a, int b, int c);
int func_002BCB60(int a, void *req);

typedef struct SlotTbl18 { /* DEBT(NAME): object with a table at +0x18, either absolute pointer or offset from the object */
    u8 pad00[0x18];
    u32 tab;
} SlotTbl18;

typedef struct SlotTbl14 { /* DEBT(NAME): same with 0x20-byte records, table at +0x14 */
    u8 pad00[0x14];
    u32 tab;
} SlotTbl14;

typedef struct SndReq { /* DEBT(NAME): request block built on the stack, 0x70 bytes */
    int w00;
    int w04;
    s16 h08;
    u8 pad0A[2];
    int w0C;
    u64 d10;
    int w18;
    int w1C;
    int w20;
    u8 pad24[0x10];
    int w34;
    u64 d38;
    int w40;
    int w44;
    u8 pad48[0x28];
} SndReq;

extern int D_0078BC08; /* DEBT(NAME): copy of D_0078BC04/D_0078BC00 made before each sound command */
int func_002DF388(int a, int b, int c);
int func_002E0590(int a, int b, int c);
int func_002DFEE0(int a, int b);
int func_002DFFA8(int a, int b, int c);
int func_002DFD90(int a, int b, int c, int d);
int func_002D9050(int port, u32 *type, u32 *free, u32 *format);

float func_002D46B0(float a, float b, float c);
void func_002D7430(u32 a, int *b, int *c);
void func_002D7480(u32 a, int b, int c);
void func_002DEEF0(void);
void func_002D9118(void);
int func_002EF240(char *fmt, ...);
extern char D_00576350[];

extern char D_00576368[];

typedef struct SndHalf { /* DEBT(NAME): 0x80-byte half of a double-buffered sound voice, only w58/b71 known */
    u8 pad00[0x58];
    s32 w58;
    u8 pad5C[0x15];
    u8 b71;
    u8 pad72[0xE];
} SndHalf;

typedef struct SndVoice { /* DEBT(NAME) */
    SndHalf h[2];
} SndVoice;

typedef struct SndSlot { /* DEBT(NAME): 0x1C-byte entry, 4 per group (0x70) */
    SndVoice *v;
    u8 pad04[0xC];
    s32 w10;
    u8 pad14[8];
} SndSlot;

extern SndSlot D_0078BC90[][4];

void func_002F8C30(SndVoice *a, SndVoice *b);
int func_002DEA08(int a, int b);
int func_002DEAC0(int a, int b, int c);
int func_002DC2D0(void);
int func_002DC320(void);
void func_002DC310(int a);
int func_002DC780(void);
int func_002DC7D8(void);
void func_002DC7C8(int a);
int func_002DCBD8(void);
void func_002DD1C8(void *m, float a);
void func_002DD318(void *dst, void *src, float a);
void func_002DD270(void *dst, void *src, float a);
extern void (*D_0078D604)(int);
extern int D_0078D608;
extern int D_005663E4;
extern void (**D_00567EB4)(void);

extern int D_0057CBC0; /* DEBT(NAME): errno set by the syscall stubs, copied into reent->_errno by the *_r wrappers */
u32 func_002F8A38(int a);
int func_002F8900(int a, int b, int c);
int func_002F8980(int a, int b, int c);
int func_002F8A20(int a);
int func_002F8A30(int a, int b, int c);
int func_002F8AF0(int fd, int *st);
void func_002DF880(void);
void func_002F8160(int a, void (*fn)(void), int b);
void func_002F8300(void);
extern u32 *D_0078C028;
extern u32 *D_0078C02C;
extern u32 *D_0078C030;
extern int D_0078D600;
int func_002E11A0(int a);
int func_00300280(void); /* DEBT(TYPE): DI wrapper, returns the old status */
void func_003002C8(void);

void AtelSetEffectFlag(int a);
void func_002DD610(void *a, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);
float func_002E8750(float x);
float func_002D4690(float a, float b);
void op_mfifo_set(void *p, int q, int r, int s);
void op_md_tex0_reset(void *p, u64 v);
void opp_dbg_draw_spl(AnimCtx *o, int b);
void func_002AF368(AnimCtx *o, int b);
void func_002AF648(AnimCtx *o, int b);
void func_002AF828(AnimCtx *o, int b);
void opp_dbg_draw_line_circle(AnimCtx *o, int b);
extern u8 D_004F4050[];

typedef struct EvQueue { /* DEBT(NAME): ring buffer of 64 event masks with two counters; layout from func_002CEFF0 */
    u32 a[64];
    u32 b[64];
    u32 c[64];
    u16 h300;
    u16 h302;
} EvQueue;
extern EvQueue D_00764430;

typedef struct EvSlots { /* DEBT(NAME) */
    u16 h00;
    u8 pad02[0xE];
    u32 w10[64];
} EvSlots;
extern EvSlots D_00764740;

typedef struct ObjH4 { /* DEBT(NAME): only the u16 count at +4 is known */
    u8 pad00[4];
    u16 n;
} ObjH4;

/* String tables selected by func_002DE320 / func_002DE410. */
extern char *D_00566348[8];
extern char *D_00566368[4];
extern char D_00576B28;

/* GS environment packet constructed by func_002CF1D0. */
extern u64 D_006F2EE0[];

/* DEBT(NAME): four-float per-entry multipliers, accessed through the +0x390 table. */
typedef struct W10MultiplierCount { u8 pad0[0x14]; s16 count; } W10MultiplierCount;
typedef struct W10MultiplierTable { u8 pad0[0x390]; Vec4 *values; } W10MultiplierTable;

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_func_002D3FF0_INT ((int (*)(s32))func_002D3FF0)

/* DEBT(TYPE): this caller supplies two scalar floats to the legacy no-argument declaration. */
#define CALL_func_002D4410_FLOAT ((int (*)(float, float))func_002D4410)

#endif
