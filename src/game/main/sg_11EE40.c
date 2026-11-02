/* tu_035 0x11ee40-0x11f8d0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void func_0011EE40(s32 v)
{
    D_00307FA0 = v;
}

s32 Sg_PcReadGetLen(void)
{
    return D_00580B00;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11EE40", Sg_PcReadL);

INCLUDE_ASM("build/ee_asm/game/main/sg_11EE40", _Sg_PcRead);

s32 Sg_PcRead(s32 a)
{
    s32 r = _Sg_PcRead(a, 0);

    Sg_MemSetCurrentAddr(r);
    return r;
}

s32 Sg_PcReadD(s32 a)
{
    s32 r = _Sg_PcRead(a, 1);

    Sg_MemSetCurrentAddr(r);
    return r;
}

s32 Sg_PcReadH(s32 a)
{
    s32 r = _Sg_PcRead(a, 2);

    Sg_MemSetCurrentAddr(r);
    return r;
}

void Sg_PcWrite(int *data, int bytes, int index)
{
    char path[0x100];
    int fd;
    if (ffx_debugmode != 0) {
        func_002F0008(path, D_00569DF0, D_00569DF8, index);
        fd = func_002FC4E0(path, 0x602);
        if (fd < 0) {
            yiAssert(0, D_00569E00, D_00569E10, index);
            return;
        }
        func_002FCD90(fd, data, bytes);
        func_002FC768(fd);
    }
}

void func_0011F248(s8 v)
{
    D_00307FDE = v;
}

void func_0011F258(s8 v)
{
    D_00580B04 = v;
}

s8 Sg_CaptureGetSelect(void)
{
    return D_00580B04;
}

void func_0011F278(s8 v)
{
    D_00580B05 = v;
}

s8 func_0011F288(void)
{
    return D_00580B05;
}

void func_0011F298(s8 v)
{
    D_00307FDF = v;
}

s8 func_0011F2A8(void)
{
    return D_00307FDF;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11EE40", Sg_CaptureToFile);

INCLUDE_ASM("build/ee_asm/game/main/sg_11EE40", func_0011F658);
