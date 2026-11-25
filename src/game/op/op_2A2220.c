/* tu_320 0x2a2220-0x2a43d8: medium; ~opu_rgba_en (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: misc. engine helpers (see w10.h). */
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A2220);

void Ch_SetShadeCol(Chr *, int, float, float, float);
void func_00110540(Chr *, int, float);

void func_002A2558(Chr *a0, int a1, s32 a2)
{
    float vec[0x100];
    register float *vp __asm__("$16") = vec;
    int idx;
    u8 *st;
    int h0e;
    register u32 t __asm__("$2");

    __asm__("" : "+r"(vp));
    idx = opus_get_chr_status_index(a0, 0, 0);
    st = (u8 *)owu_chr_status + (idx << 5);
    h0e = *(u16 *)(st + 0xE);
    MMI_OP2Z("pextlb", t, a1);
    MMI_OP2Z("pextlh", t, t);
    VU0_QMTC2_NI(31, t);
    VU0_OP("vitof0.xyzw $vf31, $vf31");
    VU0_SQC2(31, 0, vp);
    {
        register u32 cmax __asm__("$2") = 0x437F0000U;
        register u32 cscale __asm__("$3");
        __asm__("" : "+r"(cmax));
        cscale = 0x3C000000U;
        VU0_CTC2_NI(21, cmax);
        VU0_QMTC2_NI(29, cscale);
    }
    VU0_LQC2(31, 0, vp);
    VU0_OP("vmulx.xyzw $vf31, $vf31, $vf29x");
    VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
    VU0_OP("vminii.xyzw $vf31, $vf31, I");
    VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
    VU0_SQC2(31, 0, vp);
    Ch_SetShadeCol(a0, 0, vec[0], vec[1], vec[2]);
    func_00110540(a0, 0, vec[3]);
    if (a2 != 0 && h0e < 0x20) {
        a0 = (Chr *)MsGetWeaponHandle(h0e, 0);
        if (a0 != 0) {
            Ch_SetShadeCol(a0, 0, vec[0], vec[1], vec[2]);
            func_00110540(a0, 0, vec[3]);
        }
        a0 = (Chr *)MsGetWeaponHandle(h0e, 1);
        if (a0 != 0) {
            Ch_SetShadeCol(a0, 0, vec[0], vec[1], vec[2]);
            func_00110540(a0, 0, vec[3]);
        }
    }
}

void func_002A26B0(Chr *a0, int a1, s32 a2)
{
    float vec[0x100];
    register float *vp __asm__("$16") = vec;
    int idx;
    u8 *st;
    int h0e;
    register u32 t __asm__("$2");
    Chr *h;

    idx = opus_get_chr_status_index(a0, 0, 0);
    st = (u8 *)owu_chr_status + (idx << 5);
    h0e = *(u16 *)(st + 0xE);
    MMI_OP2Z("pextlb", t, a1);
    MMI_OP2Z("pextlh", t, t);
    VU0_QMTC2_NI(31, t);
    VU0_OP("vitof0.xyzw $vf31, $vf31");
    VU0_SQC2(31, 0, vp);
    {
        register u32 cmax __asm__("$2") = 0x437F0000U;
        register u32 cscale __asm__("$3") = 0x3C000000U;
        VU0_CTC2_NI(21, cmax);
        VU0_QMTC2_NI(29, cscale);
    }
    VU0_LQC2(31, 0, vp);
    VU0_OP("vmulx.xyzw $vf31, $vf31, $vf29x");
    VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
    VU0_OP("vminii.xyzw $vf31, $vf31, I");
    VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
    VU0_SQC2(31, 0, vp);
    if (a2 != 0 && h0e < 0x20) {
        h = (Chr *)MsGetWeaponHandle(h0e, 0);
        if (h != 0) {
            Ch_SetShadeCol(h, 0, vec[0], vec[1], vec[2]);
            func_00110540(h, 0, vec[3]);
        }
        h = (Chr *)MsGetWeaponHandle(h0e, 1);
        if (h != 0) {
            Ch_SetShadeCol(h, 0, vec[0], vec[1], vec[2]);
            func_00110540(h, 0, vec[3]);
        }
    }
}

