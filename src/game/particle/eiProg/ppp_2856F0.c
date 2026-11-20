/* tu_307 0x2856f0-0x288570: low; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/r6.h" /* needed by t6.h (R6Fvec) */
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_002856F0(char *base, EvMsgB *ev, ScriptCtx *ctx) {
    Wkh0b2 *w;
    int cnt;

    if (D_006A3BC4 == 0) {
        cnt = ev->b7;
        if (cnt != 0) {
            w = SLOT_WORK(Wkh0b2, base, ctx, 0);
            if (w->b2 != 0) {
                w->b2--;
            } else {
                w->b2 = cnt;
                if (ev->wC != 0xFFFFFFFF && ev->w14 != 0xFFFFFFFF) {
                    if (func_0027F180(base, ev, func_00285540, &w->h0, ev->h4, ev->b8, ev->b6)) {
                        w->b2--;
                    }
                }
            }
        }
    }
}

void func_00285790(char *base, ScriptCtx *ctx) {
    Wkh0b2 *w = SLOT_WORK(Wkh0b2, base, ctx, 0);

    w->h0 = 0;
    w->b2 = 0;
}

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[3];
    int idx;
    int ofsC;
} EvBornCmlp;

typedef struct {
    void *p0;
    int w4;
    float f8;
} WkBornCmlp;

void func_00282830(void *a0, void *a1, void *a2);

void KeBornPtCmlp(char *base, void *ev, ScriptCtx *ctx, int *out) {
    EvBornCmlp *p = ev;
    T6_Mem **mp = (T6_Mem **)out;
    T6_MemEnt *e = &ppvMng->p3C[p->idx];
    T6_Mem *m;
    char *s7;
    WkBornCmlp *s5;
    float f20, f21;
    Vec4 sp0, sp10, sp20;

    if (e == 0) {
        *mp = 0;
    } else {
        m = func_00267320(ppvMng, e);
        *mp = m;
        if (m == 0) {
            return;
        }
        m->user = (ScriptWork *)base;
    }
    s7 = (char *)*mp + (p->ofsC + 0xA0);
    func_00282798(s7, SLOT_WORK(void, base, ctx, 1));
    s5 = SLOT_WORK(WkBornCmlp, base, ctx, 0);
    if (s5->p0 == 0) {
        s5->f8 = 1.0f / (float)(p->b4 + 1);
    } else {
        func_002DD0B0(&sp0, s5->p0);
        func_002DD038(&sp10, (Vec4 *)s7, &sp0);
        f20 = p->b4;
        f21 = s5->f8;
        while (f20 > 0.0f) {
            char *s0;
            float t;

            e = &ppvMng->p3C[p->idx];
            if (e == 0) {
                *mp = 0;
            } else {
                m = func_00267320(ppvMng, e);
                *mp = m;
                if (m == 0) {
                    return;
                }
                m->user = (ScriptWork *)base;
            }
            t = f21 * f20;
            s0 = (char *)*mp + (p->ofsC + 0xA0);
            f20 -= 1.0f;
            func_002DD068(&sp20, &sp10, t);
            func_00282830(s0, &sp0, &sp20);
        }
    }
    s5->p0 = s7;
}

void func_002859B8(char *base, EvMsgC *p, ScriptCtx *ctx) {
    int out[4];

    if (D_006A3BC4 == 0) {
        if (p->w8 != 0xFFFFFFFF && p->w10 != 0xFFFFFFFF) {
            KeBornPtCmlp(base, p, ctx, out);
        }
    }
}

void func_00285A00(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 0);

    w->w0 = 0;
}

int func_00285A18(float *v, float *out)
{
    float x = v[0];
    float y = v[1];
    float a;
    double t;

    a = x * y; /* DEBT(FAKE): the product shares the result variable (register steering) */
    if (a > 0.0f) {
        a = -3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
        t = func_002E76D0(func_002ED038(y / x));
        a = func_002EC440(func_002EBBB0(func_002ED038(a), t));
    } else if (a < 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
        t = func_002E76D0(func_002ED038(x / y));
        a = func_002EC440(func_002EBC08(func_002ED038(a), t));
    } else if (x != 0.0f) {
        a = 3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
    } else if (y != 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
    } else {
        return 0;
    }
    *out = a;
    return 1;
}

