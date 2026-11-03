/* EE Battle-Effect Overlay: group 0x11, file 09403 (group_index 517)
 * Load base: 0x01B00000, .text: 0x01B00530..0x01B00F28
 *
 * Effect scene: caster charge-up — motion 178..181 sequence, radial ring
 * sparks on the caster (optpos 27/43), a bind mote on the caster and an
 * 8-step finish counter.
 */
#include "../rcef_overlay.h"

extern void func_001A2B78(int chr_id, int a1, float f12, float f13, float f14, float f15, float f16, int a2, int a3, int t0, int t1);
extern void *D_01B004F0[];
extern u8 D_01B004F8[8];
extern u8 D_01B00F40[8];
extern int D_01B00F30; /* remaining ring steps */
extern int D_01B00F34; /* ring step total */

void func_001A3818(int a0, int a1, int a2, int a3, float f12);
void func_001A3848(int a0, int a1, int a2);

void func_01B00580(W3Task *t);
void func_01B005C8(W3Task *t);
void func_01B00670(W3Task *t);
void func_01B006E8(W3Task *t);
void func_01B007B0(W3Task *t);
void func_01B00860(W3Task *t);
void func_01B00900(W3Task *t);
void func_01B00940(W3Task *t);
void func_01B00950(W3Task *t);
void func_01B009F0(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00AD0(W3Task *t);
void func_01B00C10(W3Task *t);
void func_01B00D50(W3Task *t);

void func_01B00530(W3Task *t)
{
    D_01B00F30 = D_01B00F34 = 8;
    func_001A1D08(t, func_01B00580);
    func_001A1D50(t, func_001A2058);
}

void func_01B00580(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B005C8);
    func_001A1D50(t, func_001A2098);
}

void func_01B005C8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A4288(0);
    func_001A2B78(caster, 2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 32, 32, 32);
    func_001A2B80(caster, 178);
    func_0019FF90(&D_00313CB0, func_01B00A70);
    func_001A1D08(t, func_01B00670);
    func_001A1DF0(t, 4);
}

/* charge-up setup: camera helpers, target cue, motion task */
void func_01B00670(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;
    W3Task *task = t;

    func_0019FF90(&D_00313CB0, func_01B009F0);
    func_001A1D08(t, func_01B006E8);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 179 + screen helpers */
void func_01B006E8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;
    W3Task *task = t;

    func_001A2B80(caster, 179);
    func_0019FF90(&D_00313CB0, func_01B00950);
    func_001A3818(4, 30, 10, 4, 3.1415927f);
    func_001A3848(2, 64, 30);
    func_001A3800(-5, 0);
    func_001A1D08(task, func_01B007B0);
    func_001A1D50(task, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 180 + ring enable */
void func_01B007B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B78(caster, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 24, 32, 32);
    func_001A2B80(caster, 180);
    D_01B00F34 = 1;
    D_01B00F30 = 1;
    func_001A1D08(t, func_01B00860);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 181 + ring step 3 */
void func_01B00860(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 181);
    D_01B00F30 = D_01B00F34 = 3;
    func_0019FF90(&D_00313CB0, func_01B00A70);
    func_001A1D08(t, func_01B00900);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00900(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00940);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00940(W3Task *t)
{
    t->flags |= 4;
}

/* ring spark on the caster */
void func_01B00950(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A4288(1);
    func_001A13A0(o, D_00313CB0.caster, 0);
    func_001A1420(o, 64);
    o->scale[0] = 0.9f;
    o->scale[1] = 0.9f;
    o->scale[2] = 0.9f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00940);
    func_001A1D50(t, func_001A20D8);
}

/* ring step tick: kick spark batches while steps remain */
void func_01B009F0(W3Task *t)
{
    if (D_01B00F30 <= 0) {
        func_001A1D08(t, func_01B00940);
        return;
    }
    func_0019FF90(&D_00313CB0, func_01B00AD0);
    func_0019FF90(&D_00313CB0, func_01B00C10);
    D_01B00F30 = D_01B00F30 - 1;
}

void func_01B00A70(W3Task *t)
{
    if (D_01B00F30 <= 0) {
        func_001A1D08(t, func_01B00940);
        return;
    }
    func_0019FF90(&D_00313CB0, func_01B00D50);
    D_01B00F30 = D_01B00F30 - 1;
}

/* radial ring spark, optpos 27 */
void func_01B00AD0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float ang;
    float frac;

    frac = (float)(D_01B00F30 + 1) / (float)D_01B00F34;
    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    func_001A1378(o, D_00313CB0.caster, 27);
    func_001A1420(o, 64);
    o->flagsBC |= 0x4000;
    o->rot[2] = ang;
    o->unk170[0] = 0.8f;
    o->unk170[1] = 0.75f;
    o->unk170[2] = 0.7f;
    o->unk170[3] = frac;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->scale[0] = 0.55f;
    o->scale[1] = 0.55f;
    o->scale[2] = 0.55f;
    func_001A0000(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00940);
    func_001A1DF0(t, 32);
}

/* radial ring spark, optpos 43 */
void func_01B00C10(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float ang;
    float frac;

    frac = (float)(D_01B00F30 + 1) / (float)D_01B00F34;
    ang = (float)func_002EFD78() * 4.656612873077393e-10f * 360.0f;
    func_001A1378(o, D_00313CB0.caster, 43);
    func_001A1420(o, 64);
    o->flagsBC |= 0x4000;
    o->rot[2] = ang;
    o->unk170[0] = 0.8f;
    o->unk170[1] = 0.75f;
    o->unk170[2] = 0.7f;
    o->unk170[3] = frac;
    o->rot[0] = 0;
    o->rot[1] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->scale[0] = 0.55f;
    o->scale[1] = 0.55f;
    o->scale[2] = 0.55f;
    func_001A0000(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00940);
    func_001A1DF0(t, 32);
}

/* bind mote on the caster */
void func_01B00D50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A13A0(o, caster, 0);
    func_001A1420(o, 64);
    o->pos[0] = 0;
    o->pos[1] = -1.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.5f;
    o->scale[1] = 0.5f;
    o->scale[2] = 0.5f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00940);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00DF8(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00F40, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B004F0, D_01B004F8);
    func_0019FF90(&D_00313CB0, func_01B00530);
    return 0;
}

int func_01B00E68(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00E90(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00EB8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00EE0(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00F08(void)
{
    return 0;
}

int func_01B00F10(void)
{
    return 0;
}

int func_01B00F18(void)
{
    return 0;
}

int func_01B00F20(void)
{
    return 0;
}