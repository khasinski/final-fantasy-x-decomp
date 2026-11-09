#ifndef FFX_U1_H
#define FFX_U1_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* <stdarg.h> of the EE toolchain (not shipped with the compiler copy used here) */
#ifndef va_start
typedef char *va_list;
#define va_start(ap, last) \
    ((ap) = ((va_list)__builtin_next_arg(last) \
             - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0)))
#define va_end(ap) ((void)0)
#endif

/* ---- c_165320 ---- */

extern u8 D_00595F68[][3]; /* DEBT(TYPE): 3-byte records indexed by D_00595F6C[i].value? seen in func_00162ED8 */

typedef struct Rec595F6C { /* DEBT(NAME): named after D_00595F6C, 0x34-byte entries */
    u8 type;
    u8 pad_01[7];
    s32 id;
    u8 pad_0C[4];
    s32 value;
    u8 pad_14[0x20];
} Rec595F6C;

extern int D_0030DE30;
extern Rec595F6C *D_00595F6C;
extern s8 D_0030DE4C;
extern u8 D_0030DE4E;
extern char D_0056BD40[];
extern char D_00597470[];
extern int D_0030DE08[4];
extern s8 D_0030DE68[8];
extern s8 D_0030DE78[8];

int func_002FCD90(int fd, void *buf, int size);
int func_002E0C98(int *dst, int src);

void func_00165828(char *fmt, va_list ap);
void func_00165A38(char *fmt, ...);

typedef struct Rec57CB80 { /* DEBT(NAME): named after D_0057CB80 */
    s32 w00;
    s32 *sizes; /* in sectors, one per entry of D_00597490 */
    s32 w08;
    s32 w0C;
} Rec57CB80;

extern Rec57CB80 D_0057CB80;
extern s8 D_0030DE4D;
extern s8 D_0030DE4F;
extern u8 D_00596070[0x1400];
extern int D_0030DE54;

/* ---- c_14D4B0 ---- */
extern u16 D_0030BBB0[256]; /* character code conversion table */
extern int D_0030BDD0[2]; /* DEBT(TYPE): handles freed with TkFree; length unknown */
extern int D_0030BDD8[2]; /* DEBT(TYPE): handles freed with TkFree; length unknown */
void func_00174A90(int a);
void func_00174AF8(int a);
void func_00159CE8(int a, int b, int c, int d, int e);
int func_00158D60(void);
s32 TkMalloc(s32 size);
void TkFree(s32 h);
void TkSetEventJumpMapNo(int a, int b);
int TkGetNowEventJumpMapNo(void);

extern u16 D_0030BAD8[]; /* code ranges: {first, count, code[count]}..., ends with first == 0 */
int TkCheckSoftWareReset(void);

/* ---- c_14E5E0 ---- */
extern int D_0030BDCC;
extern int D_0030BDE0[2]; /* DEBT(TYPE): cleared together with D_0030BDD0/D_0030BDD8 */
extern char D_0058F950[];
EvGameState *AtelGetCtrlWork(int i); /* same as q1.h */
void func_0014D4F8(void);
void func_0014D5D8(int *a, int *b);
void func_0014D8C8(void);
void func_0014D9F8(int i);
void func_0014D718(u8 *src, u8 *dst);
void func_0014E1D8(void);
void AtelExecSoftWareReset(void);
void func_0014E5E0(int a);
void func_00145858(void);
void AtelUpdateBattleStatus(void);
void func_0014C3A8(void);
void func_00136450(void);
void AtelExecEventSound(void);

typedef struct Rec36E230 { /* DEBT(NAME): named after D_0036E230, 8-byte entries */
    u16 h00;
    u16 h02;
    u16 h04;
    u16 h06;
} Rec36E230;

extern Rec36E230 D_0036E230[];

