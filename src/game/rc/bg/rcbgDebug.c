/* tu_148 0x190f20-0x193c80: medium; rcbgDebug (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/w3.h"
#include "vu0.h"

R2AnimFrame *func_00190F20(R2Anim *a) {
    u32 flags = a->flags;
    R2AnimFrame *frame;

    if (a->n == 0) {
        return 0;
    }
    frame = &a->frames[a->cur];
    if (!(flags & 1)) {
        a->frac += a->speed;
        if (a->frac >= 0x100) {
            a->time += a->frac / 256;
            a->frac = a->frac % 256;
            while (frame->time < a->time) {
                a->time -= frame->time + 1;
                if (!(flags & 2)) {
                    a->cur = a->cur + 1;
                    if (a->cur >= a->n) {
                        switch (flags & 0xF00) {
                        case 0:
                            a->cur = 0;
                            break;
                        case 0x100:
                            a->cur = a->n - 1;
                            break;
                        }
                    }
                } else {
                    a->cur = a->cur - 1;
                    if (a->cur < 0) {
                        switch (flags & 0xF00) {
                        case 0:
                            a->cur = a->n - 1;
                            break;
                        case 0x100:
                            a->cur = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return frame;
}

R2AnimFrame *func_00191060(R2Anim *a, int i) {
    if (i < a->n) {
        return &a->frames[i];
    }
    return 0;
}

int *func_00191088(Q3Tab *t) {
    return &t->tab[t->idx];
}

void func_001910A0(void) {
    func_001921A8();
}

void func_001910A8(void) {
    func_001921B0();
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", rcbgFpSaveSub);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001910B8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001911A0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001912B8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191388);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001914C0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001916D0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191920);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191A70);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191A78);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191BF0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191BF8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191ED0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001921A8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001921B0);

void func_001921B8(void) {
}

void func_001921C0(void) {
}

void func_001921C8(void) {
}

void func_001921D0(void) {
}

void func_001921D8(void) {
}

void func_001921E0(float *m) {
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    func_0018F260(m, pool->fFC, pool->fFC, pool->fFC);
}

extern void func_001ACB48(float ang, void *out, float *eye, float *tgt, void *up);

void rcbgSetViewMatrix(void *out, float *eye, float *tgt, void *up, float ang)
{
    W3Core *core;
    W3Pool *pool;
    float e[4];
    float t[4];
    float *tp;
    int s;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    s = *(int *)&pool->fFC; /* DEBT(CAST): the scale is moved as raw bits */
    VU0_LQC2(31, 0, eye);
    VU0_QMTC2_NI(30, s);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, e);
    tp = t;
    VU0_LQC2(31, 0, tgt);
    VU0_QMTC2_NI(30, s);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, tp);
    func_001ACB48(ang, out, e, tp, up);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192280);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", rcbgSetProjectionMatrixSub);

u32 func_00192458(float z)
{
    W3Core *core;
    W3Pool *pool;
    float v[4];

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    if (pool != 0) {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * pool->fFC;
        v[3] = 1.0f;
    } else {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * 10.0f;
        v[3] = 1.0f;
    }
    func_002DCE08(v, D_00314260, v);
    return func_002ECF38(v[2] / v[3]); /* DEBT(FAKE): the (u32) conversion libcall (fptoui) is not linkable by its own name */
}

int func_00192508(float z)
{
    W3Core *core;
    W3Pool *pool;
    float v[4];
    int out[4];

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    if (pool != 0) {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * pool->fFC;
        v[3] = 1.0f;
    } else {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * 10.0f;
        v[3] = 1.0f;
    }
    func_002DCE08(v, D_00314260, v);
    v[2] = v[2] / v[3];
    func_002DD0E8(out, v);
    return out[2] / 0x3000;
}

void func_001925D8(void *a, void *b) {
    func_002DCE38(a, D_003142A0, b);
    func_002DCE38(a, D_00314260, a);
}

