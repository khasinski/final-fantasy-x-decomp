/* EE Battle-Effect Overlay: group 0x11, file 09635 (unique 0x01B01540)
 * Load base: 0x01B00000, .text: 0x01B01540..0x01B01598 (1 function)
 */
#include "common.h"

extern u8 *D_01B07630;

void func_01B072C0(void *a0, int a1, int a2, float f0, float f1);

void func_01B01540(void)
{
    u8 *p = D_01B07630 + 0x1A60;

    func_01B072C0(p, 0x1E, 0, 0.5f, 1.0f);
    *(float *)(p + 4) = 0.65f;
}
