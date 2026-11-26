#include "common.h"

typedef struct {
    u8 pad00[0x127];
    u8 b127;
} OvlF80;

typedef struct {
    u8 pad00[0xF80];
    OvlF80 f80;
} OvlWork;

extern OvlWork *D_01B08868;

extern void func_01B00DF0(void *, void *, void *);
extern void func_01B02370(int, int, void *);
extern void func_01B044B0(void *);

void ovl_09476_14f8(void *a0)
{
    float sp00[4];
    float sp10[4];
    OvlWork *w = D_01B08868;
    OvlF80 *s0;

    func_01B02370(-1, 0xC, sp00);
    func_01B02370(-1, 0xB, sp10);
    s0 = &w->f80;
    if (s0->b127 < 2) {
        func_01B044B0(a0);
    } else {
        s0->b127 -= 2;
        func_01B00DF0(s0, sp10, sp00);
    }
}