float func_00282A58(float x);
extern double D_00574408;
extern double D_00574410;

void func_00285B98(char *base, void *unused, ScriptCtx *ctx) {
    Wkf0f4f8 *s0;
    Wkw0w4w8 *s2;
    float f20, f21;
    float v[4];
    float out;

    if (D_006A3BC4 == 0) {
        s0 = SLOT_WORK(Wkf0f4f8, base, ctx, 1);
        f20 = s0->f4;
        f21 = s0->f0;
        if (f20 != 0.0f || f21 != 0.0f || s0->f8 != 0.0f) {
            s2 = SLOT_WORK(Wkw0w4w8, base, ctx, 0);
            v[0] = -f20;
            v[1] = f21;
            if (func_00285A18(v, &out) != 0) {
                register double x __asm__("$2") = func_002ED038(out * 32768.0f);
                register double d __asm__("$5");
                __asm__ volatile(".set noat; lui $1, %%hi(D_00574408); ld %0, %%lo(D_00574408)($1); .set at" : "=r"(d));
                s2->w8 = func_002EC2A0(func_002EBF18(x, d));
            }
            v[0] = func_00282A58(f20 * f20 + f21 * f21);
            v[1] = -s0->f8;
            if (func_00285A18(v, &out) != 0) {
                register double x __asm__("$2") = func_002ED038(out * 32768.0f);
                register double d __asm__("$5");
                __asm__ volatile(".set noat; lui $1, %%hi(D_00574410); ld %0, %%lo(D_00574410)($1); .set at" : "=r"(d));
                s2->w0 = func_002EC2A0(func_002EBF18(x, d));
            }
        }
    }
}

void func_00282B88(s32, s32, u8 *, float);
void func_00282E68(void *, s32, void *, s32, s32, s32, s32, void *, u16 *, s32);

void func_00285CF0(void *arg0, void *arg1, void *arg2) {
    float temp_f1;
    float temp_f2;
    float temp_f3;
    s32 temp_a0;
    s32 temp_s2;
    u32 temp_a3;
    u8 *temp_s0;
    u8 *temp_s0_2;
    void *temp_s3;

    temp_s3 = arg0 + ((*(s32 *)((u8 *)(*(void **)((u8 *)arg2 + 0xC)) + 8)) + 0xA0);
    if (D_006A3BC4 == 0) {
        temp_f3 = *(float *)((u8 *)temp_s3 + 8);
        temp_f2 = *(float *)((u8 *)temp_s3 + 4) + temp_f3;
        temp_f1 = *(float *)((u8 *)temp_s3 + 0) + temp_f2;
        *(float *)((u8 *)temp_s3 + 4) = temp_f2;
        *(float *)((u8 *)temp_s3 + 0) = temp_f1;
        if (*(s32 *)((u8 *)arg0 + 0xC) == *(s32 *)((u8 *)arg1 + 0)) {
            *(float *)((u8 *)temp_s3 + 0) = temp_f1 + *(float *)((u8 *)arg1 + 8);
            *(float *)((u8 *)temp_s3 + 4) = temp_f2 + *(float *)((u8 *)arg1 + 0xC);
            *(float *)((u8 *)temp_s3 + 8) = temp_f3 + *(float *)((u8 *)arg1 + 0x10);
        }
    }
    temp_a0 = *(s32 *)((u8 *)arg1 + 4);
    if (temp_a0 != 0xFFFF) {
        temp_s2 = *(u8 *)((u8 *)arg1 + 0x1C) * 4;
        temp_a3 = *(u32 *)((u8 *)D_006A3924->res + (temp_a0 << 5) + 0x10);
        temp_s0 = D_006A3BCC + 0x10;
        func_002DA928(temp_s0, ((temp_a3 >> 5) & 0x3FFF) + temp_s2, 4, (temp_a3 >> 0x13) & 0xF, 0, 0, 0x10, 0x10);
        *(u64 *)(temp_s0 + 0x50) = (0x08000000ULL << 32) | 0x8100;
        temp_s0_2 = D_006A3BCC;
        func_00282B88(*(s32 *)((u8 *)arg1 + 0x14), *(s32 *)((u8 *)arg1 + 0x18), temp_s0_2 + 0x70, *(float *)((u8 *)temp_s3 + 0));
        func_002B2A28(D_006A3BCC, 0x107, 0, 0);
        D_006A3BCC = temp_s0_2 + 0x1070;
        func_00282E68(arg0, *(s32 *)((u8 *)arg1 + 4), arg0 + ((*(s32 *)((u8 *)(*(void **)((u8 *)arg2 + 0xC)) + 0)) + 0xA0), temp_s2, 0, 0, 1, 0, ppvMng->scale, ppvMng->w78);
    }
}

