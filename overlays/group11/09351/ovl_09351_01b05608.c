#include "common.h"

extern u8 *D_01B0E828;
extern u8 D_01B0D6B8[];
extern u8 D_01B0D700[];

extern void func_01B08838(void *);
extern void func_01B08F88(void *, void *);

void func_01B05608(void)
{
    u8 *s0 = D_01B0E828;
    void *p = *(void **)(s0 + 0x2934);

    if (p != 0) {
        func_01B08838(p);
        *(void **)(s0 + 0x2934) = 0;
    }
    func_01B08F88(D_01B0D6B8, D_01B0D700);
}
