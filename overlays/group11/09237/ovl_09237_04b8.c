/* EE Battle-Effect Overlay: group 0x11, file 09237 (part 1)
 * Load base: 0x01B00000, .text: 0x01B004B8..0x01B005A0 (3 functions)
 */
#include "rcef_overlay.h"

extern int D_01B01390;

void func_001A42D0(int a0, int a1);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B00508(W3Task *t);
void func_01B00550(W3Task *t);
void func_01B005A0(W3Task *t);
void func_01B011A0(W3Task *t);

void func_01B004B8(W3Task *t)
{
    D_01B01390 = 0;
    func_001A42D0(2, 0);
    func_001A1D08(t, func_01B00508);
    func_001A1D50(t, func_001A2058);
}

void func_01B00508(W3Task *t)
{
    func_001A2B58(0);
    func_001A1D08(t, func_01B00550);
    func_001A1D50(t, func_001A2098);
}

void func_01B00550(W3Task *t)
{
    func_0019FF90_t(&D_00313CB0, func_01B011A0);
    func_001A1D08(t, func_01B005A0);
    func_001A1DF0(t, 0x1E);
}