void opus_chara_status_rgb_set(Chr *a0, s32 a1)
{
    float vec[0x100];
    register float *vp __asm__("$16") = vec;
    int idx;
    u8 *st;
    u16 h0e;
    register u32 c1 __asm__("$2");
    register u32 c2 __asm__("$3");
    register u32 cscale __asm__("$2");

    idx = opus_get_chr_status_index(a0, 0, 0);
    st = (u8 *)owu_chr_status + (idx << 5);
    h0e = *(u16 *)(st + 0xE);
    c1 = *(u32 *)(st + 0x10);
    MMI_OP2Z("pextlb", c1, c1);
    MMI_OP2Z("pextlh", c1, c1);
    VU0_QMTC2_NI(31, c1);
    VU0_OP("vitof0.xyzw $vf31, $vf31");
    c2 = *(u32 *)(st + 0x18);
    MMI_OP2Z("pextlb", c2, c2);
    MMI_OP2Z("pextlh", c2, c2);
    VU0_QMTC2_NI(30, c2);
    VU0_OP("vitof0.xyzw $vf30, $vf30");
    cscale = 0x38800000U;
    VU0_QMTC2_NI(29, cscale);
    VU0_OP("vmul.xyz $vf31, $vf30, $vf31");
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf29x");
    VU0_SQC2(31, 0, vp);
    func_00110530(a0, vec[0], vec[1], vec[2]);
    if (a1 != 0) {
        a0 = (Chr *)MsGetWeaponHandle(h0e, 0);
        if (a0 != 0) {
            func_00110530(a0, vec[0], vec[1], vec[2]);
        }
        a0 = (Chr *)MsGetWeaponHandle(h0e, 1);
        if (a0 != 0) {
            func_00110530(a0, vec[0], vec[1], vec[2]);
        }
    }
}

void *op_malloc(void *, int);
void op_free(void *, void *);
void Sg_LightGetDir(int, void *);
void Sg_LightGetColor(int, void *);
s32 Sg_LightSetDir(int, void *);
s32 Sg_LightSetColor(int, void *);

