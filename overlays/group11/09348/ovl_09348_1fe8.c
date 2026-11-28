#include "common.h"

typedef struct {
    u8 pad00[0x184C];
    int w184C;
} OvlState;

extern int D_01B0A9B8;
extern u8 D_01B0A9C0[];
extern void *D_01B0AA04;
extern u8 D_01B0AA08[];
extern u8 D_01B0AA48[];
extern OvlState *D_01B0AB88;

extern void func_001CDDD8(int);
extern int func_01B06390(void *, void *);

void func_01B01FE8(void)
{
    OvlState *s = D_01B0AB88;
    int r0, r1, r2;

    r0 = func_01B06390(D_01B0A9C0, D_01B0AA04);
    r1 = func_01B06390(D_01B0AA08, 0);
    r2 = func_01B06390(D_01B0AA48, 0);
    if (r0 == 1 && r1 == 1 && r2 == 1 && s->w184C == 1) {
        func_001CDDD8(D_01B0A9B8);
    }
}
