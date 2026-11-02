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

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", opu_clut_load);

INCLUDE_ASM("build/ee_asm/game/op/op_2A2220", opu_texture_load);

u16 *func_002A3600(W10Ctx *c, u16 *pc) {
    W10Actor *a;

    a = c->actor;
    switch (c->unk21A & 0xF000) {
    case 0:
        a->unkA8 = 0;
        a->unkBB = 7;
        pc++;
        opus_draw_on(&c->list300, c->unk214);
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
                dst = func_002A3EC8(dst, func_00117C18((int)chr, i), len); /* DEBT(TYPE): funcs.h takes s32 */
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
