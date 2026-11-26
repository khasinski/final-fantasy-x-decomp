#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x3C];
    void *fn104;
    u8 pad108[0x3278];
    float f3380;
} OvlWork;

extern u8 D_01B01448[];
extern u8 D_01B087A0[];
extern OvlWork *D_01B08868;

extern void func_01B04790(void *, void *, int, int, float, int, int);

void ovl_09476_1490(void)
{
    OvlWork *s0 = D_01B08868;

    func_01B04790(D_01B087A0, s0, 0, 0, 0.01f, 0, 0);
    s0->fC4 = s0->f3380;
    s0->fn104 = D_01B01448;
}
