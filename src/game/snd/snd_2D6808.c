/* tu_340 0x2d6808-0x2d7090: low; ~Snd (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad/event glue (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

void func_002D6808(s32 v) {
    D_0078BA48 = v;
}

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D6808", func_002D6818);
INCLUDE_RODATA("build/ee_asm/game/snd/snd_2D6808/rodata", jtbl_00576060);

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D6808", func_002D6A28);
INCLUDE_RODATA("build/ee_asm/game/snd/snd_2D6808/rodata", jtbl_005760A0);

void SndRemoveFootSepWork(void) {
    func_002D6A28(1);
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;

    D_0078BA4C = 0;
    D_0078BA50 = 0;
}

void func_002D6B88(void) {
    func_002D6A28(0);
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;
    D_0078BA4C = 0;
    D_0078BA50 = 0;
}

void SndClearFootStatus(void) {
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0;
    D_0078BA38.cur = 0;
    D_0078BA40.cur = 0;
}

void func_002D6C08(void) {
    D_0078BA28.cur = 0;
    D_0078BA30.cur = 0xFFFFFFFF;
    D_0078BA38.cur = 0xFFFFFFFF;
    D_0078BA40.cur = 0xFFFFFFFF;
}

void func_002D6C38(void) {
    D_0078BA28.pend = D_0078BA28.cur;
    D_0078BA30.pend = D_0078BA30.cur;
    D_0078BA38.pend = D_0078BA38.cur;
    D_0078BA40.pend = D_0078BA40.cur;
}

void func_002D6C80(void) {
    D_0078BA28.cur = D_0078BA28.pend;
    D_0078BA30.cur = D_0078BA30.pend;
    D_0078BA38.cur = D_0078BA38.pend;
    D_0078BA40.cur = D_0078BA40.pend;
}

void func_002D6CC8(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA28.cur |= mask;
    } else {
        D_0078BA28.cur &= ~mask;
    }
}

void func_002D6D00(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA30.cur |= mask;
    } else {
        D_0078BA30.cur &= ~mask;
    }
}

s32 func_002D6D38(void) {
    return D_0078BA30.cur;
}

s32 func_002D6D48(void) {
    return D_0078BA28.cur;
}

s32 func_002D6D58(void) {
    return D_0078BA38.cur;
}

s32 func_002D6D68(void) {
    return D_0078BA40.cur;
}

void func_002D6D78(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA38.cur |= mask;
    } else {
        D_0078BA38.cur &= ~mask;
    }
}

void func_002D6DB0(s32 bit, s32 on) {
    u32 mask = 1 << bit;

    if (on) {
        D_0078BA40.cur |= mask;
    } else {
        D_0078BA40.cur &= ~mask;
    }
}

s32 *_m2c_SndSetFootSep_func_002D6818(s32 a, s32 b, s32 c) __asm__("func_002D6818");
void SndSetFootSep(s32 a, s32 b, s32 c, s32 d) {
    *_m2c_SndSetFootSep_func_002D6818(a, b, c) = d;
}

s32 func_002D6E10(u32 idx) {
    u32 *tbl = D_0078BA50;

    if (tbl == 0) {
        return 0;
    }
    if (idx >= tbl[0]) {
        return 0;
    }
    return tbl[idx + 1];
}

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D6808", func_002D6E48);
INCLUDE_RODATA("build/ee_asm/game/snd/snd_2D6808/rodata", jtbl_005760E0);
INCLUDE_RODATA("build/ee_asm/game/snd/snd_2D6808/rodata", jtbl_00576100);
INCLUDE_RODATA("build/ee_asm/game/snd/snd_2D6808/rodata", jtbl_00576140);
