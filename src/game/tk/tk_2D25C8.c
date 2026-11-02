/* tu_336 0x2d25c8-0x2d3d68: low; ~Tk (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: timed callback queue (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/g4.h"

void func_002D25C8(s32 a, s32 b, s32 c, s32 d) {
    D_0078B0C0[a][b][c] = d;
}

int func_002D25F0(int a, int b, int c) {
    u8 target = D_00561F10[c];
    int i;

    for (i = 0; i < 16; i++) {
        if (D_0078B0C0[a][b][i] == target) {
            return i;
        }
    }
    return -1;
}

int TkGetControlerBindAnalogIndex(int a, int b, int c) {
    int v;
    int i;
    s8 *p;

    if (c < 4) {
        return c;
    }
    if (c >= 12) {
        return c;
    }
    c -= 4;
    v = func_002D25F0(a, b, c);
    if (v < 0) {
        func_002EF240(D_00575FF0, c);
        return 0;
    }
    for (i = 0, p = D_00561F10; ; i++) {
        if (v == *p++) {
            return i + 4;
        }
    }
}

u16 func_002D26C8(s32 a, s32 b, int maskArg) {
    u16 mask = maskArg;
    u8 *map = D_0078B0C0[a][b];
    u16 v = 0;
    s32 i;

    for (i = 0; i < 16; i++) {
        if ((mask >> i) & 1) {
            v |= 1 << map[i];
        }
    }
    return v;
}

W10PadEnt *func_002D2730(s32 a, s32 b, s32 c) {
    W10Pad *p = &D_0078ACC8[a][b];

    return &p->ring[(p->head + c) & 3];
}

void func_002D2768(s32 a, s32 b, s32 v) {
    W10Pad *p = &D_0078ACC8[a][b];

    p->active = v;
}

u8 func_002D2790(s32 a, s32 b) {
    W10Pad *p = &D_0078ACC8[a][b];

    return p->active;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D27B8);

void func_002D2808(s32 a, s32 b, s32 v) {
    W10Pad *p = &D_0078ACC8[a][b];

    p->val[0] = v;
}

void func_002D2830(s32 a, s32 b, s32 v) {
    W10Pad *p = &D_0078ACC8[a][b];

    p->val[1] = v;
}

u8 func_002D2858(s32 a, s32 b) {
    W10Pad *p = &D_0078ACC8[a][b];

    return p->stat[0];
}

u8 func_002D2880(s32 a, s32 b) {
    W10Pad *p = &D_0078ACC8[a][b];

    return p->stat[2];
}

u8 func_002D28A8(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->kind;
}

u8 func_002D28C8(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->id1;
}

u16 TkGetControlerHist(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->w4;
}

void func_002D2908(int a, int b, int c)
{
    W10PadEnt *sample = func_002D2730(a, b, c);

    /* DEBT(ORDER): source order reproduces the original store scheduling. */
    sample->w4 = 0;
    sample->w6 = 0;
    sample->wA = 0;
    sample->w1C = 0;
}

u16 TkGetControlerReptHist(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->wA;
}

u16 TkGetControlerRept2Hist(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->w1C;
}

u16 TkGetControlerTrigHist(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->w6;
}

u16 TkGetControlerTrigRHist(s32 a, s32 b, s32 c) {
    return func_002D2730(a, b, c)->w8;
}

u8 TkGetControlerAnalogHist(s32 a, s32 b, s32 idx, s32 c) {
    return func_002D2730(a, b, c)->axes[idx];
}

u8 TkGetControlerAnalog(s32 a, s32 b, s32 idx) {
    W10Pad *p = &D_0078ACC8[a][b];

    return p->axes[idx];
}

void func_002D2A10(W10PadEnt *e) {
    s32 i;

    for (i = 0; i < 4; i++) {
        e->axes[i] = 0x80;
    }
    for (i = 4; i < 12; i++) {
        e->axes[i] = 0;
    }
    for (; i < 16; i++) {
        e->axes[i] = 0x80;
    }
}

void func_002D2AA0(W10Pad *p) {
    s32 i;

    for (i = 0; i < 4; i++) {
        p->axes[i] = 0x80;
    }
    for (i = 4; i < 12; i++) {
        p->axes[i] = 0;
    }
    for (; i < 16; i++) {
        p->axes[i] = 0x80;
    }
}

void func_002D2B30(W10PadEnt *e) {
    e->kind = 0xFF;
    e->w4 = 0;
    e->w6 = 0;
    e->w8 = 0;
    e->wA = 0;
    e->w1C = 0;
    func_002D2A10(e);
}

void func_002D2B58(W10Pad *p) {
    p->shift[0] = 8;
    p->shift[1] = 8;
}

void func_002D2B68(W10Pad *p) {
    s32 i;

    p->val[0] = 0;
    p->val[1] = 0;
    p->shift[0] = 8;
    p->shift[1] = 8;
    for (i = 0; i < 6; i++) {
        p->out[i] = 0xFF;
        p->res[i] = 0;
    }
}

void func_002D2BB8(W10Pad *p) {
    W10PadEnt *e = p->ring;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_002D2B30(e);
        e->w2 = 0;
        e->w1E = 0;
        e++;
    }
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D2C00);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D2C98);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D2F20);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D30E0);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3180);

void func_002D32B8(W10Pad *o) {
    s32 r0, r1;

    if (o->active) {
        r0 = o->val[0];
        r1 = o->val[1];
        r0 >>= o->shift[0];
        r1 >>= o->shift[1];
    } else {
        r0 = 0;
        r1 = 0;
    }
    o->res[0] = r0;
    o->res[1] = r1;
}

int func_002D32F0(int a, int b, int c)
{
    if (c == 0xFF) {
        return 0;
    }
    return func_002DE448(a, b, c, 3) == 0 ? 1 : 8;
}

void func_002D3330(W10Pad *a, u8 b, u8 c) {
    a->out[0] = b;
    a->out[1] = c;
    a->res[0] = 0;
    a->res[1] = 0;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3348);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3468);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D34E8);
INCLUDE_RODATA("build/ee_asm/game/tk/tk_2D25C8/rodata", jtbl_00576020);

void func_002D3868(void) {
    s32 mask;
    s32 i, j;

    for (i = 0; i < 2; i++) {
        mask = D_0078ACC0[i];
        for (j = 0; j < 1; j++) {
            if ((mask >> j) & 1) {
                func_002D34E8(i, j, &D_0078AE80[i][j]);
            }
        }
    }
}

void func_002D3920(void) {
    s32 mask;
    s32 i, j;

    for (i = 0; i < 2; i++) {
        mask = D_0078ACC0[i];
        for (j = 0; j < 1; j++) {
            if ((mask >> j) & 1) {
                func_002D2F20(i, j, &D_0078AE80[i][j]);
            }
        }
    }
}

void func_002D39D8(s32 port, s32 slot) {
    s32 r;

    if ((D_0078ACC0[port] >> slot) & 1) {
        return;
    }
    while ((r = func_002DDED8(port, slot, D_0078AEC0[port][slot])) != 1) {
        func_002D3FF0(0);
    }
    D_0078ACC0[port] |= r << slot;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3AA8);

void func_002D3B88(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_0078ACC0[i] = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3BC0);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D3C30);

void func_002D3D00(void) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            func_002D3C30(i, j);
        }
    }
}
