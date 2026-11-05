/* EE Battle-Effect Overlay: group 0x11, file 09570
 * Load base: 0x01B00000, .text: 0x01B00580..0x01B00DD8 (24 functions)
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00540[];
extern u8 D_01B00548[0x38];
extern int D_01B00DE0;
extern u8 D_01B00DF0[];
extern s32 D_00313E48;

void func_001A2C88(int a0, int a1, int a2, int a3);
void func_001A3000(int chr_id, int idx, float *out);
float rcVec3fLength(Vec4 *v);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B005C0(W3Task *t);
void func_01B00608(W3Task *t);
void func_01B00678(W3Task *t);
void func_01B006B8(W3Task *t);
void func_01B00768(W3Task *t);
void func_01B007E8(W3Task *t);
void func_01B00828(W3Task *t);
void func_01B008C0(W3Task *t);
void func_01B00930(W3Task *t);
void func_01B00960(W3Task *t);
void func_01B00970(W3Task *t);
void func_01B00A20(W3Task *t);
void func_01B00B90(W3Task *t);
void func_01B00C20(W3Task *t);

void func_01B00580(W3Task *t)
{
    D_01B00DE0 = 0;
    func_001A1D08(t, func_01B005C0);
    func_001A1D50(t, func_001A2058);
}

void func_01B005C0(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00608);
    func_001A1D50(t, func_001A2098);
}

void func_01B00608(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2C88(caster, D_00313CB0.targets[0], 2, 4);
    func_001A2B80(caster, 186);
    func_001A1D08(t, func_01B00678);
    func_001A1DF0(t, 35);
}

void func_01B00678(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00970);
    func_001A1D20(t, func_01B006B8);
}

void func_01B006B8(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_0019FF90(&D_00313CB0, func_01B00A20);
    D_01B00DE0++;
    if (D_00313CB0.target_count >= 2) {
        func_001A1D08(t, func_01B00768);
        func_001A1D50(t, func_001A2148);
        t->frame[t->sp].count = caster;
    } else {
        func_001A1D08(t, func_01B008C0);
        func_001A1D50(t, func_001A2148);
        t->frame[t->sp].count = caster;
    }
}

void func_01B00768(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2C88(caster, D_00313CB0.targets[D_01B00DE0], 4, 8);
    func_001A2B80(caster, 187);
    func_001A1D08(t, func_01B007E8);
    func_001A1DF0(t, 30);
}

void func_01B007E8(W3Task *t)
{
    func_0019FF90(&D_00313CB0, func_01B00970);
    func_001A1D20(t, func_01B00828);
}

void func_01B00828(W3Task *t)
{
    W3Task *r = func_0019FF90_t(&D_00313CB0, func_01B00A20);
    int i;

    i = D_01B00DE0;
    r->frame[r->sp].count = i;
    D_01B00DE0 = i + 1;
    if (i + 1 < D_00313CB0.target_count) {
        func_001A1D20(t, func_01B00768);
    } else {
        func_001A1D20(t, func_01B008C0);
    }
}

void func_01B008C0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 188);
    func_001A1D08(t, func_01B00930);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00930(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B00960);
}

void func_01B00960(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00970(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 49);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos[2] = -5.0f;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00960);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00A20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float p[4];
    float q[4];
    float d[4];
    int caster = D_00313CB0.caster;
    int idx;
    int tgt;
    W3Task *r;
    int ki;
    float k;

    func_001A4288(0);
    idx = t->frame[t->sp].count;
    tgt = D_00313CB0.targets[idx];
    r = func_0019FF90_t(&D_00313CB0, func_01B00B90);
    r->frame[r->sp].count = idx;
    func_001A2F00(caster, 49, p);
    func_001A3000(tgt, 6, q);
    VEC3_SUB(d, q, p);
    rcVec3fLength((Vec4 *)d);
    k = 0.125f;
    MIPS_MFC1(ki, k);
    VEC3_SCALE(d, d, ki);
    o->pos[0] = p[0];
    o->pos[1] = p[1];
    o->pos[2] = p[2];
    o->vel[0] = d[0];
    o->vel[1] = d[1];
    o->vel[2] = d[2];
    o->pos_w = 0;
    o->vel[3] = 0;
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B00960);
    func_001A1DF0(t, 8);
}

void func_01B00B90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[t->frame[t->sp].count], 6);
    func_001A1420(o, 16);
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.15f;
    func_001A1D08(t, func_01B00C20);
    func_001A1DF0(t, 8);
}

void func_01B00C20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A3800(D_00313CB0.targets[t->frame[t->sp].count], 0);
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B00960);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00CA8(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00DF0, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00540, D_01B00548);
    func_0019FF90(&D_00313CB0, func_01B00580);
    return 0;
}

int func_01B00D18(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B00D40(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00D68(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00D90(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00DB8(void) { return 0; }
int func_01B00DC0(void) { return 0; }
int func_01B00DC8(void) { return 0; }
int func_01B00DD0(void) { return 0; }
