/* tu_355 0x2e2220-0x2e4250: medium; unk_2E2220 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

void func_002E2220(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D8_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

void func_002E2288(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D9_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

INCLUDE_ASM("build/ee_asm/sdk/libipu/libipu_2E2220", func_002E22F0);

INCLUDE_ASM("build/ee_asm/sdk/libipu/libipu_2E2220", func_002E23D8);

INCLUDE_ASM("build/ee_asm/sdk/libipu/libipu_2E2220", func_002E2528);

void func_002E2590(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D9_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

INCLUDE_ASM("build/ee_asm/sdk/libipu/libipu_2E2220", func_002E25F8);
