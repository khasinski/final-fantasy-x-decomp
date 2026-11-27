#include "common.h"

typedef struct {
    u8 pad00[0x3180];
    int w3180;
} Work10B8;

extern int D_01B0B128;
extern u8 D_01B0B130[];
extern Work10B8 *D_01B0B1F8;
extern int D_01B0B200;
extern int func_01B06A98(void *, int);
extern void func_001CDDD8(int);

void func_01B010B8(void)
{
    Work10B8 *w = D_01B0B1F8;
    if (func_01B06A98(D_01B0B130, D_01B0B200) == 1 && w->w3180 == 1) {
        func_001CDDD8(D_01B0B128);
    }
}
