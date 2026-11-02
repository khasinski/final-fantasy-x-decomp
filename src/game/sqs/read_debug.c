/* tu_278 0x254a38-0x255a08: low; read_debug (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */

void func_00254A38(void)
{
    int i;

    if (D_003271BC == 0) {
        D_003271BC = 1;
        for (i = 0; i < 16; i++) {
            D_006A3190[i] = 0;
            D_006A31D0[i] = 0;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", set_read_chgname);

void func_00254B68(int i)
{
    D_006A3190[i] = 0;
    D_006A31D0[i] = 0;
}

int func_00254B90(void)
{
    return ((int *)GetCD())[12]; /* DEBT(CAST): word 0x30 of the SysVt block */
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00254BB0);

int CDfileName_PC(int a)
{
    SysVt *vt = GetCD();

    return func_00254BB0(vt->f20 + a);
}

int func_00254EB8(int i, int a)
{
    return func_00254BB0(D_0078E4C4[i] + a);
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", CDfileSize_PC);

int func_00254FD0(int a)
{
    return func_00163158(D_0078E4B8 + a);
}

void func_00254FF8(int n)
{
    if (n < 0) {
        func_001577A8(D_00573860, D_00573850, 0x14D);
    }
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00255020);

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00255100);

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00255238);

void PcFileTblSet(int a)
{
    if (D_0078E498.f30 != 0) {
        func_0011D590(D_0078E498.f30, 10);
    }
    D_0078E498.f30 = func_00255100(a, 0);
}

void pc_fat_index_filename_set(void)
{
    u8 language[3]; /* two-letter code and the terminating NUL */
    CALL_MsSetCountryName_INT(language);
    /* DEBT(ORDER): independent configuration writes retain original scheduling. */
    if (D_005661F4 == 0)
    {
        D_00327080.language[0] = language[0];
        D_00327080.language[1] = language[1];
        D_003270B0.language[0] = language[0];
        D_003270B0.language[1] = language[1];
        D_003270E0.language[0] = language[0];
        D_003270E0.language[1] = language[1];
        D_0078E498.f28 = func_00255020(&D_00327080, 0);
        D_0078E498.f2C = func_00255020(&D_003270B0, 0);
        /* DEBT(CAST): loader API uses an integer address/handle view. */
        D_0078E498.f30 = func_00255100((s32) &D_003270E0, 0);
        return;
    }
    D_00327110.b1A = language[0];
    D_00327110.b1B = language[1];
    D_00327138.b1A = language[0];
    D_00327138.b1B = language[1];
    D_0078E498.f28 = func_00255020(&D_00327110, 0);
    D_0078E498.f2C = func_00255020(&D_00327138, 0);
    D_0078E498.f30 = 0;
}

void func_002558E0(void)
{
    u8 buf[2];

    MsSetCountryName(buf);
    D_00327160.b1A = buf[0];
    D_00327160.b1B = buf[1];
    func_00255020(&D_00327160, 0);
}

void func_00255920(void)
{
    u8 buf[2];

    MsSetCountryName(buf);
    D_00327190.b1A = buf[0];
    D_00327190.b1B = buf[1];
    func_00255020(&D_00327190, 0);
}

int func_00255960(void)
{
    return func_00164648();
}

int func_00255980(void)
{
    return -1;
}

int func_00255988(void)
{
    return -1;
}

void PcReadFunc_set(void)
{
    T6_VT->f14 = (int (*)())CDfileSize_PC;
    T6_VT->f58 = (int (*)())CDfileName_PC;
    T6_VT->f54 = (int (*)())func_00255020;
    T6_VT->f68 = (int (*)())func_00255238;
    T6_VT->f60 = (int (*)())PcFileTblSet;
    T6_VT->f78 = (int (*)())func_00255960;
    T6_VT->f88 = (int (*)())func_00255980;
    T6_VT->f8C = (int (*)())func_00255988;
    T6_VT->f04 = (int (*)())func_00254FD0;
}
