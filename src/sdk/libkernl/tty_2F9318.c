/* tu_369 0x2f8000-0x2fac84: low; libkernl/tty (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#define func_002F9C00 func_002F9C00_orig
#include "ffx/v7.h"
#undef func_002F9C00
void func_002F9C00(int c);
#include "ffx/r7.h"
#include "ffx/g4.h"

/* Legacy syscall wrappers defined in tty.c. */
void func_002F8320(void);
void func_002F8360(void);

int func_002F9318(int c)
{
    register int r __asm__("$2");
    int i, t;

    EE_LI_V1(-0x2F);
    EE_SYSCALL(r, c);
    t = r;
    if (t != c) {
        return ((int (*)(int))func_002F8320)(c);
    }
    if ((u32)t >= 0x100 || D_00568DE0 == 0) {
        return -1;
    }
    i = D_00791A38.count & 0x1FF;
    D_00791A38.count = i + 1;
    D_00791A38.ent[i].flag = 0;
    D_00791A38.ent[i].c = t;
    func_002F8410(D_00791A30);
    return t;
}

int func_002F93B0(u32 c)
{
    int i;

    if (c >= 0x80 || D_00568DE0 == 0) {
        return -1;
    }
    i = D_00791A38.count & 0x1FF;
    D_00791A38.count = i + 1;
    D_00791A38.ent[i].flag = 1;
    D_00791A38.ent[i].c = c;
    func_002F8410(D_00791A30);
    return c;
}

int func_002F9430(int c)
{
    register int r __asm__("$2");
    int i, t;

    EE_LI_V1(-0x2F);
    EE_SYSCALL(r, c);
    t = r;
    if (t != c) {
        return ((int (*)(int))func_002F8360)(c);
    }
    if ((u32)t >= 0x100 || D_00568DE0 == 0) {
        return -1;
    }
    i = D_00791A38.count & 0x1FF;
    D_00791A38.count = i + 1;
    D_00791A38.ent[i].flag = 2;
    D_00791A38.ent[i].c = t;
    func_002F8410(D_00791A30);
    return t;
}

int func_002F94C8(u16 a, int b, int c)
{
    G4SifReq req;

    req.w0 = a;
    req.w4 = b;
    req.w8 = c;
    req.wC = (int)D_00791E40 | 0x20000000;
    return func_002F8810(1, &req);
}

int func_002F9510(int a)
{
    return func_002F8810(2, &a);
}

int func_002F9538(int a, s8 b)
{
    W11Args2 args;

    args.a = a;
    args.b = b;
    return func_002F8810(3, &args);
}

int func_002F9568(int a)
{
    return func_002F8810(4, &a);
}

int func_002F9590(int a, int b, u16 c)
{
    W11Args3 args;

    args.a = a;
    args.b = b;
    args.c = c;
    return func_002F8810(-5, &args);
}

int func_002F95C8(int a, int b, u16 c)
{
    W11Args3 args;

    args.a = a;
    args.b = b;
    args.c = c;
    return func_002F8810(-6, &args);
}

int func_002F9600(int a, s8 b)
{
    W11Args2 args;

    args.a = a;
    args.b = b;
    return func_002F8810(-7, &args);
}

int func_002F9630(int a)
{
    return func_002F8810(-8, &a);
}

int func_002F9658(int a)
{
    return func_002F8810(-9, &a);
}

int func_002F9680(int a)
{
    return func_002F8810(0x10, &a);
}

W11Ring *func_002F96A8(int size)
{
    W11Ring *q = &D_00791E80;

    q->size = size;
    q->count = 0;
    q->wr = q->data;
    q->rd = q->data;
    return q;
}

void func_002F96D0(W11Ring *q)
{
    q->count++;
    q->wr++;
    if (q->wr == q->data + q->size) {
        q->wr = q->data;
    }
}

void func_002F9710(W11Ring *q)
{
    q->count--;
    q->rd++;
    if (q->rd == q->data + q->size) {
        q->rd = q->data;
    }
}

