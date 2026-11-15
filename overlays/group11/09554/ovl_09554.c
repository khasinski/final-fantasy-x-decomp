/* EE Battle-Effect Overlay: group 0x11, file 09554
 * Load base: 0x01B00000, .text: 0x01B005F8..0x01B01410 (27 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B005B8[];
extern u8 D_01B005C0[0x38];
extern int D_01B01420;
extern u8 D_01B01430[];
extern float D_01B01470[4];
extern float D_01B01480[4];
extern float D_01B01490[4];
extern int D_01B014A0;
extern float D_01B014B0[3];
extern Chr *D_01B014C0;
extern int D_01B014C4;
extern u8 D_01B014D0[];
extern s32 D_00313E48;

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_SCALEF(d, a, kf, tmp) \
    __asm__ volatile("mfc1 %0, %3\n\tlqc2 $vf31, 0(%2)\n\tqmtc2 %0, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%1)" \
                     : "=&r"(tmp) : "r"(d), "r"(a), "f"(kf) : "memory")

W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");
int func_001BB930_x(int eff, int chr, int a2, int a3, int *p, int t1, int t2, int t3) __asm__("func_001BB930");
void func_001E4C80(int a0, int a1);
void func_001A4288(int se_id);
void func_001A4370(int a0, int a1);
void func_001A2B78(int chr_id, int a1, int a2, int a3, int t0, int t1, float f12, float f13, float f14, float f15, float f16);
void func_001A2B80(int chr_id, int motion_id);
float func_001A31D0(int chr_id);
float func_001A3620(int a0, float f12, float f13, float f14);
void func_001A3848(int a0, int a1, int a2);
void func_001A3A40(int chr_id, void *p, int a2);
void func_001A3BB0(int chr_id);
void func_001A3C50(int chr_id, int a1, void *out, float *in);
void func_001A3740(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int s0);
void func_001C69C8(int chr_id, int a1, int a2);

void func_01B00738(W3Task *t);
void func_01B00780(W3Task *t);
void func_01B00868(W3Task *t);
void func_01B008F0(W3Task *t);
void func_01B00950(W3Task *t);
void func_01B00A08(W3Task *t);
void func_01B00A78(W3Task *t);
void func_01B00AB8(W3Task *t);
void func_01B00AC8(W3Task *t);
void func_01B00B80(W3Task *t);
void func_01B00C28(W3Task *t);
void func_01B00CB0(W3Task *t);
void func_01B00D08(W3Task *t);
void func_01B00D80(W3Task *t);
void func_01B00FB0(W3Task *t);
void func_01B01150(W3Task *t);
void func_01B01198(W3Task *t);

void func_01B005F8(W3Task *t)
{
    int v;
    int f;
    int c;

    D_01B01420 = 0;
    D_01B01470[0] = D_01B01470[1] = D_01B01470[2] = D_01B01470[3] = 0;
    D_01B01480[0] = D_01B01480[1] = D_01B01480[2] = D_01B01480[3] = 0;
    D_01B01490[0] = D_01B01490[1] = D_01B01490[2] = D_01B01490[3] = 0;
    c = D_00313CB0.targets[0];
    func_001BB930_x(D_00313CB0.eff_id, c, 0, 0, &v, 0, 0, 0);
    f = (v >> 8) & 1;
    D_01B014A0 = f;
    func_001E4C80(0, f);
    D_01B014C0 = rcefGetChrHandle(c);
    func_001107D8(D_01B014C0, &D_01B014B0[0], &D_01B014B0[1], &D_01B014B0[2]);
    func_001A42D0(1, 0);
    D_01B014C4 = func_001AF358() == 0x02050000;
    func_001A1D08(t, func_01B00738);
    func_001A1D50(t, func_001A2058);
}

void func_01B00738(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00780);
    func_001A1D50(t, func_001A2098);
}

void func_01B00780(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A4288(0);
    func_001A4370(0, 0);
    if (D_01B014A0) {
        func_0019FF90(&D_00313CB0, func_01B00D08);
    } else {
        func_0019FF90(&D_00313CB0, func_01B01150);
    }
    if (!D_01B014C4) {
        float z = 0;
        func_001A2B78(caster, 2, 0, 20, 32, 32, z, 15.0f, z, z, z);
    }
    func_001A2B80(caster, 200);
    func_001A1D08(t, func_01B00868);
    func_001A1DF0(t, 19);
}

void func_01B00868(W3Task *t)
{
    func_001A4370(0, 1);
    func_0019FF90(&D_00313CB0, func_01B00AC8);
    func_0019FF90(&D_00313CB0, func_01B00B80);
    func_0019FF90(&D_00313CB0, func_01B00C28);
    func_001A1D08(t, func_01B008F0);
    func_001A1DF0(t, 24);
}

void func_01B008F0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A1D08(t, func_01B00950);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00950(W3Task *t)
{
    int caster = D_00313E48;

    if (!D_01B014C4) {
        func_001A2B78(caster, 1, 0, 10, 32, 32, 0, 0, 1.0f, 0.4f, 0);
    }
    func_001A2B80(caster, 201);
    func_001A1D08(t, func_01B00A08);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A08(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 202);
    func_001A1D08(t, func_01B00A78);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A78(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00AB8);
    func_001A1D50(t, func_001A2348);
}

void func_01B00AB8(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00AC8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 0);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->pos[2] = -30.0f;
    o->rot[1] = 180.0f;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00AB8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00B80(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 0);
    o->pos[0] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = -10.0f;
    o->pos[2] = -30.0f;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00AB8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00C28(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313E48, 0);
    o->pos[0] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = -12.0f;
    o->pos[2] = -30.0f;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    func_001A1D08(t, func_01B00CB0);
    func_001A1DF0(t, 23);
}

void func_01B00CB0(W3Task *t)
{
    rcefMainKickPar(&D_00313CB0, (RcefObj *)t, 0, 2);
    func_001A1D08(t, func_01B00AB8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00D08(W3Task *t)
{
    float y = D_01B014B0[1];

    D_01B01480[1] = y * -2.5f;
    D_01B01490[1] = y * 4.75f / 20.0f;
    func_001A1D08(t, func_01B00D80);
    func_001A1DF0(t, 18);
}

void func_01B00D80(W3Task *t)
{
    int tgt = D_00313CB0.targets[0];
    int hnd;
    float ang;
    float p[4];
    float m[16];

    hnd = func_001A3080(tgt, 6);
    if (D_01B01420 < 20) {
        ang = func_001A3620(2, 0.0f, 3.1415927f, (float)D_01B01420 / 20.0f);
    } else {
        ang = 3.1415927f;
    }
    p[0] = 0;
    p[1] = func_001A31D0(tgt);
    p[2] = ang;
    func_001A3C50(tgt, hnd, D_01B01430, p);
    VEC3_ADD(D_01B01430 + 48, D_01B01430 + 48, D_01B01470);
    VEC3_ADD(D_01B01470, D_01B01470, D_01B01480);
    VEC3_ADD(D_01B01480, D_01B01480, D_01B01490);
    func_001A3A40(tgt, D_01B01430, 0);
    D_01B01420++;
    if (D_01B01420 >= 21) {
        int caster = D_00313CB0.caster;
        int ki;
        float k;

        func_001A3800(tgt, 28);
        D_01B01470[1] -= D_01B014B0[1] * 4.0f;
        D_01B01420 = 0;
        func_001A3848(2, 64, 30);
        func_001A2E80(caster, 0, m);
        k = -100.0f;
        __asm__ volatile("" : : "f"(k));
        __asm__ volatile("" : : "f"(k));
        VEC3_SCALEF(D_01B01480, m + 8, k, ki);
        D_01B01490[0] = D_01B01490[1] = D_01B01490[2] = D_01B01490[3] = 0;
        func_001A4310(1);
        func_001A1D08(t, func_01B00FB0);
    }
}

void func_01B00FB0(W3Task *t)
{
    int tgt = D_00313CB0.targets[0];
    int hnd;
    float p[4];

    hnd = func_001A3080(tgt, 6);
    p[0] = 0;
    p[1] = func_001A31D0(tgt);
    p[2] = (float)D_01B01420 * 1.5707964f / 30.0f + 3.1415927f;
    func_001A3C50(tgt, hnd, D_01B01430, p);
    VEC3_ADD(D_01B01430 + 48, D_01B01430 + 48, D_01B01470);
    VEC3_ADD(D_01B01470, D_01B01470, D_01B01480);
    VEC3_ADD(D_01B01480, D_01B01480, D_01B01490);
    func_001A3A40(tgt, D_01B01430, 0);
    if (D_01B01420 == 5) {
        func_001A3740(255, 255, 255, 64, 0, 0, 0, 0, 16);
    }
    D_01B01420++;
    if (D_01B01420 >= 31) {
        func_001A3800(tgt, 0);
        func_001A3BB0(tgt);
        func_001A1D08(t, func_01B00AB8);
    }
}

void func_01B01150(W3Task *t)
{

    D_01B01480[1] = D_01B01490[1] = 0;
    func_001A1D08(t, func_01B01198);
    func_001A1DF0(t, 18);
}

void func_01B01198(W3Task *t)
{
    int tgt = D_00313CB0.targets[0];
    int hnd;
    float p[4];
    float z;

    hnd = func_001A3080(tgt, 6);
    if (D_01B01420 == 0) {
        func_001C69C8(tgt, 5, 1);
    }
    z = 0;
    p[0] = z;
    p[1] = func_001A31D0(tgt);
    p[2] = z;
    func_001A3C50(tgt, hnd, D_01B01430, p);
    VEC3_ADD(D_01B01430 + 48, D_01B01430 + 48, D_01B01470);
    VEC3_ADD(D_01B01470, D_01B01470, D_01B01480);
    VEC3_ADD(D_01B01480, D_01B01480, D_01B01490);
    func_001A3A40(tgt, D_01B01430, 0);
    D_01B01420++;
    if (D_01B01420 >= 21) {
        func_001A3800(tgt, 0);
        func_001A3BB0(tgt);
        t->flags |= 4;
    }
}

int func_01B012E0(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B014D0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B005B8, D_01B005C0);
    func_0019FF90(&D_00313CB0, func_01B005F8);
    return 0;
}

int func_01B01350(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01378(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B013A0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B013C8(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B013F0(void) { return 0; }
int func_01B013F8(void) { return 0; }
int func_01B01400(void) { return 0; }
int func_01B01408(void) { return 0; }
