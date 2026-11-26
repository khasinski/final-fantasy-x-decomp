#include "common.h"

typedef struct {
    void *p00;
} Arg4;

extern u8 D_01B00CA0[];
extern u8 D_01B00D40[];

extern void func_01B04088(Arg4 *);

int ovl_09222_2a58(void)
{
    Arg4 a0;
    Arg4 a1;
    u8 *s0 = D_01B00D40;

    a0.p00 = s0;
    func_01B04088(&a0);
    a1.p00 = s0 - 0xA0;
    func_01B04088(&a1);
    return 0;
}
