/* EE Battle-Effect Overlay: group 0x11, file 09357
 * Load base: 0x01B00000, .text: 0x01B00558..0x01B01100 (26 functions)
 */
#include "../rcef_overlay.h"
#include "vu0.h"

extern void *D_01B00518[];
extern u8 D_01B00520[];
extern int D_01B01108[3];
extern float D_01B01118[3];
extern float D_01B01124;
extern int D_01B01128;
extern int D_01B0112C;
extern u8 D_01B01130[];
extern s32 D_00313E48;

float rcVec3fLength(Vec4 *v);
void rcVec3fNormalize(Vec4 *v);
float func_002E93A0(float a);
void func_001A3000(int chr_id, int idx, float *out);
float func_001A3620(int mode, float a, float b, float t);
void func_001A2348(W3Task *t);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B00558(W3Task *t);
void func_01B00768(W3Task *t);
void func_01B007B0(W3Task *t);
void func_01B00858(W3Task *t);
void func_01B00898(W3Task *t);
void func_01B008A8(W3Task *t);
void func_01B00948(W3Task *t);
void func_01B009C8(W3Task *t);
void func_01B00A80(W3Task *t);
void func_01B00B38(W3Task *t);
void func_01B00BC8(W3Task *t);
void func_01B00C30(W3Task *t);
void func_01B00CE8(W3Task *t);
void func_01B00DA0(W3Task *t);
void func_01B00DD8(W3Task *t);
void func_01B00E40(W3Task *t);
void func_01B00EA8(W3Task *t);
void func_01B00F10(W3Task *t);

void func_01B00558(W3Task *t)
{
    float p[4];
    float q[4];
    float d[4];
    int ids[3];
    float mx = 0.0f;
    float zero = mx;
    float twopi;
    float rad;
    RcefMainCtx *c = &D_00313CB0;
    int *tg = c->targets;
    int n = c->target_count;
    int i;
    D_01B01108[2] = n - 1;
    D_01B01108[0] = n / 2;
    D_01B01108[1] = 0;
    func_001A2F00(c->caster, 12, p);
    __asm__ volatile("" ::: "memory");
    twopi = 6.2831855f;
    rad = 57.29578f;
    for (i = 0; i < 3; i++) {
        int id = tg[D_01B01108[i]];

        ids[i] = id;
        func_001A3000(id, 6, q);
        VEC3_SUB(d, q, p);
        d[3] = zero;
        d[1] = zero;
        {
            float len = rcVec3fLength((Vec4 *)d);
            if (mx < len)
                mx = len;
        }
        rcVec3fNormalize((Vec4 *)d);
        D_01B01118[i] = func_002E93A0(d[2]);
        if (zero < d[0])
            D_01B01118[i] = twopi - D_01B01118[i];
        D_01B01118[i] = (twopi - D_01B01118[i]) * 57.29578f;
    }
    D_01B0112C = 0;
    D_01B01124 = mx / 400.0f;
    D_01B01128 = 0;
    func_001A42D0(1, 0);
    func_001A1D08(t, func_01B00768);
    func_001A1D50(t, func_001A2058);
}

void func_01B00768(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B007B0);
    func_001A1D50(t, func_001A2098);
}

void func_01B007B0(W3Task *t)
{
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 178);
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

void func_01B008A8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313E48, 69);
    func_001A1420(o, 0x140);
    o->pos[0] = 0;
    o->pos[1] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[2] = -5.0f;
    o->scale[0] = -0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = D_01B01124;
    func_001A1D08(t, func_01B00948);
    func_001A1DF0(t, 20);
}

void func_01B00948(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A4288(0);
    func_001A4310(1);
    o->rot[0] = 0;
    o->rot[1] = D_01B01118[1];
    o->rot[2] = 0;
    *(float *)&o->rot_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    D_01B01128 = 0;
    func_001A1D08(t, func_01B009C8);
    func_001A1DF0(t, 10);
}

