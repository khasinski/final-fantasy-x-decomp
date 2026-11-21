/* EE Battle-Effect Overlay: group 0x11, file 09357
 * .text: 0x01B00768..0x01B01040 (18 functions, 2264B).
 */
#include "rcef_overlay.h"

extern float func_001A3620(int, float, float, float);
extern void func_001A2348(W3Task *t);
extern void func_01B00558(W3Task *t);

extern u8 D_01B00518[];
extern u8 D_01B00520[];
extern int D_01B01108;
extern int D_01B0110C;
extern int D_01B01110;
extern float D_01B01118[4];
extern float D_01B0111C;
extern float D_01B01124;
extern int D_01B01128;
extern int D_01B0112C;
extern u8 D_01B01130[];

void func_01B007B0(W3Task *t);
void func_01B00858(W3Task *t);
void func_01B00898(W3Task *t);
void func_01B008A8(RcefObj *o);
void func_01B00948(RcefObj *o);
void func_01B009C8(RcefObj *o);
void func_01B00A80(RcefObj *o);
void func_01B00B38(RcefObj *o);
void func_01B00BC8(RcefObj *o);
void func_01B00C30(RcefObj *o);
void func_01B00CE8(RcefObj *o);
void func_01B00DA0(W3Task *t);
void func_01B00DD8(W3Task *t);
void func_01B00E40(W3Task *t);
void func_01B00EA8(W3Task *t);
void func_01B00F10(RcefObj *o);

void func_01B00768(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B007B0);
    func_001A1D50(t, func_001A2098);
}

void func_01B007B0(W3Task *t)
{
    int caster = D_00313CB0.caster;
    func_001A2B80(caster, 0xB2);
    func_0019FF90(&D_00313CB0, func_01B008A8);
    func_0019FF90(&D_00313CB0, func_01B00B38);
    func_0019FF90(&D_00313CB0, func_01B00DA0);
    func_001A1D08(t, func_01B00858);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00858(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00898);
    func_001A1D50(t, func_001A2348);
}

void func_01B00898(W3Task *t)
{
    t->flags |= 4;
}

void func_01B008A8(RcefObj *o)
{
    func_001A1378(o, D_00313CB0.caster, 69);
    func_001A1420(o, 0x140);
    o->pos[0] = 0.0f;
    o->pos[1] = 0.0f;
    o->pos[2] = -5.0f;
    o->pos_w = 0;
    o->scale[0] = -0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = D_01B01124;
    o->scale[3] = 0.0f;
    func_001A1D08(&o->task, func_01B00948);
    func_001A1DF0(&o->task, 20);
}

void func_01B00948(RcefObj *o)
{
    func_001A4288(0);
    func_001A4310(1);
    /* DEBT(ORDER): volatile rot[0] preserves sw/lwc1 interleaving before kick */
    *(volatile float *)&o->rot[0] = 0.0f;
    o->rot[1] = D_01B0111C;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    D_01B01128 = 0;
    func_001A1D08(&o->task, func_01B009C8);
    func_001A1DF0(&o->task, 10);
}

void func_01B009C8(RcefObj *o)
{
    float v = func_001A3620(1, D_01B01118[1], D_01B01118[2], (float)D_01B01128 / 60.0f);
    /* DEBT(ORDER): volatile counter load orders D_01B01128++ alongside rot[0..2] */
    int c = *(volatile int *)&D_01B01128 + 1;
    o->rot[1] = v;
    o->rot[0] = 0.0f;
    o->rot[2] = 0.0f;
    /* DEBT(CAST): write rot_w as float to stay in float alias set with rot[0..2] */
    *(float *)&o->rot_w = 0.0f;
    D_01B01128 = c;
    if (c >= 60) {
        D_01B01128 = 0;
        func_001A1D08(&o->task, func_01B00A80);
        func_001A1D50(&o->task, func_001A20D8);
    }
}

