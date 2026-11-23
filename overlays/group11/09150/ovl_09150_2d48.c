/* EE Battle-Effect Overlay: group 0x11, file 09150 (0x01B02D48..0x01B02D98)
 * Shared across open battle-effect containers (80 bytes each)
 */
#include "common.h"

typedef struct Arg2D48 {
    u8 *p00;
    float f04;
    int i08;
} Arg2D48;

void func_002DD038(void *dst, void *a, void *b);

void func_01B02D48(Arg2D48 *a0)
{
    u8 *s0 = a0->p00;

    func_002DD038(s0 + 0x40, s0 + 0x30, s0 + 0x20);
    *(int *)(s0 + 0x58) = a0->i08;
    *(float *)(s0 + 0x54) = a0->f04;
    *(void **)(s0 + 0x50) = 0;
}
