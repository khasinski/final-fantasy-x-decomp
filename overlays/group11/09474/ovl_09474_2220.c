#include "common.h"

typedef struct {
    u8 pad00[0x04];
    int w04;
    u8 pad08[0x0E];
    u8 b16;
    u8 pad17[0xAD];
    void *pC4;
} OvlEA8;

extern OvlEA8 D_01B00EA8;

extern void func_00110648(void *, int);
extern void func_01B044E8(int, int);
extern void func_01B04D48(int);
extern void *func_01B04DB8(int);

void func_01B02220(void)
{
    func_01B04D48(0x3016);
}

void func_01B02228(void)
{
    OvlEA8 *s0 = &D_01B00EA8;
    void *v0 = func_01B04DB8(0x3016);

    s0->pC4 = v0;
    s0->b16 = 0x20;
    func_00110648(v0, 0);
    {
        register int three __asm__("$3") = 3;
        s0->w04 = three;
    }
    func_01B044E8(2, 1);
}