void func_01B00A80(RcefObj *o)
{
    float v = func_001A3620(1, D_01B01118[2], D_01B01118[1], (float)D_01B01128 / 60.0f);
    D_01B01128++;
    o->rot[0] = 0.0f;
    o->rot[1] = v;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    if (D_01B01128 >= 60) {
        func_001A1D08(&o->task, func_01B00898);
        func_001A1D50(&o->task, func_001A20D8);
    }
}

void func_01B00B38(RcefObj *o)
{
    func_001A1378(o, D_00313CB0.caster, 69);
    func_001A1420(o, 0x140);
    o->pos[0] = 0.0f;
    o->pos[1] = 8.5f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = D_01B01124;
    o->scale[3] = 0.0f;
    func_001A1D08(&o->task, func_01B00BC8);
    func_001A1DF0(&o->task, 20);
}

void func_01B00BC8(RcefObj *o)
{
    /* DEBT(ORDER): volatile rot[0] preserves sw/lwc1 interleaving before kick */
    *(volatile float *)&o->rot[0] = 0.0f;
    o->rot[1] = D_01B0111C;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    D_01B0112C = 0;
    func_001A1D08(&o->task, func_01B00C30);
}

void func_01B00C30(RcefObj *o)
{
    float v = func_001A3620(1, D_01B01118[1], D_01B01118[2], (float)D_01B0112C / 60.0f);
    /* DEBT(ORDER): volatile counter load orders D_01B0112C++ alongside rot[0..2] */
    int c = *(volatile int *)&D_01B0112C + 1;
    o->rot[1] = v;
    o->rot[0] = 0.0f;
    o->rot[2] = 0.0f;
    /* DEBT(CAST): write rot_w as float to stay in float alias set with rot[0..2] */
    *(float *)&o->rot_w = 0.0f;
    D_01B0112C = c;
    if (c >= 60) {
        D_01B0112C = 0;
        func_001A1D08(&o->task, func_01B00CE8);
        func_001A1D50(&o->task, func_001A20D8);
    }
}

void func_01B00CE8(RcefObj *o)
{
    float v = func_001A3620(1, D_01B01118[2], D_01B01118[1], (float)D_01B0112C / 60.0f);
    D_01B0112C++;
    o->rot[0] = 0.0f;
    o->rot[1] = v;
    o->rot[2] = 0.0f;
    o->rot_w = 0;
    if (D_01B0112C >= 60) {
        func_001A1D08(&o->task, func_01B00898);
        func_001A1D50(&o->task, func_001A20D8);
    }
}

void func_01B00DA0(W3Task *t)
{
    func_001A1D08(t, func_01B00DD8);
    func_001A1DF0(t, 30);
}

void func_01B00DD8(W3Task *t)
{
    W3Task *child = func_0019FF90(&D_00313CB0, func_01B00F10);
    child->frame[child->sp].count = D_01B0110C;
    func_001A1D08(t, func_01B00E40);
    func_001A1DF0(t, 25);
}

void func_01B00E40(W3Task *t)
{
    W3Task *child = func_0019FF90(&D_00313CB0, func_01B00F10);
    child->frame[child->sp].count = D_01B01108;
    func_001A1D08(t, func_01B00EA8);
    func_001A1DF0(t, 20);
}

void func_01B00EA8(W3Task *t)
{
    W3Task *child = func_0019FF90(&D_00313CB0, func_01B00F10);
    child->frame[child->sp].count = D_01B01110;
    func_001A1D08(t, func_01B00898);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00F10(RcefObj *o)
{
    int idx = o->task.frame[o->task.sp].count;
    int tgt = D_00313CB0.targets[idx];
    func_001A13A0(o, tgt, 6);
    func_001A1420(o, 0x10);
    o->scale[0] = 0.25f;
    o->scale[1] = 0.25f;
    o->scale[2] = 0.25f;
    o->scale[3] = 0.0f;
    func_001A3800(tgt, 0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(&o->task, func_01B00898);
    func_001A1D50(&o->task, func_001A20D8);
}

int func_01B00FD0(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01130, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00518, D_01B00520);
    func_0019FF90(&D_00313CB0, func_01B00558);
    return 0;
}
