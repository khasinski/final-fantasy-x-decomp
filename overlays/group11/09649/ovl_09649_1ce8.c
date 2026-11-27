#include "common.h"

typedef struct {
    u8 pad00[0x2DF0];
    u8 sub2DF0[0x10];
} Work1CE8;

extern Work1CE8 *D_01B0B1F8;
extern void func_00118098(int, int);
extern void func_01B0A4B8(void *, int, int, float, float);

void func_01B01CE8(void)
{
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B0A4B8(D_01B0B1F8->sub2DF0, 20, 0, 1.0f, 0.5f);
}
