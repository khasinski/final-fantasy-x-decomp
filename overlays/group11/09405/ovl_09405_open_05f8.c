/* EE Battle-Effect Overlay: group 0x11, file 09405
 * .text: 0x01B005F8..0x01B006CC (1 function).
 */
#include "rcef_overlay.h"

extern int D_01B01CD0;
extern int D_01B01D14;
extern int D_01B01D18;
extern int D_01B01D1C;

/* DEBT(TYPE): funcs.h declares func_001B4E18(u8), overlay calls it with int */
extern int func_001B4E18_i(int chr_id) __asm__("func_001B4E18");
extern void func_01B006D0(W3Task *t);

void func_01B005F8(W3Task *t)
{
    int target = D_00313CB0.targets[0];
    int caster = D_00313CB0.caster;

    D_01B01D1C = MsGetColorStatus(target);
    D_01B01CD0 = 0;
    D_01B01D14 = (func_001B4E18_i(caster) == 0x1041);
    D_01B01D18 = func_001BB930(D_00313CB0.eff_id, target, 0, 0, 0, 0, 0, 0);
    func_001A42D0(2, 0);
    func_001A1D08(t, func_01B006D0);
    func_001A1D50(t, func_001A2058);
}
