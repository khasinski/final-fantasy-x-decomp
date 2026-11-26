#include "common.h"

typedef struct {
    u8 pad00[0xEC0];
    void *pEC0;
} OvlWork;

extern OvlWork *D_01B08A90;

extern void func_01B04440(void *);

void ovl_09644_1770(void)
{
    OvlWork *s0 = D_01B08A90;

    if (s0->pEC0 != 0) {
        func_01B04440(s0->pEC0);
        s0->pEC0 = 0;
    }
}
