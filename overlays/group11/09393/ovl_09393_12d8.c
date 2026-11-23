/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B012D8..0x01B01344, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B012D8..0x01B01344 (2 functions)
 */
#include "common.h"

typedef struct Work09393 {
    u8 pad0000[0x1A20];
    float unk1A20[4];
} Work09393;

extern Work09393 *D_01B07C10;

void func_01B02140(int a0, int a1, int a2, void *a3);
void func_01B03030(int a0, int a1);

void func_01B012D8(u8 *a0)
{
    Work09393 *w = D_01B07C10;

    func_01B02140(*(int *)(a0 + 0x120), 0x10, 0, a0 + 0xD0);
    *(int *)(a0 + 0x104) = 0;
    *(float *)(a0 + 0xD4) = w->unk1A20[1] - 0.5f;
}

void func_01B01338(u8 *a0)
{
    func_01B03030(*(int *)(a0 + 0x120), 0xE);
}
