#include "common.h"

typedef struct {
    u8 pad00[0xC80];
    u8 fC80[0x248];
    float fEC8;
} OvlWork;

extern OvlWork *D_01B08A90;

extern void func_01B05558(void *, void *, void *);

void ovl_09644_1898(void)
{
    float sp00[4];
    float sp10[4];
    OvlWork *w = D_01B08A90;

    sp00[0] = 0.0f;
    sp00[1] = w->fEC8;
    sp10[0] = -20.0f;
    sp10[2] = -10.0f;
    sp10[3] = 1.0f;
    sp00[2] = 0.0f;
    sp00[3] = 0.0f;
    sp10[1] = 0.0f;
    func_01B05558(sp00, w->fC80, sp10);
}
