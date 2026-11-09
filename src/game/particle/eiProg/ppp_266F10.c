/* tu_287 0x266f10-0x268680: low; ~ppp (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#define pppSetMatrix _unused_pppSetMatrix
#include "ffx/s6.h"
#undef pppSetMatrix
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_00266F10(void)
{
    PtrTab3 tab = D_00573F88; /* unused local copy of the table */
}

void func_00266F40(void) {
}

void func_00266F48(R6Link *n) {
    func_002EF240(D_00573F98);
    for (; n != 0; n = n->next) {
        func_002EF240(D_00573FA8, n);
    }
}

void *pppMemAlloc(void *heap, void *sub, int size)
{
    void *p = pppAlloc(heap, size);

    D_0036F204 = 0;
    if (p == 0) {
        if (((int *)sub)[1] == 0 || (p = pppAlloc(sub, size)) == 0) { /* DEBT(CAST): sub heap header word 1 */
            func_002EF240(D_00573FB0, size);
            D_0036F204 = 1;
            return 0;
        }
    }
    return p;
}

int func_00267028(void *heap, void *sub, void *p)
{
    if (p != 0) {
        if ((HBlk *)p <= ((HHead *)heap)->last) { /* DEBT(CAST): heap header type of the prototype unknown */
            return pppFree(heap, p);
        } else {
            return pppFree(sub, p);
        }
    }
}

void func_00267070(ObjGroup *grp)
{
    int i;

    for (i = 0; i < grp->count; i++) {
        Child *c = grp->children[i];

        if (c->fn10 != 0) {
            c->fn10(grp);
        }
    }
}

void func_002670E0(ObjGroup *grp)
{
    int i;

    for (i = 0; i < grp->count; i++) {
        Child *c = grp->children[i];

        if (c->fn14 != 0) {
            c->fn14(grp);
        }
    }
}

void func_00267150(ObjGroup *grp)
{
    int i;

    for (i = 0; i < grp->count; i++) {
        Child *c = grp->children[i];

        if (c->fn18 != 0) {
            c->fn18(grp);
        }
    }
}

void func_002671C0(T6_PrObj *o)
{
    T6_PrDef *def = o->cls->def;
    int *w = (int *)((char *)o + def->ofs); /* DEBT(CAST): property words at a class-given offset */
    T6_PrEnt *e;
    int i;

    for (i = 0; i < def->n; i++) {
        e = &def->ent[i];
        *w++ = e->init;
        if (e->ops != 0 && e->ops->f20 != 0) {
            e->ops->f20(o, e);
        }
    }
}

void func_00267270(T6_PrObj *o)
{
    T6_PrDef *def = o->cls->def;
    int *w = (int *)((char *)o + def->ofs); /* DEBT(CAST): property words at a class-given offset */
    T6_PrEnt *e;
    int i;

    for (i = 0; i < def->n; i++) {
        e = &def->ent[i];
        *w++ = e->init;
        if (e->ops != 0 && e->ops->f1C != 0) {
            e->ops->f1C(o, e);
        }
    }
}

typedef struct PppObj {
    struct PppObj *next;
    u8 pad4[4];
    struct PppCls *cls;
    int wC;
    u8 pad10[0x80];
    int w90;
    int w94;
} PppObj;

typedef struct PppDef {
    u8 pad0[0x20];
    int ofs;
    s16 prio;
    s16 n;
} PppDef;

typedef struct PppCls {
    PppDef *def;
    PppObj *last;
    int w8;
    u16 refs;
} PppCls;

typedef struct PppMgr {
    u8 pad0[0x30];
    PppObj *list;
} PppMgr;

T6_Mem *func_00267320(T6_ColMgr *mgr, T6_MemEnt *e)
{
    PppMgr *m = (PppMgr *)mgr;
    PppCls *cls = (PppCls *)e;
    PppDef *def = cls->def;
    PppObj *o;
    PppObj *cur;
    PppObj **prev;
    int prio;

    o = pppMemAlloc(D_006A3924, &D_006A3924->sub, def->ofs + def->n * 4);
    if (o == 0) {
        return 0;
    }
    cur = m->list;
    o->wC = 0;
    o->w90 = 0;
    o->w94 = 0;
    o->cls = cls;
    if (cur == 0) {
        cls->last = o;
        m->list = o;
        o->next = 0;
    } else if (cls->last != 0) {
        *(PppObj **)o = cls->last->next;
        cls->last->next = o;
    } else {
        prio = def->prio;
        prev = &m->list;
        cur = m->list;
        do {
            if (cur->cls->def->prio >= prio) {
                cls->last = o;
                *prev = o;
                o->next = cur;
                goto done;
            }
            prev = &cur->next;
            cur = cur->next;
        } while (cur != 0);
        cls->last = o;
        *prev = o;
        o->next = 0;
    }
done:
    cls->refs++;
    func_00267270((T6_PrObj *)o);
    return (T6_Mem *)o;
}

