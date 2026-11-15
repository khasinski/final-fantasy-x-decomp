/* EE Battle-Effect Overlay: group 0x11, file 09404
 * Load base: 0x01B00000, .text: 0x01B00738..0x01B01368 (28 functions)
 *
 * Effect scene: caster motion 184..188 sequence with screen fades, two
 * puffs on the caster, a gathering burst sampled from the target positions
 * and a sequence of sparks.
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B006F8[];
extern u8 D_01B00700[8];
extern u8 D_01B01380[8];
extern RcefObj *D_01B01370;
extern int D_01B01374;
extern void *D_01B01370_a __asm__("D_01B01370");

void func_001A3000(int chr_id, int idx, float *out);
void func_001A3740(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int s0);

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_COPY(d, s) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tsqc2 $vf31, 0(%0)" : : "r"(d), "r"(s) : "memory")

#define MFC1_NV(v, f) __asm__("mfc1 %0, %1" : "=r"(v) : "f"(f))

void func_01B00BE8_a(W3Task *t) __asm__("func_01B00BE8");
void func_01B00788(W3Task *t);
void func_01B00840(W3Task *t);
void func_01B00880(W3Task *t);
void func_01B008F0(W3Task *t);
void func_01B00938(W3Task *t);
void func_01B009F8(W3Task *t);
void func_01B00A40(W3Task *t);
void func_01B00AD0(W3Task *t);
void func_01B00B38(W3Task *t);
void func_01B00BA8(W3Task *t);
void func_01B00BE8(W3Task *t);
void func_01B00BF8(W3Task *t);
void func_01B00CB0(W3Task *t);
void func_01B00D68(W3Task *t);
void func_01B01048(W3Task *t);
void func_01B01080(W3Task *t);
void func_01B011B0(W3Task *t);
void func_01B007D0(W3Task *t);

void func_01B00738(W3Task *t)
{
    D_01B01370 = 0;
    D_01B01374 = 60;
    func_001A1D08(t, func_01B00788);
    func_001A1D50(t, func_001A2058);
}

void func_01B00788(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00880);
    func_001A1D50(t, func_001A2098);
}

void func_01B007D0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 184);
    func_001A1D08(t, func_01B00840);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00840(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 185);
    func_001A1D08(t, func_01B00880);
}

void func_01B00880(W3Task *t)
{
    func_001A36D8(0, 0, 0, 64, 15);
    func_001A4288(0);
    func_0019FF90(&D_00313CB0, func_01B00BF8);
    func_001A1D08(t, func_01B008F0);
    func_001A1DF0(t, 36);
}

void func_01B008F0(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 186);
    func_001A1D08(t, func_01B00938);
    func_001A1DF0(t, 24);
}

void func_01B00938(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A3740(255, 255, 255, 128, 0, 0, 0, 64, 8);
    func_0019FF90(&D_00313CB0, func_01B00CB0);
    D_01B01370_a = func_0019FF90(&D_00313CB0, func_01B00D68);
    func_001A1D08(t, func_01B009F8);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B009F8(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 187);
    func_001A1D08(t, func_01B00A40);
    func_001A1DF0(t, 30);
}

void func_01B00A40(W3Task *t)
{
    func_001A3740(255, 255, 255, 128, 0, 0, 0, 64, 12);
    func_001A4288(1);
    func_001A3800(-5, 0);
    func_0019FF90(&D_00313CB0, func_01B011B0);
    func_001A1D08(t, func_01B00AD0);
    func_001A1D50(t, func_001A2210);
}

void func_01B00AD0(W3Task *t)
{
    func_001A3740(0, 0, 0, 64, 0, 0, 0, 0, 15);
    func_001A1D08(t, func_01B00B38);
    func_001A1DF0(t, 20);
}

void func_01B00B38(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 188);
    func_001A1D08(t, func_01B00BA8);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00BA8(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00BE8(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00BF8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 6);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos[2] = -20.0f;
    o->pos_w = 0;
    o->rot[0] = -15.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.25f;
    o->scale[1] = 0.25f;
    o->scale[2] = 0.25f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00CB0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 6);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos[2] = -13.0f;
    o->pos_w = 0;
    o->rot[0] = -15.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00D68(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float c[4];
    float a[4];
    float g[4];
    float tmp[4];
    float m[20];
    float k;
    float z;
    float h;
    int ki;
    int n = 60;
    int j = 0;
    register int i __asm__("$18");
    register float *dp __asm__("$21");
    int caster = D_00313CB0.caster;

    func_001A3000(caster, 6, p);
    func_001A2E80(caster, 6, m);
    MFC1_NV(ki, -150.0f);
    VEC3_SCALE(tmp, m + 8, ki);
    VEC3_ADD(p, p, tmp);
    MFC1_NV(ki, 20.0f);
    VEC3_SCALE(tmp, m + 4, ki);
    VEC3_ADD(p, p, tmp);
    z = 0.0f;
    c[0] = z;
    c[3] = z;
    c[2] = z;
    c[1] = z;
    for (i = 0; i < D_00313CB0.target_count; i++) {
        func_001A3000(D_00313CB0.targets[i], j, tmp);
        VEC3_ADD(c, c, tmp);
    }
    MFC1_NV(ki, 1.0f / (float)D_00313CB0.target_count);
    VEC3_SCALE(c, c, ki);
    dp = a;
    VEC3_SUB(dp, c, p);
    MFC1_NV(ki, 1.0f / (float)n);
    VEC3_SCALE(dp, dp, ki);
    h = 0.1f;
    __asm__("" : "+f"(h));
    a[1] = a[1] - 30.0f * h;
    g[0] = 0;
    g[1] = h;
    g[2] = 0;
    g[3] = 0;
    func_0019FF90(&D_00313CB0, func_01B01048);
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->vel[0] = a[0];
    o->vel[1] = a[1];
    o->vel[2] = a[2];
    o->acc[0] = g[0];
    o->acc[1] = g[1];
    o->acc[2] = g[2];
    o->pos_w = 0;
    o->vel[3] = 0;
    o->acc_w = 0;
    o->scale[3] = 0;
    o->scale[0] = 0.26f;
    o->scale[1] = 0.26f;
    o->scale[2] = 0.26f;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B00BE8);
    func_001A1DF0(t, 54);
}

void func_01B01048(W3Task *t)
{
    D_01B01374 = D_01B01374 - 1;
    if (D_01B01374 >= 0) {
        func_0019FF90(&D_00313CB0, func_01B01080);
        return;
    }
    func_001A1D08(t, func_01B00BE8);
}

void func_01B01080(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float r;
    float s;
    float *src;
    int ki;

    s = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    r = (float)func_002EFD78() * 4.656612873077393e-10f * 0.2f + 0.2f;
    src = D_01B01370->pos;
    VEC3_COPY(p, src);
    o->pos[0] = p[0];
    o->unk170[0] = 1.0f;
    o->pos[1] = p[1];
    o->scale[0] = r;
    o->pos_w = 0;
    o->pos[2] = p[2];
    o->scale[1] = r;
    o->scale[2] = r;
    o->rot[0] = 0;
    o->unk170[1] = 1.0f;
    o->unk170[2] = 1.0f;
    o->unk170[3] = 0.3f;
    o->flagsBC |= 0x4000;
    o->rot[2] = s;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    func_001A0000(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A2110);
}

void func_01B011B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->pos[0] = 0;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = -0.1f;
    o->scale[0] = 0.5f;
    o->scale[1] = 0.5f;
    o->scale[2] = 0.5f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}

int func_01B01238(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01380, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B006F8, D_01B00700);
    func_0019FF90(&D_00313CB0, func_01B00738);
    return 0;
}

int func_01B012A8(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B012D0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B012F8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01320(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01348(void)
{
    return 0;
}

int func_01B01350(void)
{
    return 0;
}

int func_01B01358(void)
{
    return 0;
}

int func_01B01360(void)
{
    return 0;
}
