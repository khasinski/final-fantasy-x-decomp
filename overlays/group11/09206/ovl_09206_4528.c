#include "common.h"

typedef struct {
    u8 pad00[0x984];
    float f984;
    u8 pad988[0x1C];
    float f9A4;
    u8 pad9A8[0x4C];
    float f9F4;
} Work4528;

extern Work4528 *D_01B0C888;

void func_01B04528(void)
{
    Work4528 *w = D_01B0C888;
    w->f9A4 = w->f984 += 0.5f;
}

void func_01B04550(void)
{
    Work4528 *w = D_01B0C888;
    float v = w->f9F4;
    w->f9A4 = v;
    __asm__ volatile("");
    w->f984 = v;
}
