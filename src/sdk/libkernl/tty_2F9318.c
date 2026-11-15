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

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9750);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F98E8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9A38);

extern int D_00568DE4;
extern char D_00792240[];

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9B08);

int func_002F9BC8(int c)
{
    while (*(volatile u32 *)0x1000F130 & 0x8000) {
    }
    *(volatile u8 *)0x1000F180 = c;
    return c;
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

INCLUDE_ASM("build/ee_asm/sdk/libkernl/tty", func_002F9EE0);
INCLUDE_RODATA("build/ee_asm/sdk/libkernl/tty/rodata", jtbl_00578BC0);

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
