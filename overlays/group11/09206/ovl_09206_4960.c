#include "common.h"

typedef struct {
    u8 pad00[0x8600];
    void *p8600;
} Work4960;

extern Work4960 *D_01B0C888;
extern void func_01B07BA0(void *);

void func_01B04960(void)
{
    Work4960 *w = D_01B0C888;
    if (w->p8600 != 0) {
        func_01B07BA0(w->p8600);
        w->p8600 = 0;
    }
}
