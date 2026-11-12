/* tu_157 0x198f10-0x199e00: medium; rcbgScene (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/w3.h"

void func_00198F10(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    func_00199448(pool);
}

void func_00198F38(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    func_00199510(pool);
}

void func_00198F60(void)
{
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    func_001994E0(pool);
}

void func_00198F88(int i)
{
    W3Core *core;
    W3Pool *pool;

    core = 0;
    if (g_pMainWork != 0) {
        core = g_pMainWork->core;
    }
    if (core != 0 && i >= 0 && i < core->npool) {
        core->pool = &core->pools[i];
        rcbgSceneChkSortLayer((S2Table *)core->pool); /* DEBT(TYPE): s2.h declares the pool as S2Table */
        if (core->npool >= 2) {
            pool = core->pools;
        } else {
            pool = core->pool;
        }
        rcbgGuideSetModelFromIdMap(g_pMainWork->sub, pool->items[pool->curItem]);
    }
}

void rcbgSceneInit(W3Pool *o) {
    func_002EF0D0(o, 0, 0x120);
    o->flags = 1;
    o->fFC = 10.0f;
}

void rcbgSceneFini(W3Pool *p)
{
    int i;

    for (i = 0; i < p->count; i++) {
        rcbgLayerFini(&p->voices[i]);
    }
    p->count = 0;
    if (p->voices != 0) {
        func_0018FC10(p->voices);
        p->voices = 0;
    }
    for (i = 0; i < p->nobj; i++) {
        if (p->objs[i]->dtor != 0) {
            p->objs[i]->dtor(p->objs[i]);
        }
    }
    p->nobj = 0;
    if (p->objs != 0) {
        func_0018FC10(p->objs);
        p->objs = 0;
    }
    if (p->buf14 != 0) {
        func_0018FC10(p->buf14);
        p->buf14 = 0;
    }
    for (i = 0; i < p->numItems; i++) {
        if (p->items[i] != 0) {
            rcbgModelDelete(p->items[i]);
            p->items[i] = 0;
        }
    }
    p->numItems = 0;
}

void func_001991D8(W3Pool *p, W3Item *o)
{
    p->nobj++;
    p->objs = _rcRealloc(p->objs, p->nobj * 4, D_0056DB10, 0x58);
    p->objs[p->nobj - 1] = o;
}

int rcbgSceneAddObject(R2KeyList *l, int key) {
    int i;
    int n = 0;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i]->key == key) {
            n++;
        }
    }
    return n;
}

W3Item *func_00199288(W3Pool *p, int id, int n) {
    int cnt;
    int i;
    W3Item *found;

    cnt = 0;
    found = 0;
    for (i = 0; i < p->nobj; i++) {
        if (p->objs[i]->id == id) {
            if (cnt == n) {
                found = p->objs[i];
                break;
            }
            cnt++;
        }
    }
    return found;
}

void func_001992F8(W3Pool *p, W3Item *o) {
    W3Item *it;
    int i;

    for (i = 0; i < p->nobj; i++) {
        it = p->objs[i];
        if (it == o) {
            if (it->dtor != 0) {
                it->dtor(it);
            }
            for (; i < p->nobj - 1; i++) {
                p->objs[i] = p->objs[i + 1];
            }
            p->nobj--;
            p->objs = _rcRealloc(p->objs, p->nobj * sizeof(W3Item *), D_0056DB10, 156);
        }
    }
}

void func_001993E0(W3Pool *p, int id) {
    while (rcbgSceneAddObject((R2KeyList *)p, id) > 0) { /* DEBT(CAST): the key list is the object list of the pool */
        func_001992F8(p, func_00199288(p, id, 0));
    }
}

void func_00199448(W3Pool *p) {
    W3Item *o;
    int i;

    for (i = 0; i < p->nobj; i++) {
        o = p->objs[i];
        if (o->update != 0) {
            o->update(o);
        }
    }
    if (p->count != 0) {
        rcbgSceneSetMatrix(p);
    }
    func_001999A8(p);
    func_00199B48(p);
    func_00199580(p);
}

void func_001994E0(W3Pool *p) {
    func_001998D0(p);
    func_00199630(p, 0, 1);
}

void func_00199510(W3Pool *p) {
    W3Item *o;
    int i;

    for (i = 0; i < p->nobj; i++) {
        o = p->objs[i];
        if (o->draw != 0) {
            o->draw(o);
        }
    }
    func_001995E0(p);
}

void func_00199580(W3Pool *p) {
    W3Voice *v = p->voices;
    int i;

    for (i = 0; i < p->count; i++) {
        func_00192A68(v);
        v++;
    }
}

void func_001995E0(W3Pool *p) {
    func_00199630(p, 0, 0);
    func_002B2E10(func_00199620, p, 0, 1);
}

