/* tu_294 0x26dad8-0x26f218: low; unk_26DAD8 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/w8.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/q6.h"

extern float eff_sin_t[];

void func_0026DAD8(ScriptWork *base, u32 *k, ScriptCtx *ctx)
{
    U4VecSrc *w;

    if (D_006A3BC4 == 0) {
        w = SLOT_WORK(U4VecSrc, base, ctx, 0);
        if (k[0] == (u32)base->owner) {
            if (k[1] != 0xFFFFFFFF) {
                w->src = (float *)(ppvMng->p3C[k[1]].base + (k[2] + 0xA0));
            } else {
                w->src = (float *)D_006EA450;
            }
        }
        w->v[0] = w->src[0];
        w->v[1] = w->src[1];
        w->v[2] = w->src[2];
    }
}

void func_0026DB70(int base, ScriptCtx *ctx)
{
    ScriptWorkFlags *w = (ScriptWorkFlags *)(ctx->info->slot[1] + base); /* DEBT(CAST): script memory base arrives as an int */

    w->bA1 = 0;
}

typedef struct Db88Key {
    int w0;
    u32 idx;
    int ofs;
    u8 cnt;
} Db88Key;

typedef struct Db88Flags {
    u8 b0;
    u8 b1;
} Db88Flags;

void func_0026DB88(ScriptWork *base, Db88Key *k, ScriptCtx *ctx)
{
    float *w0 = SLOT_WORK(float, base, ctx, 0);
    Db88Flags *w1 = SLOT_WORK(Db88Flags, base, ctx, 1);
    T6_MemEnt *ent;
    T6_Mem *mem;
    float *dst;

    if (D_006A3BC4 != 0) {
        return;
    }
    if (w1->b1 == 0) {
        if (k->idx == 0xFFFFFFFF) {
            return;
        }
        ent = &ppvMng->p3C[k->idx];
        if (ent == 0) {
            mem = 0;
        } else {
            mem = func_00267320(ppvMng, ent);
            if (mem == 0) {
                return;
            }
            mem->user = base;
        }
        dst = (float *)((char *)mem + (k->ofs + 0xA0));
        dst[0] = w0[0];
        dst[1] = w0[1];
        dst[2] = w0[2];
        w1->b1 = k->cnt;
    }
    w1->b1--;
}

void func_0026DC70(int base, ScriptCtx *ctx)
{
    ScriptWorkFlags *w = (ScriptWorkFlags *)(ctx->info->slot[1] + base); /* DEBT(CAST): see func_0026DB70 */

    w->bA1 = 0;
}

#define VU0_RAND(out, t) \
    MIPS_ADDI0(t, -1); \
    VU0_QMTC2_NI(2, t); \
    VU0_OP("vrxor R, $vf2x"); \
    VU0_OP("vitof0.x $vf2, $vf2"); \
    VU0_OP("vrnext.x $vf1, R"); \
    VU0_OP("vadd.x $vf1, $vf1, $vf2"); \
    VU0_QMFC2_NI(out, 1)

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026DC88);

typedef struct FxKey1F { int key; int dst; float d; u8 range; } FxKey1F;
typedef struct FxKey1B { int key; int dst; u8 d; u8 range; } FxKey1B;
typedef struct FxKey1H { int key; int dst; u16 d; u8 range; } FxKey1H;
typedef struct FxKey1W { int key; int dst; u32 d; u8 range; } FxKey1W;
typedef struct FxKey3I { int key; int dst; u8 pad8[8]; int d[3]; u8 pad1C[4]; u8 range; } FxKey3I;

void func_0026DE80(ScriptWork *base, FxKey1F *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a += b;
            } else {
                a += a;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        *dst += k->d * *v - k->d;
    }
}

void func_0026DF60(ScriptWork *base, FxKey1F *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a + b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        *dst += k->d * *v;
    }
}

void func_0026E048(ScriptWork *base, FxKey1F *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            a = -a;
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a - b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        *dst += k->d * *v;
    }
}

void func_0026E130(ScriptWork *base, FxKey1B *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a += b;
            } else {
                a += a;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u8 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u8 *)D_006EA450;
        }
        *dst += (u8)(int)(k->d * *v - k->d);
    }
}

void func_0026E220(ScriptWork *base, FxKey1B *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a + b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u8 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u8 *)D_006EA450;
        }
        *dst += (u8)(int)(k->d * *v);
    }
}

void func_0026E318(ScriptWork *base, FxKey1B *k, ScriptCtx *ctx)
{
    float *v;
    u8 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            a = -a;
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a - b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u8 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u8 *)D_006EA450;
        }
        *dst += (u8)(int)(k->d * *v);
    }
}

void func_0026E410(ScriptWork *base, FxKey1H *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a += b;
            } else {
                a += a;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u16 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u16 *)D_006EA450;
        }
        *dst += (u16)(int)(k->d * *v - k->d);
    }
}

void func_0026E500(ScriptWork *base, FxKey1H *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a + b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u16 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u16 *)D_006EA450;
        }
        *dst += (u16)(int)(k->d * *v);
    }
}

