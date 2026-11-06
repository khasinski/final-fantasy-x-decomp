/* EE Battle-Effect Overlay: group 0x11, file 09573
 * Load base: 0x01B00000, .text: 0x01B006C0..0x01B01130 (25 functions)
 */
#include "../rcef_overlay.h"

extern void *D_01B00680[];
extern u8 D_01B00688[];
extern int D_01B01138;  /* frame counter */
extern int *D_01B0113C; /* screen-effect object */
extern int D_01B01140;  /* caster */
extern int D_01B01144;  /* caster chr handle */
extern u8 D_01B01150[];
extern s32 D_00313E48;

void func_001A02D8(void);
void func_001A02E8(int a0);
void *func_001A2388(void);
void func_001A23C8(void *obj);
void func_001A2530(void *obj, int a1, int a2, int a3);
void func_001A2608(void *obj);
void func_00110B80(int h, int a1);
void func_00299218(int h);
void func_001B5810(int chr, int a1);
void func_001CE2F0(int chr, int a1);
void func_0019FDF0(RcefMainCtx *ctx);

void func_01B00760(W3Task *t);
void func_01B007A8(W3Task *t);
void func_01B00828(W3Task *t);
void func_01B00860(W3Task *t);
void func_01B008A0(W3Task *t);
void func_01B008F8(W3Task *t);
void func_01B00908(W3Task *t);
void func_01B009B0(W3Task *t);
void func_01B00BF0(W3Task *t);
void func_01B00C90(W3Task *t);
void func_01B00D00(W3Task *t);
void func_01B00D40(W3Task *t);
void func_01B00DB0(W3Task *t);
void func_01B00E78(W3Task *t);
void func_01B00EF0(W3Task *t);

void func_01B006C0(W3Task *t)
{
    int caster = D_00313E48;
    int h;

    D_01B01140 = caster;
    h = (int)rcefGetChrHandle(caster);
    D_01B01144 = h;
    graphicCharacterInstanceSetMeshSegmentAlpha(h, 0, 0);
    graphicCharacterInstanceSetMeshSegmentAlpha(D_01B01144, 1, 1);
    graphicCharacterInstanceSetMeshSegmentAlpha(D_01B01144, 2, 0);
    D_01B01138 = 0;
    D_01B0113C = 0;
    func_001A1D08(t, func_01B00760);
    func_001A1D50(t, func_001A2058);
}

void func_01B00760(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B007A8);
    func_001A1D50(t, func_001A2098);
}

void func_01B007A8(W3Task *t)
{
    func_001A4288(0);
    func_00299218(D_01B01144);
    func_00110B80(D_01B01144, 0);
    func_0019FF90(&D_00313CB0, func_01B00C90);
    func_0019FF90(&D_00313CB0, func_01B00D40);
    func_001A1D08(t, func_01B00828);
}

void func_01B00828(W3Task *t)
{
    func_001A1D08(t, func_01B00860);
    func_001A1D50(t, func_001A21E0);
}

void func_01B00860(W3Task *t)
{
    func_001A37F0();
    func_001A1D08(t, func_01B008A0);
    func_001A1D50(t, func_001A2210);
}

void func_01B008A0(W3Task *t)
{
    int caster = D_00313E48;

    func_001B57F0(caster, 0);
    func_001CE2F0(caster, 1);
    func_001A1D08(t, func_01B008F8);
}

void func_01B008F8(W3Task *t)
{
    t->flags |= 4;
}

