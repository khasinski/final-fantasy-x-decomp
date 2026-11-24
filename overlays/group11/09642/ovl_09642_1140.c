#include "common.h"

typedef struct {
    u8 pad00[0xD6C];
    int fD6C;
} Work1140;

extern int D_01B08FD8;
extern u8 D_01B08FE0[];
extern void *D_01B09024;
extern Work1140 *D_01B09148;

extern void func_001CDDD8(int);
extern int func_01B04AD8(void *, void *);

void func_01B01140(void)
{
    Work1140 *w = D_01B09148;

    if (func_01B04AD8(D_01B08FE0, D_01B09024) == 1 && w->fD6C == 1) {
        func_001CDDD8(D_01B08FD8);
    }
}
