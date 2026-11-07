/* tu_170 0x1a21e0-0x1a43b0: low; ~rcef (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/w3.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "vu0.h"

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

typedef struct RcefSlot30 {
    u16 flags;
    s16 timer;
    u8 pad04[0x2C];
} RcefSlot30;

extern RcefSlot30 D_00313F30[16];
extern s16 D_00314230;
extern s16 D_00314232;

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A29A0);

void func_001A29C8(int i)
{
    D_00313F30[i].flags = 0;
}

int func_001A29E8(void)
{
    return D_00314230;
}

void func_001A29F8(int v)
{
    D_00314232 = v;
}

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

void func_001A2DD8(float *v)
{
    float k = -651.89862f; /* 0xC422F983 */
    int ki;

    MIPS_MFC1(ki, k);
    VU0_LQC2(31, 0, v);
    VU0_QMTC2_NI(30, ki);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, v);
    k = 1024.0f;
    v[1] -= k;
}

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

void func_001A2F00(int a, int b, float *c)
{
    float m[16];

    ((void (*)(Chr *, int, float *))func_001072F8)(rcefGetChrHandle(a), b, m); /* DEBT(CAST) */
    VU0_LQC2(31, 0, m + 12);
    VU0_SQC2(31, 0, c);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2F50);

void func_001A2FD8(int a, int b, float *c)
{
    func_001A2F00(a, b, c);
    c[1] = 0;
}

void func_001A3000(int a, int b, float *c) {
    func_001A2F00(a, func_001A3080(a, b), c);
}

void func_001A3040(int a, int b, float *c) {
    func_001A2FD8(a, func_001A3080(a, b), c);
}

int func_001A3080(int a, int b)
{
    return Ch_OptposGetElement((s32)rcefGetChrHandle(a), b, 0); /* DEBT(CAST): Ch_OptposGetElement declared with s32 */
}

float func_001A30B8(int a)
{
    return Ch_GetFixHeight(rcefGetChrHandle(a));
}

float func_001A30E0(int a)
{
    float v0[4];
    float v1[4];
    Chr *c;

    c = rcefGetChrHandle(a);
    Ch_OptposGet(c, 0, v0);
    Ch_OptposGet(c, 2, v1);
    return (v0[1] - v1[1]) * 10.0f;
}

float func_001A3140(int a)
{
    return func_00110910(rcefGetChrHandle(a)) * 10.0f;
}

float func_001A3170(int a)
{
    return func_001109E0(rcefGetChrHandle(a)) * 10.0f;
}

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

float func_001A3348(float a)
{
    return 4.712389f - a;
}

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

extern void func_001A2DD8(float *v);
extern void func_001A2D58(float *m);

void func_001A3BD8(int id, int dst, float *in)
{
    float a[4];
    float b[4];
    float m[16];

    VU0_LQC2(31, 0, in);
    VU0_SQC2(31, 0, a);
    func_001A2DD8(a);
    func_001B6790(id, b);
    func_001A2D58(m);
    op_rt_m_yxz(dst, (int)m, (int)a, (int)b); /* DEBT(CAST): prototype takes four ints */
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3C50);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3DC8);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3ED8);

void func_001A40E0(int a, int b, float *out)
{
    float m0[16];
    float m1[16];
    register Chr *c __asm__("$18"); /* DEBT(FAKE): keeps the original callee-saved register order */
    int i;
    register float *p __asm__("$3"); /* DEBT(FAKE): original pointer registers */
    register float *q __asm__("$2");
    float k;
    int ki;

    c = rcefGetChrHandle(a);
    i = func_001A3080(a, 0);
    ((void (*)(Chr *, int, float *))func_001072F8)(c, b, m0); /* DEBT(CAST) */
    ((void (*)(Chr *, int, float *))func_001072F8)(c, i, m1);
    p = m0 + 12;
    q = m1 + 12;
    VU0_LQC2(31, 0, p);
    VU0_LQC2(30, 0, q);
    VU0_OP("vsub.xyz $vf31, $vf31, $vf30");
    VU0_SQC2(31, 0, out);
    k = 10.0f;
    MIPS_MFC1(ki, k);
    VU0_LQC2(31, 0, out);
    VU0_QMTC2_NI(30, ki);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, out);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4190);

void func_001A41D0(int a, float *out)
{
    float m[16];

    func_001A2E80(a, 0, m);
    VU0_LQC2(31, 0, m + 8);
    VU0_SQC2(31, 0, out);
    rcVec3fNormalize((Vec4 *)out); /* DEBT(CAST) */
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4210);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4288);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A42D0);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4310);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4370);
