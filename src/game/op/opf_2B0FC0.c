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

extern char D_00575AC0[];
void func_00120108(char *fmt, ...);
void func_002EA328(int status) __attribute__((noreturn));
void op_spline_xyz(void *dst, float t, int a, int b, s16 n);
void func_002B5978(float *dst, float *src, float s);

typedef struct SplRec {
    s16 h0;
    u8 pad2[5];
    s8 b7;
    int w8;
    int wC;
} SplRec;

void opf_spl_gw(void *a0)
{
    s8 *sub = *(s8 **)((u8 *)a0 + 0x220);
    u8 *base = (u8 *)opus_no_get((u8 *)a0 + 0x300, sub, *(s16 *)(sub + 0xA0));
    SplRec *sp = *(SplRec **)(base + 0xBC);

    if (sp == 0) {
        func_00120108(D_00575AC0);
        func_002EA328(1);
    }
    op_spline_xyz(a0, *(float *)(sub + sub[0xA2]) * (1.0f / 256.0f), sp->w8, sp->wC, sp->h0);
    if (sp->b7 != 0) {
        func_002B5978((float *)(sub + 0x90), (float *)a0, 16.0f);
    } else {
        func_002B5978((float *)(sub + 0x90), (float *)a0, 1.0f);
    }
}