void func_00199620(W3Pool *p) {
    func_00199630(p, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgScene", func_00199630);

int func_001999A0(void);

void func_001998D0(W3Pool *p)
{
    float v[4];
    Chr *chr;
    W3Core *core;

    if (p->i10C != 0 || func_001999A0() != 0) {
        chr = Sg_GetPlayer();
        if (chr != 0) {
            Ch_GetPos(chr, &v[0], &v[1], &v[2]);
            v[3] = 1.0f;
            func_002DCE08(v, D_003142A0, v);
            *(float *)&p->pad100[8] = (v[2] / v[3]) * 0.1f;
        } else {
            *(float *)&p->pad100[8] = 98.0f;
        }
    } else {
        *(float *)&p->pad100[8] = 0.0f;
    }
    core = W3_CORE();
    core->w10 = 0;
}

int func_001999A0(void)
{
    return 0;
}

typedef struct {
    u8 pad00[0x64];
    int i64;
    u8 pad68[8];
    float v70[4];
    float v80[4];
    float v90[4];
    u8 padA0[0x10];
    float fB0;
    float fB4;
    float fB8;
    float fBC;
    float fC0;
    float fC4;
    int iC8;
    float fCC;
    int iD0;
    int iD4;
    int iD8;
    float fDC;
    int iE0;
    int iE4;
    float fE8;
    int iEC;
    float fF0;
    float fF4;
    int iF8;
    float fFC;
} RcbgScenePool;

float rcbgSetProjectionMatrixSub(float *m, int a, float *fov, float b, float c, float d);
void func_0019A718(float a, float b, float c, float d, float e);
void rcbgSetViewMatrix(float *out, float *eye, float *tgt, float *up, float ang);

void func_001999A8(W3Pool *pool)
{
    RcbgScenePool *p = (RcbgScenePool *)pool;
    float s;
    float f;
    int odd;

    if (p->iC8 != 0) {
        odd = p->iC8 & 1;
        s = eff_sin_t[(((u32)(int)(p->fDC * 65536.0f / 6.2831855f) + 0x4000) >> 4) & 0xFFF];
        switch ((p->iC8 - 1) / 2) {
        case 0:
            break;
        case 1:
            if (p->iD0 > 0) {
                s *= (float)(p->iD0 - p->iE0) / (float)p->iD0;
            }
            break;
        }
        if (p->iD8 > 0) {
            f = (float)(p->iD4 + func_002EFD78() % p->iD8);
        } else {
            f = (float)p->iD4;
        }
        if (odd != 0) {
            p->fC0 = s * f;
        } else {
            p->fC4 = s * f;
        }
        p->fDC += p->fCC;
        p->iE0++;
        if (p->iD0 > 0 && p->iE0 >= p->iD0) {
            func_00199B30(pool);
        }
        rcbgSceneSetMatrix(pool);
    }
}

void func_00199B30(W3Pool *pool)
{
    pool->iC8 = 0;
    pool->fC0 = pool->fC4 = 0;
}

void func_00199B48(W3Pool *pool)
{
    RcbgScenePool *p = (RcbgScenePool *)pool;
    float s;

    if (p->iE4 != 0) {
        s = eff_sin_t[((u32)(int)(p->fF4 * 65536.0f / 6.2831855f) >> 4) & 0xFFF];
        switch (p->iE4) {
        case 1:
            break;
        case 2:
            if (p->iEC > 0) {
                s *= (float)(p->iEC - p->iF8) / (float)p->iEC;
            }
            break;
        }
        p->fB4 = s * p->fF0;
        p->fF4 += p->fE8;
        p->iF8++;
        if (p->iEC > 0 && p->iF8 >= p->iEC) {
            func_00199C50(pool);
        }
        rcbgSceneSetMatrix(pool);
    }
}

void func_00199C50(W3Pool *pool)
{
    pool->fB4 = 0;
    pool->iE4 = 0;
}

void func_00199C60(W3Pool *pool)
{
    W3Voice *voice;
    int i;

    for (i = 0, voice = pool->voices; i < pool->count; i++, voice++) {
        func_00198CA8(&voice->subB0, 0);
    }
}

void rcbgSceneSetMatrix(W3Pool *pool)
{
    RcbgScenePool *p = (RcbgScenePool *)pool;
    float m0[16];
    float m1[16];
    float fov;
    Chr *chr;
    Rec142F0 *scr = ms_screen;

    if (p->fB0 != 0.0f) {
        chr = Sg_GetPlayer();
        if (chr != 0) {
            Ch_SetClipZ(chr, 1000.0f);
        }
        p->fB8 = rcbgSetProjectionMatrixSub(m0, 1, &fov, p->fB0, p->fC0, p->fC4 + (float)p->i64);
        p->fBC = p->fB8 * (7.0f / 6.0f);
        func_0019A718(512.0f / p->fB8, 416.0f / p->fBC, scr->f1C, scr->f08, scr->f0C);
        rcbgSetViewMatrix(m1, p->v70, p->v80, p->v90, p->fB4);
        fov += 256.0f;
        MsSetCameraMatrix(fov, 1, (int)m0, (int)m1, (int)p->v80, (int)p->v70);
    }
}
