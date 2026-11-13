/* tu_337 0x2d3d68-0x2d41a8: low; ~Tk (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad module (ports/slots) (see w10.h). */
#define func_002D3FF0 _hdr_func_002D3FF0
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r7.h"
#include "ffx/u5.h"
#undef func_002D3FF0

s32 func_002D3D68(void) {
    return 12;
}

s32 func_002D3D70(void) {
    return 12;
}

void TkClearSoundSyncVFlag(void) {
    D_0078B124 = 0;
}

void func_002D3D88(void) {
    D_0078B124 = 1;
}

s32 TkGetSoundSyncVFlag(void) {
    return D_0078B124;
}

void func_002D3DA8(void) {
    D_0078B128 = 0;
}

void func_002D3DB8(void) {
    D_0078B128 = 1;
}

s32 func_002D3DC8(void) {
    return D_0078B128;
}

void func_002D3DD8(void) {
    D_0078B12C = 0;
}

void func_002D3DE8(void) {
    D_0078B12C = 1;
}

s32 func_002D3DF8(void) {
    return D_0078B12C;
}

void func_002D3E08(void) {
    D_0078B110++;
    D_0078B100++;
}

s32 func_002D3E30(void) {
    return D_0078B100;
}

void func_002D3E40(void) {
    D_0078B134 = (s32)GS_CSR;
    func_002D2010();
    func_002D3868();
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D3D68", func_002D3E78);

int func_002D3F08(int value)
{
    SYNC();
    SYNC_P();
    /* Read the shared value before replacing it, between the synchronization barriers. */
    (void)D_0078B0F0;
    D_0078B0F0 = value;
    SYNC();
    SYNC_P();
    return D_0078B0F0;
}

void func_002D3F30(s32 a, void (*fn)(void)) {
    func_002D3F08(0);
    func_002D1F18(a);
    func_002D1F48(a, fn);
    func_002D3F08(1);
}

s32 func_002D3F80(void) {
    D_0078B0E0++;
    return func_002D3F08(0);
}

s32 func_002D3FB0(void) {
    if (D_0078B0E0 > 0) {
        D_0078B0E0 = D_0078B0E0 - 1;
    } else {
        D_0078B0E0 = 0;
    }
    return func_002D3F08(1);
}

s32 func_002D3FF0(s32 a)
{
    s32 s1 = 1;
    s32 s0;
    s32 zero = 0;

    if (a > zero) {
        s1 = a;
    }
    s0 = D_0078B100;

    while (s0 < s1) {
        func_002F8420(func_002D2050());
        s0 = D_0078B100;
    }
    s1 = s0;
    do {
        func_002F8420(func_002D2050());
        s0 = D_0078B100;
    } while (s1 == s0);
    s0--;
    D_0078B130 = D_0078B134;
    func_002D41E0();
    func_002D3F80();
    D_0078B100 = 1;
    func_002D3FB0();
    D_0078B120 = s0;
    func_002D3D88();
    func_002D3DB8();
    func_002D3DE8();
    func_002D5CE8();
    return s0;
}

s32 func_002D4118(void) {
    return D_0078B130;
}

s32 TkGetLastSyncVCounter(void) {
    return D_0078B120;
}

s64 func_002D4138(void) {
    return D_0078B110;
}

void func_002D4148(void) {
    D_0078B120 = 0;
    D_0078B100 = 0;
    D_0078B110 = 0;
    D_0078B0F0 = 0;
    D_0078B0E0 = 0;
    func_002D3F30(0, func_002D3E40);
    func_002D3D88();
    func_002D3DB8();
    func_002D3DE8();
}
