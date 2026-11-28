#include "common.h"

extern u8 *D_01B0C0B0;
extern void func_01B073E8(void *);
extern void *func_01B04BF0(int);
extern void Ch_TextureSetImageBase(void *, int, int);
extern void Ch_TextureSetClutBase(void *, int, int);

void func_01B04128(void)
{
    u8 *s0 = D_01B0C0B0 + 0x8000;
    void *h;

    if (*(void **)(s0 + 0x5C4) != 0) {
        func_01B073E8(*(void **)(s0 + 0x5C4));
        *(void **)(s0 + 0x5C4) = 0;
    }
    h = func_01B04BF0(-1);
    Ch_TextureSetImageBase(h, -1, -1);
    Ch_TextureSetClutBase(h, -1, -1);
    h = func_01B04BF0(1);
    Ch_TextureSetImageBase(h, -1, -1);
    Ch_TextureSetClutBase(h, -1, -1);
}
