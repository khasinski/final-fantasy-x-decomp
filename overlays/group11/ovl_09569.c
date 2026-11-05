/* EE Battle-Effect Overlay: group 0x11, file 09569 (group_index 542)
 * Load base: 0x01B00000, .text: 0x01B00580..0x01B00EB8
 *
 * Effect scene: caster/charge sequence — bind motes on the caster and target,
 * per-target motion cues (72..74, 176..180, 35/36) and a ring flash finish.
 */
#include "../rcef_overlay.h"

extern void MsSetMove(int chr_id, float f12, float f13, float f14, float f15, float f16, int a2, int a3, int t0, int t1);
extern void func_001A2B78(int chr_id, int a1, float f12, float f13, float f14, float f15, float f16, int a2, int a3, int t0, int t1);
extern void func_001A2B88(int chr_id);
extern int func_001BB930(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3);
extern int func_001B6620_i(int id) __asm__("func_001B6620"); /* DEBT(TYPE): original returns an unextended int; funcs.h says u8 */
extern void *D_01B00540[];
extern u8 D_01B00548[0x38];
extern u8 D_01B00ED0[8];
extern int D_01B00EC0; /* current bind target pointer */
extern s32 D_00313CB4; /* eff_id */
extern s32 D_00313E50; /* targets[0] */

void func_01B005F0(W3Task *t);
void func_01B00638(W3Task *t);
void func_01B006C8(W3Task *t);
void func_01B00708(W3Task *t);
void func_01B00740(W3Task *t);
void func_01B007E8(W3Task *t);
void func_01B00820(W3Task *t);
void func_01B00858(W3Task *t);
void func_01B00868(W3Task *t);
void func_01B00878(W3Task *t);
void func_01B00948(W3Task *t);
void func_01B009B8(W3Task *t);
void func_01B00A00(W3Task *t);
void func_01B00A70(W3Task *t);
void func_01B00AE0(W3Task *t);
void func_01B00B50(W3Task *t);
void func_01B00B80(W3Task *t);
void func_01B00BF0(W3Task *t);
void func_01B00C38(W3Task *t);
void func_01B00CC8(W3Task *t);
void func_01B00D50(W3Task *t);
int func_01B00D88(int eff_id);

void func_01B00580(W3Task *t)
{
    D_01B00EC0 = func_001BB930(D_00313CB0.eff_id, D_00313CB0.targets[0], 0, 0, 0, 0, 0, 0);
    func_001A1D08(t, func_01B005F0);
    func_001A1D50(t, func_001A2058);
}

void func_01B005F0(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00638);
    func_001A1D50(t, func_001A2098);
}

void func_01B00638(W3Task *t)
{
    W3Task *task = t;

    func_001A2B78(D_00313CB0.caster, 11, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0, 84, 32, 32);
    func_0019FF90(&D_00313CB0, func_01B00948);
    func_001A1D08(task, func_01B006C8);
    func_001A1DF0(task, 13);
}

void func_01B006C8(W3Task *t)
{
    func_001A4288(0);
    func_001A1D08(t, func_01B00708);
    func_001A1DF0(t, 70);
}

void func_01B00708(W3Task *t)
{
    func_001A1D08(t, func_01B00740);
    func_001A1DF0(t, 10);
}

/* caster motion 1 + bind check + charge kick */
void func_01B00740(W3Task *t)
{
    W3Task *task = t;

    func_001A2B78(D_00313CB0.caster, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 104, 32, 32);
    func_0019FF90(&D_00313CB0, func_01B00878);
    if (D_01B00EC0 == 0) {
        func_0019FF90(&D_00313CB0, func_01B00B80);
    }
    func_001A1D08(task, func_01B00820);
    func_001A1DF0(task, 13);
}

void func_01B007E8(W3Task *t)
{
    func_001A1D08(t, func_01B00820);
    func_001A1DF0(t, 13);
}

void func_01B00820(W3Task *t)
{
    func_001A1D08(t, func_01B00858);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00858(W3Task *t)
{
    func_001A1D08(t, func_01B00868);
}

void func_01B00868(W3Task *t)
{
    t->flags |= 4;
}

/* bind mote on the target */
void func_01B00878(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int chr = D_00313CB0.targets[0];

    if (D_01B00EC0 != 0) {
        func_001A3800(chr, 0);
    } else {
        func_001A3800(chr, 2);
    }
    func_001A13A0(o, chr, 0);
    func_001A1420(o, 16);
    o->scale[0] = 0.05f;
    o->scale[1] = 0.05f;
    o->scale[2] = 0.05f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00868);
    func_001A1D50(t, func_001A20D8);
}

/* caster motion 176 + frame save */
void func_01B00948(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 176);
    func_001A1D08(t, func_01B009B8);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 177 */
void func_01B009B8(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 177);
    func_001A1D08(t, func_01B00A00);
    func_001A1DF0(t, 38);
}

/* caster motion 178 + frame save */
void func_01B00A00(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 178);
    func_001A1D08(t, func_01B00A70);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 179 + frame save */
void func_01B00A70(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 179);
    func_001A1D08(t, func_01B00AE0);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 180 + frame save */
void func_01B00AE0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 180);
    func_001A1D08(t, func_01B00B50);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00B50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A2B68();
    o->task.flags |= 4;
}

/* target motion 72 + frame save */
void func_01B00B80(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int target = D_00313CB0.targets[0];

    func_001A2B80(target, 72);
    func_001A1D08(t, func_01B00BF0);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = target;
}

/* target motion 73 */
void func_01B00BF0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int target = D_00313CB0.targets[0];

    func_001A2B80(target, 73);
    func_001A1D08(t, func_01B00C38);
    func_001A1DF0(t, 15);
}

/* target motion 74 + branch on motion state */
void func_01B00C38(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int target = D_00313CB0.targets[0];
    func_001A2B80(target, 74);
    if (func_001B6620_i(target) < 2) {
        func_001A1D08(t, func_01B00CC8);
        func_001A1D50(t, func_001A2148);
        o->task.frame[o->task.sp].count = target;
    } else {
        func_001A1D08(t, func_01B00D50);
        func_001A1D50(t, func_001A2148);
        o->task.frame[o->task.sp].count = target;
    }
}

/* target motion 35/36 branch + frame save */
void func_01B00CC8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int target = D_00313CB0.targets[0];

    if (func_001B6620_i(target) <= 0) {
        func_001A2B80(target, 35);
    } else {
        func_001A2B80(target, 36);
    }
    func_001A1D08(t, func_01B00D50);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = target;
}

/* end target motion + clear flag */
void func_01B00D50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A2B88(D_00313CB0.targets[0]);
    o->task.flags |= 4;
}

int func_01B00D88(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00ED0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00540, D_01B00548);
    func_0019FF90(&D_00313CB0, func_01B00580);
    return 0;
}

int func_01B00DF8(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00E20(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00E48(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00E70(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00E98(void)
{
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