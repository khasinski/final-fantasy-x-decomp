/* tu_128 0x17a9c0-0x17db20: low; unk_17A9C0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v2.h"
#include "ffx/r2.h"

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

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AB10);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AB40);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017ABA8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AC10);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AC88);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AD00);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017AD78);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017ADB8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017ADF8);

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

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017BE90);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017BF20);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C1C8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C470);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017C778);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C470);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CA18);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C530);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CCF8);

void func_0017CD50(void *p) {
    func_002EF0D0(p, 0, 0x40);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CD60);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017CD70);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_17A9C0/rodata", jtbl_0056C5F0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A9C0", func_0017D3C8);
