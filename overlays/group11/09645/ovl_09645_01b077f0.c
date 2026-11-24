#include "common.h"

typedef struct Ovl09645Work2 {
    u8 pad00[0x29D0];
    u8 f29D0[0x18];
    s32 w29E8;
    float f29EC;
    float f29F0;
} Ovl09645Work2;

extern u8 D_01B00B18[];

void func_01B07100(void *);
void func_01B13CB8(void *);
void func_01B140C0(void *);

void func_01B077F0(Ovl09645Work2 *a0)
{
    void *args[3];

    args[0] = a0->f29D0;
    args[1] = func_01B07100;
    args[2] = a0;
    func_01B13CB8(args);

    args[0] = D_01B00B18;
    args[1] = a0->f29D0;
    func_01B140C0(args);

    a0->w29E8 = 0;
    a0->f29EC = a0->f29F0 = 0.0f;
}
