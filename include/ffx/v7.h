#ifndef FFX_V7_H
#define FFX_V7_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/r7.h"

/* ---- VU0 micro memory / VIF0 helpers (c_2DB640, c_2DC650) ---- */

/* VIF0 registers, accessed as volatile hardware registers (cf. func_002DCB68) */
#define V7_VIF0_FBRST (*(volatile u32 *)0x10003810)
#define V7_VIF0_ERR (*(volatile u32 *)0x10003820)

/* one VU0 data-memory qword as read back by func_002DC5F0 */
typedef union V7VuQword {
    u64 d[2];
    u16 h[8];
} V7VuQword;

V7VuQword func_002DC5F0(u16 addr);

/* ---- libdma (c_2DB640) ---- */

/* DMAC channel register block (0x1000xx00); hardware registers, hence volatile */
typedef struct V7DmaChan {
    u32 chcr;
    u32 pad04[3];
    u32 madr;
    u32 pad14[3];
    u32 qwc;
    u32 pad24[3];
    u32 tadr;
    u32 pad34[3];
    u32 asr0;
    u32 pad44[3];
    u32 asr1;
    u32 pad54[11];
    u32 sadr;
} V7DmaChan;

/* DMAC control registers (hardware, volatile). The final D_STAT mask store of func_002DB700
   is a plain store (it sits in a jal delay slot, which gcc never fills with a volatile access) */
#define V7_D_CTRL (*(volatile u32 *)0x1000E000)
#define V7_D_STAT (*(volatile u32 *)0x1000E010)
#define V7_D_STAT_W (*(u32 *)0x1000E010) /* DEBT(FAKE): non-volatile alias of D_STAT */

extern volatile V7DmaChan *D_00566250[10]; /* channel register blocks */
extern int D_00566290[10]; /* nonzero: channel present */
int func_002DB7F0(void *env);

/* ---- newlib libc ---- */
struct V7Uio;
struct W11Glue;
void *func_002EE630(W11Reent *ptr, int size); /* _malloc_r */
int func_002F0108(W11File *fp, char *buf, int n); /* __sread */
int func_002F0170(void *cookie, const char *buf, int n); /* __swrite */
long func_002F01F0(W11File *fp, int off, int whence); /* __sseek */
int func_002F5E90(W11File *fp, struct V7Uio *uio); /* __sfvwrite */
int func_002F22C8(W11Reent *ptr, W11File *fp, const char *fmt, void *ap); /* _vfprintf_r */
int func_002F3A70(W11File *fp, const char *fmt, void *ap); /* __svfscanf */
int func_002F0078(void); /* eofread */
extern char D_005781D8[]; /* "\n" */
extern double D_005789E0[]; /* mprec tens[] */
int func_002F6358(W11Reent *ptr, int fd, int off, int whence); /* _lseek_r */
long func_002F4708(W11Reent *ptr, int fd, int buf, int n); /* _write_r */
/* libgcc soft-double helpers (__muldf3, __subdf3 = func_002EBC08, __cmpdf2 = func_002EC198, ...)
   are called by address: the link has no libgcc symbol names, so a double operation that the
   original compiled to a libcall is written as that call */
long long func_003003B0(double a); /* __fixunsdfdi */
double func_002EBC70(double a, double b); /* __muldf3 (also in u4.h) */

void func_002ED500(W11Reent *ptr); /* __sinit */
extern char D_005789C8[]; /* "C" */
extern char D_005789B8[]; /* "" */
int func_002F9B08(void);
int func_002F9A38(void *buf, int n);
int func_002F98E8(const void *buf, int n);

/* DEBT(NAME): small character queue fed by func_002F93B0 */
typedef struct V7CharQ {
    int w0;
    int count;
    struct {
        u8 flag;
        u8 c;
    } ent[512];
} V7CharQ;
extern int D_00568DE0;
extern V7CharQ D_00791A38;
extern int D_00791A30; /* semaphore */

int func_002F8ED8(int irq);
int func_002F8110(int irq, int id);
extern int D_00792394;
extern int D_00568DEC;
int func_002F9EE0(const char *fmt, void *ap);
extern void *D_00568DE8;
void func_002F9C00(void);
extern int D_00568E8C;
extern int D_795368;
int func_002FA8F8(int a, int b, int c, int d, int e, int f, int g);

void *func_002F7990(W11Reent *ptr, int n, int size); /* _calloc_r */
/* ctype tolower() as inlined by newlib (bit 0 of the ctype table = upper case) */
static inline int v7_tolower(int c)
{
    return (D_005780C9[c] & 1) ? c - 'A' + 'a' : c;
}

