#include "common.h"

typedef struct {
    u8 pad00[0x180C];
    int w180C;
} OvlState;

extern int D_01B0A3B8;
extern u8 D_01B0A3C0[];
extern void *D_01B0A404;
extern u8 D_01B0A408[];
extern u8 D_01B0A448[];
extern OvlState *D_01B0A568;

extern void func_001CDDD8(int);
extern int func_01B05D90(void *, void *);

void func_01B01DD8(void)
{
    OvlState *s = D_01B0A568;
    int r0, r1, r2;

    r0 = func_01B05D90(D_01B0A3C0, D_01B0A404);
    r1 = func_01B05D90(D_01B0A408, 0);
    r2 = func_01B05D90(D_01B0A448, 0);
    if (r0 == 1 && r1 == 1 && r2 == 1 && s->w180C == 1) {
        func_001CDDD8(D_01B0A3B8);
    }
}