void func_00285EA8(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

void func_00285EC8(void *arg0, void *arg1, void *arg2) {
    Wkf0f4f8f10f14f18f1Cf20f24 *temp_s3;
    s32 temp_a0;
    s32 temp_s2;
    u32 temp_a3;
    u8 *temp_s0;
    u8 *temp_s0_2;

    temp_s3 = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, arg0, (ScriptCtx *)arg2, 2);
    if (D_006A3BC4 == 0) {
        temp_s3->f4 += temp_s3->f8;
        temp_s3->f0 += temp_s3->f4;
        temp_s3->f14 += temp_s3->f18;
        temp_s3->f10 += temp_s3->f14;
        temp_s3->f20 += temp_s3->f24;
        temp_s3->f1C += temp_s3->f20;
        if (*(s32 *)((u8 *)arg0 + 0xC) == *(s32 *)((u8 *)arg1 + 0)) {
            temp_s3->f0 += *(float *)((u8 *)arg1 + 8);
            temp_s3->f4 += *(float *)((u8 *)arg1 + 0xC);
            temp_s3->f8 += *(float *)((u8 *)arg1 + 0x10);
            temp_s3->f10 += *(float *)((u8 *)arg1 + 0x20);
            temp_s3->f14 += *(float *)((u8 *)arg1 + 0x24);
            temp_s3->f18 += *(float *)((u8 *)arg1 + 0x28);
            temp_s3->f1C += *(float *)((u8 *)arg1 + 0x2C);
            temp_s3->f20 += *(float *)((u8 *)arg1 + 0x30);
            temp_s3->f24 += *(float *)((u8 *)arg1 + 0x34);
        }
    }
    temp_a0 = *(s32 *)((u8 *)arg1 + 4);
    if (temp_a0 != 0xFFFF) {
        temp_s2 = *(u8 *)((u8 *)arg1 + 0x1C) * 4;
        temp_a3 = *(u32 *)((u8 *)D_006A3924->res + (temp_a0 << 5) + 0x10);
        temp_s0 = D_006A3BCC + 0x10;
        func_002DA928(temp_s0, ((temp_a3 >> 5) & 0x3FFF) + temp_s2, 4, (temp_a3 >> 0x13) & 0xF, 0, 0, 0x10, 0x10);
        *(u64 *)(temp_s0 + 0x50) = (0x08000000ULL << 32) | 0x8100;
        temp_s0_2 = D_006A3BCC;
        func_00282B88(*(s32 *)((u8 *)arg1 + 0x14), *(s32 *)((u8 *)arg1 + 0x18), temp_s0_2 + 0x70, temp_s3->f0);
        func_002B2A28(D_006A3BCC, 0x107, 0, 0);
        D_006A3BCC = temp_s0_2 + 0x1070;
        func_00282E68(arg0, *(s32 *)((u8 *)arg1 + 4), arg0 + ((*(s32 *)((u8 *)(*(void **)((u8 *)arg2 + 0xC)) + 0)) + 0xA0), temp_s2, (s32)temp_s3->f10, (s32)temp_s3->f1C, 1, 0, ppvMng->scale, ppvMng->w78);
    }
}

