#include "common.h"

extern void *D_01B07ED4;

extern int func_01B020D8(int);
extern int func_00117580(int);
extern u8 *func_00117BF8(int, int);
extern u8 *func_001175D8(int, int, int *);
extern void func_001178E0(int);
extern void func_01B03380(int, int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);
extern void func_002A7308(void *, int, int, int);

void func_01B01778(void)
{
    int sz;
    int s0;
    int s2 = func_01B020D8(-1);
    int s3 = func_00117580(s2);

    for (s0 = 0; s0 < s3; s0++) {
        u8 *s1 = func_00117BF8(s2, s0);
        u8 *t0 = func_001175D8(s2, s0, &sz);
        int a2;

        for (a2 = 0; a2 < sz; a2 += 16) {
            *(u_long128 *)(t0 + a2) = *(u_long128 *)(s1 + a2);
        }
    }

    func_001178E0(s2);
    func_01B03380(-1, 0);
}

void func_01B01858(void)
{
    int s0 = func_01B020D8(-1);

    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_002A7308(D_01B07ED4, s0, 1, 0);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
    func_01B03380(-1, 1);
}
