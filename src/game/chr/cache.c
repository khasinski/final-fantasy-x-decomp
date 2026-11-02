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

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_OverFlow);

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

INCLUDE_ASM("build/ee_asm/game/chr/cache", func_00110FA8);

INCLUDE_ASM("build/ee_asm/game/chr/cache", func_00111038);

void func_001110F0(void)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && (h->w8 & 7) == 0) {
            func_00110D38(h);
        }
    }
}

void func_00111158(void)
{
    s32 i;
    HandleB *h;

    for (i = 0; i < 100; i++) {
        h = (HandleB *)D_0057F2C0[i]; /* DEBT(CAST) */
        if (h->st != 0 && h->st != 7) {
            h->st--;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_Exist);

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
            h->w8 |= 7;
            return;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_Use);

void func_00111500(s32 a, s32 b)
{
    s32 i;
    Handle *h;

    for (i = 0; i < 100; i++) {
        h = D_0057F2C0[i];
        if (h->wC != 0 && h->w0 == b && h->b4 == a) {
            h->b5 = 0;
            h->w8 = (h->w8 & ~0xF8) | 0x40;
            func_0011CFB8(h->wC, 4);
            return;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_Entry_NotYet);

INCLUDE_ASM("build/ee_asm/game/chr/cache", Cache_Entry);

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
