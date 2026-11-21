/* EE Battle-Effect Overlay: group 0x11, file 09405
 * .text: 0x01B00718..0x01B00848 (1 function).
 */
#include "rcef_overlay.h"

extern int D_01B01D14;

/* DEBT(TYPE): funcs.h declares func_001B6620(u8)->u8, overlay calls it as int->int */
extern int func_001B6620_i(int chr_id) __asm__("func_001B6620");
extern void func_001A2B78(int chr_id, int a1, int a2, int a3, int t0, int t1, float f0, float f1, float f2, float f3, float f4);
extern void func_001A2198(W3Task *t);
extern void func_01B00848(W3Task *t);

void func_01B00718(W3Task *t)
{
    int caster = D_00313CB0.caster;
    int target = D_00313CB0.targets[0];
    float dist;

    func_001A2B80(caster, 16);
    if (func_001B6620_i(target) > 0) {
        dist = 4.0f;
    } else {
        dist = 0.0f;
    }
    switch (D_01B01D14) {
    case 0:
        func_001A2B78(caster, 2, 0, 30, 32, 32, 0.0f, dist + 5.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 1:
        func_001A2B78(caster, 2, 0, 30, 32, 32, 0.0f, dist + 9.0f, 0.0f, 0.0f, 0.0f);
        break;
    }
    func_001A4288(0);
    func_001A1D08(t, func_01B00848);
    func_001A1D50(t, func_001A2198);
    t->frame[t->sp].count = caster;
}