void func_00286110(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8f10f14f18f1Cf20f24 *w = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->f10 = w->f14 = w->f18 = w->f1C = w->f20 = w->f24 = 0.0f;
}

extern T6_ColMgr *ppvMng_6150 __asm__("ppvMng.NON_MATCHING");

void func_00286150(void *arg0, void *arg1, void *arg2) {
    Wkf0f4f8 *temp_s0;
    s32 temp_a1;
    s32 temp_s7;
    u32 temp_a3;
    u8 *temp_s2;
    u8 *temp_s3;
    u8 *temp_s0_2;

    temp_s0 = SLOT_WORK(Wkf0f4f8, arg0, (ScriptCtx *)arg2, 2);
    if (D_006A3BC4 == 0) {
        temp_s0->f4 += temp_s0->f8;
        temp_s0->f0 += temp_s0->f4;
        if (*(s32 *)((u8 *)arg0 + 0xC) == *(s32 *)((u8 *)arg1 + 0)) {
            temp_s0->f0 += *(float *)((u8 *)arg1 + 8);
            temp_s0->f4 += *(float *)((u8 *)arg1 + 0xC);
            temp_s0->f8 += *(float *)((u8 *)arg1 + 0x10);
        }
    }
    temp_a1 = *(s32 *)((u8 *)arg1 + 4);
    if (temp_a1 != 0xFFFF) {
        temp_s7 = *(u8 *)((u8 *)arg1 + 0x1C) * 4;
        temp_a3 = *(u32 *)((u8 *)D_006A3924->res + (temp_a1 << 5) + 0x10);
        temp_s2 = D_006A3BCC + 0x10;
        func_002DA928(temp_s2, ((temp_a3 >> 5) & 0x3FFF) + temp_s7, 4, (temp_a3 >> 0x13) & 0xF, 0, 0, 0x10, 0x10);
        *(u64 *)(temp_s2 + 0x50) = (0x08000000ULL << 32) | 0x8100;
        temp_s3 = D_006A3BCC;
        temp_s0_2 = temp_s3 + 0x70;
        func_00282B88(*(s32 *)((u8 *)arg1 + 0x14), *(s32 *)((u8 *)arg1 + 0x18), temp_s0_2, temp_s0->f0);
        if (*(u8 *)((u8 *)arg1 + 0x1D) & 2) {
            func_002F8660(0);
            func_002DAC50(temp_s2, (s32)temp_s0_2);
        } else {
            *(u64 *)(temp_s2 + 0x50) = (0x08000000ULL << 32) | 0x8100;
            func_002B2A28(D_006A3BCC, 0x107, 0, 0);
            D_006A3BCC = temp_s3 + 0x1070;
        }
        func_00282E68(arg0, *(s32 *)((u8 *)arg1 + 4), arg0 + ((*(s32 *)((u8 *)(*(void **)((u8 *)arg2 + 0xC)) + 0)) + 0xA0), temp_s7, 0, 0, *(u8 *)((u8 *)arg1 + 0x1D), 0, ppvMng_6150->scale, ppvMng_6150->w78);
    }
}

void func_00286348(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 2);

    w->w0 = 0;
    w->w4 = 0;
    w->w8 = 0;
}

