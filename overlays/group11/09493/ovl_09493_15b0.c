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
} OvlFF0;

typedef struct {
    u8 pad00[0xFF0];
    OvlFF0 ff0;
} OvlWork;

extern OvlWork *D_01B08E28;

extern void func_01B086C8(void *, int);

void ovl_09493_15b0(void)
{
    OvlFF0 *v0 = &D_01B08E28->ff0;

    v0->b83 = 0x80;
    v0->b82 = 0xFF;
    v0->b81 = 0xFF;
    v0->b80 = 0xFF;
    v0->b84 = 0xFF;
    v0->b85 = 0xFF;
    v0->b86 = 0xFF;
    v0->b87 = 0;
    v0->w88 = 0x18;
    v0->b98 = 0x48;
    v0->b99 = 0;
    func_01B086C8(v0, 0x1E);
}
