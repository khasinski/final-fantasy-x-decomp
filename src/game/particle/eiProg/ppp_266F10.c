/* tu_287 0x266f10-0x268680: low; ~ppp (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", func_00267320);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", pppSetMatrix);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_266F10", _pppRunPart);

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
