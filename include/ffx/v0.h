#ifndef FFX_V0_H
#define FFX_V0_H
/* declarations added by worker v0 (round 8) */

/* argument block of func_00113810: two words at 0xC/0x10 forwarded to func_00104F28 */
typedef struct V0Pair {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ int a;
    /* 0x10 */ int b;
} V0Pair; /* DEBT(NAME): field names unknown */

void func_00113810(V0Pair *p);

/* GS register images (field layout of the Sony libgraph sceGs* types) */
typedef struct V0GifTag {
    unsigned long NLOOP : 15;
    unsigned long EOP : 1;
    unsigned long pad16 : 16;
    unsigned long id : 14;
    unsigned long PRE : 1;
    unsigned long PRIM : 11;
    unsigned long FLG : 2;
    unsigned long NREG : 4;
    unsigned long REGS0 : 4;
    unsigned long REGS1 : 4;
    unsigned long REGS2 : 4;
    unsigned long REGS3 : 4;
    unsigned long REGS4 : 4;
    unsigned long REGS5 : 4;
    unsigned long REGS6 : 4;
    unsigned long REGS7 : 4;
    unsigned long REGS8 : 4;
    unsigned long REGS9 : 4;
    unsigned long REGS10 : 4;
    unsigned long REGS11 : 4;
    unsigned long REGS12 : 4;
    unsigned long REGS13 : 4;
    unsigned long REGS14 : 4;
    unsigned long REGS15 : 4;
} V0GifTag;

typedef struct V0GsBitbltbuf {
    unsigned long SBP : 14;
    unsigned long pad14 : 2;
    unsigned long SBW : 6;
    unsigned long pad22 : 2;
    unsigned long SPSM : 6;
    unsigned long pad30 : 2;
    unsigned long DBP : 14;
    unsigned long pad46 : 2;
    unsigned long DBW : 6;
    unsigned long pad54 : 2;
    unsigned long DPSM : 6;
    unsigned long pad62 : 2;
} V0GsBitbltbuf;

typedef struct V0GsTrxpos {
    unsigned long SSAX : 11;
    unsigned long pad11 : 5;
    unsigned long SSAY : 11;
    unsigned long pad27 : 5;
    unsigned long DSAX : 11;
    unsigned long pad43 : 5;
    unsigned long DSAY : 11;
    unsigned long DIR : 2;
    unsigned long pad61 : 3;
} V0GsTrxpos;

typedef struct V0GsTrxreg {
    unsigned long RRW : 12;
    unsigned long pad12 : 20;
    unsigned long RRH : 12;
    unsigned long pad44 : 20;
} V0GsTrxreg;

typedef struct V0GsTrxdir {
    unsigned long XDIR : 2;
    unsigned long pad2 : 62;
} V0GsTrxdir;

/* DMA tag + VIF DIRECT + GIF A+D list that sets up a host->local image transfer (0x60 bytes) */
typedef struct V0GsLoadPk {
    /* 0x00 */ u32 dma[2];
    /* 0x08 */ u32 vif0;
    /* 0x0C */ u32 vif1;
    /* 0x10 */ V0GifTag giftag;
    /* 0x20 */ V0GsBitbltbuf bitbltbuf;
    /* 0x28 */ long bitbltbufaddr;
    /* 0x30 */ V0GsTrxpos trxpos;
    /* 0x38 */ long trxposaddr;
    /* 0x40 */ V0GsTrxreg trxreg;
    /* 0x48 */ long trxregaddr;
    /* 0x50 */ V0GsTrxdir trxdir;
    /* 0x58 */ long trxdiraddr;
} V0GsLoadPk;

typedef struct V0TexHdr {
    /* 0x00 */ u16 psm;
    /* 0x02 */ u16 h2;
    /* 0x04 */ u16 x;
    /* 0x06 */ u16 y;
    /* 0x08 */ u16 w;
    /* 0x0A */ u16 h;
    /* 0x0C */ u32 data;
} V0TexHdr; /* DEBT(NAME): fields named from how func_001170A8 feeds them to the upload packet */

typedef struct V0TexUpload {
    /* 0x00 */ V0GsLoadPk pk;
    /* 0x60 */ u32 data;
    /* 0x64 */ u16 tbw;
    /* 0x66 */ u16 h66;
    /* 0x68 */ u16 h68;
    /* 0x6A */ u16 tbp;
    /* 0x6C */ union { int i; u16 h; } n; /* DEBT(TYPE): written as int, read back as u16 */
} V0TexUpload;

void Sg_GsloadSetBase(V0TexUpload *t);
void func_00116EB0(V0GsLoadPk *p, int dbw, int dpsm, int dsax, int dsay, int rrw, int rrh);
void func_001170A8(V0TexHdr *h, V0TexUpload *t);
void func_001170E8(int *in, V0TexUpload *t);

/* GS register numbers and value builders (Sony libgraph names/layout) for the c_11D178 writers */
#define GS_REG_RGBAQ      0x01
#define GS_REG_XYOFFSET_1 0x18
#define GS_REG_XYOFFSET_2 0x19
#define GS_REG_ZBUF_2     0x4F
#define GS_REG_TEX1_1     0x14
#define GS_REG_ALPHA_1    0x42
#define GS_REG_TEST_1     0x47
#define GS_REG_TEST_2     0x48
#define SCE_GS_PSMZ24     0x31
#define SCE_GS_SET_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
void func_0011D9E0(int r, int g, int b, int a, int q);
void Sg_GsZBUF(int zmsk);
void func_0011DAA8(int zmsk);

extern s32 D_00580924;    /* index of the open GIF tag in D_00580928 */
extern Cmd16 *D_0058092C; /* the open GIF tag (NLOOP patched when the list is closed) */

s32 func_0012E140(Actor *a, s32 unused, ScriptCtx *ctx);

s32 func_00101528(int kind);

extern char D_00569698[], D_005696B0[]; /* message strings of Cache_Exist2 */

void func_0013BCE0(Actor *a, float x, float y, float z); /* same as q1.h */

void func_0014C9E8(int i, int a, int b);
void func_0014CA20(s32 a, float x, float y);
void func_00206860(int r, int c, int v);
void func_00206888(int r, int c, int v);
void AtelSetEncountBattleEndStatus(s32 a, s32 b, s32 c);

void func_0013B470(Actor *a, float v);
void func_0013B488(Actor *a, float v);

void AtelSetPos3d(Actor *a, int flag, float x, float y, float z); /* same as q1.h */

void func_0013D928(int a, int *p, float f); /* same as q1.h */
void func_0013D9D0(int a, int *p, float f); /* same as q1.h */

int func_002D4850(float w, float x, float y, float z);
float func_002D4338(float a);
float func_002D4690(float a, float b);
void func_0014C928(int v, int b, int c, int d); /* DEBT(TYPE): asm (c_14C478); argument roles unknown */

void func_002D4D58(int obj, float x, float y, float z); /* DEBT(TYPE): asm, argument roles from the caller */

float sqrtf(float x); /* libm, linked at 0x2E9708 */
void func_001495A8(int v, int a, int b, int c); /* DEBT(TYPE): argument roles unknown */

/* record returned by AtelGetSnd3dWork as used by func_0012DED0 (DEBT(NAME): field names unknown) */
typedef struct V0Rec1364F0 {
    /* 0x00 */ u32 w0;
    /* 0x04 */ u16 *flags;
    /* 0x08 */ float v8[3];
    /* 0x14 */ float v14[3];
} V0Rec1364F0;

int func_002D47E8(float a, float b, float c, float d, float e, float f);

#endif
