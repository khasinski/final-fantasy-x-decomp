/* tu_327 0x2b1e08-0x2b33f8: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_002B1E08(void)
{
    func_002B1E30();
    func_002B1F88();
    func_002B37C0();
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B1E30);

void func_002B1F88(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B1F90);

void func_002B21E0(s32 a) {
    func_002B1F90(a);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", op_gs1_transfer);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2298);

int func_002B22C0(int n)
{
    int i = 0;
    int v;

    for (v = 1; v < n; v <<= 1) {
        i++;
    }
    return i;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B22F8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B24F8);

void func_002B2730(s32 a) {
    func_002B24F8(0x2100, 0xD00, a, 0x31);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2748);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2788);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2810);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2970);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B29D8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2A28);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2A80);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2AD8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2B30);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2B88);

void op_wot_triger(s32 on) {
    if (on) {
        D_00703FF7 = 1;
    } else {
        D_00703FF7 = 0;
    }
}

void func_002B2C70(s32 bank) {
    W10Callback *e;
    void (*fn)(s32, s32);
    s8 *list = &D_006F2F60[bank];
    s8 id;
    s32 i = 0;

    do {
        id = list[i];
        if (id < 0) {
            break;
        }
        e = &D_006F2FE0[bank + id];
        fn = e->fn;
        fn(e->arg0, e->arg1);
        if (e->count != 0) {
            if (--e->count == 0) {
                func_002B2E70(id, bank);
                i--;
            }
        }
        i++;
    } while (i < 0x20);
}

void func_002B2D38(void) {
    func_002B2C70(0);
}

void func_002B2D40(void) {
    func_002B2C70(0x20);
}

void func_002B2D48(void) {
    func_002B2C70(0x40);
}

void func_002B2D50(void) {
    func_002B2C70(0x60);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2D58);

s32 func_002B2DF0(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0);
}

s32 func_002B2E10(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x20);
}

s32 func_002B2E30(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x40);
}

s32 func_002B2E50(void (*fn)(s32, s32), s32 arg0, s32 arg1, u16 count) {
    return func_002B2D58(fn, arg0, arg1, count, 0x60);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2E70);

void func_002B2F10(u32 id) {
    func_002B2E70(id, 0);
}

void func_002B2F18(u32 id) {
    func_002B2E70(id, 0x20);
}

void func_002B2F20(u32 id) {
    func_002B2E70(id, 0x40);
}

void func_002B2F28(u32 id) {
    func_002B2E70(id, 0x60);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2F30);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B2FF0);

void func_002B3120(int a, u8 b, u8 c)
{
    op_gs1_transfer();
    func_002B2FF0(a, b, c);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1E08", func_002B3168);
