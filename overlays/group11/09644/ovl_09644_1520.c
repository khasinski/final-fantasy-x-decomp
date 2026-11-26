#include "common.h"

typedef struct {
    u8 pad00[0x04];
    int w04;
    u8 pad08[0x0E];
    u8 b16;
    u8 pad17[0xAD];
    void *pC4;
} OvlA90;

extern OvlA90 D_01B00A90;

extern void func_00110648(void *, int);
extern void func_01B02B38(int, int);
extern void *func_01B03408(int);

void ovl_09644_1520(void)
{
    OvlA90 *s0 = &D_01B00A90;
    void *v0 = func_01B03408(0x3016);

    s0->pC4 = v0;
    s0->b16 = 0x20;
    func_00110648(v0, 0);
    {
        register int three __asm__("$3") = 3;
        s0->w04 = three;
    }
    func_01B02B38(2, 1);
}
