#include "common.h"

typedef struct Ovl09115Work {
    u8 pad00[0x18];
    s32 w18;
    u8 pad1C[0x14];
    s32 w30;
} Ovl09115Work;

extern u8 D_01B00A70[];
extern u8 D_01B00A88[];
extern u8 D_01B04BF0[];

void func_01B05698(void *);
void func_01B07D70(void *);
void func_01B12748(void *);
void func_01B12B50(void *);

void func_01B05FC0(Ovl09115Work *a0, void *a1, void *a2)
{
    void *args[4];

    args[0] = a0;
    args[1] = func_01B05698;
    args[2] = a0;
    func_01B12748(args);

    args[0] = D_01B00A70;
    args[1] = a0;
    func_01B12B50(args);

    args[0] = D_01B04BF0;
    args[1] = D_01B00A88;
    args[2] = a1;
    args[3] = a2;
    func_01B07D70(args);

    a0->w30 = 0;
    a0->w18 = 0;
}
