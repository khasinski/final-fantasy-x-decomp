/* tu_298 0x270bb8-0x276e00: medium; pppYanagi (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", prcPacketDataClose);

void func_00270C78(int *a)
{
    func_00270C80(*a);
}

void func_00270C80(int a)
{
    u32 *h = func_002DB6D8(2);

    func_002F8660(0);
    func_002DBA28(h, a);
    func_002DBF78(h, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00270CD8);

int func_00270DD8(char *m, char *v, int n) {
    register int f __asm__("$2");
    int c;

    VU0_LQC2(4, 0, m);
    VU0_LQC2(5, 0x10, m);
    VU0_LQC2(6, 0x20, m);
    VU0_LQC2(7, 0x30, m);
    f = 0x3F;
loop:
    VU0_LQC2(8, 0, v);
    MIPS_ADDI(v, 0x10);
    VU0_OP("vmulax.xyzw ACC, $vf4, $vf8x");
    VU0_OP("vmadday.xyzw ACC, $vf5, $vf8y");
    VU0_OP("vmaddaz.xyzw ACC, $vf6, $vf8z");
    VU0_OP("vmaddw.xyzw $vf9, $vf7, $vf8w");
    VU0_OP("vclipw.xyz $vf9, $vf9w");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_OP("vnop");
    VU0_CFC2_NI(c, 18);
    f &= c;
    if (f != 0) {
        MIPS_ADDI(n, -1);
        if (n > 0) {
            goto loop;
        }
    }
    return f;
}

void func_00270E40(float *v, float *d, int mode)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (mode == 0) {
            v[i] += func_002B3DB0(d[i]);
        } else {
            v[i] += func_002B3DB0(d[i]) * func_002B3DF8(1.0f);
        }
    }
}

void func_00270EE8(float *v, float *d, int mode)
{
    float r = func_002B3DB0(1.0f);

    if (mode == 0) {
        r = 2.0f * r;
    } else {
        r = r + func_002B3DB0(1.0f);
    }
    v[0] += d[0] * r - d[0];
    v[1] += d[1] * r - d[1];
    v[2] += d[2] * r - d[2];
}

void func_00270FA8(u64 tex0)
{
    func_002EF240(D_00574270, (int)(tex0 & 0x3FFF), (int)((tex0 >> 14) & 0x3F), (int)((tex0 >> 20) & 0x3F),
                  (int)((tex0 >> 26) & 0xF), (int)((tex0 >> 30) & 0xF), (int)((tex0 >> 34) & 1), (int)((tex0 >> 35) & 3));
    func_002EF240(D_005742A8, (int)((tex0 >> 37) & 0x3FFF), (int)((tex0 >> 51) & 0xF), (int)((tex0 >> 55) & 1),
                  (int)((tex0 >> 56) & 0x1F), (int)(tex0 >> 61));
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", prcPrintMatrix);

void prcPrintPacket(u64 *p, u64 *end)
{
    u64 tag;
    u64 regs;
    int nloop;
    int nreg;
    int i;
    int j;

    while (p < end) {
        tag = p[0];
        regs = p[1];
        nreg = tag >> 60;
        nloop = tag & 0x7FFF;
        func_002EF240(D_005742F8, nloop, nreg, regs, p, tag, regs);
        p += 2;
        for (i = 0; i < nloop; i++) {
            for (j = 0; j < nreg; j++) {
                switch (regs & 0xF) {
                case 3:
                    func_002EF240(D_00574328);
                    func_002EF240(D_00574338, func_002ED038(((float *)p)[0]), func_002ED038(((float *)p)[1]));
                    break;
                case 5:
                    func_002EF240(D_00574340);
                    func_002EF240(D_00574350, ((u32 *)p)[0] >> 4, ((u32 *)p)[1] >> 4, ((u32 *)p)[2]);
                    break;
                case 14:
                    func_002EF240(D_00574360);
                    func_002EF240(D_00574370, p[0]);
                    func_002EF240(D_00574380, p[1]);
                    break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 15:
                    break;
                }
                p += 2;
                regs >>= 4;
            }
        }
    }
}

int func_002713C0(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

    s->parts = pppMemAlloc(D_006A3924, D_006A3924->sub, k->count * 0xA0);
    if (s->parts == 0) {
        return 0;
    }
    func_002EF0D0(s->parts, 0, k->count * 0xA0);
    s->aux = pppMemAlloc(D_006A3924, D_006A3924->sub, 0xC);
    if (s->aux == 0) {
        return 0;
    }
    s->rec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 8);
    if (s->rec == 0) {
        return 0;
    }
    func_002EF0D0(s->rec, 0, s->nrec * 8);
    return 1;
}

void func_002714A0(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

    func_002DD128((struct W3Whole *)s); /* DEBT(CAST): prototype takes the W3Whole view */
    s->w48 = 0;
    s->parts = 0;
    s->w4C = 0;
    s->aux = 0;
    s->nrec = (life->len2 - life->start2) / 4096 + 1;
    s->rec = 0;
    s->done = 0;
}

