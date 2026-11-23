/* EE Battle-Effect Overlay: group 0x11, file 09404 (part 2: 0x01B01048..0x01B012A8, 4 functions) */
#include "rcef_overlay.h"
#include "vu0.h"

extern void *D_01B006F8[];
extern u8 D_01B00700[0x38];
extern RcefObj *D_01B01370;
extern s32 D_01B01374;
extern u8 D_01B01380[];

void func_001A2110(W3Task *t);
void func_001A0000_k(RcefMainCtx *ctx, RcefObj *o, int idx) __asm__("func_001A0000");

extern void func_01B00738(W3Task *t);
extern void func_01B00BE8(W3Task *t);
void func_01B01080(W3Task *t);

void func_01B01048(W3Task *t)
{
    if (--D_01B01374 >= 0) {
        func_0019FF90(&D_00313CB0, func_01B01080);
    } else {
        func_001A1D08(t, func_01B00BE8);
    }
}

void func_01B01080(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float pos[4];
    float rz;
    float sc;

    rz = (float)func_002EFD78() * (1.0f / 2147483648.0f) * 360.0f;
    sc = (float)func_002EFD78() * (1.0f / 2147483648.0f) * 0.2f + 0.2f;
    VU0_LQC2(31, 0, D_01B01370->pos);
    VU0_SQC2(31, 0, pos);
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    o->pos_w = 0;
    o->rot[0] = 0.0f;
    o->rot[1] = 0.0f;
    o->rot[2] = rz;
    o->rot_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = sc;
    o->scale[3] = 0;
    o->unk170[2] = o->unk170[1] = o->unk170[0] = 1.0f;
    o->unk170[3] = 0.3f;
    o->flagsBC |= 0x4000;
    func_001A0000_k(&D_00313CB0, o, 0);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A2110);
}

void func_01B011B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    o->pos[0] = 0.0f;
    o->pos[1] = -0.1f;
    o->pos[2] = 0.0f;
    o->pos_w = 0;
    o->scale[2] = o->scale[1] = o->scale[0] = 0.5f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00BE8);
    func_001A1D50(t, func_001A20D8);
}

int func_01B01238(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01380, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B006F8, D_01B00700);
    func_0019FF90(&D_00313CB0, func_01B00738);
    return 0;
}
