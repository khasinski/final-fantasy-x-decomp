/* EE Battle-Effect Overlay: group 0x11, file 09356 (group_index 300)
 * Load base: 0x01B00000, .text: 0x01B005F8..0x01B013C0 (27 functions)
 */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B005B8[];
extern u8 D_01B005C0[0x38];
extern int D_01B013D0;
extern int D_01B013C0[];
extern u8 D_01B013E0[];
extern int D_01B01420_dummy;
extern float D_01B01420[4];
extern float D_01B01430[4];
extern float D_01B01440[4];
extern float D_01B01450[3];
extern Chr *D_01B01460;
extern u8 D_01B01470[];
extern s32 D_00313E48;

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC3_SCALEF(d, a, kf, tmp) \
    __asm__ volatile("mfc1 %0, %3\n\tlqc2 $vf31, 0(%2)\n\tqmtc2 %0, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%1)" \
                     : "=&r"(tmp) : "r"(d), "r"(a), "f"(kf) : "memory")

W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");
int func_001BB930_x(int eff, int chr, int a2, int a3, int *p, int t1, int t2, int t3) __asm__("func_001BB930");
void func_001A4288(int se_id);
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

void func_01B006C8(W3Task *t);
void func_01B00710(W3Task *t);
void func_01B00828(W3Task *t);
void func_01B008B8(W3Task *t);
void func_01B00918(W3Task *t);
void func_01B009C0(W3Task *t);
void func_01B00A30(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00A80(W3Task *t);
void func_01B00B50(W3Task *t);
void func_01B00BD8(W3Task *t);
void func_01B00C60(W3Task *t);
void func_01B00CB8(W3Task *t);
void func_01B00D30(W3Task *t);
void func_01B00F60(W3Task *t);
void func_01B01100(W3Task *t);
void func_01B01148(W3Task *t);

void func_01B005F8(W3Task *t)
{
    register int c __asm__("$10");
    float z = 0;

    c = D_00313CB0.targets[0];
    D_01B013C0[4] = 0;
    D_01B01420[0] = D_01B01420[1] = D_01B01420[2] = D_01B01420[3] = z;
    D_01B01430[0] = D_01B01430[1] = D_01B01430[2] = D_01B01430[3] = z;
    D_01B01440[0] = D_01B01440[1] = D_01B01440[2] = D_01B01440[3] = z;
    D_01B01460 = rcefGetChrHandle(c);
    func_001107D8(D_01B01460, &D_01B01450[0], &D_01B01450[1], &D_01B01450[2]);
    func_001A42D0(1, 0);
    func_001A1D08(t, func_01B006C8);
    func_001A1D50(t, func_001A2058);
}

void func_01B006C8(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00710);
    func_001A1D50(t, func_001A2098);
}

void func_01B00710(W3Task *t)
{
    int v;
    int tgt = D_00313CB0.targets[0];
    int caster = D_00313CB0.caster;
    float z;

    func_001A4288(0);
    func_001BB930_x(D_00313CB0.eff_id, tgt, 0, 0, &v, 0, 0, 0);
    if ((v >> 8) & 1) {
        func_0019FF90(&D_00313CB0, func_01B00CB8);
    } else {
        func_0019FF90(&D_00313CB0, func_01B01100);
    }
    z = 0;
    func_001A2B78(caster, 2, 0, 20, 32, 32, z, 15.0f, z, z, z);
    func_001A2B80(caster, 176);
    func_001A1D08(t, func_01B00828);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00828(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_0019FF90(&D_00313CB0, func_01B00A80);
    func_0019FF90(&D_00313CB0, func_01B00B50);
    func_0019FF90(&D_00313CB0, func_01B00BD8);
    func_001A2B80(caster, 177);
    func_001A1D08(t, func_01B008B8);
    func_001A1DF0(t, 24);
}

void func_01B008B8(W3Task *t)
{
    int caster = D_00313E48;

    func_001A1D08(t, func_01B00918);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00918(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B78(caster, 1, 0, 10, 32, 32, 0, 0, 1.0f, 0.4f, 0);
    func_001A2B80(caster, 178);
    func_001A1D08(t, func_01B009C0);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B009C0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 179);
    func_001A1D08(t, func_01B00A30);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00A30(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00A70);
    func_001A1D50(t, func_001A2348);
}

void func_01B00A70(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00A80(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A1420(o, 16);
    func_001A13A0(o, caster, 7);
    o->pos[0] = 0;
    o->pos[1] = 5.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 180.0f;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00A70);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00B50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 6);
    o->scale[3] = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00A70);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00BD8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313E50, 6);
    func_001A1420(o, 64);
    o->pos[0] = 0;
    o->pos[1] = -7.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = 0.1f;
    func_001A1D08(t, func_01B00C60);
    func_001A1DF0(t, 23);
}

