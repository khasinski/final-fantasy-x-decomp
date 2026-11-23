/* EE Battle-Effect Overlay: group 0x11, file 09237 (part 3)
 * Load base: 0x01B00000, .text: 0x01B010F0..0x01B012C0 (4 functions)
 */
#include "rcef_overlay.h"

extern void *D_01B00478[];
extern u8 D_01B00480[0x38];
extern u8 D_01B01440[];
extern s32 D_00313E48;

void func_0019FFD0(RcefMainCtx *ctx, RcefObj *o, int a2, int a3);
void MsEffectEndMotion(int chr, int a1);

void func_01B004B8(W3Task *t);
void func_01B00B00(W3Task *t);
void func_01B01210(W3Task *t);

void func_01B010F0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[t->frame[t->sp].count], 6);
    func_001A1420(o, 0x10);
    o->scale[3] = 0;
    o->scale[0] = 0.15f;
    o->scale[1] = 0.15f;
    o->scale[2] = 0.15f;
    func_0019FFD0(&D_00313CB0, o, 0, 0);
    func_001A1D08(t, func_01B00B00);
    func_001A1D50(t, func_001A20D8);
}

void func_01B011A0(W3Task *t)
{
    int caster = D_00313E48;

    func_001A2B80(caster, 0x7A);
    func_001A1D08(t, func_01B01210);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}

void func_01B01210(W3Task *t)
{
    MsEffectEndMotion(D_00313E48, 0);
    t->flags |= 4;
}

int func_01B01250(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B01440, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00478, D_01B00480);
    func_0019FF90(&D_00313CB0, func_01B004B8);
    return 0;
}