void pppDeletePObject(T6_PrObj *o)
{
    T6_PrCls *cls = o->cls;
    T6_PrDef *def = cls->def;
    T6_PrEnt *e;
    int i;

    for (i = 0; i < def->n; i++) {
        e = &def->ent[i];
        if (e->ops != 0 && e->ops->f24 != 0) {
            e->ops->f24(o, e);
        }
    }
    if (--cls->refs == 0) {
        cls->last = 0;
    } else if (cls->last == o) {
        cls->last = o->next;
    }
    func_00267028(D_006A3924, D_006A3924->sub, o);
}

void _pppAllFreePObject(Slot80 *s)
{
    T6_PrObj *o;
    T6_PrObj *next;

    for (o = s->objs; o != 0; o = next) {
        next = o->next;
        pppDeletePObject(o);
    }
    s->objs = 0;
    if (s->buf != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->buf);
        s->buf = 0;
    }
    D_006A3BC8 = 0;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void pppSetMatrix(void *arg0) {
    register u8 *s0 __asm__("$16");
    register u8 *s1 __asm__("$17");
    register u8 *v0 __asm__("$2");
    register u8 *v1 __asm__("$3");
    register float f1 __asm__("$f1");
    register float f0 __asm__("$f0");

    s0 = (u8 *)&D_006A3930;
    s1 = (u8 *)arg0;
    pppGetRotMatrixXYZ((void *)s0, (void *)(s1 + 0x50));
    VU0_QMTC2_NI(9, *(float *)(s1 + 0x60));
    VU0_LQC2(10, 0, s0);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, s0);

    v0 = s0 + 0x10;
    VU0_QMTC2_NI(9, *(float *)(s1 + 0x64));
    VU0_LQC2(10, 0, v0);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, v0);

    v1 = s0 + 0x20;
    VU0_QMTC2_NI(9, *(float *)(s1 + 0x68));
    VU0_LQC2(10, 0, v1);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, v1);

    f1 = *(float *)(s1 + 0x40);
    *(float *)(s0 + 0x30) = f1;
    f0 = *(float *)(s1 + 0x44);
    *(float *)(s0 + 0x34) = f0;
    f1 = *(float *)(s1 + 0x48);
    *(float *)(s0 + 0x38) = f1;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", _pppStartPart);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", _pppInitPdt);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", _pppInitData);

void pppInitEnv(HeapMgr *m, HeapCfg *cfg, void *buf, int size)
{
    HeapMgrV *v = (HeapMgrV *)m; /* DEBT(CAST): HeapMgr describes sub as bytes */

    D_006A3924 = m;
    if (cfg != 0) {
        v->w20 = cfg->w14;
        v->tbl = cfg->tbl;
        v->p28 = cfg->p1C;
    }
    pppCreateHeap(&v->main, buf, size);
    v->sub.first = 0;
}

void func_00267AC0(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", func_00267AC8);

void func_00267F10(T6_ColMgr *m)
{
    T6_MemEnt *e;
    int i;

    for (i = 0; i < m->count; i++) {
        e = &m->p3C[i];
        if (m->p3C == 0 || e == 0) {
            continue;
        }
        if (m->w8 < e->w8) {
            continue;
        }
        e->w8 = 0x7FFFFFFF;
        if (func_00267320(m, e) == 0) {
            break;
        }
    }
}

typedef struct PppRunMgr {
    int w0;
    int w4;
    int w8;
    int wC;
    int w10;
    int w14;
    int w18;
    u8 b1C;
    u8 b1D;
    u8 pad1E[0x30 - 0x1E];
    void *p30;
} PppRunMgr;

void func_00267AC8(void *m);

int _pppRunPart(void *a, int flags)
{
    PppRunMgr *m = (PppRunMgr *)a;

    ppvMng = (T6_ColMgr *)m;
    if (flags & 0x10) {
        func_002670E0((ObjGroup *)m);
    }
    func_00267F10((T6_ColMgr *)m);
    func_00267AC8(m);
    if (flags & 0x20) {
        func_00267150((ObjGroup *)m);
    }
    if (D_006A3BC4 != 0) {
        return 0;
    }
    m->wC = m->w8;
    m->w8 += m->w10;
    if (m->b1C != 0) {
        if (m->b1D != 0) {
            return m->p30 == 0;
        }
        if (m->w8 > 0x6FFFFFFF) {
            m->w8 = 0x70000000;
            m->wC = 0x70000000 - m->w10;
        }
        return 0;
    }
    return m->w8 >= m->w4;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", func_00268080);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", _pppRunPartFp);

void func_00268610(NodeOwner *owner, void (**tbl)(), int c)
{
    Node8 *n = owner->list;
    Node8 *next;

    while (n != 0) {
        void (*fn)() = tbl[n->info->b0E];

        next = n->next;
        if (fn != 0) {
            fn(n, c);
        }
        n = next;
    }
}