void func_01B009C8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float r = func_001A3620(1, D_01B01118[1], D_01B01118[2], (float)D_01B01128 / 60.0f);
    int n;

    o->rot[1] = r;
    o->rot[0] = 0;
    o->rot[2] = 0;
    n = D_01B01128 + 1;
    *(float *)&o->rot_w = 0;
    D_01B01128 = n;
    if (n >= 60) {
        D_01B01128 = 0;
        func_001A1D08(t, func_01B00A80);
        func_001A1D50(t, func_001A20D8);
    }
}
void func_01B00A80(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float r = func_001A3620(1, D_01B01118[2], D_01B01118[1], (float)D_01B01128 / 60.0f);

    o->rot[1] = r;
    o->rot[0] = 0;
    D_01B01128++;
    o->rot[2] = 0;
    *(float *)&o->rot_w = 0;
    if (D_01B01128 >= 60) {
        func_001A1D08(t, func_01B00898);
        func_001A1D50(t, func_001A20D8);
    }
}

void func_01B00B38(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313E48, 69);
    func_001A1420(o, 0x140);
    o->pos[0] = 0;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->pos[1] = 8.5f;
    o->scale[0] = 0.1f;
    o->scale[1] = 0.1f;
    o->scale[2] = D_01B01124;
    func_001A1D08(t, func_01B00BC8);
    func_001A1DF0(t, 20);
}

void func_01B00BC8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->rot[0] = 0;
    o->rot[1] = D_01B01118[1];
    o->rot[2] = 0;
    *(float *)&o->rot_w = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    D_01B0112C = 0;
    func_001A1D08(t, func_01B00C30);
}

void func_01B00C30(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float r = func_001A3620(1, D_01B01118[1], D_01B01118[2], (float)D_01B0112C / 60.0f);
    int n;

    o->rot[1] = r;
    o->rot[0] = 0;
    o->rot[2] = 0;
    n = D_01B0112C + 1;
    *(float *)&o->rot_w = 0;
    D_01B0112C = n;
    if (n >= 60) {
        D_01B0112C = 0;
        func_001A1D08(t, func_01B00CE8);
        func_001A1D50(t, func_001A20D8);
    }
}

void func_01B00CE8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float r = func_001A3620(1, D_01B01118[2], D_01B01118[1], (float)D_01B0112C / 60.0f);

    o->rot[1] = r;
    o->rot[0] = 0;
    D_01B0112C++;
    o->rot[2] = 0;
    *(float *)&o->rot_w = 0;
    if (D_01B0112C >= 60) {
        func_001A1D08(t, func_01B00898);
        func_001A1D50(t, func_001A20D8);
    }
}

void func_01B00DA0(W3Task *t)
{
    func_001A1D08(t, func_01B00DD8);
    func_001A1DF0(t, 30);
}

void func_01B00DD8(W3Task *t)
{
    W3Task *r = func_0019FF90_t(&D_00313CB0, func_01B00F10);

    r->frame[r->sp].count = D_01B01108[1];
    func_001A1D08(t, func_01B00E40);
    func_001A1DF0(t, 25);
}

void func_01B00E40(W3Task *t)
{
    W3Task *r = func_0019FF90_t(&D_00313CB0, func_01B00F10);

    r->frame[r->sp].count = D_01B01108[0];
    func_001A1D08(t, func_01B00EA8);
    func_001A1DF0(t, 20);
}

void func_01B00EA8(W3Task *t)
{
    W3Task *r = func_0019FF90_t(&D_00313CB0, func_01B00F10);

    r->frame[r->sp].count = D_01B01108[2];
    func_001A1D08(t, func_01B00898);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00F10(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int tgt = D_00313CB0.targets[t->frame[t->sp].count];

    func_001A13A0(o, tgt, 6);
    func_001A1420(o, 16);
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.25f;
    func_001A3800(tgt, 0);
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00898);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00FD0(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01130, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00518, D_01B00520);
    func_0019FF90(&D_00313CB0, func_01B00558);
    return 0;
}

int func_01B01040(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01068(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01090(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B010B8(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B010E0(void) { return 0; }
int func_01B010E8(void) { return 0; }
int func_01B010F0(void) { return 0; }
int func_01B010F8(void) { return 0; }
