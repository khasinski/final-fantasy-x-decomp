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
    if (core != 0 && i >= 0 && i < core->unk0) {
        core->pool = &core->unk4[i];
        rcbgSceneChkSortLayer((S2Table *)core->pool); /* DEBT(TYPE): s2.h declares the pool as S2Table */
        if (core->unk0 >= 2) {
            pool = core->unk4;
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

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgScene", func_001998D0);

int func_001999A0(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgScene", func_001999A8);

void func_00199B30(W3Pool *pool)
{
    pool->iC8 = 0;
    pool->fC0 = pool->fC4 = 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgScene", func_00199B48);

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

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgScene", rcbgSceneSetMatrix);