void func_00271528(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);

    if (s->parts != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->parts);
        s->parts = 0;
    }
    if (s->aux != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->aux);
        s->aux = 0;
    }
    if (s->rec != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, s->rec);
        s->rec = 0;
    }
}

void func_002715A8(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysW *s = SLOT_WORK(T6_PSysW, o, ctx, 0);
    T6_PRec *src;
    Particle *p;
    int t;
    int i;
    int n;

    if (k->id == 0xFFFF) {
        return;
    }
    if (D_006A3924->tbl[k->id] == 0) {
        return;
    }
    if (s->parts == 0 && !func_002713C0(o, k, ctx)) {
        return;
    }
    t = o->t;
    n = t / 4096;
    if (s->done == 0 && n < s->nrec) {
        src = SLOT_WORK(T6_PRec, o, ctx, 1);
        s->rec[n].h[0] = src->h[0];
        s->rec[n].h[1] = src->h[1];
        s->rec[n].h[2] = src->h[2];
        i = 0; /* DEBT(FAKE): dead store, steers register allocation */
        s->rec[n].h[3] = src->h[3];
    }
    if (t >= life->len - 0x1000) {
        p = (Particle *)s->parts; /* DEBT(CAST): parts is declared as a word pointer */
        n = k->count;
        for (i = 0; i < n; i++, p++) {
            if (p->flags & 1) {
                break;
            }
        }
        if (i < n) {
            o->t = t - 0x1000;
        }
        s->done = 1;
    }
    if (D_006A3BC4 == 0 && ((u8 *)ppvMng)[0x1D] == 0) { /* DEBT(CAST): byte 0x1D of the manager */
        func_002718A0(o, k, ctx);
    }
    func_00271988(o, k, ctx, s);
    if (D_006A3BC4 == 0) {
        func_002725B8((PtEmitter *)k, (PtOwner *)s); /* DEBT(CAST): emitter/owner views of the key and work */
    }
}

void func_00271788(int *a)
{
    func_00270C78(a);
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00271790);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_002718A0);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00271988);

void func_002725B8(PtEmitter *e, PtOwner *o)
{
    PtAnim *anim = (PtAnim *)D_006A3924->tbl[e->anim]; /* DEBT(CAST): tbl is declared as DataRef ** */
    Particle *p = o->parts;
    PtKey *k;
    int i;
    u16 f;
    int n = e->count;

    for (i = 0; i < n; i++, p++) {
        if (p->flags & 1) {
            p->age++;
            k = &anim->keys[p->frame];
            if (p->age >= o->life) {
                p->flags &= ~1;
            }
            p->vel.x += e->vel.x;
            p->vel.y += e->vel.y;
            p->vel.z += e->vel.z;
            func_002DD020(&p->v10, &p->v10, &p->vel);
            p->acc.x += e->acc.x;
            p->acc.y += e->acc.y;
            p->acc.z += e->acc.z;
            p->pos.x += p->acc.x;
            p->pos.y += p->acc.y;
            p->pos.z += p->acc.z;
            p->time += e->speed.h;
            if (p->time >= k->dur) {
                p->time -= k->dur;
                f = p->frame;
                if (++p->frame >= anim->frames) {
                    if (k->flags & 0x80) {
                        p->frame = 0;
                    } else {
                        p->frame = f;
                    }
                    p->time = 0;
                }
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00272780);

void func_00272978(char *base, ScriptCtx *ctx) {
    R6Wkw68w6Cw70 *w = SLOT_WORK(R6Wkw68w6Cw70, base, ctx, 2);

    w->w70 = w->w6C = w->w68 = 0;
}

void func_00272998(char *base, ScriptCtx *ctx)
{
    Wkf54f58f60f64 *w = SLOT_WORK(Wkf54f58f60f64, base, ctx, 2);

    w->f54 = w->f58 = w->f60 = w->f64 = 0.0f;
}

void func_002729C0(char *base, ScriptCtx *ctx)
{
    Wkp68p6C *w = SLOT_WORK(Wkp68p6C, base, ctx, 2);

    if (w->p68 != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p68);
        w->p68 = 0;
    }
    if (w->p6C != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p6C);
        w->p6C = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00272A28);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00272F80);

void func_00273488(char *base, ScriptCtx *ctx) {
    R6WkwD0wD4wD8wDC *w = SLOT_WORK(R6WkwD0wD4wD8wDC, base, ctx, 2);

    w->wDC = w->wD8 = w->wD4 = w->wD0 = 0;
}

void func_002734B0(char *base, ScriptCtx *ctx)
{
    WkfBCfC0fC8fCC *w = SLOT_WORK(WkfBCfC0fC8fCC, base, ctx, 2);

    w->fBC = w->fC0 = w->fC8 = w->fCC = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_002734D8);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_002735F8);

