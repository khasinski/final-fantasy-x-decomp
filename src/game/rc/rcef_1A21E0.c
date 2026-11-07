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

/* DEBT(CAST) */
void func_001A24C8(void *obj) {
    void *temp_6;

    Ch_TextureSetImageBase((*(Chr **)((u8 *)(obj) + (4))), -1, -1);
    Ch_TextureSetClutBase((*(Chr **)((u8 *)(obj) + (4))), -1, -1);
    Ch_DrawEnEffect((*(Chr **)((u8 *)(obj) + (4))), 0);
    temp_6 = (*(void **)((u8 *)(obj) + (8)));
    if (temp_6 != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, temp_6);
        (*(void **)((u8 *)(obj) + (8))) = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2530);

int _m2c_func_001A2608_Ch_TextureLoadImage(int, int) __asm__("Ch_TextureLoadImage");
s32 _m2c_func_001A2608_func_0010D4D8(s32, s32) __asm__("func_0010D4D8");
s32 _m2c_func_001A2608_op1_mdc_draw(s32, void *, void *, s32, s32) __asm__("op1_mdc_draw");
/* DEBT(CAST) */
void func_001A2608(void *arg0) {
    void *temp_17;
    void *temp_18;

    temp_18 = arg0 + 0xC0;
    temp_17 = arg0 + 0x80;
    func_002DCE38(temp_17, D_003142A0, temp_18);
    func_002DCE38(temp_17, D_00314260, temp_17);
    _m2c_func_001A2608_Ch_TextureLoadImage((*(s32 *)((u8 *)(arg0) + (4))), -1);
    _m2c_func_001A2608_func_0010D4D8((*(s32 *)((u8 *)(arg0) + (4))), -1);
    _m2c_func_001A2608_op1_mdc_draw((*(s32 *)((u8 *)(arg0) + (8))), arg0 + 0x10, temp_18, 0, 0);
}

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
extern float D_00314234;

s32 func_001A29A0(s32 arg0) {
    s32 _bit_v;
    u8 *_base_p = (u8 *)&D_00313F30;
    _bit_v = (*(u16 *)((arg0 * 0x30) + _base_p)) & 2;
    return _bit_v != 0;
}

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

/* DEBT(CAST) */
float func_001A2A08(s32 arg0) {
    u8 *_base_p = (u8 *)&D_00313F30;
    return (*(float *)((u8 *)(((arg0 * 0x30) + _base_p)) + (8)));
}

float func_001A2A28(void)
{
    return D_00314234;
}

/* DEBT(CAST) */
float func_001A2A38(s32 arg0) {
    u8 *_base_p = (u8 *)&D_00313F30;
    return (*(float *)((u8 *)(((arg0 * 0x30) + _base_p)) + (0xC)));
}

/* DEBT(CAST) */
float func_001A2A58(s32 arg0) {
    u8 *_base_p = (u8 *)&D_00313F30;
    return (*(float *)((u8 *)(((arg0 * 0x30) + _base_p)) + (0x10)));
}

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

int _m2c_func_001A2B58_MsEffectReady(int id, int flag) __asm__("MsEffectReady");
void func_001A2B58(s32 arg0) {
    _m2c_func_001A2B58_MsEffectReady(D_00313CB4, arg0 != 0);
}

extern s32 _m2c_func_001A2B68_D_00313E48 __asm__("D_00313E48");
void func_001A2B68(void) {
    MsEffectEndMotion(_m2c_func_001A2B68_D_00313E48, 0);
}

s32 _m2c_func_001A2B78_MsSetMove() __asm__("MsSetMove");
void func_001A2B78(void) {
    _m2c_func_001A2B78_MsSetMove();
}

void func_001A2B80(void) {
    func_001CE050();
}

void func_001A2B88(s32 arg0) {
    MsEffectEndMotion(arg0, 0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2B90);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A2C20);

void _m2c_func_001A2C80_MsSetChrPos(int id, float *pos) __asm__("MsSetChrPos");
void func_001A2C80(s32 arg0, float *arg1) {
    _m2c_func_001A2C80_MsSetChrPos(arg0, arg1);
}

