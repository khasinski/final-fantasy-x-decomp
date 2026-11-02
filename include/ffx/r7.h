#ifndef FFX_R7_H
#define FFX_R7_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/w11.h"

/* VIF0 registers (0x10003800 block) */
#define VIF0_FBRST (*(u32 *)0x10003810)
#define VIF0_ERR (*(u32 *)0x10003820)

void SqsStraightStreamingDataSend(int a, int b);
void func_00253628(int a, int b);
void func_00253788(int a, int b);
extern s32 D_00791600;
void func_002E9B68(void);

extern char D_00578D68[];
extern W11Ring D_00791E80;
typedef struct R7Pair { int w0; int w4; } R7Pair;
extern R7Pair *D_007923A4;
extern R7Pair *D_007923AC;

int func_002EF290(W11Reent *r, const char *s);
char *func_002F1DA0(char *s, const char *delim, char **lasts); /* strtok_r */
u32 *func_002F62F0(W11Reent *r);
int func_002F87F0(int a);
void func_003002E0(void);
void func_002F9090(void);
void func_002F9240(void);
W11File *func_002ED590(W11Reent *r, const char *file, const char *mode); /* _fopen_r */
void func_002E9B10(void);
void func_001000B8(int a);

extern u8 D_005780C9[]; /* ctype table (bit0 upper, bit1 lower) */
void func_002D05F0(int a);

double func_002F0E20(W11Reent *r, const char *s, char **end);
char *func_002F6268(W11Reent *r, int category, const char *locale);
long func_002F1E40(W11Reent *r, const char *s, char **end, int base);
int func_002F74C0(W11Reent *r, int a, int b, int c);

/* variadic argument pointer of the EE gcc: first anonymous argument = register save area just below next_arg;
   nreg = number of argument registers (8) minus named parameters */
#define R7_VA_START(ap, last, nreg) ((ap) = (void *)((char *)__builtin_next_arg(last) - (nreg) * 8))

typedef struct R7Blk20 { int w[5]; } R7Blk20;
extern R7Blk20 D_005662E8;


/* DMAC registers: global enable (read) / write ports and SPR channels */
#define DMAC_ENABLER (*(volatile u32 *)0x1000F520)
#define DMAC_ENABLEW (*(volatile u32 *)0x1000F590)
#define D8_CHCR (*(volatile u32 *)0x1000B000)
#define D9_CHCR (*(volatile u32 *)0x1000B400)

#define UNCACHED(p) ((void *)((u32)(p) | 0x20000000))

/* IOP RPC client (libcdvd): sceSifCallRpc and helpers */
int func_002FB4C8(void *cd, int rpc, int mode, void *send, int ssize, void *recv, int rsize, void *endfunc, void *efarg);
void func_002FABD8(void *addr, int size);
int func_002E12B0(int cmd);
int func_00300280(void); /* DEBT(TYPE): DI wrapper, returns the old status */
void func_003002C8(void);
extern int D_005675C0[];
extern int D_00567E08[];
extern int D_00567A00;
extern int D_005663EC;
extern int D_005663D0;
extern char D_00576DA0[];
extern char D_00576DB0[];
extern char D_00576DD0[];

int func_002FA4E0(const char *fmt, ...);


/* libcdvd read request (sent with sceSifCallRpc, 0x18 bytes) */
typedef struct R7CdMode {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
} R7CdMode;

typedef struct R7CdRead {
    int lbn;
    int sectors;
    void *buf;
    R7CdMode mode;
    u8 pad0F;
    void *p10;
    void *p14;
} R7CdRead;

extern R7CdRead D_005664C0;
extern int D_005663F4;
extern volatile int D_00566414; /* volatile: set by the cdvd RPC end callback func_002E0790 (SIF interrupt context) */
extern int D_005663F0;
extern int D_005663E8;
extern int D_00567580;
extern int D_005674C0[];
extern int D_00567590[];
extern char D_00576D78[];
extern char D_00576D90[];
int func_002E1108(void);
int func_002E0F98(int a);
void func_002E09C8(void *data);


extern int D_00568E80;
extern int D_00568E84;

/* DEBT(NAME): request block of func_002BCB60 (0x48 bytes), offsets from op_md_draw_map_test */
typedef struct R7Req {
    int w0;
    int w4;
    s16 h8;
    u8 padA[2];
    int wC;
    u64 q10;
    int w18;
    int w1C;
    int w20;
    u8 pad24[0x34 - 0x24];
    int w34;
    u64 q38;
    int w40;
    int w44;
    u8 pad48[0x20]; /* DEBT(PADDING): frame size of op_md_draw_map_test */
} R7Req;

/* DEBT(NAME): thread argument of func_002D21A8 */
typedef struct R7Thr {
    u8 pad00[0x20];
    int idx;
} R7Thr;

void func_002B5348(int a, int b, int c, int d);
void func_002B53D0(int a, int b, int c, int d);
void func_002B5458(int a, int b, int c, int d);
void op_rt_m_yxz(int a, int b, int c, int d);
void func_002B5568(int a, int b, int c, int d);
void func_002B55F0(int a, int b, int c, int d);


int func_002E0360(int a, int b, int c, int d);
int func_002DF250(int a, int b, int c, int d);
void func_002E06A8(void);
long func_002F7418(W11Reent *ptr, int fd, int buf, int n);
extern int D_0078BF80[];
extern int D_0078BC40[];


float func_002E6888(float x, float y); /* DEBT(NAME): __kernel_cosf guess (fdlibm) */
float func_002E7330(float x, float y, int iy); /* DEBT(NAME): __kernel_sinf guess (fdlibm) */
int func_002E53E0(float x, float *y); /* DEBT(NAME): __ieee754_rem_pio2f guess (fdlibm) */

int func_002E69E0(float *x, float *y, int e0, int nx, int prec, const int *ipio2); /* DEBT(NAME): __kernel_rem_pio2f guess (fdlibm) */
extern int D_005777F8[]; /* npio2_hw */
extern int D_005774E0[]; /* two_over_pi */

extern double D_005778E0; /* __kernel_cos C6 */
extern double D_005778E8; /* C5 */
extern double D_005778F0; /* C4 */
extern double D_005778F8; /* C3 */
extern double D_00577900; /* C2 */
extern double D_00577908; /* C1 */

float func_002E8750(float x); /* DEBT(NAME): floorf guess (newlib) */
float func_002E8860(float x, int n); /* DEBT(NAME): scalbnf guess (newlib) */
extern int D_00577A10[]; /* init_jk */
extern float D_00577A20[]; /* PIo2 */

extern float D_00577A88[]; /* __kernel_tanf T[13] */

extern float D_00577BD0[]; /* atanf: atanhi[4] */
extern float D_00577BE0[]; /* atanlo[4] */
extern float D_00577BF0[]; /* aT[11] */

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_func_003002C8_INT ((int (*)(void))func_003002C8)

/* DEBT(TYPE): soft-double libcall takes raw double bits in general-purpose argument registers. */
#define CALL_func_002EC198_BITS ((int (*)(s64, s64))func_002EC198)

#endif
