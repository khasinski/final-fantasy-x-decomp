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

s32 func_002D27B8(s32 a, s32 b) {
    W10Pad *p = &D_0078ACC8[a][b];
    s32 v = 0;
    if (p->type == 5) {
        v = p->shift[0] != 8;
        if (p->shift[1] != 8) {
            v++;
        }
    }
    return v;
}

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

extern u16 _m2c_func_002D2C00_D_00561F20[] __asm__("D_00561F20");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002D2C00(W10Pad *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 temp_3_2 __asm__("$3");
    register s32 temp_5 __asm__("$5");
    register s32 var_10 __asm__("$10");
    s32 var_12;
    u16 *var_11;
    register u16 *var_8 __asm__("$8");
    register u32 temp_3 __asm__("$3");
    s32 var_9;
    s32 diff;
    register u8 *base __asm__("$3");
    register u16 *end __asm__("$13");

    var_11 = _m2c_func_002D2C00_D_00561F20;
    base = arg0->padA0;
    end = &var_11[4];
    __asm__("" : "+r"(end));
    var_8 = (u16 *)((arg4 * 8) + (s32)base);
    __asm__ volatile("" : "+r"(var_8), "+r"(end));
    arg2 &= 0xFFFF;
    arg3 &= 0xFFFF;
    __asm__("" : "+r"(arg2), "+r"(arg3));
    var_12 = 0;
    do {
        temp_3 = *var_11;
        var_10 = 0;
        var_9 = *var_8;
        temp_5 = arg2 & temp_3;
        temp_3_2 = arg3 & temp_3;
        diff = temp_3_2 & (temp_3_2 ^ temp_5);
        if (temp_5 != 0) {
            if (temp_5 == temp_3_2) {
                var_9 -= 1;
                if (var_9 <= 0) {
                    var_10 = temp_5;
                    var_9 = (*(s16 *)((u8 *)(arg0) + (0x96)));
                }
            } else {
                var_10 = temp_5;
                __asm__("" : "+r"(var_10));
                var_9 = (*(s16 *)((u8 *)(arg0) + (0x94)));
                if (diff) {
                    var_10 = 0;
                }
            }
        }
        {
            register s32 or_v0 __asm__("$2") = var_12 | var_10;
            var_12 = or_v0 & 0xFFFF;
        }
        *var_8 = var_9;
        var_11++;
        var_8++;
    } while ((s32) var_11 < (s32) end);
    return var_12;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D2C98);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D25C8", func_002D2F20);

int func_002DEB70(int, int);
int func_002DEBD0(int, int);

int func_002D30E0(int port, int slot, int state, u8 *info)
{
    W10Pad *p = &D_0078ACC8[port][slot];

    if (func_002DEB70(port, slot) == 1) {
        if ((info[1] & 0xF) != 9) {
            if (func_002DEBD0(port, slot) != 0) {
                state = 7;
            }
        }
    } else {
        p->stat[2] = 0;
    }
    return state;
}

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

void _m2c_func_002D3468_func_002D2C98(void *, s32, u16) __asm__("func_002D2C98");
void _m2c_func_002D3468_func_002D3348(s32, s32, void *, s32) __asm__("func_002D3348");
void _m2c_func_002D3468_func_002DE228() __asm__("func_002DE228");
/* DEBT(CAST) */
void func_002D3468(s32 arg0, s32 arg1, s32 arg2) {
    W10Pad *temp_16 = &D_0078ACC8[arg0][arg1];
    _m2c_func_002D3468_func_002DE228(arg0, arg1, arg2);
    _m2c_func_002D3468_func_002D3348(arg0, arg1, temp_16, arg2);
    _m2c_func_002D3468_func_002D2C98(temp_16, arg2, (*(u16 *)((u8 *)(temp_16) + (0x98))));
}

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

void func_002D3AA8(s32 a, s32 b) {
    s32 var_16;
    s32 var_17;

    if (a < 0) {
        var_17 = 0;
        do {
            var_16 = 0;
            do {
                func_002D3AA8(var_17, var_16);
                var_16 += 1;
            } while (var_16 <= 0);
            var_17 += 1;
        } while (var_17 < 2);
    }
    if (((s32) D_0078ACC0[a] >> b) & 1) {
        func_002DE0C0(a, b);
        D_0078ACC0[a] &= ~(1 << b);
    }
}

void func_002D3B88(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_0078ACC0[i] = 0;
    }
}

void func_002D3BC0(s32 a, s32 b) {
    u8 *base = D_0078ACC8[a][b].padA0;
    s32 i, j;
    __asm__("" : "+r"(base));
    for (i = 0; i < 2; i++) {
        s16 *row = (s16 *)((i * 8) + (s32)base);
        for (j = 0; j < 4; j++) {
            row[j] = 0;
        }
    }
}

/* DEBT(CAST) */
void func_002D3C30(s32 a, s32 b) {
    W10Pad *temp_16;
    s32 var_17;
    s32 var_6;

    var_17 = 0;
    temp_16 = &D_0078ACC8[a][b];
    temp_16->type = temp_16->pad9E = 1;
    temp_16->active = 0;
    (*(s16 *)((u8 *)(temp_16) + (0x94))) = 0xC;
    (*(s16 *)((u8 *)(temp_16) + (0x96))) = 5;
    func_002D2B58(temp_16);
    func_002D2B68(temp_16);
    func_002D2BB8(temp_16);
    func_002D3BC0(a, b);
    __asm__ volatile("" : "+r"(var_17));
    var_6 = var_17;
    temp_16->head = 0;
    temp_16->stat[3] = 0;
    do {
        func_002D25C8(a, b, var_6, var_17);
        var_17 += 1;
        var_6 = var_17;
    } while (var_17 < 0x10);
}

void func_002D3D00(void) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            func_002D3C30(i, j);
        }
    }
}
