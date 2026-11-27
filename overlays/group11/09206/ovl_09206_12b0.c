#include "common.h"

typedef struct {
    u8 pad00[0xA30];
    u8 items[20][0x600];
} Work12B0;

extern Work12B0 *D_01B0C888;
extern u8 D_01B11E30[];
extern void *func_002B49A0(void *, int, int);
extern void func_01B01320(void *, void *);

void func_01B012B0(void)
{
    Work12B0 *w = D_01B0C888;
    int i;
    for (i = 0; i < 20; i++) {
        func_01B01320(func_002B49A0(D_01B11E30, 4, i), w->items[i]);
    }
}
