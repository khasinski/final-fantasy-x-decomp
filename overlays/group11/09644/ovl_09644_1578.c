#include "common.h"

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} OvlCE0;

typedef struct {
    u8 pad00[0xCE0];
    OvlCE0 ce0;
    u8 padD7C[0xC4];
    u8 fE40[0x10];
} OvlWork;

extern OvlWork *D_01B08A90;

extern void func_00118098(int, int);
extern void func_01B07DD0(void *, int);
extern void func_01B08090(void *, int, int, float, float);

void ovl_09644_1578(void)
{
    OvlWork *w = D_01B08A90;
    OvlCE0 *s0;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B08090(w->fE40, 1, 0, 1.0f, 0.3f);
    s0 = &w->ce0;
    s0->b83 = 0x80;
    s0->b82 = 0xFF;
    s0->b81 = 0xFF;
    s0->b80 = 0xFF;
    s0->b84 = 0xFF;
    s0->b85 = 0xFF;
    s0->b86 = 0xFF;
    s0->b87 = 0;
    s0->w88 = 0;
    s0->b98 = 0x44;
    s0->b99 = 0;
    func_01B07DD0(s0, 0x14);
}
