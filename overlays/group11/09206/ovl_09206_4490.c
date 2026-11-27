#include "common.h"

extern u8 *D_01B0C888;

extern void func_0010D380(s32, s32, s32);
extern void func_0010D3A8(s32, s32, s32);
extern s32 func_01B053A8(s32);
extern void func_01B07BA0(void *);

void func_01B04490(void)
{
    u8 *s0 = D_01B0C888 + 0x8000;
    s32 h;

    if (*(void **)(s0 + 0x604) != 0) {
        func_01B07BA0(*(void **)(s0 + 0x604));
        *(void **)(s0 + 0x604) = 0;
    }
    h = func_01B053A8(-1);
    func_0010D380(h, -1, -1);
    func_0010D3A8(h, -1, -1);
    h = func_01B053A8(1);
    func_0010D380(h, -1, -1);
    func_0010D3A8(h, -1, -1);
}
