/* EE Battle-Effect Overlay: group 0x11, file 09405
 * .text: 0x01B00D00..0x01B01AD8 (12 functions).
 */
#include "rcef_overlay.h"
#include "vu0.h"

#define VEC3_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC4_SCALE(d, a, ki) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tqmtc2.ni %2, $vf30\n\tvmulx.xyzw $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(ki) : "memory")

#define VEC4_SUB(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvsub.xyzw $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

#define VEC4_ADD(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvadd.xyzw $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")

extern float D_01B01C50[4][4];
extern float D_01B01C80[4];
extern float D_01B01C90[4];
extern float D_01B01CE0[4];
extern float D_01B01CF0[4];
extern float D_01B01D00[4];
extern int D_01B01D10;
extern int D_01B01D1C;

extern void func_01B00CF0(W3Task *t);
extern void func_01B01AD8(W3Task *t);

extern void func_0018F170(float *v);
extern void func_001A1460(RcefObj *o);
extern void func_001A2C80(int chr_id, float *pos);
extern void func_001A2CC8(float *m);
extern void func_001A2D58(float *m);
extern void func_001A2DD8(float *v);
extern int func_001A3080(int chr_id, int a1);
extern float func_001A31D0(int chr_id);
extern float func_001A3200(float a);
extern void func_001A33F0(int chr_id, int a1);
extern void func_001A33F8(int chr_id, int a1);
extern void func_001A3870(int chr_id);
extern void func_001A3890(int chr_id, float *a1, float *a2);
extern void func_001A39F0(int chr_id);
extern void func_001A3A40(int chr_id, void *m, void *a2);
extern void func_001A3BB0(int chr_id);
extern void func_001A3DC8(int chr_id, int a1, float *m, float *rot);
extern void func_001A41D0(int chr_id, float *out);
extern void func_002B54E0(void *out, void *m, float *rot, float *pos);
extern void func_002DCE38(void *out, void *a, void *b);

void func_01B00DC0(W3Task *t);
void func_01B01118(W3Task *t);
void func_01B012E8(W3Task *t);
void func_01B016C8(W3Task *t);
void func_01B018D0(W3Task *t);
void func_01B01930(W3Task *t);

void func_01B00D00(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 281);
    func_001A1420(o, 256);
    o->pos[0] = 5.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = -90.0f;
    o->rot_w = 0;
    o->scale[0] = 0.08f;
    o->scale[1] = 0.08f;
    o->scale[2] = 0.08f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00DC0);
    func_001A1DF0(t, 6);
}

void func_01B00DC0(W3Task *t)
{
    func_001A1460((RcefObj *)t);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00E00(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 281);
    func_001A1420(o, 256);
    o->pos[0] = 2.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 90.0f;
    o->rot[2] = 10.0f;
    o->rot_w = 0;
    o->scale[0] = 0.25f;
    o->scale[1] = 0.25f;
    o->scale[2] = 0.25f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00EC8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 281);
    func_001A1420(o, 256);
    o->pos[0] = 2.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = 2.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 90.0f;
    o->rot[2] = 10.0f;
    o->rot_w = 0;
    o->scale[0] = 0.25f;
    o->scale[1] = 0.25f;
    o->scale[2] = 0.25f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00F90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 281);
    func_001A1420(o, 256);
    o->pos[0] = 2.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = -2.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 90.0f;
    o->rot[2] = 10.0f;
    o->rot_w = 0;
    o->scale[0] = 0.25f;
    o->scale[1] = 0.25f;
    o->scale[2] = 0.25f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01060(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 281);
    o->pos[0] = 5.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = -90.0f;
    o->rot_w = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B01118(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 0);
    func_001A1420(o, 32);
    o->pos[0] = 0.0f;
    o->pos[1] = -1.5f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    o->scale[3] = 0.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B00CF0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B011C8(W3Task *t)
{
    float dir[4];
    int caster = D_00313CB0.caster;
    int target = D_00313CB0.targets[0];
    int ki;
    float s;

    D_01B01D10 = 0;
    func_001A2F00(target, 0, D_01B01CE0);
    func_001A41D0(caster, dir);
    D_01B01CF0[0] = dir[0];
    D_01B01CF0[1] = -1.0f;
    D_01B01CF0[2] = dir[2];
    D_01B01CF0[3] = 0.0f;
    func_0018F170(D_01B01CF0);
    s = 1.5f;
    MIPS_MFC1(ki, s);
    VEC3_SCALE(D_01B01CF0, D_01B01CF0, ki);
    D_01B01D00[0] = -D_01B01CF0[0] / 6.0f;
    D_01B01D00[1] = -D_01B01CF0[1] / 6.0f;
    D_01B01D00[2] = -D_01B01CF0[2] / 6.0f;
    func_001A1D20(t, func_01B012E8);
}