s16 *opu_ffxlight(AnimCtx *o, s16 *p)
{
    void *obj300 = (u8 *)o + 0x300;
    register u8 *t __asm__("$20") = o->p220;
    register u8 *buf __asm__("$16");

    switch (o->h21A & 0xF000) {
    case 0x0000: {
        u8 *m = op_malloc(*(void **)((u8 *)o + 0x3A8), 0x80);
        *(u8 **)(t + 0xBC) = m;
        buf = m;
        Sg_LightGetDir(0, buf + 0x00);
        Sg_LightGetDir(1, buf + 0x20);
        Sg_LightGetDir(2, buf + 0x40);
        Sg_LightGetColor(0, buf + 0x10);
        Sg_LightGetColor(1, buf + 0x30);
        Sg_LightGetColor(2, buf + 0x50);
        Sg_LightGetColor(3, buf + 0x70);
        p += 1;
        break;
    }
    case 0x1000:
        buf = *(u8 **)(t + 0xBC);
        Sg_LightSetDir(0, buf + 0x00);
        Sg_LightSetDir(1, buf + 0x20);
        Sg_LightSetDir(2, buf + 0x40);
        Sg_LightSetColor(0, buf + 0x10);
        Sg_LightSetColor(1, buf + 0x30);
        Sg_LightSetColor(2, buf + 0x50);
        Sg_LightSetColor(3, buf + 0x70);
        op_free(*(void **)((u8 *)o + 0x3A8), *(void **)(t + 0xBC));
        *(void **)(t + 0xBC) = 0;
        p += 1;
        break;
    case 0x2000:
        buf = *(u8 **)(t + 0xBC);
        if (buf != 0) {
            u8 *volatile lp[6];
            u8 *dst = (u8 *)o;
            s16 *sp = p;
            u8 *src;
            int i;

            {
                register u8 *v __asm__("$2");
                v = (u8 *)o + 0x10; lp[5] = v;
                v = (u8 *)o + 0x20; lp[0] = v;
                v = (u8 *)o + 0x30; lp[2] = v;
                v = (u8 *)o + 0x40; lp[3] = v;
                v = (u8 *)o + 0x50; lp[4] = v;
                v = (u8 *)o + 0x70; lp[1] = v;
            }
            for (i = 0; i < 4; i++) {
                if (sp[1] != 0) {
                    register u32 sc __asm__("$3");
                    src = (u8 *)opus_no_get(obj300, (ScriptSub *)t, sp[1]);
                    VU0_LQC2(16, 0x90, t);
                    VU0_LQC2(17, 0x90, src);
                    VU0_OP("vsub.xyzw $vf31, $vf16, $vf17");
                    VU0_SQC2(31, 0x0, dst);
                    sc = 0x38000000U;
                    VU0_QMTC2_NI(12, sc);
                    VU0_LQC2(31, 0x30, src);
                    VU0_OP("vmulw.xyz $vf31, $vf31, $vf31w");
                    VU0_OP("vmulx.xyz $vf31, $vf31, $vf12x");
                    VU0_SQC2(31, 0x10, dst);
                } else {
                    register u_long128 qv __asm__("$2");
                    qv = *(u_long128 *)(buf + 0x00);
                    *(u_long128 *)((u8 *)sp + 0x00) = qv;
                    qv = *(u_long128 *)(buf + 0x10);
                    *(u_long128 *)((u8 *)sp + 0x10) = qv;
                }
                func_002DCEC8(dst, dst);
                {
                    float f = *(float *)(src + 0x4C);
                    u32 sc1 = 0x3B800000U;
                    register u32 fi __asm__("$3");
                    u32 c1;
                    VU0_QMTC2_NI(12, sc1);
                    MIPS_MFC1(fi, f);
                    VU0_QMTC2_NI(13, fi);
                    VU0_LQC2(16, 0x0, dst);
                    VU0_LQC2(17, 0x0, buf);
                    VU0_OP("vsub.xyzw $vf31, $vf16, $vf17");
                    VU0_OP("vmulx.xyz $vf31, $vf31, $vf13x");
                    VU0_OP("vmulx.xyz $vf31, $vf31, $vf12x");
                    VU0_OP("vadd.xyz $vf31, $vf31, $vf17");
                    VU0_OP("vmove.w $vf31, $vf0");
                    VU0_SQC2(31, 0x0, dst);
                    c1 = 0x3F800000U;
                    VU0_CTC2_NI(21, c1);
                    VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
                    VU0_LQC2(16, 0x10, dst);
                    VU0_LQC2(17, 0x10, buf);
                    VU0_OP("vsub.xyzw $vf31, $vf16, $vf17");
                    VU0_OP("vmulx.xyz $vf31, $vf31, $vf13x");
                    VU0_OP("vmulx.xyz $vf31, $vf31, $vf12x");
                    VU0_OP("vadd.xyz $vf31, $vf31, $vf17");
                    VU0_OP("vminii.xyzw $vf31, $vf31, I");
                    VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
                    VU0_OP("vmove.w $vf31, $vf0");
                    VU0_SQC2(31, 0x10, dst);
                }
                sp += 1;
                dst += 0x20;
                buf += 0x20;
            }
            Sg_LightSetDir(0, (u8 *)o + 0x00);
            Sg_LightSetColor(0, lp[5]);
            Sg_LightSetDir(1, lp[0]);
            Sg_LightSetColor(1, lp[2]);
            Sg_LightSetDir(2, lp[3]);
            Sg_LightSetColor(2, lp[4]);
            Sg_LightSetColor(3, lp[1]);
        }
        p += 5;
        break;
    case 0x3000:
        func_002A2C68();
        p += 1;
        break;
    case 0x4000:
        opus_ffxfocus_free();
        p += 1;
        break;
    }
    return p;
}

