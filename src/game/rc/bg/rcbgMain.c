/* tu_150 0x1944c0-0x194f80: medium; rcbgMain (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"

void func_001944C0(W3ImgPair *o, W3Reader *r) {
    func_0019DE78(r, &o->h10, 2);
    func_0019DE78(r, &o->h12, 2);
    func_0019D878(r, 12);
    func_00194420(&o->img20, r);
    func_00194420(&o->img60, r);
}

void func_00194530(void) {
    if (g_pMainWork != 0) {
        rcbgFini();
    }
    g_pMainWork = _rcCalloc(1, 0x1C, D_0056D840, 46);
    g_pMainWork->sub = rcbgGuideNew();
    func_002DD128((struct W3Whole *)D_00313850); /* DEBT(CAST): matrices are passed as the W3Whole view */
    func_002DD128((struct W3Whole *)D_003138D0);
    func_002DD128((struct W3Whole *)D_00313910);
    func_002DD128((struct W3Whole *)D_00313950);
    if (FFXIsDebug() && FFXIsPC()) {
        func_001910A0();
    }
}

void rcbgFini(void) {
    if (g_pMainWork != 0) {
        if (g_pMainWork->core != 0) {
            rcbgPreFini();
        }
        if (FFXIsDebug() && FFXIsPC()) {
            func_001910A8();
        }
        if (g_pMainWork->sub != 0) {
            func_00195B40(g_pMainWork->sub);
            g_pMainWork->sub = 0;
        }
        if (g_pMainWork->buf10 != 0) {
            rcdtChunkDelete(g_pMainWork->buf10);
            g_pMainWork->buf10 = 0;
        }
        if (g_pMainWork->buf14 != 0) {
            rcdtChunkDelete(g_pMainWork->buf14);
            g_pMainWork->buf14 = 0;
        }
        if (g_pMainWork->buf18 != 0) {
            rcdtChunkDelete(g_pMainWork->buf18);
            g_pMainWork->buf18 = 0;
        }
        if (g_pMainWork != 0) {
            func_0018FC10(g_pMainWork);
            g_pMainWork = 0;
        }
    }
}

void func_001946E0(void) {
    if (FFXIsDebug() && FFXIsPC()) {
        func_001947E0();
    }
    if (g_pMainWork->w08 == 0) {
        func_00194830();
    }
    if (g_pMainWork != 0 && g_pMainWork->core != 0) {
        func_00198F10();
    }
    if (FFXIsDebug() && FFXIsPC()) {
        func_001912B8();
    }
}

void func_00194780(void) {
    if (g_pMainWork != 0 && g_pMainWork->core != 0) {
        func_00198F38();
    }
}

void func_001947B0(void) {
    if (g_pMainWork != 0 && g_pMainWork->core != 0) {
        func_00198F60();
    }
}

void func_001947E0(void) {
    int v;

    if (g_pMainWork->w0C == 0) {
        v = func_001AEBD8();
        if (v != 0) {
            g_pMainWork->w0C = v;
            g_pMainWork->w08 = 0;
        }
    }
}

void func_00194830(void) {
    if (g_pMainWork == 0 || g_pMainWork->core == 0) {
        rcbgPreDummyInit();
    }
    if (FFXIsDebug() && FFXIsPC() && g_pMainWork->w08 == 0) {
        rcbgFpSaveSub();
    }
    func_00194948(func_001948C0());
    g_pMainWork->w08 = 1;
}

int func_001948C0(void) {
    int v = func_001AEBD8();

    if (v != 0) {
        switch (v) {
        case 0x610000:
            v = 0x61;
            break;
        case 0x2350000:
            v = 0x235;
            break;
        case 0x2360000:
            v = 0x236;
            break;
        default:
            v = 0;
            break;
        }
    } else {
        v = func_0013A278();
    }
    return v;
}

void func_00194948(int id) {
    switch (id) {
    case 0x235:
    case 0x236:
        func_001949E0(func_0019B888());
        break;
    case 0x61:
        func_001949E0(func_0019ACB8());
        break;
    case 0xAD:
        func_001949E0(rcbgFPm173New());
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgMain", func_001949E0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgMain", func_00194A50);

void *func_00194AB0(int a, int b) {
    W3Core *c;
    void *ret;
    W3Pool *p;

    c = W3_CORE();
    ret = 0;
    if (c != 0) {
        p = G2_GetPool();
        if (p != 0) {
            ret = func_00199288(p, a, b);
        }
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgMain", func_00194B10);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgMain", func_00194BE8);

void func_00194C18(int id) {
    if (G2_GetCore() != 0 && G2_GetPool() != 0) {
        func_001993E0(G2_GetPool(), id);
    }
}

void func_00194C80(YnChunk *c) {
    W3Pair blk;
    W3Reader rd;
    W3Pool *pool;
    W3Pool *p;
    W3Core *core;
    YnChunk *h;
    void *o;
    int npool;
    int id;
    int size;

    pool = 0;
    if (func_00194F08(c->tag) != 0) {
        return;
    }
    c++;
    npool = 0;
    for (;;) {
        h = c;
        id = func_00194F08(c->tag);
        size = c->size * 16;
        c++;
        func_0019D518(&blk, c);
        rcdtParseInit(&rd);
        rcdtParseSet(&rd, &blk);
        switch (id) {
        case 1:
            rcbgPreInit();
            rcbgPreLoad(&rd);
            break;
        case 2:
            pool = &W3_CORE()->unk4[npool++];
            rcbgSceneLoad(pool, &rd);
            break;
        case 5:
            rcbgSceneModelLoad(pool, &rd);
            break;
        case 6:
            func_001941A0(pool, &rd);
            break;
        case 8:
            o = func_0019A4A8();
            func_001944C0(o, &rd);
            func_001949E0(o);
            break;
        case 10:
            o = func_0019A6D8();
            func_001944C0(o, &rd);
            func_001949E0(o);
            break;
        case 11:
            core = W3_CORE();
            if (core == 0) {
                rcbgPreDummyInit();
                core = W3_CORE();
            }
            p = &core->unk4[h->index];
            if (p->items[p->numItems] != 0) {
                rcbgModelDelete(p->items[p->numItems]);
            }
            o = rcbgModelNew();
            rcbgModelLoad(o, &rd);
            p->items[p->numItems] = o;
            p->numItems++;
            break;
        case 7:
            break;
        case 12:
            return;
        default:
            func_0018F5E8(D_0056D850, D_0056D840, 0x1F1);
            func_0018F5E8(D_0056D868);
            break;
        }
        func_0019D6C8((W3Pair *)&rd); /* DEBT(CAST): declared with W3Pair, it is the reader destructor */
        c = (YnChunk *)((u8 *)c + size);
    }
}

char *func_00194EF0(int id) {
    return D_003136D8[id];
}

int func_00194F08(char *tag) {
    int i;
    int r = -1;

    for (i = 0; D_003136D8[i] != 0; i++) {
        if (func_002F0A58(tag, D_003136D8[i], 4) == 0) {
            r = i;
            break;
        }
    }
    return r;
}
