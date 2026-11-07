/* tu_128 0x17a9c0-0x17db20: low; unk_17A9C0 (config/tu_map.tsv) */
#define func_0017AB10 _hdr_func_0017AB10
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#undef func_0017AB10

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017A9C0);

void func_0017AAE8(Obj17A110 *o) {
    o->h30 = 0;
    o->h32 = 0;
    o->h36 = 0;
    o->w48 = 0;
    o->w44 = 0;
    o->w54 = 0;
    o->w58 = 0;
    o->w4C = 0;
    o->w50 = 0;
}

/* DEBT(CAST) */
void func_0017AB10(float *arg0, float *arg1) {
    float *var_4;
    float *var_5;
    float temp_f0;
    s32 var_2;

    var_4 = arg0;
    var_5 = arg1;
    var_2 = 3;
    do {
        temp_f0 = *var_5;
        var_2 -= 1;
        var_5 = (float *)((u8 *)var_5 + (4));
        *var_4 = temp_f0;
        var_4 = (float *)((u8 *)var_4 + (4));
    } while (var_2 >= 0);
}

/* DEBT(CAST) */
void func_0017AB40(void *arg0, void *arg1) {
    (*(u16 *)((u8 *)(arg0) + (0x80))) = (u16) (*(u16 *)((u8 *)(arg1) + (0)));
    (*(u16 *)((u8 *)(arg0) + (0x82))) = (u16) (*(u16 *)((u8 *)(arg1) + (2)));
    (*(u16 *)((u8 *)(arg0) + (0x84))) = (u16) (*(u16 *)((u8 *)(arg1) + (4)));
    func_0017AB10(arg0 + 0x50, arg1 + 0x50);
    func_0017AB10(arg0 + 0x60, arg1 + 0x60);
    func_0017AB10(arg0 + 0x70, arg1 + 0x70);
}

/* DEBT(CAST) */
void func_0017ABA8(void *arg0, void *arg1) {
    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (*(u16 *)((u8 *)(arg1) + (0x80)));
    (*(u16 *)((u8 *)(arg0) + (2))) = (u16) (*(u16 *)((u8 *)(arg1) + (0x82)));
    (*(u16 *)((u8 *)(arg0) + (4))) = (u16) (*(u16 *)((u8 *)(arg1) + (0x84)));
    func_0017AB10(arg0 + 0x50, arg1 + 0x50);
    func_0017AB10(arg0 + 0x60, arg1 + 0x60);
    func_0017AB10(arg0 + 0x70, arg1 + 0x70);
}

/* DEBT(CAST) */
void func_0017AC10(void *arg0, void *arg1) {
    (*(u16 *)((u8 *)(arg0) + (0x30))) = (u16) (*(u16 *)((u8 *)(arg1) + (0)));
    (*(u16 *)((u8 *)(arg0) + (0x32))) = (u16) (*(u16 *)((u8 *)(arg1) + (2)));
    (*(u16 *)((u8 *)(arg0) + (0x36))) = (u16) (*(s32 *)((u8 *)(arg1) + (4)));
    (*(float *)((u8 *)(arg0) + (0x38))) = (float) (*(float *)((u8 *)(arg1) + (0x40)));
    (*(float *)((u8 *)(arg0) + (0x3C))) = (float) (*(float *)((u8 *)(arg1) + (0x44)));
    (*(s32 *)((u8 *)(arg0) + (0x48))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x4C)));
    func_0017AB10(arg0, arg1 + 0x10);
    func_0017AB10(arg0 + 0x10, arg1 + 0x20);
    func_0017AB10(arg0 + 0x20, arg1 + 0x30);
}

