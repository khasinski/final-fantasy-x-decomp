/* tu_290 0x26ac38-0x26b218: low; unk_26AC38 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_0026AC38(char *a0, int *a1, char *a2) {
    char *p;
    int *q;
    int off;

    if (D_006A3BC4 == 0 && a1[0] == *(int *)(a0 + 0xC)) {
        q = a1 + 4;
        off = **(int **)(a2 + 0xC) + 0xA0;
        p = a0 + off;
        VU0_LQC2(10, 0, p);
        VU0_LQC2(11, 0, q);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p);
    }
}

void func_0026AC80(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x0($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026ACA0);

void func_0026AD08(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x4($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AD28);

void func_0026AD90(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x4($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026ADB0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026ADF8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AE18);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AE80);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AEA0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AF08);

void func_0026AF28(char *a0, int *a1, char *a2) {
    char *p;
    int *q;
    int off;

    if (D_006A3BC4 == 0 && a1[0] == *(int *)(a0 + 0xC)) {
        q = a1 + 4;
        off = **(int **)(a2 + 0xC) + 0xA0;
        p = a0 + off;
        VU0_LQC2(10, 0, p);
        VU0_LQC2(11, 0, q);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p);
    }
}


void func_0026AF70(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x0($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026AF90);

void func_0026AFF8(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x4($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B018);

void func_0026B080(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lw         $2, 0xC($5)\n"
        "lw         $3, 0x4($2)\n"
        "addiu      $3, $3, 0xA0\n"
        "addu       $4, $4, $3\n"
        "sqc2       $vf0, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) : "r"(a1) : "$2", "$3");
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B0A0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B0E8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B108);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B170);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B190);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26AC38", func_0026B1F8);
