/* EE Battle-Effect Overlay: group 0x11, file 09238
 * Load base: 0x01B00000, .text: 0x01B00490..0x01B00C70 (23 functions)
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00450[];
extern u8 D_01B00458[0x38];
extern void *D_01B00C78;
extern int D_01B00C7C;
extern u8 D_01B00C80[];
extern s32 D_00313E48;

void func_001A3000(int chr_id, int idx, float *out);
void func_001A2530(void *obj, int a1, int a2, int a3);
void func_001A2608(void *obj);

void func_01B004D8(W3Task *t);
void func_01B00520(W3Task *t);
void func_01B00568(W3Task *t);
void func_01B005E0(W3Task *t);
void func_01B00630(W3Task *t);
void func_01B006A0(W3Task *t);
void func_01B006E0(W3Task *t);
void func_01B006F0(W3Task *t);
void func_01B007B0(W3Task *t);
void func_01B009C8(W3Task *t);
void func_01B00AB8(W3Task *t);

void func_01B00490(W3Task *t)
{
    D_01B00C78 = 0;
    D_01B00C7C = 0;
    func_001A1D08(t, func_01B004D8);
    func_001A1D50(t, func_001A2058);
}

void func_01B004D8(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00520);
    func_001A1D50(t, func_001A2098);
}

void func_01B00520(W3Task *t)
{
    func_001A2B80(D_00313E48, 98);
    func_001A1D08(t, func_01B00568);
    func_001A1DF0(t, 43);
}

void func_01B00568(W3Task *t)
{
    func_001A4288(0);
    func_001A4288(1);
    func_0019FF90(&D_00313CB0, func_01B006F0);
    func_0019FF90(&D_00313CB0, func_01B007B0);
    func_001A1D08(t, func_01B005E0);
    func_001A1DF0(t, 10);
}

void func_01B005E0(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B009C8);
    func_001A1D08(t, func_01B00630);
    func_001A1DF0(t, 2);
}

void func_01B00630(W3Task *t)
{
    func_001A3800(D_00313CB0.targets[0], 0);
    func_001A1D08(t, func_01B006A0);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = D_00313CB0.caster;
}

void func_01B006A0(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B006E0);
    func_001A1D50(t, func_001A21E0);
}

void func_01B006E0(W3Task *t)
{
    t->flags |= 4;
}

void func_01B006F0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 140);
    o->pos[0] = -1.9f;
    o->pos[1] = 0;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot[2] = 90.0f;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B006E0);
    func_001A1D50(t, func_001A20D8);
}

#define VEC3_SUB(d, a, b) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tlqc2 $vf30, 0(%2)\n\tvsub.xyz $vf31, $vf31, $vf30\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(b) : "memory")
#define VEC3_SCALE(d, a, ki) \
    __asm__ volatile("lqc2 $vf31, 0(%1)\n\tqmtc2.ni %2, $vf30\n\tvmulx.xyz $vf31, $vf31, $vf30x\n\tsqc2 $vf31, 0(%0)" \
                     : : "r"(d), "r"(a), "r"(ki) : "memory")

void func_01B007B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float q[4];
    float e[4];
    float d[4];
    float m[4];
    register float *mp __asm__("$3"); /* DEBT(FAKE) */
    float k;
    register int ki __asm__("$2"); /* DEBT(FAKE): original register choice */

    o->flagsBC |= 0x2000;
    func_001A2F00(D_00313CB0.caster, 140, p);
    func_001A3000(D_00313CB0.targets[0], 6, q);
    VEC3_SUB(d, q, p);
    rcVec3fNormalize((Vec4 *)d);
    k = 14.0f;
    mp = m;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(mp, d, ki);
    VEC3_SUB(p, p, mp);
    k = 18.0f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(mp, d, ki);
    VEC3_SUB(q, q, mp);
    VEC3_SUB(e, q, p);
    k = 0.1f;
    {
        register int kj __asm__("$3"); /* DEBT(FAKE) */
        MIPS_MFC1(kj, k);
        VEC3_SCALE(e, e, kj);
    }
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->vel[0] = e[0];
    o->vel[1] = e[1];
    o->vel[2] = e[2];
    o->pos_w = 0;
    o->vel[3] = 0;
    o->rot[0] = 90.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.05f;
    o->scale[1] = 0.4f;
    o->scale[2] = 0.05f;
    o->scale[3] = 0;
    o->unk140[0] = -0.00049f;
    o->unk140[1] = 0.01f;
    o->unk140[2] = -0.0049f;
    o->unk14C_w = 0;
    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.09f;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B006E0);
    func_001A1DF0(t, 10);
}

void func_01B009C8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A4288(2);
    func_001A13A0(o, D_00313CB0.targets[0], 6);
    func_001A1420(o, 16);
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B006E0);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00A68(W3Task *t)
{
    D_01B00C78 = func_001A2388();
    func_001A2530(D_01B00C78, D_00313E50, 1, 1);
    func_001A1D08(t, func_01B00AB8);
}

void func_01B00AB8(W3Task *t)
{
    func_001A2608(D_01B00C78);
    if (++D_01B00C7C >= 60) {
        func_001A23C8(D_01B00C78);
        func_001A1D08(t, func_01B006E0);
    }
}

void func_01B00B30(W3Task *t)
{
    t->flags |= 4;
}

int func_01B00B40(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00C80, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00450, D_01B00458);
    func_0019FF90(&D_00313CB0, func_01B00490);
    return 0;
}

int func_01B00BB0(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00BD8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00C00(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00C28(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00C50(void)
{
    return 0;
}

int func_01B00C58(void)
{
    return 0;
}

int func_01B00C60(void)
{
    return 0;
}

int func_01B00C68(void)
{
    return 0;
}