int func_00274340(void)
{
    return D_00372FF4;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00274350);

void func_002746A8(char *base, ScriptCtx *ctx) {
    R6Wkw0w1C *w = SLOT_WORK(R6Wkw0w1C, base, ctx, 2);

    w->w1C = w->w0 = 0;
}

void func_002746C8(char *base, ScriptCtx *ctx)
{
    Wkf8fCf14f18 *w = SLOT_WORK(Wkf8fCf14f18, base, ctx, 2);

    w->f8 = w->fC = w->f14 = w->f18 = 0.0f;
}

void func_002746F0(char *base, ScriptCtx *ctx) {
    R6Ptr0 *w = SLOT_WORK(R6Ptr0, base, ctx, 2);

    if (w->p0 != 0) {
        func_00198318(w->p0);
        func_00197D38((int)w->p0);
        w->p0 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00274740);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00274A30);
INCLUDE_RODATA("build/ee_asm/game/particle/eiProg/pppYanagi/rodata", jtbl_005743D0);

int func_00274BC8(void *k, int *w)
{
    u32 *key = k; /* DEBT(TYPE): key record with the part count at 0x8 */
    u8 buf[16];
    char *m;
    u32 i;

    func_00275320(buf);
    m = pppMemAlloc(D_006A3924, D_006A3924->sub, key[2] * 0x30);
    w[1] = (int)m;
    if (m == 0) {
        return 0;
    }
    for (i = 0; i < key[2]; i++) {
        func_00274A30(m, k, buf, 0);
        m += 0x30;
    }
    w[0] = (int)k;
    return 1;
}

void func_00274C80(char *base, ScriptCtx *ctx) {
    Wkw0w4 *w = SLOT_WORK(Wkw0w4, base, ctx, 1);

    w->w4 = w->w0 = 0;
}

void func_00274CA0(char *base, ScriptCtx *ctx) {
    R6HeapRef2 *w = SLOT_WORK(R6HeapRef2, base, ctx, 1);

    if (w->p4 != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p4);
        w->p4 = 0;
    }
}

void func_00274CE8(char *base, void *k, ScriptCtx *ctx)
{
    int *w = SLOT_WORK(int, base, ctx, 1);

    if (*w == 0 && func_00274BC8(k, w) == 0) {
        return;
    }
    func_00274D80(base, k, ctx);
    func_00274FB0(base, k, ctx);
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00274D80);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00274FB0);

extern void func_002DCF48(void *dst, void *src);

void func_00275320(void *buf) {
    struct {
        char pad[0x30];
        u_long128 v;
    } t;

    func_002DCF48(&t, D_006A3970);
    VU0_LQC2(31, 0, &t.v);
    VU0_SQC2(31, 0, buf);
}

int func_00275360(int a0, int *p) /* DEBT(TYPE): no value, but func_00275388 returns its result */
{
    *p = a0;
}

void func_00275368(int base, ScriptCtx *ctx)
{
    ScriptWorkA0 *w = (ScriptWorkA0 *)(ctx->info->slot[1] + base); /* DEBT(CAST): script memory base arrives as an int */

    w->wA0 = 0;
}

void func_00275380(void) {
}

