#include "common.h"

typedef struct {
    u8 pad00[0x3388];
    int w3388;
} OvlWork;

extern u8 D_01B087E8[];
extern u8 D_01B08848[];
extern OvlWork *D_01B08868;

extern void func_01B00DC0(void);
extern int func_01B03910(void *);
extern void func_01B044B0(void *);
extern int func_01B082A0(void *);

void ovl_09476_0c18(void *a0)
{
    OvlWork *s1 = D_01B08868;
    int s0 = func_01B082A0(D_01B087E8);
    int v0 = func_01B03910(D_01B08848);

    if (s0 != 0 && v0 != 0) {
        s1->w3388 = 1;
        func_01B00DC0();
        func_01B044B0(a0);
    }
}
