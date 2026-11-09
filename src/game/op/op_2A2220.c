/* tu_320 0x2a2220-0x2a43d8: medium; ~opu_rgba_en (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: misc. engine helpers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A2220);

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A2558);

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A26B0);

/* DEBT(NAME): module and names guessed: script-op handlers (see w10.h). */
INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", opus_chara_status_rgb_set);

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", opu_ffxlight);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A3678);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", func_002A3D88);

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
