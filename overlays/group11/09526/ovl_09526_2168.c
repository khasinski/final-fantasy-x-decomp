/* EE Battle-Effect Overlay: group 0x11, file 09526 (0x01B02168..0x01B021D4)
 * Shared with: 09431 (0x01B1A2D0..0x01B1A33C)
 * .text: 1 function (108 bytes)
 */
#include "common.h"

extern u8 D_01B00A80[];
void func_01B02068(void *);
void func_01B0D628(void *m);
void func_01B0DA30(void *m);

void func_01B02168(u8 *a0, int a1)
{
    void *m[4];

    m[0] = a0;
    m[1] = func_01B02068;
    m[2] = a0;
    func_01B0D628(m);
    m[0] = D_01B00A80;
    m[1] = a0;
    func_01B0DA30(m);
    *(int *)(a0 + 0x3C) = a1;
    *(int *)(a0 + 0x30) = 0;
    *(int *)(a0 + 0x18) = 0;
}
