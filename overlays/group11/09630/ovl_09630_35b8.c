#include "common.h"

typedef struct {
    u8 pad00[0x85EC];
    int w85EC;
} Work9630;

extern int D_01B0BF40;
extern u8 D_01B0BF48[];
extern int D_01B0BF8C;
extern Work9630 *D_01B0C0B0;
extern int D_01B0C0B8;
extern int D_01B0C0BC;

extern void func_0010D380(int, int, int);
extern int func_0010D3A8(int, int, int);
extern void func_001CDDD8(int);
extern void func_002A7308(int, int, int, int);
extern int func_01B04BF0(int);
extern int func_01B077A8(void *, int);

void func_01B035B8(void)
{
    Work9630 *w = D_01B0C0B0;
    if (func_01B077A8(D_01B0BF48, D_01B0BF8C) == 1 && w->w85EC == 1) {
        func_001CDDD8(D_01B0BF40);
    }
}

void func_01B03628(void)
{
    int h = func_01B04BF0(-1);
    func_0010D380(h, -1, 0x3C00);
    func_0010D3A8(h, -1, 0x2EE0);
    func_002A7308(D_01B0C0B8, h, 1, 0);
}

void func_01B03688(void)
{
    int h = func_01B04BF0(1);
    func_0010D380(h, -1, 0x3C00);
    func_0010D3A8(h, -1, 0x2EE0);
    func_002A7308(D_01B0C0BC, h, 1, 0);
}
