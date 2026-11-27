#include "common.h"
typedef struct { u8 *obj; u32 shift; u32 set; } Arg1120;
void func_01B0C228(Arg1120 *a) {
    u8 *obj = a->obj;
    if (a->set != 0) {
        *(u32 *)(obj + 0x130) |= (1 << a->shift);
    } else {
        *(u32 *)(obj + 0x130) &= ~(1 << a->shift);
    }
}