/* DEBT(CAST) */
void func_0017AC88(void *arg0, void *arg1) {
    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (*(u16 *)((u8 *)(arg1) + (0x30)));
    (*(float *)((u8 *)(arg0) + (0x40))) = (float) (*(float *)((u8 *)(arg1) + (0x38)));
    (*(u16 *)((u8 *)(arg0) + (2))) = (u16) (*(u16 *)((u8 *)(arg1) + (0x32)));
    (*(float *)((u8 *)(arg0) + (0x44))) = (float) (*(float *)((u8 *)(arg1) + (0x3C)));
    (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (*(u16 *)((u8 *)(arg1) + (0x36)));
    (*(s32 *)((u8 *)(arg0) + (0x4C))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x48)));
    func_0017AB10(arg0 + 0x10, arg1);
    func_0017AB10(arg0 + 0x20, arg1 + 0x10);
    func_0017AB10(arg0 + 0x30, arg1 + 0x20);
}

typedef struct { u8 b[4]; } B4;
void func_0017AD00(u8 *a, u8 *b) {
    u8 *p = a + 0x68000;
    B4 *dst = (B4 *)(a + 0x683A8);
    B4 *src = (B4 *)(b + 0x20);
    s32 i = 2;
    *(B4 *)(p + 0x370) = *(B4 *)b;
    *(float *)(p + 0x374) = *(float *)(b + 4);
    *(float *)(p + 0x378) = *(float *)(b + 8);
    *(float *)(p + 0x37C) = *(float *)(b + 0xC);
    do {
        *dst = *src;
        i--;
        dst++;
        src++;
    } while (i >= 0);
}

/* DEBT(CAST) */
void func_0017AD78(void *arg0, void *arg1) {
    (*(s32 *)((u8 *)(arg0) + (0))) = (s32) (*(s32 *)((u8 *)(arg1) + (0)));
    (*(s64 *)((u8 *)(arg0) + (0x20))) = (s64) (*(s64 *)((u8 *)(arg1) + (0x20)));
    (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (*(s32 *)((u8 *)(arg1) + (4)));
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (*(s32 *)((u8 *)(arg1) + (8)));
    (*(s32 *)((u8 *)(arg0) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg1) + (0xC)));
    (*(s32 *)((u8 *)(arg0) + (0x10))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x10)));
    (*(s32 *)((u8 *)(arg0) + (0x14))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x14)));
}

/* DEBT(CAST) */
void func_0017ADB8(void *arg0, void *arg1) {
    (*(s32 *)((u8 *)(arg0) + (0))) = (s32) (*(s32 *)((u8 *)(arg1) + (0)));
    (*(s64 *)((u8 *)(arg0) + (0x20))) = (s64) (*(s64 *)((u8 *)(arg1) + (0x20)));
    (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (*(s32 *)((u8 *)(arg1) + (4)));
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (*(s32 *)((u8 *)(arg1) + (8)));
    (*(s32 *)((u8 *)(arg0) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg1) + (0xC)));
    (*(s32 *)((u8 *)(arg0) + (0x10))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x10)));
    (*(s32 *)((u8 *)(arg0) + (0x14))) = (s32) (*(s32 *)((u8 *)(arg1) + (0x14)));
}

void func_0017ADF8(V2Save17AE *save, V2State17AE *state) {
    s32 remaining;
    u16 *src;
    u16 *dst;
    u16 value;

    save->h80 = (u16) state->h00;
    save->h82 = (u16) state->h02;
    save->h84 = (u16) state->w04;
    save->h86 = (u16) state->h30;
    save->w88 = (s32) state->w08;
    CALL_func_0017AB10_INT(save->v50, state->v10);
    CALL_func_0017AB10_INT(save->v60, state->v20);
    dst = save->h90;
    src = state->h38;
    remaining = 3;
    save->w8C = (s32) state->w34;
    do {
        value = *src;
        remaining -= 1;
        src += 1;
        *dst = value;
        dst += 1;
    } while (remaining >= 0);
}

/* DEBT(CAST): integer-width views follow the existing shared interfaces. */
void func_0017AE98(V2State17AE *state, V2Save17AE *save)
{
    s32 remaining;
    u16 *src;
    u16 *dst;
    u16 value;

    state->h00 = (u16) save->h80;
    state->h02 = (u16) save->h82;
    state->w04 = (s32) save->h84;
    state->h30 = (u16) save->h86;
    state->w08 = (s32) save->w88;
    CALL_func_0017AB10_INT(state->v10, save->v50);
    CALL_func_0017AB10_INT(state->v20, save->v60);
    dst = state->h38;
    src = save->h90;
    remaining = 3;
    state->w34 = (s32) save->w8C;
    do
    {
        value = *src;
        remaining -= 1;
        src += 1;
        *dst = value;
        dst += 1;
    } while (remaining >= 0);
}

