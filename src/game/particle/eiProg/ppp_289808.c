/* tu_309 0x289808-0x28b480: low; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/u4.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/q6.h"

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_00289808);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_00289B68);

void func_0028A2F8(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28w1F0h1F4b1F8 *w = SLOT_WORK(Wkq0q8q10q18q20q28w1F0h1F4b1F8, base, ctx, 0);

    w->b1F8 = 0;
    w->h1F4 = 0;
    w->w1F0 = 0;
    w->h1F6 = func_002EFD78();
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
}

void func_0028A350(char *base, ScriptCtx *ctx) {
    Wkq0q8q10q18q20q28w1F0h1F4b1F8 *w = SLOT_WORK(Wkq0q8q10q18q20q28w1F0h1F4b1F8, base, ctx, 0);

    w->b1F8 = 0;
    w->h1F4 = 0;
    w->w1F0 = 0;
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", func_0028A388);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_289808", pppKeShpTailPhtDraw);

void func_0028B050(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4 *w = SLOT_WORK(Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4, base, ctx, 0);

    w->b1F4 = 0;
    w->h1F0 = 0;
    w->w1EC = 0;
    w->h1F2 = func_002EFD78();
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
    w->f1E0 = w->f1E4 = w->f1E8 = 0.0f;
}

void func_0028B0B8(char *base, ScriptCtx *ctx)
{
    Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4 *w = SLOT_WORK(Wkq0q8q10q18q20q28f1E0f1E4f1E8w1ECh1F0b1F4, base, ctx, 0);

    w->b1F4 = 0;
    w->h1F0 = 0;
    w->w1EC = 0;
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
    w->q20 = 0;
    w->q28 = 0;
    w->f1E0 = w->f1E4 = w->f1E8 = 0.0f;
}

void func_0028B100(void) {
}

void func_0028B108(void) {
}

void func_0028B110(char *base, ScriptCtx *ctx) {
    Wkb0b1h2h4b6 *w = SLOT_WORK(Wkb0b1h2h4b6, base, ctx, 0);

    w->h2 = 0;
    w->h4 = 0;
    w->b1 = 0;
    w->b0 = 0x1F;
    w->b6 = 0;
}

void func_0028B140(void) {
}

typedef struct {
    s32 w0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    u8 b18;
    u8 b19;
} Ppp28B148Arg;

typedef struct {
    float v00[4];
    float v10[4];
    void *p20;
    u8 *p24;
    void *p28;
    s32 w2C;
    float v30[4];
    u64 q40;
    u64 q48;
    u64 q50;
    float f58;
    float f5C;
} Ppp28B148Ctx;

void func_002DCE08(void *, void *, void *);
void func_002830A0(void *);
int func_002832F0(void *);
void func_002B2A28(void *, u32, int, int);
void func_002B2AD8(void *, u32, int, int);

void func_0028B148(char *base, Ppp28B148Arg *arg, ScriptCtx *ctx)
{
    Ppp28B148Ctx sp;
    s32 dbIdx;
    s32 *slots = ctx->info->slot;
    u8 *mng = (u8 *)ppvMng;
    u8 *w2 = SLOT_WORK(u8, base, ctx, 2);
    float *w0 = SLOT_WORK(float, base, ctx, 0);
    s16 *w1;
    u8 *dbuf;
    u8 *ent;
    u64 fbp;

    if (D_006A3BC4 == 0) {
        w0[1] += w0[2];
        w0[0] += w0[1];
        if (*(s32 *)(base + 0xC) == arg->w0) {
            w0[0] += arg->f4;
            w0[1] += arg->f8;
            w0[2] += arg->fC;
        }
    }
    w1 = SLOT_WORK(s16, base, ctx, 1);
    {
        u8 *m = (u8 *)ppvMng;
        sp.v10[0] = (float)(w1[0] * *(u16 *)(m + 0x70)) * (1.0f / 524288.0f);
        sp.v10[1] = (float)(w1[1] * *(u16 *)(m + 0x72)) * (1.0f / 524288.0f);
        sp.v10[2] = (float)(w1[2] * *(u16 *)(m + 0x74)) * (1.0f / 524288.0f);
        sp.v10[3] = (float)(w1[3] * *(u16 *)(m + 0x76)) * (1.0f / 524288.0f);
    }
    if (arg->b19 & 2) {
        float *w3 = SLOT_WORK(float, base, ctx, 3);
        sp.v00[2] = 512.0f;
        sp.v00[0] = w3[0];
        sp.v00[1] = w3[1];
        sp.v00[3] = 1.0f;
        sp.p28 = D_006A3A70;
    } else {
        *(u_long128 *)sp.v00 = *(u_long128 *)(w2 + 0x30);
        sp.p28 = D_006A3A70;
    }
    sp.p20 = D_006A3A70;
    sp.p24 = (u8 *)D_006A3BCC + 0x10;
    sp.f58 = arg->f10 * *(float *)(mng + 0x60);
    sp.f5C = arg->f14 * *(float *)(mng + 0x64);
    dbuf = (u8 *)Sg_GetDBuffDC(&dbIdx);
    sp.v30[0] = sp.v30[2] = sp.v30[3] = 0.0f;
    sp.v30[1] = -w0[0];
    ent = dbuf + (((dbIdx + arg->b18) & 1) * 0x170 + 0x60);
    fbp = *(u64 *)ent;
    {
        u64 t0 = ((fbp & 0xFF) << 5) | (10ULL << 30);
        u64 t1 = (((fbp >> 24) & 0x3F) << 20) | (((fbp >> 16) & 0x3F) << 14);
        sp.q40 = (t0 | t1) | (10ULL << 26);
    }
    sp.q48 = *(u64 *)(ent + 0x30);
    sp.q50 = *(u64 *)(ent + 0x20);
    func_002DCE08(sp.v30, w2, sp.v30);
    *(s32 *)&sp.v30[3] = arg->b19;
    func_002830A0(&sp);
    if (func_002832F0(&sp) != 0) {
        if (arg->b19 & 2) {
            func_002B2A28(D_006A3BCC, (u32)(sp.p24 - (u8 *)D_006A3BCC) >> 4, 4, 0);
        } else {
            func_002B2AD8(D_006A3BCC, (u32)(sp.p24 - (u8 *)D_006A3BCC) >> 4, sp.w2C / 0x3000, 0);
        }
        D_006A3BCC = sp.p24;
    }
}

void func_0028B460(char *base, ScriptCtx *ctx) {
    Wkq0w8 *w = SLOT_WORK(Wkq0w8, base, ctx, 0);

    w->q0 = 0;
    w->w8 = 0;
}
