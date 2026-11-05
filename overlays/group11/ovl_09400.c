/* EE Battle-Effect Overlay: group 0x11, file 09400
 * Load base: 0x01B00000, .text: 0x01B00418..0x01B00D60 (24 functions)
 *
 * Wave of motes sweeping between the caster and the first target, followed by
 * damage-motion cues on the target.
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B003D8[];
extern u8 D_01B003E0[0x38];
extern int D_01B00D68;
extern u8 D_01B00D70[];
extern s32 D_00313E48;

float func_001A30E0_f(int chr_id) __asm__("func_001A30E0");
float func_001A3140_f(int chr_id) __asm__("func_001A3140");
void func_001A0040_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0040");
void func_001A0000_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0000");

void func_01B00458(W3Task *t);
void func_01B004A0(W3Task *t);
void func_01B00510(W3Task *t);
void func_01B00570(W3Task *t);
void func_01B00600(W3Task *t);
void func_01B00670(W3Task *t);
void func_01B006A0(W3Task *t);
void func_01B006B0(W3Task *t);
void func_01B00928(W3Task *t);
void func_01B00968(W3Task *t);
void func_01B00B18(W3Task *t);
void func_01B00B50(W3Task *t);
void func_01B00BA0(W3Task *t);
void func_01B00BF0(W3Task *t);

void func_01B00418(W3Task *t)
{
    D_01B00D68 = 0;
    func_001A1D08(t, func_01B00458);
    func_001A1D50(t, func_001A2058);
}

void func_01B00458(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B004A0);
    func_001A1D50(t, func_001A2098);
}

void func_01B004A0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 178);
    func_001A1D08(t, func_01B00510);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00510(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 179);
    func_0019FF90(&D_00313CB0, func_01B00B18);
    func_001A4288(0);
    func_001A1D20(t, func_01B00570);
}

void func_01B00570(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B006B0);
    func_0019FF90(&D_00313CB0, func_01B006B0);
    if (++D_01B00D68 >= 60) {
        func_001A1D08(t, func_01B00600);
    }
}

void func_01B00600(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 180);
    func_001A1D08(t, func_01B00670);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00670(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B006A0);
}

void func_01B006A0(W3Task *t)
{
    t->flags |= 4;
}

void func_01B006B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float m1[16];
    float m2[16];
    float va[4];
    float vb[4];
    float d[4];
    int caster = D_00313CB0.caster;
    int tgt = D_00313CB0.targets[0];
    float a, b, lc, lt, hc, ht, x;
    float k;
    int ki;
    register u32 fl __asm__("$3"); /* DEBT(FAKE): original register assignment */

    a = (float)func_002EFD78() * 4.656612873077393e-10f;
    b = (float)func_002EFD78() * 4.656612873077393e-10f;
    func_001A2E80(caster, 0, m1);
    func_001A2E80(tgt, 0, m2);
    lc = func_001A30E0_f(caster);
    lt = func_001A30E0_f(tgt);
    hc = func_001A3140_f(caster);
    ht = func_001A3140_f(tgt);
    va[3] = 1.0f;
    vb[3] = 1.0f;
    vb[2] = -ht;
    vb[0] = (a * ht + a * ht) - ht;
    va[0] = (a * hc + a * hc) - hc;
    va[1] = -b * lc;
    x = -hc;
    va[2] = x + x;
    vb[1] = -b * lt;
    func_002DCE08(va, m1, va);
    func_002DCE08(vb, m2, vb);
    VEC3_SUB(d, vb, va);
    k = 0.06666667f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(d, d, ki);
    fl = o->flagsBC | 0x2000;
    o->flagsBC = fl;
    o->pos[0] = va[0];
    o->pos[1] = va[1];
    o->pos[2] = va[2];
    o->vel[0] = d[0];
    o->vel[1] = d[1];
    o->vel[2] = d[2];
    o->pos_w = 0;
    o->vel[3] = 0;
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.01f;
    func_001A0040_k(&D_00313CB0, o, 1);
    *((u8 *)o + 984) = 66;
    if (func_002EFD78() % 6 < 3) {
        func_001A1D08(t, func_01B00928);
        func_001A1DF0(t, 15);
    } else {
        func_001A1D08(t, func_01B006A0);
        func_001A1DF0(t, 30);
    }
}

void func_01B00928(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00968);
    t->flags |= 4;
}

void func_01B00968(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float m[16];
    float w[4];
    int tgt = D_00313CB0.targets[0];
    float l, h, x, y, ang, z;

    func_001A2E80(tgt, 0, m);
    l = func_001A30E0_f(tgt);
    h = func_001A3140_f(tgt);
    x = (float)func_002EFD78() * 4.656612873077393e-10f;
    x = x * h;
    x = x + x;
    w[0] = x - h;
    y = (float)func_002EFD78() * 4.656612873077393e-10f;
    w[3] = 1.0f;
    w[2] = -h * 0.5f;
    w[1] = y * -l;
    func_002DCE08(w, m, w);
    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    z = (float)func_002EFD78() * 4.656612873077393e-10f * 0.05f + 0.05f;
    o->rot[2] = ang;
    o->flagsBC |= 0x4000;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->pos[0] = w[0];
    o->pos[1] = w[1];
    o->pos[2] = w[2];
    o->scale[2] = o->scale[1] = o->scale[0] = z;
    func_001A0000_k(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B006A0);
    func_001A1D50(t, func_001A2110);
}

void func_01B00B18(W3Task *t)
{
    func_001A1D08(t, func_01B00B50);
    func_001A1DF0(t, 15);
}

void func_01B00B50(W3Task *t)
{
    MsDamageSetMotion(D_00313E50, 5, 1);
    func_001A1D08(t, func_01B00BA0);
    func_001A1DF0(t, 20);
}

void func_01B00BA0(W3Task *t)
{
    MsDamageSetMotion(D_00313E50, 5, 1);
    func_001A1D08(t, func_01B00BF0);
    func_001A1DF0(t, 20);
}

void func_01B00BF0(W3Task *t)
{
    func_001A3800(D_00313E50, 0);
    t->flags |= 4;
}

int func_01B00C30(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00D70, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B003D8, D_01B003E0);
    func_0019FF90(&D_00313CB0, func_01B00418);
    return 0;
}

int func_01B00CA0(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00CC8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00CF0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00D18(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00D40(void) { return 0; }
int func_01B00D48(void) { return 0; }
int func_01B00D50(void) { return 0; }
int func_01B00D58(void) { return 0; }