void func_00286368(void *arg0, void *arg1, void *arg2) {
    Wkf0f4f8f10f14f18f1Cf20f24 *temp_s0;
    s32 temp_a1;
    s32 temp_fp;
    u32 temp_a3;
    u8 *temp_s2;
    u8 *temp_s4;
    u8 *temp_s3;

    temp_s0 = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, arg0, (ScriptCtx *)arg2, 2);
    if (D_006A3BC4 == 0) {
        temp_s0->f4 += temp_s0->f8;
        temp_s0->f0 += temp_s0->f4;
        temp_s0->f14 += temp_s0->f18;
        temp_s0->f10 += temp_s0->f14;
        temp_s0->f20 += temp_s0->f24;
        temp_s0->f1C += temp_s0->f20;
        if (*(s32 *)((u8 *)arg0 + 0xC) == *(s32 *)((u8 *)arg1 + 0)) {
            temp_s0->f0 += *(float *)((u8 *)arg1 + 8);
            temp_s0->f4 += *(float *)((u8 *)arg1 + 0xC);
            temp_s0->f8 += *(float *)((u8 *)arg1 + 0x10);
            temp_s0->f10 += *(float *)((u8 *)arg1 + 0x20);
            temp_s0->f14 += *(float *)((u8 *)arg1 + 0x24);
            temp_s0->f18 += *(float *)((u8 *)arg1 + 0x28);
            temp_s0->f1C += *(float *)((u8 *)arg1 + 0x2C);
            temp_s0->f20 += *(float *)((u8 *)arg1 + 0x30);
            temp_s0->f24 += *(float *)((u8 *)arg1 + 0x34);
        }
    }
    temp_a1 = *(s32 *)((u8 *)arg1 + 4);
    if (temp_a1 != 0xFFFF) {
        temp_fp = *(u8 *)((u8 *)arg1 + 0x1C) * 4;
        temp_a3 = *(u32 *)((u8 *)D_006A3924->res + (temp_a1 << 5) + 0x10);
        temp_s2 = D_006A3BCC + 0x10;
        func_002DA928(temp_s2, ((temp_a3 >> 5) & 0x3FFF) + temp_fp, 4, (temp_a3 >> 0x13) & 0xF, 0, 0, 0x10, 0x10);
        *(u64 *)(temp_s2 + 0x50) = (0x08000000ULL << 32) | 0x8100;
        temp_s4 = D_006A3BCC;
        temp_s3 = temp_s4 + 0x70;
        func_00282B88(*(s32 *)((u8 *)arg1 + 0x14), *(s32 *)((u8 *)arg1 + 0x18), temp_s3, temp_s0->f0);
        if (*(u8 *)((u8 *)arg1 + 0x38) & 2) {
            func_002F8660(0);
            func_002DAC50(temp_s2, (s32)temp_s3);
        } else {
            *(u64 *)(temp_s2 + 0x50) = (0x08000000ULL << 32) | 0x8100;
            func_002B2A28(D_006A3BCC, 0x107, 0, 0);
            D_006A3BCC = temp_s4 + 0x1070;
        }
        func_00282E68(arg0, *(s32 *)((u8 *)arg1 + 4), arg0 + ((*(s32 *)((u8 *)(*(void **)((u8 *)arg2 + 0xC)) + 0)) + 0xA0), temp_fp, (s32)temp_s0->f10, (s32)temp_s0->f1C, *(u8 *)((u8 *)arg1 + 0x38), 0, ppvMng->scale, ppvMng->w78);
    }
}