typedef struct TtyState {
    volatile int sid;
    volatile int tx_rem;
    volatile int rx_pos;
    volatile int busy;
    u8 *tx_ptr;
    u8 *rx_buf;
    W11Ring *ring;
} TtyState;

extern char D_00578B20[];
extern char D_00578B48[];
extern char D_00578B60[];
extern char D_00578B78[];

int func_002FA4A8(const char *fmt, ...);

void func_002F9750(int type, int len, TtyState *st)
{
    int r;

    switch (type) {
    case 1:
    case 2:
        if (len != 0) {
            if ((u32)(st->rx_pos + len) > 0x140) {
                func_002FA4A8(D_00578B20);
            }
            len = func_002F9590(st->sid, (int)(st->rx_buf + st->rx_pos), (u16)len);
            if (len < 0) {
                func_002FA4A8(D_00578B48);
            }
            st->rx_pos += len;
        } else {
            u8 *buf = st->rx_buf;
            for (len = 12; len < *(u16 *)buf; len++) {
                *st->ring->wr = st->rx_buf[len];
                func_002F96D0(st->ring);
            }
            st->rx_pos = 0;
        }
        break;
    case 3:
        r = func_002F95C8(st->sid, (int)st->tx_ptr, (u16)st->tx_rem);
        if (r < 0) {
            func_002FA4A8(D_00578B60, r);
            st->busy = 0;
        } else {
            st->tx_ptr += r;
            st->tx_rem -= r;
        }
        break;
    case 4:
        if (st->tx_rem != 0) {
            func_002FA4A8(D_00578B78, st->tx_rem);
        }
        st->busy = 0;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F98E8);

extern TtyState D_00791F90;

int func_002F9A38(void *buf, int n)
{
    char *dst = buf;
    int i;

    for (i = 0; i < n; i++) {
        while (1) {
            int cnt = *(volatile int *)&D_00791F90.ring->count;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            if (cnt != 0) {
                break;
            }
        }
        dst[i] = *D_00791F90.ring->rd;
        func_002F9710(D_00791F90.ring);
        if (dst[i] == '\n' || dst[i] == '\r') {
            return i + 1;
        }
    }
    return i;
}

extern int D_00568DE4;
extern char D_00792240[];

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9B08);

int func_002F9BC8(int c)
{
    register u32 p __asm__("$3");
    register int ret __asm__("$2");
    while (*(volatile u32 *)0x1000F130 & 0x8000) {
    }
    p = 0x10000000;
    ret = c;
    __asm__ volatile("" : "+r"(p), "+r"(ret));
    *(u8 *)(p | 0xF180) = c;
    return ret;
}

void func_002F9C00(int c)
{
    if (D_00568DE4 >= 0x7E) {
        D_00568DE4 = 0;
        D_00792240[0x7F] = 0;
        func_002F9680((int)D_00792240);
    }
    if (c == '\n') {
        int i = D_00568DE4;
        D_00568DE4 = 0;
        D_00792240[i] = c;
        D_00792240[i + 1] = 0;
        func_002F9680((int)D_00792240);
    } else {
        D_00792240[D_00568DE4++] = c;
    }
}

