/* tu_036 0x11f8d0-0x11fc58: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"

s32 Sg_CaptureGetGuiHide(void)
{
    s32 r = 0;

    if (D_00307FE0 != 0) {
        r = D_00580B08 != 0;
    }
    return r;
}

void Sg_CaptureEnable(void)
{
    D_00307FE0 = 1;
    D_00580B08 = 1 - (D_00580B05 & 1);
    D_00307FE4 = 3;
    D_00307FE8 = 0;
    D_00307FEC = 0;
    D_00580B10[0] = D_02004A28;
    D_00580B10[1] = D_02004A2C;
    D_00580B10[2] = D_02004A1C;
    D_00580B10[3] = D_02004A20;
    D_00580B10[4] = D_02004A24;
}

void func_0011F990(int a, int b)
{
    if (b != 0) {
        D_00307FE8 = a;
        D_00307FE0 = b;
        D_00580B08 = 1;
        D_00307FE4 = 3;
        D_00307FEC = 0;
        D_00307FF0 = 0;
        D_00580B10[0] = D_02004A28;
        D_00580B10[1] = D_02004A2C;
        D_00580B10[2] = D_02004A1C;
        D_00580B10[3] = D_02004A20;
        D_00580B10[4] = D_02004A24;
    }
}

void func_0011FA30(int v)
{
    D_00307FE8 = v;
    D_00307FE0 = 1;
    D_00580B08 = 1;
    D_00307FEC = 1;
    D_00307FF0 = 0;
    D_00580B10[0] = D_02004A28;
    D_00580B10[1] = D_02004A2C;
    D_00580B10[2] = D_02004A1C;
    D_00580B10[3] = D_02004A20;
    D_00580B10[4] = D_02004A24;
}

void func_0011FAA8(void)
{
    D_00307FE0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11F8D0", Sg_Capture);
