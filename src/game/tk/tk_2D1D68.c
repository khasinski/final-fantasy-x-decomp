/* tu_335 0x2d1d68-0x2d25c8: low; ~Tk (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: timed callback queue (see w10.h). */
#define func_002D24F8 _hdr_func_002D24F8
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/g4.h"
#undef func_002D24F8

void func_002D1D68(s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        D_0078ACBC++;
    }
}

s32 func_002D1DA0(void) {
    return D_0078ACBC;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D1DB0);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D1E70);

s32 func_002D1F18(s32 mode) {
    mode = W10_CLAMP_IDX(mode);
    return D_0078ACA0[mode];
}

void func_002D1F48(s32 mode, void (*v)(void)) {
    if (mode < 3) {
        mode = W10_CLAMP_IDX(mode);
        D_0078ACB0[mode] = v;
    }
}

void (*func_002D1F88(s32 mode))(void) {
    mode = W10_CLAMP_IDX(mode);
    return D_0078ACB0[mode];
}

void func_002D1FB8(s32 i) {
    func_002F8410(D_00788BC0[i]);
}

void TkSignalSemaBGThread(void) {
    func_002F8400(D_0078AC58[0]);
}

void (*TkRegistBGThreadFunc(void (*fn)(void)))(void) {
    void (*old)(void) = D_0078AC60[0];

    D_0078AC60[0] = fn;
    return old;
}

void func_002D1FF0(void) {
    func_002F8420(D_0078AC58[0]);
}

void func_002D2000(void) {
    func_002F8410(D_0078AC80);
}

void func_002D2010(void) {
    SemaParam st;

    func_002F8450(D_0078AC80, &st);
    if (st.numWaitThreads != 0) {
        func_002F8400(D_0078AC80);
    }
}

s32 func_002D2050(void) {
    return D_0078AC80;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D2060);

void func_002D2168(void) {
    func_002D20D0(func_002D3E78);
}

void func_002D2178(void) {
    func_002D20D0(0);
}

s32 func_002D2180(void) {
    ThreadParam st;

    return func_002F82E0(func_002F82D0(), &st);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D21A8);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D2210);

void func_002D2330(void) {
    D_0078AC88.maxCount = 0x10000;
    D_0078AC88.initCount = 0;
    D_0078AC88.option = 0;
    D_0078AC80 = func_002F83E0(&D_0078AC88);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D1D68", func_002D2370);

s32 _m2c_func_002D24F8_func_002F83F0() __asm__("func_002F83F0");
extern s32 _m2c_func_002D24F8_D_00788BC0[] __asm__("D_00788BC0");
extern s32 _m2c_func_002D24F8_D_0078AC50[] __asm__("D_0078AC50");
extern s32 _m2c_func_002D24F8_D_0078AC58[] __asm__("D_0078AC58");
extern s32 _m2c_func_002D24F8_D_0078AC80 __asm__("D_0078AC80");
void func_002D24F8(void) {
    s32 i;
    s32 j;
    s32 temp_2;

    func_002D3F80();
    for (i = 0; i < 3; i++) {
        temp_2 = func_002D1F18(i);
        func_002F8230(temp_2);
        func_002F81F0(temp_2);
        _m2c_func_002D24F8_func_002F83F0(_m2c_func_002D24F8_D_00788BC0[i]);
    }
    _m2c_func_002D24F8_func_002F83F0(_m2c_func_002D24F8_D_0078AC80);
    for (j = 0; j < 1; j++) {
        _m2c_func_002D24F8_func_002F83F0(_m2c_func_002D24F8_D_0078AC58[j]);
        func_002F8230(_m2c_func_002D24F8_D_0078AC50[j]);
        func_002F81F0(_m2c_func_002D24F8_D_0078AC50[j]);
    }
    func_002D3FB0();
    func_002D20D0(0);
}