void func_01B012E8(W3Task *t)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float rot[4];
    float c0[4];
    float c1[4];
    int caster = D_00313CB0.caster;
    Chr *chr = rcefGetChrHandle(caster);
    int target = D_00313CB0.targets[0];
    int idx = func_001A3080(target, 6);
    int ki;

    if (D_01B01D10 < 10) {
        if (D_01B01D10 >= 5) {
            VEC3_ADD(D_01B01CF0, D_01B01CF0, D_01B01D00);
            VEC3_ADD(D_01B01CE0, D_01B01CE0, D_01B01CF0);
            func_001A2D58(m2);
            rot[0] = rot[1] = rot[2] = rot[3] = 0.0f;
            rot[1] = func_001A31D0(target);
            rot[0] = (float)D_01B01D10 * 0.05f;
            func_001A2DD8(rot);
            func_002B54E0(D_01B01C50, m2, rot, D_01B01CE0);
            ki = 0x3DCCCCCD;
            VEC3_SCALE(D_01B01C50[0], D_01B01C50[0], ki);
            VEC3_SCALE(D_01B01C50[1], D_01B01C50[1], ki);
            VEC3_SCALE(D_01B01C50[2], D_01B01C50[2], ki);
            func_001A3A40(target, D_01B01C50, 0);
        }
    } else {
        if (D_01B01D10 == 10) {
            func_001A2B80(target, 73);
            func_001A33F8(target, 0);
        }
        func_001072F8(chr, 281, m0);
        func_001A2CC8(m0);
        rot[0] = rot[1] = rot[2] = rot[3] = 0.0f;
        rot[1] = func_001A3200(func_001A31D0(target) + 1.57079637f);
        func_001A3DC8(target, idx, m1, rot);
        func_002DCE38(D_01B01C50, m0, m1);
        func_001A3A40(target, D_01B01C50, D_01B01C90);
    }
    D_01B01D10++;
    if (t->frame[t->sp].count > 0) {
        c0[0] = 24.0f;
        c0[1] = 16.0f;
        c0[2] = 0.0f;
        c0[3] = 0.0f;
        c1[0] = 1.4f;
        c1[1] = 1.2f;
        c1[2] = 0.1f;
        c1[3] = 1.0f;
        if (D_01B01D1C == 0) {
            func_001A3870(target);
            func_001A3890(target, c0, c1);
        }
        func_001A33F0(target, 1);
        func_001A33F8(target, 1);
        func_001A2F00(target, 0, D_01B01CE0);
        func_001A41D0(caster, D_01B01CF0);
        D_01B01D00[0] = 0.0f;
        D_01B01D00[1] = 1.0f;
        D_01B01D00[2] = 0.0f;
        D_01B01D00[3] = 0.0f;
        {
            float s = -2.0f;
            int k2;
            MIPS_MFC1(k2, s);
            VEC3_SCALE(D_01B01CF0, D_01B01CF0, k2);
        }
        D_01B01D00[2] = -D_01B01CF0[2] / 20.0f;
        D_01B01D10 = 0;
        D_01B01CF0[1] += 2.0f;
        D_01B01CF0[2] *= 2.5f;
        func_001A2B80(target, 72);
        func_001A1D20(t, func_01B016C8);
    }
}

