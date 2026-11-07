/* tu_290 0x26ac38-0x26b218: low; unk_26AC38 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

#define MMI_SQ_ZERO(off, p) __asm__ volatile("sq $0, " #off "(%0)" : : "r"(p) : "memory")
#define MMI_SD_ZERO(off, p) __asm__ volatile("sd $0, " #off "(%0)\n\tnop" : : "r"(p) : "memory")
#define VU0_STORE_VF0_NOP(p) __asm__ volatile("sqc2 $vf0, 0(%0)\n\tnop" : : "r"(p) : "memory")
#define MMI_LQ(reg, off, p) __asm__ volatile("lq $" #reg ", " #off "(%0)" : : "r"(p) : "$" #reg, "memory")
#define MMI_SQ(reg, off, p) __asm__ volatile("sq $" #reg ", " #off "(%0)" : : "r"(p) : "memory")
#define MMI_LD(reg, off, p) __asm__ volatile("ld $" #reg ", " #off "(%0)" : : "r"(p) : "$" #reg, "memory")
#define MMI_SD(reg, off, p) __asm__ volatile("sd $" #reg ", " #off "(%0)" : : "r"(p) : "memory")

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

void func_0026AC80(char *a0, char *a1) {
    a0 += **(int **)(a1 + 0xC) + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026ACA0(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            VU0_LQC2(10, 0, p1);
            VU0_LQC2(11, 0, q);
            VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
            VU0_SQC2(10, 0, p1);
        }
        VU0_LQC2(10, 0, p0);
        VU0_LQC2(11, 0, p1);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p0);
    }
}

void func_0026AD08(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026AD28(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            VU0_LQC2(10, 0, p1);
            VU0_LQC2(11, 0, q);
            VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
            VU0_SQC2(10, 0, p1);
        }
        VU0_LQC2(10, 0, p0);
        VU0_LQC2(11, 0, p1);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p0);
    }
}

void func_0026AD90(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026ADB0(char *a0, int *a1, char *a2) {
    char *p;
    int *q;
    int off;

    if (D_006A3BC4 == 0 && a1[0] == *(int *)(a0 + 0xC)) {
        q = a1 + 4;
        off = **(int **)(a2 + 0xC) + 0xA0;
        p = a0 + off;
        MMI_LQ(2, 0x0, p);
        MMI_LQ(3, 0x0, q);
        VU0_OP("paddw $2, $2, $3");
        MMI_SQ(2, 0x0, p);
    }
}

void func_0026ADF8(char *a0, char *a1) {
    a0 += **(int **)(a1 + 0xC) + 0xA0;
    MMI_SQ_ZERO(0, a0);
}

void func_0026AE18(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            MMI_LQ(2, 0x0, p1);
            MMI_LQ(3, 0x0, q);
            VU0_OP("paddw $2, $2, $3");
            MMI_SQ(2, 0x0, p1);
        }
        MMI_LQ(2, 0x0, p0);
        MMI_LQ(3, 0x0, p1);
        VU0_OP("paddw $2, $2, $3");
        MMI_SQ(2, 0x0, p0);
    }
}

void func_0026AE80(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    MMI_SQ_ZERO(0, a0);
}

void func_0026AEA0(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            MMI_LQ(2, 0x0, p1);
            MMI_LQ(3, 0x0, q);
            VU0_OP("paddw $2, $2, $3");
            MMI_SQ(2, 0x0, p1);
        }
        MMI_LQ(2, 0x0, p0);
        MMI_LQ(3, 0x0, p1);
        VU0_OP("paddw $2, $2, $3");
        MMI_SQ(2, 0x0, p0);
    }
}

void func_0026AF08(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    MMI_SQ_ZERO(0, a0);
}

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

void func_0026AF70(char *a0, char *a1) {
    a0 += **(int **)(a1 + 0xC) + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026AF90(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            VU0_LQC2(10, 0, p1);
            VU0_LQC2(11, 0, q);
            VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
            VU0_SQC2(10, 0, p1);
        }
        VU0_LQC2(10, 0, p0);
        VU0_LQC2(11, 0, p1);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p0);
    }
}

void func_0026AFF8(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026B018(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 4;
            VU0_LQC2(10, 0, p1);
            VU0_LQC2(11, 0, q);
            VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
            VU0_SQC2(10, 0, p1);
        }
        VU0_LQC2(10, 0, p0);
        VU0_LQC2(11, 0, p1);
        VU0_OP("vadd.xyzw $vf10, $vf10, $vf11");
        VU0_SQC2(10, 0, p0);
    }
}

void func_0026B080(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    VU0_STORE_VF0_NOP(a0);
}

void func_0026B0A0(char *a0, int *a1, char *a2) {
    char *p;
    int *q;
    int off;

    if (D_006A3BC4 == 0 && a1[0] == *(int *)(a0 + 0xC)) {
        q = a1 + 2;
        off = **(int **)(a2 + 0xC) + 0xA0;
        p = a0 + off;
        MMI_LD(2, 0x0, p);
        MMI_LD(3, 0x0, q);
        VU0_OP("paddh $2, $2, $3");
        MMI_SD(2, 0x0, p);
    }
}

void func_0026B0E8(char *a0, char *a1) {
    a0 += **(int **)(a1 + 0xC) + 0xA0;
    MMI_SD_ZERO(0, a0);
}

void func_0026B108(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 2;
            MMI_LD(2, 0x0, p1);
            MMI_LD(3, 0x0, q);
            VU0_OP("paddh $2, $2, $3");
            MMI_SD(2, 0x0, p1);
        }
        MMI_LD(2, 0x0, p0);
        MMI_LD(3, 0x0, p1);
        VU0_OP("paddh $2, $2, $3");
        MMI_SD(2, 0x0, p0);
    }
}

void func_0026B170(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    MMI_SD_ZERO(0, a0);
}

void func_0026B190(char *a0, int *a1, char *a2) {
    register int *offs __asm__("$7") = *(int **)(a2 + 0xC);
    register int off0 __asm__("$2") = offs[0] + 0xA0;
    register int off1 __asm__("$3") = offs[1] + 0xA0;
    register char *p0 __asm__("$7") = a0 + off0;
    register char *p1 __asm__("$6") = a0 + off1;

    if (D_006A3BC4 == 0) {
        if (a1[0] == *(int *)(a0 + 0xC)) {
            int *q = a1 + 2;
            MMI_LD(2, 0x0, p1);
            MMI_LD(3, 0x0, q);
            VU0_OP("paddh $2, $2, $3");
            MMI_SD(2, 0x0, p1);
        }
        MMI_LD(2, 0x0, p0);
        MMI_LD(3, 0x0, p1);
        VU0_OP("paddh $2, $2, $3");
        MMI_SD(2, 0x0, p0);
    }
}

void func_0026B1F8(char *a0, char *a1) {
    a0 += (*(int **)(a1 + 0xC))[1] + 0xA0;
    MMI_SD_ZERO(0, a0);
}