void func_001A2C88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MsSetChrDirTarget(arg0, 2, 0, arg1, arg2, arg3);
}

void func_001A2CA0(s32 arg0, s32 arg1, s32 arg2) {
    MsSetChrDirTarget(arg0, 1, 0, 0, arg1, arg2);
}

void func_001A2CB8(Chr *arg0) {
    func_002994B8(arg0);
}

void func_001A2CC0(Chr *arg0) {
    func_002994D8(arg0);
}

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

int MsSetChrDirF(int id, float v); /* DEBT(TYPE): defined with u8 id, callers do not mask */
void func_001A31A0(s32 arg0, float fparg0) {
    MsSetChrDirF(arg0, func_001A3200(fparg0));
}

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

void func_001A33F0(s32 arg0, s32 arg1) {
    MsSetChrVisible(arg0, arg1);
}

int MsGetWeaponHandle(int id, int flag); /* DEBT(TYPE): guessed from call sites */
void func_001A33F8(s32 arg0, s32 arg1) {
    s32 temp_2;

    temp_2 = MsGetWeaponHandle(arg0, 0);
    if (temp_2 != 0) {
        func_00110718(temp_2, arg1 == 0);
    }
}

int MsGetWeaponHandle(int id, int flag); /* DEBT(TYPE): guessed from call sites */
void func_001A3438(s32 arg0, s32 arg1) {
    s32 temp_2;

    temp_2 = MsGetWeaponHandle(arg0, 1);
    if (temp_2 != 0) {
        func_00110718(temp_2, arg1 == 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3478);

typedef struct RcefCtx238 {
    u8 pad0[0x204];
    s32 w204;
    float f208;
    s32 w20C;
    s32 w210;
    s32 w214;
    s32 w218;
    s32 w21C;
    s32 w220;
    s32 w224;
    s32 w228;
    s32 w22C;
    s32 w230;
    s32 w234;
} RcefCtx238;

extern RcefCtx238 D_00313CB0;
extern void func_001A01B0(void *ctx, float *c, int frames);
extern void func_001A01E0(void *ctx, float *c0, float *c1, int frames);

void func_001A3568(float *v)
{
    do {
        v[0] = (float)func_002EFD78() * 4.656612873077393e-10f * 2.0f - 1.0f;
        v[2] = (float)func_002EFD78() * 4.656612873077393e-10f * 2.0f - 1.0f;
        v[1] = v[3] = 0.0f;
        rcVec3fNormalize((Vec4 *)v); /* DEBT(CAST) */
    } while (v[0] == 0.0f && v[2] == 0.0f);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3620);

void func_001A36D8(u8 r, u8 g, u8 b, u8 a, int frames)
{
    float c[4];

    c[0] = r;
    c[1] = g;
    c[2] = b;
    c[3] = a;
    func_001A01B0(&D_00313CB0, c, frames);
}

void func_001A3740(u8 r0, u8 g0, u8 b0, u8 a0, u8 r1, u8 g1, u8 b1, u8 a1, int frames)
{
    float c0[4];
    float c1[4];

    c0[0] = r0;
    c0[1] = g0;
    c0[2] = b0;
    c0[3] = a0;
    c1[0] = r1;
    c1[1] = g1;
    c1[2] = b1;
    c1[3] = a1;
    func_001A01E0(&D_00313CB0, c0, c1, frames);
}

s32 _m2c_func_001A37F0_func_001A0210(s32 *) __asm__("func_001A0210");
extern s32 _m2c_func_001A37F0_D_00313CB0 __asm__("D_00313CB0");
void func_001A37F0(void) {
    _m2c_func_001A37F0_func_001A0210(&_m2c_func_001A37F0_D_00313CB0);
}

void func_001A3800(s32 arg0, s32 arg1) {
    func_001C5E90(D_00313CB4, arg0, arg1);
}

void func_001A3818(int a0, int a1, int a2, int a3, float f12)
{
    D_00313CB0.w220 = 1;
    D_00313CB0.w204 = a0;
    D_00313CB0.f208 = f12;
    D_00313CB0.w20C = a1;
    D_00313CB0.w214 = a2;
    D_00313CB0.w218 = a3;
    D_00313CB0.w210 = 0;
}

void func_001A3848(int a0, int a1, int a2)
{
    D_00313CB0.w234 = 1;
    D_00313CB0.w224 = a0;
    D_00313CB0.w228 = a1;
    D_00313CB0.w22C = a2;
    D_00313CB0.w230 = 0;
}

s32 _m2c_func_001A3870_Ch_ClutCreate(Chr *) __asm__("Ch_ClutCreate");
void func_001A3870(s32 arg0) {
    _m2c_func_001A3870_Ch_ClutCreate(rcefGetChrHandle(arg0));
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3890);

void func_001A39F0(s32 arg0) {
    Ch_ClutDispose(rcefGetChrHandle(arg0));
}

void func_001A3A10(s32 arg0, s32 arg1) {
    Ch_SetOrgMatrix(rcefGetChrHandle(arg0), arg1);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A3A40);

void func_001A3BB0(s32 arg0) {
    Ch_SetOrgMatrix(rcefGetChrHandle(arg0), 0);
}

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

s32 _m2c_func_001A4190_func_001A40E0(s32, s32, s32) __asm__("func_001A40E0");
void func_001A4190(s32 arg0, s32 arg1, s32 arg2) {
    _m2c_func_001A4190_func_001A40E0(arg0, func_001A3080(arg0, arg1), arg2);
}

void func_001A41D0(int a, float *out)
{
    float m[16];

    func_001A2E80(a, 0, m);
    VU0_LQC2(31, 0, m + 8);
    VU0_SQC2(31, 0, out);
    rcVec3fNormalize((Vec4 *)out); /* DEBT(CAST) */
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_1A21E0", func_001A4210);

int *_m2c_func_001A4288_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
s32 _m2c_func_001A4288_op_oef2_se_on(PtrHolder8 *, s32, s32) __asm__("op_oef2_se_on");
extern s32 _m2c_func_001A4288_D_00313CB8 __asm__("D_00313CB8");
void func_001A4288(s32 arg0) {
    PtrHolder8 *temp_2;

    temp_2 = _m2c_func_001A4288_op_oef2_a_get(_m2c_func_001A4288_D_00313CB8, 6, arg0);
    func_002943B8(temp_2);
    _m2c_func_001A4288_op_oef2_se_on(temp_2, 0x40, 0x100);
}

int *_m2c_func_001A42D0_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
s32 _m2c_func_001A42D0_op_oef2_stream_cue(s32 *, s32, s32) __asm__("op_oef2_stream_cue");
extern s32 _m2c_func_001A42D0_D_00313CB8 __asm__("D_00313CB8");
void func_001A42D0(s32 arg0, s32 arg1) {
    _m2c_func_001A42D0_op_oef2_stream_cue(_m2c_func_001A42D0_op_oef2_a_get(_m2c_func_001A42D0_D_00313CB8, 6, arg0), arg1, 0x800);
}

int *_m2c_func_001A4310_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
s32 _m2c_func_001A4310_op_oef2_se_on(s32 *, s32, s32) __asm__("op_oef2_se_on");
extern s32 _m2c_func_001A4310_D_00313CB8 __asm__("D_00313CB8");
void func_001A4310(s32 arg0) {
    if (op_oef2_sound_cue_check(0x800) == 0) {
        _m2c_func_001A4310_op_oef2_se_on(_m2c_func_001A4310_op_oef2_a_get(_m2c_func_001A4310_D_00313CB8, 6, arg0), 0x40, 0x100);
    }
}

void _m2c_func_001A4370_func_0014D3F0(int a, int b, int c) __asm__("func_0014D3F0");
int *_m2c_func_001A4370_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
extern s32 _m2c_func_001A4370_D_00313CB8 __asm__("D_00313CB8");
void func_001A4370(s32 arg0, s32 arg1) {
    _m2c_func_001A4370_func_0014D3F0(7, arg1, _m2c_func_001A4370_op_oef2_a_get(_m2c_func_001A4370_D_00313CB8, 5, arg0));
}