void func_01B00908(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 0);
    o->pos[0] = 0;
    o->pos[1] = -0.1f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.2f;
    rcefMainKickPar(&D_00313CB0, o, 0, 2);
    func_001A1D08(t, func_01B008F8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B009B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float d[3];
    float q[4];
    float k = 4.656612873077393e-10f;
    float one = 1.0f;
    float s;
    float h;
    int caster = D_00313CB0.caster;

    d[0] = (float)func_002EFD78() * k * 2.0f - one;
    d[1] = -((float)func_002EFD78() * k) * 0.5f - 0.5;
    d[2] = (float)func_002EFD78() * k * 2.0f - one;
    func_002DCEC8((s32)d, (s32)d);
    func_002DD998(q, d, 0.001f);
    h = (float)func_002EFD78() * k * 5.0f + 20.0f;
    func_002DD998(d, d, h);
    d[1] = d[1] * 0.8f;
    d[2] = d[2] * 1.8f;
    s = (float)func_002EFD78() * k * 0.15f + 0.1f;
    o->flagsBC |= 0x2000;
    func_001A13A0(o, caster, 0);
    o->scale[0] = s;
    o->scale[1] = s;
    o->scale[2] = s;
    o->pos_w = 0;
    o->vel[3] = 0;
    o->rot[1] = 0;
    o->rot[2] = 0;
    o->rot_w = 0;
    o->scale[3] = 0;
    o->pos[0] = d[0];
    o->pos[1] = d[1];
    o->pos[2] = d[2];
    o->vel[0] = q[0];
    o->vel[1] = q[1];
    o->vel[2] = q[2];
    o->rot[0] = 90.0f;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B008F8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00BF0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.caster, 0);
    o->pos[0] = 0;
    o->pos[1] = -10.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[3] = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.3f;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B008F8);
    func_001A1D50(t, func_001A20D8);
}

void func_01B00C90(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 74);
    func_001A1D08(t, func_01B00D00);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B00D00(W3Task *t)
{
    func_001A2B80(D_00313E48, 75);
    t->flags |= 4;
}

void func_01B00D40(W3Task *t)
{
    void *o = func_001A2388();

    D_01B0113C = o;
    func_001A2530(o, D_01B01140, 1, 1);
    func_001A36D8(0, 0, 0, 64, 15);
    func_001A02E8(1);
    func_001A1D08(t, func_01B00DB0);
}

void func_01B00DB0(W3Task *t)
{
    int n;

    n = ++D_01B01138;
    if (n < 150) {
        if (n < 75) {
            if (n % 12 == 0) {
                func_0019FF90(&D_00313CB0, func_01B009B0);
            }
        } else if ((n & 7) == 0) {
            func_0019FF90(&D_00313CB0, func_01B009B0);
        }
    } else {
        func_0019FF90(&D_00313CB0, func_01B00908);
        D_01B01138 = 0;
        func_001A1D08(t, func_01B00E78);
    }
    func_001A02D8();
    func_001A2608(D_01B0113C);
}

void func_01B00E78(W3Task *t)
{
    D_01B01138 = D_01B01138 + 1;
    if (D_01B01138 >= 5) {
        D_01B0113C[4] &= ~8;
        D_01B01138 = 0;
        func_001A1D08(t, func_01B00EF0);
    }
    func_001A02D8();
    func_001A2608(D_01B0113C);
}

void func_01B00EF0(W3Task *t)
{
    if (D_01B01138 < 50) {
        if ((D_01B01138 & 7) == 0) {
            func_0019FF90(&D_00313CB0, func_01B009B0);
        }
    }
    ((u8 *)D_01B0113C)[0x2B] = (130 - D_01B01138) * 128 / 130;
    if (D_01B01138 != 130) {
        func_001A02D8();
    }
    func_001A2608(D_01B0113C);
    D_01B01138 = D_01B01138 + 1;
    if (D_01B01138 > 130) {
        func_001A3800(D_01B01140, 10);
        func_001B5810(D_01B01140, 0);
        func_001A23C8(D_01B0113C);
        func_001A02E8(0);
        t->flags |= 4;
        D_01B0113C = 0;
    }
}

int func_01B01000(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01150, 0x01E40000, 0x000C0000, 0x01D40000, 1, D_01B00680, D_01B00688);
    func_0019FF90(&D_00313CB0, func_01B006C0);
    return 0;
}

int func_01B01070(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B01098(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B010C0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B010E8(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01110(void) { return 0; }
int func_01B01118(void) { return 0; }
int func_01B01120(void) { return 0; }
int func_01B01128(void) { return 0; }
