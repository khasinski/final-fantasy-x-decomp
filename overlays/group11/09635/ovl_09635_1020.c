/* EE Battle-Effect Overlay: group 0x11, file 09635 (unique 0x01B01020)
 * Load base: 0x01B00000, .text: 0x01B01020..0x01B01078 (1 function)
 */
#include "common.h"

extern u8 *D_01B07630;

void func_01B072C0(void *a0, int a1, int a2, float f0, float f1);

void func_01B01020(void)
{
    u8 *p = D_01B07630 + 0x1A60;

    func_01B072C0(p, 0x1E, 0, 1.0f, 0.5f);
    *(float *)(p + 0x14) = 0.65f;
}
