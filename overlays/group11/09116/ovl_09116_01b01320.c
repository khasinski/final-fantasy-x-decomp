#include "common.h"

typedef struct Ovl09116Part {
    u8 pad00[0x6C];
    int active;
} Ovl09116Part;

extern Ovl09116Part *D_01B06D28;
extern int D_01B06D2C;
extern int D_01B06D30;
extern int D_01B06D34;
extern u8 D_01B01440[];

void *func_01B042B8(void *a0);
void func_01B04480(void *a0);

void *func_01B01320(Ovl09116Part *a0, int a1)
{
    int i;
    void *s0;

    D_01B06D28 = a0;
    for (i = 0; i < a1; i++, a0++) {
        a0->active = 0;
    }
    D_01B06D2C = 0;
    D_01B06D30 = a1;
    D_01B06D34 = 0;
    s0 = func_01B042B8(D_01B01440);
    func_01B04480(s0);
    return s0;
}
