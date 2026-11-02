/* tu_161 0x19bad8-0x19cfe0: low; ~Yn (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void Yn_BgInit(void) {
    func_00194530();
}

void Yn_BgEnd(void) {
    if (g_pMainWork != 0) {
        rcbgFini();
    }
}

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
void Yn_PreBgSetData(a)
    void *a;
{
    if (g_pMainWork != 0) {
        if (a != 0) {
            func_00194C80(a);
            func_00198F88(0);
        }
    }
}

void func_0019BB40(void) {
    if (g_pMainWork != 0) {
        func_001946E0();
    }
}

void func_0019BB60(void) {
    if (g_pMainWork != 0) {
        func_00194780();
    }
}

void func_0019BB80(void) {
    if (g_pMainWork != 0) {
        func_001947B0();
    }
}

void func_0019BBA0(int v)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        pool->i10C = v;
    }
}

void func_0019BBD0(int a)
{
    if (g_pMainWork != 0) {
        func_00198F88(a);
    }
}

int func_0019BBF0(void)
{
    return 0;
}

void func_0019BBF8(void)
{
}

void func_0019BC00(void)
{
}

int func_0019BC08(void)
{
    W3Core *core;
    W3Pool *pool;
    int n;

    n = 0;
    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            n = pool->count;
        }
    }
    return n;
}

void func_0019BC38(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->flags &= ~1;
    }
}

void func_0019BCA8(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->flags |= 1;
    }
}

void func_0019BD10(int idx, int a, int b)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->i0C = a;
        voice->i10 = b;
    }
}

int func_0019BD88(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i0C;
    }
    return ret;
}

int func_0019BDF0(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i10;
    }
    return ret;
}

void func_0019BE58(int idx, float f)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->f14 = f;
    }
}

float func_0019BEC0(int idx)
{
    W3Voice *voice;
    float ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->f14;
    }
    return ret;
}

void func_0019BF20(int idx, int a, int b)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->i24 = a;
        voice->i28 = b;
    }
}

int func_0019BF98(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i24;
    }
    return ret;
}

int func_0019C000(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i28;
    }
    return ret;
}

void func_0019C068(int idx, int a, int b)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->i04 = a;
        voice->i08 = b;
    }
}

int func_0019C0E0(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i04;
    }
    return ret;
}

int func_0019C148(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->i08;
    }
    return ret;
}

void func_0019C1B0(int idx, int v)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->b43 = v;
    }
}

int func_0019C218(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->b43;
    }
    return ret;
}

int func_0019C280(int idx)
{
    W3Voice *voice;
    int ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = ((G2Sub90 *)&voice->sub90)->n; /* DEBT(CAST): W3Sub90 in types.h has u16 h8 + pad at +8 instead of s32 */
    }
    return ret;
}

void func_0019C2E8(int idx, int v)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.h6 = v;
    }
}

void func_0019C350(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.flags |= 1;
    }
}

void func_0019C3B8(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.flags &= ~1;
    }
}

void func_0019C428(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.flags |= 2;
    }
}

void func_0019C490(int idx)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.flags &= ~2;
    }
}

void func_0019C500(int idx, u32 v)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->sub90.flags = (voice->sub90.flags & 0xFFFFF0FF) | v;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/yn_19BAD8", func_0019C580);

float func_0019C5C0(void)
{
    W3Core *core;
    W3Pool *pool;
    float f;

    f = 0;
    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            f = pool->fC0;
        }
    }
    return f;
}

float func_0019C5F8(void)
{
    W3Core *core;
    W3Pool *pool;
    float f;

    f = 0;
    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            f = pool->fC4;
        }
    }
    return f;
}

void func_0019C630(int a, float f, int b, int c, int d)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        pool->iC8 = a;
        pool->fCC = f;
        pool->iD0 = b;
        pool->iD4 = c;
        pool->iD8 = d;
        pool->iDC = 0;
        pool->iE0 = 0;
    }
}

void func_0019C678(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        func_00199B30(pool);
    }
}

void func_0019C6A8(float f)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            pool->fB4 = f;
            rcbgSceneSetMatrix(pool);
        }
    }
}

float func_0019C6E0(void)
{
    W3Core *core;
    W3Pool *pool;
    float f;

    f = 0;
    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            f = pool->fB4;
        }
    }
    return f;
}

void func_0019C718(int a, float f, int b, float g)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        pool->iE4 = a;
        pool->fE8 = f;
        pool->iEC = b;
        pool->fF0 = g;
        pool->iF4 = 0;
        pool->iF8 = 0;
    }
}

void func_0019C758(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
        func_00199C50(pool);
    }
}