void func_002865F0(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8f10f14f18f1Cf20f24 *w = SLOT_WORK(Wkf0f4f8f10f14f18f1Cf20f24, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->f10 = w->f14 = w->f18 = w->f1C = w->f20 = w->f24 = 0.0f;
}

typedef struct {
    u64 x00;
    u64 x08;
    void *x10;
    void *x14;
    u8 *x18;
    T6_LtShape *x1C;
    float x20;
    int x24;
    u64 x28;
    float *x30;
    float *x34;
    int x38;
    int x3C;
    int x40;
    void *x44;
    int pad48[2];
} Req6630;

typedef struct {
    int id;
    int idx;
    float f8;
    float fC;
    float f10;
    u8 b14;
    u8 b15;
} Ev6630;

typedef struct {
    float f0;
    float f4;
    union {
        float f8;
        int *p8;
    } u;
} Wk6630;

typedef struct {
    u64 frame;
    u8 pad08[0x18];
    u64 zbuf;
    u8 pad28[8];
    u64 xyoffset;
    u8 pad38[0x170 - 0x38];
} DBuffDraw6630;

typedef struct {
    u8 pad0[0x60];
    DBuffDraw6630 draw[2];
} DBuffDC6630;

extern T6_ColMgr *ppvMng_6630 __asm__("ppvMng");
extern u8 *D_006A3BCC_6630 __asm__("D_006A3BCC.NON_MATCHING");
void func_00286940(Req6630 *req);

#define SCE_GS_SET_TEX0_6630(tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp0) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
     ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
     ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

void func_00286630(ScriptWork *base, Ev6630 *msg, ScriptCtx *ctx) {
    T6_ColMgr *mgr = ppvMng_6630;
    int *slot = ctx->info->slot;
    void *w2 = (char *)base + (slot[2] + 0xA0);
    Wk6630 *s0 = (Wk6630 *)((char *)base + (slot[0] + 0xA0));
    s16 *t1;
    int a;
    Req6630 req;
    float col[4];
    int dbuf;
    DBuffDraw6630 *draw;

    if (D_006A3BC4 == 0) {
        s0->f4 += s0->u.f8;
        s0->f0 += s0->f4;
        if (base->owner == msg->id) {
            s0->f0 += msg->f8;
            s0->f4 += msg->fC;
            if (msg->b14 < 4) {
                s0->u.f8 += msg->f10;
            }
        }
    }
    if (msg->idx == 0xFFFF) {
        return;
    }
    t1 = (s16 *)((char *)base + (slot[1] + 0xA0));
    a = t1[3] * ppvMng_6630->scale[3];
    if (a == 0) {
        return;
    }
    col[3] = (float)a * 1.4901161e-8f;
    col[0] = (float)(t1[0] * ppvMng_6630->scale[0]) * 1.4901161e-8f;
    col[1] = (float)(t1[1] * ppvMng_6630->scale[1]) * 1.4901161e-8f;
    col[2] = (float)(t1[2] * ppvMng_6630->scale[2]) * 1.4901161e-8f;
    req.x10 = D_006A3A70;
    req.x14 = w2;
    req.x30 = col;
    req.x34 = col;
    req.x18 = D_006A3BCC_6630;
    req.x1C = D_006A3924->res[msg->idx].shape;
    req.x20 = s0->f0 * mgr->m60[0];
    req.x24 = msg->b15;
    req.x44 = ((T6_LtWork *)base)->pts;
    if (msg->b14 >= 4 && s0->u.p8 != 0) {
        int v = *s0->u.p8;
        req.x3C = msg->b14 & 8;
        req.x40 = 1;
        req.x38 = v;
    } else {
        req.x40 = 0;
    }
    draw = &((DBuffDC6630 *)Sg_GetDBuffDC(&dbuf))->draw[(dbuf + msg->b14) & 1];
    if (msg->b14 < 2) {
        req.x08 = SCE_GS_SET_TEX0_6630((draw->frame & 0xFF) << 5, (draw->frame >> 16) & 0x3F, (draw->frame >> 24) & 0x3F, 10, 10, 0, 0, 0, 0, 0, 0, 0);
    } else {
        req.x08 = (((draw->frame >> 16) & 0x3F) << 14) | 0x2A8201A00ULL;
    }
    req.x28 = draw->xyoffset;
    req.x00 = draw->zbuf;
    func_00286940(&req);
    D_006A3BCC_6630 = req.x18;
    if (msg->b14 >= 4 && s0->u.p8 != 0) {
        *s0->u.p8 = req.x38;
    }
}

void func_00286900(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}

void func_00286920(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00286940);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", func_00287058);

void func_00287948(void) {
}

void func_00287950(void) {
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_2856F0", pppKeMdlBmpDraw);