void func_0026E5F8(ScriptWork *base, FxKey1H *k, ScriptCtx *ctx)
{
    float *v;
    u16 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            a = -a;
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a - b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u16 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u16 *)D_006EA450;
        }
        *dst += (u16)(int)(k->d * *v);
    }
}

void func_0026E6F0(ScriptWork *base, FxKey1W *k, ScriptCtx *ctx)
{
    float *v;
    u32 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a += b;
            } else {
                a += a;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u32 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u32 *)D_006EA450;
        }
        *dst += (int)(k->d * *v - k->d);
    }
}

void func_0026E838(ScriptWork *base, FxKey1W *k, ScriptCtx *ctx)
{
    float *v;
    u32 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a + b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u32 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u32 *)D_006EA450;
        }
        *dst += (int)(k->d * *v);
    }
}

void func_0026E958(ScriptWork *base, FxKey1W *k, ScriptCtx *ctx)
{
    float *v;
    u32 *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            a = -a;
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a - b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (u32 *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (u32 *)D_006EA450;
        }
        *dst += (int)(k->d * *v);
    }
}

float func_0026EA78(float a, float b) {
    return a * b - a;
}

void func_0026EA88(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a += b;
            } else {
                a += a;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        dst[0] += func_0026EA78(k->d[0], *v);
        dst[1] += func_0026EA78(k->d[1], *v);
        dst[2] += func_0026EA78(k->d[2], *v);
    }
}

float func_0026EBB8(float a, float b) {
    return a * b;
}

void func_0026EBC0(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a + b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        dst[0] += func_0026EBB8(k->d[0], *v);
        dst[1] += func_0026EBB8(k->d[1], *v);
        dst[2] += func_0026EBB8(k->d[2], *v);
    }
}

float func_0026ED00(float a, float b) {
    return a * b;
}

void func_0026ED08(ScriptWork *base, T6_FxKeyF *k, ScriptCtx *ctx)
{
    float *v;
    float *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0) {
        if (base->owner == 0) {
            VU0_RAND(a, t);
            a = -a;
            if (k->range != 0) {
                VU0_RAND(b, t);
                a = (a - b) * 0.5f;
            }
            v = SLOT_WORK(float, base, ctx, 0);
            *v = a;
        } else if (k->key == base->owner) {
            v = SLOT_WORK(float, base, ctx, 0);
        } else {
            return;
        }
        if (k->dst != -1) {
            dst = (float *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (float *)D_006EA450;
        }
        dst[0] += func_0026ED00(k->d[0], *v);
        dst[1] += func_0026ED00(k->d[1], *v);
        dst[2] += func_0026ED00(k->d[2], *v);
    }
}

int func_0026EE48(int a, float s) {
    return a * s - a;
}

void func_0026EE68(ScriptWork *base, FxKey3I *k, ScriptCtx *ctx)
{
    float *v;
    int *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0 && k->key == base->owner) {
        VU0_RAND(a, t);
        if (k->range != 0) {
            VU0_RAND(b, t);
            a += b;
        } else {
            a += a;
        }
        v = SLOT_WORK(float, base, ctx, 0);
        *v = a;
        if (k->dst != -1) {
            dst = (int *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (int *)D_006EA450;
        }
        dst[0] += func_0026EE48(k->d[0], *v);
        dst[1] += func_0026EE48(k->d[1], *v);
        dst[2] += func_0026EE48(k->d[2], *v);
    }
}

int func_0026EF88(int a, float s) {
    return a * s;
}

void func_0026EFA8(ScriptWork *base, FxKey3I *k, ScriptCtx *ctx)
{
    float *v;
    int *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0 && k->key == base->owner) {
        VU0_RAND(a, t);
        if (k->range != 0) {
            VU0_RAND(b, t);
            a = (a + b) * 0.5f;
        }
        v = SLOT_WORK(float, base, ctx, 0);
        *v = a;
        if (k->dst != -1) {
            dst = (int *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (int *)D_006EA450;
        }
        dst[0] += func_0026EF88(k->d[0], *v);
        dst[1] += func_0026EF88(k->d[1], *v);
        dst[2] += func_0026EF88(k->d[2], *v);
    }
}

int func_0026F0D0(int a, float s) {
    return a * s;
}

void func_0026F0F0(ScriptWork *base, FxKey3I *k, ScriptCtx *ctx)
{
    float *v;
    int *dst;
    float a, b;
    register int t __asm__("$8");

    if (D_006A3BC4 == 0 && k->key == base->owner) {
        VU0_RAND(a, t);
        a = -a;
        if (k->range != 0) {
            VU0_RAND(b, t);
            a = (a - b) * 0.5f;
        }
        v = SLOT_WORK(float, base, ctx, 0);
        *v = a;
        if (k->dst != -1) {
            dst = (int *)((char *)base + (k->dst + 0xA0));
        } else {
            dst = (int *)D_006EA450;
        }
        dst[0] += func_0026F0D0(k->d[0], *v);
        dst[1] += func_0026F0D0(k->d[1], *v);
        dst[2] += func_0026F0D0(k->d[2], *v);
    }
}
