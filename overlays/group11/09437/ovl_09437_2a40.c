#include "common.h"

typedef struct {
    u8 pad00[0x1F20];
    int w1F20;
} Work2A40;

extern Work2A40 *D_01B0A5F0;
extern u8 D_01B12470[];
extern void func_01B05A90(void *, int, int, int);

void func_01B02A40(void)
{
    func_01B05A90(D_01B12470, D_01B0A5F0->w1F20, 0x40, 0x100);
}
