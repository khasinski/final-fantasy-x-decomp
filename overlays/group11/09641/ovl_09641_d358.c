#include "common.h"

typedef struct {
    u8 *obj;
    float val;
} Arg0D88;

void func_01B10D88(Arg0D88 *a)
{
    u8 *p = a->obj;
    p[0x13A] = 0;
    *(float *)(p + 0x60) = a->val;
}
