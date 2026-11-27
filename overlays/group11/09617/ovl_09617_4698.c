#include "common.h"

typedef struct {
    u8 *p00;
    u32 w04;
    float f08;
} Arg4698;

void func_01B04698(Arg4698 *a0)
{
    u8 *v0 = a0->p00;
    u32 w = a0->w04;

    v0[0x14D] = 1;
    *(u32 *)(v0 + 0x150) = w;
    *(float *)(v0 + 0x1B8) = a0->f08;
}