void func_002ED338(W11File *ptr, int flags, int file, W11Reent *data); /* std() */

double func_002F6FE8(W11Bigint *a, int *e); /* b2d */
W11File *func_002ED400(W11Reent *ptr); /* __sfp */
struct W11Glue *func_002ED390(W11Reent *d, int n); /* __sfmoreglue */
int func_002EDB68(W11File *fp, long off, int whence); /* fseek */

W11Bigint *func_002F64D0(W11Reent *ptr, W11Bigint *b, int m, int a); /* __multadd */
W11Bigint *func_002F68B0(W11Reent *ptr, W11Bigint *a, W11Bigint *b); /* __multiply */
void func_002F64A0(W11Reent *ptr, W11Bigint *v); /* _Bfree */
extern const int D_005789D0[3]; /* pow5mult p05[] */
void *func_002F7A50(W11Reent *ptr, void *p, int n); /* _realloc_r */

void func_002ED6D8(W11Reent *ptr, void *p); /* _free_r */

/* newlib CHECK_INIT(): give the stream a reent and make sure stdio is set up */
#define V7_CHECK_INIT(fp) \
    do { \
        if ((fp)->_cookie54 == 0) { \
            (fp)->_cookie54 = D_005681A4; \
        } \
        if (!(fp)->_cookie54->__sdidinit) { \
            func_002ED500((fp)->_cookie54); \
        } \
    } while (0)

void func_002EE288(W11File *fp); /* __smakebuf */
int func_002EFDC8(W11File *fp); /* __srefill */
int func_002F0A58(const char *a, const char *b, int n); /* strncmp (also in t2.h) */
extern char **D_00568604; /* environ */

int func_002F8AE8(int fd); /* isatty */
int func_002EDFF8(W11Reent *ptr, int fd, int *st); /* _fstat_r */

/* newlib struct stat as filled by func_002F8AF0 (only st_mode is read here) */
typedef struct V7Stat {
    u16 st_dev;
    u16 st_ino;
    u32 st_mode;
    u8 pad08[0x10 - 0x08];
    long st_size;
    u8 pad18[0x70 - 0x18]; /* DEBT(PADDING): size from the frames of func_002EE288/func_002EDB68 */
} V7Stat;

int func_002F6730(u32 x); /* __hi0bits */
int func_002F67B8(u32 *y); /* __lo0bits */

int func_002F6D58(W11Bigint *a, W11Bigint *b); /* __mcmp */
int func_002F7718(W11File *fp); /* __submore */

char *func_002F4AE8(W11Reent *ptr, double d, int mode, int ndigits, int *decpt, int *sign, char **rve); /* _dtoa_r */

void *func_002EEFCC(void *dst, const void *src, int n); /* memmove */
void *func_002EEDA8(const void *s, int c, int n); /* memchr */
int func_002F4768(W11File *fp); /* __swsetup */

/* FILE seek callback (_seek member) */
typedef long (*V7SeekFn)(void *cookie, long off, int whence);

/* newlib dlmalloc (2.6) chunk and bin macros */
typedef struct V7MChunk {
    u32 prev_size;
    u32 size;
    struct V7MChunk *fd;
    struct V7MChunk *bk;
} V7MChunk;
extern V7MChunk *D_005681A8[]; /* av_ */
extern unsigned long D_005685B0; /* trim_threshold */
extern unsigned long D_005685B8; /* top_pad */
int func_002ED9F8(W11Reent *ptr, u32 pad); /* _malloc_trim_r */
#define V7_BIN_AT(i) ((V7MChunk *)((char *)&D_005681A8[2 * (i) + 2] - 2 * sizeof(u32)))
#define V7_TOP (V7_BIN_AT(0)->fd)
#define V7_LAST_REMAINDER (V7_BIN_AT(1))
#define V7_BINBLOCKS (V7_BIN_AT(0)->size)
#define V7_MARK_BINBLOCK(ii) (V7_BINBLOCKS |= ((unsigned long)1 << ((ii) / 4)))
#define V7_UNLINK(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }

/* newlib struct __siov / __suio */
typedef struct V7Iov {
    const void *iov_base;
    int iov_len;
} V7Iov;

typedef struct V7Uio {
    V7Iov *uio_iov;
    int uio_iovcnt;
    int uio_resid;
} V7Uio;

#endif