void func_01B00C60(W3Task *t)
{
    rcefMainKickPar(&D_00313CB0, (RcefObj *)t, 0, 2);
    func_001A1D08(t, func_01B00A70);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00CB8(W3Task *t)
{
    float y = D_01B01450[1];

    D_01B01430[1] = y * -2.5f;
    D_01B01440[1] = y * 4.75f / 20.0f;
    func_001A1D08(t, func_01B00D30);
    func_001A1DF0(t, 18);
}

void func_01B00D30(W3Task *t)
{
    int tgt = D_00313CB0.targets[0];
    int hnd;
    float ang;
    float p[4];
    float m[16];

    hnd = func_001A3080(tgt, 6);
    if (D_01B013D0 < 20) {
        ang = func_001A3620(2, 0.0f, 3.1415927f, (float)D_01B013D0 / 20.0f);
    } else {
        ang = 3.1415927f;
    }
    p[0] = 0;
    p[1] = func_001A31D0(tgt);
    p[2] = ang;
    func_001A3C50(tgt, hnd, D_01B013E0, p);
    VEC3_ADD(D_01B013E0 + 48, D_01B013E0 + 48, D_01B01420);
    VEC3_ADD(D_01B01420, D_01B01420, D_01B01430);
    VEC3_ADD(D_01B01430, D_01B01430, D_01B01440);
    func_001A3A40(tgt, D_01B013E0, 0);
    D_01B013D0++;
    if (D_01B013D0 >= 21) {
        int caster = D_00313CB0.caster;
        int ki;
        float k;

        func_001A3800(tgt, 28);
        D_01B01420[1] -= D_01B01450[1] * 4.0f;
        D_01B013D0 = 0;
        func_001A3848(2, 64, 30);
        func_001A2E80(caster, 0, m);
        k = -100.0f;
        __asm__ volatile("" : : "f"(k));
        __asm__ volatile("" : : "f"(k));
        VEC3_SCALEF(D_01B01430, m + 8, k, ki);
        D_01B01440[0] = D_01B01440[1] = D_01B01440[2] = D_01B01440[3] = 0;
        func_001A4310(1);
        func_001A1D08(t, func_01B00F60);
    }
}

void func_01B00F60(W3Task *t)
{
    int tgt = D_00313E50;
    int hnd;
    float p[4];

    hnd = func_001A3080(tgt, 6);
    p[0] = 0;
    p[1] = func_001A31D0(tgt);
    p[2] = (float)D_01B013D0 * 1.5707964f / 30.0f + 3.1415927f;
    func_001A3C50(tgt, hnd, D_01B013E0, p);
    VEC3_ADD(D_01B013E0 + 48, D_01B013E0 + 48, D_01B01420);
    VEC3_ADD(D_01B01420, D_01B01420, D_01B01430);
    VEC3_ADD(D_01B01430, D_01B01430, D_01B01440);
    func_001A3A40(tgt, D_01B013E0, 0);
    if (D_01B013D0 == 5) {
        func_001A3740(255, 255, 255, 64, 0, 0, 0, 0, 16);
    }
    D_01B013D0++;
    if (D_01B013D0 >= 31) {
        func_001A3800(tgt, 0);
        func_001A3BB0(tgt);
        func_001A1D08(t, func_01B00A70);
    }
}

void func_01B01100(W3Task *t)
{
    D_01B01430[1] = D_01B01440[1] = 0;
    func_001A1D08(t, func_01B01148);
    func_001A1DF0(t, 18);
}

void func_01B01148(W3Task *t)
{
    int tgt = D_00313E50;
    int hnd;
    float p[4];
    float z;

    hnd = func_001A3080(tgt, 6);
    if (D_01B013D0 == 0) {
        func_001C69C8(tgt, 5, 1);
    }
    z = 0;
    p[0] = z;
    p[1] = func_001A31D0(tgt);
    p[2] = z;
    func_001A3C50(tgt, hnd, D_01B013E0, p);
    VEC3_ADD(D_01B013E0 + 48, D_01B013E0 + 48, D_01B01420);
    VEC3_ADD(D_01B01420, D_01B01420, D_01B01430);
    VEC3_ADD(D_01B01430, D_01B01430, D_01B01440);
    func_001A3A40(tgt, D_01B013E0, 0);
    D_01B013D0++;
    if (D_01B013D0 >= 21) {
        func_001A3800(tgt, 0);
        func_001A3BB0(tgt);
        t->flags |= 4;
    }
}

int func_01B01290(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01470, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B005B8, D_01B005C0);
    func_0019FF90(&D_00313CB0, func_01B005F8);
    return 0;
}

int func_01B01300(void)
{
    rcefMainProcRunAfter((void *)&D_00313CB0);
    return 0;
}

int func_01B01328(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01350(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01378(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B013A0(void) { return 0; }
int func_01B013A8(void) { return 0; }
int func_01B013B0(void) { return 0; }
int func_01B013B8(void) { return 0; }
