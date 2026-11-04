/* tu_374 0x2fffd0-0x300500: medium; libkernl/iopreset (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/sdk/libkernl/iopreset", func_002FFFD0);

int func_00300110(void)
{
    if (func_002F87F0(4) & 0x10000) {
        return 1;
    }
    return 0;
}

int func_00300138(void)
{
    if (func_002F87F0(4) & 0x40000) {
        func_002F8850();
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/iopreset", func_00300170);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/iopreset", func_00300280);

int func_003002C8_(void) __asm__("func_003002C8"); /* the header declares it void; callers that need the result cast */
int func_003002C8_(void)
{
    int st;
    COP0_MFC0_STATUS(st);
    st &= 0x10000;
    EI();
    return st != 0;
}

void func_003002E0(void)
{
    SemaParam a;
    SemaParam b;

    a.maxCount = 1;
    a.initCount = 1;
    b.maxCount = 1;
    b.initCount = 1;
    D_00568E94 = func_002F83E0(&a);
    D_00568E98 = func_002F83E0(&b);
}

void func_00300328(void)
{
    func_003002E0();
    func_002F9090();
    func_002F9240();
}

long long func_00300350(double a)
{
    if (func_002EC198(a, 0) < 0) {
        return -func_003003B0(func_002EBC08(0, a));
    }
    return func_003003B0(a);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/iopreset", func_003003B0);
