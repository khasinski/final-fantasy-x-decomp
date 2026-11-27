#include "common.h"

typedef struct {
    u8 pad00[0x5D20];
    u8 sub5D20[0x40];
} OvlState;

extern OvlState *D_01B0BD58;

extern void func_00118098(int, int);
extern void func_01B051C8(int, int, int, void *);
extern void func_01B0AFB8(void *, int, int, float, float);

void func_01B02FA0(void)
{
    func_01B0AFB8(D_01B0BD58->sub5D20, 0x1E, 0, 1.0f, 0.5f);
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
}

void func_01B02FF0(void *a0)
{
    func_01B051C8(-1, 0x8A, 0, a0);
}
