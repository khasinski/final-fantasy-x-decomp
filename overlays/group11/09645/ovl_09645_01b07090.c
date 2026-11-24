#include "common.h"

typedef struct Ovl09645Work1 {
    u8 pad00[0x18];
    float f18;
    float f1C;
} Ovl09645Work1;

extern u8 D_01B00B00[];
extern s32 D_01B00B2C;

void func_01B06780(void *);
void func_01B13CB8(void *);
void func_01B140C0(void *);

void func_01B07090(Ovl09645Work1 *a0)
{
    void *args[3];

    args[0] = a0;
    args[1] = func_01B06780;
    args[2] = a0;
    func_01B13CB8(args);

    args[0] = D_01B00B00;
    args[1] = a0;
    func_01B140C0(args);

    a0->f18 = a0->f1C = 0.0f;
    D_01B00B2C = 0x3C;
}
