/* tu_359 0x2e9828-0x2eb7a0: low; unk_2E9828 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/v7.h"
#include "ffx/g4.h"
#include "ffx/w11.h"

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002E9828);

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002E9938);

void func_002E9B10(void)
{
    while (*D_00567EB4) {
        D_00567EB4++;
        (*(D_00567EB4 - 1))();
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002E9B68);

void func_002E9C18(void)
{
    if (D_00791600 == 0) {
        D_00791600 = 1;
        func_002E9B68();
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002E9C38);

void func_002EA328(int status)
{
    func_002E9B10();
    func_002ED4F0();
    func_001000B8(status);
}

unsigned long func_002EA358(float input)
{
    unsigned long high;
    double value = input;

    if (value < 0) {
        return 0;
    }
    high = (unsigned long)(unsigned int)(value * (1.0 / 4294967296.0)) << 32;
    value -= (double)high;
    if (value < 0) {
        high -= (unsigned int)-value;
    } else {
        high += (unsigned int)value;
    }
    return high;
}

double func_002EA450(s64 u)
{
    double d = func_002EC1E8(u >> 32);
    s32 v;
    double f;

    d = func_002EBC70(d, 65536.0);
    d = func_002EBC70(d, 65536.0);
    v = u & 0xFFFFFFFFLL;
    f = func_002EC1E8(v);
    if (v < 0) {
        f = func_002EBBB0(f, 4294967296.0);
    }
    return func_002EBBB0(d, f);
}

float func_002EA4E8(long value)
{
    double high;

    /* Preserve discarded low bits when the integer exceeds double precision. */
    if ((unsigned long)value + 0x1fffffffffffffUL > 0x3ffffffffffffeUL) {
        if ((int)value & 0x7ff) {
            value |= 0x800;
        }
    }
    high = (double)(int)(value >> 32);
    high *= 65536.0;
    high *= 65536.0;
    return (float)(high + (double)(unsigned int)(value & 0xffffffffUL));
}

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002EA5C8);

/* Module: libgcc soft-float (fp-bit.c: double + single precision), newlib libm helpers */

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002EAC30);

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002EAC90);

INCLUDE_ASM("build/ee_asm/sdk/libgcc/libgcc_2E9828", func_002EB260);
