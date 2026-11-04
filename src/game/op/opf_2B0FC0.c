/* tu_325 0x2b0fc0-0x2b1720: medium; ~opf (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"

void func_002B0FC0(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $6, 0x220($4)\n"
        "addiu      $6, $6, 0x30\n"
        "lui        $3, (0x3D800000 >> 16)\n"
        "qmtc2.ni   $3, $vf26\n"
        "lqc2       $vf21, 0x10($6)\n"
        "vmulx.xyzw $vf21, $vf21, $vf26x\n"
        "sqc2       $vf21, 0x60($6)\n"
        "daddu     $2, $5, $0\n"
        :  : "r"(a0), "r"(a1) : "$2", "$3", "$6");
}

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B0FE8);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B10B0);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B1170);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B12D8);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B1390);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", opf_sph);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B1500);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", func_002B15B0);

INCLUDE_ASM("build/ee_asm/game/op/opf_2B0FC0", opf_spl_gw);
