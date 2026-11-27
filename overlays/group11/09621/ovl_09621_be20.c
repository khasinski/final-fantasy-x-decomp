#include "common.h"

typedef struct {
    u8 *obj;
    float val;
} Arg0DA0;

void func_01B10DA0(Arg0DA0 *a)
{
    u8 *p = a->obj;
    p[0x139] = 0;
    *(float *)(p + 0x64) = a->val;
}
