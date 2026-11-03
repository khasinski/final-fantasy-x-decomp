/* EE Battle-Effect Overlay: group 0x11, file 09572 (group_index 528)
 * Load base: 0x01B00000, .text: 0x01B00580..0x01B00CB8
 *
 * Effect scene: a shielding aura blinks on the target while its mesh alpha
 * pulses, then sparks burst upward and the target flashes twice.
 */
#include "../rcef_overlay.h"

extern void *D_01B00540[];
extern u8 D_01B00548[0x38];
extern u8 D_01B00CC8[];
extern u8 D_01B00CD0[8];
extern int D_01B00CC0; /* blink tick counter */

void func_01B00608(W3Task *t);
void func_01B00650(W3Task *t);
void func_01B00698(W3Task *t);
void func_01B00838(W3Task *t);
void func_01B00848(W3Task *t);
void func_01B00858(W3Task *t);
void func_01B00A20(W3Task *o);
void func_01B00AE8(W3Task *t);
void func_01B00B58(W3Task *t);
void func_01B00580(W3Task *t)
{
    Chr *chr = rcefGetChrHandle(D_00313CB0.caster);

    func_00110C30(chr, 1, 1.0f);
    graphicCharacterInstanceSetMeshSegmentAlpha((int)chr, 1, 0);
    D_01B00CC0 = 0;
    func_001A1D08(t, func_01B00608);
    func_001A1D50(t, func_001A2058);
}

void func_01B00608(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00650);
    func_001A1D50(t, func_001A2098);
}

void func_01B00650(W3Task *t)
{
    func_001A4288(0);
    func_0019FF90(&D_00313CB0, func_01B00AE8);
    func_001A1D20(t, func_01B00698);
}

void func_01B00698(W3Task *t)
{
    Chr *chr = rcefGetChrHandle(D_00313CB0.caster);
    RcefObj *o = (RcefObj *)t;

    if (D_01B00CC0 < 20) {
        if ((D_01B00CC0 & 7) == 0) {
            func_0019FF90(&D_00313CB0, func_01B00858);
        }
    } else if (D_01B00CC0 < 70) {
        if (D_01B00CC0 % 5 == 0) {
            func_0019FF90(&D_00313CB0, func_01B00858);
        }
    } else if (D_01B00CC0 % 3 == 0) {
        func_0019FF90(&D_00313CB0, func_01B00858);
    }
    if (D_01B00CC0 >= 100) {
        if (D_01B00CC0 == 100) {
            func_0019FF90(&D_00313CB0, func_01B00A20);
        }
        if (D_01B00CC0 < 120) {
            float v = (float)(D_01B00CC0 - 100) / 20.0f;

            func_00110C30(chr, 1, 1.0f - v);
        } else {
            graphicCharacterInstanceSetMeshSegmentAlpha((int)chr, 1, 1);
            func_001A1D08(t, func_01B00838);
            func_001A1D50(t, func_001A21E0);
        }
    }
    D_01B00CC0 = D_01B00CC0 + 1;
}

void func_01B00838(W3Task *t)
{
    func_001A1D08(t, func_01B00848);
}

void func_01B00848(W3Task *t)
{
    t->flags |= 4;
}
/* rising spark with a random jitter, spawned at the target */
void func_01B00858(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float dir[3];
    float pos[3];
    float vel[3];
    float k = 4.656612873077393e-10f;
    float one = 1.0f;
    float h;
    int caster = D_00313CB0.caster;

    dir[0] = (float)func_002EFD78() * k * 2.0f - one;
    dir[1] = (float)func_002EFD78() * k * 2.0f - one;
    dir[2] = (float)func_002EFD78() * k * 2.0f - one;
    func_002DCEC8((s32)dir, (s32)dir);
    h = (float)func_002EFD78() * k * 20.0f + 10.0f;
    func_002DD998(pos, dir, h);
    func_002DD998(vel, dir, 0.1f);
    o->flagsBC |= 0x2000;
    func_001A1378(o, caster, 235);
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    o->pos_w = 0;
    o->vel[0] = vel[0];
    o->vel[1] = vel[1];
    o->vel[2] = vel[2];
    o->vel_w = 0;
    o->rot[0] = 90.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.75f;
    o->scale[1] = 0.75f;
    o->scale[2] = 0.75f;
    o->scale_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00848);
    func_001A1D50(t, func_001A20D8);
}

/* target flash: bind to the caster's chr, tint, kick a spark */
void func_01B00A20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    o->flagsBC |= 0x10;
    func_001A1378(o, caster, 235);
    o->pos[0] = 0;
    o->pos[1] = 15.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->rot[0] = -30.0f;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[0] = 0.65f;
    o->scale[1] = 0.65f;
    o->scale[2] = 0.65f;
    o->scale_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(&o->task, func_01B00848);
    func_001A1D50(&o->task, func_001A20D8);
}

/* second flash on the same target (bigger, tinted red) */
void func_01B00AE8(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 194);
    func_001A1D08(t, func_01B00B58);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00B58(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A2B68();
    o->task.flags |= 4;
}

int func_01B00B88(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00CD0, 0x01E40000, 0x000C0000, 0x01D40000, 1, D_01B00540, D_01B00548);
    func_0019FF90(&D_00313CB0, func_01B00580);
    return 0;
}

int func_01B00BF8(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00C20(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00C48(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00C70(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00C98(void)
{
    return 0;
}

int func_01B00CA0(void)
{
    return 0;
}

int func_01B00CA8(void)
{
    return 0;
}

int func_01B00CB0(void)
{
    return 0;
}