/* ---- c_14F628 / c_150630: script opcode handlers ---- */
void Sg_PLightDefine(float x, float y, float z, float w, int idx, int a, int b, int c, int d);
void Ch_SetShadeCol(Chr *chr, float x, float y, float z, int n);
int func_00107428(Chr *chr, int bone, Vec4 *in, Vec4 *out); /* same as q7.h */
void func_00107210(Chr *chr, Chr *target, int v);
void func_00107250(Chr *chr, Chr *target, int v, float x, float y, float z);
int Ch_OptposGet(); /* DEBT(TYPE): q7.h declares (int, int, int); called as (Chr *, int, float *) like r2.h */
void func_00105500(Chr *chr, int a, int b, int c, int d, int e);
void func_001055B0(Chr *chr, int a, int b, int c, int d, int e);
void func_00105670(Chr *chr, int a, int b, int c, int d, int e);
void func_00108178(Chr *chr, float angle, float v);
int Ch_DataReadSync(int h);

/* ---- c_153730: effect handles of the script effect opcodes ---- */
extern int D_0058FE10[3]; /* kind 1 */
extern int D_0058FE20[3]; /* kind 0 */
extern int D_0058FE30[3]; /* kind 2 */
extern int D_0058FE40[3]; /* kind 3 */
s32 MsCameraGet(s32 a, s32 b, s32 c);
void MsCameraFree(int h);
int func_00145628(Actor *a);
void func_001A9EF0(u32 id, int which, float *x, float *y, float *z);
void func_001A9F50(u32 id, int which, float *x, float *y, float *z);
void MsCameraSetRect(s32 h, s32 i, float *v);
char *func_0013A468(char *p);
void func_0010A230(Chr *chr, float a, float b); /* same as r3.h */
void func_001A6E90(int h, int which, float x, float y, float z);
void func_001A76E0(int h, int which, float x, float y, float z);
void func_001A7BC0(int h, int which, float a, float b, float c, float d, float e, float f);
void func_001A7E00(int h, int which, int mode, float a, float b, float c, float d, float e, float f);

/* ---- c_154880 ---- */
float func_001AA028(void);
float MsNearRag(float a, float b);
void func_001A8DA0(int h, int which, int on);
void MsCameraSetRoll(int h, float a);
void func_001A6FA0(int h, int which, float a, float b, float c, float d);
void MsCameraSetAct(int h, int which, int a, int b, float *v);
void func_001A89F8(int h, int which, int mode, float a, float b, float c, float d, float e);
void func_001A8B38(int a, int b, int ceil, float lo, float hi, float k);
void func_001A9550(int id, int which, int c, int total, int mode);
void func_001A96A8(int id, int which, int c, int t0, int t1, int t2, int h4);
void func_001A9860(int id, int which, float a, float b, float c, float d);
void func_001A99D0(int id, int k, float a, float b, float c);

/* ---- c_1558A0 ---- */
void func_001A6E10(int h, int which, int v);
void func_001A83F0(int h, int a, int b, int var, float r);
void func_001A8850(int h, int a, int b, int var, float x, float y, float z);
void MsCameraSetBtl(int h, int which, int id, int a, int b, int c, float x, float y, float z, float w);

/* ---- c_156900 ---- */
typedef struct Rec58F9F0 { /* DEBT(NAME): named after D_0058F9F0, 0x210-byte entries; count copied from D_0058F9E0 */
    s32 n;
    u8 pad_04[0x20C];
} Rec58F9F0;

extern Rec58F9F0 D_0058F9F0[2];
extern int D_0030D408;
extern int D_0058FE58;
extern int D_0058FE5C;
extern int D_0058FE68;
extern int D_0058FE6C;
extern u8 D_0030D3E8;
int func_001AAAB0(int h, int which);
int func_001AC0B8(int h, int which);
void func_001608D0(void);
void MsCameraSetSpline(int h, int which, int var, float x, float y, int n);
void func_00171648(int on);
void func_002E08F0(int id, void *buf, int size);
extern u8 D_0058FE70[0x2000];
void func_0015B808(int a);
void CdEnvInit(int a);
void MsEnvInit(void);
void func_001AB568(int h, int a, int b, int c, float f, int d, int e, int g);
void func_001AB6D8(int a, int b, int c, int d, int e, float f, int g, float f2, int h);

#endif
