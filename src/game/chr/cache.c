/* tu_017 0x110cd8-0x111b50: medium; cache (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/s0.h"

void func_00110CD8(Handle *h) {
}

void Cache_Dump(void)
{
    int i;

    for (i = 0; i < 100; i++) {
        func_00110CD8(D_0057F2C0[i]);
    }
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00110D28(s32 v)
{
    D_0057F5E0 = v;
}

s32 func_00110D38(void *p) /* DEBT(TYPE): returns nothing */
{
    Handle *h = p;

    h->w0 = -1;
    func_0011D590(h->wC, 6);
    h->wC = 0;
}

void func_00111AA0(void);

s32 Cache_OverFlow(void)
{
    s32 i;
    Handle *h;
    s32 min_st = 100;
    s32 min_wC = 0xFFFFFFF;
    Handle *best = 0;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0) {
            if (h->b6 == 0) {
                if (h->b5 == 0) {
                    if ((h->u8.w & 7) != 7) {
                        if (h->u8.b.st < min_st) {
                            best = h;
                            min_st = h->u8.b.st;
                        }
                        if (h->u8.b.st == min_st && h->wC < min_wC) {
                            best = h;
                            min_wC = h->wC;
                        }
                    }
                }
            }
        }
    }
    if (best != 0) {
        func_00110D38(best);
        func_00111AA0();
        return 0;
    }
    return 1;
}

s32 func_00110E38(s32 kind, s32 id, s32 force)
{
    int i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == id && h->b4 == kind) {
            if (h->b5 != 0 && force != 0) {
                return -1;
            }
            func_00110D38(h);
            return 0;
        }
    }
    return 1;
}

void func_00110EB8(s32 kind, s32 force)
{
    int i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->b4 == kind && (h->b5 == 0 || force == 0)) {
            func_00110D38(h);
        }
    }
}

void func_00110F48(void)
{
    s32 i;

    for (i = 0; i < 100; i++) {
        Handle *h = D_0057F2C0[i];

        if (h->wC && h->b5 == 0) {
            func_00110D38(h);
        }
    }
    func_00111AA0();
}

void func_00110FA8(void)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->b5 == 0 && (h->u8.w & 7) != 5 && (h->u8.w & 7) != 7) {
            func_00110D38(h);
        }
    }
    func_00111AA0();
}

int func_00111038(int a, int b)
{
    s32 i, j;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            for (j = i; j < 99; j++) {
                D_0057F2C0[j] = D_0057F2C0[j + 1];
            }
            D_0057F2C0[99] = h;
            if ((h->u8.w & 7) != 7) {
                h->u8.w = (h->u8.w & ~7) | 5;
            }
            return 0;
        }
    }
    return 1;
}

void func_001110F0(void)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && (h->u8.w & 7) == 0) {
            func_00110D38(h);
        }
    }
}

void func_00111158(void)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->u8.b.st != 0 && h->u8.b.st != 7) {
            h->u8.b.st--;
        }
    }
}

extern char D_00569658[], D_00569668[];

s32 Cache_Exist(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            if (h->b6 != 0) {
                yiAssert(0, D_00569658, D_00569668, a, b, h->wC);
            }
            return h->wC;
        }
    }
    return 0;
}

void func_00111250(s32 a, s32 b, s32 v)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->b7 = v;
            return;
        }
    }
}

s32 Cache_CheckYet(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            if (h->b6) {
                return 1;
            }
            return 0;
        }
    }
    return 2;
}

s32 Cache_Exist2(s32 kind, s32 id)
{
    s32 r = Cache_CheckYet(kind, id);

    if (r == 2) {
        yiAssert(0, D_00569698, D_005696B0, ch_create_name(id));
    }
    return r;
}

s32 Cache_Exist3(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            return h->wC;
        }
    }
    return 0;
}

void Cache_Lock(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->u8.w |= 7;
            return;
        }
    }
}

s32 Cache_Use(int a, int b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->b5 = 1;
            func_00111038(a, b);
            if (h->b4 == 1) {
                func_0011CFB8(h->wC, 2);
            } else if (h->b4 == 2) {
                func_0011CFB8(h->wC, 3);
            }
            return;
        }
    }
}

void func_00111500(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->b5 = 0;
            h->u8.w = (h->u8.w & ~0xF8) | 0x40;
            func_0011CFB8(h->wC, 4);
            return;
        }
    }
}

extern char D_00569658[], D_005696C8[], D_005696F0[], D_005696F8[], D_00569700[];

void Cache_Entry_NotYet(int a, int b, int c)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->b6 = c;
            return;
        }
    }
    ((s32 (*)(s32))Sg_MemDump)(0);
    yiAssert(0, D_00569658, D_005696C8, c, ch_create_name(b), b >> 16, a == 1 ? D_00569700 : (a == 2 ? D_005696F0 : D_005696F8));
}

void Cache_Entry(s32 a, s32 b, s32 c)
{
    s32 i;
    Handle *h;

retry:
    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC == 0) {
            h->w0 = b;
            h->b4 = a;
            h->u8.b.st = 5;
            h->u8.b.rest = 0;
            h->wC = c;
            h->b5 = 0;
            h->b6 = 0;
            h->b7 = 0;
            func_0011CFB8(c, 4);
            return;
        }
    }
    if (Cache_OverFlow() == 0) {
        goto retry;
    }
}

void func_00111758(void)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = &D_0057EC80[i];
        D_0057F2C0[i] = h;
        h->wC = 0;
    }
    D_0057F5E0 = 0;
}

void func_00111798(int n, int desc)
{
    s32 i, j, k;
    Handle *t;

    for (i = 0; i < n; i++) {
        k = i;
        for (j = i; j < n; j++) {
            if (desc) {
                if ((u32)D_0057F450[k]->wC < (u32)D_0057F450[j]->wC) {
                    k = j;
                }
            } else {
                if ((u32)D_0057F450[j]->wC < (u32)D_0057F450[k]->wC) {
                    k = j;
                }
            }
        }
        t = D_0057F450[i];
        D_0057F450[i] = D_0057F450[k];
        D_0057F450[k] = t;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_SweepBG);

void func_00111AA0(void)
{
    while (Cache_SweepBG(0) != 0) {
    }
}

void func_00111AC0(void)
{
    func_00110F48();
}

void func_00111AC8(void)
{
    func_00110FA8();
}

int Sg_CacheDisposeChr(int v)
{
    func_00110E38(2, v, 1);
    func_00110E38(2, v | 0x10000, 1);
    func_00110E38(2, v | 0x20000, 1);
    func_00110E38(2, v | 0x30000, 1);
    return func_00110E38(1, v, 1);
}