int func_00275388(char *base, int ev, ScriptCtx *ctx) /* DEBT(TYPE): returns func_00275360() (no value) */
{
    int *w = SLOT_WORK(int, base, ctx, 1);

    if (*w == 0) {
        return func_00275360(ev, w);
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_002753C8);

void func_002754B8(int base, ScriptCtx *ctx)
{
    ScriptWork128 *w = (ScriptWork128 *)(ctx->info->slot[2] + base); /* DEBT(CAST): see func_00275368 */

    w->w128 = 0;
}

void func_002754D0(char *base, ScriptCtx *ctx)
{
    Wkf74f78f80f84 *w = SLOT_WORK(Wkf74f78f80f84, base, ctx, 2);

    w->f74 = w->f78 = w->f80 = w->f84 = 0.0f;
}

void func_002754F8(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00275500);

int func_00275A68(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    s->parts = pppMemAlloc(D_006A3924, D_006A3924->sub, k->count * 0xA0);
    if (s->parts == 0) {
        return 0;
    }
    func_002EF0D0(s->parts, 0, k->count * 0xA0);
    s->rec = pppMemAlloc(D_006A3924, D_006A3924->sub, s->nrec * 8);
    if (s->rec == 0) {
        return 0;
    }
    func_002EF0D0(s->rec, 0, s->nrec * 8);
    return 1;
}

void func_00275B30(T6_PObj *o, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);

    func_002DD128((struct W3Whole *)s); /* DEBT(CAST): prototype takes the W3Whole view */
    s->w44 = 0;
    s->w48 = 0;
    s->parts = 0;
    s->rec = 0;
    s->nrec = (life->len - life->start) / 4096 + 1;
    s->done = 0;
}

void func_00275BB8(char *base, ScriptCtx *ctx)
{
    Wkp40p4C *w = SLOT_WORK(Wkp40p4C, base, ctx, 0);

    if (w->p40 != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p40);
        w->p40 = 0;
    }
    if (w->p4C != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->p4C);
        w->p4C = 0;
    }
}

void func_00275C20(T6_PObj *o, T6_PKey *k, ScriptCtx *ctx)
{
    T6_PLife *life = *o->life;
    T6_PSysB *s = SLOT_WORK(T6_PSysB, o, ctx, 0);
    T6_PRec *src;
    Particle *p;
    int t;
    int i;
    int n;

    if (k->id == 0xFFFF) {
        return;
    }
    if (D_006A3924->tbl[k->id] == 0) {
        return;
    }
    if (s->parts == 0 && !func_00275A68(o, k, ctx)) {
        return;
    }
    t = o->t;
    n = t / 4096;
    if (s->done == 0 && n < s->nrec) {
        src = SLOT_WORK(T6_PRec, o, ctx, 1);
        s->rec[n].h[0] = src->h[0];
        s->rec[n].h[1] = src->h[1];
        s->rec[n].h[2] = src->h[2];
        i = 0; /* DEBT(FAKE): dead store, steers register allocation */
        s->rec[n].h[3] = src->h[3];
    }
    if (t >= life->len - 0x1000) {
        p = (Particle *)s->parts; /* DEBT(CAST): parts is declared as a word pointer */
        n = k->count;
        for (i = 0; i < n; i++, p++) {
            if (p->flags & 1) {
                break;
            }
        }
        if (i < n) {
            o->t = t - 0x1000;
        }
        s->done = 1;
    }
    if (D_006A3BC4 == 0) {
        if (((u8 *)ppvMng)[0x1D] == 0) { /* DEBT(CAST): byte 0x1D of the manager */
            func_00275F00(o, k, ctx);
        }
        func_00276008(o, k, ctx, s);
        func_00276C38((PtEmitterB *)k, (PtOwnerB *)s); /* DEBT(CAST): emitter/owner views of the key and work */
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00275DF0);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00275F00);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/pppYanagi", func_00276008);

void func_00276C38(PtEmitterB *e, PtOwnerB *o)
{
    PtAnim *anim = (PtAnim *)D_006A3924->tbl[e->anim]; /* DEBT(CAST): tbl is declared as DataRef ** */
    Particle *p = o->parts;
    PtKey *k;
    int i;
    u16 f;
    int n = e->count;

    for (i = 0; i < n; i++, p++) {
        if (p->flags & 1) {
            p->age++;
            k = &anim->keys[p->frame];
            if (p->age >= o->life) {
                p->flags &= ~1;
            }
            p->vel.x += e->vel.x;
            p->vel.y += e->vel.y;
            p->vel.z += e->vel.z;
            func_002DD020(&p->v10, &p->v10, &p->vel);
            p->acc.x += e->acc.x;
            p->acc.y += e->acc.y;
            p->acc.z += e->acc.z;
            p->pos.x += p->acc.x;
            p->pos.y += p->acc.y;
            p->pos.z += p->acc.z;
            p->time += e->speed.h;
            if (p->time >= k->dur) {
                p->time -= k->dur;
                f = p->frame;
                if (++p->frame >= anim->frames) {
                    if (k->flags & 0x80) {
                        p->frame = 0;
                    } else {
                        p->frame = f;
                    }
                    p->time = 0;
                }
            }
        }
    }
}