void opus_ffxfocus_free(void) {
    if (D_00703FF0.flag8) {
        Sg_EnFocus(D_00703FF0.val9);
        D_00703FF0.flag8 = 0;
    }
}

void func_002A2C68(void) {
    s32 v = Sg_EnFocus(0);

    if (!D_00703FF0.flag8) {
        D_00703FF0.val9 = v;
        D_00703FF0.flag8 = 1;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", opu_tc_load);

void Ch_ClutCreate(Chr *chr);
void *func_001175D8(Chr *chr, int idx, int *n);
void op_free(void *heap, void *p);
#define HEAP(o) (*(void **)((u8 *)(o) + 0x3A8))

/* DEBT(CAST): script stream read as s16 words, raw byte offsets */
s16 *opu_clut_load(AnimCtx *o, s16 *p)
{
    u8 *t = o->p220;
    Chr *chr = owu_chr_hd[t[0x18]];
    int src = *(int *)((u32)o + (t[0x1E] << 2) + 0x360);
    int n;
    u8 *x;

    switch ((s16)o->h21A & 0xF000) {
    case 0:
        op_oef2_clut_load(op_oef2_a_get(src, 3, p[1]), 1);
        p += 2;
        break;
    case 0x1000:
        Ch_ClutCreate(chr);
        n = op_chara_hsv_size_get(chr);
        if (n != 0) {
            op_free(HEAP(o), *(void **)(t + 0xBC));
            *(void **)(t + 0xBC) = op_malloc(HEAP(o), n);
            func_002A3BD8(chr, *(T6_PackBuf **)(t + 0xBC));
        } else {
            *(int *)(t + 0xBC) = 0;
        }
        p += 1;
        break;
    case 0x2000:
        if (*(int *)(t + 0xBC) != 0) {
            op_chara_hsv(chr, *(T6_PackBuf **)(t + 0xBC), (int)*(float *)(t + 0x40), (int)*(float *)(t + 0x44),
                         (int)*(float *)(t + 0x48), (int)*(float *)(t + 0x3C));
        }
        p += 1;
        break;
    case 0x5000:
        if (*(int *)(t + 0xBC) != 0) {
            u8 *e = (u8 *)&owu_chr_status[opus_get_chr_status_index(chr, 0, 0)];
            int v = e[0x17];

            e[0x17] = v & 0xFE;
            op_chara_hsv(chr, *(T6_PackBuf **)(t + 0xBC), (int)*(float *)(t + 0x40), (int)*(float *)(t + 0x44),
                         (int)*(float *)(t + 0x48), (int)*(float *)(t + 0x3C));
            e[0x17] = v;
        }
        p += 1;
        break;
    case 0x3000:
        if (*(int *)(t + 0xBC) != 0) {
            op_free(HEAP(o), *(void **)(t + 0xBC));
            *(int *)(t + 0xBC) = 0;
        }
        Ch_ClutDispose(chr);
        p += 1;
        break;
    case 0x4000: {
        u8 *s = (u8 *)op_oef2_a_get(src, 9, p[2]);
        int i;

        x = func_001175D8(chr, p[1], &n);
        for (i = 0; i < n; i += 16) {
            *(u_long128 *)(x + i) = *(u_long128 *)(s + i);
        }
        p += 3;
        break;
    }
    case 0x6000: {
        int v = p[1];
        int *s;
        u8 *big;
        u8 *d;

        p += 2;
        s = op_oef2_a_get(src, 3, v);
        big = op_malloc(HEAP(o), 0x20000);
        d = big + ((v & 7) << 14);
        *(u_long128 *)(d + 0x2000) = *(u_long128 *)s;
        func_002A3EC8(d, (void *)s[1], (u32)((u16 *)s)[1] >> 2);
        x = d + 0x1000;
        op_hsv_to_rgba(x, d, (u32)((u16 *)s)[1] >> 2, (int)*(float *)(t + 0x40), (int)*(float *)(t + 0x44),
                       (int)*(float *)(t + 0x48), (int)*(float *)(t + 0x3C));
        d += 0x2000;
        *(u8 **)(d + 4) = x;
        op_oef2_clut_load((int *)d, 1);
        op_free(HEAP(o), big);
        break;
    }
    }
    return p;
}

void *Ch_TextureGetImagePtr(Chr *chr, int idx, int *w, int *h);

/* DEBT(CAST): script stream read as s16 words, raw byte offsets */
s16 *opu_texture_load(AnimCtx *o, s16 *p)
{
    u8 *t = o->p220;
    int src = *(int *)((u32)o + (t[0x1E] << 2) + 0x360);
    Chr *chr = owu_chr_hd[t[0x18]];
    int *s;
    u_long128 *d;
    int w[2];
    int n;
    int i;

    switch ((s16)o->h21A & 0xF000) {
    case 0:
        op_oef2_texture_load(op_oef2_a_get(src, 2, p[1]), 1);
        p += 2;
        break;
    case 0x1000:
        op_et_tex_load_triger(1);
        p += 1;
        break;
    case 0x2000:
        op_et_tex_load_triger(0);
        p += 1;
        break;
    case 0x4000:
        s = op_oef2_a_get(src, 9, p[2]);
        d = Ch_TextureGetImagePtr(chr, p[1], &w[0], &w[1]);
        n = w[0] * w[1];
        for (i = 0; i < n; i += 16) {
            *(u_long128 *)((u8 *)d + i) = *(u_long128 *)((u8 *)s + i);
        }
        p += 3;
        break;
    case 0x5000:
        func_0010B9B8(chr, 0);
        p += 1;
        break;
    }
    return p;
}

u16 *func_002A3600(W10Ctx *c, u16 *pc) {
    W10Actor *a;

    a = c->actor;
    switch (c->h21A & 0xF000) {
    case 0:
        a->hA8 = 0;
        a->bBB = 7;
        pc++;
        opus_draw_on(&c->list300, c->h214);
        break;
    case 0x1000:
        pc++;
        func_002AEFB8(a);
        break;
    }
    return pc;
}

extern int func_002CFA20(int, void *, int, int, int, int, int, int, int, int);
extern void func_002A38A0(AnimCtx *, u8 *, int);
extern void func_002B2E50(void *, int, int, int);
extern void func_002CF040(void *, int);
extern void func_002CF1D0(void *, int);

s16 *func_002A3678(AnimCtx *o, s16 *p)
{
    u8 *t = o->p220;

    switch ((s16)o->h21A & 0xF000) {
    case 0: {
        u32 v = ((u16 *)p)[2];
        void *tex;
        u16 *q;
        u16 lo;
        u16 hi;

        if (v & 0x8000) {
            v = (v & 0x3FFF) + 0x1A00;
        }
        tex = op_oef2_a_get(*(int *)((u32)o + (t[0x1E] << 2) + 0x360), 2, p[1]);
        q = (u16 *)((u8 *)p + ((u16 *)p)[3]);
        lo = q[0];
        hi = q[1];
        *(int *)((u8 *)o + 0x354) = func_002CFA20(*(int *)((u8 *)o + 0x354), tex, v, (hi << 16) | lo, p[4],
                                                  (int)*(float *)(t + 0x40), (int)*(float *)(t + 0x44),
                                                  *(int *)(t + 0xC8), t[0xC2], t[0xC3]);
        p += 5;
        break;
    }
    case 0x1000:
        func_002A38A0(o, t, p[1]);
        p += 2;
        break;
    case 0x2000:
        func_002A3B38();
        p += 1;
        break;
    case 0x3000:
        func_002B2730(0);
        func_002A2C68();
        p += 1;
        break;
    case 0x6000:
        func_002B2E50((void *)func_002B2730, 0, 0, 1);
        p += 1;
        break;
    case 0x7000:
        func_002B2730((int)*(float *)(t + p[1]) << 8);
        p += 2;
        break;
    case 0x4000:
        func_002CF040(&p[2], p[1] << 16);
        p += 9;
        break;
    case 0x5000:
        func_002CF1D0(&p[2], p[1] << 16);
        p += 9;
        break;
    }
    return p;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A38A0);

void func_002A3B38(void) {
    func_002B2748(0, 0);
}

s32 op_chara_hsv_size_get(Chr *a) {
    s32 total = 0;
    s32 n = func_00117BB8(a);
    s32 i;

    if (n == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        total += Ch_ClutGetSize(a, i) << 3;
    }
    total = (total + 0xF) & 0xFFFFFFF0;
    if (total != 0) {
        return total + 0x20;
    }
    return 0;
}

void func_002A3BD8(Chr *chr, T6_PackBuf *buf)
{
    int n;
    u8 *dst;
    int i;
    int len;

    if (op_get_chr_status_stone(chr) == 0) {
        dst = buf->data;
        buf->n = n = func_00117BB8(chr);
        for (i = 0; i < n; i++) {
            buf->len[i] = len = Ch_ClutGetSize(chr, i);
            if (len != 0) {
                dst = func_002A3EC8(dst, func_00117C18(chr, i), len);
            }
        }
    }
}

void op_chara_hsv(Chr *chr, T6_PackBuf *buf, int a, int b, int c, int d)
{
    u8 *src;
    int n;
    int i;
    int len;

    if (op_get_chr_status_stone(chr) == 0) {
        n = buf->n;
        src = buf->data;
        for (i = 0; i < n; i++) {
            len = buf->len[i];
            if (len != 0) {
                src = op_hsv_to_rgba(Ch_ClutGetPtr((int)chr, i), src, len, a, b, c, d); /* DEBT(TYPE): funcs.h takes s32 */
            }
        }
    }
}

void func_002A3D88(u32 *dst, u32 *src, int count, int a3, int t0, int t1, int t2)
{
    u32 *d;
    u32 *s;
    void *buf;
    int n;

    buf = (void *)func_002B3888(0x800); /* DEBT(CAST): int vs void* */
    d = dst;
    s = src;
    n = count / 256;
    while (n > 0) {
        func_002A3EC8(buf, s, 0x100);
        s += 0x100;
        op_hsv_to_rgba(d, buf, 0x100, a3, t0, t1, t2);
        d += 0x100;
        n--;
    }
    n = count / 256;
    if (count == n * 256) {
        func_002A3EC8(buf, s, 0);
        op_hsv_to_rgba(d, buf, 0, a3, t0, t1, t2);
    }
    func_002B39C0(0x800);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A3EC8);

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", op_hsv_to_rgba);

void func_002A4318(s32 a, s16 b) {
    func_002D07A0(a, b);
}

void opus_all_clut_dispose(void) {
    s32 i;

    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_status[i].chr != 0) {
            Ch_ClutDispose(owu_chr_status[i].chr);
        }
    }
}

u16 *func_002A4380(AnimCtx *o, u16 *p)
{
    AnimTgt *t = o->p220;

    switch ((s16)o->h21A & 0xF000) { /* DEBT(TYPE): read as signed here, h21A is declared u16 */
    case 0:
        t->hB8 = p[1];
        t->b19 &= 0x7F;
        break;
    case 0x1000:
        t->hB8 = p[1];
        t->b19 |= 0x80;
        break;
    }
    return p + 2;
}