void func_0017AF38(Obj17A110 *o, V2Save17A *s)
{
    o->h30 = s->h00;
    o->w48 = s->w0C;
    o->h32 = s->h02;
    o->f38 = s->f08;
    o->h36 = s->h04;
    o->h34 = s->h06;
    func_0017AB10(o->v00, s->v10);
    func_0017AB10(o->v10, s->v20);
    func_0017AB10(o->v20, s->v30);
}

void func_0017AFB0(V2Save17A *s, Obj17A110 *o)
{
    s->h00 = o->h30;
    s->w0C = o->w48;
    s->h02 = o->h32;
    s->f08 = o->f38;
    s->h04 = o->h36;
    s->h06 = o->h34;
    func_0017AB10(s->v10, o->v00);
    func_0017AB10(s->v20, o->v10);
    func_0017AB10(s->v30, o->v20);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017B028);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017B0D0);

void func_0017B178(R2Cpy38 *d, R2Cpy20 *s) {
    d->w0 = s->w0;
    d->q38 = s->q20;
    d->w4 = s->w4;
    d->w8 = s->w8;
    d->wC = s->wC;
    d->w10 = s->w10;
    d->w14 = s->w14;
}

void func_0017B1B8(R2Cpy20 *d, R2Cpy38 *s) {
    d->w0 = s->w0;
    d->q20 = s->q38;
    d->w4 = s->w4;
    d->w8 = s->w8;
    d->wC = s->wC;
    d->w10 = s->w10;
    d->w14 = s->w14;
}

void func_0017B1F8(R2Cpy10 *d, R2Cpy10 *s) {
    d->h0 = s->h0;
    d->w4 = s->w4;
    d->h2 = s->h2;
    d->w8 = s->w8;
    func_0017AB10(d->sub[0], s->sub[0]);
    func_0017AB10(d->sub[1], s->sub[1]);
    func_0017AB10(d->sub[2], s->sub[2]);
    func_0017AB10(d->sub[3], s->sub[3]);
}

void func_0017B270(R2Big68 *a, R2Mat40 *b) {
    int i;
    int j;
    a->w68260 = b->w4;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            a->m68270[i][j] = b->m40[i][j];
        }
    }
}

void func_0017B2E8(R2Big68 *a, R2Mat40 *b) {
    int i;
    int j;
    b->w4 = a->w68260;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            b->m40[i][j] = a->m68270[i][j];
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017B360);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017B390);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017B480);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C420);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017BC40);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017BD90);

extern u8 D_0030EAE8[];

int func_0017BE90(u8 *src, u8 *dst)
{
    unsigned int i, j, k;
    int idx;
    int n = 0;
    u8 *d = dst;
    u8 *s = src;

    for (i = 0; i < 4; i++) {
        idx = (i & 1) << 6;
        for (j = 0; j < 16; j++) {
            for (k = 0; k < 4; k++) {
                d[n] = s[D_0030EAE8[idx]];
                idx++;
                n++;
            }
        }
        s += 0x40;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017BF20);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C1C8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C470);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C778);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C470);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CA18);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C530);

void _m2c_func_0017CCF8_func_002DAB10(void *ctx, int a, int b, int c, int d, int e, int f, int g) __asm__("func_002DAB10");
void func_0017CCF8(s32 arg0) {
    u8 sp[0x70];
    _m2c_func_0017CCF8_func_002DAB10(sp, 0x3C00, 1, 0, 0, 0, 0x40, 0x400);
    func_0017CA18(sp, arg0 + 0x276B0);
}

void func_0017CD50(void *p) {
    func_002EF0D0(p, 0, 0x40);
}

void func_0017CD60(void *arg0) {
    func_002EF0D0(arg0, 0, 0x40);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CD70);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C5F0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017D3C8);
