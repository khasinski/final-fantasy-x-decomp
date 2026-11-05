/* EE Battle-Effect Overlay: group 0x11, file 09566 (group_index 522)
 * Load base: 0x01B00000, .text: 0x01B005D0..0x01B00EC0
 *
 * Effect scene: rise-up charge — bind to caster, charge aura pulses in a
 * 5-pulse loop, targets get marked, then a radial burst of ring sparks.
 */
#include "../rcef_overlay.h"

extern void *D_01B00590[];
extern u8 D_01B00598[8];
extern int D_01B00EC8; /* charge pulse counter */
extern u8 D_01B00ED0[8];

void func_01B00610(W3Task *t);
void func_01B00658(W3Task *t);
void func_01B006B0(W3Task *t);
void func_01B00700(W3Task *t);
void func_01B007B8(W3Task *t);
void func_01B00808(W3Task *t);
void func_01B00858(W3Task *t);
void func_01B00888(W3Task *t);
void func_01B00898(W3Task *t);
void func_01B00948(W3Task *t);
void func_01B009D8(W3Task *t);
void func_01B00A90(W3Task *t);
void func_01B00CD8(W3Task *t);
void func_01B00D48(W3Task *t);

void func_01B005D0(W3Task *t)
{
    D_01B00EC8 = 0;
    func_001A1D08(t, func_01B00610);
    func_001A1D50(t, func_001A2058);
}

void func_01B00610(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00658);
    func_001A1D50(t, func_001A2098);
}

void func_01B00658(W3Task *t)
{
    func_001A4288(0);
    func_0019FF90(&D_00313CB0, func_01B00CD8);
    func_001A1D08(t, func_01B006B0);
    func_001A1DF0(t, 84);
}

void func_01B006B0(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00898);
    func_001A1D08(t, func_01B00700);
    func_001A1DF0(t, 2);
}

void func_01B00700(W3Task *t)
{
    register W3Task *tt __asm__("$19") = t; /* DEBT(FAKE): original register assignment */
    int i;

    i = 5;
    do {
        func_0019FF90(&D_00313CB0, func_01B00A90);
    } while (--i >= 0);
    D_01B00EC8 = D_01B00EC8 + 1;
    if (D_01B00EC8 >= 10) {
        func_001A1D08(tt, func_01B007B8);
        func_001A1DF0(tt, 10);
    }
}

void func_01B007B8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00948);
    func_001A1D08(t, func_01B00808);
    func_001A1DF0(t, 8);
}

void func_01B00808(W3Task *t)
{
    MsSetChrVisible(D_00313CB0.caster, 0);
    func_001A1D08(t, func_01B00858);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00858(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00888);
}

void func_01B00888(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00898(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A13A0(o, caster, 0);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = -12.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00888);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00948(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A13A0(o, caster, 0);
    func_001A1420(o, 16);
    o->scale[0] = 0.8f;
    o->scale[1] = 0.8f;
    o->scale[2] = 0.8f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B009D8);
    func_001A1DF0(t, 10);
}

void func_01B009D8(W3Task *t)
{
    int i;

    for (i = 0; i < D_00313CB0.target_count; i++) {
        func_001A3800(D_00313CB0.targets[i], 0);
    }
    func_001A1D08(t, func_01B00888);
    func_001A1D50(t, func_001A20D8);
}

/* radial ring-spark spawner */
void func_01B00A90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float k = 4.656612873077393e-10f;
    float dir[3];
    float vel[3];
    float ang;
    float rad;
    float b;
    float c;
    int caster = D_00313CB0.caster;
    int idx;

    ang = (float)func_002EFD78() * k * 360.0f;
    rad = (float)func_002EFD78() * k * 0.06f + 0.02f;
    idx = ((int)func_002EFD78() & 1) != 0 ? 15 : 26;
    func_001A2F00(caster, idx, dir);
    dir[1] = dir[1] + (float)func_002EFD78() * k * 5.0f;
    b = (float)func_002EFD78() * k * 6.2831853f;
    c = (float)func_002EFD78() * k * 0.6f;
    vel[0] = func_002E8648(b) * c;
    vel[1] = (float)func_002EFD78() * k * 0.2f;
    vel[2] = func_002E89C0(b) * c;
    o->flagsBC |= 0x4000;
    o->rot[2] = ang;
    o->scale[0] = rad;
    o->scale[1] = rad;
    o->scale[2] = rad;
    o->unk140[0] = 0.02f;
    o->unk140[1] = 0.02f;
    o->unk140[2] = 0.02f;
    o->pos[0] = dir[0];
    o->pos[1] = dir[1];
    o->pos[2] = dir[2];
    o->pos_w = 0;
    o->vel[0] = vel[0];
    o->vel[1] = vel[1];
    o->vel[2] = vel[2];
    o->vel[3] = 0;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->unk14C_w = 0;
    o->unk180[0] = 0;
    o->unk180[1] = 0;
    o->unk180[2] = 0;
    o->unk18C = -0.045f;
    func_001A0000(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00888);
    func_001A1DF0(t, 20);
}

void func_01B00CD8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 178);
    func_001A1D08(t, func_01B00D48);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00D48(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 179);
    func_001A1D08(t, func_01B00888);
    func_001A1DF0(t, 10);
}

int func_01B00D90(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00ED0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00590, D_01B00598);
    func_0019FF90(&D_00313CB0, func_01B005D0);
    return 0;
}

int func_01B00E00(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00E28(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00E50(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00E78(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00EA0(void)
{
    return 0;
}

int func_01B00EA8(void)
{
    return 0;
}

int func_01B00EB0(void)
{
    return 0;
}

int func_01B00EB8(void)
{
    return 0;
}