void func_002F9CB0(int c)
{
    if (c == '\n') {
        func_002F9BC8('\r');
        func_002F9BC8('\n');
    } else {
        func_002F9BC8(c);
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9CE8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9D78);

void func_002F9D78(double);
long func_002E9C38(long, long);
long func_002EA5C8(long, long);
unsigned long func_002EAC90(unsigned long, unsigned long);
unsigned long func_002EB260(unsigned long, unsigned long);

int func_002F9EE0(const char *fmt, void *ap_arg)
{
    char *ap = (char *)ap_arg;
    char buf[32];
    char *pad;
    char *p;
    int mod;
    int n;
    long v;
    unsigned long uv;

    while (*fmt != '\0') {
        pad = 0;
        mod = 0;
        if (*fmt == '%') {
        again:
            switch (*++fmt) {
            case '0': {
                int c2;
                n = fmt[1] - '0';
                c2 = fmt[2];
                if ((u8)n < 10) {
                    if ((u32)(c2 - '0') < 10) {
                        n = n * 10 + (c2 - '0');
                        if (n > 31) {
                            n = 31;
                        }
                        fmt += 2;
                    } else {
                        fmt += 1;
                    }
                    {
                        char *end = &buf[31];
                        pad = end - n;
                    }
                    while (n > 0) {
                        buf[31 - n] = '0';
                        n--;
                    }
                }
                goto again;
            }
            case 'l':
                mod = 'l';
                goto again;
            case 'h':
                mod = 'h';
                goto again;
            case 'o':
                if (mod == 'l') {
                    ap += 8;
                    uv = *(unsigned long *)(ap - 8);
                } else if (mod == 'h') {
                    ap += 8;
                    uv = *(unsigned short *)(ap - 8);
                } else {
                    ap += 8;
                    uv = *(unsigned int *)(ap - 8);
                }
                p = &buf[31];
                *p = '\0';
                if (uv == 0) {
                    *--p = '0';
                } else {
                    while (uv != 0) {
                        *--p = (uv & 7) + '0';
                        uv >>= 3;
                    }
                }
                if (pad != 0 && pad < p) {
                    p = pad;
                }
                while (*p != '\0') {
                    ((void (*)(int))D_00568DE8)(*p++);
                }
                break;
            case 'x':
                if (mod == 'l') {
                    ap += 8;
                    uv = *(unsigned long *)(ap - 8);
                } else if (mod == 'h') {
                    ap += 8;
                    uv = *(unsigned short *)(ap - 8);
                } else {
                    ap += 8;
                    uv = *(unsigned int *)(ap - 8);
                }
                p = &buf[31];
                *p = '\0';
                if (uv == 0) {
                    *--p = '0';
                } else {
                    while (uv != 0) {
                        unsigned long d = uv & 0xF;
                        if (d < 10) {
                            *--p = d + '0';
                        } else {
                            *--p = d + 0x57;
                        }
                        uv >>= 4;
                    }
                }
                if (pad != 0 && pad < p) {
                    p = pad;
                }
                while (*p != '\0') {
                    ((void (*)(int))D_00568DE8)(*p++);
                }
                break;
            case 'd':
                if (mod == 'l') {
                    ap += 8;
                    v = *(long *)(ap - 8);
                } else if (mod == 'h') {
                    ap += 8;
                    v = *(short *)(ap - 8);
                } else {
                    ap += 8;
                    v = *(int *)(ap - 8);
                }
                p = &buf[31];
                *p = '\0';
                if (v == 0) {
                    *--p = '0';
                } else {
                    if (v < 0) {
                        v = -v;
                        ((void (*)(int))D_00568DE8)('-');
                    }
                    while (v != 0) {
                        *--p = func_002EA5C8(v, 10) + '0';
                        v = func_002E9C38(v, 10);
                    }
                }
                if (pad != 0 && pad < p) {
                    p = pad;
                }
                while (*p != '\0') {
                    ((void (*)(int))D_00568DE8)(*p++);
                }
                break;
            case 'u':
                if (mod == 'l') {
                    ap += 8;
                    uv = *(unsigned long *)(ap - 8);
                } else if (mod == 'h') {
                    ap += 8;
                    uv = *(unsigned short *)(ap - 8);
                } else {
                    ap += 8;
                    uv = *(unsigned int *)(ap - 8);
                }
                p = &buf[31];
                *p = '\0';
                if (uv == 0) {
                    *--p = '0';
                } else {
                    while (uv != 0) {
                        *--p = func_002EB260(uv, 10) + '0';
                        uv = func_002EAC90(uv, 10);
                    }
                }
                if (pad != 0 && pad < p) {
                    p = pad;
                }
                while (*p != '\0') {
                    ((void (*)(int))D_00568DE8)(*p++);
                }
                break;
            case 'e':
            case 'f': {
                float fv;
                ap += 8;
                fv = *(float *)(ap - 8);
                if (fv == 0.0f) {
                    ((void (*)(int))D_00568DE8)('0');
                } else {
                    func_002F9D78((double)fv);
                }
                break;
            }
            case 's': {
                char *sp;
                ap += 8;
                sp = *(char **)(ap - 8);
                if (*sp == '\0') {
                    ((void (*)(int))D_00568DE8)('(');
                    ((void (*)(int))D_00568DE8)('n');
                    ((void (*)(int))D_00568DE8)('u');
                    ((void (*)(int))D_00568DE8)('l');
                    ((void (*)(int))D_00568DE8)('l');
                    ((void (*)(int))D_00568DE8)(')');
                } else {
                    p = sp;
                    do {
                        ((void (*)(int))D_00568DE8)(*p++);
                    } while (*p != '\0');
                }
                break;
            }
            case 'c':
                ap += 8;
                v = *(signed char *)(ap - 8);
                ((void (*)(int))D_00568DE8)((int)v);
                break;
            default:
                break;
            }
        } else {
            ((void (*)(int))D_00568DE8)(*fmt);
        }
        fmt++;
    }
}

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

int func_002FA4A8(const char *fmt, ...)
{
    void *ap;

    R7_VA_START(ap, fmt, 7);
    return func_002F9EE0(fmt, ap);
}

int func_002FA4E0(const char *fmt, ...)
{
    void *ap;
    void *old;
    int ret;

    R7_VA_START(ap, fmt, 7);
    old = D_00568DE8;
    D_00568DE8 = func_002F9C00;
    ret = func_002F9EE0(fmt, ap);
    D_00568DE8 = old;
    return ret;
}

void func_002FA540(W11SlotSrc *a, W11SlotDst *b)
{
    b->tbl[a->idx] = a->val;
}

void func_002FA560(W11SlotSrc *a, W11SlotDst *b)
{
    b->out = a->idx;
}

int func_002FA570(int i)
{
    return D_007924C0[i];
}

int func_002FA588(int i, int v)
{
    return D_007924C0[i] = v;
}

u32 *func_002FA5A8(void)
{
    return D_00792398;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002FA5B8);

void func_002FA838(void)
{
    func_002F8ED8(5);
    func_002F8110(5, D_00792394);
    D_00568DEC = 0;
}

u32 func_002FA870(u32 a, u32 b)
{
    u32 old = D_00792398[5];

    D_00792398[5] = a;
    D_00792398[6] = b;
    return old;
}

u32 func_002FA888(u32 a, u32 b)
{
    u32 old = D_00792398[3];

    D_00792398[3] = a;
    D_00792398[4] = b;
    return old;
}

void func_002FA8A0(u32 id, void *handler, void *data)
{
    u32 offset = (u32)id * 8;
    R7Pair *entry;
    /* DEBT(CAST): command selectors and table addresses use the same 32-bit word view. */
    if ((s32)id < 0) id = (u32)D_007923A4;
    else id = (u32)D_007923AC;
    offset += id;
    entry = (R7Pair *)offset;
    entry->w0 = (int)handler;
    entry->w4 = (int)data;
}

void func_002FA8D0(u32 id)
{
    u32 offset = (u32)id * 8;
    R7Pair *entry;
    /* DEBT(CAST): command selectors and table addresses use the same 32-bit word view. */
    if ((s32)id < 0) id = (u32)D_007923A4;
    else id = (u32)D_007923AC;
    offset += id;
    entry = (R7Pair *)offset;
    entry->w0 = 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002FA8F8);

int func_002FAA30(int a, int b, int c, int d, int e, int f)
{
    return func_002FA8F8(a, 0, b, c, d, e, f);
}

int func_002FAA70(int a, int b, int c, int d, int e, int f)
{
    return func_002FA8F8(a, 1, b, c, d, e, f);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002FAAB0);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002FABD8);
