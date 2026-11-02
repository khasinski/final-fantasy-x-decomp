/* tu_355 0x2e2830-0x2e4250: medium; unk_2E2220; split at 0x2e2830: library split: 0x2E2220-0x2E2830 is libipu (IPU registers, IPU DMA channels), 0x2E2830 starts the fdlibm double math (calls fp-bit, 0x7FF00000 masks) (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E2830", func_002E2830);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E2830", func_002E2E00);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E2830", func_002E3138);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E2830", func_002E3528);
