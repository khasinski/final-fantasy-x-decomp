#include "common.h"

typedef struct {
    u8 pad00[0x862C];
    int w862C;
} Work37F8;

extern int D_01B0C6F8;
extern u8 D_01B0C700[];
extern int D_01B0C744;
extern Work37F8 *D_01B0C888;
extern int func_01B07F60(void *, int);
extern void func_001CDDD8(int);

void func_01B037F8(void)
{
    Work37F8 *w = D_01B0C888;
    if (func_01B07F60(D_01B0C700, D_01B0C744) == 1 && w->w862C == 1) {
        func_001CDDD8(D_01B0C6F8);
    }
}
