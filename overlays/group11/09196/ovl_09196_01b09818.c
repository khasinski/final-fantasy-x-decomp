#include "common.h"

typedef struct Ovl09196Work32C0 {
    u8 pad00[0x2A00];
    u8 f2A00[0x18];
    s32 w2A18;
    float f2A1C;
    float f2A20;
} Ovl09196Work32C0;

extern u8 D_01B00B18[];
extern u8 D_01B07A38[];

void func_01B18300(void *);
void func_01B18708(void *);

void func_01B09818(Ovl09196Work32C0 *a0)
{
    void *args[3];

    args[0] = a0->f2A00;
    args[1] = D_01B07A38;
    args[2] = a0;
    func_01B18300(args);

    args[0] = D_01B00B18;
    args[1] = a0->f2A00;
    func_01B18708(args);

    a0->w2A18 = 0;
    a0->f2A1C = a0->f2A20 = 0.0f;
}
