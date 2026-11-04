/* tu_170 0x1a21e0-0x1a43b0: low; ~rcef (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/w3.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"

void func_001A21E0(W3Task *t)
{
    if (D_00313CCC.head.next == t && D_00313CCC.tail.prev == D_00313CCC.head.next) {
        func_001A1DC0(t);
    }
}

void func_001A2210(W3Task *t)
{
    if (D_00313EAC == 0) {
        func_001A1DC0(t);
    }
}

void func_001A2230(W3Task *t)
{
    if (D_00313ED0 == 0) {
        func_001A1DC0(t);
    }
}

void func_001A2250(W3Task *t)
{
    if (D_00313EE4 == 0) {
        func_001A1DC0(t);
    }
}

void func_001A2270(W3Task *t)
{
    int id;
    Chr *obj;
    int want;

    id = t->frame[t->sp].count;
    obj = rcefGetChrHandle(id);
    want = t->frame[t->sp].arg1;
    if ((func_00111B50(obj) >> 8) == want) {
        MsEffectSetSpeed(id, 0);
        func_001A1DC0(t);
    }
}

void func_001A2300(W3Task *t)
{
    if (func_0014AA50(t->frame[t->sp].count) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A2348(W3Task *t)
{
    if (op_oef2_sound_cue_check(0x800) == 0) {
        func_001A1DC0(t);
    }
}

void *func_001A2388(void)
{
    void *obj;

    obj = pppMemAlloc(D_006A3924, D_006A3924->sub, 0x100);
    func_001A2400(obj);
    return obj;
}

void func_001A23C8(void *obj)
{
    func_001A24C8(obj);
    func_00267028(D_006A3924, D_006A3924->sub, obj);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2400);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A24C8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2530);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2608);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2698);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2880);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A29A0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A29C8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A29E8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A29F8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2A08);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2A28);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2A38);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2A58);

void func_001A2A78(u32 a0)
{
    __asm__ volatile(
        "lui        $2, %%hi(D_00314240)\n"
        "addiu      $2, $2, %%lo(D_00314240)\n"
        "lqc2       $vf31, 0x0($2)\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0) : "$2");
}

int rcefIsBattle(void)
{
    return MsBattleGetStatus() != 0;
}

Chr *rcefGetChrHandle(int a)
{
    if (rcefIsBattle() != 0) {
        return MsGetChrHandle(a);
    }
    return func_0013B0F8(a);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", rcuiMotionProc);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B58);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B68);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B78);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B80);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B88);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B90);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2C20);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2C80);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2C88);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2CA0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2CB8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2CC0);

void func_001A2CC8(float * v)
{
    __asm__ volatile(
        "lui        $3, (0x42C80000 >> 16)\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "addiu      $2, $4, 0x10\n"
        "lqc2       $vf31, 0x0($2)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $4, $4, 0x20\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        : "+r"(v) :  : "$2", "$3");
}

void func_001A2D10(u32 a0)
{
    __asm__ volatile(
        "lui        $3, (0x3C23D70A >> 16)\n"
        "ori        $3, $3, (0x3C23D70A & 0xFFFF)\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "addiu      $2, $4, 0x10\n"
        "lqc2       $vf31, 0x0($2)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $4, $4, 0x20\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) :  : "$2", "$3");
}

void func_001A2D58(float *p) {
    func_002DD128((struct W3Whole *)p); /* DEBT(CAST): prototype takes the W3Whole view of this object */
    p[10] = 0.01f;
    p[5] = 0.01f;
    p[0] = 0.01f;
}

void func_001A2D98(float *p) {
    func_002DD128((struct W3Whole *)p); /* DEBT(CAST): prototype takes the W3Whole view of this object */
    p[10] = 0.001f;
    p[5] = 0.001f;
    p[0] = 0.001f;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2DD8);

void func_001A2E10(int a, int b, float *c) {
    S2_func_001072F8(rcefGetChrHandle(a), b, c);
    func_001A2CC8(c);
}

void func_001A2E58(int a, int b, float *c) {
    func_001A2E10(a, b, c);
    c[13] = 0;
}

void func_001A2E80(int a, int b, float *c) {
    func_001A2E10(a, func_001A3080(a, b), c);
}

void func_001A2EC0(int a, int b, float *c) {
    func_001A2E58(a, func_001A3080(a, b), c);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2F00);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2F50);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2FD8);

void func_001A3000(int a, int b, float *c) {
    func_001A2F00(a, func_001A3080(a, b), c);
}

void func_001A3040(int a, int b, float *c) {
    func_001A2FD8(a, func_001A3080(a, b), c);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3080);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A30B8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A30E0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3140);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3170);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A31A0);

float func_001A31D0(int id) {
    float v = 0.0f;

    func_001B6E48(id, &v);
    v = func_001A3200(v);
    return v;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3200);

float func_001A32A0(float *v) {
    float r = func_002E93A0(-v[2]);

    if (v[0] > 0.0f) {
        r = 6.2831855f - r;
    }
    return r;
}

void func_001A32F8(float *out, float a) {
    out[0] = -func_002E89C0(a);
    out[1] = 0.0f;
    out[2] = -func_002E8648(a);
    out[3] = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3348);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3360);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A33F0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A33F8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3438);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3478);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3568);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3620);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A36D8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3740);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A37F0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3800);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3818);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3848);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3870);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3890);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A39F0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3A10);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3A40);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3BB0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3BD8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3C50);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3DC8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3ED8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A40E0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4190);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A41D0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4210);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4288);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A42D0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4310);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4370);