void func_0019C788(void)
{
    W3Pool *pool;

    if (g_pMainWork != 0) {
        pool = g_pMainWork->core ? g_pMainWork->core->pool : 0;
        if (pool != 0) {
            pool->flags |= 1;
        }
    }
}

void func_0019C7C8(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0)
    {
        /* DEBT(ORDER): shared pool expansion retains the original null fallback and register lifetimes. */
        V2_POOL(core, pool);
        if (pool != 0)
        {
            pool->flags &= ~1U;
        }
    }
}

void func_0019C810(int idx, int val)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->iA4 = val;
    }
}

void func_0019C878(int idx)
{
    W3Voice *voice;
    W3Sub90 *sub;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        sub = &voice->sub90;
        sub->h6 = sub->h8 - 1;
    }
}

void func_0019C8E0(int idx, float a, float b)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        if (a != 0) {
            voice->f44 = a;
        }
        if (b != 0) {
            voice->f48 = b;
        }
        voice->i78 = 0;
        voice->i74 = 0;
    }
}

void func_0019C980(int idx, float a, float b, int n)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        if (a != 0) {
            voice->f58 = a;
            voice->f54 = voice->f44;
        } else {
            voice->f54 = voice->f58 = voice->f44;
        }
        if (b != 0) {
            voice->f60 = b;
            voice->f5C = voice->f48;
        } else {
            voice->f5C = voice->f60 = voice->f48;
        }
        voice->i74 = n;
        voice->i78 = 0;
    }
}

float func_0019CA58(int idx)
{
    float ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        ret = W3_GetPool()->voices[idx].f44;
    }
    return ret;
}

float func_0019CAB8(int idx)
{
    float ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        ret = W3_GetPool()->voices[idx].f48;
    }
    return ret;
}

void func_0019CB18(int idx, float a, float b)
{
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        voice = W3_GetPool()->voices + idx;
        voice->f4C = a;
        voice->f50 = b;
        voice->i80 = 0;
        voice->i7C = 0;
    }
}

void func_0019CB98(int idx, float a, float b, int n)
{
    W3Core *core;
    W3Pool *pool;
    W3Voice *voice;

    if (idx < func_0019BC08()) {
        if (g_pMainWork != 0) {
            V2_POOL(core, pool);
        } else {
            pool = 0;
        }
        voice = pool->voices + idx;
        voice->f64 = voice->f4C;
        voice->f68 = a;
        voice->f6C = voice->f50;
        voice->f70 = b;
        voice->i7C = n;
        voice->i80 = 0;
    }
}

float func_0019CC38(int idx)
{
    W3Voice *voice;
    float ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->f4C;
    }
    return ret;
}

float func_0019CC98(int idx)
{
    W3Voice *voice;
    float ret;
    int count;

    count = func_0019BC08();
    ret = 0;
    if (idx < count) {
        voice = W3_GetPool()->voices + idx;
        ret = voice->f50;
    }
    return ret;
}

void func_0019CCF8(void) {
}

void func_0019CD00(void)
{
}

void func_0019CD08(void)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00196638(g_pMainWork->sub);
    }
}

void func_0019CD38(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00196640(g_pMainWork->sub, a);
    }
}

void func_0019CD68(void)
{
    Yn_PreBgSetData();
}

void func_0019CD70(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197A58(g_pMainWork->sub, a);
    }
}

void func_0019CDA0(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197B70(g_pMainWork->sub, a);
    }
}

void func_0019CDD0(int a, int b)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197B80(g_pMainWork->sub, a, b);
    }
}

void func_0019CE00(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197B98(g_pMainWork->sub, a);
    }
}

void func_0019CE30(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197BD0(g_pMainWork->sub, a);
    }
}

void func_0019CE60(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197C40(g_pMainWork->sub, a);
    }
}

void func_0019CE90(int a)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197C58(g_pMainWork->sub, a);
    }
}

void func_0019CEC0(float f)
{
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        func_00197CA8(g_pMainWork->sub, f);
    }
}

float func_0019CEF0(void)
{
    float ret;

    ret = 0;
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        ret = func_00197CB0(g_pMainWork->sub);
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/rc/yn_19BAD8", Yn_GuideMapSetMapNo);

int Yn_GuideMapGetMapNo(void)
{
    W3Core *core;
    W3Pool *pool;
    int n;

    n = -1;
    if (g_pMainWork != 0 && g_pMainWork->sub != 0) {
        V2_POOL(core, pool);
        if (pool != 0) {
            n = pool->curItem;
        }
    }
    return n;
}

void func_0019CFD8(void) {
    Yn_PreBgSetData();
}
