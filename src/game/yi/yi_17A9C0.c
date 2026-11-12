/* tu_128 0x17a9c0-0x17db20: low; unk_17A9C0 (config/tu_map.tsv) */
#define func_0017AB10 _hdr_func_0017AB10
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#undef func_0017AB10

typedef struct YiMat17A9C0 {
    u64 d[8];
} YiMat17A9C0;

typedef struct YiObj17A9C0 {
    int w00;
    int w04;
    int w08;
    int w0C;
    YiMat17A9C0 m10;
    float v50[4];
    float v60[4];
    float v70[4];
    u16 h80;
    u16 h82;
    u16 h84;
    u16 h86;
    int w88;
    int w8C;
    u16 h90[4];
    int w98;
    u8 pad9C[0x10];
    int wAC;
} YiObj17A9C0;

void func_002DD128(void *m);

void func_0017A9C0(YiObj17A9C0 *o)
{
    YiMat17A9C0 m;
    float v[4];
    int i;

    func_002EF0D0(v, 0, 0x10);
    v[3] = 1.0f;
    o->h84 = 0;
    o->h82 = 0;
    o->h80 = 0;
    for (i = 0; i < 4; i++) {
        o->v50[i] = o->v60[i] = o->v70[i] = v[i];
    }
    o->wAC = 0;
    o->w98 = 0;
    o->h86 = 0;
    o->w8C = 0;
    for (i = 0; i < 4; i++) {
        o->h90[i] = 0;
    }
    o->w00 = 0;
    o->w04 = 0;
    o->w08 = 0;
    o->w0C = 0x6C040014;
    func_002DD128(&m);
    o->m10 = m;
}

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

void func_0017B028(u8 *a, u8 *b) {
    u8 *b30 = b + 0x30;
    B4 *dst;
    B4 *src;
    s32 i;
    *(B4 *)(a + 0x68370) = *(B4 *)(b + 0xC);
    *(float *)(a + 0x68374) = *(float *)(b + 0x10);
    *(float *)(a + 0x68378) = *(float *)(b + 0x14);
    *(float *)(a + 0x6837C) = *(float *)(b + 0x18);
    *(float *)(a + 0xBCB44) = *(float *)(b + 0x1C);
    *(float *)(a + 0xBCB48) = *(float *)(b + 0x20);
    dst = (B4 *)(a + 0x683A8);
    src = (B4 *)b;
    i = 2;
    do {
        *dst = *src;
        i--;
        dst++;
        src++;
    } while (i >= 0);
    func_0017AB10(a + 0x68250, b30);
}

void func_0017B0D0(u8 *a, u8 *b) {
    u8 *a30 = a + 0x30;
    B4 *dst;
    B4 *src;
    s32 i;
    *(B4 *)(a + 0xC) = *(B4 *)(b + 0x68370);
    *(float *)(a + 0x10) = *(float *)(b + 0x68374);
    *(float *)(a + 0x14) = *(float *)(b + 0x68378);
    *(float *)(a + 0x18) = *(float *)(b + 0x6837C);
    *(float *)(a + 0x1C) = *(float *)(b + 0xBCB44);
    *(float *)(a + 0x20) = *(float *)(b + 0xBCB48);
    dst = (B4 *)a;
    src = (B4 *)(b + 0x683A8);
    i = 2;
    do {
        *dst = *src;
        i--;
        dst++;
        src++;
    } while (i >= 0);
    func_0017AB10(a30, b + 0x68250);
}

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

void _m2c_func_0017B360_func_0017B480(void *, void *) __asm__("func_0017B480");
void func_0017B360(void *a, R2Mat40 *b) {
    if (b->w4 != 0x100) {
        __asm__ volatile("");
        if (b->w4 == 0x110) {
            _m2c_func_0017B360_func_0017B480(a, b);
        } else {
            BREAK();
        }
    }
}

extern s32 _m2c_func_0017B390_D_0065F750[] __asm__("D_0065F750");
void _m2c_func_0017B390_func_002DA610(int a, int b) __asm__("func_002DA610");
s32 _m2c_func_0017B390_func_002DB6D8(int a0) __asm__("func_002DB6D8");
extern void _m2c_func_0017B390_func_002DBB00(void *ch, int a, int b) __asm__("func_002DBB00");
void _m2c_func_0017B390_func_002DBF78(int a, int b, int c) __asm__("func_002DBF78");
void _m2c_func_0017B390_func_002F8660() __asm__("func_002F8660");
void func_0017B390(void) {
    s32 temp_2_2;
    s32 *temp_2;
    s32 *temp_3;

    _m2c_func_0017B390_D_0065F750[0] = 0x8004;
    _m2c_func_0017B390_D_0065F750[1] = 0x10000000;
    temp_3 = &_m2c_func_0017B390_D_0065F750[4];
    _m2c_func_0017B390_D_0065F750[2] = 0xE;
    _m2c_func_0017B390_D_0065F750[3] = 0;
    temp_3[0] = 0x01000000;
    temp_3[1] = 1;
    temp_3[2] = 0x4C;
    temp_3[3] = 0;
    temp_2 = &_m2c_func_0017B390_D_0065F750[8];
    temp_2[0] = 0x01000000;
    temp_2[1] = 1;
    temp_2[2] = 0x4D;
    temp_2[3] = 0;
    temp_2_2 = _m2c_func_0017B390_func_002DB6D8(2);
    _m2c_func_0017B390_func_002DBF78(temp_2_2, 0, 0x100);
    *(volatile u8 *)(temp_2_2) |= 1;
    *(volatile u8 *)(temp_2_2) |= 0x40;
    *(volatile u8 *)(temp_2_2) &= 0x7F;
    *(u8 *)(temp_2_2) &= 0xF3;
    _m2c_func_0017B390_func_002F8660(0);
    _m2c_func_0017B390_func_002DBB00((void *) temp_2_2, (s32) _m2c_func_0017B390_D_0065F750, 5);
    _m2c_func_0017B390_func_002DA610(0, 0);
}

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