void func_00192618(u32 a0)
{
    __asm__ volatile(
        "lui        $3, (0x42C80000 >> 16)\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "addiu      $2, $4, 0x10\n"
        "lqc2       $vf31, 0x0($2)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $4, $4, 0x20\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) :  : "$2", "$3");
}

void rcCalcTex0Prm(int w, int h, int *tw, int *th, int *tbw) {
    if (tw != 0) {
        *tw = rcLog2(w);
    }
    if (th != 0) {
        *th = rcLog2(h);
    }
    if (tbw != 0) {
        *tbw = (w + 63) / 64;
        if (*tbw & 1) {
            *tbw = *tbw + 1;
        }
    }
}

void func_00192708(u64 *regs) {
    int n;
    int i;
    R2Qw *q;
    R2Pkt pkt;

    /* regs: (data, address) pairs for A+D, ended by address -1 */
    n = 0;
    for (i = 1; regs[i] != -1; i += 2) {
        n++;
    }
    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550); /* DEBT(TYPE): D_00303550 holds a buffer address but is declared s32 */
    q = pkt.cur;
    q->d.lo = n | (u64)1 << 60;
    q->d.hi = 0xE;
    q++;
    for (i = 0; i < n; i++) {
        q->d.lo = regs[i * 2];
        q->d.hi = regs[i * 2 + 1];
        q++;
    }
    pkt.cur = q;
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
}

void func_001927F8(void) {
    R2Pkt pkt;
    R2Qw *q;

    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550); /* DEBT(TYPE): D_00303550 holds a buffer address but is declared s32 */
    q = pkt.cur;
    q = func_00192848(q);
    pkt.cur = q;
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
}

R2Qw *func_00192848(R2Qw *p) {
    p->d.lo = 4 | (u64)1 << 60;
    p->d.hi = 0xE;
    p++;
    p->d.lo = D_006F2CE0.r30.data;
    p->d.hi = D_006F2CE0.r30.addr;
    p++;
    p->d.lo = D_006F2CE0.r60.data;
    p->d.hi = D_006F2CE0.r60.addr;
    p++;
    p->d.lo = D_006F2CE0.r70.data;
    p->d.hi = D_006F2CE0.r70.addr;
    p++;
    p->d.lo = D_006F2CE0.r80.data;
    p->d.hi = D_006F2CE0.r80.addr;
    return p + 1;
}

int func_001928C0(void) {
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", rcbgIDLoad);

void func_00192990(W3Voice *v)
{
    func_002EF0D0(v, 0, 0xC0);
    func_00190E38((R2Anim *)&v->sub90); /* DEBT(CAST): W3Voice.sub90 is the R2Anim block of t2.h */
    func_00198870(&v->subB0);
    v->i2C = v->i30 = 0x100;
    v->d38 = 0x44;
    v->rgba[0] = v->rgba[1] = v->rgba[2] = v->b43 = 0x80;
    v->f44 = v->f48 = 1.0f;
}

void rcbgLayerFini(W3Voice *v) {
    /* DEBT(TYPE): W3Voice.sub90 is really an R2Anim block */
    if (((R2Anim *)&v->sub90)->img != 0) {
        func_00199F18(((R2Anim *)&v->sub90)->img);
        ((R2Anim *)&v->sub90)->img = 0;
    }
    if (v->subB0.img != 0) {
        func_00199F18(v->subB0.img);
        v->subB0.img = 0;
    }
    func_00190E70((R2Anim *)&v->sub90);
    func_00198880(&v->subB0);
}

void func_00192A68(W3Voice *v)
{
    R2Anim *anim = (R2Anim *)&v->sub90; /* DEBT(CAST): W3Voice.sub90 is the R2Anim block of t2.h */
    R2AnimFrame *fr;

    fr = func_00190F20(anim);
    if (fr != 0) {
        func_0019A1A0(anim->img, fr->cell);
        func_00198CA8(&v->subB0, fr->cell);
    }
    func_00198908(&v->subB0);
    func_00192AD8(v);
}

void func_00192AD8(W3Voice *v)
{
    float t;

    if (v->i74 != 0) {
        v->i78++;
        t = (float)v->i78 / v->i74;
        v->f44 = v->f54 + (v->f58 - v->f54) * t;
        v->f48 = v->f5C + (v->f60 - v->f5C) * t;
        if (v->i78 >= v->i74) {
            v->i74 = 0;
        }
    }
    if (v->i7C != 0) {
        v->i80++;
        t = (float)v->i80 / v->i7C;
        v->f4C = v->f64 + (v->f68 - v->f64) * t;
        v->f50 = v->f6C + (v->f70 - v->f6C) * t;
        if (v->i80 >= v->i7C) {
            v->i7C = 0;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192BC0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192E00);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00193110);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001933D0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00193728);