void func_01B016C8(W3Task *t)
{
    float m[16];
    float rot[4];
    int target = D_00313CB0.targets[0];
    int ki;

    VEC3_ADD(D_01B01CF0, D_01B01CF0, D_01B01D00);
    VEC3_ADD(D_01B01CE0, D_01B01CE0, D_01B01CF0);
    if (D_01B01CF0[1] >= 0.0f && D_01B01CE0[1] >= 0.0f) {
        /* DEBT(FAKE): match $a1/$f1/$f2 regalloc for 0.6f/0.8f scale and 0.0f */
        register int k __asm__("$5");
        register float s1 __asm__("$f1");
        float s0 = 0.6f;
        MIPS_MFC1(k, s0);
        VEC3_SCALE(D_01B01CF0, D_01B01CF0, k);
        s1 = 0.8f;
        MIPS_MFC1(k, s1);
        VEC3_SCALE(D_01B01D00, D_01B01D00, k);
        D_01B01CE0[1] = 0.0f;
        D_01B01CF0[1] = -D_01B01CF0[1];
        if (D_01B01D10 == 0) {
            func_001A3800(target, 2);
        }
        func_0019FF90(&D_00313CB0, func_01B01118);
        D_01B01D10++;
        if (D_01B01D10 >= 3) {
            D_01B01D10 = 0;
            func_001A1D08(t, func_01B018D0);
            func_001A1D50(t, func_001A2148);
            t->frame[t->sp].count = target;
        }
    }
    func_001A2D58(m);
    rot[0] = rot[1] = rot[2] = rot[3] = 0.0f;
    rot[1] = func_001A31D0(target);
    func_001A2DD8(rot);
    func_002B54E0(D_01B01C50, m, rot, D_01B01CE0);
    ki = 0x3DCCCCCD;
    VEC3_SCALE(D_01B01C50[0], D_01B01C50[0], ki);
    VEC3_SCALE(D_01B01C50[1], D_01B01C50[1], ki);
    VEC3_SCALE(D_01B01C50[2], D_01B01C50[2], ki);
    func_001A3A40(target, D_01B01C50, 0);
}

void func_01B018D0(W3Task *t)
{
    int target = D_00313E50;

    func_001A2C80(target, D_01B01C80);
    func_001A3BB0(target);
    func_001A2B80(target, 74);
    func_001A1D08(t, func_01B01930);
}

void func_01B01930(W3Task *t)
{
    float c0[4];
    float c1[4];
    float c2[4];
    float c3[4];
    int target = D_00313E50;

    if (D_01B01D1C == 0) {
        float f;
        int ki;
        c0[0] = 24.0f;
        c0[1] = 16.0f;
        c0[2] = 0.0f;
        c0[3] = 0.0f;
        c1[0] = 1.0f;
        c1[1] = 1.0f;
        c1[2] = 1.0f;
        c1[3] = 1.0f;
        c2[0] = 1.4f;
        c2[1] = 1.2f;
        c2[2] = 0.1f;
        c2[3] = 1.0f;
        f = (float)(10 - D_01B01D10) / 10.0f;
        MIPS_MFC1(ki, f);
        VEC4_SCALE(c0, c0, ki);
        VEC4_SUB(c3, c2, c1);
        VEC4_SCALE(c3, c3, ki);
        VEC4_ADD(c3, c3, c1);
        func_001A3890(target, c0, c3);
    }
    D_01B01D10++;
    if (D_01B01D10 >= 11) {
        if (D_01B01D1C == 0) {
            func_001A39F0(target);
        }
        func_001A1D08(t, func_01B01AD8);
        func_001A1D50(t, func_001A2148);
        t->frame[t->sp].count = target;
    }
}
