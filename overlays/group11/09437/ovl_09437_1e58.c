#include "common.h"

typedef struct {
    u8 pad00[0x1F1C];
    int w1F1C;
} Work1E58;

extern Work1E58 *D_01B0A5F0;
extern void func_0011ABA8(int);
extern void func_00103208(int);
extern int func_01B03910(int);
extern void func_01B04D38(int, int);
extern void func_01B05060(int);

void func_01B01E58(void)
{
    Work1E58 *w = D_01B0A5F0;
    func_0011ABA8(0);
    func_00103208(func_01B03910(1));
    if (w->w1F1C != -1) {
        func_00103208(func_01B03910(2));
    }
    func_01B04D38(-1, 0);
}

void func_01B01EC0(void)
{
    Work1E58 *w = D_01B0A5F0;
    func_01B05060(0x4029);
    if (w->w1F1C != -1) {
        func_01B05060(w->w1F1C);
    }
}
