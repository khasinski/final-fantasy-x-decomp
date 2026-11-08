/* tu_348 0x2dba00-0x2dc110: medium; libdma (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002DBA00(s32 arg0) {
    register s32 p __asm__("$2");
    register s32 m1 __asm__("$3");

    p = 0x10000000;
    m1 = 0xFFFF0000;
    __asm__("" : "+r"(p), "+r"(m1));
    p |= 0xE060;
    m1 |= 0xFFFF;
    __asm__("" : "+r"(p), "+r"(m1));
    p = *(s32 *)p;
    if (arg0 != m1) {
        *(s32 *)0x1000E060 = arg0;
    }
    return p;
}

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBA28);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBB00);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBBE8);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBCD0);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBD98);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBE88);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DBF78);

INCLUDE_ASM("build/ee_asm/sdk/libdma/libdma", func_002DC040);
